/*
  ==============================================================================

    PageTile.h
    Created: 4 Nov 2023 6:20:20pm
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ColourPalette.h"

//==============================================================================
/*
*/
class PageTile  : public juce::Component
{
public:
    PageTile();
    ~PageTile() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PageTile)
};
