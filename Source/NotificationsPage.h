/*
  ==============================================================================

    NotificationsPage.h
    Created: 4 Nov 2023 3:06:41am
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ColourPalette.h"

//==============================================================================
/*
*/
class NotificationsPage : public juce::Component
{
public:
    NotificationsPage();
    ~NotificationsPage(){}

    void resized() override;

private:
    
    //=========================================================
    class NotificationsPageViewedContent : public juce::Component {
    public:
        NotificationsPageViewedContent();
        ~NotificationsPageViewedContent();

        void paint(juce::Graphics&) override;
        void resized() override;
    private:
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NotificationsPageViewedContent)
    };

    
    NotificationsPageViewedContent m_ViewedContent;
    juce::Viewport viewport;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NotificationsPage)
};

