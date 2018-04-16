#include "./BeatDisplay.h"

void BeatDisplay::setup(){
    ofLog(OF_LOG_NOTICE) << "BeatDisplay::setup() ("<<ofGetElapsedTimef()<<")";
    
    setupWindow();

    mHistorySize = beats->at(mBeatIndex)->getHistorySize();
    mTriggerAmp = beats->at(mBeatIndex)->getTriggerAmp();
    mTriggerVel = beats->at(mBeatIndex)->getTriggerVel();

    mVelocitySlider.enableMouseEvents();
    mVelocitySlider.enableAppEvents();
    mVelocitySlider.setSize(10,8);
    mVelocitySlider.setPosition(x+width-mVelocitySlider.width,y+height/2+mTriggerVel*height/2 - mVelocitySlider.height/2);
    mVelocitySlider.setBounds(x, y, width, height);
    mVelocitySlider.setup(mouse, mId);

    mAmplitudeSlider.enableMouseEvents();
    mAmplitudeSlider.enableAppEvents();
    mAmplitudeSlider.setSize(graphWidth/mHistorySize, 8);
    mAmplitudeSlider.setPosition(x + width - graphWidth, y + height - mTriggerAmp*height - mAmplitudeSlider.y/2);
    mAmplitudeSlider.setBounds(x, y, width, height);
    mAmplitudeSlider.setup(mouse, mId);
}

void BeatDisplay::setBeatIndex(int index){
    mBeatIndex = index;
    mHistorySize = beats->at(mBeatIndex)->getHistorySize();
}

void BeatDisplay::update(){
    mBeatState = beats->at(mBeatIndex)->getState();
    vel = beats->at(mBeatIndex)->vel;
    amp = beats->at(mBeatIndex)->amp;

    if(mVelocitySlider.mUpdateFlag = true){
        mVelocitySlider.mUpdateFlag = false;

        mTriggerVel = ((y + height/2) - mVelocitySlider.y-mVelocitySlider.height/2)/height;
        beats->at(mBeatIndex)->setTriggerVel(mTriggerVel);

    }

    if(mAmplitudeSlider.mUpdateFlag = true){
        mAmplitudeSlider.mUpdateFlag = false;

        mTriggerAmp = ((y + height) - mAmplitudeSlider.y-mAmplitudeSlider.height/2)/height;
        beats->at(mBeatIndex)->setTriggerAmp(mTriggerAmp);
    }


}

void BeatDisplay::draw(){
    drawWindow();

    ofSetColor(200);
    nameFont.drawString(ofToString(vel, 2), x + 5, y + height - 18 );
    nameFont.drawString(ofToString(amp, 2), x + 5, y + height - 5);

    if(mVelocitySlider.mClickedOn){
        nameFont.drawString(ofToString(mTriggerVel, 2), mVelocitySlider.x + mVelocitySlider.width, mVelocitySlider.y);
    }

    ofSetColor(255);
    if(mBeatState == 0){
        ofSetColor(45, 45, 55);
    } else if (mBeatState == 1){
        ofSetColor(45, 255, 55);
    } else {
        ofSetColor(150, 45, 55);
    }
    ofDrawCircle(x + 5, y+5, 3);

    //Draw beat history graph
    ofSetColor(150, 45, 55);
    for(int i = 0; i < mHistorySize; i++){
        ofDrawRectangle(x + width - graphWidth +  i*( graphWidth /mHistorySize), y + height,
        graphWidth/mHistorySize, (*beats)[mBeatIndex]->getHistoryValue(i) * -height);
    }
    if(amp > mTriggerAmp){
        ofSetColor(25,255,25);
    } else {
        ofSetColor(100);
    }

    ofDrawLine(x + width - graphWidth, y + height - mTriggerAmp*height, x + width - graphWidth + (mHistorySize/graphWidth), y + height - mTriggerAmp*height);

    // Draw Trigger Velocity Bar
    ofSetColor(25, 25, 200);
    ofDrawLine(x + width-graphWidth, y + height/2 + mTriggerVel*height/2, x+width,  y + height/2 - mTriggerVel*height/2);
    
    // Draw Velocity Bar
    if(vel > mTriggerVel){
        ofSetColor(25, 255, 25);
    } else {
        ofSetColor(100);
    }
    ofDrawLine(x + width-graphWidth, y + height/2 + vel*height/2, x+width,  y + height/2 - vel*height/2);

}

void BeatDisplay::drawDebug(){
    ControlWindow::drawDebug();
    nameFont.drawString("this->beatState:" + ofToString(mBeatState),getRight(), getTop() + 48 );
    nameFont.drawString(ofToString("beats->at(")+ofToString(mBeatIndex)+ofToString(")->getState():") + ofToString(beats->at(mBeatIndex)->getState()),getRight(), getTop() + 60 );
    nameFont.drawString("trigger vel: " + ofToString(beats->at(mBeatIndex)->getTriggerVel()),getRight(), getTop() + 84 );
    nameFont.drawString("velhandleid: " + ofToString(mVelocitySlider.mId),getRight(), getTop() + 72 );
}

void BeatDisplay::onRollover(int x, int y){
    mVelocitySlider.enableMouseEvents();
    mAmplitudeSlider.enableMouseEvents();
}

void BeatDisplay::onRollout(){
    mVelocitySlider.disableMouseEvents();
    mAmplitudeSlider.disableMouseEvents();
}

void BeatDisplay::updateSubComponentPositions(){

    

}