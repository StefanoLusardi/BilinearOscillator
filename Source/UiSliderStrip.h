/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
class Core;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class UiSliderStrip  : public Component
{
public:
    //==============================================================================
    UiSliderStrip (Component* parent, Core& core);
    ~UiSliderStrip();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;

    // Binary resources:
    static const char* phase_invert_png;
    static const int phase_invert_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Component* mParent;
	ValueTree mUiModel;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> mSliderFreq;
    std::unique_ptr<Label> mLabelFreq;
    std::unique_ptr<Slider> mSliderAmp;
    std::unique_ptr<Label> mLabelAmp;
    std::unique_ptr<ImageButton> mPhaseInvert;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UiSliderStrip)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
