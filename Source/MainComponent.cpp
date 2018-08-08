/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "MainUi.h"
#include "Oscillator.h"

//==============================================================================
MainComponent::MainComponent()
{
	mMainUi.reset(new MainUi(this, mCore));
	addAndMakeVisible(mMainUi.get());

    setSize (800, 500);
    setAudioChannels (0, 2);
}

MainComponent::~MainComponent()
{
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
	const auto initPhase { 0.5 };
	mWTO = std::make_unique<WavetableOsc<double>>(sampleRate, mCore.getFreq(), initPhase);
    mWTO->Init(WaveformType::Saw);
}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
	bufferToFill.clearActiveBufferRegion();	
	
    const auto amp  = mCore.getAmp();
	const auto freq = mCore.getFreq();
	mWTO->SetFrequency(freq);

    auto* leftBuffer  = bufferToFill.buffer->getWritePointer (0, bufferToFill.startSample);
    auto* rightBuffer = bufferToFill.buffer->getWritePointer (1, bufferToFill.startSample);
	
	for (auto n = 0; n < bufferToFill.numSamples; ++n)
    {
		const auto sample = mWTO->GetOutputSample(freq);
        leftBuffer[n]  = sample * amp;
        rightBuffer[n] = sample * amp;
    }
}

void MainComponent::releaseResources()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
}

void MainComponent::resized()
{
	mMainUi->setBounds(getLocalBounds());
}
