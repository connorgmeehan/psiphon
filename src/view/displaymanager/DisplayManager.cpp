#include "./DisplayManager.h"

void DisplayManager::setup(Input* pInput, Beats* pBeats, Channels* pChannels){
    mpChannels = pChannels;
    mpInput = pInput;
    mpBeats = pBeats;

    mChannels.push_back(mGrid);
}

void DisplayManager::update(){
    ChannelPrimitive::setFFT(mpInput->fourier);

    if( mpBeats->at(0)->getState() == 1 ){ onKick( mpBeats->at(0)->amp ); } 
    if( mpBeats->at(1)->getState() == 1 ){ onSnare( mpBeats->at(1)->amp ); } 
    if( mpBeats->at(2)->getState() == 1 ){ onHat( mpBeats->at(2)->amp ); } 

    for(unsigned int i = 0; i < mpChannels->mDisplayBuffer.size(); i++){
        if( mpChannels->mDisplayBuffer.at(i).mId != -1){

            if(mChannels.at( mpChannels->mDisplayBuffer.at(i).mId )->isSetup == false){
                mChannels.at( mpChannels->mDisplayBuffer.at(i).mId )->setup();
                mChannels.at( mpChannels->mDisplayBuffer.at(i).mId )->isSetup = true;
            }

            mChannels.at( mpChannels->mDisplayBuffer.at(i).mId )->update();
        }
    }
}

void DisplayManager::draw(){
    for(unsigned int i = 0; i < mpChannels->mDisplayBuffer.size(); i++){
        if(mpChannels->mDisplayBuffer.at(i).mId != -1){
            mChannels.at( mpChannels->mDisplayBuffer.at(i).mId )->draw();
        }
    }
}

void DisplayManager::onKick(float & amp){
    ofLog(OF_LOG_VERBOSE) << "Display::Manager::onKick(amp:"<<amp<<");";
    for(unsigned int i = 0; i < mpChannels->mDisplayBuffer.size(); i++){
        if(mpChannels->mDisplayBuffer.at(i).mId != -1){
            mChannels.at( mpChannels->mDisplayBuffer.at(i).mId )->onKick(amp);
        }
    }
}

void DisplayManager::onSnare(float & amp){
    ofLog(OF_LOG_VERBOSE) << "Display::Manager::onSnare(amp:"<<amp<<");";
    for(unsigned int i = 0; i < mpChannels->mDisplayBuffer.size(); i++){
        if(mpChannels->mDisplayBuffer.at(i).mId != -1){
            mChannels.at( mpChannels->mDisplayBuffer.at(i).mId )->onSnare(amp);
        }
    }
}

void DisplayManager::onHat(float & amp){
    ofLog(OF_LOG_VERBOSE) << "Display::Manager::onHat(amp:"<<amp<<");";
    for(unsigned int i = 0; i < mpChannels->mDisplayBuffer.size(); i++){
        if(mpChannels->mDisplayBuffer.at(i).mId != -1){
            mChannels.at( mpChannels->mDisplayBuffer.at(i).mId )->onHat(amp);
        }
    }
}