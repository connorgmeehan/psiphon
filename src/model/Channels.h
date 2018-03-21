#pragma once

#include "ofMain.h"

class Channel{
    public:
        int mId = -1;
        std::string mName = "unset";
        Channel(int id, std::string name){
            mId = id;
            mName = name;
        }
};

class Channels{
public:
    const std::string whatAmI = "I AM A CHANNELS CLASS FOR THE MODEL";
    std::vector<Channel> activeChannels;
    int activeChannelsSize = 0;
    std::vector<Channel> selectableChannels;
    int selectableChannelsSize = 0;

    void addSelectableChannel(Channel toAdd){ 
        ofLog(OF_LOG_VERBOSE) << " Channels::addSelectableChannel("<<toAdd.mId<<", "<<toAdd.mName<<");"; 
        selectableChannels.push_back(toAdd); 
        selectableChannelsSize++;
        ofLog(OF_LOG_VERBOSE) << " Channels::addSelectableChannel() - selectableChannels.size() == " << selectableChannels.size();
    }
    void addSelectableChannel(int id, std::string name){
        ofLog(OF_LOG_VERBOSE) << " Channels::addSelectableChannel("<<id<<", "<<name<<");";
        selectableChannels.push_back(Channel(id, name));
        selectableChannelsSize++;
        ofLog(OF_LOG_VERBOSE) << " Channels::addSelectableChannel() - selectableChannels.size() == " << selectableChannels.size();
    }
    Channel getSelectableChannel(int id){
        return selectableChannels[id];
    }

    void addActiveChannel(Channel toAdd){ 
        ofLog(OF_LOG_VERBOSE) << " Channels::addActiveChannel("<<toAdd.mId<<", "<<toAdd.mName<<");"; 
        activeChannels.push_back(toAdd); 
        activeChannelsSize++;
        ofLog(OF_LOG_VERBOSE) << " Channels::addActiveChannel() - activeChannels.size() == " << activeChannels.size();
     }
    void addActiveChannel(int id){ activeChannels.push_back(selectableChannels.at(id));}
    void removeActiveChannel(int id){ activeChannels.erase(activeChannels.begin() + id);}

    int getSelectableChannelSize(){ 
        ofLog(OF_LOG_VERBOSE) << "Channels::getSelectableChannelSize() - selectableChannelsSize == " << selectableChannelsSize;
        ofLog(OF_LOG_VERBOSE) << "Channels::getSelectableChannelSize() - selectableChannels.size() == " << selectableChannels.size();
        return (int)selectableChannels.size(); 
        
    }
    int getActiveChannelSize(){ 
        ofLog(OF_LOG_VERBOSE) << "Channels::getActiveChannelSize() - activeChannelsSize == " << activeChannelsSize;
        ofLog(OF_LOG_VERBOSE) << "Channels::getActiveChannelSize() - activeChannels.size() == " << activeChannels.size();
        return (int) activeChannels.size(); 
        
    }
};