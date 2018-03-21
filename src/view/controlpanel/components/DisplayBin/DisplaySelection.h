#pragma once

#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"
#include "model/Mouse.h"

class DisplaySelection : public ofxMSAInteractiveObject {
    private:
        int mSelectionId = -1;
        int mChannelId = -1;
        std::string mName = "";
    public:
        void setup(int channelId, int selectionId, std::string name){
            mSelectionId = selectionId;
            mChannelId =channelId;
            mName = name;
        }

        void update(){

        }
        
        void draw(){
        }

};
