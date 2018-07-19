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
//[/Headers]

#include "MainUi.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainUi::MainUi (Component* parent, ValueTree& model)
    : mParent{parent}, mModel{model}
{
    //[Constructor_pre] You can add your own custom stuff here..
	mModel.addListener(this);
    //[/Constructor_pre]

    setName ("MainUi");
    mUiButtonStrip.reset (new UiButtonStrip (this, mModel));
    addAndMakeVisible (mUiButtonStrip.get());
    mUiSliderStrip.reset (new UiSliderStrip (this, mModel));
    addAndMakeVisible (mUiSliderStrip.get());

    //[UserPreSize]
    //[/UserPreSize]

    setSize (435, 180);


    //[Constructor] You can add your own custom stuff here..
	mModel.appendChild({ "Ui", {{"name", mUiButtonStrip->getName()}} }, nullptr);
	mModel.appendChild({ "Ui", {{"name", mUiSliderStrip->getName()}} }, nullptr);

	//auto t1 = mModel.getChildWithProperty("name", mUiSliderStrip->getName());
	//auto t2 = mModel.getChildWithProperty("name", mUiButtonStrip->getName());
	//mUiSliderStrip->setModel(t1);
	//mUiButtonStrip->setModel(t2);

	mUiSliderStrip->setModel(mModel.getChildWithProperty("name", mUiSliderStrip->getName()));
	mUiButtonStrip->setModel(mModel.getChildWithProperty("name", mUiButtonStrip->getName()));
    
	//[/Constructor]
}

MainUi::~MainUi()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    mUiButtonStrip = nullptr;
    mUiSliderStrip = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainUi::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainUi::resized()
{
    //[UserPreResize] Add your own custom resize code here..
	//[/UserPreResize]
    mUiButtonStrip->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (1.0000f), proportionOfHeight (0.3300f));
    mUiSliderStrip->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.3300f), proportionOfWidth (1.0000f), proportionOfHeight (0.6600f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MainUi::valueTreePropertyChanged(ValueTree& treeWhosePropertyHasChanged, const Identifier& property)
{
    auto propertyChangedId = property;
    var propertyChanged = treeWhosePropertyHasChanged.getProperty(property);
	auto valueChanged = propertyChanged.isDouble() ? static_cast<double>(propertyChanged) : 0.0;

	mModel.createXml()->writeToFile({"D:/Workspace/Projects/Juce/BilinearOscillator/model_dump_main.xml"}, "");
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
                 constructorParams="Component* parent, ValueTree&amp; model" variableInitialisers="mParent{parent}, mModel{model}"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="435" initialHeight="180">
  <BACKGROUND backgroundColour="ff323e44"/>
  <JUCERCOMP name="ButtonStrip" id="94d533df8a0dd9aa" memberName="mUiButtonStrip"
             virtualName="UiButtonStrip" explicitFocusOrder="0" pos="0% 0% 100% 32.778%"
             sourceFile="UiButtonStrip.cpp" constructorParams="this, mModel"/>
  <JUCERCOMP name="SliderStrip" id="187099a553730501" memberName="mUiSliderStrip"
             virtualName="UiSliderStrip" explicitFocusOrder="0" pos="0% 32.778% 100% 66.111%"
             sourceFile="UiSliderStrip.cpp" constructorParams="this, mModel"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
