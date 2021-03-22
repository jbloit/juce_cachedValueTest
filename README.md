# juce_cachedValueTest
Access/Change a model from a gui element, the JUCE way (at least how I do it)


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
