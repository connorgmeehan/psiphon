#pragma once

#include <string>

enum DragType{
    DRAG_EMPTY,
    DRAG_WINDOW
};

class Mouse {
    public:
        DragType mDragType = DRAG_EMPTY;
        std::string mName;
        int mValue;
        ofVec2f mOffset;

    void reset(){
        mDragType = DRAG_EMPTY;
        mName = std::string{"general_dragable"};
        mValue = -1;
    }

    void set(DragType dragType, std::string name, int value, ofVec2f offset){
        mDragType = dragType;
        mName = name;
        mValue = value;
        mOffset = offset;
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
};