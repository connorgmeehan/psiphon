#include "BeatAnalyser.h"

#include "model/Input.h"
using namespace psiInput;

#include "model/Beats.h"
using namespace psiBeat;


void BeatAnalyser::setup(){

}

void BeatAnalyser::update(){

    for(int i = 0; i < beats.getBeatSize(); i++){

        int fftPos = beats[i].getPos();
        int fftRadius = beats[i].getRadius();

        int lowerBounds = fftPos-fftRadius;
        if(lowerBounds < 0){ lowerBounds = 0; }
        int upperBounds = fftPos+fftRadius;
        if(upperBounds > bufferSize){ upperBounds = bufferSize-1; }

        // Calculate amplitude (average volume)
        float amplitude = 0;
        for(int i = lowerBounds; i < upperBounds; i++){
            amplitude += fourier[i];
        }
        beats[i].setAmp( amplitude / (upperBounds - lowerBounds) );

        //calculating velocity
        float velocity = 0.0;
        ofLog(OF_LOG_VERBOSE) << " vel = 0.0";
        float c = 0.0;
        ofLog(OF_LOG_VERBOSE) << "c = 0.0";
        for(vector<float>::size_type i = 0; i < beats[i].getHistorySize() - 1; i++){
            ofLog(OF_LOG_VERBOSE) << "loop " << i;
            float y = beats[i].getHistoryValue(i) - c;
            ofLog(OF_LOG_VERBOSE) << " y =" << y;
            float t = velocity + y;
            ofLog(OF_LOG_VERBOSE) << "t = "<< t;
            c = (t - velocity) - y;
            ofLog(OF_LOG_VERBOSE) << " c =" << c;
            velocity = t;
            ofLog(OF_LOG_VERBOSE) << "velocity = " << velocity;
        }
        beats[i].setVel(velocity);
        
    }
}