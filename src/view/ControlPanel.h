#pragma once
#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlWindow.h"

//Model
#include "model/Input.h"
#include "model/Beats.h"

#include "view/controlpanel/FourierDisplay.cpp"
#include "view/controlpanel/BeatDisplay.cpp"

class ControlPanel {
private:
    Beats *mpBeats;
    Input *mpIn;

    vector<ControlWindow*> mControlWindows; // stores all renderable and updatable elements in the control panel.

    FourierDisplay mFourierDisplay; // FFT Display TODO: Add the ability to move the beat analysers and change the radius.
    BeatDisplay mKickDisplay;   //Beat display shows amplitude and velocity as well as a boolean where there is currently a beat.
public:
    void setup(Beats *pBeat, Input *pIn);
    void update();
    void draw();

    void addControlElement(ControlWindow* window, std::string name, ofVec2f translate);
};

