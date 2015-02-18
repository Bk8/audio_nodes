/*
  ==============================================================================

    AudioInputToOutput.cpp
    Created: 31 Jan 2015 1:46:17pm
    Author:  Conner Lacy

  ==============================================================================
*/

#include "AudioInputToOutput.h"

AudioInputToOutput::AudioInputToOutput()
{
    
    reverb = new Reverb();
    
    Reverb::Parameters reverbParams;
    reverbParams.roomSize = 0.5;
    reverbParams.damping = 0.5;
    reverbParams.wetLevel = 1.0;
    reverbParams.dryLevel = 0.0;
    reverbParams.freezeMode = 0.0;
    
    reverb->setParameters(reverbParams);
}

void AudioInputToOutput::freeze(bool onOrOff)
{
    auto reverbParams = reverb->getParameters();
    
    if(onOrOff)
    {
        reverbParams.freezeMode = 1.0;
    }
    else
    {
        reverbParams.freezeMode = 0.0;
    }
    
    reverb->setParameters(reverbParams);
}

void AudioInputToOutput::audioDeviceIOCallback(const float **inputChannelData, int numInputChannels, float **outputChannelData, int numOutputChannels, int numSamples)
{
    for (int i = 0; i < numSamples; i++)
    {
        for (int j = numInputChannels; j >= 0; j--)
        {
            if(inputChannelData[j] != 0 && outputChannelData[j] != 0)
            {
                outputChannelData[j][i] = inputChannelData[j][i];
            }
        }
    }
    
    //Reverb
    reverb->processStereo(outputChannelData[0], outputChannelData[1], numSamples);
}

void AudioInputToOutput::audioDeviceAboutToStart(AudioIODevice *device)
{
    DBG("Device about to start:" + device->getName());
    
    if(device->getInputChannelNames().size() == device->getOutputChannelNames().size());
    {
        DBG(device->getName() + "has equal number of input and output channels");
    }
}

void AudioInputToOutput::audioDeviceStopped()
{
    
}

void AudioInputToOutput::audioDeviceError(const String &errorMessage)
{
    DBG("Audio Device ERROR:" + errorMessage);
}

void AudioInputToOutput::setToggle(ToggleButton *tog)
{
    toggle = tog;
}

