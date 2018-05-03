#pragma once

// Include oF
#include "ofMain.h"
// Include Channels model
#include "model/Channels.h"
#include "model/Beats.h"
#include "model/Input.h"
// Include the general Channel class
#include "./channels/Channel.h"
// Include Channels
#include "./channels/BRUT/All.h"
class DisplayManager {
    public:

        std::vector<Channel> mChannels;

        void setup(Channels* pChannels);
        void update();
        void draw();
};