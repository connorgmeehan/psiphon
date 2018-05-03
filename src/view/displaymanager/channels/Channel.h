#pragma once

#include "ofMain.h"

#include "model/Beats.h"
#include "model/Input.h"

struct Beat{
    float amp;
    float vec;
    bool active;
}

class Channel {
    public:

        static std::vector<float> fft;
        static std::vector<Beat> beats;

        virtual std::string getName(){ return "channel_general"; }
        virtual std::string getFolderName(){ return "folder_general"; }

        virtual void setup();
        virtual void update();
        virtual void draw();
}