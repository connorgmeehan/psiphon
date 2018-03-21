#pragma once

#define PSI_BUFFER_SIZE 512

#include "model/All.h"

class ModelConfig{
    private:
        Beats* mpBeats;
        Channels* mpChannels;
        Input* mpInput;
        Mouse* mpMouse;

        int mBufferSize;
    public:
        void setup(Beats* pBeats, Channels* pChannels, Input* pInput, Mouse* pMouse);

        void setupBeats();
        void setupChannels();
        void setupInput();
        void setupMouse();
};