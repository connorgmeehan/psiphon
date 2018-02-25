#pragma once

#include "ofMain.h"

namespace psiBeat{

    struct BeatElementValue {
        float value;
        void operator=(const float& other){ value = other; }
        float operator()(){ return this->value; }
        void setValue(float& other){ value = other; }
        float getValue(){ return this->value; }
    };

    class BeatElement {
    private:
        std::string mName;

        int mFftPosition = -1;
        int mRadius = -1;

        float mAmpThreshold = 0.5;
        float mVelThreshold = 0.5;

        bool mIsBeat = false;
        float mScale = 1.0f;
    public:
        std::vector<float> beatHistory;
        BeatElementValue amp;
        BeatElementValue vel;

        void setup(std::string& name){
            mName = name;
        }

        bool operator()(){ 
            return mIsBeat;
        }

        std::string getName(){ return mName; }
        void setName(std::string name){ mName = name; }

        void setAmp(float newAmp){ 
            ofLog(OF_LOG_VERBOSE) << "Beats::setAmp(newAmp" << newAmp << ")";
            amp = newAmp;
            beatHistory.insert(beatHistory.begin(), newAmp);
            beatHistory.pop_back();
        }

        void setVel(float newVel){
            ofLog(OF_LOG_VERBOSE) << "Beats::setVel(newVel" << newVel << ")";
            vel = newVel;
        }

        const inline float getAmpThreshold(){ return mAmpThreshold; }
        void setAmpThreshold(float& other){ mAmpThreshold = other; }

        const inline float getVelThreshold(){ return mVelThreshold; }
        void setVelThreshold(float& other){ mVelThreshold = other; }

        const inline int getPos(){ return mFftPosition; }
        void setPos(int position){ mFftPosition = position; }
        const inline int getRadius(){ return mRadius; }
        void setRadius(int radius){ mRadius = radius; }
        
        int getHistorySize(){
            return (int) beatHistory.size();
        }
        void setHistorySize(int historySize){
            while(beatHistory.size() != historySize){
                if(beatHistory.size() < historySize){
                    beatHistory.push_back(beatHistory[beatHistory.size()]);
                } else {
                    beatHistory.pop_back();
                }
            }
        }
        float getHistoryValue(int index){
            ofLog(OF_LOG_VERBOSE) << "Beats::BeatElement::getHistoryValue( index " << index << " )";
            return beatHistory[index];
        }

        std::vector<float>& getHistory(){ return beatHistory; }
        
    };

    #include "config/BeatConfig.h"

    class Beats {
    private:
        int historySize = 3;
    public:
        BeatElement kick;
        BeatElement snare;
        BeatElement hat;

        std::vector<BeatElement*> mBeatsArray = {&kick, &snare, &hat};
        BeatElement operator[](int i){
            return *mBeatsArray[i];
        }

        void setup(){
            this->kick.setPos(beatConfig.kickDefaultPos);
            this->kick.setRadius(beatConfig.kickDefaultRadius);
            this->kick.setHistorySize(historySize);
            this->snare.setPos(beatConfig.snareDefaultPos);
            this->snare.setRadius(beatConfig.snareDefaultRadius);
            this->snare.setHistorySize(historySize);
            this->hat.setPos(beatConfig.hatDefaultPos);
            this->hat.setRadius(beatConfig.hatDefaultRadius);
            this->hat.setHistorySize(historySize);
        }

        int getBeatSize(){ return (int) mBeatsArray.size(); }
        
    };

    extern Beats beats;

};
