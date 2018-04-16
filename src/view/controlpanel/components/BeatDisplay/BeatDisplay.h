#pragma once

#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlWindow.h"
#include "model/Beats.h"
#include "./VelocitySlider.h"
#include "./AmplitudeSlider.h"

#define graphWidth 40
#define velocityHandleRadius 5

class BeatDisplay : public ControlWindow {
    private:

        VelocitySlider mVelocitySlider;
        AmplitudeSlider mAmplitudeSlider;

        int mBeatState; // 0 = no beat, 1 = beat, 2 = cooldown
        int mBeatIndex = 0;
        int mHistorySize;
        float vel, amp;
        float mTriggerVel, mTriggerAmp;
    public:
        void setup();
        void setBeatIndex(int index);
        void update();
        void draw();
        void drawDebug();

        void onRollover(int x, int y);
        void onRollout();

        void updateSubComponentPositions();
};

