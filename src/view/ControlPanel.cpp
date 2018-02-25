#include "view/ControlPanel.h"

void ControlPanel::setup(){

    mFourierDisplay.pre_setup(ofToString("fourier_display"), ofVec2f(10, 50));
    mKickDisplay.pre_setup(ofToString("beat_kick"), ofVec2f(532, 50));
    
    mControlWindows.push_back( &mFourierDisplay );
    mControlWindows.push_back( &mKickDisplay );

}

void ControlPanel::update(){
    for(vector<ControlWindow>::size_type i = 0; i < mControlWindows.size(); i++){
        mControlWindows[i]->pre_update();
    }
}

void ControlPanel::draw(){
    for(vector<ControlWindow>::size_type i = 0; i < mControlWindows.size(); i++){
        mControlWindows[i]->pre_draw();
    }
}