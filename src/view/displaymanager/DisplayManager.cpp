#include "./DisplayManager.h"

void DisplayManager::setup(Input* pInput, Beats* pBeats, Channels* pChannels){
    mpChannels = pChannels;
    mpInput = pInput;
    mpBeats = pBeats;-=
}

void DisplayManager::update(){
    for(unsigned int i = 0; i < mpChannels->mDisplayBuffer.size(); i++){
        //mChannels.at( mpChannels->mDisplayBuffer.at(i) )->update();
    }
}

void DisplayManager::draw(){
    for(unsigned int i = 0; i < mpChannels->mDisplayBuffer.size(); i++){
        //mChannels.at( mpChannels->mDisplayBuffer.at(i) )->draw();
    }
}