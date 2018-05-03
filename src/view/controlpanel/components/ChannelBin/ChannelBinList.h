#pragma once

#include "ofMain.h"

#include "model/Mouse.h"
#include "model/Channels.h"
#include "view/controlpanel/ControlWindow/ControlSubComponent.h"

enum ListElementType{
    CHANNEL_BIN_ROOT,
    CHANNEL_BIN_FOLDER,
    CHANNEL_BIN_CHANNEL
};

struct ChannelStruct{
    std::string mChannelName;
    int mChannelId;
    ChannelStruct(std::string channelName, int channelId){
        mChannelName = channelName;
        mChannelId = channelId;
    }
};

struct FolderStruct{
    std::string mFolderName;
    int mFolderId;
    std::vector<ChannelStruct> mChannels;
    FolderStruct(int folderId, std::string folderName, std::vector<ChannelStruct> channels){
        mFolderName = folderName;
        mFolderId = folderId;
        mChannels = channels;
    }
};

struct ElementStruct{
    ListElementType mType;
    int mId;
    std::string mName;
    //TODO: Image?

    ElementStruct(ListElementType type, int id, std::string name){
        mType = type;
        mId = id;
        mName = name;
    }
};

class ChannelBinList : public ControlSubComponent {
    public:
        Mouse* mpMouse;
        Channels* mpChannels;

        std::vector<FolderStruct> mFolders;
        std::vector<ElementStruct> mElements;
        int mHoverId = -1;

        int mElementHeight = 16;
        int mCurrentOffset;

        int mCurrentFolder = -1; // -1 designates no folder, [0-*] designates the folder id
        void setup(Channels* channels, Mouse* mouse){
            mpChannels = channels;
            mpMouse = mouse;
        }
        void update(){}
        void draw(){

            ofFill();

            for(unsigned int i = 0; i < mElements.size(); i++){
                if(mHoverId == i){
                    ofSetColor(70);
                } else {
                    if(i%2==0){
                        ofSetColor(30);
                    } else {
                        ofSetColor(50);
                    }
                }

                ofDrawRectangle(x, y+i*mElementHeight, width, mElementHeight);
                
                ofSetColor(200);
                if(mElements[i].mType == CHANNEL_BIN_FOLDER){
                    textFont.drawString(ofToString("[f] ") + mElements[i].mName, x+3, y+i*mElementHeight+12);
                } else {
                    textFont.drawString(mElements[i].mName, x+12, y+i*mElementHeight+12);
                }
            }
        }
        
        void getChannelData(){
            for(unsigned int i = 0; i < mpChannels->mFolders.getSize(); i++){
                std::vector<ChannelStruct> tempChannels;
                for(unsigned int j = 0; j < mpChannels->getChannelSize(); j++){
                    if(i == mpChannels->getChannel(j).mFolderId){
                        tempChannels.push_back( ChannelStruct(mpChannels->getChannel(j).mName, mpChannels->getChannel(j).mId));
                    }
                }
                mFolders.push_back(FolderStruct(i, mpChannels->getFolderName(i), tempChannels));
            }
            populateList(-1, 0);

            for(unsigned int i = 0; i < mFolders.size(); i++){
                ofLog() << "FolderStruct["<<i<<"] - mName: " << mFolders[i].mFolderName;
            }
        }

        void populateList(int folder, int offset){
            mElements = std::vector<ElementStruct>{};
            if(folder == -1){
                for(unsigned int i = offset; i < mFolders.size(); i++){
                    if(i < 16){
                        mElements.push_back( ElementStruct(CHANNEL_BIN_FOLDER, mFolders[i].mFolderId, mFolders[i].mFolderName) );
                    }
                }
            } else {
                mElements.push_back( ElementStruct(CHANNEL_BIN_ROOT, -1, std::string("...") ) );
                for(unsigned int i = offset; i < mFolders[folder].mChannels.size(); i++){
                    if(i < 15){
                        mElements.push_back( ElementStruct(CHANNEL_BIN_CHANNEL, mFolders[folder].mChannels[i].mChannelId, mFolders[folder].mChannels[i].mChannelName) );
                    }
                }
            }
        }

        void onRollout(int x, int y){
            mHoverId = -1;
        }

        void onPress(int x, int y, int button){
            if(!mpMouse->isActive()){   // if mouse is free
                if((int) (y-this->y)/mElementHeight < mElements.size()){ // and element to press is in range
                    elementPressHandler( mElements[(int) (y-this->y)/mElementHeight] ); 
                }
            }
        }

        void onMouseMove(int x, int y){
            mHoverId = (y-getTop())/mElementHeight; // Change the mHoverId to change which list element is highlighted
        }

        void mouseDragged(int x, int y, int button){
            if(mpMouse->getDragType() == DRAG_CHANNELBIN_PREDRAG_CHANNEL){
                if( mpMouse->getOffset().distance(ofVec3f(getMouseX(), getMouseY())) > 5 ){
                    mpMouse->set(DRAG_CHANNELBIN_CHANNEL, mpMouse->getName(), mpMouse->getValue(), mpMouse->getOffset());
                }
            } else if(mpMouse->getDragType() == DRAG_CHANNELBIN_PREDRAG_FOLDER){
                if( mpMouse->getOffset().distance(ofVec3f(getMouseX(), getMouseY())) > 5 ){
                    mpMouse->set(DRAG_CHANNELBIN_FOLDER, mpMouse->getName(), mpMouse->getValue(), mpMouse->getOffset());
                }
            }
        }

        void onRelease(int x, int y, int button){
            if(mpMouse->getDragType() == DRAG_CHANNELBIN_PREDRAG_CHANNEL || mpMouse->getDragType() == DRAG_CHANNELBIN_PREDRAG_FOLDER || mpMouse->getDragType() == DRAG_CHANNELBIN_PREDRAG_ROOT){
                elementActivateHandler( mElements[(int) (y-this->y)/mElementHeight] );
            }
        }

        void elementPressHandler(ElementStruct & el){
            switch(el.mType){
                case CHANNEL_BIN_CHANNEL:   mpMouse->set( DRAG_CHANNELBIN_PREDRAG_CHANNEL, el.mName, el.mId, ofVec2f(x,y) );    break;
                case CHANNEL_BIN_FOLDER:    mpMouse->set( DRAG_CHANNELBIN_PREDRAG_FOLDER, el.mName, el.mId, ofVec2f(x,y) );     break;
                case CHANNEL_BIN_ROOT:      mpMouse->set( DRAG_CHANNELBIN_PREDRAG_ROOT, el.mName, el.mId, ofVec2f(x,y) );     break;
            }
        }

        void elementActivateHandler(ElementStruct & el){
            switch(el.mType){
                case CHANNEL_BIN_CHANNEL:                               break;
                case CHANNEL_BIN_FOLDER:    populateList(el.mId, 0);    break;
                case CHANNEL_BIN_ROOT:      populateList(-1, 0);        break;
            }
        }

};