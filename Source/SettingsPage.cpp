/*
  ==============================================================================

    SettingsPage.cpp
    Created: 4 Nov 2023 3:04:53am
    Author:  Shawn Joseph

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SettingsPage.h"

SettingsPage::SettingsPage(){
   

    // Create a viewport and set its size
    addAndMakeVisible(viewport);
    viewport.setViewedComponent(&m_ViewedContent, false);
    viewport.setScrollBarsShown(false, false);
    
}



void SettingsPage::resized()
{
    // Set the bounds of the viewport to match the size of the parent component
    viewport.setBounds(getLocalBounds());
    
    // Set the content size
    m_ViewedContent.setBounds(0, 0, getWidth(), 800);

}
//========================================================================================

SettingsPage::SettingsPageViewedContent::SettingsPageViewedContent() { // constructor of the content view
   


}

SettingsPage::SettingsPageViewedContent::~SettingsPageViewedContent() { // destructor of the content view
    
    
}

void SettingsPage::SettingsPageViewedContent::paint(juce::Graphics & g){ // paint method of content view
  
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
    g.drawText("Settings Page is Under Maintenance", getLocalBounds(), juce::Justification::centred, true);
    
}

void SettingsPage::SettingsPageViewedContent::resized() { // resized method of the content view
    
    
    
}
