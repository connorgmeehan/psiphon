#pragma once

#include "ofMain.h"

#include "../Channel.h"

class Grid : public Channel {
    void draw(){
        ofSetColor(255,0,0);
        for(int i = -20; i < 20; i++){
            for(int j = -20; j < 20; j++){
                ofDrawRectangle(i*40, j*40, 20,20);
            }
        }
    }
};