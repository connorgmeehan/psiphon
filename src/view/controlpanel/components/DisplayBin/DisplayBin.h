#pragma once

#include "ofMain.h"
#include "view/controlpanel/ControlWindow/ControlWindow.h"

#include "model/Channels.h"

#include "./NewSelectorButton.h"
#include "./ChannelSelector.h"

#define dSelectorWidth 100
#define dNewSelectorWidth 50

class DisplayBin : public ControlWindow {
    public:
        NewSelectorButton mNewSelectorButton;
        std::vector<ChannelSelector*> mChannelSelectors;

        void setup();
        void update();
        void draw();

        void onPress(int x, int y, int button);

        void addNewSelector(); // adds blank channel selector to end of list
        void addNewSelector(int index); // ads blank channel selector to a position in list

        void removeSelector(int index); // removes a specific index

        void updateWidthForSelectors();
        void updateSelectorPositions();

        void updateSubComponentPositions();

};