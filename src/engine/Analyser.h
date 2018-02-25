#pragma once

#include "ofxFFTLive.h"
#include "engine/BeatAnalyser.h"

class Analyser {
private:
    ofxFFTLive mFftLive;
    BeatAnalyser mBeatAnalyser;
public:
    void setup(int deviceId);
    void update();
};
