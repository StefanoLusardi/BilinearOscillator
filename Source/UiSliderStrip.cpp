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
#include "SliderLNF.h"
#include "SliderLNF_Horizontal.h"
#include "SliderLNF_Vertical.h"
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
    mSliderFreq->setRange (20, 5000, 0.001);
    mSliderFreq->setSliderStyle (Slider::LinearHorizontal);
    mSliderFreq->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);
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
    mSliderAmp->setRange (0, 1, 0.001);
    mSliderAmp->setSliderStyle (Slider::LinearHorizontal);
    mSliderAmp->setTextBoxStyle (Slider::TextBoxRight, false, 80, 20);
    mSliderAmp->setColour (Slider::textBoxTextColourId, Colours::black);
    mSliderAmp->setColour (Slider::textBoxOutlineColourId, Colour (0xff8e989b));
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

    mPhaseInvert.reset (new ImageButton ("PhaseInvert"));
    addAndMakeVisible (mPhaseInvert.get());
    mPhaseInvert->setButtonText (String());

    mPhaseInvert->setImages (false, true, true,
                             ImageCache::getFromMemory (phase_invert_png, phase_invert_pngSize), 0.900f, Colour (0xffa45c94),
                             ImageCache::getFromMemory (phase_invert_png, phase_invert_pngSize), 0.900f, Colours::red,
                             ImageCache::getFromMemory (phase_invert_png, phase_invert_pngSize), 0.900f, Colours::lime);

    //[UserPreSize]
	mPhaseInvert->setClickingTogglesState(true);

	/// MODEL BINDING

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

	/// SLIDER BINDINGS

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

	const auto setParamBinding = [&] (ValueTree& uiModel, Slider* component, const Bindings& binding = Bindings::OneWay)
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

	/// BUTTON BINDINGS

	const auto setUiModelParam_Button = [&] (ValueTree& uiModel, auto* component)
	{
		if (!component) { return; }

		if (auto& paramButton = uiModel.getChildWithProperty(Props[Prop::Id], component->getName()); !paramButton.isValid())
		{
			// paramButton does not exist in uiModel. Create its ValueTree and append it to uiModel
			uiModel.appendChild(
			{
				Tags[Tag::Param],
				{
					{ Props[Prop::Id],    component->getName() },
					{ Props[Prop::Value], component->getToggleState() }
				}
			}, nullptr/*&core.getUndoManager()*/);
		}
		else
		{
			// paramButton already exists in uiModel. Set its current value on component
			component->setToggleState(paramButton[Props[Prop::Value]], NotificationType::dontSendNotification);
		}
	};

	const auto setParamBinding_Button = [&] (ValueTree& uiModel, Button* component, const Bindings& binding = Bindings::OneWay)
	{
		auto modelValue = uiModel
			.getChildWithProperty(Props[Prop::Id], component->getName())
			.getPropertyAsValue(Props[Prop::Value], &core.getUndoManager(), false);
		auto& buttonValue = component->getToggleStateValue();

		// OneWay: Ui responds to Model updates.
		if (Bindings::OneWay == binding) { buttonValue.referTo(modelValue); }

		// TwoWay: Model is set after Ui updates.
		if (Bindings::TwoWay == binding) { buttonValue.referTo(modelValue); modelValue.referTo(buttonValue); }
	};

	// Get the ValueTree model for the current Ui
	mUiModel = setUiModel();

	setUiModelParam(mUiModel, mSliderAmp.get());
	setParamBinding(mUiModel, mSliderAmp.get());

	setUiModelParam(mUiModel, mSliderFreq.get());
	setParamBinding(mUiModel, mSliderFreq.get());

	setUiModelParam_Button(mUiModel, mPhaseInvert.get());
	setParamBinding_Button(mUiModel, mPhaseInvert.get());

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

	mPhaseInvert->onClick = [&]
	{
		core.getUndoManager().beginNewTransaction();
		auto uiProperty = mUiModel.getChildWithProperty(Props[Prop::Id], mPhaseInvert->getName());
		uiProperty.setProperty(Props[Prop::Value], mPhaseInvert->getToggleState(), nullptr /*&core.getUndoManager()*/);
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
    mPhaseInvert = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void UiSliderStrip::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = static_cast<float> (proportionOfWidth (0.0000f)), y = static_cast<float> (proportionOfHeight (0.0000f)), width = static_cast<float> (proportionOfWidth (1.0000f)), height = static_cast<float> (proportionOfHeight (1.0000f));
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

void UiSliderStrip::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    mSliderFreq->setBounds (proportionOfWidth (0.1569f), proportionOfHeight (0.0000f), proportionOfWidth (0.6003f), proportionOfHeight (0.5232f));
    mLabelFreq->setBounds (proportionOfWidth (0.0501f), proportionOfHeight (0.0000f), proportionOfWidth (0.1035f), proportionOfHeight (0.5232f));
    mSliderAmp->setBounds (proportionOfWidth (0.1569f), proportionOfHeight (0.5232f), proportionOfWidth (0.6003f), proportionOfHeight (0.5232f));
    mLabelAmp->setBounds (proportionOfWidth (0.0501f), proportionOfHeight (0.5232f), proportionOfWidth (0.1035f), proportionOfHeight (0.5232f));
    mPhaseInvert->setBounds (proportionOfWidth (0.8001f), proportionOfHeight (0.6516f), proportionOfWidth (0.1569f), proportionOfHeight (0.2500f));
    //[UserResized] Add your own custom resize handling here..

	const auto isHorizontal = getWidth() >= 3 * getHeight();

	if (mIsHorizontal != isHorizontal)
	{
		if (isHorizontal)
		{
			mLabelAmp->setVisible(true);
			mLabelFreq->setVisible(true);

			mSliderAmp->setTextBoxStyle(Slider::TextBoxRight, false, 80, 20);
			mSliderAmp->setSliderStyle(Slider::LinearHorizontal);

			mSliderFreq->setTextBoxStyle(Slider::TextBoxRight, false, 80, 20);
			mSliderFreq->setSliderStyle(Slider::LinearHorizontal);
		}
		else
		{
			mLabelAmp->setVisible(false);
			mLabelFreq->setVisible(false);

			mSliderAmp->setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
			mSliderAmp->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);

			mSliderFreq->setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
			mSliderFreq->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
		}

		mIsHorizontal = isHorizontal;
	}

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
    <ROUNDRECT pos="0% 0% 100% 100%" cornerSize="20.00000000000000000000" fill="solid: ffffff00"
               hasStroke="1" stroke="5, mitered, butt" strokeColour="solid: ff000000"/>
  </BACKGROUND>
  <SLIDER name="SliderFreq" id="49b85c14e9b29fb6" memberName="mSliderFreq"
          virtualName="" explicitFocusOrder="0" pos="15.69% 0% 60.026% 52.315%"
          textboxtext="ff000000" min="20.00000000000000000000" max="5000.00000000000000000000"
          int="0.00100000000000000002" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="0.50000000000000000000"
          needsCallback="0"/>
  <LABEL name="freq label" id="6bca026c5b9e7e17" memberName="mLabelFreq"
         virtualName="" explicitFocusOrder="0" pos="5.013% 0% 10.352% 52.315%"
         textCol="ff000000" edTextCol="ff000000" edBkgCol="0" labelText="Frequency"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="SliderAmp" id="b06f49a585e9b552" memberName="mSliderAmp"
          virtualName="" explicitFocusOrder="0" pos="15.69% 52.315% 60.026% 52.315%"
          textboxtext="ff000000" textboxoutline="ff8e989b" min="0.00000000000000000000"
          max="1.00000000000000000000" int="0.00100000000000000002" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="0.50000000000000000000" needsCallback="0"/>
  <LABEL name="amp label" id="531e30d8428f3fd" memberName="mLabelAmp"
         virtualName="" explicitFocusOrder="0" pos="5.013% 52.315% 10.352% 52.315%"
         textCol="ff000000" edTextCol="ff000000" edBkgCol="0" labelText="Amplitude"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="33"/>
  <IMAGEBUTTON name="PhaseInvert" id="14f6f7c6a495ed84" memberName="mPhaseInvert"
               virtualName="" explicitFocusOrder="0" pos="80.013% 65.162% 15.69% 25%"
               buttonText="" connectedEdges="0" needsCallback="0" radioGroupId="0"
               keepProportions="1" resourceNormal="phase_invert_png" opacityNormal="0.89999997615814208984"
               colourNormal="ffa45c94" resourceOver="phase_invert_png" opacityOver="0.89999997615814208984"
               colourOver="ffff0000" resourceDown="phase_invert_png" opacityDown="0.89999997615814208984"
               colourDown="ff00ff00"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: phase_invert_png, 1368, "../Resources/Icons/phase_invert.png"
