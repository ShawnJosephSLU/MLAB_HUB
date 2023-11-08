/*
  ==============================================================================

    LoginPage.h
    Created: 8 Nov 2023 8:33:54am
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class LoginPage  : public juce::Component
{
public:
    LoginPage();
    ~LoginPage() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LoginPage)
};
