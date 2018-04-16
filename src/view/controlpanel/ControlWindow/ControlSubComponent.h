#pragma once

#include "ofMain.h"

#include "ofxMSAInteractiveObject.h"

class ControlSubComponent : public ofxMSAInteractiveObject {
public:

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