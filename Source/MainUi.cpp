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
#include <thread>

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
    //[/Constructor]
}

MainUi::~MainUi()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    mUiButtonStrip = nullptr;
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

    g.fillAll (Colour (0xffa45c94));

    {
        float x = static_cast<float> (proportionOfWidth (0.7500f)), y = static_cast<float> (proportionOfHeight (0.1000f)), width = static_cast<float> (proportionOfWidth (0.2500f)), height = static_cast<float> (proportionOfHeight (0.2000f));
        Colour strokeColour = Colours::yellow;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawEllipse (x, y, width, height, 5.000f);
    }

    {
        int x = proportionOfWidth (0.7500f), y = proportionOfHeight (0.1000f), width = proportionOfWidth (0.2500f), height = proportionOfHeight (0.2000f);
        String text (TRANS("sL Bilinear Oscillator"));
        Colour fillColour = Colours::yellow;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainUi::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    mUiButtonStrip->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (0.7519f), proportionOfHeight (0.0997f));
    mUiSliderStrip->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0997f), proportionOfWidth (0.7519f), proportionOfHeight (0.1994f));
    mUiUndoRedo->setBounds (proportionOfWidth (0.7519f), proportionOfHeight (0.0000f), proportionOfWidth (0.2482f), proportionOfHeight (0.0997f));
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

	if (uiName == mUiSliderStrip->getName())
	{
		mUiPlotter->update(uiParam, paramValue);		
	}

	/// DEBUG
	if ( false )
	{
		DBG("Ui Name: "		<< uiName.toString());
		DBG("Ui Param: "	<< uiParam.toString());
		DBG("Param Value: " << paramValue.toString() << "\n");

		const StringRef xmlModelFile { "model_dump_ui.xml" };
		const auto xmlModelFilePath { File::getCurrentWorkingDirectory().getChildFile(xmlModelFile) };
		const auto ok = treeWhosePropertyHasChanged.getRoot().createXml()->writeToFile(xmlModelFilePath, StringRef{});
	}
}

void MainUi::valueTreeChildAdded(ValueTree& parentTree, ValueTree& childWhichHasBeenAdded)
{
}

void MainUi::valueTreeChildRemoved(ValueTree& parentTree, ValueTree& childWhichHasBeenRemoved, int indexFromWhichChildWasRemoved)
{
}

void MainUi::valueTreeChildOrderChanged(ValueTree& parentTreeWhoseChildrenHaveMoved, int oldIndex, int newIndex)
{
}

void MainUi::valueTreeParentChanged(ValueTree& treeWhoseParentHasChanged)
{
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
  <BACKGROUND backgroundColour="ffa45c94">
    <ELLIPSE pos="75% 10% 25% 20%" fill="solid: 0" hasStroke="1" stroke="5, mitered, butt"
             strokeColour="solid: ffffff00"/>
    <TEXT pos="75% 10% 25% 20%" fill="solid: ffffff00" hasStroke="0" text="sL Bilinear Oscillator"
          fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
          bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <JUCERCOMP name="ButtonStrip" id="94d533df8a0dd9aa" memberName="mUiButtonStrip"
             virtualName="UiButtonStrip" explicitFocusOrder="0" pos="0% 0% 75.185% 9.97%"
             sourceFile="UiButtonStrip.cpp" constructorParams="this, core"/>
  <JUCERCOMP name="SliderStrip" id="187099a553730501" memberName="mUiSliderStrip"
             virtualName="UiSliderStrip" explicitFocusOrder="0" pos="0% 9.97% 75.185% 19.94%"
             sourceFile="UiSliderStrip.cpp" constructorParams="this, core"/>
  <JUCERCOMP name="UndoRedo" id="d5fb429b43c90dae" memberName="mUiUndoRedo"
             virtualName="UiUndoRedo" explicitFocusOrder="0" pos="75.185% 0% 24.815% 9.97%"
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
