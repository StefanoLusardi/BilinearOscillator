/*
  ==============================================================================

    ParameterTags.h
    Created: 25 Jul 2018 10:32:12pm
    Author:  stefa

  ==============================================================================
*/

#pragma once
#include <map>
	
enum class Tag { Ui, Param };
enum class Prop { Id, Value };
enum class Param { Amp, Freq, Play, Mute};
enum class Wave {Saw, Sqr, Tri };

static std::map<Tag, const char*> Tags 
{ 
	{Tag::Ui, "Ui"}, 
	{Tag::Param, "Param"}
};

static std::map<Prop, const char*> Props 
{ 
	{Prop::Id, "id"}, 
	{Prop::Value, "value"}
};

static std::map<Param, const char*> Params 
{ 
	{Param::Amp,  "Amp"}, 
	{Param::Freq, "Freq"},
	{Param::Play, "Play"},
	{Param::Mute, "Mute"}
};

static std::map<Wave, const char*> Waves 
{ 
	{Wave::Saw, "Saw"}, 
	{Wave::Sqr, "Sqr"}, 
	{Wave::Tri, "Tri"}
};

enum class Bindings { OneWay, TwoWay };