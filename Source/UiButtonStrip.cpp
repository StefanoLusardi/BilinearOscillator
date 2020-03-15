/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "ParameterTags.h"
#include "Core.h"
//[/Headers]

#include "UiButtonStrip.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
UiButtonStrip::UiButtonStrip (Component* parent, Core& core)
    : mParent{parent}
{
    //[Constructor_pre] You can add your own custom stuff here..
    setName (Widgets[Widget::ButtonStrip]);
    //[/Constructor_pre]

    mButtonSaw.reset (new ImageButton (String()));
    addAndMakeVisible (mButtonSaw.get());

    mButtonSaw->setImages (false, true, true,
                           ImageCache::getFromMemory (saw_png, saw_pngSize), 0.900f, Colour (0xffa45c94),
                           ImageCache::getFromMemory (saw_png, saw_pngSize), 0.900f, Colours::red,
                           ImageCache::getFromMemory (saw_png, saw_pngSize), 0.900f, Colours::lime);
    mButtonSqr.reset (new ImageButton (String()));
    addAndMakeVisible (mButtonSqr.get());

    mButtonSqr->setImages (false, true, true,
                           ImageCache::getFromMemory (sqr_png, sqr_pngSize), 0.900f, Colour (0xffa45c94),
                           ImageCache::getFromMemory (sqr_png, sqr_pngSize), 0.900f, Colours::red,
                           ImageCache::getFromMemory (sqr_png, sqr_pngSize), 0.900f, Colours::lime);
    mButtonTri.reset (new ImageButton (String()));
    addAndMakeVisible (mButtonTri.get());

    mButtonTri->setImages (false, true, true,
                           ImageCache::getFromMemory (tri_png, tri_pngSize), 0.900f, Colour (0xffa45c94),
                           ImageCache::getFromMemory (tri_png, tri_pngSize), 0.900f, Colours::red,
                           ImageCache::getFromMemory (tri_png, tri_pngSize), 0.900f, Colours::lime);

    //[UserPreSize]
	mButtonSaw->setName(Waves[Wave::Saw]);
	mButtonSqr->setName(Waves[Wave::Sqr]);
	mButtonTri->setName(Waves[Wave::Tri]);

	mButtonSaw->setClickingTogglesState(true);
	mButtonSqr->setClickingTogglesState(true);
	mButtonTri->setClickingTogglesState(true);

	mButtonSaw->setRadioGroupId(1);
	mButtonSqr->setRadioGroupId(1);
	mButtonTri->setRadioGroupId(1);

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

	const auto setUiModelParam = [&] (ValueTree& uiModel, auto* component)
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

	const auto setParamBinding = [&] (ValueTree& uiModel, auto* component, const Bindings& binding = Bindings::OneWay)
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

	mUiModel = setUiModel();

	setUiModelParam(mUiModel, mButtonSaw.get());
	setParamBinding(mUiModel, mButtonSaw.get());

	setUiModelParam(mUiModel, mButtonSqr.get());
	setParamBinding(mUiModel, mButtonSqr.get());

	setUiModelParam(mUiModel, mButtonTri.get());
	setParamBinding(mUiModel, mButtonTri.get());

    //[/UserPreSize]

    setSize (435, 60);


    //[Constructor] You can add your own custom stuff here..
	mButtonSaw->onClick = [&]
	{
		if (mButtonSaw->getToggleState()) { core.getUndoManager().beginNewTransaction(); }
		auto uiProperty = mUiModel.getChildWithProperty(Props[Prop::Id], mButtonSaw->getName());
		uiProperty.setProperty(Props[Prop::Value], mButtonSaw->getToggleState(), nullptr /*&core.getUndoManager()*/);
	};

	mButtonSqr->onClick = [&]
	{
		if (mButtonSqr->getToggleState()) { core.getUndoManager().beginNewTransaction(); }
		auto uiProperty = mUiModel.getChildWithProperty(Props[Prop::Id], mButtonSqr->getName());
		uiProperty.setProperty(Props[Prop::Value], mButtonSqr->getToggleState(), nullptr /*&core.getUndoManager()*/);
	};

	mButtonTri->onClick = [&]
	{
		if (mButtonTri->getToggleState()) { core.getUndoManager().beginNewTransaction(); }
		auto uiProperty = mUiModel.getChildWithProperty(Props[Prop::Id], mButtonTri->getName());
		uiProperty.setProperty(Props[Prop::Value], mButtonTri->getToggleState(), nullptr/*&core.getUndoManager()*/);
	};
    //[/Constructor]
}

UiButtonStrip::~UiButtonStrip()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    mButtonSaw = nullptr;
    mButtonSqr = nullptr;
    mButtonTri = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void UiButtonStrip::paint (Graphics& g)
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

