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
    
    juce::ImageButton& getHomeButton() { return m_HomeBtn; }
    juce::ImageButton& getNewsButton() { return m_NewsBtn; }
    juce::ImageButton& getNotificationsButton() { return m_NotificationBtn; }
    juce::ImageButton& getProductsButton() { return m_ProductsBtn; }
    juce::ImageButton& getAccountButton() { return m_UserAccountBtn; }
    juce::ImageButton& getSettingsButton() { return m_SettingsBtn; }
    
    ButtonType& getClickedButton() {return buttonClicked;}


private:
    juce::ImageButton m_HomeBtn;
    juce::ImageButton m_NewsBtn;
    juce::ImageButton m_NotificationBtn;
    juce::ImageButton m_ProductsBtn;
    juce::ImageButton m_UserAccountBtn;
    juce::ImageButton m_SettingsBtn;

    
    //button images
    const juce::Image m_HomeBtnImg = juce::ImageCache::getFromMemory(BinaryData::home_btn_png, BinaryData::home_btn_pngSize);
    const juce::Image m_NewsBtnImg = juce::ImageCache::getFromMemory(BinaryData::news_btn_png, BinaryData::news_btn_pngSize);
    const juce::Image m_NotificationBtnImg = juce::ImageCache::getFromMemory(BinaryData::notification_btn_png, BinaryData::notification_btn_pngSize);
    const juce::Image m_ProductsBtnImg = juce::ImageCache::getFromMemory(BinaryData::products_png, BinaryData::products_pngSize);
    const juce::Image m_SettingsBtnImg = juce::ImageCache::getFromMemory(BinaryData::settings_btn_png, BinaryData::settings_btn_pngSize);
    const juce::Image m_UserAccountBtnImg = juce::ImageCache::getFromMemory(BinaryData::account_btn_default_png, BinaryData::account_btn_default_pngSize);

    
    // private Methods
    void setButtonWithImage(juce::ImageButton &btn, juce::Image img);
    
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
