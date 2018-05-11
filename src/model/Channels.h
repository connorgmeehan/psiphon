#pragma once

#include "ofMain.h"

struct Channel{
    int mId;
    int mFolderId;
    std::string mName;
    Channel(int id, std::string name, int folderId){
        mId = id;
        mName = name;
        mFolderId = folderId;
    }

    Channel(const Channel & input){
        mId = input.mId;
        mName = input.mName;
        mFolderId = input.mFolderId;
    }
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
            int folderId = mFolders.getId(folderName);
            mAvaliableChannels.push_back( Channel(id, name, folderId) );
        }

        void pushToBuffer(int channelId){
            mDisplayBuffer.push_back(mAvaliableChannels[channelId]);
        }

        Channel getChannel(int i){ return mAvaliableChannels[i]; }
        std::string getChannelName(int i){ return mAvaliableChannels[i].mName; }
        int getChannelSize(){ return (int) mAvaliableChannels.size(); }
        int getBufferSize(){ return (int) mDisplayBuffer.size(); }

        std::vector<Channel> getFolderContents(int folderId){
            std::vector<Channel> retval;
            for(unsigned int i = 0; i < mAvaliableChannels.size(); i++){
                if(mAvaliableChannels[i].mFolderId == folderId){
                    retval.push_back(mAvaliableChannels[i]);
                }
            }
            return retval;
        }


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