/*
  ==============================================================================

    ProductsPage.h
    Created: 4 Nov 2023 3:05:45am
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

class ProductsPage : public juce::Component
{
public:
    ProductsPage();
    ~ProductsPage(){}

    void resized() override;
    void paint(juce::Graphics&) override;

    // stores the scroll position of the viewport
    int getScrollPosition() {return m_ScrollPosition;}
private:
    
    //=========================================================
    class ProductsPageViewedContent : public juce::Component {
    public:
        ProductsPageViewedContent();
        ~ProductsPageViewedContent();

        void paint(juce::Graphics&) override;
        void resized() override;
        void createNewDataTile(std::vector<Data*> data); //TODO: Not sure if this should me a limited or unlimtied vecto
        int getPageHeight() {return m_PageHeight;}
    private:
        //vector of tiles based on data from from the data model
        std::vector<PageTile*> m_ProductsDataTiles;  //TODO: figure out a way to use smart pointers for auto garbage collection
        
        //stores the value of the bottom of the page
        int m_PageHeight;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProductsPageViewedContent)
    };

    
    ProductsPageViewedContent m_ViewedContent;
    juce::Viewport viewport;
    int m_ScrollPosition;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProductsPage)
};

