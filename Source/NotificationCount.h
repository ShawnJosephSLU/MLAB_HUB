/*
  ==============================================================================

    NotificationCount.h
    Created: 7 Nov 2023 8:46:05am
    Author:  Shawn Joseph

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class NotificationCount  : public juce::Component
{
public:
    NotificationCount();
    ~NotificationCount() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    /**sets the number of notifications to be displayed*/
    void setValue(int n_Notifications) {m_NumOfNotifications = std::move(n_Notifications); repaint();}
    int getValue() {return m_NumOfNotifications;} // gets the number of notifications
    
private:
    int m_NumOfNotifications = 0;// this value represents the number of notifications
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NotificationCount)
};
