#pragma once
#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlWindow.h"

class FourierDisplay : public ControlWindow {
private:
    ofMesh mFftMesh;
    float mXSpacing = -1;
    
public:
    void setup(){
        ofLog(OF_LOG_NOTICE) << "FourierDisplay::setup() ("<<ofGetElapsedTimef()<<")";
        ofLog(OF_LOG_NOTICE) << "FourierDisplay::setup() width=="<<width<<", in->bufferSize=="<<in->bufferSize<<", (width / in->bufferSize)"<< (width/in->bufferSize);        
        mXSpacing = width / in->bufferSize;

        setupWindow();
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
        drawWindow();

        ofSetColor(255,0,0);
        for(vector<float>::size_type i = 0; i < in->fourier.size(); i++){
            ofDrawRectangle(x + i*mXSpacing, y + height, 1, in->fourier[i]*-height);
        }
    }
};

