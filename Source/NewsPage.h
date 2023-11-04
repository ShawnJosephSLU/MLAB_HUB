/*
  ==============================================================================

    NewsPage.h
    Created: 4 Nov 2023 3:05:56am
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ColourPalette.h"
//==============================================================================
/*
*/

class NewsPage : public juce::Component
{
public:
    NewsPage();
    ~NewsPage(){}

    void resized() override;

private:
    
    //=========================================================
    class NewsPageViewedContent : public juce::Component {
    public:
        NewsPageViewedContent();
        ~NewsPageViewedContent();

        void paint(juce::Graphics&) override;
        void resized() override;
    private:
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NewsPageViewedContent)
    };

    
    NewsPageViewedContent m_ViewedContent;
    juce::Viewport viewport;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NewsPage)
};


