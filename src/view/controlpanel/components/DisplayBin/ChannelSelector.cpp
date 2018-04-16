#include "./ChannelSelector.h"

void ChannelSelector::setup(Channels* pChannels){
    mpChannels = pChannels;

    mSelectableChannels.resize(0);
}

void ChannelSelector::update(){

}

void ChannelSelector::draw(){
    ofSetColor(255);
    // Draw control buttons
    ofDrawRectangle(x,y,width,height*(1-mSelectableChannelSectionSize));
    ofSetColor(0,255,00);
    ofDrawRectangle(x,y+(height*(1-mSelectableChannelSectionSize)),width, height*mSelectableChannelSectionSize);
}

void ChannelSelector::addNewChannel(int channelId, int index){
    if(index > 0 && index < mSelectableChannels.size()){
        SelectableChannel temp;
        temp.setup(channelId, mpChannels->getChannel(channelId).mName);
        mSelectableChannels.insert(mSelectableChannels.begin()+index, temp);
        resizeSelectableChannels();
    }
}

void ChannelSelector::resizeSelectableChannels(){
    float newWidth = width/mSelectableChannelSectionSize/mSelectableChannels.size();

    for(vector<SelectableChannel>::size_type i = 0; i < mSelectableChannels.size(); i++){
        mSelectableChannels[i].setWidth(newWidth);
    }
}
