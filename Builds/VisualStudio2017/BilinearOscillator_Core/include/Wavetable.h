/*
  ==============================================================================

    Wavetable.h
    Created: 1 Aug 2018 6:35:22pm
    Author:  stefa

  ==============================================================================
*/

#pragma once

template <typename T>
class Wavetable
{
public:
    explicit Wavetable(const int& rootFreq, const std::vector<T>& buffer)
        : mRootFreq(rootFreq)
        , mSamplesBuffer(buffer)
    {
    }

    explicit Wavetable(const int& rootFreq, const int& bufferSize)
        : mRootFreq(rootFreq)
        , mSamplesBuffer(std::vector<T>(bufferSize))
    {
    }

    ~Wavetable()
    {
    }

    inline void SetSampleBuffer(const std::vector<T>& buffer)
    {
        mSamplesBuffer = buffer;
    }

    inline const int& Size() const
    {
        return mSamplesBuffer.size();
    }

    inline const T& GetSample(const int index) const
    {
        return mSamplesBuffer[index];
    }

    // Remove
    inline const T& operator[](const int& index) const
    {
        return mSamplesBuffer[index];
    }

//private:
    // Move to private, add a getter only.
    T const mRootFreq;
    std::vector<T> mSamplesBuffer;
};