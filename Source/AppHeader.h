/*
  ==============================================================================

    AppHeader.h
    Created: 6 Nov 2023 12:28:41am
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class AppHeader  : public juce::Component
{
public:
    AppHeader();
    ~AppHeader() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AppHeader)
};
