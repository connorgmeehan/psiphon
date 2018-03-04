#pragma once

#include "ofxFFTLive.h"
#include "engine/BeatAnalyser.h"

#include "model/Input.h"
#include "model/Beats.h"

class Analyser {
private:

    int mBufferSize;

    ofxFFTLive mFftLive;
    BeatAnalyser mBeatAnalyser;

    Beats* mpBeats;
    Input* mpIn;

public:
    void setup( Input *in, Beats *beats, int deviceId);
    void update();
};
