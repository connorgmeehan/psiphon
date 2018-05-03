#pragma once

#include "ofMain.h"

#include "model/Channels.h"
#include "model/Mouse.h"

#include "view/controlpanel/ControlWindow/ControlWindow.h"

#include "./ChannelBinList.h"

class ChannelBin : public ControlWindow {
    public:

        ChannelBinList mChannelBinList;
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

        void updateSubComponentPositions(ofVec2f translate);
        
};