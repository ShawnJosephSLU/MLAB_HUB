/*
  ==============================================================================

    PageNavigator.cpp
    Created: 3 Nov 2023 5:36:45pm
    Author:  Shawn Joseph

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PageNavigator.h"

//==============================================================================
PageNavigator::PageNavigator()
{
    setButtonWithImage(m_HomeBtn, m_HomeBtnImg);
    setButtonWithImage(m_NewsBtn, m_NewsBtnImg);
    setButtonWithImage(m_UserAccountBtn, m_UserAccountBtnImg);
    setButtonWithImage(m_NotificationBtn, m_NotificationBtnImg);
    setButtonWithImage(m_ProductsBtn, m_ProductsBtnImg);
    setButtonWithImage(m_SettingsBtn, m_SettingsBtnImg);
   

}

PageNavigator::~PageNavigator()
{
}

void PageNavigator::paint(juce::Graphics& g)
{
// Define the top and bottom colors for the gradient with alpha values
    juce::Colour topColor(240, 240, 240);
    juce::Colour bottomColor(200, 200, 200);
    
    
    topColor = topColor.withAlpha(0.75f);
    bottomColor = bottomColor.withAlpha(0.75f);


    // Create a gradient using gradientFill
    juce::ColourGradient gradient(topColor, 0.0f, 0.0f, bottomColor, 0.0f, static_cast<float>(getHeight()), false);

    // Fill the background with the gradient
    g.setGradientFill(gradient);
    g.fillRoundedRectangle(getLocalBounds().toFloat(), getHeight() / 2);
    
   

    struct ButtonInfo {
        bool& isActive;
        juce::ImageButton& button;
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
        g.setColour(juce::Colours::black);

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
}



void PageNavigator::resized()
{
    auto area = getLocalBounds().reduced(16, 16);
    int spacer = 16; // Adjust the spacing as needed
    int numButtons = 6; // The number of buttons

    int buttonWidth = (area.getWidth() - (numButtons - 1) * spacer) / numButtons;

    m_HomeBtn.setBounds(area.removeFromLeft(buttonWidth));
    area.removeFromLeft(spacer);

    m_ProductsBtn.setBounds(area.removeFromLeft(buttonWidth));
    area.removeFromLeft(spacer);

    m_UserAccountBtn.setBounds(area.removeFromLeft(buttonWidth));
    area.removeFromLeft(spacer);

    m_NewsBtn.setBounds(area.removeFromLeft(buttonWidth));
    area.removeFromLeft(spacer);

    m_SettingsBtn.setBounds(area.removeFromLeft(buttonWidth));
    area.removeFromLeft(spacer);

    m_NotificationBtn.setBounds(area.removeFromLeft(buttonWidth));
}


void PageNavigator::setButtonWithImage(juce::ImageButton &btn, juce::Image img) { 
    addAndMakeVisible(btn);
   
    //setButton Image
    
    btn.setImages(true, true, true,
                        img,
                        1.0,
                        buttonColour,
                        img,
                        1.0,
                        buttonColour,
                        img,
                        1.0,
                        buttonColour);
}

