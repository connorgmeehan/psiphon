#pragma once

#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlWindow.h"
#include "model/Beats.h"
#include "./VelocitySlider.h"
#include "./ScaleSlider.h"

#define graphWidth 40
#define velocityHandleRadius 5

class BeatDisplay : public ControlWindow {
    private:

        VelocitySlider mVelocitySlider;
        ScaleSlider mScaleSlider;

        int mBeatState; // 0 = no beat, 1 = beat, 2 = cooldown
        int mBeatIndex = 0;
        int mHistorySize;
        float vel, amp;
        float mTriggerVel = 0.15f;
        float mScale = 1.0f;
    public:
        void setup();
        void setBeatIndex(int index);
        void update();
        void draw();
        void drawDebug();

        void onRollover(int x, int y);
        void onRollout();

        void updateSubComponentPositions(ofVec2f translate);
};

