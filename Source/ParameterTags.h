#pragma once
#include <map>
	
enum class Tag { Ui, Param };
static std::map<Tag, const char*> Tags 
{ 
	{Tag::Ui, "Ui"}, 
	{Tag::Param, "Param"}
};

enum class Prop { Id, Value };
static std::map<Prop, const char*> Props 
{ 
	{Prop::Id, "id"}, 
	{Prop::Value, "value"}
};

enum class Param { Amp, Freq, PhInv};
static std::map<Param, const char*> Params 
{ 
	{Param::Amp,   "Amp"}, 
	{Param::Freq,  "Freq"},
	{Param::PhInv, "PhInv"}
};

enum class Wave {Saw, Sqr, Tri, None};
static std::map<Wave, const char*> Waves 
{ 
	{Wave::Saw, "Saw"}, 
	{Wave::Sqr, "Sqr"}, 
	{Wave::Tri, "Tri"}
};

enum class Widget {Osc, Plotter, SliderStrip, ButtonStrip};
static std::map<Widget, const char*> Widgets 
{ 
	{Widget::Osc,		  "Osc"}, 
	{Widget::Plotter,	  "Plotter"}, 
	{Widget::SliderStrip, "SliderStrip"}, 
	{Widget::ButtonStrip, "ButtonStrip"}, 
};

enum class Bindings { OneWay, TwoWay };