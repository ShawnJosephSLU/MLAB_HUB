/*
  ==============================================================================

    PageNavigator.h
    Created: 3 Nov 2023 5:36:45pm
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PageNavigator.h"
#include "ColourPalette.h"
#include "ImageManager.h"
#include "ML_ImageButton.h"

//==============================================================================

enum class ButtonType
{
    Home,
    News,
    Notification,
    Products,
    UserAccount,
    Settings
};

class PageNavigator  : public juce::Component
{
public:
    PageNavigator();
    ~PageNavigator() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    ML_ImageButton& getHomeButton() { return m_HomeBtn; }
    ML_ImageButton& getNewsButton() { return m_NewsBtn; }
    ML_ImageButton& getNotificationsButton() { return m_NotificationBtn; }
    ML_ImageButton& getProductsButton() { return m_ProductsBtn; }
    ML_ImageButton& getAccountButton() { return m_UserAccountBtn; }
    ML_ImageButton& getSettingsButton() { return m_SettingsBtn; }
    
    ButtonType& getClickedButton() {return buttonClicked;}


private:
    ML_ImageButton m_HomeBtn;
    ML_ImageButton m_NewsBtn;
    ML_ImageButton m_NotificationBtn;
    ML_ImageButton m_ProductsBtn;
    ML_ImageButton m_UserAccountBtn;
    ML_ImageButton m_SettingsBtn;

    

    
    // private Methods
    void setButtonsWithImage();
    
    // is button active flags
    bool isHomeBtnActive = false;
    bool isNewsBtnActive = false;
    bool isNotificationBtnActive = false;
    bool isProductsBtnActive = false;
    bool isUserAccountBtnActive = false;
    bool isSettingsBtnActive = false;
    

    ButtonType buttonClicked = ButtonType::Home;
    
    // this is the colour of the button when it is active
    juce::Colour buttonColour = juce::Colours::transparentBlack;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PageNavigator)
};
