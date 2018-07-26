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
enum class Property { Id, Value };

static std::map<Tag, const char*> Tags { {Tag::Ui, "Ui"}, {Tag::Param, "Param"}};
static std::map<Property, const char*> Properties { {Property::Id, "id"}, {Property::Value, "value"}};
