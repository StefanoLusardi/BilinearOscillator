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
#include "SliderLNF.h"
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
	mLookAndFeel.reset(new SliderLNF());
	setLookAndFeel(mLookAndFeel.get());
    //[/Constructor_pre]

    setName ("MainUi");
    mDumpModelButton.reset (new TextButton ("DumpModelButton"));
    addAndMakeVisible (mDumpModelButton.get());
    mDumpModelButton->setButtonText (TRANS("Save"));
    mDumpModelButton->setColour (TextButton::buttonColourId, Colour (0xff4dff00));
    mDumpModelButton->setColour (TextButton::buttonOnColourId, Colour (0x00ffffff));
    mDumpModelButton->setColour (TextButton::textColourOffId, Colours::black);
    mDumpModelButton->setColour (TextButton::textColourOnId, Colours::red);

    mUiUndoRedo.reset (new UiUndoRedo (this, core));
    addAndMakeVisible (mUiUndoRedo.get());
    mUiPlotter.reset (new UiPlotter (this, core, String("Main")));
    addAndMakeVisible (mUiPlotter.get());
    mOsc1.reset (new UiOscillator (this, core, String("1")));
    addAndMakeVisible (mOsc1.get());
    mOsc2.reset (new UiOscillator (this, core, String("2")));
    addAndMakeVisible (mOsc2.get());
    mOsc2Plotter.reset (new UiPlotter (this, core, String("2")));
    addAndMakeVisible (mOsc2Plotter.get());
    mOsc1Plotter.reset (new UiPlotter (this, core, String("1")));
    addAndMakeVisible (mOsc1Plotter.get());

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
		if (!ok) mDumpModelButton->setButtonText("MODEL DUMP ERROR!");
	};
    //[/Constructor]
}

MainUi::~MainUi()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    mDumpModelButton = nullptr;
    mUiUndoRedo = nullptr;
    mUiPlotter = nullptr;
    mOsc1 = nullptr;
    mOsc2 = nullptr;
    mOsc2Plotter = nullptr;
    mOsc1Plotter = nullptr;


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

    mDumpModelButton->setBounds (proportionOfWidth (0.8309f), proportionOfHeight (0.5076f), proportionOfWidth (0.0972f), proportionOfHeight (0.0846f));
    mUiUndoRedo->setBounds (proportionOfWidth (0.3978f), proportionOfHeight (0.4955f), proportionOfWidth (0.2000f), proportionOfHeight (0.0997f));
    mUiPlotter->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.5997f), proportionOfWidth (1.0000f), proportionOfHeight (0.4003f));
    mOsc1->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (0.4995f), proportionOfHeight (0.3006f));
    mOsc2->setBounds (proportionOfWidth (0.4995f), proportionOfHeight (0.0000f), proportionOfWidth (0.4995f), proportionOfHeight (0.3006f));
    mOsc2Plotter->setBounds (proportionOfWidth (0.4995f), proportionOfHeight (0.3006f), proportionOfWidth (0.4995f), proportionOfHeight (0.1994f));
    mOsc1Plotter->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.3006f), proportionOfWidth (0.4995f), proportionOfHeight (0.1994f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MainUi::valueTreePropertyChanged(ValueTree& treeWhosePropertyHasChanged, const Identifier& property)
{
	const auto& uiName		{ treeWhosePropertyHasChanged.getParent().getProperty(Props[Prop::Id]) };
	const auto& uiParam		{ treeWhosePropertyHasChanged.getProperty(Props[Prop::Id]) };
	const auto& paramValue	{ treeWhosePropertyHasChanged.getProperty(property) };

	mOsc1Plotter->repaint();
	mOsc2Plotter->repaint();
	mUiPlotter->repaint();
	/*
	DBG("Ui Name: "		<< uiName.toString());
	DBG("Ui Param: "	<< uiParam.toString());
	DBG("Param Value: " << paramValue.toString() << "\n");
	*/
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
  <TEXTBUTTON name="DumpModelButton" id="4e58062973560f20" memberName="mDumpModelButton"
              virtualName="" explicitFocusOrder="0" pos="82.963% 50.765% 9.63% 8.41%"
              bgColOff="ff4dff00" bgColOn="ffffff" textCol="ff000000" textColOn="ffff0000"
              buttonText="Save" connectedEdges="0" needsCallback="0" radioGroupId="0"/>
  <JUCERCOMP name="UndoRedo" id="d5fb429b43c90dae" memberName="mUiUndoRedo"
             virtualName="UiUndoRedo" explicitFocusOrder="0" pos="40% 49.541% 20% 9.939%"
             sourceFile="UiUndoRedo.cpp" constructorParams="this, core"/>
  <JUCERCOMP name="Plotter" id="da26afd6fc6b0c15" memberName="mUiPlotter"
             virtualName="UiPlotter" explicitFocusOrder="0" pos="0% 59.939% 100% 40.061%"
             sourceFile="UiPlotter.cpp" constructorParams="this, core, String(&quot;Main&quot;)"/>
  <JUCERCOMP name="Osc1" id="14853f5da6cdd18a" memberName="mOsc1" virtualName="UiOscillator"
             explicitFocusOrder="0" pos="0% 0% 49.63% 30.122%" sourceFile="UiOscillator.cpp"
             constructorParams="this, core, String(&quot;1&quot;)"/>
  <JUCERCOMP name="Osc2" id="c063d797912deb50" memberName="mOsc2" virtualName="UiOscillator"
             explicitFocusOrder="0" pos="49.63% 0% 49.63% 30.122%" sourceFile="UiOscillator.cpp"
             constructorParams="this, core, String(&quot;2&quot;)"/>
  <JUCERCOMP name="Osc2Plotter" id="b2ffffd1aa82b8ac" memberName="mOsc2Plotter"
             virtualName="UiPlotter" explicitFocusOrder="0" pos="49.63% 30.122% 49.63% 19.878%"
             sourceFile="UiPlotter.cpp" constructorParams="this, core, String(&quot;2&quot;)"/>
  <JUCERCOMP name="Osc1Plotter" id="9a446a2cd534d444" memberName="mOsc1Plotter"
             virtualName="UiPlotter" explicitFocusOrder="0" pos="0% 30.122% 49.63% 19.878%"
             sourceFile="UiPlotter.cpp" constructorParams="this, core, String(&quot;1&quot;)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
