#pragma once

#include "ofMain.h"

#include "../ChannelPrimitive.h"

class Grid : public ChannelPrimitive {

    std::string getName(){ return "GRID"; }
    std::string getFolderName(){ return "BRUT"; }

    ofVec3f colour;

    void setup(){
        colour = ofPoint(100, 255, 255);
    }

    void update(){
        ofLog(OF_LOG_VERBOSE) << "Grid::update() - colour(x,y,z) = ("<<colour.x<<","<<colour.y<<","<<colour.z<<")";
        colour = colour - ofVec3f(1,1,1);
    }

    void draw(){
        ofSetColor(colour.x, colour.y, colour.z);
        for(int i = -20; i < 20; i++){
            for(int j = -20; j < 20; j++){
                ofDrawRectangle(i*40, ofGetHeight() - j*40*fft[i], 20,20);
            }
        }
    }

    void onKick(float & amp){
        ofLog(OF_LOG_VERBOSE) << "Grid::onKick() - changing color"  << ofRandom(255);
        colour = ofPoint( ofRandom(255*amp), ofRandom(255*amp), ofRandom(255*amp) );
        ofLog(OF_LOG_VERBOSE) << "colour(x,y,z) = ("<<colour.x<<","<<colour.y<<","<<colour.z<<")";
    }
};