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
    mpChannels->addSelectableChannel(0, "Channel0");
    mpChannels->addSelectableChannel(1, "Channel1");
    mpChannels->addSelectableChannel(2, "Channel2");
    mpChannels->addSelectableChannel(3, "Channel3");
    mpChannels->addSelectableChannel(4, "Channel4");
    mpChannels->addSelectableChannel(5, "Channel5");
    mpChannels->addActiveChannel(mpChannels->getSelectableChannel(0));
    mpChannels->addActiveChannel(mpChannels->getSelectableChannel(1));
    mpChannels->addActiveChannel(mpChannels->getSelectableChannel(2));
    mpChannels->addActiveChannel(mpChannels->getSelectableChannel(3));
    ofLog(OF_LOG_VERBOSE) << " - ModelConfig::setupChannels() ("<<ofGetElapsedTimef()<<")";
}

void ModelConfig::setupMouse(){
    ofLog(OF_LOG_VERBOSE) << " + ModelConfig::setupMouse() ("<<ofGetElapsedTimef()<<")";
    mpMouse->reset();
    ofLog(OF_LOG_VERBOSE) << " - ModelConfig::setupMouse() ("<<ofGetElapsedTimef()<<")";
}