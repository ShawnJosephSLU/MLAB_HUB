#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
   
    // Initialize temp_pos to an initial value
        temp_pos = 0;
    
    setSize(600, 400); //set size
    
    // opens the initial page
    if(Networking::isAuthenticated()) {
        m_CurrentPageID = PageID::Home;
        addAndMakeVisible(m_HomePage);
        m_AppHeader.getHeaderLabel().setText("Home", juce::dontSendNotification);
        addAndMakeVisible(m_AppHeader);
        addAndMakeVisible(m_PageNavigator);
    }else {
        m_CurrentPageID = PageID::Login;
        addAndMakeVisible(m_LoginPage);
        m_AppHeader.setVisible(false);
    }
    

    m_PageNavigator.getHomeButton().onClick = [&] {
        if(Networking::isAuthenticated()) //checks whether the user is logged in,  only then will the page opened
            openHomePage();
        else
            openLoginPage();
    };

    m_PageNavigator.getNewsButton().onClick = [&] {
        if(Networking::isAuthenticated())
            openNewsPage();
        else
            openLoginPage();
    };

    m_PageNavigator.getNotificationsButton().onClick = [&] {
        if(Networking::isAuthenticated())
            openNotificationsPage();
        else
            openLoginPage();
    };

    m_PageNavigator.getSettingsButton().onClick = [&] {
        if(Networking::isAuthenticated())
            openSettingsPage();
        else
            openLoginPage();
    };

    m_PageNavigator.getAccountButton().onClick = [&] {
        if(Networking::isAuthenticated())
            openAccountPage();
        else
            openLoginPage();
    };

    m_PageNavigator.getProductsButton().onClick = [&] {
        if(Networking::isAuthenticated())
            openProductsPage();
        else
            openLoginPage();
    };
    
}



MainComponent::~MainComponent()
{
}

void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Desktop::getInstance().isDarkModeActive()
        ? ColourPalette::getDarkModeBgColour()
        : juce::Colours::white);

    hideNavbar(); // Hide the navbar when scrolled

    static int lastNotificationValue = -1; // Initialize with an impossible value

    int currentNotificationValue = Networking::getNotificationValue();

    if (currentNotificationValue != lastNotificationValue) {
        // The notification value has changed, update the counter
        m_PageNavigator.getNotifcationCounter().setValue(currentNotificationValue);
        DBG("Notifications = " << currentNotificationValue);
        
        // Update the last known value
        lastNotificationValue = currentNotificationValue;
    }
}





void MainComponent::resized()
{
    auto area = getLocalBounds();
    auto appHeaderArea = area.removeFromTop(120);
    auto pageArea = area;
    
    m_AppHeader.setBounds(appHeaderArea);
    
    m_HomePage.setBounds(pageArea);
   
    switch(m_CurrentPageID) {
        case PageID::Home :  {
            m_HomePage.setBounds(pageArea);
        }; break;
        case PageID::News : {
            m_NewsPage.setBounds(pageArea);
        }; break;
        case PageID::Products :{
            m_ProductsPage.setBounds(pageArea);
        }; break;
        case PageID::Account : {
            m_AccountPage.setBounds(pageArea);
        }; break;
        case PageID::Notifications : {
            m_NotificationsPage.setBounds(pageArea);
        }; break;
        case PageID::Settings : {
            m_SettingsPage.setBounds(pageArea);

        }; break;
        case PageID::Login : {
            m_LoginPage.setBounds(pageArea);
        }
            
    }
    
    m_PageNavigator.setBounds(20, getHeight() - 80, getWidth() - 40, 60);
    m_PageNavigator.toFront(true);
    
    
    // set the min and max value for navbar posy
    minNavLimit = m_PageNavigator.getY();
    maxNavLimit = m_PageNavigator.getY() + 82;
    

    
   
}

// Open the Home Page
void MainComponent::openHomePage() {
    m_CurrentPageID = PageID::Home;
    m_PageNavigator.getClickedButton() = ButtonType::Home;
    m_PageNavigator.repaint();

    removeChildComponent(&m_NewsPage);
    removeChildComponent(&m_ProductsPage);
    removeChildComponent(&m_AccountPage);
    removeChildComponent(&m_NotificationsPage);
    removeChildComponent(&m_SettingsPage);
    removeChildComponent(&m_LoginPage);


    addAndMakeVisible(m_HomePage);
    m_HomePage.setBounds(getLocalBounds());
    
    m_AppHeader.getHeaderLabel().setText("Home", juce::dontSendNotification);
    m_AppHeader.repaint();

    repaint();
    resized();
    
}

