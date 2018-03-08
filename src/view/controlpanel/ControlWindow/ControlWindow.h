#pragma once

#include "ofMain.h"

#include "ofxMSAInteractiveObject.h"

#include "model/Beats.h"
#include "model/Input.h"

class ControlWindow : public ofxMSAInteractiveObject{
protected:

    bool useWindow = true;
    Input* in = nullptr;
    Beats* beats = nullptr;

    std::string mName;

    static ofTrueTypeFont nameFont;

    void drawWindow();

public:

    virtual void setup(){};

    virtual void update(){};
    
    virtual void draw(){};


    void setBeatPointer(Beats* _beats);
    void setInputPointer(Input* _input);
    void setName(std::string name);

    void setUseWindow(bool _useWindow);



};
