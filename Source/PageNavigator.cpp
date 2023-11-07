/*
  ==============================================================================

    PageNavigator.cpp
    Created: 3 Nov 2023 5:36:45pm
    Author:  Shawn Joseph

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PageNavigator.h"
#include "Networking.h"

//==============================================================================
PageNavigator::PageNavigator()
{
    setButtonsWithImage();
    addAndMakeVisible(m_NotificationCounter);
    
}

PageNavigator::~PageNavigator()
{
}

void PageNavigator::paint(juce::Graphics& g)
{

    
    if(juce::Desktop::getInstance().isDarkModeActive() == true){
        g.setColour(ColourPalette::getDarkModeNavBarColour());
        
    }
    else {
        g.setColour(ColourPalette::getLightModeNavBarColour());
    }
    g.fillRoundedRectangle(getLocalBounds().toFloat(), getHeight() / 2);

    
    
    
// opened page indicator logic
   
    struct ButtonInfo {
        bool& isActive;
        ML_ImageButton& button;
    };

    ButtonInfo buttonInfos[] = {
        {isHomeBtnActive, m_HomeBtn},
        {isNewsBtnActive, m_NewsBtn},
        {isNotificationBtnActive, m_NotificationBtn},
        {isProductsBtnActive, m_ProductsBtn},
        {isUserAccountBtnActive, m_UserAccountBtn},
        {isSettingsBtnActive, m_SettingsBtn}
    };

    for (const ButtonInfo& buttonInfo : buttonInfos) {
        buttonInfo.isActive = false;
        if(juce::Desktop::getInstance().isDarkModeActive() == true){
            g.setColour(ColourPalette::getDarkModeCurrentPageIndicator());
            
        }
        else {
            g.setColour(ColourPalette::getLightModeCurrentPageIndicator());
        }

        if ((&buttonInfo.button == &m_HomeBtn && buttonClicked == ButtonType::Home) ||
            (&buttonInfo.button == &m_NewsBtn && buttonClicked == ButtonType::News) ||
            (&buttonInfo.button == &m_NotificationBtn && buttonClicked == ButtonType::Notification) ||
            (&buttonInfo.button == &m_ProductsBtn && buttonClicked == ButtonType::Products) ||
            (&buttonInfo.button == &m_UserAccountBtn && buttonClicked == ButtonType::UserAccount) ||
            (&buttonInfo.button == &m_SettingsBtn && buttonClicked == ButtonType::Settings)) {
            buttonInfo.isActive = true;
            g.fillRoundedRectangle(buttonInfo.button.getX() + (buttonInfo.button.getWidth() / 2) - 3,
                                   buttonInfo.button.getY() - 12, 6, 6, 3);
        }
    }
    
    
    drawNotificationCounter(); //draws the notification counter and adjusts the size
    
}



void PageNavigator::resized()
{
    auto area = getLocalBounds().reduced(0, 16);
    int buttonSize =  area.getHeight(); // Use the minimum of width and height for the button size
    int spacerSize = getWidth() / 13;

    // Now, set the bounds for each button with the same width and height
    area.removeFromLeft(spacerSize);
    m_HomeBtn.setBounds(area.removeFromLeft(buttonSize));
    area.removeFromLeft(spacerSize);
    m_ProductsBtn.setBounds(area.removeFromLeft(buttonSize));
    area.removeFromLeft(spacerSize);
    m_UserAccountBtn.setBounds(area.removeFromLeft(buttonSize));
    area.removeFromLeft(spacerSize);
    m_NewsBtn.setBounds(area.removeFromLeft(buttonSize));
    area.removeFromLeft(spacerSize);
    m_SettingsBtn.setBounds(area.removeFromLeft(buttonSize));
    area.removeFromLeft(spacerSize);
    m_NotificationBtn.setBounds(area.removeFromLeft(buttonSize));
    area.removeFromLeft(spacerSize);
    
    
   

}


void PageNavigator::setButtonsWithImage() { 
    m_HomeBtn.setImages(ImageManager::getDarkModeHomPageBtnImg(), ImageManager::getLightModeHomePageBtnImg());
    m_ProductsBtn.setImages(ImageManager::getDarkModeProductsPageBtnImg(), ImageManager::getLightModeProductsPageBtnImg());
    m_NewsBtn.setImages(ImageManager::getDarkModeNewsBtnImg(), ImageManager::getLightModeNewsBtnImg());
    m_NotificationBtn.setImages(ImageManager::getDarkModeNotificationsBtnImg(), ImageManager::getLightModeNotificationsBtnImg());
    m_SettingsBtn.setImages(ImageManager::getDarkModeSettingsBtnImg(), ImageManager::getLightModeSettingsBtnImg());
    m_UserAccountBtn.setImages(ImageManager::getDarkModeUserAccountBtnImg(), ImageManager::getLightModeUserAccountBtnImg());

    
    addAndMakeVisible(m_HomeBtn);
    addAndMakeVisible(m_NewsBtn);
    addAndMakeVisible(m_ProductsBtn);
    addAndMakeVisible(m_SettingsBtn);
    addAndMakeVisible(m_NotificationBtn);
    addAndMakeVisible(m_UserAccountBtn);
    
    // set which buttons can display notifications
    m_NotificationBtn.setAsNotificationBtn(true);
   
    

}
//===================================================================================================
void PageNavigator::drawNotificationCounter() {
    // if the button is a notification counter and the count is > 0  display the counter
    if(Networking::getNotificationValue() > 0 && Networking::getNotificationValue() < 10 ) {
        m_NotificationCounter.setVisible(true);
        m_NotificationCounter.setBounds(
                                        m_NotificationBtn.getX() + m_NotificationBtn.getWidth() / 2,
                                        m_NotificationBtn.getY() + 2,
                                        16,
                                        16
                                        );
    
        
    }//increase the width of the counter if value is above 10 and less that 100
    else if(Networking::getNotificationValue() >= 10 && Networking::getNotificationValue() < 100) {
        
        m_NotificationCounter.setVisible(true);
        m_NotificationCounter.setBounds(
                                        m_NotificationBtn.getX()  + m_NotificationBtn.getWidth() / 2,
                                        m_NotificationBtn.getY() + 2,
                                        24,
                                        16
                                        );
       
        
    }
    
    else if(Networking::getNotificationValue() >= 100) {
        
        m_NotificationCounter.setVisible(true);
        m_NotificationCounter.setBounds(
                                        m_NotificationBtn.getX()  + m_NotificationBtn.getWidth() / 2,
                                        m_NotificationBtn.getY() + 2,
                                        24,
                                        16
                                        );
        
    }
    else {
        m_NotificationCounter.setVisible(false);
    }
}
//======================================================================================================




