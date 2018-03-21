#include "view/controlpanel/components/DisplayBin/DisplayBin.h"

void DisplayBin::setup(){
    setupWindow();
    ofLog(OF_LOG_VERBOSE) << "DisplayBin::setup() ("<<ofGetElapsedTimef()<<")";
    ofLog(OF_LOG_VERBOSE) << "DisplayBin::setup() - channels == nullptr? " << (channels = nullptr);
    ofLog(OF_LOG_VERBOSE) << "DisplayBin::setup() - beats->getBeatSize()? " << beats->getBeatSize();    
    ofLog(OF_LOG_VERBOSE) << "DisplayBin::setup() - what is \"channels\"? " << ofToString(channels->getSelectableChannel(0).mId);
    ofLog(OF_LOG_VERBOSE) << "DisplayBin::setup() - channels.getSelectableChannelSize() " << channels->getSelectableChannelSize();
    ofLog(OF_LOG_VERBOSE) << "DisplayBin::setup() - channels.getActiveChannelSize() " << channels->getActiveChannelSize();
}

void DisplayBin::update(){

}

void DisplayBin::draw(){
    drawWindow();
    for(int i = 0; i < selectableChannels.size(); i++){
        selectionWidth = width / selectableChannels[i].size();
        for(int j = 0; j < selectableChannels[i].size(); j++){
            ofSetColor(100 + (j%2)*50);
            ofDrawRectangle(x + j * selectionWidth, y, selectionWidth, height);
        }
    }
}

void DisplayBin::drawDebug(){
    ControlWindow::drawDebug();
    nameFont.drawString("selectionSize:" + ofToString(selectableChannels.size()),getRight(), getTop() + 48 );
    nameFont.drawString("selectionWidth:" + ofToString(selectionWidth),getRight(), getTop() + 60 );
}