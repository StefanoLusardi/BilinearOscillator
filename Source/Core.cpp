/*
  ==============================================================================

    Core.cpp
    Created: 31 Jul 2018 11:29:14pm
    Author:  stefa

  ==============================================================================
*/

#include "Core.h"
#include "ParameterTags.h"

Core::Core()
{
	const StringRef xmlModelFile{"model_dump_ui.xml"};
	const auto xmlModelFilePath{File::getCurrentWorkingDirectory().getChildFile(xmlModelFile)};
	const std::unique_ptr<XmlElement> xmlElementModel{XmlDocument::parse(xmlModelFilePath)};
	mModel = xmlElementModel != nullptr ? ValueTree::fromXml(*xmlElementModel) : ValueTree("MainUi");
}

ValueTree& Core::getModel() { return mModel; }

UndoManager& Core::getUndoManager() { return mUndoManager; }

double Core::getAmp() const
{
	const auto uiSlider  { mModel.getChildWithProperty(Props[Prop::Id], "SliderStrip") };
	const auto sliderAmp { uiSlider.getChildWithProperty(Props[Prop::Id], "SliderAmp") };
	return sliderAmp[Props[Prop::Value]];
}

double Core::getFreq() const
{
	const auto uiSlider  { mModel.getChildWithProperty(Props[Prop::Id], "SliderStrip") };
	const auto sliderFreq { uiSlider.getChildWithProperty(Props[Prop::Id], "SliderFreq") };
	return sliderFreq[Props[Prop::Value]];
}