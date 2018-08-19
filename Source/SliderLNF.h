/*
  ==============================================================================

    SliderLNF.h
    Created: 20 Aug 2018 12:04:27am
    Author:  stefa

  ==============================================================================
*/

#pragma once
#include "BaseLNF.h"

class SliderLNF : public BaseLNF
{
public:
    SliderLNF()
	{
        setColour (Slider::thumbColourId, Colours::red);
    }
};
