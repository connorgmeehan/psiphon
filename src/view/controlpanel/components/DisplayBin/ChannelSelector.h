#pragma once

#include "ofMain.h"

#include "view/controlpanel/ControlWindow/ControlSubComponent.h"
#include "model/Channels.h"

#include "./SelectableChannel.h"


enum AutoPlayType{
    AUTO_NONE,
    AUTO_SHUFFLE,
    AUTO_CYCLE
};

class ChannelSelector : public ControlSubComponent {
    public:

        Channels* mpChannels;

        int activeChannelIndex;

        AutoPlayType mAutoPlayType = AUTO_NONE;
        int mAutoPlayTrigger = -1; // -1 = none

        int mSelectedChannel;
        vector<SelectableChannel> mSelectableChannels;

        float mSelectableChannelSectionSize = 0.9f;
        
        void setup(Channels* channels);
        void update();
        void draw();

        void addNewChannel(int channelId, int index);

        void resizeSelectableChannels();
};