#pragma once

#include "ofMain.h"

enum AutoPlayBehaviour{
    AUTO_NONE,
    AUTO_SHUFFLE,
    AUTO_CYCLE
};

class BeatElement {
private:
    std::string mName;

    int mFftPosition = -1;
    int mRadius = -1;

    float mAmpThreshold = 0.18; 
    float mVelThreshold = 0.18;

    int mBeatState = 0;
    float mScale = 1.0f;

    u_int64_t mBeatLastTime = 0;
    u_int64_t mBeatCooldown = 200;
public:
    std::vector<float> beatHistory;
    
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

    void calculateVelocity(){
        float gradient = 0.0f;
        for(int i = 0; i < beatHistory.size()-2; i++){
            gradient += (beatHistory[i] - beatHistory[i+1]);
        }
        vel = (gradient / beatHistory.size()) * mScale;
    }

    int getState(){
        return mBeatState;
    }

    void setState(int state){
        mBeatState = state;
    }

    void resetTimer(){ mBeatLastTime = ofGetElapsedTimeMillis(); }
    bool checkTimer(){ return (ofGetElapsedTimeMillis()-mBeatLastTime > mBeatCooldown); }

    const inline float getTriggerAmp(){ return mAmpThreshold; }
    void setTriggerAmp(float& other){ mAmpThreshold = other; }

    const inline float getTriggerVel(){ return mVelThreshold; }
    void setTriggerVel(float& other){ mVelThreshold = other; }

    const inline float getScale(){ return mScale; }
    void setScale(float & other){ mScale = other; }

    const inline int getPosition(){ return mFftPosition; }
    void setPosition(int position){ mFftPosition = position; }
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
        return &mBeatsArray.at(i);
    }

    BeatElement* at(int i){
        return &mBeatsArray[i];
    }

    BeatElement operator()(std::string _beatName){

    }

    void addBeat(std::string name, int position, int radius){
        BeatElement temp;
        temp.setName(name);
        temp.setPosition(position);
        temp.setRadius(radius);
        temp.setHistorySize(historySize);
        mBeatsArray.push_back(temp);
    }

    int getBeatSize(){ return (int) mBeatsArray.size(); }
    
};
