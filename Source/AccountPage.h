/*
  ==============================================================================

    AccountPage.h
    Created: 4 Nov 2023 3:06:15am
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once
#include "ColourPalette.h"

class AccountPage : public juce::Component
{
public:
    AccountPage();
    ~AccountPage(){}

    void resized() override;

private:
    
    //=========================================================
    class AccountPageViewedContent : public juce::Component {
    public:
        AccountPageViewedContent();
        ~AccountPageViewedContent();

        void paint(juce::Graphics&) override;
        void resized() override;
    private:
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AccountPageViewedContent)
    };

    
    AccountPageViewedContent m_ViewedContent;
    juce::Viewport viewport;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AccountPage)
};

