#include "view/controlpanel/ControlPanel.h"

void ControlPanel::setup(Beats *pBeat, Input *pInput, Mouse *pMouse, Channels *pChannels){

    mpIn = pInput;
    mpBeats = pBeat;
    mpMouse = pMouse;
    mpChannels = pChannels;

    ControlWindow::setPointers(mpBeats, mpIn, mpMouse, mpChannels);

    addControlElement( &mDebugDisplay, ofToString("debug"), ofVec2f(800, 100), ofVec2f(100, 60));
    addControlElement( &mFourierDisplay, ofToString("fourier"), ofVec2f(10, 100),  ofVec2f(512, 256) );

    addControlElement( &mKickDisplay, ofToString("beat_kick"), ofVec2f(522, 100), ofVec2f(70, 50));
    mKickDisplay.setBeatIndex(0);
    addControlElement( &mSnareDisplay, ofToString("beat_snare"), ofVec2f(522, 160), ofVec2f(70, 50));
    mSnareDisplay.setBeatIndex(1);
    addControlElement( &mHatDisplay, ofToString("beat_hat"), ofVec2f(522, 220), ofVec2f(70, 50));
    mHatDisplay.setBeatIndex(2);

    addControlElement( &mDisplayBin, ofToString("display_bin"), ofVec2f(800,100), ofVec2f(204,400));
}

void ControlPanel::update(){

}

void ControlPanel::draw(){

}

void ControlPanel::addControlElement(ControlWindow* window, std::string name, ofVec2f translate, ofVec2f dimensions){
    window->setName(name);
    window->setPosition(translate.x, translate.y);
    window->setSize(dimensions.x, dimensions.y);

    window->enableAllEvents();

    window->setup();
    window->setId((int) mControlWindows.size());

    mControlWindows.push_back( window );
}