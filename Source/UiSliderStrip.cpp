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
#include "ParameterTags.h"
#include "Core.h"
//[/Headers]

#include "UiSliderStrip.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
UiSliderStrip::UiSliderStrip (Component* parent, Core& core)
    : mParent{parent}
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    setName ("SliderStrip");
    mSliderFreq.reset (new Slider ("SliderFreq"));
    addAndMakeVisible (mSliderFreq.get());
    mSliderFreq->setRange (0, 1, 0);
    mSliderFreq->setSliderStyle (Slider::LinearHorizontal);
    mSliderFreq->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);
    mSliderFreq->setColour (Slider::thumbColourId, Colour (0xffa45c94));
    mSliderFreq->setColour (Slider::textBoxTextColourId, Colours::black);
    mSliderFreq->setSkewFactor (0.5);

    mLabelFreq.reset (new Label ("freq label",
                                 TRANS("Frequency")));
    addAndMakeVisible (mLabelFreq.get());
    mLabelFreq->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    mLabelFreq->setJustificationType (Justification::centredLeft);
    mLabelFreq->setEditable (false, false, false);
    mLabelFreq->setColour (Label::textColourId, Colours::black);
    mLabelFreq->setColour (TextEditor::textColourId, Colours::black);
    mLabelFreq->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    mSliderAmp.reset (new Slider ("SliderAmp"));
    addAndMakeVisible (mSliderAmp.get());
    mSliderAmp->setRange (0, 1, 0);
    mSliderAmp->setSliderStyle (Slider::LinearHorizontal);
    mSliderAmp->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);
    mSliderAmp->setColour (Slider::thumbColourId, Colour (0xffa45c94));
    mSliderAmp->setColour (Slider::textBoxTextColourId, Colours::black);
    mSliderAmp->setSkewFactor (0.5);

    mLabelAmp.reset (new Label ("amp label",
                                TRANS("Amplitude")));
    addAndMakeVisible (mLabelAmp.get());
    mLabelAmp->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    mLabelAmp->setJustificationType (Justification::centredLeft);
    mLabelAmp->setEditable (false, false, false);
    mLabelAmp->setColour (Label::textColourId, Colours::black);
    mLabelAmp->setColour (TextEditor::textColourId, Colours::black);
    mLabelAmp->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
	const auto setUiModel = [&] () -> ValueTree
	{
		if (!core.getModel().getChildWithProperty(Props[Prop::Id], this->getName()).isValid())
		{
			// model does not contain current Ui ValueTree. Create it and add it to model.
			core.getModel().appendChild( { Tags[Tag::Ui], {{Props[Prop::Id], this->getName()}} }, nullptr/*&core.getUndoManager()*/);
		}

		// Return current Ui ValueTree.
		return core.getModel().getChildWithProperty(Props[Prop::Id], this->getName());
	};

	const auto setUiModelParam = [&] (ValueTree& uiModel, auto* component)
	{
		if (!component) { return; }

		if (auto& paramSlider = uiModel.getChildWithProperty(Props[Prop::Id], component->getName()); !paramSlider.isValid())
		{
			// paramSlider does not exist in uiModel. Create its ValueTree and append it to uiModel
			uiModel.appendChild(
			{
				Tags[Tag::Param],
				{
					{ Props[Prop::Id],    component->getName() },
					{ Props[Prop::Value], component->getValue() }
				}
			}, nullptr/*&core.getUndoManager()*/);
		}
		else
		{
			// paramSlider already exists in uiModel. Set its current value on component
			component->setValue(paramSlider[Props[Prop::Value]], NotificationType::dontSendNotification);
		}
	};

	const auto setParamBinding = [&] (ValueTree& uiModel, auto* component, const Bindings& binding = Bindings::OneWay)
	{
		auto modelValue = uiModel
			.getChildWithProperty(Props[Prop::Id], component->getName())
			.getPropertyAsValue(Props[Prop::Value], &core.getUndoManager(), false);
		auto& sliderValue = component->getValueObject();

		// OneWay: Ui responds to Model updates.
		if (Bindings::OneWay == binding) { sliderValue.referTo(modelValue); }

		// TwoWay: Model is set after Ui updates.
		if (Bindings::TwoWay == binding) { sliderValue.referTo(modelValue); modelValue.referTo(sliderValue); }
	};

	// Get the ValueTree model for the current Ui
	mUiModel = setUiModel();

	setUiModelParam(mUiModel, mSliderAmp.get());
	setParamBinding(mUiModel, mSliderAmp.get());

	setUiModelParam(mUiModel, mSliderFreq.get());
	setParamBinding(mUiModel, mSliderFreq.get());

    //[/UserPreSize]

    setSize (435, 120);


    //[Constructor] You can add your own custom stuff here..
	mSliderAmp ->onDragStart = [&] { core.getUndoManager().beginNewTransaction(); };
	mSliderFreq->onDragStart = [&] { core.getUndoManager().beginNewTransaction(); };
	mSliderAmp ->onDragEnd   = [&] { core.getUndoManager().beginNewTransaction(); };
	mSliderFreq->onDragEnd   = [&] { core.getUndoManager().beginNewTransaction(); };

	mSliderAmp->onValueChange = [&]
	{
		auto uiProperty = mUiModel.getChildWithProperty(Props[Prop::Id], mSliderAmp->getName());
		uiProperty.setProperty(Props[Prop::Value], mSliderAmp->getValue(), nullptr);
	};

	mSliderFreq->onValueChange = [&]
	{
		auto uiProperty = mUiModel.getChildWithProperty(Props[Prop::Id], mSliderFreq->getName());
		uiProperty.setProperty(Props[Prop::Value], mSliderFreq->getValue(), nullptr);
	};
    //[/Constructor]
}

