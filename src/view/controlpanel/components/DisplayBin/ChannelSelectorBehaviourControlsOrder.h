#pragma once

#include "ofMain.h"

#include "view/controlpanel/ControlWindow/ControlSubComponent.h"

#include "model/Channels.h"
#include "model/Mouse.h"

class ChannelSelectorBehaviourControlsOrder : public ControlSubComponent{
    public:
        Mouse* mpMouse;
        Channels* mpChannels;

        AutoPlayBehaviour mBehaviour;
        int mHoverId = INT_MAX;
        int mElementWidth = -1;

        void setup(Mouse* pMouse, Channels* pChannels){
            mpMouse = pMouse;
            mpChannels = pChannels;
            mBehaviour = AUTO_NONE;
            mElementWidth = width/3;
        }

        void update(){

        }

        void draw(){
            ofFill();
            ofSetColor(25);
            ofDrawRectangle(x,y,width,height);

            ofSetColor(40);
            ofDrawRectangle(x+mHoverId*mElementWidth,y,mElementWidth,height);

            ofSetColor(70,100,20);
            ofDrawRectangle(x+mBehaviour*mElementWidth,y,mElementWidth,height);
            ofSetColor(200);

            textFont.drawString("n", 3+x, y+12);
            textFont.drawString("s", 3+x+mElementWidth, y+12);
            textFont.drawString("c", 3+x+mElementWidth*2, y+12);
        }

        void onMouseMove(int x, int y){
            mHoverId = (int) (x-this->x)/mElementWidth;
        }

        void onRollout(int x, int y){
            mHoverId = INT_MAX;
        }

        void onPress(int x, int y, int button){
            ofLog() << "ChannelBehaviourButtons::onPress(x:"<<x<<", y:"<<y<<")";
            if(!mpMouse->isActive()){
                mBehaviour = static_cast<AutoPlayBehaviour>(mHoverId);
                ofLog() << "ChannelBehaviourButtoxns::onPress(x:"<<x<<", y:"<<y<<") - mBehaviour:"<<mBehaviour<<" - mHoverId:"<<mHoverId;
            }
        }

        AutoPlayBehaviour getBehaviour(){
            return mBehaviour;
        }
};