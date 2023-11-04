/*
  ==============================================================================

    ProductsPage.cpp
    Created: 4 Nov 2023 3:05:45am
    Author:  Shawn Joseph

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ProductsPage.h"

ProductsPage::ProductsPage()
{
   

    // Create a viewport and set its size
    addAndMakeVisible(viewport);
    viewport.setViewedComponent(&m_ViewedContent, false);
    viewport.setScrollBarsShown(false, false);

}

void ProductsPage::resized()
{
    // Set the bounds of the viewport to match the size of the parent component
    viewport.setBounds(getLocalBounds());
    
    // Set the content size
    m_ViewedContent.setBounds(0, 0, getWidth(), 800);

}
//========================================================================================

ProductsPage::ProductsPageViewedContent::ProductsPageViewedContent() { // constructor of the content view
   


}

ProductsPage::ProductsPageViewedContent::~ProductsPageViewedContent() { // destructor of the content view
    
    
}

void ProductsPage::ProductsPageViewedContent::paint(juce::Graphics & g){ // paint method of content view
    if(juce::Desktop::getInstance().isDarkModeActive() == true){
        g.fillAll(ColourPalette::getDarkModeBgColour());
    }
    else {
        g.fillAll(ColourPalette::getLightModeBgColour());

    }
    
    
    if(juce::Desktop::getInstance().isDarkModeActive() == true){
        g.setColour(ColourPalette::getDarkModeMainTextColour());
        
    }
    else {
        g.setColour(ColourPalette::getLightModeMainTextColour());
    }
    g.setFont(14.0f);
    g.drawText("Products Page is Under Maintenance", getLocalBounds(), juce::Justification::centred, true);
    
}

void ProductsPage::ProductsPageViewedContent::resized() { // resized method of the content view
    
    
    
}

