/*
  ==============================================================================

    LoginPage.cpp
    Created: 8 Nov 2023 8:33:54am
    Author:  Shawn Joseph

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LoginPage.h"


//==============================================================================
LoginPage::LoginPageViewedContent::LoginPageViewedContent()
{
    
    setupComponents();

}

LoginPage::LoginPageViewedContent::~LoginPageViewedContent()
{
}

void LoginPage::LoginPageViewedContent::paint (juce::Graphics& g)
{
    g.drawImage(ImageManager::getLoginPageBgImg(), getLocalBounds().expanded(10, 10).toFloat());
    
    // add rounded rect around the  forms 
    g.setColour(juce::Colours::white);
    g.drawRoundedRectangle(m_EmailForm.getBounds().toFloat(), m_EmailForm.getHeight() /2 , 1.0f);
    g.drawRoundedRectangle(m_PasswordForm.getBounds().toFloat(), m_PasswordForm.getHeight() /2 , 1.0f);

}

void LoginPage::LoginPageViewedContent::resized()
{
    auto area = getLocalBounds();
    int xMargin = area.getWidth()/8;
    area.removeFromTop(area.getHeight() /4); //remove space from the top
    area.removeFromLeft(xMargin);
    area.removeFromRight(xMargin);
    
    // set bounds of Components
    m_WelcomeLabel.setBounds(area.removeFromTop(50));
    
    m_SubHeading.setBounds(area.removeFromTop(50));
    area.removeFromTop(50);
    m_EmailForm.setBounds(area.removeFromTop(50));
    area.removeFromTop(20);
    m_PasswordForm.setBounds(area.removeFromTop(50));
    area.removeFromTop(20);
    m_LoginButton.setBounds(area.removeFromTop(50));

}

void LoginPage::LoginPageViewedContent::setupComponents() {
    
    //Welcome
    m_WelcomeLabel.setText("Welcome", juce::dontSendNotification);
    m_WelcomeLabel.setJustificationType(juce::Justification::centred);
    m_WelcomeLabel.setFont(juce::Font("Ariel", 50, juce::Font::bold));
    
    m_SubHeading.setText("Keep your MLAB apps updated, verified, and organized with MLAB Hub.",
                         juce::dontSendNotification);
    m_SubHeading.setJustificationType(juce::Justification::centred);
    m_SubHeading.setFont(juce::Font("Ariel", 13, 0));
    
    // textEditors justification
    m_EmailForm.setJustification(juce::Justification::centred);
    m_PasswordForm.setJustification(juce::Justification::centred);
    
    // textEditors BackGroundColour
    m_EmailForm.setColour(juce::TextEditor::backgroundColourId, juce::Colours::transparentBlack);
    m_PasswordForm.setColour(juce::TextEditor::backgroundColourId, juce::Colours::transparentBlack);
    
    // textEditors OutlineColour without focus
    m_EmailForm.setColour(juce::TextEditor::outlineColourId, juce::Colours::transparentBlack);
    m_PasswordForm.setColour(juce::TextEditor::outlineColourId, juce::Colours::transparentBlack);
    
    // textEditors OutlineColour with focus
    m_EmailForm.setColour(juce::TextEditor::focusedOutlineColourId, juce::Colours::transparentBlack);
    m_PasswordForm.setColour(juce::TextEditor::focusedOutlineColourId, juce::Colours::transparentBlack);
    
    
    //textEditors PlaceHolderText
    m_EmailForm.setTextToShowWhenEmpty("Email", juce::Colours::white);
    m_PasswordForm.setTextToShowWhenEmpty("Password", juce::Colours::white);

    
    //set the password Form to hide text
    m_PasswordForm.setPasswordCharacter(0x2022); // 0x202 = '•'
    
    
    
    
    // set login button text
    m_LoginButton.setButtonText("Login");
    
    //set login button background colour
    m_LoginButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    
    
    
    
    if(juce::Desktop::getInstance().isDarkModeActive()){
        m_WelcomeLabel.setColour(juce::Label::textColourId, ColourPalette::getDarkModeMainTextColour());
    }
    else{
        m_WelcomeLabel.setColour(juce::Label::textColourId, ColourPalette::getLightModeMainTextColour());
    }
    
    // make components visible
    addAndMakeVisible( m_BackgroundImage);
    addAndMakeVisible( m_WelcomeLabel);
    addAndMakeVisible( m_SubHeading);
    addAndMakeVisible( m_IncorrectMessage);
    addAndMakeVisible( m_EmailForm);
    addAndMakeVisible( m_PasswordForm);
    addAndMakeVisible( m_LoginButton);
}




LoginPage::LoginPage(){
   

    // Create a viewport and set its size
    addAndMakeVisible(viewport);
    viewport.setViewedComponent(&m_ViewedContent, false);
    viewport.setScrollBarsShown(false, false);
    
}


void LoginPage::resized()
{
    // Set the bounds of the viewport to match the size of the parent component
    viewport.setBounds(getLocalBounds());
    
    // Set the content size
    m_ViewedContent.setBounds(0, 0, getWidth(), 1000);

}




