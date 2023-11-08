/*
  ==============================================================================

    LoginPage.h
    Created: 8 Nov 2023 8:33:54am
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ColourPalette.h"
#include "ImageManager.h"
#include "ML_TextButton.h"
//==============================================================================
/*
*/


#pragma once
#include "ColourPalette.h"

class LoginPage : public juce::Component
{
public:
    LoginPage();
    ~LoginPage(){}

    void resized() override;

    ML_TextButton& getLoginButton() {return m_ViewedContent.getLoginButton();}

private:
    
    //=========================================================
    class LoginPageViewedContent  : public juce::TextButton
    {
    public:
        LoginPageViewedContent();
        ~LoginPageViewedContent() override;

        void paint (juce::Graphics&) override;
        void resized() override;
        ML_TextButton& getLoginButton() {return m_LoginButton;}

    private:
        void setupComponents();

        juce::ImageComponent m_BackgroundImage;
        juce::Label m_WelcomeLabel;
        juce::Label m_IncorrectMessage;
        
        juce::TextEditor m_EmailForm;
        juce::TextEditor m_PasswordForm;
        
        ML_TextButton m_LoginButton;
        
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LoginPageViewedContent)
    };

    
    LoginPageViewedContent m_ViewedContent;
    juce::Viewport viewport;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LoginPage)
};

































