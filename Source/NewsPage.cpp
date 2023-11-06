/*
  ==============================================================================

    NewsPage.cpp
    Created: 4 Nov 2023 3:05:56am
    Author:  Shawn Joseph

  ==============================================================================
*/

#include <JuceHeader.h>
#include "NewsPage.h"

NewsPage::NewsPage()
{
   

    // Create a viewport and set its size
    addAndMakeVisible(viewport);
    viewport.setViewedComponent(&m_ViewedContent, false);
    viewport.setScrollBarsShown(false, false);
}



void NewsPage::resized()
{
    // Set the bounds of the viewport to match the size of the parent component
    viewport.setBounds(getLocalBounds());
    
    // Set the content size
    m_ViewedContent.setBounds(0, 0, getWidth(), m_ViewedContent.getPageHeight());
    
}
//========================================================================================

NewsPage::NewsPageViewedContent::NewsPageViewedContent() { // constructor of the content view
   
    // temp vector of data for testing
    Data data_temp;
    std::vector<Data*> dataList_temp;
    dataList_temp.push_back(&data_temp);
    
    int n = 20; //create "n" temp tile
    for(int i = 0; i < n; i++){
        createNewDataTile(dataList_temp);
    }
    
    // add The tile to the viewedContent
    for (PageTile* dataTile : m_NewsPageTiles ) {
        addAndMakeVisible(dataTile);
    }
    
    

}

NewsPage::NewsPageViewedContent::~NewsPageViewedContent() { // destructor of the content view
    
    // manual garbage collection for the ``` m_HomeDataTiles```
    for (PageTile* x : m_NewsPageTiles) {
        delete x;
    }
}

void NewsPage::NewsPageViewedContent::paint(juce::Graphics & g){ // paint method of content view
    
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

void NewsPage::NewsPageViewedContent::resized() { // resized method of the content view
    // set the position of the tiles
    auto area = getLocalBounds();
    int spacerSize = 1;
    
    for (int i = 0 ; i <  m_NewsPageTiles.size(); i++) {
        m_NewsPageTiles[i]->setBounds(area.removeFromTop(300));
        area.removeFromTop(spacerSize);
                
    }
    m_PageHeight = (int)m_NewsPageTiles.size() * (300 + spacerSize); //assigning the value of the page's height
   


}

void NewsPage::NewsPageViewedContent::createNewDataTile(std::vector<Data*> data) {
    
    PageTile* newTile = new PageTile();  // Create a new Tile Dynamically
    
    newTile->passData(data);     // add the vector of data to the new Tile
    
    
    m_NewsPageTiles.push_back(newTile);//add the tile to the homePageTile vector

    // resize the viewport
   // resized();
}

