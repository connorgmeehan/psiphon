#include "view/ControlPanel.h"

void ControlPanel::setup(Beats *pBeat, Input *pInput){

    mpIn = pInput;
    mpBeats = pBeat;

    addControlElement( &mFourierDisplay, ofToString("fourier_display"), ofVec2f(10, 50),  ofVec2f(512, 256) );


    addControlElement( &mKickDisplay, ofToString("beat_kick"), ofVec2f(522, 50), ofVec2f(70, 50));
    mKickDisplay.setBeatIndex(0);
    addControlElement( &mSnareDisplay, ofToString("beat_snare"), ofVec2f(522, 110), ofVec2f(70, 50));
    mSnareDisplay.setBeatIndex(1);
    addControlElement( &mHatDisplay, ofToString("beat_hat"), ofVec2f(522, 170), ofVec2f(70, 50));
    mHatDisplay.setBeatIndex(2);
}

void ControlPanel::update(){
    // for(vector<ControlWindow>::size_type i = 0; i < mControlWindows.size(); i++){
    //     mControlWindows[i]->_update();
    // }
}

void ControlPanel::draw(){

}

void ControlPanel::addControlElement(ControlWindow* window, std::string name, ofVec2f translate, ofVec2f dimensions){
    window->setBeatPointer(mpBeats);
    window->setInputPointer(mpIn);

    window->setName(name);
    window->setPosition(translate.x, translate.y);
    window->setSize(dimensions.x, dimensions.y);

    window->enableAllEvents();

    window->setup();

    mControlWindows.push_back( window );
}