#pragma once

#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlSubComponent.h"

#include "model/Mouse.h"

class VelocitySlider : public ControlSubComponent {
    public:
        Mouse* mpMouse;
        int mId;
        bool mUpdateFlag = false;
        bool mClickedOn = false;

        void setup(Mouse* pMouse ,int id){
            mId = id;
            mpMouse = pMouse;
        }

        void draw(){
            if(!isMouseOver()){
                ofSetColor(150, 150, 150, 150);
            } else {
                if(mClickedOn){
                    ofSetColor(225, 200, 200, 200);
                } else {
                    ofSetColor(200,200,200,200);
                }
            }
            ofDrawRectangle(x,y,width,height);
        }

        void onPress(int x, int y, int button){
            if(button == OF_MOUSE_BUTTON_1){
                if(!mpMouse->isActive()){
                    mpMouse->set(DRAG_BEAT_VELOCITY_SLIDER, ofToString("BeatDisplay.VelocitySlider"), mId, ofVec2f(x - this->x, y-this->y));
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
                if(mpMouse->getDragType()==DRAG_BEAT_VELOCITY_SLIDER && mpMouse->getValue() == mId){
                    setY(y-mpMouse->getOffset().y);
                    reinsertInVerticalBoundaries();
                    mUpdateFlag = true;
                }
            }
        }
};