#pragma once

#include "ofMain.h"

struct Channel{
    int mId;
    int mFolderId;
    std::string mName;
};

class Folders{
    public:
        std::vector<std::string> mFolderNames;

        int getId(std::string folderName){

            //If folder exists, return folder ID
            for(std::vector<std::string>::size_type i = 0; i < mFolderNames.size(); i++){
                if(folderName == mFolderNames[i]){
                    return i;
                }
            }
            
            // If folder does not exist, add it and return id;
            mFolderNames.push_back(folderName);
            return mFolderNames.size()-1;
        }

        std::string getName(int i){
            return mFolderNames[i];
        }

        std::string operator[](int i){
            return mFolderNames[i];
        }

        int getSize(){ 
            return mFolderNames.size(); 
        }
};

class Channels{
    public:
        std::vector<Channel> mDisplayBuffer;
        std::vector<Channel> mAvaliableChannels;
        Folders mFolders;

        void addChannel(int id, std::string name, std::string folderName){
            Channel temp;
            temp.mId = id;
            temp.mName = name;
            temp.mFolderId = mFolders.getId(folderName);
            mAvaliableChannels.push_back(temp);
        }

        void addToBuffer(Channel toAdd, int i){
            mDisplayBuffer.insert(mDisplayBuffer.begin()+i, toAdd);
        }

        Channel getChannel(int i){ return mAvaliableChannels[i]; }
        std::string getChannelName(int i){ return mAvaliableChannels[i].mName; }
        vector<Channel> getBuffer(int i){ return mDisplayBuffer; }
        Channel getBufferAtPos(int i){ return mDisplayBuffer[i]; }
        int getChannelSize(){ return (int) mAvaliableChannels.size(); }
        int getBufferSize(){ return (int) mDisplayBuffer.size(); }


        std::vector<int> getChannelIdByFolderId(int folderId){
            std::vector<int> retval;
            for(unsigned int i = 0; i < mAvaliableChannels.size(); i++){
                if(mAvaliableChannels[i].mFolderId == folderId){
                    retval.push_back(i);
                }
            }
            return retval;
        }

        unsigned int getFoldersSize(){ return mFolders.getSize(); }
        std::string getFolderName(int index){ return mFolders.getName(index); }
};