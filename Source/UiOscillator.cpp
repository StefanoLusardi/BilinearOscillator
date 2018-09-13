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
#include "ParameterTags.h"
//[/Headers]

#include "UiOscillator.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
UiOscillator::UiOscillator (Component* parent, Core& core, const String& objId)
    : mParent{parent}
{
    //[Constructor_pre] You can add your own custom stuff here..
    setName ("Oscillator" + objId);

	//const auto setUiModel = [&] () -> ValueTree
	//{
	//	if (!core.getModel().getChildWithProperty(Props[Prop::Id], this->getName()).isValid())
	//	{
	//		// model does not contain current Ui ValueTree. Create it and add it to model.
	//		core.getModel().appendChild( { Tags[Tag::Ui], {{Props[Prop::Id], this->getName()}} }, nullptr);
	//	}

	//	// Return current Ui ValueTree.
	//	return core.getModel().getChildWithProperty(Props[Prop::Id], this->getName());
	//};

	const auto setUiModel = [&] () -> ValueTree
	{
		if (mParent && core.getModel().getChildWithProperty(Props[Prop::Id], mParent->getName()).isValid())
		{
			if (!core.getModel()
				.getChildWithProperty(Props[Prop::Id], mParent->getName())
				.getChildWithProperty(Props[Prop::Id], this->getName()).isValid())
			{
				core.getModel()
					.getChildWithProperty(Props[Prop::Id], mParent->getName())
					.appendChild( { Tags[Tag::Ui], {{Props[Prop::Id], this->getName()}} }, nullptr);
			}
			return core.getModel()
				.getChildWithProperty(Props[Prop::Id], mParent->getName())
				.getChildWithProperty(Props[Prop::Id], this->getName());
		}
		else
		{
			if (!core.getModel().getChildWithProperty(Props[Prop::Id], this->getName()).isValid())
			{
				core.getModel().appendChild( { Tags[Tag::Ui], {{Props[Prop::Id], this->getName()}} }, nullptr);
			}
			return core.getModel().getChildWithProperty(Props[Prop::Id], this->getName());
		}
	};

	mUiModel = setUiModel();
    //[/Constructor_pre]

    mButtons.reset (new UiButtonStrip (this, core));
    addAndMakeVisible (mButtons.get());
    mSliders.reset (new UiSliderStrip (this, core));
    addAndMakeVisible (mSliders.get());

    //[UserPreSize]
    //[/UserPreSize]

    setSize (435, 180);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

UiOscillator::~UiOscillator()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    mButtons = nullptr;
    mSliders = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void UiOscillator::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void UiOscillator::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    mButtons->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (1.0000f), proportionOfHeight (0.3323f));
    mSliders->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.3323f), proportionOfWidth (1.0000f), proportionOfHeight (0.6586f));
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

<JUCER_COMPONENT documentType="Component" className="UiOscillator" componentName=""
                 parentClasses="public Component" constructorParams="Component* parent, Core&amp; core, const String&amp; objId"
                 variableInitialisers="mParent{parent}" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="435"
                 initialHeight="180">
  <BACKGROUND backgroundColour="ff323e44"/>
  <JUCERCOMP name="Buttons" id="d53e1e56aa8f0e71" memberName="mButtons" virtualName="UiButtonStrip"
             explicitFocusOrder="0" pos="0% 0% 100% 33.233%" sourceFile="UiButtonStrip.cpp"
             constructorParams="this, core"/>
  <JUCERCOMP name="Sliders" id="bbb8682bd56b35e2" memberName="mSliders" virtualName="UiSliderStrip"
             explicitFocusOrder="0" pos="0% 33.233% 100% 65.861%" sourceFile="UiSliderStrip.cpp"
             constructorParams="this, core"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
