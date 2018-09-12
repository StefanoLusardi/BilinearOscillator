/*
  ==============================================================================

    Interpolator.h
    Created: 1 Aug 2018 6:34:02pm
    Author:  stefa

  ==============================================================================
*/

#pragma once
#include <vector>
#include <cassert>

namespace Interpolation
{
	template<typename T = double>
	class Interpolator
	{
	public:
		virtual ~Interpolator() {}
		// Requires only the last sample, but assumes that previous samples are constantly updated
		virtual const T& ShiftInterpolate(const T& alpha, const T& sample) = 0;
		// Requires the entire array of samples to be interpolated
		virtual const T& Interpolate(const T& alpha, const std::vector<T>& samples) = 0;

	protected:
		Interpolator(const int& numSamples) 
		: mSamples(std::vector<T>(numSamples, 0)) {}

		void ShiftSamples(const T& newSample)
		{
			// Shift old samples one position to the left
			std::rotate(mSamples.begin(), mSamples.begin() + 1, mSamples.end());            
			// Add newSample in the last (rightmost) position
			mSamples.back() = newSample;
		}

		std::vector<T> mSamples; // Array of samples around the interpolation point

	private:
		Interpolator() {};
	};

	template<typename T = double>
	class LinearInterpolator : public Interpolator<>
	{
	public:  
		LinearInterpolator() : Interpolator(mSamplesSize) {}
		~LinearInterpolator() override {}

		const T& ShiftInterpolate(const T& alpha, const T& sample) override
		{        
			this->ShiftSamples(sample);
			return this->mSamples[0] + alpha*(this->mSamples[1] - this->mSamples[0]);
		}

		const T& Interpolate(const T& alpha, const std::vector<T>& samples) override
		{        	
			assert(samples.size() == mSamplesSize);
			this->mSamples = samples;
			return this->mSamples[0] + alpha*(this->mSamples[1] - this->mSamples[0]);
		}

	private:
		static const int mSamplesSize = 2;
	};


	template<typename T = double>
	class QuadraticInterpolator : public Interpolator<T>
	{
	public:  
		QuadraticInterpolator() : Interpolator(mSamplesSize) {}
		~QuadraticInterpolator() override {}

		const T& ShiftInterpolate(const T& alpha, const T& sample) override
		{
			ShiftSamples(sample);
			return this->mSamples[1] + 0.5*alpha*(this->mSamples[2] - this->mSamples[0] + alpha*(this->mSamples[2] - 2 * this->mSamples[1] + this->mSamples[0]));
		}

		const T& Interpolate(const T& alpha, const std::vector<T>& samples) override
		{
			assert(samples.size() == mSamplesSize);
			this->mSamples = samples;
			return this->mSamples[1] + 0.5*alpha*(this->mSamples[2] - this->mSamples[0] + alpha*(this->mSamples[2] - 2 * this->mSamples[1] + this->mSamples[0]));
		} 

	private:
		static const int mSamplesSize = 3;
	};

	template<typename T = double>
	class CubicInterpolator : public Interpolator<T>
	{
	public:  
		CubicInterpolator() : Interpolator(mSamplesSize) {}
		~CubicInterpolator() override {}

		const T& ShiftInterpolate(const T& alpha, const T& sample) override
		{
			ShiftSamples(sample);
			return this->mSamples[1] + 0.5*alpha*(this->mSamples[2] - this->mSamples[0] + alpha*(2.0*this->mSamples[0] - 5.0*this->mSamples[1] + 4.0*this->mSamples[2] - this->mSamples[3] + alpha*(3.0*(this->mSamples[1] - this->mSamples[2]) + this->mSamples[3] - this->mSamples[0])));
		}

		const T& Interpolate(const T& alpha, const std::vector<T>& samples) override
		{
			assert(samples.size() == mSamplesSize);   
			this->mSamples = samples;
			return this->mSamples[1] + 0.5*alpha*(this->mSamples[2] - this->mSamples[0] + alpha*(2.0*this->mSamples[0] - 5.0*this->mSamples[1] + 4.0*this->mSamples[2] - this->mSamples[3] + alpha*(3.0*(this->mSamples[1] - this->mSamples[2]) + this->mSamples[3] - this->mSamples[0])));
		}

	private:
		static const int mSamplesSize = 4;
	};

	// Linear
	// y = p[0] + a*(p[1] - p[0]);

	// Quadratic
	// y = p[1] + 0.5*a*(p[2] - p[0] + a*(p[2] - 2 * p[1] + p[0]));

	// Cubic
	// y = p[1] + 0.5*a*(p[2] - p[0] + a*(2.0*p[0] - 5.0*p[1] + 4.0*p[2] - p[3] + a*(3.0*(p[1] - p[2]) + p[3] - p[0])));


}
