#pragma once
#include "ofMain.h"

//General Classes
#include "./ControlWindow/ControlWindow.h"
#include "./ControlWindow/ControlSubComponent.h"

//Model
#include "model/Input.h"
#include "model/Beats.h"
#include "model/Mouse.h"
#include "model/Channels.h"

//Components
#include "./components/DebugDisplay.cpp"
#include "./components/FourierDisplay/FourierDisplay.h"
#include "./components/BeatDisplay/BeatDisplay.h"
#include "./components/DisplayBin/DisplayBin.h"
#include "./components/ChannelBin/ChannelBin.h"


class ControlPanel {
private:
    Beats *mpBeats;
    Input *mpIn;
    Mouse *mpMouse;
    Channels *mpChannels;
    
    vector<ControlWindow*> mControlWindows; // stores all renderable and updatable elements in the control panel.

    DebugDisplay mDebugDisplay;
    FourierDisplay mFourierDisplay; // FFT Display TODO: Add the ability to move the beat analysers and change the radius.
    DisplayBin mDisplayBin;
    ChannelBin mChannelBin;
    BeatDisplay mKickDisplay;   //Beat display shows amplitude and velocity as well as a boolean where there is currently a beat.
    BeatDisplay mSnareDisplay;
    BeatDisplay mHatDisplay;


public:
    void setup(Beats *pBeat, Input *pIn, Mouse *pMouse, Channels *pChannels);
    void update();
    void draw();

    void addControlElement(ControlWindow* window, std::string name, ofVec2f translate, ofVec2f dimensions);

    void mouseMoved(ofMouseEventArgs & e);

};

