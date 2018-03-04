#pragma once
#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlWindow.h"

class FourierDisplay : public ControlWindow {
private:
    ofMesh mFftMesh;
    float mXSpacing = -1;
    
public:
    void setup(){
        mWindowState.dimensions = ofVec2f(512, 256);

        ofLog(OF_LOG_NOTICE) << "mWindowState.dimensions.x == " << mWindowState.dimensions.x;
        ofLog(OF_LOG_NOTICE) << "protected variable Input* in == nullptr?  " << (in == nullptr);
        mXSpacing = mWindowState.dimensions.x / in->bufferSize;
    }
    void update(){
        /*mFftMesh.addVertex(ofPoint(getTranslate().x, getTranslate().y + getDimensions().y));
        for(vector<float>::size_type i = 0; i < fourier.size(); i++){
            mFftMesh.addVertex(ofPoint(getTranslate().x + (getDimensions().x / bufferSize()) * i, getTranslate().y + getDimensions().y - In::fft(i) * getDimensions().y));
        }
        mFftMesh.addVertex(ofPoint(getTranslate().x + getDimensions().x, getTranslate().y + getDimensions().y));
        */
    }
    void draw(){
        ofSetColor(255,0,0);
        for(vector<float>::size_type i = 0; i < in->fourier.size(); i++){
            ofDrawRectangle(getTranslate().x + i*mXSpacing, getTranslate().y + getDimensions().y, 1, in->fourier[i]*-getDimensions().y);
        }
    }
};

