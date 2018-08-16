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

#include "UiPlotter.h"
//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
UiPlotter::UiPlotter (Component* parent, Core& core)
    : mParent{parent}
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    setName ("UiPlotter");

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	auto uiModel  = core.getModel().getChildWithProperty(Props[Prop::Id], "SliderStrip");
	auto ampModel = uiModel.getChildWithProperty(Props[Prop::Id], "SliderAmp").getPropertyAsValue(Props[Prop::Value], nullptr, false);

	amp.referTo(ampModel);
    //[/Constructor]
}

UiPlotter::~UiPlotter()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}


//==============================================================================
void UiPlotter::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = 0.0f, y = 0.0f, width = static_cast<float> (proportionOfWidth (1.0000f)), height = static_cast<float> (proportionOfHeight (1.0000f));
        Colour fillColour = Colours::yellow;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 20.000f);
    }

    //[UserPaint] Add your own custom painting code here..

	Path p;
	g.setColour(Colours::blueviolet);

	const auto yc = getLocalBounds().getCentreY() * float(amp.getValue());
	const auto xq = getLocalBounds().getWidth() / 4.0f;

	const auto x_1_4 = xq;
	const auto x_2_4 = xq * 2;
	const auto x_3_4 = xq * 3;

	auto y = yc;
    p.startNewSubPath(Point<float>(0, y));

	auto step = 0.0f;
	for (auto x = 0; x < getLocalBounds().getWidth(); ++x)
	{
		if (x >= 0	   && x < x_1_4) { step =  yc / xq; }
		if (x >= x_1_4 && x < x_2_4) { step = -yc / xq; }
		if (x >= x_2_4 && x < x_3_4) { step = -yc / xq; }
		if (x >= x_3_4)		     	 { step =  yc / xq; }

		y += step;
		p.lineTo(Point<float>(x, y));
	}

	p.applyTransform(AffineTransform::translation(0.0f, getLocalBounds().getCentreY() - yc));
	g.strokePath(p, PathStrokeType(5.0f));

    //[/UserPaint]
}

void UiPlotter::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void UiPlotter::update(const var& propertyChanged, const var& propertyValue)
{
	DBG("Property Changed: " << propertyChanged.toString());
	DBG("Property Value  : " << propertyValue.toString() << "\n");

	// = float(propertyValue);
	repaint();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="UiPlotter" componentName="UiPlotter"
                 parentClasses="public Component" constructorParams="Component* parent, Core&amp; core"
                 variableInitialisers="mParent{parent}" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="0">
    <ROUNDRECT pos="0 0 100% 100%" cornerSize="20.00000000000000000000" fill="solid: ffffff00"
               hasStroke="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
