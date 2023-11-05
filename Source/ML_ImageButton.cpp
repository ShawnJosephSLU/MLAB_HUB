/*
  ==============================================================================

    ML_ImageButton.cpp
    Created: 5 Nov 2023 9:47:29am
    Author:  Shawn Joseph

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ML_ImageButton.h"

//==============================================================================
ML_ImageButton::ML_ImageButton()
{
    
}

ML_ImageButton::~ML_ImageButton()
{
}

void ML_ImageButton::paint (juce::Graphics& g)
{
    if(juce::Desktop::getInstance().isDarkModeActive() == true){
        g.drawImage(m_DarkModeButtonImage, getLocalBounds().toFloat());

    }
    else {
        g.drawImage(m_LightModeButtonImage, getLocalBounds().toFloat());
    }
   
}

void ML_ImageButton::resized()
{
   
}
