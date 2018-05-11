#pragma once

#include "ofMain.h"

#include "view/controlpanel/ControlWindow/ControlSubComponent.h"

#include "model/Channels.h"
#include "model/Mouse.h"
#include "model/Beats.h"

struct ChannelElementStruct{
    int mId;
    std::string mName;
    ChannelElementStruct(int id, std::string name){
        mId = id;
        mName = name;
    }
};

class ChannelSelector : public ControlSubComponent {
    public:
        Mouse* mpMouse;
        Channels* mpChannels;

        int mAutoPlayTrigger = -1; // -1 = none

        int mSelectedChannel = -1; // This is the active channel we return for the DisplayManager to render;
        std::vector<Channel> mElements;
        int mHoverId = -1;
        int mElementHeight = 16;
        int mSelectableChannelSectionSize = 16;
        
        void setup(Channels* pChannels, Mouse* pMouse);
        void update();
        void draw();

        void addChannel(int id, std::string name, int folderId, int offset);
        void addChannel(Channel toadd, int offset);
        void addFolder( int id, std::string name, int offset);
        void resizeSelectableChannels();
        void changeChannel(AutoPlayBehaviour behaviour);

        void onPress(int x, int y, int button);
        void onRelease(int x, int y, int button);
        void mouseDragged(int x, int y, int button);
        void onRollout(int x, int y);
        void onMouseMove(int x, int y);

        void elementPressHandler(Channel & el);
        void elementActivateHandler(int activeElementId);

        Channel getSelected();

};