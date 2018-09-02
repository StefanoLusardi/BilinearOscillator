/*
  ==============================================================================

    SliderLNF_Vertical.h
    Created: 2 Sep 2018 4:35:38pm
    Author:  stefa

  ==============================================================================
*/

#pragma once
#include "SliderLNF.h"

class SliderLNF_Vertical : public SliderLNF
{
public:
    SliderLNF_Vertical()
	{
        setColour (Slider::thumbColourId, Colours::green);
    }
};