static const unsigned char resource_UiSliderStrip_phase_invert_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,64,0,0,0,64,8,3,0,0,0,157,183,129,236,0,0,1,59,80,76,84,69,0,0,0,255,0,0,255,
0,0,255,0,0,254,0,0,255,0,0,255,0,0,254,0,0,255,0,0,254,0,0,254,0,0,255,0,0,255,0,0,254,0,0,254,0,0,254,0,0,255,0,0,254,0,0,255,0,0,254,0,0,255,0,0,255,0,0,254,0,0,255,0,0,255,0,0,254,0,0,255,0,0,255,
0,0,254,0,0,254,0,0,255,0,0,255,0,0,254,0,0,254,0,0,255,0,0,255,0,0,254,0,0,254,0,0,254,0,0,255,0,0,255,0,0,255,0,0,254,0,0,255,0,0,255,0,0,254,0,0,255,0,0,255,0,0,254,0,0,254,0,0,254,0,0,255,0,0,254,
0,0,255,0,0,255,0,0,255,0,0,254,0,0,254,0,0,255,0,0,254,0,0,254,0,0,255,0,0,255,0,0,254,0,0,255,0,0,255,0,0,255,0,0,254,0,0,255,0,0,254,0,0,254,0,0,254,0,0,254,0,0,255,0,0,255,0,0,254,0,0,254,0,0,254,
0,0,254,0,0,254,0,0,254,0,0,254,0,0,254,0,0,255,0,0,254,0,0,255,0,0,255,0,0,254,0,0,255,0,0,255,0,0,254,0,0,255,0,0,254,0,0,255,0,0,254,0,0,254,0,0,255,0,0,254,0,0,254,0,0,254,0,0,254,0,0,254,0,0,255,
0,0,255,0,0,255,0,0,78,167,167,89,0,0,0,104,116,82,78,83,0,34,102,127,153,178,204,229,51,202,126,14,135,219,116,238,253,177,129,104,78,53,27,4,52,103,8,97,218,236,160,85,9,199,32,194,209,88,210,185,36,
66,228,107,170,223,101,5,193,232,233,71,239,10,37,224,251,164,2,92,254,69,44,247,109,17,241,234,148,225,166,214,181,196,189,174,220,157,230,139,119,244,31,98,249,56,74,252,80,50,248,24,243,124,143,227,
161,217,206,179,150,82,68,136,94,70,31,3,0,0,3,100,73,68,65,84,88,195,189,151,135,114,226,48,16,134,29,122,8,36,161,195,65,104,1,66,66,18,46,141,35,189,247,222,123,189,182,239,255,4,247,203,24,108,99,
217,242,77,230,110,103,64,178,86,159,45,175,181,69,146,244,175,164,199,225,116,185,61,94,242,122,220,46,167,163,231,47,105,159,179,151,244,210,235,247,217,166,251,2,65,226,73,48,208,103,139,239,31,144,
167,15,134,194,145,104,44,158,136,39,163,169,112,104,80,30,27,232,239,204,250,98,134,167,51,108,230,80,54,151,215,13,231,115,217,33,121,21,233,214,117,129,156,92,188,56,204,102,149,202,92,101,185,194,
148,195,69,116,71,208,169,114,166,140,142,65,225,173,153,190,93,205,11,253,216,168,52,142,102,130,163,159,100,79,240,215,45,236,83,247,179,41,95,241,155,226,104,3,24,159,158,17,152,120,102,90,54,231,236,
28,159,47,84,37,145,52,190,97,94,179,193,95,255,252,130,144,151,22,151,216,10,38,141,246,99,188,24,151,150,155,68,236,22,163,93,227,69,216,191,96,227,249,43,171,128,215,10,248,22,69,189,2,223,127,186,
33,230,215,55,192,135,165,42,44,57,172,83,164,49,46,178,63,147,77,204,219,66,59,131,54,173,85,192,123,252,54,248,109,112,59,114,15,251,33,163,81,244,99,255,213,197,252,46,248,189,86,183,142,61,169,122,
86,31,252,175,38,230,89,136,216,111,95,212,224,155,29,239,198,22,170,136,249,3,230,102,234,101,137,40,160,177,64,89,200,31,130,63,210,92,151,225,219,74,215,7,255,23,242,199,224,79,116,35,136,15,74,148,
131,69,179,34,254,148,197,163,132,110,40,75,237,160,2,227,228,4,252,25,248,243,11,253,88,14,145,86,238,244,32,254,229,173,249,75,236,254,171,235,174,193,60,226,164,28,237,29,68,33,107,254,230,22,207,184,
51,12,135,136,28,172,117,178,221,109,37,247,15,120,129,148,113,60,172,24,193,197,213,170,242,248,4,254,153,163,136,16,185,88,235,38,138,90,221,128,133,243,23,158,34,74,228,102,173,135,40,105,193,191,130,
127,227,106,98,68,30,214,194,45,226,230,252,59,41,207,49,74,28,46,200,90,204,72,152,242,31,44,138,155,232,22,20,135,180,90,1,203,0,31,102,202,246,10,96,131,152,201,20,216,151,222,77,87,151,84,108,96,254,
21,222,192,191,154,155,167,253,21,176,15,34,220,9,47,100,237,166,41,101,31,152,237,196,103,240,79,143,22,55,104,239,68,19,95,192,253,233,225,222,130,239,248,2,223,27,239,224,107,183,55,86,124,199,27,185,
241,224,250,10,25,236,210,138,87,227,1,51,66,119,68,186,56,199,11,156,89,242,44,34,41,185,196,24,19,19,172,206,58,181,230,53,49,209,24,149,79,192,31,11,120,77,84,102,121,161,164,213,29,129,63,20,240,82,
69,147,23,186,50,19,82,6,29,136,120,93,102,210,231,198,125,234,152,215,92,244,185,81,146,50,106,118,222,3,191,43,226,89,46,9,106,175,213,250,96,7,189,109,33,111,168,15,228,10,133,85,104,91,208,108,10,
249,134,161,66,105,215,72,240,15,218,88,23,241,11,156,26,169,85,165,173,225,111,117,69,184,128,121,78,149,214,170,19,145,193,154,203,194,231,207,115,235,196,86,165,74,75,139,34,190,138,245,171,91,72,103,
153,38,139,32,182,106,101,46,63,55,219,58,216,216,168,214,39,185,186,41,104,190,219,60,47,240,100,2,170,113,229,196,82,49,57,177,148,58,39,22,163,252,128,106,132,117,210,65,203,51,83,38,45,241,229,39,
246,145,210,85,79,109,169,104,18,167,182,88,52,194,57,181,25,228,215,239,78,247,179,231,70,38,62,191,225,228,234,180,127,114,109,201,231,206,206,255,83,254,0,185,255,12,32,218,195,199,223,0,0,0,0,73,69,
78,68,174,66,96,130,0,0};

const char* UiSliderStrip::phase_invert_png = (const char*) resource_UiSliderStrip_phase_invert_png;
const int UiSliderStrip::phase_invert_pngSize = 1368;


//[EndFile] You can add extra defines here...
//[/EndFile]
