#include "engine/ModelConfig/ModelConfig.h"

void ModelConfig::setup(Beats* pBeats, Channels* pChannels, Input* pInput, Mouse* pMouse, DisplayManager* pDisplayManager){
    ofLog(OF_LOG_VERBOSE) << " + ModelConfig::setup() ("<<ofGetElapsedTimef()<<")";
    mpBeats = pBeats;
    mpChannels = pChannels;
    mpInput = pInput;
    mpMouse = pMouse;
    mpDisplayManager = pDisplayManager;

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

    for(unsigned int i = 0; i < mpDisplayManager->mChannels.size(); i++){
        mpChannels->addChannel(i, mpDisplayManager->mChannels[i]->getName(), mpDisplayManager->mChannels[i]->getFolderName() );
    }
    
    ofLog(OF_LOG_VERBOSE) << " - ModelConfig::setupChannels() ("<<ofGetElapsedTimef()<<")";
}

void ModelConfig::setupMouse(){
    ofLog(OF_LOG_VERBOSE) << " + ModelConfig::setupMouse() ("<<ofGetElapsedTimef()<<")";
    mpMouse->reset();
    ofLog(OF_LOG_VERBOSE) << " - ModelConfig::setupMouse() ("<<ofGetElapsedTimef()<<")";
}