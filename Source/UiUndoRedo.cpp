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
//[/Headers]

#include "UiUndoRedo.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
UiUndoRedo::UiUndoRedo (Component* parent, UndoManager& undoManager)
    : mParent{parent}, mUndoManager{undoManager}
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
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	mButtonUndo->onClick = [&] { mUndoManager.undo(); };
	mButtonRedo->onClick = [&] { mUndoManager.redo(); };
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

    g.fillAll (Colour (0xff323e44));

    {
        float x = 0.0f, y = 0.0f, width = static_cast<float> (proportionOfWidth (1.0000f)), height = static_cast<float> (proportionOfHeight (1.0000f));
        Colour fillColour = Colours::yellow;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 20.000f);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void UiUndoRedo::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    mButtonUndo->setBounds (proportionOfWidth (0.0547f), proportionOfHeight (0.2905f), proportionOfWidth (0.4049f), proportionOfHeight (0.4931f));
    mButtonRedo->setBounds (proportionOfWidth (0.5488f), proportionOfHeight (0.2905f), proportionOfWidth (0.4049f), proportionOfHeight (0.4931f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="UiUndoRedo" componentName="UiUndoRedo"
                 parentClasses="public Component" constructorParams="Component* parent, UndoManager&amp; undoManager"
                 variableInitialisers="mParent{parent}, mUndoManager{undoManager}"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <ROUNDRECT pos="0 0 100% 100%" cornerSize="20.00000000000000000000" fill="solid: ffffff00"
               hasStroke="0"/>
  </BACKGROUND>
  <TEXTBUTTON name="ButtonUndo" id="2905daae1318e8f9" memberName="mButtonUndo"
              virtualName="" explicitFocusOrder="0" pos="4.545% 28.972% 40.909% 49.533%"
              bgColOn="ffa45c94" buttonText="Undo" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="ButtonRedo" id="f80fc073aaa0b332" memberName="mButtonRedo"
              virtualName="" explicitFocusOrder="0" pos="54.545% 28.972% 40.909% 49.533%"
              bgColOn="ffa45c94" buttonText="Redo" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
