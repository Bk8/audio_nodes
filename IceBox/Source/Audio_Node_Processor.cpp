/*
  ==============================================================================

    Audio_Node_Processor.cpp
    Created: 19 Feb 2015 1:48:32pm
    Author:  connerlacy

  ==============================================================================
*/

#include "Audio_Node_Processor.h"

//==============================================================================
//================== Audio Processor Pure Virtual Functions ====================
//==============================================================================

//----------------------- Initialization / Processing --------------------------

void Audio_Node_Processor::prepareToPlay(double sampleRate, int estimatedSamplesPerBlock)
{
    
}

void Audio_Node_Processor::releaseResources()
{
    
}

void Audio_Node_Processor::processBlock(AudioSampleBuffer &buffer, MidiBuffer &midiMessages)
{
    
}


//-------------------------- Processor Properties ------------------------------

const String Audio_Node_Processor::getName() const
{
    
}

const String Audio_Node_Processor::getInputChannelName (int channelIndex) const
{
    
}

const String Audio_Node_Processor::getOutputChannelName (int channelIndex) const
{
    
}

bool Audio_Node_Processor::isInputChannelStereoPair (int index) const
{
    
}

bool Audio_Node_Processor::isOutputChannelStereoPair (int index) const
{
    
}

bool Audio_Node_Processor::silenceInProducesSilenceOut () const
{
    
}

double Audio_Node_Processor::getTailLengthSeconds () const
{
    
}

bool Audio_Node_Processor::acceptsMidi () const
{
    
}

bool Audio_Node_Processor::producesMidi () const
{
    
}


//----------------------- Audio Processor Editor -------------------------------

AudioProcessorEditor* Audio_Node_Processor::createEditor()
{
    
}

bool Audio_Node_Processor::hasEditor() const
{
    
}


//------------------------- Presets (Programs) ---------------------------------

int	Audio_Node_Processor::getNumPrograms ()
{
    
}

int	Audio_Node_Processor::getCurrentProgram ()
{
    
}

void Audio_Node_Processor::setCurrentProgram (int index)
{
    
}

const String Audio_Node_Processor::getProgramName (int index)
{
    
}

void Audio_Node_Processor::changeProgramName (int index, const String &newName)
{
    
}

void Audio_Node_Processor::getStateInformation (juce::MemoryBlock &destData)
{
    
}

void Audio_Node_Processor::setStateInformation (const void *data, int sizeInBytes)
{
    
}