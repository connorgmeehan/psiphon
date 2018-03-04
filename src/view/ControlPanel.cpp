#include "view/ControlPanel.h"

void ControlPanel::setup(Beats *pBeat, Input *pInput){

    mpIn = pInput;
    mpBeats = pBeat;

    addControlElement( &mFourierDisplay, ofToString("fourier_display"), ofVec2f(10, 50) );
    addControlElement( &mKickDisplay, ofToString("beat_kick"), ofVec2f(538, 50));
}

void ControlPanel::update(){
    for(vector<ControlWindow>::size_type i = 0; i < mControlWindows.size(); i++){
        mControlWindows[i]->pre_update();
    }
}

void ControlPanel::draw(){
    for(vector<ControlWindow>::size_type i = 0; i < mControlWindows.size(); i++){
        mControlWindows[i]->pre_draw();
    }
}

void ControlPanel::addControlElement(ControlWindow* window, std::string name, ofVec2f translate){
    window->setBeatPointer(mpBeats);
    window->setInputPointer(mpIn);
    window->pre_setup(name, translate);
    mControlWindows.push_back( window );
}