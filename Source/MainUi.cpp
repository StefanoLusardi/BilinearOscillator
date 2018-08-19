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
#include "UiButtonStrip.h"
#include "UiSliderStrip.h"
#include "ParameterTags.h"
#include "Core.h"
//[/Headers]

#include "MainUi.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainUi::MainUi (Component* parent, Core& core)
    : mParent{parent}
{
    //[Constructor_pre] You can add your own custom stuff here..
	core.getModel().addListener(this);
    //[/Constructor_pre]

    setName ("MainUi");
    mUiButtonStrip.reset (new UiButtonStrip (this, core));
    addAndMakeVisible (mUiButtonStrip.get());
    mDumpModelButton.reset (new TextButton ("DumpModelButton"));
    addAndMakeVisible (mDumpModelButton.get());
    mDumpModelButton->setButtonText (String());
    mDumpModelButton->setColour (TextButton::buttonColourId, Colour (0x00ffffff));
    mDumpModelButton->setColour (TextButton::buttonOnColourId, Colour (0x00ffffff));
    mDumpModelButton->setColour (TextButton::textColourOffId, Colours::red);
    mDumpModelButton->setColour (TextButton::textColourOnId, Colours::red);

    mUiSliderStrip.reset (new UiSliderStrip (this, core));
    addAndMakeVisible (mUiSliderStrip.get());
    mUiUndoRedo.reset (new UiUndoRedo (this, core));
    addAndMakeVisible (mUiUndoRedo.get());
    mUiPlotter.reset (new UiPlotter (this, core));
    addAndMakeVisible (mUiPlotter.get());

    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 500);


    //[Constructor] You can add your own custom stuff here..
	mDumpModelButton->addShortcut(KeyPress(KeyPress::spaceKey));
	mDumpModelButton->onClick = [&]
	{
		// Press spacebar to dump the model content
		const StringRef xmlModelFile { "model_dump_ui.xml" };
		const auto xmlModelFilePath { File::getCurrentWorkingDirectory().getChildFile(xmlModelFile) };
		const auto ok =  core.getModel().createXml()->writeToFile(xmlModelFilePath, StringRef{});
		mDumpModelButton->setButtonText(ok ? "" : "MODEL DUMP ERROR!");
	};
    //[/Constructor]
}

MainUi::~MainUi()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    mUiButtonStrip = nullptr;
    mDumpModelButton = nullptr;
    mUiSliderStrip = nullptr;
    mUiUndoRedo = nullptr;
    mUiPlotter = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainUi::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainUi::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    mUiButtonStrip->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (0.7514f), proportionOfHeight (0.0997f));
    mDumpModelButton->setBounds (proportionOfWidth (0.7503f), proportionOfHeight (0.0997f), proportionOfWidth (0.2497f), proportionOfHeight (0.1994f));
    mUiSliderStrip->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0997f), proportionOfWidth (0.7503f), proportionOfHeight (0.1994f));
    mUiUndoRedo->setBounds (proportionOfWidth (0.7514f), proportionOfHeight (0.0000f), proportionOfWidth (0.2486f), proportionOfHeight (0.0997f));
    mUiPlotter->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.3006f), proportionOfWidth (1.0000f), proportionOfHeight (0.6994f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MainUi::valueTreePropertyChanged(ValueTree& treeWhosePropertyHasChanged, const Identifier& property)
{
	const auto& uiName		{ treeWhosePropertyHasChanged.getParent().getProperty(Props[Prop::Id]) };
	const auto& uiParam		{ treeWhosePropertyHasChanged.getProperty(Props[Prop::Id]) };
	const auto& paramValue	{ treeWhosePropertyHasChanged.getProperty(property) };

	if (uiName == mUiSliderStrip->getName() ||
		uiName == mUiButtonStrip->getName())
	{
		mUiPlotter->repaint();
	}

	DBG("Ui Name: "		<< uiName.toString());
	DBG("Ui Param: "	<< uiParam.toString());
	DBG("Param Value: " << paramValue.toString() << "\n");
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainUi" componentName="MainUi"
                 parentClasses="public Component, public ValueTree::Listener"
                 constructorParams="Component* parent, Core&amp; core" variableInitialisers="mParent{parent}"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="800" initialHeight="500">
  <BACKGROUND backgroundColour="ffffff"/>
  <JUCERCOMP name="ButtonStrip" id="94d533df8a0dd9aa" memberName="mUiButtonStrip"
             virtualName="UiButtonStrip" explicitFocusOrder="0" pos="0% 0% 75.138% 9.97%"
             sourceFile="UiButtonStrip.cpp" constructorParams="this, core"/>
  <TEXTBUTTON name="DumpModelButton" id="4e58062973560f20" memberName="mDumpModelButton"
              virtualName="" explicitFocusOrder="0" pos="75.028% 9.97% 24.972% 19.94%"
              bgColOff="ffffff" bgColOn="ffffff" textCol="ffff0000" textColOn="ffff0000"
              buttonText="" connectedEdges="0" needsCallback="0" radioGroupId="0"/>
  <JUCERCOMP name="SliderStrip" id="187099a553730501" memberName="mUiSliderStrip"
             virtualName="UiSliderStrip" explicitFocusOrder="0" pos="0% 9.97% 75.028% 19.94%"
             sourceFile="UiSliderStrip.cpp" constructorParams="this, core"/>
  <JUCERCOMP name="UndoRedo" id="d5fb429b43c90dae" memberName="mUiUndoRedo"
             virtualName="UiUndoRedo" explicitFocusOrder="0" pos="75.138% 0% 24.862% 9.97%"
             sourceFile="UiUndoRedo.cpp" constructorParams="this, core"/>
  <JUCERCOMP name="Plotter" id="da26afd6fc6b0c15" memberName="mUiPlotter"
             virtualName="UiPlotter" explicitFocusOrder="0" pos="0% 30.06% 100% 69.94%"
             sourceFile="UiPlotter.cpp" constructorParams="this, core"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
