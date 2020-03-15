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

void Core::setupModel()
{
	/*findTreeT (myTree, [] (const ValueTree& v)
	{
		if (auto* p = v.getPropertyPointer (propertyToSearchFor))
			DBG (propertyToSearchFor << ": " << p->toString());
	});*/

	const auto osc1Id { String("1") };
	const auto osc1Model = findTree(mModel, Widgets[Widget::Osc] + osc1Id);

	auto osc1Amp = findTree(osc1Model, Params[Param::Amp]);
	auto osc1Freq = findTree(osc1Model, Params[Param::Freq]);
	auto osc1PhInv = findTree(osc1Model, Params[Param::PhInv]);

	mOsc1Amp.referTo(osc1Amp, Props[Prop::Value], nullptr);
	mOsc1Freq.referTo(osc1Freq, Props[Prop::Value], nullptr);
	mOsc1PhInv.referTo(osc1PhInv, Props[Prop::Value], nullptr);

	const auto osc2Id { String("2") };
	const auto osc2Model = findTree(mModel, Widgets[Widget::Osc] + osc2Id);

	auto osc2Amp = findTree(osc2Model, Params[Param::Amp]);
	auto osc2Freq = findTree(osc2Model, Params[Param::Freq]);
	auto osc2PhInv = findTree(osc2Model, Params[Param::PhInv]);

	mOsc2Amp.referTo(osc2Amp, Props[Prop::Value], nullptr);
	mOsc2Freq.referTo(osc2Freq, Props[Prop::Value], nullptr);
	mOsc2PhInv.referTo(osc2PhInv, Props[Prop::Value], nullptr);
}
