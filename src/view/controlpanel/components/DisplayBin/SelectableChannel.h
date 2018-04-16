#pragma once

#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"

class SelectableChannel : public ofxMSAInteractiveObject{
    public:

        int mChannelId;
        std::string mChannelName;
        float mOffset = 0;

        void setup(int id, std::string name){
            mChannelId = id;
            mChannelName = name;
        }
        void update(){

        }
        void draw(){
            if(isMouseOver()){
                ofSetColor(25);
            } else {
                ofSetColor(75);
            }
            ofDrawRectangle(x, y+mOffset, width, height);

            ofSetColor(200);
            ofDrawBitmapString(mChannelName, x+2, y+mOffset+2);
        }
};