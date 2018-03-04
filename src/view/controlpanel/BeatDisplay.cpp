#pragma once

#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlWindow.h"
#include "model/Beats.h"

class BeatDisplay : public ControlWindow {
    private:
        int mBeatState; // 0 = no beat, 1 = beat, 2 = cooldown
        int mBeatIndex = 0;
    public:
        void setup(){
            mWindowState.dimensions = ofVec2f(80, 50);
        }

        void setBeatIndex(int index){
            mBeatIndex = index;
        }

        void update(){
            mBeatState = beats->at(mBeatIndex)->getState();
        }

        void draw(){

            ofSetColor(255);
            nameFont.drawString(ofToString(beats->at(mBeatIndex)->amp), getTranslate().x + 5, getTranslate().y + getDimensions().y - 5);
            if(mBeatState == 0){
                ofSetColor(45, 45, 55);
            } else if (mBeatState == 1){
                ofSetColor(45, 255, 55);
            } else {
                ofSetColor(150, 45, 55);
            }
            ofDrawCircle(getTranslate() + 20, 10);

            ofSetColor(150, 45, 55);
            ofDrawRectangle( getTranslate().x + getDimensions().x-10, getTranslate().y + getDimensions().y/2, -10, beats->at(mBeatIndex)->vel * -getDimensions().y/2);
            ofDrawRectangle(getTranslate().x + getDimensions().x, getTranslate().y + getDimensions().y, -10, beats->at(mBeatIndex)->amp * -getDimensions().y);
        }
};