UiSliderStrip::~UiSliderStrip()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    mSliderFreq = nullptr;
    mLabelFreq = nullptr;
    mSliderAmp = nullptr;
    mLabelAmp = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void UiSliderStrip::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = static_cast<float> (proportionOfWidth (0.0000f)), y = static_cast<float> (proportionOfHeight (0.0000f)), width = static_cast<float> (proportionOfWidth (1.0000f)), height = static_cast<float> (proportionOfHeight (0.5000f));
        Colour fillColour = Colours::yellow;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 20.000f);
    }

    {
        float x = static_cast<float> (proportionOfWidth (0.0000f)), y = static_cast<float> (proportionOfHeight (0.5000f)), width = static_cast<float> (proportionOfWidth (1.0000f)), height = static_cast<float> (proportionOfHeight (0.5000f));
        Colour fillColour = Colours::yellow;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 20.000f);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void UiSliderStrip::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    mSliderFreq->setBounds (proportionOfWidth (0.2555f), proportionOfHeight (0.0000f), proportionOfWidth (0.6991f), proportionOfHeight (0.5151f));
    mLabelFreq->setBounds (proportionOfWidth (0.0517f), proportionOfHeight (0.0000f), proportionOfWidth (0.2555f), proportionOfHeight (0.5151f));
    mSliderAmp->setBounds (proportionOfWidth (0.2555f), proportionOfHeight (0.5151f), proportionOfWidth (0.6991f), proportionOfHeight (0.5151f));
    mLabelAmp->setBounds (proportionOfWidth (0.0517f), proportionOfHeight (0.5151f), proportionOfWidth (0.2555f), proportionOfHeight (0.5151f));
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

<JUCER_COMPONENT documentType="Component" className="UiSliderStrip" componentName="SliderStrip"
                 parentClasses="public Component" constructorParams="Component* parent, Core&amp; core"
                 variableInitialisers="mParent{parent}" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="435"
                 initialHeight="120">
  <BACKGROUND backgroundColour="0">
    <ROUNDRECT pos="0% 0% 100% 50%" cornerSize="20.00000000000000000000" fill="solid: ffffff00"
               hasStroke="0"/>
    <ROUNDRECT pos="0% 50% 100% 50%" cornerSize="20.00000000000000000000" fill="solid: ffffff00"
               hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="SliderFreq" id="49b85c14e9b29fb6" memberName="mSliderFreq"
          virtualName="" explicitFocusOrder="0" pos="25.554% 0% 69.905% 51.511%"
          thumbcol="ffa45c94" textboxtext="ff000000" min="0.00000000000000000000"
          max="1.00000000000000000000" int="0.00000000000000000000" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="0.50000000000000000000" needsCallback="0"/>
  <LABEL name="freq label" id="6bca026c5b9e7e17" memberName="mLabelFreq"
         virtualName="" explicitFocusOrder="0" pos="5.174% 0% 25.554% 51.511%"
         textCol="ff000000" edTextCol="ff000000" edBkgCol="0" labelText="Frequency"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="SliderAmp" id="b06f49a585e9b552" memberName="mSliderAmp"
          virtualName="" explicitFocusOrder="0" pos="25.554% 51.511% 69.905% 51.511%"
          thumbcol="ffa45c94" textboxtext="ff000000" min="0.00000000000000000000"
          max="1.00000000000000000000" int="0.00000000000000000000" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="0.50000000000000000000" needsCallback="0"/>
  <LABEL name="amp label" id="531e30d8428f3fd" memberName="mLabelAmp"
         virtualName="" explicitFocusOrder="0" pos="5.174% 51.511% 25.554% 51.511%"
         textCol="ff000000" edTextCol="ff000000" edBkgCol="0" labelText="Amplitude"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
