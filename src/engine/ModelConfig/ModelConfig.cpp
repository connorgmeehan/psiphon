#include "engine/ModelConfig/ModelConfig.h"

void ModelConfig::setup(Beats* pBeats, Channels* pChannels, Input* pInput, Mouse* pMouse){
    ofLog(OF_LOG_VERBOSE) << " + ModelConfig::setup() ("<<ofGetElapsedTimef()<<")";
    mpBeats = pBeats;
    mpChannels = pChannels;
    mpInput = pInput;
    mpMouse = pMouse;

    setupInput();
    setupBeats();
    setupChannels();
    setupMouse();
    ofLog(OF_LOG_VERBOSE) << " - ModelConfig::setup() ("<<ofGetElapsedTimef()<<")";
}

void ModelConfig::setupInput(){
    ofLog(OF_LOG_VERBOSE) << " + ModelConfig::setupInput() ("<<ofGetElapsedTimef()<<")";
    mpInput->bufferSize = PSI_BUFFER_SIZE;
    mpInput->fourier.resize(mpInput->bufferSize);
    ofLog(OF_LOG_VERBOSE) << " - ModelConfig::setupInput() ("<<ofGetElapsedTimef()<<")";
}

void ModelConfig::setupBeats(){
    ofLog(OF_LOG_VERBOSE) << " + ModelConfig::setupBeats() ("<<ofGetElapsedTimef()<<")";
    mpBeats->addBeat("kick", mpInput->bufferSize*0.02, mpInput->bufferSize*0.01);
    mpBeats->addBeat("snare", mpInput->bufferSize*0.06, mpInput->bufferSize*0.03);
    mpBeats->addBeat("hihat", mpInput->bufferSize*0.15, mpInput->bufferSize*0.10);
    ofLog(OF_LOG_VERBOSE) << " - ModelConfig::setupBeats() ("<<ofGetElapsedTimef()<<")";
}

void ModelConfig::setupChannels(){
    ofLog(OF_LOG_VERBOSE) << " + ModelConfig::setupChannels() ("<<ofGetElapsedTimef()<<")";
    //Channel dummy data
    mpChannels->addChannel(0, "Channel0", "basic");
    mpChannels->addChannel(1, "Channel1", "basic");
    mpChannels->addChannel(2, "Channel2", "basic2");
    mpChannels->addChannel(3, "Channel3", "basic2");
    mpChannels->addChannel(4, "Channel4", "basic2");
    mpChannels->addChannel(5, "Channel5", "basic3");
    mpChannels->addChannel(6, "Channel0", "basic3");
    mpChannels->addChannel(7, "Channel1", "basic3");
    mpChannels->addChannel(8, "Channel2", "basic4");
    mpChannels->addChannel(9, "Channel3", "basic4");
    mpChannels->addChannel(10, "Channel4", "basic4");
    mpChannels->addChannel(11, "Channel5", "basic5");
    mpChannels->addToBuffer(mpChannels->getChannel(0),0);
    mpChannels->addToBuffer(mpChannels->getChannel(1),0);
    mpChannels->addToBuffer(mpChannels->getChannel(2),0);
    mpChannels->addToBuffer(mpChannels->getChannel(3),0);
    ofLog(OF_LOG_VERBOSE) << " - ModelConfig::setupChannels() ("<<ofGetElapsedTimef()<<")";
}

void ModelConfig::setupMouse(){
    ofLog(OF_LOG_VERBOSE) << " + ModelConfig::setupMouse() ("<<ofGetElapsedTimef()<<")";
    mpMouse->reset();
    ofLog(OF_LOG_VERBOSE) << " - ModelConfig::setupMouse() ("<<ofGetElapsedTimef()<<")";
}