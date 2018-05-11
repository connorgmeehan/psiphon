#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);

    mpIn = new Input();
    mpBeats = new Beats();
    mpMouse = new Mouse();
    mpChannels = new Channels();

    mDisplayManager.setup(mpIn, mpBeats, mpChannels);

    ModelConfig tempModelConfig;
    tempModelConfig.setup(mpBeats, mpChannels, mpIn, mpMouse, &mDisplayManager);

    mAnalyser.setup(mpIn, mpBeats, 5);  // sets up the audio analyser to input 4
    mControlPanel.setup(mpBeats, mpIn, mpMouse, mpChannels); // sets up the control panel
}

//--------------------------------------------------------------
void ofApp::update(){
    mAnalyser.update(); // updates the (audio)Analyser class so it updates the model
    mControlPanel.update(); // updates the controlPanel
}

void ofApp::updateView(ofEventArgs & args){
    mDisplayManager.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    mControlPanel.draw();
}

void ofApp::drawView(ofEventArgs & args){
    ofClear(0);
    mDisplayManager.draw();
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
    mpMouse->reset();
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

void ofApp::exit(){
    delete mpIn;
    delete mpBeats;
    delete mpMouse;
    delete mpChannels;
}