/*
  ==============================================================================

    Data.h
    Created: 5 Nov 2023 10:09:22pm
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class Data  : public juce::Component
{
public:
    Data();
    ~Data() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Data)
};