void UiButtonStrip::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    mButtonSaw->setBounds (proportionOfWidth (0.0444f), proportionOfHeight (0.2540f), proportionOfWidth (0.2533f), proportionOfHeight (0.5397f));
    mButtonSqr->setBounds (proportionOfWidth (0.3733f), proportionOfHeight (0.2540f), proportionOfWidth (0.2533f), proportionOfHeight (0.5397f));
    mButtonTri->setBounds (proportionOfWidth (0.7022f), proportionOfHeight (0.2540f), proportionOfWidth (0.2533f), proportionOfHeight (0.5397f));
    //[UserResized] Add your own custom resize handling here..
	FlexBox fb;
    fb.flexWrap = FlexBox::Wrap::wrap;
    fb.justifyContent = FlexBox::JustifyContent::spaceAround;

	const auto margin = static_cast<float>(proportionOfHeight(0.1f));
	const auto flexMargin = FlexItem::Margin(margin, margin, margin, margin);

	fb.items.add (FlexItem(*mButtonSaw).withFlex(1).withMargin(flexMargin));
	fb.items.add (FlexItem(*mButtonSqr).withFlex(1).withMargin(flexMargin));
	fb.items.add (FlexItem(*mButtonTri).withFlex(1).withMargin(flexMargin));

	fb.performLayout (getLocalBounds().toFloat());
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

<JUCER_COMPONENT documentType="Component" className="UiButtonStrip" componentName=""
                 parentClasses="public Component" constructorParams="Component* parent, Core&amp; core"
                 variableInitialisers="mParent{parent}" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="435"
                 initialHeight="60">
  <BACKGROUND backgroundColour="0">
    <ROUNDRECT pos="0 0 100% 100%" cornerSize="20.0" fill="solid: ffffff00"
               hasStroke="1" stroke="5, mitered, butt" strokeColour="solid: ff000000"/>
  </BACKGROUND>
  <IMAGEBUTTON name="" id="7db05320ddd74eb0" memberName="mButtonSaw" virtualName=""
               explicitFocusOrder="0" pos="4.415% 25.481% 25.386% 53.846%" buttonText=""
               connectedEdges="0" needsCallback="0" radioGroupId="0" keepProportions="1"
               resourceNormal="saw_png" opacityNormal="0.8999999761581421" colourNormal="ffa45c94"
               resourceOver="saw_png" opacityOver="0.8999999761581421" colourOver="ffff0000"
               resourceDown="saw_png" opacityDown="0.8999999761581421" colourDown="ff00ff00"/>
  <IMAGEBUTTON name="" id="30c631eda481bac9" memberName="mButtonSqr" virtualName=""
               explicitFocusOrder="0" pos="37.307% 25.481% 25.386% 53.846%"
               buttonText="" connectedEdges="0" needsCallback="0" radioGroupId="0"
               keepProportions="1" resourceNormal="sqr_png" opacityNormal="0.8999999761581421"
               colourNormal="ffa45c94" resourceOver="sqr_png" opacityOver="0.8999999761581421"
               colourOver="ffff0000" resourceDown="sqr_png" opacityDown="0.8999999761581421"
               colourDown="ff00ff00"/>
  <IMAGEBUTTON name="" id="4ea5ec108ddbef92" memberName="mButtonTri" virtualName=""
               explicitFocusOrder="0" pos="70.199% 25.481% 25.386% 53.846%"
               buttonText="" connectedEdges="0" needsCallback="0" radioGroupId="0"
               keepProportions="1" resourceNormal="tri_png" opacityNormal="0.8999999761581421"
               colourNormal="ffa45c94" resourceOver="tri_png" opacityOver="0.8999999761581421"
               colourOver="ffff0000" resourceDown="tri_png" opacityDown="0.8999999761581421"
               colourDown="ff00ff00"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: saw_png, 383, "../Resources/Icons/saw.png"
