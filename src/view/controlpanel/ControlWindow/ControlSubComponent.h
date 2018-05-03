#pragma once

#include "ofMain.h"

#include "ofxMSAInteractiveObject.h"

#include "model/All.h"

class ControlSubComponent : public ofxMSAInteractiveObject {
public: 

    static Mouse* mouse;
    static Channels* channels;
    static Input* input;
    static Beats* beats;

    bool mDrawDebug = false;
    ofRectangle mBounds;

    static ofTrueTypeFont textFont;

    virtual void drawDebug() ;

    void setBounds(ofRectangle toSet);
    void setBounds(int x, int y, int width, int height);

    void reinsertInHorizontalBoundaries();
    void reinsertInVerticalBoundaries();

    void onKeyPress(int key);
};