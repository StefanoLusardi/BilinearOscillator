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

#include "UiButtonStrip.h"
#include "UiSliderStrip.h"
#include "UiUndoRedo.h"
#include "UiPlotter.h"
#include "UiOscillator.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainUi  : public Component,
                public ValueTree::Listener
{
public:
    //==============================================================================
    MainUi (Component* parent, Core& core);
    ~MainUi();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void valueTreePropertyChanged(ValueTree& treeWhosePropertyHasChanged, const Identifier& property) override;
	void valueTreeChildAdded(ValueTree& parentTree, ValueTree& childWhichHasBeenAdded) override { }
	void valueTreeChildRemoved(ValueTree& parentTree, ValueTree& childWhichHasBeenRemoved, int indexFromWhichChildWasRemoved) override { }
	void valueTreeChildOrderChanged(ValueTree& parentTreeWhoseChildrenHaveMoved, int oldIndex, int newIndex) override { }
	void valueTreeParentChanged(ValueTree& treeWhoseParentHasChanged) override { }
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Component* mParent;
	std::unique_ptr<BaseLNF> mLookAndFeel;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<TextButton> mDumpModelButton;
    std::unique_ptr<UiButtonStrip> mUiButtonStrip;
    std::unique_ptr<UiSliderStrip> mUiSliderStrip;
    std::unique_ptr<UiUndoRedo> mUiUndoRedo;
    std::unique_ptr<UiPlotter> mUiPlotter;
    std::unique_ptr<UiOscillator> mOsc2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainUi)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
