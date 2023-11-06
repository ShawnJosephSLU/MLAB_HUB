/*
  ==============================================================================

    AppHeader.cpp
    Created: 6 Nov 2023 12:28:41am
    Author:  Shawn Joseph

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AppHeader.h"
#include "ColourPalette.h"

//==============================================================================
AppHeader::AppHeader()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

AppHeader::~AppHeader()
{
}

void AppHeader::paint (juce::Graphics& g)
{

    if(juce::Desktop::getInstance().isDarkModeActive() == true){
        g.fillAll(ColourPalette::getDarkModePageTileColour());
    }
    else {
        g.fillAll(ColourPalette::getLightModePageTileColour());
    }
    
    if(juce::Desktop::getInstance().isDarkModeActive() == true){
        g.setColour(ColourPalette::getDarkModeMainTextColour());

    }
    else {
        g.setColour(ColourPalette::getLightModeMainTextColour());

    }
    g.setFont (14.0f);
    g.drawText ("App Header", getLocalBounds(),
                juce::Justification::centred, true);
}

void AppHeader::resized()
{
   

}
