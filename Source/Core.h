/*
  ==============================================================================

    Core.h
    Created: 31 Jul 2018 11:29:14pm
    Author:  stefa

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "ParameterTags.h"

class Core
{
public:
	Core();

	Core(const Core& other) = delete;
	Core(Core&& other) noexcept = delete;
	Core& operator=(const Core& other) = delete;
	Core& operator=(Core&& other) noexcept = delete;

	ValueTree& getModel();
	UndoManager& getUndoManager();

	double getOsc1Amp()   const { return mOsc1Amp; }
	double getOsc2Amp()   const { return mOsc2Amp; }
	double getOsc1Freq()  const { return mOsc1Freq; }
	double getOsc2Freq()  const { return mOsc2Freq; }
	bool   getOsc1PhInv() const { return mOsc1PhInv; }
	bool   getOsc2PhInv() const { return mOsc2PhInv; }

	void setupModel();

private:
	ValueTree mModel;
	UndoManager mUndoManager;

	CachedValue<double> mOsc1Amp;
	CachedValue<double> mOsc2Amp;
	CachedValue<double> mOsc1Freq;
	CachedValue<double> mOsc2Freq;
	CachedValue<bool>   mOsc1PhInv;
	CachedValue<bool>   mOsc2PhInv;

};

template <typename Function>
static ValueTree findTreeT (const ValueTree& tree, const Function& function)
{
    function (tree);

    for (auto&& child : tree)
        findTreeT(child, function);
}

inline ValueTree findTree(ValueTree tree, const Identifier& propertyId)
{
    for (auto& child : tree)
    {
		DBG(child.getProperty(Props[Prop::Id]).toString());
        if (static_cast<Identifier>(child.getProperty(Props[Prop::Id])) == propertyId)
        {
            return ValueTree(child);
        }

        if(auto t = findTree(child, propertyId); t.isValid())
        {
	        return t;
        }
    }
	return {};
}