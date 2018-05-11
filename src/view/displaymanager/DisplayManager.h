#pragma once

// Include oF
#include "ofMain.h"
// Include Channels model
#include "model/Channels.h"
#include "model/Beats.h"
#include "model/Input.h"
// Include the general Channel class
#include "./channels/ChannelPrimitive.h"
// Include Channels
#include "./channels/BRUT/All.h"
class DisplayManager {
    public:

        Channels* mpChannels;
        Beats* mpBeats;
        Input* mpInput;

        std::vector<ChannelPrimitive*> mChannels;

        Grid* mGrid = new Grid();

        void setup(Input* pInput, Beats* pBeats, Channels* pChannels);
        void update();
        void draw();

        void onKick(float & amp);
        void onSnare(float & amp);
        void onHat(float & amp);
};