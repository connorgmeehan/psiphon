#include "view/controlpanel/ControlWindow/ControlWindow.h"

ofTrueTypeFont ControlWindow::nameFont;

void ControlWindow::setName(std::string name){
    ofLog(OF_LOG_VERBOSE) << "ControlWindow::setName(name: "<< name <<", position("<<x<<", "<<y<<") );";

    // Check if the title font has been loaded
    if(!nameFont.isLoaded()){
        nameFont.load("HelveticaNeueCyr-Light.otf", 9, true, false);
    }
    mName = name;
}

void ControlWindow::drawWindow(){
    if(!enabled) return;
    //Draw Window Background

    ofSetColor(25, 25, 25);
    ofDrawRectangle(x, y, w, h);
    
    //Draw Window Border
    ofSetColor(35, 35, 35);
    ofDrawRectangle(x, y, w, -12);
    ofSetColor(220, 220, 220);
    nameFont.drawString(mName, x+3, y-2);
}


//getters and setters
void ControlWindow::setBeatPointer(Beats* _beats){ beats = _beats; }
void ControlWindow::setInputPointer(Input* _input){ in = _input; }

void ControlWindow::setUseWindow(bool _useWindow){ useWindow = _useWindow; }
