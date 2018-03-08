#pragma once

#pragma once

#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlWindow.h"
#include "model/Beats.h"

class DebugDisplay : public ControlWindow{
    private:
        bool mButton0 = false;
        bool mButton1 = false;
        bool mButton2 = false;

        ofVec2f lastMouse;

    public:
        void setup(){
            ofLog(OF_LOG_NOTICE) << "DebugDisplay::setup() ("<<ofGetElapsedTimef()<<")";
            setupWindow();
        }

        void draw(){
            drawWindow();
            nameFont.drawString("fps: " + ofToString(ofGetFrameRate(),2) ,x+2, y+12);
            nameFont.drawString("framenum: " + ofToString(ofGetFrameNum(),2) ,x+2, y+24);
            nameFont.drawString("timealive: " + ofToString(ofGetLastFrameTime(),2) ,x+2, y+36);
            nameFont.drawString("mouse: (" + ofToString(mButton0)+","+ofToString(mButton1)+","+ofToString(mButton2)+")" ,x+2, y+48);
            nameFont.drawString("mousepos: ("+ofToString(lastMouse) ,x+2, y+60);
        }

        void mousePressed(int x, int y, int button){
            if(button == 0){
                mButton0 = true;
            }
            if(button == 1){
                mButton1 = true;
            }
            if(button == 2){
                mButton2 = true;
            }
            lastMouse = ofVec2f(x,y);
        }

        void mouseReleased(int x, int y, int button){
            if(button == 0){
                mButton0 = false;
            }
            if(button == 1){
                mButton1 = false;
            }
            if(button == 2){
                mButton2 = false;
            }
            lastMouse = ofVec2f(x,y);
        }
};