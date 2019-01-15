# AdaptiveLearningLibrary
An adaptive learning library

What started out as an attempt to write my own machine learning library, now turned into a playground for me to implement impossible stuff in C++, maybe somewhere along the way I go back to the original idea.

1- Event system 

yes! there is already boost's signal and slots, and you can also use the pattern used extensively in JUCE, but this one tries to mimick the behaviour of events in C#. That is the event is public for subscription and raising the event can be held private for the object that owns the event
