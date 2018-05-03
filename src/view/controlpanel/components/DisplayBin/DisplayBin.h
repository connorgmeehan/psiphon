#pragma once

#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlWindow.h"

#include "./ChannelSelector.h"
#include "./ChannelSelectorBehaviourControls.h"
#include "./NewSelectorButton.h"


class DisplayBin : public ControlWindow {
    public:
        NewSelectorButton mNewSelectorButton;
        std::vector<ChannelSelector*> mChannelSelectors;
        std::vector<ChannelSelectorBehaviourControls*> mChannelBehaviours;

        int mSelectorWidth = 100;
        int mNewSelectorWidth = 50;

        void setup();
        void update();
        void draw();

        void onPress(int x, int y, int button);

        void addNewSelector(); // adds blank channel selector to end of list
        void addNewSelector(int index); // ads blank channel selector to a position in list

        void removeSelector(int index); // removes a specific index

        void updateWidthForSelectors();
        void updateSelectorPositions();

        void updateSubComponentPositions(ofVec2f translate);

};