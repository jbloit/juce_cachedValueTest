/*
  ==============================================================================

    SimpleGui.h
    Created: 22 Mar 2021 2:43:03pm
    Author:  Julien Bloit

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class SimpleGui  :
    public juce::Component,
    public juce::ValueTree::Listener
{
public:
    SimpleGui( juce::ValueTree& s) : state(s)
    {
        
        DBG("init button with state : " << s.toXmlString());
        addAndMakeVisible(incButton);
        auto label = state["myValue"].toString();
        incButton.setButtonText( label );
        
        cachedVal.referTo(state, "myValue", nullptr);
        
        state.addListener(this);
        
        incButton.onClick = [this](){
            
            cachedVal = cachedVal + 1;
            
        };
    }

    ~SimpleGui() override
    {
    }

    void paint (juce::Graphics& g) override
    {


        g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

        g.setColour (juce::Colours::grey);
        g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
        
        

    }

    void resized() override
    {
        auto area = getLocalBounds();
        incButton.setBounds(area.reduced(proportionOfWidth(0.3)));


    }

private:
    
    juce::ValueTree state;
    
    juce::TextButton incButton;
    
    juce::CachedValue <int> cachedVal;
    
    
    // This is needed to get notified when state is changed from outside of this GUI's context.
     void valueTreePropertyChanged (juce::ValueTree& tree,
                                           const juce::Identifier& property) override
    {
        if (property == juce::Identifier("myValue"))
        {
            
            incButton.setButtonText(cachedVal.getPropertyAsValue().toString());
        }
    }
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleGui)
};
