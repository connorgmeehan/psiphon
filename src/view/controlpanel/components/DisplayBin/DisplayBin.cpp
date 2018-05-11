#include "view/controlpanel/components/DisplayBin/DisplayBin.h"

void DisplayBin::setup(){
    mChannelSelectors.resize(0);

    addNewSelector();

    mNewSelectorButton.enableMouseEvents();
    mNewSelectorButton.enableAppEvents();
    mNewSelectorButton.setPosition(x+width-mNewSelectorWidth, y);
    mNewSelectorButton.setSize(mNewSelectorWidth, height);
    mNewSelectorButton.setup(mouse);

}

void DisplayBin::update(){
    for(unsigned int i = 0; i < mChannelSelectors.size(); i++){
        if(mChannelSelectors[i]->getSelected().mId != 1){
            if(i == channels->mDisplayBuffer.size()){
                channels->mDisplayBuffer.push_back( mChannelSelectors[i]->getSelected() );
            } else {
                channels->mDisplayBuffer.at(i) = mChannelSelectors[i]->getSelected();
            }
        }
    }
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

    ChannelSelector* tempSelector = new ChannelSelector();
    tempSelector->enableAllEvents();
    tempSelector->setPosition(x+mSelectorWidth*mChannelSelectors.size(),y+height*0.1);
    tempSelector->setSize(mSelectorWidth, height*0.9);
    tempSelector->setup(channels, mouse);
    mChannelSelectors.push_back(tempSelector);

    ChannelSelectorBehaviourControls* tempControls = new ChannelSelectorBehaviourControls();
    tempControls->enableAllEvents();
    tempControls->setPosition(x+mSelectorWidth*(mChannelSelectors.size()-1),y);
    tempControls->setSize(mSelectorWidth, height*0.1);
    tempControls->setup(tempSelector, mouse, channels, beats);;
    mChannelBehaviours.push_back(tempControls);
    
    updateWidthForSelectors();
}

void DisplayBin::addNewSelector(int index){

    ChannelSelector* tempSelector = new ChannelSelector();
    tempSelector->enableAllEvents();
    tempSelector->setup(channels, mouse);
    tempSelector->setPosition(x+mSelectorWidth*mChannelSelectors.size(),y+height*0.1);
    tempSelector->setSize(mSelectorWidth, height*0.9);
    mChannelSelectors.insert(mChannelSelectors.begin()+index, tempSelector);
       
    ChannelSelectorBehaviourControls* tempControls = new ChannelSelectorBehaviourControls();
    tempControls->enableAllEvents();
    tempControls->setPosition(x+mSelectorWidth*(mChannelSelectors.size()-1),y);
    tempControls->setSize(mSelectorWidth, height*0.1);
    tempControls->setup(tempSelector, mouse, channels, beats);
    mChannelBehaviours.insert(mChannelBehaviours.begin()+index, tempControls);
 
    updateWidthForSelectors();
}

void DisplayBin::removeSelector(int index){
    delete mChannelBehaviours.at(index);
    mChannelBehaviours.erase(mChannelBehaviours.begin()+index);
    delete mChannelSelectors.at(index);
    mChannelSelectors.erase(mChannelSelectors.begin()+index);
}

void DisplayBin::updateWidthForSelectors(){
    setWidth(mChannelSelectors.size()*mSelectorWidth + mNewSelectorWidth);
    mNewSelectorButton.setPosition(x+width-mNewSelectorWidth, y);
}

void DisplayBin::updateSubComponentPositions(ofVec2f translate){
    for(unsigned int i = 0; i < mChannelSelectors.size(); i++){
        mChannelSelectors[i]->translate(translate);
        mChannelBehaviours[i]->translate(translate);
        mChannelBehaviours[i]->updateSubComponentPositions(translate);
    }
    mNewSelectorButton.translate(translate);
}

void DisplayBin::updateSelectorPositions(){
    for(unsigned int i = 0; i < mChannelSelectors.size(); i++){
        mChannelSelectors[i]->setPosition(x+i*mSelectorWidth, y);
    }
}