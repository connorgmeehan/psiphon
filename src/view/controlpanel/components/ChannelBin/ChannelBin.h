#pragma once

#include "ofMain.h"

#include "model/Channels.h"
#include "model/Mouse.h"

#include "view/controlpanel/ControlWindow/ControlWindow.h"

#include "./ChannelBinListElement.h"

#define dListElHeight 16

struct ChannelStruct{
    std::string mChannelName;
    int mChannelId;
};

struct FolderStruct{
    std::string mFolderName;
    int mFolderId;
    std::vector<ChannelStruct> mChannels;
};

class ChannelBin : public ControlWindow {
    public:

        std::vector<FolderStruct> mFolders;

        std::vector<ChannelBinListElement> mToDisplay;

        int mFolderToDisplay = -1;
        int mListElementLimit = -1;

        void setup();
        void update();
        void draw();

        void populateChannelList();
        void updateListElements(int folder, int offset);
        void clickElement(int index);

        void mouseDragged(int x, int y, int button);
        void onRelease(int x, int y, int button);
        void elementClickHandler(int index);
        
        
};