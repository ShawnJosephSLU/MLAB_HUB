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
#include "PageTile.h"
#include "Data.h"

//==============================================================================
/*
*/



class HomePage : public juce::Component
{
public:
    HomePage();
    ~HomePage(){}
    void resized() override;
    void paint(juce::Graphics&) override;

    // stores the scroll position of the viewport
    int getScrollPosition() {return m_ScrollPosition;}
private:
    
    //=========================================================
    class HomePageViewedContent : public juce::Component {
    public:
        HomePageViewedContent();
        ~HomePageViewedContent();

        void paint(juce::Graphics&) override;
        void resized() override;
        
        // creates a new data tile and pushes it to homeDataTiles
        void createNewDataTile(std::vector<Data*> data); //TODO: Not sure if this should me a limited or unlimtied vector
        
        int getPageHeight() {return m_PageHeight;}
        
    private:
        
        //vector of tiles based on data from from the data model
        std::vector<PageTile*> m_HomeDataTiles;  //TODO: figure out a way to use smart pointers for auto garbage collection
        
        //stores the value of the bottom of the page
        int m_PageHeight;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HomePageViewedContent)
    };

    
    HomePageViewedContent m_ViewedContent;
    juce::Viewport viewport;
    int m_ScrollPosition;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HomePage)
};


