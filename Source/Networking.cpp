/*
  ==============================================================================

    Networking .cpp
    Created: 6 Nov 2023 1:09:19pm
    Author:  Shawn Joseph

  ==============================================================================
*/

#include "Networking.h"

int Networking::m_NumberOfNotifications = 0;
bool Networking::m_isAuthenticated = false;

int Networking::getNotificationValue() {
    return m_NumberOfNotifications;
}

void Networking::incrementNotificationValue() {
    m_NumberOfNotifications += 1;
}

void Networking::decrementNotificationValue() {
    m_NumberOfNotifications -= 1;
}


// Authentication -----------------------------------------------------------------------
bool Networking::isAuthenticated() {
    
    // TODO: This is where the authentication code goes. It should check the API 
    return m_isAuthenticated;
}

void Networking::authenticateUser(juce::String &email, juce::String &password) { 
    //parse the email and Password
    // then a token will be created is the password and email are correct
    //set the login state to true
    m_isAuthenticated = true; // should be a condition
    
}


