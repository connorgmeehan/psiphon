#include "view/controlpanel/ControlWindow/ControlWindow.h"

ofTrueTypeFont ControlWindow::nameFont;

void ControlWindow::pre_setup(std::string name, ofVec2f translate){

    // Check if the title font has been loaded
    if(!nameFont.isLoaded()){
        nameFont.load("HelveticaNeueCyr-Light.otf", 9, true, false);
    }
    ofLog(OF_LOG_VERBOSE) << "ControlWindow::pre_setup(name: "<< name <<", translate("<<translate.x<<", "<<translate.y<<");";
    mWindowState.name = name;
    mWindowState.translate = translate;
    this->setup();
}

void ControlWindow::pre_update(){
    this->update();
};

void ControlWindow::pre_draw(){
    //Draw Window Background

    ofSetColor(25, 25, 25);
    ofDrawRectangle(mWindowState.translate.x, mWindowState.translate.y, mWindowState.dimensions.x, mWindowState.dimensions.y);
    
    //Draw Window Border
    ofSetColor(35, 35, 35);
    ofDrawRectangle(mWindowState.translate.x, mWindowState.translate.y, mWindowState.dimensions.x, -12);
    ofSetColor(220, 220, 220);
    //ofDrawBitmapString(mWindowState.name, mWindowState.translate.x, mWindowState.translate.y);
    nameFont.drawString(mWindowState.name, mWindowState.translate.x+3, mWindowState.translate.y-2);
    this->draw();
}



//getters and setters
void ControlWindow::setBeatPointer(Beats* _beats){ beats = _beats; }
void ControlWindow::setInputPointer(Input* _input){ in = _input; }

ofVec2f ControlWindow::getTranslate(){ return mWindowState.translate; }
void ControlWindow::setTranslate(ofVec2f other){ mWindowState.translate = other; }

ofVec2f ControlWindow::getDimensions(){ return mWindowState.dimensions; }
void ControlWindow::setDimensions(ofVec2f other){ mWindowState.dimensions = other; }

