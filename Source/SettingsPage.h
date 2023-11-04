/*
  ==============================================================================

    SettingsPage.h
    Created: 4 Nov 2023 3:04:53am
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ColourPalette.h"
//==============================================================================
/*
*/


class SettingsPage : public juce::Component
{
public:
    SettingsPage();
    ~SettingsPage(){}
    void resized() override;

private:
    
    //=========================================================
    class SettingsPageViewedContent : public juce::Component {
    public:
        SettingsPageViewedContent();
        ~SettingsPageViewedContent();

        void paint(juce::Graphics&) override;
        void resized() override;
        
    private:
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SettingsPageViewedContent)
    };

    
    SettingsPageViewedContent m_ViewedContent;
    juce::Viewport viewport;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SettingsPage)
};



