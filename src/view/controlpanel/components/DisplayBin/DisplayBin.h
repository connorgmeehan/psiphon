#pragma once

#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlWindow.h"
#include "model/Channels.h"

class DisplayBin : public ControlWindow{
    private:
    vector<vector<Channel>> selectableChannels;
    vector<Channel> activeChannels;

    float selectionWidth = -1.0f;
    public:
        void setup();
        void update();
        void draw();
        void drawDebug();
};