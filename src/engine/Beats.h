#ifndef BEAT_CLASS
#define BEAT_CLASS

#include <string>

struct BeatStructValue {
    float value;
    void operator=(const float& other){ value = other; }
    float operator()(){ return this->value; }
    void setValue(float& other){ value = other; }
    float getValue(){ return this->value; }
};

class BeatStruct {
private:
    std::string m_Name;
    float m_AmpThreshold = 0.5;
    float m_VelThreshold = 0.5;
    bool useAmp = false;
public:
    BeatStructValue amp;
    BeatStructValue vel;

    void setup(std::string& name){
        m_Name = name;
    }

    bool operator()(){ 
        if(useAmp){
            if(amp.getValue() > m_AmpThreshold){
                return true;
            }
        } else {
            if(vel.getValue > m_VelThreshold){
                return true;
            }
        }
        return false;
    }

    std::string getName(){ return m_Name; }
    void setName(std::string name){ m_Name = name; }

    float getAmpThreshold(){ return m_AmpThreshold; }
    void setAmpThreshold(float& other){ m_AmpThreshold = other; }

    float getVelThreshold(){ return m_VelThreshold; }
    void getVelThreshold(float& other){ m_VelThreshold = other; }
    
};

class Beat {
    public:
    BeatStruct kick;
    BeatStruct snare;
    BeatStruct hat;
     
};

extern Beat beats;

#endif