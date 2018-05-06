#pragma once

#include "model/Beats.h"
#include "model/Input.h"

class BeatAnalyser{
private:
    float mThreshold;
    int mBufferSize;
    Input* mpIn;
    Beats* mpBeats;
public:
    void setup(Input* in, Beats* beats);
    void update();
    void update(std::vector<float> & fft);
};

