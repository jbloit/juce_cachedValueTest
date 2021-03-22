#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    auto state = model->getSimpleGuiState();
    simpleGui.reset(new SimpleGui(state));

    stateValue.referTo(state, "myValue", nullptr);
    
    addAndMakeVisible(simpleGui.get());
    setSize (600, 400);
    
    
    addAndMakeVisible (incButton);
    incButton.setButtonText("INC myvalue in main model");
    incButton.onClick = [this]()
    {
        auto guistate = model->getSimpleGuiState();
        int val = guistate["myValue"];
        guistate.setProperty("myValue", val+1, nullptr);
    };
    
    startTimer(1000);
}

MainComponent::~MainComponent()
{
    simpleGui = nullptr;
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));


}

void MainComponent::resized()
{
    auto area = getLocalBounds();
    simpleGui->setBounds(area.removeFromLeft(proportionOfWidth(0.5)));
    
    incButton.setBounds(area.reduced(proportionOfWidth(0.1)));
}


void MainComponent::timerCallback()
{
        
        DBG("TIMER CALLBACK, model  \n"  << model->tree.toXmlString());
    
}
