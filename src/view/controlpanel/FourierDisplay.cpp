#pragma once
#include "ofMain.h"
#include "view/controlpanel/ControlWindow.h"
#include "model/Input.h"

using namespace psiInput;

class FourierDisplay : public ControlWindow {
private:
    ofMesh mFftMesh;
    float mXSpacing = -1;
    
public:
    void setup(){
        mWindowState.dimensions = ofVec2f(512, 256);
        mXSpacing = mWindowState.dimensions.x/bufferSize;
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
        for(vector<float>::size_type i = 0; i < fourier.size(); i++){
            ofDrawRectangle(getTranslate().x + i*mXSpacing, getTranslate().y + getDimensions().y, 1, fourier[i]*-getDimensions().y);
        }
    }
};

