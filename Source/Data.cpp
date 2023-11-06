/*
  ==============================================================================

    Data.cpp
    Created: 5 Nov 2023 10:09:22pm
    Author:  Shawn Joseph

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Data.h"

//==============================================================================
Data::Data()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

Data::~Data()
{
}

void Data::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("Data", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void Data::resized()
{
    

}
