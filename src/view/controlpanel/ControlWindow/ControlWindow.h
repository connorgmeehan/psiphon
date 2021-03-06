
#define CW_BACKGROUND ofColor(25, 25, 25)
#define CW_BORDER ofColor(35, 35, 35)
#define CW_TEXT_COLOUR ofColor(220, 220, 220)

#define CW_HOVER_BACKGROUND ofColor(35, 35, 35)
#define CW_HOVER_BORDER ofColor(45)


#pragma once

#include "ofMain.h"

#include "ofxMSAInteractiveObject.h"

#include "model/Beats.h"
#include "model/Input.h"
#include "model/Mouse.h"
#include "model/Channels.h"


class ControlWindow : public ofxMSAInteractiveObject{
private:
    ofxMSAInteractiveObject mWindowBar;
    bool mShowDebug = false;

protected:

    bool mUseWindow = true;

    static Input* in;
    static Beats* beats;
    static Mouse* mouse;
    static Channels* channels;

    static ofTrueTypeFont nameFont;

    std::string mName;


    void drawWindow();
    void setupWindow();

public:
    int mId = -1;

    virtual void setup(){};

    virtual void update(){};
    
    virtual void draw(){};

    static void setPointers(Beats* _beats, Input* _input, Mouse* _mouse, Channels* _channels);
    
    void setName(std::string name);
    void setId(int id);

    virtual void drawDebug();

    void onKeyPress(int key);
    void onPress(int x, int y, int button);
    void mouseDragged(int x, int y, int button);

    virtual void updateSubComponentPositions(ofVec2f translate){};

};
