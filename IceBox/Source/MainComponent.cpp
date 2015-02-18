/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    freezeMode = false;
    
    setSize (600, 400);
    toggle = new ToggleButton;
    toggle->setSize(30, 30);
    toggle->setTopLeftPosition(50, 50);
    addAndMakeVisible(toggle);

    _deviceManager.initialise(256, 256, 0, true);
    _deviceManager.addAudioCallback(&_audioProcessorPlayer);
    _audioProcessorPlayer.setProcessor(&_audioProcessorGraph);
    
    _audioProcessorGraph.addNode(new AudioProcessorGraph::AudioGraphIOProcessor (AudioProcessorGraph::AudioGraphIOProcessor::audioInputNode));
    _audioProcessorGraph.addNode(new AudioProcessorGraph::AudioGraphIOProcessor (AudioProcessorGraph::AudioGraphIOProcessor::audioOutputNode));
    
    DBG("NUM INPUT CHANNELS: " + String(_audioProcessorGraph.getNumInputChannels()));
    DBG("NUM OUTPUT CHANNELS: " + String(_audioProcessorGraph.getNumInputChannels()));
    DBG("NUM NODES:" + String(_audioProcessorGraph.getNumNodes()));
    
    AudioProcessorGraph::Node * node1 = _audioProcessorGraph.getNode(0);
    AudioProcessorGraph::Node * node2 = _audioProcessorGraph.getNode(1);
    
    
    DBG("NODE ID 0:" + String(node1->nodeId));
    DBG("NODE ID 1:" + String(node2->nodeId));
    
    _audioProcessorGraph.addConnection(node1->nodeId, 0, node2->nodeId, 1);
    _audioProcessorGraph.addConnection(node1->nodeId, 1, node2->nodeId, 0);
    
    DBG("NUM CONNECTIONS: " + String(_audioProcessorGraph.getNumConnections()));
    
    

}

MainContentComponent::~MainContentComponent()
{

}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff001F36));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
    
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
