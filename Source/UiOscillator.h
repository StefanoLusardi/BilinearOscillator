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
//[/Headers]

#include "UiButtonStrip.h"
#include "UiSliderStrip.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class UiOscillator  : public Component
{
public:
    //==============================================================================
    UiOscillator (Component* parent, Core& core, const String& objId);
    ~UiOscillator();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Component* mParent;
	ValueTree mUiModel;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<UiButtonStrip> mButtons;
    std::unique_ptr<UiSliderStrip> mSliders;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UiOscillator)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

