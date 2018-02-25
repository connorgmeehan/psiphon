#include "engine/Analyser.h"

#include "globals.h"
#include "model/Input.h"

using namespace psiInput;

void Analyser::setup(int deviceId){
    ofLog(OF_LOG_NOTICE) << "ofApp.Analyser::setup() - @"<< ofGetElapsedTimef() << "s";

    fourier.resize(bufferSize);
    ofLog(OF_LOG_VERBOSE) << "  ofApp.Analyser::setup() - fft resized to bufferSize() (" << fourier.size() << " = " << bufferSize << ").";

    mFftLive.setup(deviceId);

    mFftLive.setPeakDecay(0.5);
    mFftLive.setMaxDecay(0.95);

    mBeatAnalyser.setup();
}

void Analyser::update(){
    mFftLive.update();
    fourier = mFftLive.getFftPeakData();

    mBeatAnalyser.update();


}