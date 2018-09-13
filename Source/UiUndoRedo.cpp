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

//[Headers] You can add your own extra header files here...
#include "Core.h"
//[/Headers]

#include "UiUndoRedo.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
UiUndoRedo::UiUndoRedo (Component* parent, Core& core)
    : mParent{parent}, mUndoManager{core.getUndoManager()}
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    setName ("UiUndoRedo");
    mButtonUndo.reset (new TextButton ("ButtonUndo"));
    addAndMakeVisible (mButtonUndo.get());
    mButtonUndo->setButtonText (TRANS("Undo"));
    mButtonUndo->setColour (TextButton::buttonOnColourId, Colour (0xffa45c94));

    mButtonRedo.reset (new TextButton ("ButtonRedo"));
    addAndMakeVisible (mButtonRedo.get());
    mButtonRedo->setButtonText (TRANS("Redo"));
    mButtonRedo->setColour (TextButton::buttonOnColourId, Colour (0xffa45c94));


    //[UserPreSize]
	mButtonUndo->setEnabled(false);
 	mButtonRedo->setEnabled(false);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	mButtonUndo->onClick = [&] { mUndoManager.undo(); };
	mButtonRedo->onClick = [&] { mUndoManager.redo(); };
	startTimer (250);
    //[/Constructor]
}

UiUndoRedo::~UiUndoRedo()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    mButtonUndo = nullptr;
    mButtonRedo = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void UiUndoRedo::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = 0.0f, y = 0.0f, width = static_cast<float> (proportionOfWidth (1.0000f)), height = static_cast<float> (proportionOfHeight (1.0000f));
        Colour fillColour = Colours::yellow;
        Colour strokeColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 20.000f);
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 20.000f, 5.000f);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void UiUndoRedo::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    mButtonUndo->setBounds (proportionOfWidth (0.0497f), proportionOfHeight (0.2576f), proportionOfWidth (0.3978f), proportionOfHeight (0.5000f));
    mButtonRedo->setBounds (proportionOfWidth (0.5525f), proportionOfHeight (0.2576f), proportionOfWidth (0.3978f), proportionOfHeight (0.5000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void UiUndoRedo::timerCallback()
{
	mButtonUndo->setEnabled(mUndoManager.canUndo());
 	mButtonRedo->setEnabled(mUndoManager.canRedo());
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="UiUndoRedo" componentName="UiUndoRedo"
                 parentClasses="public Component, public Timer" constructorParams="Component* parent, Core&amp; core"
                 variableInitialisers="mParent{parent}, mUndoManager{core.getUndoManager()}"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="0">
    <ROUNDRECT pos="0 0 100% 100%" cornerSize="20.00000000000000000000" fill="solid: ffffff00"
               hasStroke="1" stroke="5, mitered, butt" strokeColour="solid: ff000000"/>
  </BACKGROUND>
  <TEXTBUTTON name="ButtonUndo" id="2905daae1318e8f9" memberName="mButtonUndo"
              virtualName="" explicitFocusOrder="0" pos="4.972% 25.758% 39.779% 50%"
              bgColOn="ffa45c94" buttonText="Undo" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="ButtonRedo" id="f80fc073aaa0b332" memberName="mButtonRedo"
              virtualName="" explicitFocusOrder="0" pos="55.249% 25.758% 39.779% 50%"
              bgColOn="ffa45c94" buttonText="Redo" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
