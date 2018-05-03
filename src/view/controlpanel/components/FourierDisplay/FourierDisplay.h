#pragma once
#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlWindow.h"
#include "./FourierBeat.cpp"

class FourierDisplay : public ControlWindow {
private:

    ofMesh mFftMesh;
    float mXSpacing = -1;

    vector<FourierBeat> mFourierBeats;
    
public:
    void setup();
    void update();
    void draw();

    void updateSubComponentPositions(ofVec2f translate);
};

