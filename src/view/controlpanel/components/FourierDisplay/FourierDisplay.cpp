#include "./FourierDisplay.h"

void FourierDisplay::setup(){
    ofLog(OF_LOG_NOTICE) << "FourierDisplay::setup() ("<<ofGetElapsedTimef()<<")";
    ofLog(OF_LOG_NOTICE) << "FourierDisplay::setup() width=="<<width<<", in->bufferSize=="<<in->bufferSize<<", (width / in->bufferSize)"<< (width/in->bufferSize);        
    mXSpacing = width / in->bufferSize;

    setupWindow();

    mFourierBeats.resize(beats->getBeatSize());

    for(int i = 0; i < beats->getBeatSize(); i++){
        FourierBeat temp;
        mFourierBeats.push_back(temp);
        mFourierBeats[i].enableMouseEvents();
        mFourierBeats[i].enableAppEvents();
        mFourierBeats[i].setPosition(x + beats->at(i)->getPosition(), y);
        mFourierBeats[i].setSize(beats->at(i)->getRadius()*2,height);
        mFourierBeats[i].setBounds(x,y,width,height);
        mFourierBeats[i].setup(beats, mouse, mId, i, beats->at(i)->getName());
    }
}

void FourierDisplay::update(){
    for(vector<FourierBeat>::size_type i = 0; i < mFourierBeats.size(); i++){
        if(mFourierBeats[i].mUpdateFlag){
            beats->at(i)->setPosition( mFourierBeats[i].getX()+mFourierBeats[i].getWidth()/2 - x );
        }
    }
}

void FourierDisplay::draw(){
    drawWindow();

    ofSetColor(255,0,0);
    for(vector<float>::size_type i = 0; i < in->fourier.size(); i++){
        ofDrawRectangle(x + i*mXSpacing, y + height, 1, in->fourier[i]*-height);
    }
}