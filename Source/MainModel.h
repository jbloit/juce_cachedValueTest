/*
  ==============================================================================

    MainModel.h
    Created: 22 Mar 2021 2:42:19pm
    Author:  Julien Bloit

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class MainModel
{
    
public:
    MainModel()
    {
        
        juce::ValueTree simpleGuiState {"simpleGui"};
        simpleGuiState.setProperty("myValue", -1, nullptr);
        
        tree.appendChild(simpleGuiState, nullptr);
        
    };
    ~MainModel(){};
    
    juce::ValueTree getSimpleGuiState()
    {
        auto returnTree = tree.getChildWithName("simpleGui");
        DBG(" tree : \n" << tree.toXmlString());
        DBG("return tree : \n" << returnTree.toXmlString());
        return returnTree;
    }
    
    
        juce::ValueTree tree {"root"};
    
private:
    
    

    
    
    
};
