/*
  ==============================================================================

    HomePage.cpp
    Created: 4 Nov 2023 3:04:11am
    Author:  Shawn Joseph

  ==============================================================================
*/
#include <JuceHeader.h>
#include "HomePage.h"

HomePage::HomePage()
{
   

    // Create a viewport and set its size
    addAndMakeVisible(viewport);
    viewport.setViewedComponent(&m_ViewedContent, false);
    viewport.setScrollBarsShown(false, false);
    
    
    
}



void HomePage::resized()
{
    // Set the bounds of the viewport to match the size of the parent component
    viewport.setBounds(getLocalBounds());
    
    // Set the content size
    m_ViewedContent.setBounds(0, 0, getWidth(), 800);

}
//========================================================================================

HomePage::HomePageViewedContent::HomePageViewedContent() { // constructor of the content view
   
    this->addAndMakeVisible(tempTile1);
    this->addAndMakeVisible(tempTile2);
    this->addAndMakeVisible(tempTile3);
    this->addAndMakeVisible(tempTile4);
    this->addAndMakeVisible(tempTile5);


}

HomePage::HomePageViewedContent::~HomePageViewedContent() { // destructor of the content view
    
    
}

void HomePage::HomePageViewedContent::paint(juce::Graphics & g){ // paint method of content view
    
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
    g.drawText("Home Page is Under Maintenance", getLocalBounds(), juce::Justification::centred, true);
    
    
    
    
}

void HomePage::HomePageViewedContent::resized() { // resized method of the content view
    
    tempTile1.setBounds(0, 0, getWidth(), getWidth());
    tempTile2.setBounds(0, tempTile1.getBottom() + 10, getWidth() - 0, getWidth());
    tempTile3.setBounds(0, tempTile2.getBottom() + 10, getWidth() - 0, getWidth());
    tempTile4.setBounds(0, tempTile3.getBottom() + 10, getWidth() - 0, getWidth());
    tempTile5.setBounds(0, tempTile4.getBottom() + 10, getWidth() - 0, getWidth());
    
    
    
}
