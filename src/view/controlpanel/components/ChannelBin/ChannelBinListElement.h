#pragma once

#include "ofMain.h"

#include "model/Mouse.h"
#include "view/controlpanel/ControlWindow/ControlSubComponent.h"

enum ListElementType{
    CHANNEL_BIN_ROOT,
    CHANNEL_BIN_FOLDER,
    CHANNEL_BIN_CHANNEL
};

class ChannelBinListElement : public ControlSubComponent {
    public:
        static Mouse* mpMouse;
        ListElementType mListElementType;
        std::string mName;
        int mChannelId = -1;
        int mListId = -1;
        bool mbClicked = false;

        void setupElement(Mouse* pMouse, ListElementType listElementType, std::string name, int channelId, int listId){
            mpMouse = pMouse;
            mListElementType = listElementType;
            mName = name;
            mChannelId = channelId;
            mListId = listId;
        }
        void update(){}
        void draw(){

            ofFill();

            if(mbClicked){
                ofSetColor(100);
            } else {
                if(isMouseOver()){
                    ofSetColor(75);
                }else{
                    if(mListId%2 == 0){
                        ofSetColor(40);
                    } else {
                        ofSetColor(50);
                    }
                }
            }


            ofDrawRectangle(x,y,width,height);

            ofSetColor(200);

            if(mListElementType == CHANNEL_BIN_FOLDER){
                textFont.drawString("[F]",x+3,y+12);
            }

            textFont.drawString(mName, x+15,y+12);
        }

        void onPress(int x, int y, int button){
            mbClicked = true;
            if(button == OF_MOUSE_BUTTON_1 && !mpMouse->isActive()){
                if(mListElementType == CHANNEL_BIN_CHANNEL){
                    mpMouse->set(DRAG_CHANNELBIN_PREDRAG_CHANNEL, mName, mChannelId, ofVec2f(x-this->x,y-this->x));
                } else if(mListElementType) {
                    mpMouse->set(DRAG_CHANNELBIN_PREDRAG_FOLDER, mName, mChannelId, ofVec2f(x-this->x,y-this->y));
                }
            }
        }

        void onRelease(int x, int y, int button){
            mbClicked = false;

            if(mListElementType == CHANNEL_BIN_CHANNEL){
                if(button == OF_MOUSE_BUTTON_1 && mpMouse->getDragType() == DRAG_CHANNELBIN_PREDRAG_CHANNEL){
                    mbClicked = true;
                }
            } else if(mListElementType == CHANNEL_BIN_FOLDER) {

                if(button == OF_MOUSE_BUTTON_1 && mpMouse->getDragType() == DRAG_CHANNELBIN_PREDRAG_FOLDER){
                    mbClicked = true;
                }  
            }
        }
};