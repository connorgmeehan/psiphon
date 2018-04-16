#include "view/controlpanel/components/DisplayBin/DisplayBin.h"

void DisplayBin::setup(){
    mChannelSelectors.resize(0);

    addNewSelector();

    mNewSelectorButton.enableMouseEvents();
    mNewSelectorButton.enableAppEvents();
    mNewSelectorButton.setPosition(x+width-dNewSelectorWidth, y);
    mNewSelectorButton.setSize(dNewSelectorWidth, height);

}

void DisplayBin::update(){
    
}

void DisplayBin::draw(){
    drawWindow();
}

void DisplayBin::onPress(int x, int y, int button){
    ControlWindow::onPress(x, y, button);
    if(mNewSelectorButton.isMouseOver()){
        addNewSelector();
    }
}

void DisplayBin::addNewSelector(){
    ChannelSelector* toadd = new ChannelSelector();
    toadd->setSize(dSelectorWidth, height);
    toadd->setPosition(x+mChannelSelectors.size()*dSelectorWidth,y);
    toadd->enableAllEvents();
    toadd->setup(channels);
    mChannelSelectors.push_back(toadd);
    updateWidthForSelectors();
}

void DisplayBin::addNewSelector(int index){
    ChannelSelector* toadd = new ChannelSelector();
    toadd->enableAllEvents();
    toadd->setup(channels);
    toadd->setPosition(x+index*dSelectorWidth,y);
    toadd->enableAllEvents();
    mChannelSelectors.insert(mChannelSelectors.begin()+index, toadd);
    updateWidthForSelectors();
}

void DisplayBin::removeSelector(int index){
    ChannelSelector* temp = mChannelSelectors[index];
    mChannelSelectors.erase(mChannelSelectors.begin()+index);
    delete temp;
}

void DisplayBin::updateWidthForSelectors(){
    setWidth(mChannelSelectors.size()*dSelectorWidth + dNewSelectorWidth);
    mNewSelectorButton.setPosition(x+width-dNewSelectorWidth, y);
}

void DisplayBin::updateSubComponentPositions(){
    for(unsigned int i = 0; i < mChannelSelectors.size(); i++){
        mChannelSelectors[i]->setPosition(x+i*dSelectorWidth, y);
    }
    mNewSelectorButton.setPosition(x+width-dNewSelectorWidth, y);
}

void DisplayBin::updateSelectorPositions(){
    for(unsigned int i = 0; i < mChannelSelectors.size(); i++){
        mChannelSelectors[i]->setPosition(x+i*dSelectorWidth, y);
    }
}