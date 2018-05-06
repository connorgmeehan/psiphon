#pragma once

#include "ofMain.h"

#include "model/Beats.h"
#include "model/Input.h"

struct Beat{
    float amp;
    float vec;
    bool active;
};

class ChannelPrimitive {
    public:

        static std::vector<float> fft;
        static std::vector<Beat> beats;

        virtual std::string getName() = 0;
        virtual std::string getFolderName()= 0;

        virtual void setup(){}
        virtual void update(){}
        virtual void draw(){}

        static void setFFT(std::vector<float> & toset);
};