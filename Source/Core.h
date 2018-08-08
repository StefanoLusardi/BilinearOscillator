/*
  ==============================================================================

    Core.h
    Created: 31 Jul 2018 11:29:14pm
    Author:  stefa

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class Core
{
public:
	Core();

	Core(const Core& other) = delete;
	Core(Core&& other) noexcept = delete;
	Core& operator=(const Core& other) = delete;
	Core& operator=(Core&& other) noexcept = delete;

	ValueTree& getModel();
	UndoManager& getUndoManager();

	double getAmp() const;
	double getFreq() const;

private:
	ValueTree mModel;
	UndoManager mUndoManager;
};