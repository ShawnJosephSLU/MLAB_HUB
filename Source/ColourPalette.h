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
        return juce::Colours::white;
    }
    
    
    //Get Main Text Colour in DarkMode
    static juce::Colour getDarkModeMainTextColour() {
        return juce::Colours::white;
    }
    
    //Get Main Text Colour in LightMode
    static juce::Colour getLightModeMainTextColour() {
        return juce::Colours::black;
    }
    
    
private:
    // Make the constructor private to prevent instantiation
    ColourPalette();
};
