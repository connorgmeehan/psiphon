#pragma once

#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlWindow.h"
#include "model/Beats.h"

class DebugDisplay : public ControlWindow{
    private:
        bool mButton0 = false;
        bool mButton1 = false;
        bool mButton2 = false;
        std::vector<std::string> mDragTypeString{
            "DRAG_EMPTY",
            "DRAG_WINDOW",
            "DRAG_BEAT_AMPLITUDE_SLIDER",
            "DRAG_BEAT_VELOCITY_SLIDER",
            "DRAG_FOURIER_BEAT",
            // WE set the mouse drag type to 'predrag' 
            // which means the mouse hasn't moved enough to constitute a full drag
            // (if mouse doesn't move the channel is selected)
            "DRAG_CHANNELBIN_PREDRAG_CHANNEL",
            "DRAG_CHANNELBIN_PREDRAG_FOLDER",
            "DRAG_CHANNELBIN_PREDRAG_ROOT",
            "DRAG_CHANNELBIN_CHANNEL",
            "DRAG_CHANNELBIN_FOLDER",
            "DRAG_DRAWBIN_TIMER"
        };
        ofVec2f lastMouse;

    public:
        void setup(){
            ofLog(OF_LOG_NOTICE) << "DebugDisplay::setup() ("<<ofGetElapsedTimef()<<")";
            setupWindow();

            ofLog(OF_LOG_VERBOSE) << "DebugDisplay::setPointers() - channels->getBufferSize() == " << channels->getBufferSize(); 
        }

        void draw(){
            std::string displayBufferString;
            for(unsigned int i = 0 ; i < channels->mDisplayBuffer.size(); i++){
                displayBufferString+= ofToString(channels->mDisplayBuffer[i]) + ",";
            }

            drawWindow();
            nameFont.drawString("fps: " + ofToString(ofGetFrameRate(),2) ,x+2, y+12);
            nameFont.drawString("framenum: " + ofToString(ofGetFrameNum(),2) ,x+2, y+24);
            nameFont.drawString("timealive: " + ofToString(ofGetElapsedTimeMillis(),2) ,x+2, y+36);
            nameFont.drawString("mouse: (" + ofToString(mButton0)+","+ofToString(mButton1)+","+ofToString(mButton2)+")" ,x+2, y+48);
            nameFont.drawString("mousepos: "+ofToString(lastMouse) ,x+2, y+60);
            nameFont.drawString("dragtype: "+mDragTypeString[mouse->getDragType()] ,x+2, y+72);
            nameFont.drawString("dragname: "+ofToString(mouse->getName()), x+2, y+84);
            nameFont.drawString("dragvalue: "+ofToString(mouse->getValue()), x+2, y+96);
            nameFont.drawString("displaybuffer: "+ofToString(mouse->getValue()) + displayBufferString, x+2, y+108);

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