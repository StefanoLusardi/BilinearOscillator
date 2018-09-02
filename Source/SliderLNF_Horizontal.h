/*
  ==============================================================================

    SliderLNF_Horizontal.h
    Created: 2 Sep 2018 4:35:52pm
    Author:  stefa

  ==============================================================================
*/

#pragma once
#include "SliderLNF.h"

class SliderLNF_Horizontal : public SliderLNF
{
public:
    SliderLNF_Horizontal()
	{
        setColour (Slider::thumbColourId, Colours::blue);
    }
};