/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "ParameterTags.h"
#include <map>
class Core;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class UiPlotter  : public Component
{
public:
    //==============================================================================
    UiPlotter (Component* parent, Core& core, const String& objId);
    ~UiPlotter();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
private:
	void plotSaw(Path& path) const;
	void plotSqr(Path& path) const;
	void plotTri(Path& path) const;

	float getAmp() const;
	float getFreq() const;
	float getPhaseInvert() const;
	Wave getWaveform() const;

public:
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Component* mParent;
	ValueTree mUiModel;

	Value mAmp;
	Value mFreq;
	Value mPhaseInvert;
	std::map<Wave, Value> mWaveforms;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UiPlotter)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

