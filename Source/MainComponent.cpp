#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    addAndMakeVisible(m_PageNavigator);
    m_CurrentPageID = PageID::Home;
    addAndMakeVisible(m_HomePage);
    setSize(600, 400);

    m_PageNavigator.getHomeButton().onClick = [&] {
        openHomePage();
    };

    m_PageNavigator.getNewsButton().onClick = [&] {
        openNewsPage();
    };

    m_PageNavigator.getNotificationsButton().onClick = [&] {
        openNotificationsPage();
    };

    m_PageNavigator.getSettingsButton().onClick = [&] {
        openSettingsPage();
    };

    m_PageNavigator.getAccountButton().onClick = [&] {
        openAccountPage();
    };

    m_PageNavigator.getProductsButton().onClick = [&] {
        openProductsPage();
    };
    
    
}



MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    if(juce::Desktop::getInstance().isDarkModeActive() == true){
        g.fillAll(ColourPalette::getDarkModeBgColour());

    }
    else {
        g.fillAll(juce::Colours::white);

    }
}

void MainComponent::resized()
{
    auto area = getLocalBounds();
    area.removeFromTop(50);
    
    auto pageArea = area;
    
    
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
            
    }
    
    m_PageNavigator.setBounds(20, getHeight() - 80, getWidth() - 40, 60);
    m_PageNavigator.toFront(true);
    
   
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

    addAndMakeVisible(m_HomePage);
    m_HomePage.setBounds(getLocalBounds());

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

    addAndMakeVisible(m_NewsPage);
    m_NewsPage.setBounds(getLocalBounds());

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

    addAndMakeVisible(m_AccountPage);
    m_AccountPage.setBounds(getLocalBounds());

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

    addAndMakeVisible(m_NotificationsPage);
    m_NotificationsPage.setBounds(getLocalBounds());

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

    addAndMakeVisible(m_SettingsPage);
    m_SettingsPage.setBounds(getLocalBounds());

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

    addAndMakeVisible(m_ProductsPage);
    m_ProductsPage.setBounds(getLocalBounds());

    repaint();
    resized();
    
}

