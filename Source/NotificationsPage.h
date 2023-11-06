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
#include "PageTile.h"
#include "Data.h"

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
        
        // creates a new data tile and pushes it to homeDataTiles
        void createNewDataTile(std::vector<Data*> data); //TODO: Not sure if this should me a limited or unlimtied vector
        
        int getPageHeight() {return m_PageHeight;}
        
    private:
        
        //vector of tiles based on data from from the data model
        std::vector<PageTile*> m_NotificationsPageTiles;  //TODO: figure out a way to use smart pointers for auto garbage collection
        
        //stores the value of the bottom of the page
        int m_PageHeight;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NotificationsPageViewedContent)
    };

    
    NotificationsPageViewedContent m_ViewedContent;
    juce::Viewport viewport;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NotificationsPage)
};


