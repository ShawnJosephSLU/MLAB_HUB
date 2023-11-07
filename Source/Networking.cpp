/*
  ==============================================================================

    Networking .cpp
    Created: 6 Nov 2023 1:09:19pm
    Author:  Shawn Joseph

  ==============================================================================
*/

#include "Networking.h"

int Networking::m_NumberOfNotifications = 0;

int Networking::getNotificationValue() {
    return m_NumberOfNotifications;
}

void Networking::incrementNotificationValue() {
    m_NumberOfNotifications += 1;
}

void Networking::decrementNotificationValue() {
    m_NumberOfNotifications -= 1;
}
