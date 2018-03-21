#pragma once
#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlWindow.h"

//Model
#include "model/Input.h"
#include "model/Beats.h"
#include "model/Mouse.h"
#include "model/Channels.h"

#include "view/controlpanel/components/DebugDisplay.cpp"
#include "view/controlpanel/components/FourierDisplay.cpp"
#include "view/controlpanel/components/BeatDisplay.cpp"
#include "view/controlpanel/components/DisplayBin/DisplayBin.h"


class ControlPanel {
private:
    Beats *mpBeats;
    Input *mpIn;
    Mouse *mpMouse;
    Channels *mpChannels;

    vector<ControlWindow*> mControlWindows; // stores all renderable and updatable elements in the control panel.

    DebugDisplay mDebugDisplay;
    FourierDisplay mFourierDisplay; // FFT Display TODO: Add the ability to move the beat analysers and change the radius.
    BeatDisplay mKickDisplay;   //Beat display shows amplitude and velocity as well as a boolean where there is currently a beat.
    BeatDisplay mSnareDisplay;
    BeatDisplay mHatDisplay;

    DisplayBin mDisplayBin;
public:
    void setup(Beats *pBeat, Input *pIn, Mouse *pMouse, Channels *pChannels);
    void update();
    void draw();

    void addControlElement(ControlWindow* window, std::string name, ofVec2f translate, ofVec2f dimensions);
};

