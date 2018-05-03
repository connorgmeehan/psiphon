#pragma once

#include "ofMain.h"

#include "view/controlpanel/ControlWindow/ControlSubComponent.h"

#include "model/Channels.h"
#include "model/Mouse.h"
#include "model/Beats.h"

#include "./ChannelSelector.h"
#include "./ChannelSelectorBehaviourControlsOrder.h"
#include "./ChannelSelectorBehaviourControlsTrigger.h"
#include "./ChannelSelectorBehaviourControlsTimer.h"

class ChannelSelectorBehaviourControls : public ControlSubComponent {
    public:
        ChannelSelector* mpChannelSelector;
        Channels* mpChannels;
        Mouse* mpMouse;
        Beats* mpBeats;
        
        ChannelSelectorBehaviourControlsOrder* mOrder;
        ChannelSelectorBehaviourControlsTrigger* mTrigger;
        ChannelSelectorBehaviourControlsTimer* mTimer;

        int mBeatActivateCounter;

        void setup(ChannelSelector* pChannelSelector, Mouse* pMouse, Channels* pChannels, Beats* pBeats){
            mpChannelSelector = pChannelSelector;
            mpChannels = pChannels;
            mpMouse = pMouse;
            mpBeats = pBeats;

            mOrder = new ChannelSelectorBehaviourControlsOrder();

            mOrder->setPosition(x,y);
            mOrder->setSize(width*0.4, height);
            mOrder->setup(mpMouse, mpChannels);
            mOrder->enableAllEvents();
            
            mTrigger = new ChannelSelectorBehaviourControlsTrigger();
            mTrigger->setPosition(x+width*0.35,y);
            mTrigger->setSize(width*0.35, height);
            mTrigger->setup(mpMouse, mpBeats);
            mTrigger->enableAllEvents();

            mTimer = new ChannelSelectorBehaviourControlsTimer();
            mTimer->setPosition(x+width*0.75,y);
            mTimer->setSize(width*0.25, height);
            mTimer->setup(mpMouse);
            mTimer->enableAllEvents();

        }

        void update(){
            if(mTrigger->getBeatState()){

                mTimer->iterateTimer();

                if(mTimer->isLoop()){
                    mpChannelSelector->changeChannel(mOrder->getBehaviour());
                }
            }
        }

        void updateSubComponentPositions(ofVec2f translate){
            mOrder->translate(translate);
            mTrigger->translate(translate);
            mTimer->translate(translate);
        }
};