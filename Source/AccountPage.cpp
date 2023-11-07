/*
  ==============================================================================

    AccountPage.cpp
    Created: 4 Nov 2023 3:06:15am
    Author:  Shawn Joseph

  ==============================================================================
*/


//==============================================================================
#include <JuceHeader.h>
#include "AccountPage.h"

AccountPage::AccountPage(){
   

    // Create a viewport and set its size
    addAndMakeVisible(viewport);
    viewport.setViewedComponent(&m_ViewedContent, false);
    viewport.setScrollBarsShown(false, false);
    
}

void AccountPage::paint(juce::Graphics &) {
   m_ScrollPosition = viewport.getViewPosition().y;
}

void AccountPage::resized()
{
    // Set the bounds of the viewport to match the size of the parent component
    viewport.setBounds(getLocalBounds());
    
    // Set the content size
    m_ViewedContent.setBounds(0, 0, getWidth(), 1000);

}
//========================================================================================

AccountPage::AccountPageViewedContent::AccountPageViewedContent() { // constructor of the content view
   


}

AccountPage::AccountPageViewedContent::~AccountPageViewedContent() { // destructor of the content view
    
    
}

void AccountPage::AccountPageViewedContent::paint(juce::Graphics & g){ // paint method of content view
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
    g.drawText("User Account Page is Under Maintenance", getLocalBounds(), juce::Justification::centred, true);
    
}

void AccountPage::AccountPageViewedContent::resized() { // resized method of the content view
    
    
    
}
