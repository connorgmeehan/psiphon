#pragma once

#include "ofMain.h"

#include "view/controlpanel/ControlWindow/ControlSubComponent.h"

#include "model/Mouse.h"

class ChannelSelectorBehaviourControlsTimer : public ControlSubComponent{
    public:
        Mouse* mpMouse;

        int mElementHeight = 16;
        bool mbExpanded = false;
        int mHoverId = INT_MAX;
        
        int mCurrentTimer = 1;
        int mTotalTimer = 4;

        int mMaxValue = 16;

        void setup(Mouse* pMouse){
            mpMouse = pMouse;
        }

        void update(){

        }

        void draw(){
            ofFill();
            ofSetColor(220);
            ofDrawRectangle(x,y,width,height);

            ofSetColor(20);

            textFont.drawString(ofToString(mCurrentTimer)+"/"+ofToString(mTotalTimer), 3+x, y+height-4);

            if(mbExpanded){
                for(unsigned int i = 0; i < mMaxValue; i++){
                    textFont.drawString("/"+ofToString(i+1), x+3, y+12 + mElementHeight*i);
                }
            }
        
        }

        void onRollout(int x, int y){
            mHoverId = INT_MAX;

            if(mbExpanded){
                close();
            }

        }

        void onPress(int x, int y, int button){
            if(!mpMouse->isActive()){
                mpMouse->set(DRAG_DISPLAYBIN_TIMER, "timer", -1, ofVec2f(x,y));
                if(!mbExpanded){
                    expand();
                }
            }
        }
        
        void mouseDragged(int x, int y, int button){
            mHoverId = (int) (y-this->y)/mElementHeight;
        }

        void mouseReleased(int x, int y, int button){
            if(mpMouse->getDragType() == DRAG_DISPLAYBIN_TIMER){
                if(mHoverId >= 0 && mHoverId < mMaxValue){
                    mTotalTimer = mHoverId+1;
                }

                close();
            }
        }

        void iterateTimer(){
            mCurrentTimer = (mCurrentTimer+1)%mTotalTimer;
        }

        bool isLoop(){
            return (mCurrentTimer == 0);
        }

        void expand(){
            mbExpanded = true;
            setHeight(mElementHeight + mMaxValue * mElementHeight);
            setY(this->y-height+mElementHeight);
        }

        void close(){
            mbExpanded = false;
            setY(this->y+height-mElementHeight);
            setHeight(mElementHeight);
        }
};