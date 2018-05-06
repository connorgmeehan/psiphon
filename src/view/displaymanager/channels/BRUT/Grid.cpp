#pragma once

#include "ofMain.h"

#include "../ChannelPrimitive.h"

class Grid : public ChannelPrimitive {

    std::string getName(){ return "GRID"; }
    std::string getFolderName(){ return "BRUT"; }

    void draw(){
        ofSetColor(255,0,0);
        for(int i = -20; i < 20; i++){
            for(int j = -20; j < 20; j++){
                ofDrawRectangle(i*40, j*40, 20,20);
            }
        }
    }
};