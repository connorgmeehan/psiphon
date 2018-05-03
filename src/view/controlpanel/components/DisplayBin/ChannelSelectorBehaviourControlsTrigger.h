#pragma once

#include "ofMain.h"

#include "view/controlpanel/ControlWindow/ControlSubComponent.h"

#include "model/Beats.h"
#include "model/Mouse.h"

class ChannelSelectorBehaviourControlsTrigger : public ControlSubComponent{
    public:
        Mouse* mpMouse;
        Beats* mpBeats;

        int mElementHeight = 16;
        int mCurrentTrigger = -1;
        int mHoverId = -1;
        bool mbExpanded = false;

        std::vector<std::string> mBeatNames;


        void setup(Mouse* pMouse, Beats* pBeats){
            mpMouse = pMouse;
            mpBeats = pBeats;
            ofLog() << "mTrigger::setup()";
            for(unsigned int i = 0; i < mpBeats->getBeatSize(); i++){
                mBeatNames.push_back( mpBeats->at(i)->getName());
                ofLog() << "mTrigger::setup() - " << mBeatNames[i];
            }
        }

        void update(){

        }

        void draw(){
            ofFill();
            ofSetColor(200);
            ofDrawRectangle(x,y,width,height);
            ofSetColor(20);
            if(mCurrentTrigger != -1){
                textFont.drawString(mBeatNames[mCurrentTrigger], x+3, y+12);
            }
            if(mbExpanded){
                for(unsigned int i = 0; i < mBeatNames.size(); i++){
                    ofSetColor( 200 + 10*(i%2));
                    if(i == mHoverId){
                        ofSetColor(240);
                    }

                    ofDrawRectangle(x,y+mElementHeight+i*mElementHeight,width, mElementHeight);

                    ofSetColor(20);

                    textFont.drawString(mBeatNames[i], x+3, y+mElementHeight+i*mElementHeight+12);
                }
            }
        }

        void onMouseMove(int x, int y){
            mHoverId = (int) ((y-this->y)/mElementHeight)-1;
        }

        void onRollout(int x, int y){
            mHoverId = INT_MAX;
        }

        void onRelease(int x, int y, int button){
            if(!mpMouse->isActive()){
                mpMouse->setActive();
                if(mbExpanded){
                    if(mHoverId >= 0 && mHoverId < mBeatNames.size()){
                        mCurrentTrigger = mHoverId;
                    }
                    setHeight(mElementHeight);
                } else {
                    setHeight(mElementHeight+mElementHeight*mBeatNames.size());
                }
                mbExpanded = !mbExpanded;
            }
        }

        int getSelectedBeatId(){
            return mCurrentTrigger;
        }

        bool getBeatState(){
            return (mpBeats->at(mCurrentTrigger)->getState() == 1);
        }
};