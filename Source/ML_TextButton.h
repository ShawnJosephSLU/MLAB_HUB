/*
  ==============================================================================

    ML_TextButton.h
    Created: 8 Nov 2023 12:50:03pm
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ML_TextButton  : public juce::TextButton
{
public:
    ML_TextButton();
    ~ML_TextButton() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void setButtonText(juce::String text) { m_ButtonText = std::move(text);}

private:
    juce::String m_ButtonText = "Empty Text";
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ML_TextButton)
};
