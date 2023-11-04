/*
  ==============================================================================

    NewsPage.cpp
    Created: 4 Nov 2023 3:05:56am
    Author:  Shawn Joseph

  ==============================================================================
*/

#include <JuceHeader.h>
#include "NewsPage.h"

NewsPage::NewsPage()
{
   

    // Create a viewport and set its size
    addAndMakeVisible(viewport);
    viewport.setViewedComponent(&m_ViewedContent, false);
    viewport.setScrollBarsShown(false, false);
    
}



void NewsPage::resized()
{
    // Set the bounds of the viewport to match the size of the parent component
    viewport.setBounds(getLocalBounds());
    
    // Set the content size
    m_ViewedContent.setBounds(0, 0, getWidth(), 800);

}
//========================================================================================

NewsPage::NewsPageViewedContent::NewsPageViewedContent() { // constructor of the content view
   


}

NewsPage::NewsPageViewedContent::~NewsPageViewedContent() { // destructor of the content view
    
    
}

void NewsPage::NewsPageViewedContent::paint(juce::Graphics & g){ // paint method of content view
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
    g.drawText("News Page is Under Maintenance", getLocalBounds(), juce::Justification::centred, true);
    
}

void NewsPage::NewsPageViewedContent::resized() { // resized method of the content view
    
    
    
}

