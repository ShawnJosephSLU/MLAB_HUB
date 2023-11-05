/*
  ==============================================================================

    ML_ImageButton.h
    Created: 5 Nov 2023 9:47:29am
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ML_ImageButton  : public juce::TextButton
{
public:
    ML_ImageButton();
    ~ML_ImageButton() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void setImages(juce::Image dark, juce::Image light) {m_DarkModeButtonImage = dark;  m_LightModeButtonImage = light; }

private:
    juce::Image m_DarkModeButtonImage;
    juce::Image m_LightModeButtonImage;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ML_ImageButton)
};
