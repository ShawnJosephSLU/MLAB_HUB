/*
  ==============================================================================

    ImageManager.h
    Created: 5 Nov 2023 10:21:25am
    Author:  Shawn Joseph

  ==============================================================================
*/


#pragma once
#include <JuceHeader.h>

class ImageManager {
public:
    // Get the darkMode home image
    static juce::Image getDarkModeHomPageBtnImg() {
        return juce::ImageCache::getFromMemory(BinaryData::dark_mode_home_page_icon_png, BinaryData::dark_mode_home_page_icon_pngSize);
    }

    // Get the lightMode home image
    static juce::Image getLightModeHomePageBtnImg() {
        return juce::ImageCache::getFromMemory(BinaryData::light_mode_home_page_icon_png, BinaryData::light_mode_home_page_icon_pngSize);
    }

    // Get the darkMode products image
    static juce::Image getDarkModeProductsPageBtnImg() {
        return juce::ImageCache::getFromMemory(BinaryData::dark_mode_products_page_icon_png, BinaryData::dark_mode_products_page_icon_pngSize);
    }

    // Get the lightMode products image
    static juce::Image getLightModeProductsPageBtnImg() {
        return juce::ImageCache::getFromMemory(BinaryData::light_mode_products_page_icon_png, BinaryData::light_mode_products_page_icon_pngSize);
    }

    // Get the darkMode news button image
    static juce::Image getDarkModeNewsBtnImg() {
        return juce::ImageCache::getFromMemory(BinaryData::dark_mode_news_page_icon_png, BinaryData::dark_mode_news_page_icon_pngSize);
    }

    // Get the lightMode news button image
    static juce::Image getLightModeNewsBtnImg() {
        return juce::ImageCache::getFromMemory(BinaryData::light_mode_news_page_icon_png, BinaryData::light_mode_news_page_icon_pngSize);
    }

    // Get the darkMode notifications button image
    static juce::Image getDarkModeNotificationsBtnImg() {
        return juce::ImageCache::getFromMemory(BinaryData::dark_mode_notifications_page_icon_png, BinaryData::dark_mode_notifications_page_icon_pngSize);
    }

    // Get the lightMode notifications button image
    static juce::Image getLightModeNotificationsBtnImg() {
        return juce::ImageCache::getFromMemory(BinaryData::light_mode_notifications_page_icon_png, BinaryData::light_mode_notifications_page_icon_pngSize);
    }

    // Get the darkMode settings button image
    static juce::Image getDarkModeSettingsBtnImg() {
        return juce::ImageCache::getFromMemory(BinaryData::dark_mode_settings_page_icon_png, BinaryData::dark_mode_settings_page_icon_pngSize);
    }

    // Get the lightMode settings button image
    static juce::Image getLightModeSettingsBtnImg() {
        return juce::ImageCache::getFromMemory(BinaryData::light_mode_settings_page_icon_png, BinaryData::light_mode_settings_page_icon_pngSize);
    }

    // Get the darkMode user account button image
    static juce::Image getDarkModeUserAccountBtnImg() {
        return juce::ImageCache::getFromMemory(BinaryData::dark_mode_account_page_icon_png, BinaryData::dark_mode_account_page_icon_pngSize);
    }

    // Get the lightMode user account button image
    static juce::Image getLightModeUserAccountBtnImg() {
        return juce::ImageCache::getFromMemory(BinaryData::light_mode_account_page_icon_png, BinaryData::light_mode_account_page_icon_pngSize);
    }

    
private:
    // Make the constructor private to prevent instantiation
    ImageManager(){}
};
