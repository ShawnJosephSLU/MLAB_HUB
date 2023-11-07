/*
  ==============================================================================

    SettingsPage.cpp
    Created: 4 Nov 2023 3:04:53am
    Author:  Shawn Joseph

  ==============================================================================
*/
#include <JuceHeader.h>
#include "SettingsPage.h"

SettingsPage::SettingsPage()
{
   

    // Create a viewport and set its size
    addAndMakeVisible(viewport);
    viewport.setViewedComponent(&m_ViewedContent, false);
    viewport.setScrollBarsShown(false, false);
}

void SettingsPage::paint(juce::Graphics &) {
   m_ScrollPosition = viewport.getViewPosition().y;
}

void SettingsPage::resized()
{
    // Set the bounds of the viewport to match the size of the parent component
    viewport.setBounds(getLocalBounds());
    
    // Set the content size
    m_ViewedContent.setBounds(0, 0, getWidth(), m_ViewedContent.getPageHeight());
    
}
//========================================================================================

SettingsPage::SettingsPageViewedContent::SettingsPageViewedContent() { // constructor of the content view
   
    // temp vector of data for testing
    Data data_temp;
    std::vector<Data*> dataList_temp;
    dataList_temp.push_back(&data_temp);
    
    int n = 15; //create "n" temp tile
    for(int i = 0; i < n; i++){
        createNewDataTile(dataList_temp);
    }
    
    // add The tile to the viewedContent
    for (PageTile* dataTile : m_SettingsPageDataTiles ) {
        addAndMakeVisible(dataTile);
    }
    
    

}

SettingsPage::SettingsPageViewedContent::~SettingsPageViewedContent() { // destructor of the content view
    
    // manual garbage collection for the ``` m_SettingsDataTiles```
    for (PageTile* x : m_SettingsPageDataTiles) {
        delete x;
    }
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
    
    
}

void SettingsPage::SettingsPageViewedContent::resized() { // resized method of the content view
    // set the position of the tiles
    auto area = getLocalBounds();
    int spacerSize = 1;
    area.removeFromTop(spacerSize); //adds 1px of space above the first tile

    
    for (int i = 0 ; i <  m_SettingsPageDataTiles.size(); i++) {
        m_SettingsPageDataTiles[i]->setBounds(area.removeFromTop(80));
        area.removeFromTop(spacerSize);
                
    }
    m_PageHeight = (int)m_SettingsPageDataTiles.size() * (80 + spacerSize); //assigning the value of the page's height
   


}

void SettingsPage::SettingsPageViewedContent::createNewDataTile(std::vector<Data*> data) {
    
    PageTile* newTile = new PageTile();  // Create a new Tile Dynamically
    
    newTile->passData(data);     // add the vector of data to the new Tile
    
    
    m_SettingsPageDataTiles.push_back(newTile);//add the tile to the homePageTile vector

    // resize the viewport
   // resized();
}

