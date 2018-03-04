#include "engine/Analyser.h"

#include "model/Input.h"

void Analyser::setup(Input *in, Beats *beats, int deviceId){
    ofLog(OF_LOG_NOTICE) << "ofApp.Analyser::setup() - @"<< ofGetElapsedTimef() << "s";

    mpBeats = beats;
    mpIn = in;

    mBufferSize = in->bufferSize;

    mpIn->fourier.resize(mpIn->bufferSize);

    mFftLive.setup(deviceId);  // Sets up audio input

    mFftLive.setPeakDecay(0.5);
    mFftLive.setMaxDecay(0.95);

    mBeatAnalyser.setup(mpIn, mpBeats);
}

void Analyser::update(){
    mFftLive.update();
    mpIn->fourier = mFftLive.getFftPeakData();

    mBeatAnalyser.update();


}