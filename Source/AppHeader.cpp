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
    // make the header Label Bold
    m_HeaderLabel.setFont(juce::Font("Open Sans", 26, juce::Font::bold));
   // make the Header Label visible
    addAndMakeVisible(m_HeaderLabel);

}

AppHeader::~AppHeader()
{
}

void AppHeader::paint (juce::Graphics& g)
{

    if(juce::Desktop::getInstance().isDarkModeActive() == true){
        m_HeaderLabel.setColour(juce::Label::ColourIds::textColourId, ColourPalette::getDarkModeMainTextColour());
        g.fillAll(ColourPalette::getDarkModePageTileColour());
    }
    else {
        g.fillAll(ColourPalette::getLightModePageTileColour());
        m_HeaderLabel.setColour(juce::Label::ColourIds::textColourId, ColourPalette::getLightModeMainTextColour());
    }

}

void AppHeader::resized()
{
    // set the bounds of the header label
    auto area = getLocalBounds();
    auto bottomHalfArea = area.removeFromBottom(area.getHeight() / 2);
    //margins for bottom half area
    bottomHalfArea.removeFromLeft(20);
    bottomHalfArea.removeFromRight(20);

    
    auto headerLabelArea = bottomHalfArea.removeFromLeft(200);
    
    m_HeaderLabel.setBounds(headerLabelArea);

}
