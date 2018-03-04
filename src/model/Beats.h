#pragma once

#include "ofMain.h"

class BeatElementValue {
private:
    float value = -1;
public:
    void operator=(float other){ 
        ofLog(OF_LOG_NOTICE) << "BeatElementValue::operator("<< other <<")";  
        value = other; 
    }
    const float operator()(){ 
        ofLog(OF_LOG_NOTICE) << "BeatElementValue::operator()";  
        return this->value; 
    }
    void setValue(float other){
        ofLog(OF_LOG_NOTICE) << "BeatElementValue::setValue("<< other <<")";  
        value = other;
    }
    const float getValue(){
        ofLog(OF_LOG_NOTICE) << "BeatElementValue::getValue()";  
        return value; }
    };

class BeatElement {
private:
    std::string mName;

    int mFftPosition = -1;
    int mRadius = -1;

    float mAmpThreshold = 0.5; 
    float mVelThreshold = 0.5;

    bool mBeatState = 0;
    float mScale = 1.0f;

    float mBeatLastTime = 0.0f;
    float mBeatCooldown = 0.2f;
public:
    std::vector<float> beatHistory;
    //BeatElementValue amp;
    //BeatElementValue vel;
    
    float amp = 0.0f;
    float vel = 0.0f;

    void setup(std::string& name){
        mName = name;
    }

    bool operator()(){ 
        return (mBeatState == 1);
    }

    std::string getName(){ return mName; }
    void setName(std::string name){ mName = name; }

    void setAmp(float newAmp){ 
        amp = newAmp;
        beatHistory.insert(beatHistory.begin(), newAmp);
        beatHistory.pop_back();
    }

    void setVel(float newVel){
        vel = newVel;
    }

    void updateBeat(){
        if(mBeatState == 1){
            mBeatState = 2;
        } else {
            if(mBeatState == 0){
                if(vel > mVelThreshold){
                    mBeatState = 1;
                    resetTimer();
                }
            }
        }
        if(checkTimer()){
            mBeatState = 0;
        }
    }

    int getState(){
        return mBeatState;
    }

    void setState(int state){
        mBeatState = state;
    }

    void resetTimer(){ mBeatLastTime = ofGetElapsedTimef(); }
    bool checkTimer(){ return (mBeatLastTime - ofGetElapsedTimef() > mBeatCooldown); }

    const inline float getAmpThreshold(){ return mAmpThreshold; }
    void setAmpThreshold(float& other){ mAmpThreshold = other; }

    const inline float getVelThreshold(){ return mVelThreshold; }
    void setVelThreshold(float& other){ mVelThreshold = other; }

    const inline int getPosition(){ return mFftPosition; }
    void getPosition(int position){ mFftPosition = position; }
    const inline int getRadius(){ return mRadius; }
    void setRadius(int radius){ mRadius = radius; }

    int getHistorySize(){ return (int) beatHistory.size(); }
    void setHistorySize(int historySize){
        while(beatHistory.size() != historySize){
            if(beatHistory.size() < historySize){
                beatHistory.push_back(0.5);
            } else {
                beatHistory.pop_back();
            }
        }
    }
    float getHistoryValue(int index){
        return beatHistory[index];
    }

    std::vector<float>& getHistory(){ return beatHistory; }


    
};

class Beats {
private:
    int historySize = 3;
    int mBufferSize;

    std::vector<BeatElement> mBeatsArray;

public:



    BeatElement* operator[](int i){
        return &mBeatsArray[i];
    }

    BeatElement* at(int i){
        return &mBeatsArray[i];
    }

    BeatElement operator()(std::string _beatName){

    }

    void setup(int bufferSize){
        mBufferSize = bufferSize;
        addBeat("kick", mBufferSize*0.02, mBufferSize*0.01);
        addBeat("snare", mBufferSize*0.06, mBufferSize*0.03);
        addBeat("hihat", mBufferSize*0.15, mBufferSize*0.10);
    }

    void addBeat(std::string name, int position, int radius){
        BeatElement temp;
        temp.setName(name);
        temp.getPosition(position);
        temp.setRadius(radius);
        temp.setHistorySize(historySize);
        mBeatsArray.push_back(temp);
    }

    int getBeatSize(){ return (int) mBeatsArray.size(); }
    
};
