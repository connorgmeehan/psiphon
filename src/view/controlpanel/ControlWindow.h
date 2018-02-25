#pragma once

#include "ofMain.h"
#include "config/ControlWindowConfig.h"

class ControlWindow{
protected:
    struct{
        std::string name;
        ofVec2f translate;
        ofVec2f dimensions;
    } mWindowState;
    std::string mName;
    ofVec2f mTranslate;
public:
    void pre_setup(std::string name, ofVec2f translate){
        mWindowState.name = name;
        mWindowState.translate = translate;
        this->setup();
    }
    virtual void setup(){};

    virtual void pre_update(){
        this->update();
    };
    virtual void update(){};
    
    void pre_draw(){
        //Draw Window Background
        ofSetColor(controlWindowConfig.windowColour);
        ofDrawRectangle(mWindowState.translate.x, mWindowState.translate.y, mWindowState.dimensions.x, mWindowState.dimensions.y);
        
        //Draw Window Border
        ofSetColor(controlWindowConfig.borderColour);
        ofDrawRectangle(mWindowState.translate.x, mWindowState.translate.y, mWindowState.dimensions.x, -controlWindowConfig.topBorderHeight);
        ofSetColor(controlWindowConfig.borderTextColour);
        ofDrawBitmapString(mName, mWindowState.translate.x, mWindowState.translate.y);
        this->draw();
    }
    virtual void draw(){};

    //getters and setters
    ofVec2f getTranslate(){ return mWindowState.translate; }
    void setTranslate(ofVec2f other){ mWindowState.translate = other; }

    ofVec2f getDimensions(){ return mWindowState.dimensions; }
    void setDimensions(ofVec2f other){ mWindowState.dimensions = other; }


};

