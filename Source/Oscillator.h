/*
  ==============================================================================

    Oscillator.h
    Created: 1 Aug 2018 6:33:06pm
    Author:  stefa

  ==============================================================================
*/

#pragma once

#include "Interpolator.h"
#include "Wavetable.h"
#include <memory>
#include <execution>
#include <algorithm>

using namespace Interpolation;

#define PI  3.14159265359
#define NUM_MAX_WAVETABLES 10
#define NUM_SAMPLE_WAVETABLE 2048

#define NUM_WAVETABLES 10
#define TABLE_SIZE 2048

#define LOWEST_FREQ 20

enum class WaveformType { Sin, Tri, Sqr, Saw, };

template <typename T>
class WavetableOsc
{
public:
    explicit WavetableOsc(const int& sampleRate, const T& frequency, const T& phaseOffset)
		: mSampleRate{ sampleRate }, mPhase{ phaseOffset }, mFreqIncrementFactor { sampleRate / static_cast<T>(TABLE_SIZE) }
    {
		SetFrequency(frequency);

        mSampleInterpolator = std::make_unique<LinearInterpolator<T>>();
        mTableInterpolator  = std::make_unique<LinearInterpolator<T>>();
        //mSampleInterpolator = std::make_unique<CubicInterpolator<T>>();
        //mSampleInterpolator = std::make_unique<QuadraticInterpolator<T>>();
    }

    ~WavetableOsc() = default;

	void Init(const WaveformType& waveformType)
    {
        switch (waveformType) 
        {
            case WaveformType::Sin:
            {
                break;
            }
            case WaveformType::Tri: 
            {
                break;
            }
            case WaveformType::Sqr: 
            {
                break;
            }
            case WaveformType::Saw:
            {
                SetupSaw();
                break;
            }
            default: break;
        }
    }

    inline void SetFrequency(const T& frequency)
    {
        mFrequency = frequency;
        mPhaseIncrement = frequency / mFreqIncrementFactor;
    }
	    
    //T GetOutputSample() const
    //{
    //    int idxWavetable = 0;
    //    while ((mPhaseIncrement >= mWavetableList[idxWavetable]->GetStepIncrement())
    //        && (idxWavetable < (mWavetableList.size() - 1)))
    //    {
    //        ++idxWavetable;
    //    }
    //    Wavetable<T>* wavetable = mWavetableList[idxWavetable];
    //    T idxSample = mPhase * wavetable->Size();
    //    int idxSamplePrev = idxSample;
    //    int idxSampleNext = idxSamplePrev + 1;
    //    T samplesDelta = idxSample - idxSamplePrev;
    //    auto sampleOutInterp = (*mSampleInterpolator)(samplesDelta, (*wavetable)[idxSamplePrev]);
    //    auto sampleOut = (*wavetable)[int(idxSample)];
    //    //return sampleOut;
    //    return sampleOutInterp;
    //}

    T GetOutputSample(const T& frequency)
    {
        /// frequency value used here must be already smoothed to avoid UI clicks
        /// Phase Increment must be updated accordingly as:
        /// phaseInc = frequency.currentValue / tableFundamentalFreq;        
        const auto idxWavetablePrev = GetWavetableIndex(frequency);
        const auto idxWavetableNext = (idxWavetablePrev >= NUM_WAVETABLES-1) ? NUM_WAVETABLES-1 : idxWavetablePrev+1;

        const auto idxSample = mPhase;
        const auto idxSamplePrev = static_cast<int>(idxSample);
        const auto idxSampleNext = static_cast<int>(idxSamplePrev + 1);
        const auto samplesDelta = idxSample - idxSamplePrev;

        const auto sampleInterpPrev = mSampleInterpolator->ShiftInterpolate(samplesDelta, (*mWavetableList[idxWavetablePrev])[idxSamplePrev]);
        const auto sampleInterpNext = mSampleInterpolator->ShiftInterpolate(samplesDelta, (*mWavetableList[idxWavetableNext])[idxSampleNext]);
        
    	UpdatePhase();
        
        // BUG: wavetableDelta must be in range [0..1]
        const auto wavetableDelta = (frequency / mWavetableList[idxWavetablePrev]->mRootFreq) - 1;
        // T wavetableDelta = frequency - mWavetableList[idxWavetablePrev]->mRootFreq;
        return mTableInterpolator->Interpolate(wavetableDelta, { sampleInterpPrev , sampleInterpNext });
    }

private:
    int const mSampleRate;
    T mFrequency;
    T mPhase;
    T mPhaseIncrement;
    T const mFreqIncrementFactor; 

    std::unique_ptr<Interpolator<T>> mSampleInterpolator;
    std::unique_ptr<Interpolator<T>> mTableInterpolator;

    std::vector<std::unique_ptr<Wavetable<T>>> mWavetableList;

	inline void UpdatePhase()
    {
        mPhase += mPhaseIncrement;
        // Wrap back one sample before the last to avoid buffer overflow when
        // trying to read next sample of the last one (during interpolation)
        if (mPhase >= TABLE_SIZE-1)
            mPhase -= TABLE_SIZE-1;
    }

    int GetWavetableIndex(const T& frequency)
    {
		if (frequency < mWavetableList.front()->mRootFreq) { return 0; }
        if (frequency > mWavetableList.back()->mRootFreq) { return NUM_WAVETABLES; }

        int idxTable = 0;
        while (frequency > mWavetableList[idxTable]->mRootFreq)
        {
            if (frequency < mWavetableList[idxTable + 1]->mRootFreq) { return idxTable; }
            ++idxTable;
        }
        return 0;
    }

    void SetupSaw()
    {
        // Create wavetables and set each root frequency and add them to the wavetable list
        double rootFrequency = LOWEST_FREQ;
        for (auto idxTable = 0; idxTable < NUM_WAVETABLES; idxTable++)
        {
            auto wavetable = std::make_unique<Wavetable<T>>(rootFrequency, TABLE_SIZE);
			mWavetableList.push_back(std::move(wavetable));
            rootFrequency *= 2.0;
        }

        // Populate wavetables buffer
        const auto nyquistFreq = 0.5 * mSampleRate;
		for (auto&& wavetable : mWavetableList)
        {
            for (auto idxSample = 0; idxSample < TABLE_SIZE; idxSample++)
            {
                auto currentPartial = 1.0;
                while (wavetable->mRootFreq * currentPartial < nyquistFreq)
                {
					// Keep on adding harmonics until nyquistFreq is reached
                    auto phase = (idxSample * 2 * PI * currentPartial) / static_cast<T>(TABLE_SIZE - 1);
                    wavetable->mSamplesBuffer[idxSample] += std::sin(phase) * static_cast<T>(-1.0 / currentPartial);
                    currentPartial += 1;
                }
            }
        }

        // Normalize wavetables
		for (auto&& wavetable : mWavetableList)
        {
            //find the largest value ignoring polarity
            auto wavetableMax = std::max_element(std::execution::par,
				wavetable->mSamplesBuffer.begin(), 
				wavetable->mSamplesBuffer.end(), 
				[](const auto& a, const auto& b) {return (std::abs(a) < std::abs(b)); });

            const auto wavetableMaxAbs = std::abs(*wavetableMax);

            std::transform(std::execution::par,
				wavetable->mSamplesBuffer.begin(), 
				wavetable->mSamplesBuffer.end(), 
				wavetable->mSamplesBuffer.begin(), 
				[&wavetableMaxAbs](const auto& a){ return a / wavetableMaxAbs; });
        }
    }

};

