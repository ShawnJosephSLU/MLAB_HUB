/*
  ==============================================================================

    ColourPalette.h
    Created: 4 Nov 2023 4:32:59pm
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class ColourPalette {
public:
    // Get the background color for the dark mode
    static juce::Colour getDarkModeBgColour() {
        return juce::Colours::black;
    }

    // Get the background color for the light mode
    static juce::Colour getLightModeBgColour() {
        return juce::Colour(200,200,200);
    }
    
    
    //Get Main Text Colour in DarkMode
    static juce::Colour getDarkModeMainTextColour() {
        return juce::Colours::white;
    }
    
    //Get Main Text Colour in LightMode
    static juce::Colour getLightModeMainTextColour() {
        return juce::Colours::black;
    }
    
    
    //current page indicator in Dark mode
    static juce::Colour getDarkModeCurrentPageIndicator(){
        return juce::Colours::green;
    }
    
    //current page indicator in light mode
    static juce::Colour getLightModeCurrentPageIndicator(){
        return juce::Colours::orange;
    }
    
    
    //current page tile in Dark mode
    static juce::Colour getDarkModePageTileColour(){
        return juce::Colour(21,21,21);
    }
    
    //current page tile in light mode
    static juce::Colour getLightModePageTileColour(){
        return juce::Colour(240,240,240) ;
    }
    
    
    //Dark mode navbar Colour
    static juce::Colour getDarkModeNavBarColour(){
        return juce::Colour(41,41, 41).withAlpha(0.65f);
    }
    
    //Light Mode in navbar Colour
    static juce::Colour getLightModeNavBarColour(){
        return juce::Colour(220,220,220).withAlpha(0.65f);
    }
    
    //Dark mode navbar btn Colour
    static juce::Colour getDarkModeNavBarBtnColour(){
        return juce::Colours::white;
    }
    
    //Light Mode in navbar btn Colour
    static juce::Colour getLightModeNavBarBtnColour(){
        return juce::Colours::black;
    }
    
    
private:
    // Make the constructor private to prevent instantiation
    ColourPalette();
};
