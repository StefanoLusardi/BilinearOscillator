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
	auto b = mModel.getChildWithProperty(Props[Prop::Id], "SliderStrip");
	auto amp = b.getChildWithProperty(Props[Prop::Id], "SliderAmp");
	auto a = amp[Props[Prop::Value]];
	return (double)a;
}