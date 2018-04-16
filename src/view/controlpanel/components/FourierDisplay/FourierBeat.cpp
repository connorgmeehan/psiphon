#pragma once

#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlSubComponent.h"
#include "model/Beats.h"
#include "model/Mouse.h"

class FourierBeat : public ControlSubComponent{
    public:

        Beats* mpBeats;
        Mouse* mpMouse;

        int mId;
        int mBeatIndex;
        int mRadius;
        std::string mName;

        bool mClickedOn = false;
        bool mUpdateFlag = false;

        ofTrueTypeFont nameFont;

        void setup(Beats* pBeats, Mouse* pMouse, int id, int beatIndex, std::string name){
            mpBeats = pBeats;
            mpMouse = pMouse;
            mId = id;
            mBeatIndex = beatIndex;
            mName = name;
            mRadius = width/2;
            nameFont.load("HelveticaNeueCyr-Light.otf", 9, true, false);
        }

        void update(){
        }

        void draw(){
            drawDebug();
            if(isMouseOver()){
                ofSetColor(100, 200, 100, 200);
            } else {
                ofSetColor(100, 150, 100, 150);
            }
            ofDrawRectangle(x,y+height, width, height*-mpBeats->at(mBeatIndex)->amp);

            if(isMouseOver()){
                ofSetColor(220);
            } else {
                ofSetColor(200);
            }
            ofDrawLine(x,y+height*0.2,x,y+height);
            ofDrawLine(x+width,y+height*0.2,x+width,y+height);
            ofDrawLine(x+width/2,y+height*0.2,x+width/2,y+height);
            ofDrawRectangle(x,y+height*0.2,width,12);
            ofSetColor(25);
            nameFont.drawString(mName, x+2, y+10+height*0.2);
        }

        void onPress(int x, int y, int button){
            if(button == OF_MOUSE_BUTTON_1){
                if(!mpMouse->isActive()){
                    mpMouse->set(DRAG_FOURIER_BEAT, ofToString("Fourier.FourierBeat"), mBeatIndex, ofVec2f(x - this->x, y-this->y));
                    mClickedOn = true;
                }
            }
        }

        void onRelease(int x, int y, int button){
            if(button = OF_MOUSE_BUTTON_1){
                mClickedOn = false;
            }
        }

        void mouseDragged(int x, int y, int button){
            if(button == OF_MOUSE_BUTTON_1){
                if(mpMouse->isActive() && mpMouse->getDragType()==DRAG_FOURIER_BEAT && mpMouse->getValue() == mBeatIndex){
                    setX(x-mpMouse->getOffset().x);
                    reinsertInHorizontalBoundaries();
                    mUpdateFlag = true;
                }
            }
        }
};