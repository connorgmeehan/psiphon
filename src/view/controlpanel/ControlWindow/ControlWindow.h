#pragma once

#include "ofMain.h"

#include "model/Beats.h"
#include "model/Input.h"

class ControlWindow{
protected:

    Input* in = nullptr;
    Beats* beats = nullptr;

    struct{
        std::string name;
        ofVec2f translate;
        ofVec2f dimensions;
    } mWindowState;
    std::string mName;
    ofVec2f mTranslate;

    static ofTrueTypeFont nameFont;

public:

    void pre_setup(std::string name, ofVec2f translate);
    virtual void setup(){};

    void pre_update();
    virtual void update(){};
    
    void pre_draw();
    virtual void draw(){};

    //getters and setters
    ofVec2f getTranslate();
    void setTranslate(ofVec2f other);

    ofVec2f getDimensions();
    void setDimensions(ofVec2f other);
    void setBeatPointer(Beats* _beats);
    void setInputPointer(Input* _input);

};
