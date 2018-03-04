#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    mBeats.setup(mIn.bufferSize);
    mAnalyser.setup(&mIn, &mBeats, 4);  // sets up the audio analyser to input 4
    mControlPanel.setup(&mBeats, &mIn); // sets up the control panel
}

//--------------------------------------------------------------
void ofApp::update(){
    mAnalyser.update(); // updates the (audio)Analyser class so it updates the model
    mControlPanel.update(); // updates the controlPanel
}

void ofApp::updateView(ofEventArgs & args){
    // TODO: Implement display manager
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    ofDrawBitmapString("Config", 0, 12);
    mControlPanel.draw();
}

void ofApp::drawView(ofEventArgs & args){
    ofClear(0);
    ofDrawBitmapString("View", 0, 12);
}




//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}