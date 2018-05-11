#include "./BeatDisplay.h"

void BeatDisplay::setup(){
    ofLog(OF_LOG_NOTICE) << "BeatDisplay::setup() ("<<ofGetElapsedTimef()<<")";
    
    setupWindow();

    mHistorySize = beats->at(mBeatIndex)->getHistorySize();
    mScale = beats->at(mBeatIndex)->getScale();
    mTriggerVel = beats->at(mBeatIndex)->getTriggerVel();

    ofLog() << "BeatDisplay::setup() - mTriggerVel:"<<mTriggerVel;

    mVelocitySlider.enableMouseEvents();
    mVelocitySlider.enableAppEvents();
    mVelocitySlider.setSize(10,8);
    mVelocitySlider.setPosition(getRight()-mVelocitySlider.width,getCenter().y+mTriggerVel*height/2 - mVelocitySlider.height/2);
    mVelocitySlider.setPosition(
        getRight() - mVelocitySlider.width, 
        getCenter().y - mTriggerVel*height - mVelocitySlider.height/2 
    ); 

    
    mVelocitySlider.setBounds(x, y, width, height);
    mVelocitySlider.setup(mouse, mId);

    mScaleSlider.enableMouseEvents();
    mScaleSlider.enableAppEvents();
    mScaleSlider.setSize(graphWidth/mHistorySize, 8);
    mScaleSlider.setPosition(x + width - graphWidth, y + height - mScale*height - mScaleSlider.y/2);
    mScaleSlider.setBounds(x, y, width, height);
    mScaleSlider.setup(mouse, mId);
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

        mTriggerVel = (getCenter().y - mVelocitySlider.getCenter().y)/height;
        beats->at(mBeatIndex)->setTriggerVel(mTriggerVel);

    }

    if(mScaleSlider.mUpdateFlag = true){
        mScaleSlider.mUpdateFlag = false;

        mScale = (getBottom() - mScaleSlider.getCenter().y)/height*3;
        beats->at(mBeatIndex)->setScale(mScale);
    }


}

void BeatDisplay::draw(){
    drawWindow();

    ofSetColor(200);
    nameFont.drawString(ofToString(vel, 2), x + 5, y + height - 18 );
    nameFont.drawString(ofToString(amp, 2), x + 5, y + height - 5);

    nameFont.drawString(ofToString(mTriggerVel, 2), mVelocitySlider.x + mVelocitySlider.width, mVelocitySlider.y);

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

    ofSetColor(100);

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
    mScaleSlider.enableMouseEvents();
}

void BeatDisplay::onRollout(){
    mVelocitySlider.disableMouseEvents();
    mScaleSlider.disableMouseEvents();
}

void BeatDisplay::updateSubComponentPositions(ofVec2f translate){
    mScaleSlider.translate(translate);
    mVelocitySlider.translate(translate);
    mScaleSlider.setBounds(x,y,width,height);
    mVelocitySlider.setBounds(x,y,width,height);
}