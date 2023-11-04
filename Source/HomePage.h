/*
  ==============================================================================

    HomePage.h
    Created: 4 Nov 2023 3:04:11am
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ColourPalette.h"

//==============================================================================
/*
*/



class HomePage : public juce::Component
{
public:
    HomePage();
    ~HomePage(){}
    void resized() override;

private:
    
    //=========================================================
    class HomePageViewedContent : public juce::Component {
    public:
        HomePageViewedContent();
        ~HomePageViewedContent();

        void paint(juce::Graphics&) override;
        void resized() override;
        
    private:
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HomePageViewedContent)
    };

    
    HomePageViewedContent m_ViewedContent;
    juce::Viewport viewport;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HomePage)
};


