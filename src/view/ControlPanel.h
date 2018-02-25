#pragma once
#include "ofMain.h"
#include "view/controlpanel/ControlWindow.h"

#include "view/controlpanel/FourierDisplay.cpp"
#include "view/controlpanel/BeatDisplay.cpp"

class ControlPanel {
private:
    vector<ControlWindow*> mControlWindows;

    FourierDisplay mFourierDisplay;
    BeatDisplay mKickDisplay;
public:
    void setup();
    void update();
    void draw();
};

