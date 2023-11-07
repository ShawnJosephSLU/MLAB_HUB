/*
  ==============================================================================

    NotificationCount.cpp
    Created: 7 Nov 2023 8:46:05am
    Author:  Shawn Joseph

  ==============================================================================
*/

#include <JuceHeader.h>
#include "NotificationCount.h"

//==============================================================================
NotificationCount::NotificationCount()
{
    this->setInterceptsMouseClicks(false, false); // prevents thie

}

NotificationCount::~NotificationCount()
{
}

void NotificationCount::paint (juce::Graphics& g)
{
    g.setColour(juce::Colours::red); //TODO: this colour need to be gotten from the Colour model
    g.fillRoundedRectangle(getLocalBounds().toFloat(), getHeight() / 2);
    
    //Number Colours
    g.setColour(juce::Colours::white); //TODO: this colour need to be gotten from the Colour model
    
    g.setFont(juce::Font("Ariel", 12.0f, 0));
    
    if(m_NumOfNotifications >= 100) {
        g.drawText("99+", getLocalBounds(), juce::Justification::centred); //TODO: Number not Centred
    }else {
        g.drawText((juce::String)m_NumOfNotifications, getLocalBounds(), juce::Justification::centred); //TODO: Number not Centred
    }
}

void NotificationCount::resized()
{
   
}
