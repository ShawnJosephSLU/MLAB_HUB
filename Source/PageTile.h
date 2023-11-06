/*
  ==============================================================================

    PageTile.h
    Created: 4 Nov 2023 6:20:20pm
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ColourPalette.h"
#include "Data.h"

//==============================================================================
/*
*/
class PageTile  : public juce::Component
{
public:
    PageTile();
    ~PageTile() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void passData(std::vector<Data*> dataList) {m_DataList = std::move(dataList);} //passes the dataList to Tile by Reference

private:
    std::vector<Data*> m_DataList;
    
    juce::String TileID ; //TODO:  make this the unique id of tile and create the getter method for it . ID must be hashed
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PageTile)
};
