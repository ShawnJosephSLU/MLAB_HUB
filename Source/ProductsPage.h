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

//==============================================================================
/*
*/

class ProductsPage : public juce::Component
{
public:
    ProductsPage();
    ~ProductsPage(){}

    void resized() override;

private:
    
    //=========================================================
    class ProductsPageViewedContent : public juce::Component {
    public:
        ProductsPageViewedContent();
        ~ProductsPageViewedContent();

        void paint(juce::Graphics&) override;
        void resized() override;
    private:
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProductsPageViewedContent)
    };

    
    ProductsPageViewedContent m_ViewedContent;
    juce::Viewport viewport;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProductsPage)
};

