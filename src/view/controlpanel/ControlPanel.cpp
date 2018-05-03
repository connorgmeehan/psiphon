#include "view/controlpanel/ControlPanel.h"

void ControlPanel::setup(Beats *pBeat, Input *pInput, Mouse *pMouse, Channels *pChannels){

    mpIn = pInput;
    mpBeats = pBeat;
    mpMouse = pMouse;
    mpChannels = pChannels;

    ControlSubComponent::textFont.load("HelveticaNeueCyr-Light.otf", 9, true, false);

    ofAddListener(ofEvents().mouseMoved, this, &ControlPanel::mouseMoved);
    ofAddListener(ofEvents().mouseDragged, this, &ControlPanel::mouseDragged);
    ofAddListener(ofEvents().mousePressed, this, &ControlPanel::mousePressed, OF_EVENT_ORDER_AFTER_APP);

    ControlWindow::setPointers(mpBeats, mpIn, mpMouse, mpChannels);

    addControlElement( &mDebugDisplay, ofToString("debug"), ofVec2f(920, 600), ofVec2f(100, 60));
    addControlElement( &mFourierDisplay, ofToString("fourier"), ofVec2f(400, 100),  ofVec2f(512, 256) );

    addControlElement( &mDisplayBin, ofToString("display_bin"), ofVec2f(10,366), ofVec2f(204,150));
    addControlElement( &mChannelBin, ofToString("channel_bin"), ofVec2f(10,100),ofVec2f(200,256));
    addControlElement( &mKickDisplay, ofToString("beat_kick"), ofVec2f(922, 100), ofVec2f(70, 50));
    mKickDisplay.setBeatIndex(0);
    addControlElement( &mSnareDisplay, ofToString("beat_snare"), ofVec2f(922, 160), ofVec2f(70, 50));
    mSnareDisplay.setBeatIndex(1);
    addControlElement( &mHatDisplay, ofToString("beat_hat"), ofVec2f(922, 220), ofVec2f(70, 50));
    mHatDisplay.setBeatIndex(2);

    mpMouse->mDragable.setup();
    mpMouse->mDragable.enableAppEvents();
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

    window->setId((int) mControlWindows.size());
    window->setup();
    
    mControlWindows.push_back( window );
}

void ControlPanel::mouseMoved(ofMouseEventArgs & e){
    mpMouse->update(e.x, e.y); // updates the position of the dragable GU when mouse moves
}

void ControlPanel::mouseDragged(ofMouseEventArgs & e){
    mpMouse->update(e.x, e.y);
}

void ControlPanel::mousePressed(ofMouseEventArgs & e){
    mpMouse->reset();
}