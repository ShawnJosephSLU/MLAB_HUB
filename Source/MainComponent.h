#pragma once

#include <JuceHeader.h>
#include "PageNavigator.h"
#include "HomePage.h"
#include "ProductsPage.h"
#include "AccountPage.h"
#include "NewsPage.h"
#include "SettingsPage.h"
#include "NotificationsPage.h"
#include "AppHeader.h"
#include "Networking.h"
#include "LoginPage.h"


//==============================================================================

//says which page is opened in the app
enum PageID {
    Home, News, Account, Notifications, Settings, Products, Login
};

class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    
    // open pages methods
    void openHomePage();

    void openNewsPage();

    void openAccountPage();

    void openNotificationsPage();

    void openSettingsPage();

    void openProductsPage();
    
    void openLoginPage();
    
    void hideNavbar();
    
    void login();

private:
    //==============================================================================
    PageID m_CurrentPageID = Home;
    PageNavigator m_PageNavigator;
    
    //Pages
    HomePage m_HomePage;
    ProductsPage m_ProductsPage;
    AccountPage m_AccountPage;
    NewsPage m_NewsPage;
    SettingsPage m_SettingsPage;
    NotificationsPage m_NotificationsPage;
    AppHeader m_AppHeader;
    LoginPage m_LoginPage;
    
    
   
    int minNavLimit, maxNavLimit;
    int temp_pos; 
    


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
