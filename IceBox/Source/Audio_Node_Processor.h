/*
  ==============================================================================

    Audio_Node_Processor.h
    Created: 19 Feb 2015 1:48:32pm
    Author:  conner@emergent.io

  ==============================================================================
*/

#ifndef AUDIO_NODE_PROCESSOR_H_INCLUDED
#define AUDIO_NODE_PROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

/** 
 An empty class to be used as a guide for building audio processing nodes.
 
 This class should not be implemented directly or inherited. It serves as
 a template (not in the C++ sense of a template) or blueprint for building 
 new processors. It is intended simply to ease the process of getting started.
 
 To actually write a processor, create new .h and .cpp files with whatever
 filename you see fit. Using the supplied naming convention is suggested.
 "Audio_Node_Processor_Delay.h" and "Audio_Node_Processor_Delay.cpp", for
 example, would make good choices for a delay processor.
 
 Next, copy the code in between "#ifndef AUDIO_NODE_PROCESSOR_H_INCLUDED"
 and "#endif  // AUDIO_NODE_PROCESSOR_H_INCLUDED", and paste it into your new
 class. Then, just change the class name, constructor, and destructor names of
 the pasted code to match your new class.
 
 Your new processor class would consist of two new files:
    Audio_Node_Processor_YOURNAME.h
    Audio_Node_Processor_YOURNAME.cpp
 
 And contain modified code form this class, with adjusted 
 constructors/destructor:
    Audio_Node_Processor_YOURNAME();
    ~Audio_Node_Processor_YOURNAME();
 
 Note: The pure virtual functions for JUCE's AudioProcessor class have been 
 implemented. If you need to override any of AudioProcessor's virtual 
 functions, just uncomment their declaration in the header file and define
 them.
 */

class Audio_Node_Processor : AudioProcessor
{
    Audio_Node_Processor();
    ~Audio_Node_Processor();
    
    //=========================================================================
    //================ Audio Processor Pure Virtual Functions =================
    //=========================================================================
    
    //-------------------- Initialization / Processing ------------------------
    void prepareToPlay(double sampleRate, int estimatedSamplesPerBlock);
    void releaseResources();
    void processBlock(AudioSampleBuffer &buffer, MidiBuffer &midiMessages);
    
    //------------------------- Processor Properties --------------------------
    const String getName() const = 0;
    const String getInputChannelName (int channelIndex) const = 0;
    const String getOutputChannelName (int channelIndex) const = 0;
    bool isInputChannelStereoPair (int index) const = 0;
    bool isOutputChannelStereoPair (int index) const = 0;
    bool silenceInProducesSilenceOut() const = 0;
    double getTailLengthSeconds() const = 0;
    bool acceptsMidi() const = 0;
    bool producesMidi() const = 0;
    
    //------------------------ Audio Processor Editor -------------------------
    AudioProcessorEditor* createEditor() = 0;
    bool hasEditor() const = 0;
    
    //-------------------------- Presets (Programs) ---------------------------
    int	getNumPrograms ()=0;
    int	getCurrentProgram ()=0;
    void setCurrentProgram (int index)=0;
    const String getProgramName (int index) = 0;
    void changeProgramName (int index, const String &newName)=0;
    void getStateInformation (MemoryBlock &destData)=0;
    void setStateInformation (const void *data, int sizeInBytes)=0;
    
    
    //=========================================================================
    //================== Audio Processor Virtual Functions ====================
    //=========================================================================
    
    //------------------------- Processing / State ----------------------------
    // void processBlockBypassed (AudioSampleBuffer& buffer,MidiBuffer& midiMessages);
    // void reset();
    // void setNonRealtime (bool isNonRealtime) noexcept;
    
    //------------------------- Processor Properties --------------------------
    // int getNumParameters();
    // const String getParameterName (int parameterIndex);
    // float getParameter (int parameterIndex);
    // const String getParameterText (int parameterIndex);
    // String getParameterName (int parameterIndex, int maximumStringLength);
    // String getParameterText (int parameterIndex, int maximumStringLength);
    // int getParameterNumSteps (int parameterIndex);
    // float getParameterDefaultValue (int parameterIndex);
    // String getParameterLabel (int index) const;
    // bool isParameterOrientationInverted (int index) const;
    // void setParameter (int parameterIndex, float newValue);
    // bool isParameterAutomatable (int parameterIndex) const;
    // bool isMetaParameter (int parameterIndex) const;
    // void numChannelsChanged();
    // void addListener (AudioProcessorListener* newListener);
    // void removeListener (AudioProcessorListener* listenerToRemove);
    // void setPlayHead (AudioPlayHead* newPlayHead);
    
    //-------------------------- Presets (Programs) ---------------------------
    // void getCurrentProgramStateInformation (juce::MemoryBlock& destData);
    // void setCurrentProgramStateInformation (const void* data, int sizeInBytes);
    
};



#endif  // AUDIO_NODE_PROCESSOR_H_INCLUDED