// Open the News Page
void MainComponent::openNewsPage() {
    m_CurrentPageID = PageID::News;
    m_PageNavigator.getClickedButton() = ButtonType::News;

    removeChildComponent(&m_HomePage);
    removeChildComponent(&m_ProductsPage);
    removeChildComponent(&m_AccountPage);
    removeChildComponent(&m_NotificationsPage);
    removeChildComponent(&m_SettingsPage);
    removeChildComponent(&m_LoginPage);


    addAndMakeVisible(m_NewsPage);
    m_NewsPage.setBounds(getLocalBounds());
    
    m_AppHeader.getHeaderLabel().setText("News", juce::dontSendNotification);
    m_AppHeader.repaint();

    repaint();
    resized();
    
}

// Open the Account Page
void MainComponent::openAccountPage() {
    m_CurrentPageID = PageID::Account;
    m_PageNavigator.getClickedButton() = ButtonType::UserAccount;

    removeChildComponent(&m_HomePage);
    removeChildComponent(&m_ProductsPage);
    removeChildComponent(&m_NewsPage);
    removeChildComponent(&m_NotificationsPage);
    removeChildComponent(&m_SettingsPage);
    removeChildComponent(&m_LoginPage);


    addAndMakeVisible(m_AccountPage);
    m_AccountPage.setBounds(getLocalBounds());
    
    m_AppHeader.getHeaderLabel().setText("Account", juce::dontSendNotification);
    m_AppHeader.repaint();

    repaint();
    resized();
    
}

// Open the Notifications Page
void MainComponent::openNotificationsPage() {
    m_CurrentPageID = PageID::Notifications;
    m_PageNavigator.getClickedButton() = ButtonType::Notification;

    removeChildComponent(&m_HomePage);
    removeChildComponent(&m_ProductsPage);
    removeChildComponent(&m_NewsPage);
    removeChildComponent(&m_AccountPage);
    removeChildComponent(&m_SettingsPage);
    removeChildComponent(&m_LoginPage);


    addAndMakeVisible(m_NotificationsPage);
    m_NotificationsPage.setBounds(getLocalBounds());
    
    m_AppHeader.getHeaderLabel().setText("Notifications", juce::dontSendNotification);
    m_AppHeader.repaint();

    repaint();
    resized();
    
}

// Open the Settings Page
void MainComponent::openSettingsPage() {
    m_CurrentPageID = PageID::Settings;
    m_PageNavigator.getClickedButton() = ButtonType::Settings;

    removeChildComponent(&m_HomePage);
    removeChildComponent(&m_ProductsPage);
    removeChildComponent(&m_NewsPage);
    removeChildComponent(&m_AccountPage);
    removeChildComponent(&m_NotificationsPage);
    removeChildComponent(&m_LoginPage);


    addAndMakeVisible(m_SettingsPage);
    m_SettingsPage.setBounds(getLocalBounds());
    
    m_AppHeader.getHeaderLabel().setText("Settings", juce::dontSendNotification);
    m_AppHeader.repaint();

    repaint();
    resized();
   
}

// Open the Products Page
void MainComponent::openProductsPage() {
    m_CurrentPageID = PageID::Products;
    m_PageNavigator.getClickedButton() = ButtonType::Products;

    removeChildComponent(&m_HomePage);
    removeChildComponent(&m_NewsPage);
    removeChildComponent(&m_AccountPage);
    removeChildComponent(&m_NotificationsPage);
    removeChildComponent(&m_SettingsPage);
    removeChildComponent(&m_LoginPage);


    addAndMakeVisible(m_ProductsPage);
    m_ProductsPage.setBounds(getLocalBounds());
    
    m_AppHeader.getHeaderLabel().setText("Products", juce::dontSendNotification);
    m_AppHeader.repaint();

    repaint();
    resized();
    
}

void MainComponent::openLoginPage() {
    m_CurrentPageID = PageID::Login;

    removeChildComponent(&m_HomePage);
    removeChildComponent(&m_NewsPage);
    removeChildComponent(&m_AccountPage);
    removeChildComponent(&m_NotificationsPage);
    removeChildComponent(&m_SettingsPage);
    removeChildComponent(&m_ProductsPage);


    addAndMakeVisible(m_LoginPage);
    m_LoginPage.setBounds(getLocalBounds());
    
    m_AppHeader.getHeaderLabel().setText("Sign In", juce::dontSendNotification);
    m_AppHeader.getHeaderLabel().setJustificationType(juce::Justification::centred);
    m_AppHeader.repaint();

    repaint();
    resized();
}



