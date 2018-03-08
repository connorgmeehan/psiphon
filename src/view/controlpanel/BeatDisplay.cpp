#pragma once

#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlWindow.h"
#include "model/Beats.h"

#define graphWidth 40

class BeatDisplay : public ControlWindow {
    private:
        int mBeatState; // 0 = no beat, 1 = beat, 2 = cooldown
        int mBeatIndex = 0;
        int mHistorySize;
        float vel, amp;
    public:
        void setup(){
            ofLog(OF_LOG_NOTICE) << "BeatDisplay::setup() ("<<ofGetElapsedTimef()<<")";
            mHistorySize = beats->at(mBeatIndex)->getHistorySize();
        }

        void setBeatIndex(int index){
            mBeatIndex = index;
            mHistorySize = beats->at(mBeatIndex)->getHistorySize();
        }

        void update(){
            mBeatState = beats->at(mBeatIndex)->getState();
            vel = beats->at(mBeatIndex)->vel;
            amp = beats->at(mBeatIndex)->amp;
        }

        void draw(){

            drawWindow();

            ofSetColor(255);
            if(mBeatState == 0){
                ofSetColor(45, 45, 55);
            } else if (mBeatState == 1){
                ofSetColor(45, 255, 55);
            } else {
                ofSetColor(150, 45, 55);
            }
            ofDrawCircle(x + 5, y+5, 3);

            //Draw beat history graph
            ofSetColor(150, 45, 55);
            for(int i = 0; i < mHistorySize; i++){
                ofDrawRectangle(x + width - graphWidth +  i*( graphWidth /mHistorySize), y + height,
                graphWidth/mHistorySize, (*beats)[mBeatIndex]->getHistoryValue(i) * -height);
            }
            ofSetColor(200);
            nameFont.drawString(ofToString(vel, 2), x + 5, y + height - 18 );
            nameFont.drawString(ofToString(amp, 2), x + 5, y + height - 5);

            ofDrawLine(x + width-graphWidth, y + height/2 - vel*height/2, x+width,  y + height/2 + vel*height/2);
        }
};

