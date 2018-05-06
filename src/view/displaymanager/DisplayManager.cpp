#include "./DisplayManager.h"

void DisplayManager::setup(Input* pInput, Beats* pBeats, Channels* pChannels){
    mpChannels = pChannels;
    mpInput = pInput;
    mpBeats = pBeats;

    mChannels.push_back(mGrid);
}

void DisplayManager::update(){
    ChannelPrimitive::setFFT(mpInput->fourier);
    for(unsigned int i = 0; i < mpChannels->mDisplayBuffer.size(); i++){
        if(mpChannels->mDisplayBuffer.at(i) != -1){
            mChannels.at( mpChannels->mDisplayBuffer.at(i) )->update();
        }
    }
}

void DisplayManager::draw(){
    for(unsigned int i = 0; i < mpChannels->mDisplayBuffer.size(); i++){
        if(mpChannels->mDisplayBuffer.at(i) != -1){
            mChannels.at( mpChannels->mDisplayBuffer.at(i) )->draw();
        }
    }
}