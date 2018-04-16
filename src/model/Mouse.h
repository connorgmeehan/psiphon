#pragma once

#include "view/controlpanel/dragables/Dragable.h"

#include <string>

enum DragType{
    DRAG_EMPTY,
    DRAG_WINDOW,
    DRAG_BEAT_AMPLITUDE_SLIDER,
    DRAG_BEAT_VELOCITY_SLIDER,
    DRAG_FOURIER_BEAT,
    // WE set the mouse drag type to 'predrag' 
    // which means the mouse hasn't moved enough to constitute a full drag
    // (if mouse doesn't move the channel is selected)
    DRAG_CHANNELBIN_PREDRAG_CHANNEL,
    DRAG_CHANNELBIN_PREDRAG_FOLDER,

    DRAG_CHANNELBIN_CHANNEL,
    DRAG_CHANNELBIN_FOLDER
};

class Mouse {
    public:
        Dragable mDragable;
        DragType mDragType = DRAG_EMPTY;
        std::string mName;
        int mValue;
        ofVec2f mOffset;
        bool mbActive;
        
    void reset(){
        mbActive = false;
    }

    void set(DragType dragType, std::string name, int value, ofVec2f offset){
        mDragType = dragType;
        mName = name;
        mValue = value;
        mOffset = offset;
        mbActive = true;

        mDragable.set(mDragType, mName, mValue, offset);
    }

    void update(int mx, int my){
        mDragable.updatePosition(mx, my);
    }

    void draw(){

    }

    DragType getDragType(){
        return mDragType;
    }

    std::string getName(){
        return mName;
    }

    int getValue(){
        return mValue;
    }

    ofVec2f getOffset(){
        return mOffset;
    }
    bool isActive(){
        return mbActive;
    }
};