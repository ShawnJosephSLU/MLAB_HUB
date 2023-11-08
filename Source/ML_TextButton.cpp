/*
  ==============================================================================

    ML_TextButton.cpp
    Created: 8 Nov 2023 12:50:03pm
    Author:  Shawn Joseph

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ML_TextButton.h"

//==============================================================================
ML_TextButton::ML_TextButton()
{
   
}

ML_TextButton::~ML_TextButton()
{
}

void ML_TextButton::paint (juce::Graphics& g)
{
    
    g.setColour(juce::Colour(10,72,60));
    g.fillRoundedRectangle(getLocalBounds().toFloat(), getHeight() /2);


    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText (m_ButtonText, getLocalBounds(), juce::Justification::centred, true);
    
    
}

void ML_TextButton::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