static const unsigned char resource_UiButtonStrip_saw_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,64,0,0,0,64,8,6,0,0,0,170,105,113,222,0,0,1,70,73,68,65,84,120,156,237,219,219,13,133,
32,16,69,209,221,151,253,87,99,17,220,47,19,227,245,129,192,12,243,144,6,216,103,37,126,25,40,235,82,202,186,20,178,158,13,32,45,194,30,32,37,194,17,32,29,194,126,116,74,132,227,224,116,8,103,99,83,33,
92,13,77,131,112,55,50,5,194,211,192,240,8,53,227,66,35,212,14,11,139,240,102,84,72,132,183,131,194,33,180,140,9,133,208,58,36,12,66,207,136,16,8,189,3,220,35,140,136,119,141,48,42,220,45,194,200,104,
151,8,163,131,221,33,72,196,186,66,144,10,117,131,32,25,233,2,65,58,208,60,130,70,156,105,4,173,48,179,8,154,81,38,17,180,131,204,33,204,136,49,133,48,43,196,12,194,204,136,153,8,38,240,247,33,179,62,
67,205,59,47,207,12,4,83,0,160,143,96,14,0,116,17,76,2,128,30,130,89,0,208,65,48,13,0,242,8,230,1,64,22,193,5,0,200,33,184,1,0,25,4,87,0,48,30,193,29,0,140,69,112,9,0,227,16,220,2,192,24,4,215,0,208,143,
224,30,0,250,16,66,0,64,59,66,24,0,104,67,8,5,0,239,17,194,1,192,59,132,144,0,80,143,16,22,0,234,16,66,3,192,51,66,120,0,184,71,72,1,0,215,8,105,0,224,28,33,21,0,252,35,164,3,128,239,145,40,240,61,21,
6,12,253,154,159,121,54,128,31,106,152,205,198,99,175,254,46,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* UiButtonStrip::saw_png = (const char*) resource_UiButtonStrip_saw_png;
const int UiButtonStrip::saw_pngSize = 383;

// JUCER_RESOURCE: sqr_png, 251, "../Resources/Icons/sqr.png"
static const unsigned char resource_UiButtonStrip_sqr_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,64,0,0,0,64,8,6,0,0,0,170,105,113,222,0,0,0,194,73,68,65,84,120,156,237,208,65,13,192,
64,12,196,192,227,85,254,104,10,226,202,34,19,169,142,148,183,189,62,247,125,238,134,63,234,244,240,53,1,254,202,231,2,154,207,5,52,159,11,104,62,23,208,124,46,160,249,92,64,243,185,128,230,115,1,205,
231,2,154,207,5,52,159,11,104,62,23,208,124,46,160,249,92,64,243,185,128,230,115,1,205,231,2,154,207,5,52,159,11,104,62,23,208,124,46,160,249,92,64,243,185,128,230,115,1,205,231,2,154,207,5,52,159,11,
104,62,23,208,124,46,160,249,92,64,241,245,110,46,82,128,2,20,160,0,5,40,64,1,10,48,205,93,35,82,128,2,20,160,0,5,40,64,1,10,48,205,93,35,82,128,2,20,160,0,5,40,64,1,10,48,205,93,35,82,128,109,1,212,235,
253,60,192,7,17,76,150,213,241,152,54,141,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* UiButtonStrip::sqr_png = (const char*) resource_UiButtonStrip_sqr_png;
const int UiButtonStrip::sqr_pngSize = 251;

// JUCER_RESOURCE: tri_png, 406, "../Resources/Icons/tri.png"
static const unsigned char resource_UiButtonStrip_tri_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,64,0,0,0,64,8,6,0,0,0,170,105,113,222,0,0,1,93,73,68,65,84,120,156,237,153,75,14,194,
48,12,68,125,175,222,255,52,61,68,88,141,84,65,91,210,36,254,140,221,183,66,208,198,158,55,192,2,68,38,105,251,214,218,190,181,217,115,40,65,248,87,64,69,9,223,225,203,10,56,62,46,35,225,44,112,73,1,103,
207,165,151,112,23,180,148,128,187,215,210,74,232,9,88,66,64,207,53,233,36,60,9,150,90,192,147,107,211,72,24,9,148,82,192,200,61,244,18,102,130,164,18,48,115,47,173,132,21,1,82,8,88,113,6,157,132,149,
139,83,11,88,121,22,141,4,141,133,41,5,104,156,25,94,130,230,162,84,2,52,207,14,43,193,98,65,10,1,22,51,194,73,176,92,44,180,0,203,89,97,36,120,44,20,82,128,199,76,119,9,158,139,132,18,224,57,219,93,130,
39,222,5,120,204,253,89,194,243,59,200,114,230,37,175,0,227,119,65,200,239,30,15,1,22,179,186,177,106,37,100,251,192,82,128,230,140,97,180,219,9,221,62,176,16,160,113,246,50,180,90,162,104,31,104,253,
34,77,17,94,100,253,194,84,225,193,234,127,165,104,5,204,46,78,25,30,204,46,79,219,62,152,13,64,29,30,140,134,160,111,31,140,6,73,17,30,60,13,147,166,125,240,52,80,170,240,160,55,84,186,246,65,79,176,
180,225,65,175,0,203,157,76,185,107,56,125,251,224,159,0,143,157,76,57,107,186,76,251,224,74,128,231,78,166,28,27,47,215,62,40,29,94,228,21,32,34,107,62,251,31,222,133,199,126,216,228,109,65,0,0,0,0,73,
69,78,68,174,66,96,130,0,0};

const char* UiButtonStrip::tri_png = (const char*) resource_UiButtonStrip_tri_png;
const int UiButtonStrip::tri_pngSize = 406;


//[EndFile] You can add extra defines here...
//[/EndFile]

