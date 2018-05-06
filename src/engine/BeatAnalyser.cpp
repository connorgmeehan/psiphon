#include "BeatAnalyser.h"

void BeatAnalyser::setup(Input* in, Beats* beats){
    mpBeats = beats;
    mpIn = in;

    mBufferSize = in->bufferSize;

}
void BeatAnalyser::update(){
    for(int i = 0; i < mpBeats->getBeatSize(); i++){

        int fftPos = mpBeats->at(i)->getPosition();
        int fftRadius = mpBeats->at(i)->getRadius();

        int lowerBounds = fftPos-fftRadius;
        if(lowerBounds < 0){ lowerBounds = 0; }
        int upperBounds = fftPos+fftRadius;
        if(upperBounds > mpIn->bufferSize){ upperBounds = mpIn->bufferSize-1; }

        // Calculate amplitude (average volume)
        float amplitude = 0;
        for(int i = lowerBounds; i < upperBounds; i++){
            amplitude += mpIn->fourier[i];
        }
        mpBeats->at(i)->setAmp( amplitude / (upperBounds - lowerBounds) );
        mpBeats->at(i)->calculateVelocity();
        mpBeats->at(i)->updateBeat();
    }
}

void BeatAnalyser::update(std::vector<float> & fft){
    for(int i = 0; i < mpBeats->getBeatSize(); i++){

        int fftPos = mpBeats->at(i)->getPosition();
        int fftRadius = mpBeats->at(i)->getRadius();

        int lowerBounds = fftPos-fftRadius;
        if(lowerBounds < 0){ lowerBounds = 0; }
        int upperBounds = fftPos+fftRadius;
        if(upperBounds > mpIn->bufferSize){ upperBounds = mpIn->bufferSize-1; }

        // Calculate amplitude (average volume)
        float amplitude = 0;
        for(int i = lowerBounds; i < upperBounds; i++){
            amplitude += fft[i];
        }
        mpBeats->at(i)->setAmp( amplitude / (upperBounds - lowerBounds) );
        mpBeats->at(i)->calculateVelocity();
        mpBeats->at(i)->updateBeat();
    }
}