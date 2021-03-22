#pragma once

#include <JuceHeader.h>
#include "SimpleGui.h"
#include "MainModel.h"


/**
 
 Goal of this test app:
 understanding how a cachedValue propagates its updated value
 up to the main tree that it references, and the other way around.
 
 Here the tree is constructed in MainModel, a singleton.
 
 The button in simpleGui is constructed with a state, that is a reference to
 a subtree from the main model. A local cached value in the simpleGui is incremented
 when user clicks the button. In the console, the main model is printed,
 the value is correctly updated in the main model.
 
 The other way around is not automatic though, incrementing the value in the main model
 doesn't update the cached value, nor is there a cachedValue listener.
 For updating from the model to the simpleGui, we register simpleGui as a listener to its state tree .
 
 */


class MainComponent  : public juce::Component, public juce::Timer
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    
    
private:

    juce::SharedResourcePointer<MainModel> model;

    std::unique_ptr<SimpleGui> simpleGui;
    
    void timerCallback() override;
    juce::CachedValue<int> stateValue;
    
    juce::TextButton incButton;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
