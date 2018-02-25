#pragma once

#include "ofMain.h"
#include "view/controlpanel/ControlWindow.h"
#include "model/Beats.h"

using namespace psiBeat;

class BeatDisplay : public ControlWindow {
    private:
        int mBeatState; // 0 = no beat, 1 = beat, 2 = cooldown
        int mBeatIndex = 0;
    public:
        BeatDisplay(){
            mWindowState.dimensions = ofVec2f(80, 50);
        }

        void setup(){

        }

        void setBeatIndex(int index){
            mBeatIndex = index;
        }

        void update(){
            ofLog(OF_LOG_NOTICE) << "BeatDisplay::update() - beats[" << mBeatIndex << "].amp = " << beats[mBeatIndex].amp() << " ,  " << "beats[" << mBeatIndex << "].vel = " << beats[mBeatIndex].vel();
        }

        void draw(){
            if(mBeatState == 0){
                ofSetColor(45, 45, 55);
            } else if (mBeatState == 1){
                ofSetColor(45, 255, 55);
            } else {
                ofSetColor(150, 45, 55);
            }
            ofDrawCircle(getTranslate() + 25, 10);

            ofSetColor(150, 45, 55);
            ofDrawRectangle(getTranslate().x + getDimensions().x, getTranslate().y + getDimensions().y, -20, beats[mBeatIndex].vel()* -getDimensions().y);
        }
};

