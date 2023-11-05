/*
  ==============================================================================

    PageTile.cpp
    Created: 4 Nov 2023 6:20:20pm
    Author:  Shawn Joseph

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PageTile.h"

//==============================================================================
PageTile::PageTile()
{
   
}

PageTile::~PageTile()
{
}

void PageTile::paint (juce::Graphics& g)
{
    
    if(juce::Desktop::getInstance().isDarkModeActive() == true){
        g.setColour(ColourPalette::getDarkModePageTileColour());
        
    }
    else {
        g.setColour(ColourPalette::getLightModePageTileColour());
    }
    
    g.fillRoundedRectangle(getLocalBounds().toFloat(), 0);
    
    if(juce::Desktop::getInstance().isDarkModeActive() == true){
        g.setColour(ColourPalette::getDarkModeMainTextColour());
        
    }
    else {
        g.setColour(ColourPalette::getLightModeMainTextColour());
    }
    
    g.setFont(14.0f);
    g.drawText("Page Tile", getLocalBounds(), juce::Justification::centred, true);
    
}

void PageTile::resized()
{
   
}
