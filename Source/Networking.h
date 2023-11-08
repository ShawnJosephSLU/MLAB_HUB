/*
  ==============================================================================

    Networking .h
    Created: 6 Nov 2023 1:09:19pm
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once
#include "Data.h"

class Networking {
public:
    static int getNotificationValue();
    static void incrementNotificationValue();
    static void decrementNotificationValue();
    
    //Authentication
    static bool isAuthenticated();
    static void authenticateUser(juce::String& email, juce::String& password);

private:
    static int m_NumberOfNotifications; // TODO: this should be passed from the Database;
    static bool m_isAuthenticated; // TODO: must be passed from Database
};


