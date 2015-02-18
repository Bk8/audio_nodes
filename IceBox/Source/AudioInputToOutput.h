/*
  ==============================================================================

    AudioInputToOutput.h
    Created: 31 Jan 2015 1:46:17pm
    Author:  Conner Lacy

  ==============================================================================
*/

#ifndef AUDIOINPUTTOOUTPUT_H_INCLUDED
#define AUDIOINPUTTOOUTPUT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class AudioInputToOutput : public AudioIODeviceCallback
{
public:
    
    void setToggle(ToggleButton *tog);
    ScopedPointer<ToggleButton> toggle;
    
    AudioInputToOutput();
    
    ScopedPointer<Reverb> reverb;
    void freeze(bool onOrOff);
    
    void audioDeviceIOCallback(const float **inputChannelData, int numInputChannels, float **outputChannelData, int numOutputChannels, int numSamples);
    void audioDeviceAboutToStart (AudioIODevice *device);
    void audioDeviceStopped();
    void audioDeviceError(const String &errorMessage);
    
};


#endif  // AUDIOINPUTTOOUTPUT_H_INCLUDED