void MainComponent::hideNavbar() {
    
    switch (m_CurrentPageID) {
        case Home:{
                int currentPos = m_HomePage.getScrollPosition();
                int scrollDelta = currentPos - temp_pos;
            
                // Define the ratio of scroll to movement (1 pixels per unit of scroll)
                int movement = 1 * scrollDelta;
            
                // Calculate the new Y position
                int newY = m_PageNavigator.getY() + movement;
            
                // Limit the Y position to never go below `minNavLimit` or above `maxNavLimit`
                newY = juce::jlimit(minNavLimit, maxNavLimit, newY);
            
                m_PageNavigator.setBounds(m_PageNavigator.getX(), newY,
                    m_PageNavigator.getWidth(), m_PageNavigator.getHeight());
            
                temp_pos = currentPos;
        };break;
            
        case Notifications: {
            int currentPos = m_NotificationsPage.getScrollPosition();
            int scrollDelta = currentPos - temp_pos;

            // Define the ratio of scroll to movement (1 pixels per unit of scroll)
            int movement = 1 * scrollDelta;

            // Calculate the new Y position
            int newY = m_PageNavigator.getY() + movement;

            // Limit the Y position to never go below `minNavLimit` or above `maxNavLimit`
            newY = juce::jlimit(minNavLimit, maxNavLimit, newY);

            m_PageNavigator.setBounds(m_PageNavigator.getX(), newY,
                m_PageNavigator.getWidth(), m_PageNavigator.getHeight());

            temp_pos = currentPos;
        };break;
            
        case Products: {
            int currentPos = m_ProductsPage.getScrollPosition();
            int scrollDelta = currentPos - temp_pos;

            // Define the ratio of scroll to movement (1 pixels per unit of scroll)
            int movement = 1 * scrollDelta;

            // Calculate the new Y position
            int newY = m_PageNavigator.getY() + movement;

            // Limit the Y position to never go below `minNavLimit` or above `maxNavLimit`
            newY = juce::jlimit(minNavLimit, maxNavLimit, newY);

            m_PageNavigator.setBounds(m_PageNavigator.getX(), newY,
                m_PageNavigator.getWidth(), m_PageNavigator.getHeight());

            temp_pos = currentPos;
        };break;
            
        case Settings: {
            int currentPos = m_SettingsPage.getScrollPosition();
            int scrollDelta = currentPos - temp_pos;

            // Define the ratio of scroll to movement (1 pixels per unit of scroll)
            int movement = 1 * scrollDelta;

            // Calculate the new Y position
            int newY = m_PageNavigator.getY() + movement;

            // Limit the Y position to never go below `minNavLimit` or above `maxNavLimit`
            newY = juce::jlimit(minNavLimit, maxNavLimit, newY);

            m_PageNavigator.setBounds(m_PageNavigator.getX(), newY,
                m_PageNavigator.getWidth(), m_PageNavigator.getHeight());

            temp_pos = currentPos;
        };break;
            
        case News: {
            int currentPos = m_NewsPage.getScrollPosition();
            int scrollDelta = currentPos - temp_pos;

            // Define the ratio of scroll to movement (1 pixels per unit of scroll)
            int movement = 1 * scrollDelta;

            // Calculate the new Y position
            int newY = m_PageNavigator.getY() + movement;

            // Limit the Y position to never go below `minNavLimit` or above `maxNavLimit`
            newY = juce::jlimit(minNavLimit, maxNavLimit, newY);

            m_PageNavigator.setBounds(m_PageNavigator.getX(), newY,
                m_PageNavigator.getWidth(), m_PageNavigator.getHeight());

            temp_pos = currentPos;
        };break;
            
        case Account: {
            int currentPos = m_AccountPage.getScrollPosition();
            int scrollDelta = currentPos - temp_pos;

            // Define the ratio of scroll to movement (1 pixels per unit of scroll)
            int movement = 1 * scrollDelta;

            // Calculate the new Y position
            int newY = m_PageNavigator.getY() + movement;

            // Limit the Y position to never go below `minNavLimit` or above `maxNavLimit`
            newY = juce::jlimit(minNavLimit, maxNavLimit, newY);

            m_PageNavigator.setBounds(m_PageNavigator.getX(), newY,
                m_PageNavigator.getWidth(), m_PageNavigator.getHeight());

            temp_pos = currentPos;
        };break;
  
        case Login: m_PageNavigator.setVisible(false); break;

    }
}



