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

#include "UiButtonStrip.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
UiButtonStrip::UiButtonStrip (Component* parent, ValueTree& model)
    : mParent{parent}, mModel{model}
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    setName ("ButtonStrip");
    mButtonPlay.reset (new TextButton ("ButtonPlay"));
    addAndMakeVisible (mButtonPlay.get());
    mButtonPlay->setButtonText (TRANS("Play"));
    mButtonPlay->setColour (TextButton::buttonOnColourId, Colour (0xffa45c94));

    mButtonMute.reset (new TextButton ("ButtonMute"));
    addAndMakeVisible (mButtonMute.get());
    mButtonMute->setButtonText (TRANS("Mute"));
    mButtonMute->setColour (TextButton::buttonOnColourId, Colour (0xffa45c94));


    //[UserPreSize]
	mButtonMute->setClickingTogglesState(true);
	mButtonPlay->setClickingTogglesState(true);
    //[/UserPreSize]

    setSize (435, 60);


    //[Constructor] You can add your own custom stuff here..
	mButtonMute->onClick = [&]
	{
		auto uiModel = mModel.getChildWithProperty("name", getName());
		auto sliderProperty = uiModel.getChildWithProperty("id", mButtonMute->getName());
		sliderProperty.setProperty("value", mButtonMute->getToggleState(), nullptr);
	};

	mButtonPlay->onClick = [&]
	{
		auto uiModel = mModel.getChildWithProperty("name", getName());
		auto sliderProperty = uiModel.getChildWithProperty("id", mButtonPlay->getName());
		sliderProperty.setProperty("value", mButtonPlay->getToggleState(), nullptr);
	};
    //[/Constructor]
}

UiButtonStrip::~UiButtonStrip()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    mButtonPlay = nullptr;
    mButtonMute = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void UiButtonStrip::paint (Graphics& g)
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

void UiButtonStrip::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    mButtonPlay->setBounds (proportionOfWidth (0.0507f), proportionOfHeight (0.2477f), proportionOfWidth (0.4013f), proportionOfHeight (0.4955f));
    mButtonMute->setBounds (proportionOfWidth (0.5481f), proportionOfHeight (0.2477f), proportionOfWidth (0.4013f), proportionOfHeight (0.4955f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void UiButtonStrip::setModel(ValueTree&& model)
{
	model.appendChild({ "Param", { {"id", mButtonMute->getName()}, {"value", {mButtonMute->getToggleState()}} } }, nullptr);
	model.appendChild({ "Param", { {"id", mButtonPlay->getName()}, {"value", {mButtonPlay->getToggleState()}} } }, nullptr);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="UiButtonStrip" componentName="ButtonStrip"
                 parentClasses="public Component" constructorParams="Component* parent, ValueTree&amp; model"
                 variableInitialisers="mParent{parent}, mModel{model}" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="435" initialHeight="60">
  <BACKGROUND backgroundColour="ff323e44">
    <ROUNDRECT pos="0 0 100% 100%" cornerSize="20.00000000000000000000" fill="solid: ffffff00"
               hasStroke="0"/>
  </BACKGROUND>
  <TEXTBUTTON name="ButtonPlay" id="2905daae1318e8f9" memberName="mButtonPlay"
              virtualName="" explicitFocusOrder="0" pos="5.069% 24.773% 40.127% 49.547%"
              bgColOn="ffa45c94" buttonText="Play" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
  <TEXTBUTTON name="ButtonMute" id="f80fc073aaa0b332" memberName="mButtonMute"
              virtualName="" explicitFocusOrder="0" pos="54.805% 24.773% 40.127% 49.547%"
              bgColOn="ffa45c94" buttonText="Mute" connectedEdges="0" needsCallback="0"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
