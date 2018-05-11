#include "./ChannelSelector.h"

void ChannelSelector::setup(Channels* pChannels, Mouse* pMouse){
    mpMouse = pMouse;
    mpChannels = pChannels;
}

void ChannelSelector::update(){

}

void ChannelSelector::draw(){
    ofFill();

    if(isMouseOver()){
        ofSetColor(40);
    } else {
        ofSetColor(25);
    }

    ofDrawRectangle(x,y,width,height);
    for(unsigned int i = 0; i < mElements.size(); i++){
        if(mSelectedChannel == i){
            ofSetColor(70,70,20);
        } else {
            if(mHoverId == i){
                ofSetColor(70);
            } else {
                if(i%2==0){
                    ofSetColor(30);
                } else {
                    ofSetColor(50);
                }
            }
        }

        ofDrawRectangle(x, y+i*mElementHeight, width, mElementHeight);
        
        ofSetColor(200);
        textFont.drawString(mElements[i].mName, x+12, y+i*mElementHeight+12);
    }
}

void ChannelSelector::changeChannel(AutoPlayBehaviour behaviour){
    if(mElements.size() > 0){
        switch(behaviour){
            case AUTO_NONE: /* do nothing */ break;
            case AUTO_SHUFFLE: mSelectedChannel = (int) (ofRandomuf()*mElements.size()); break;
            case AUTO_CYCLE: mSelectedChannel = (mSelectedChannel + 1) % mElements.size(); break;
        }
    } else {
        mSelectedChannel = -1;
    }
}

void ChannelSelector::onPress(int x, int y, int button){
    if(!mpMouse->isActive()){   // if mouse is free
        if((int) (y-this->y)/mElementHeight < mElements.size()){ // and element to press is in range
            elementPressHandler( mElements[(int) (y-this->y)/mElementHeight] ); 
        }
    }
}

void ChannelSelector::mouseDragged(int x, int y, int button){
    if(mpMouse->getDragType() == DRAG_CHANNELBIN_PREDRAG_CHANNEL){
        if( mpMouse->getOffset().distance(ofVec3f(getMouseX(), getMouseY())) > 5 ){
            mpMouse->set(DRAG_CHANNELBIN_CHANNEL, mpMouse->getName(), mpMouse->getValue(), mpMouse->getOffset());
        }
    } else if(mpMouse->getDragType() == DRAG_CHANNELBIN_PREDRAG_FOLDER){
        if( mpMouse->getOffset().distance(ofVec3f(getMouseX(), getMouseY())) > 5 ){
            mpMouse->set(DRAG_CHANNELBIN_FOLDER, mpMouse->getName(), mpMouse->getValue(), mpMouse->getOffset());
        }
    }
}

//TODO: Change to switch statements
void ChannelSelector::onRelease(int x, int y, int button){
    ofLog(OF_LOG_VERBOSE) << "ChannelSelector::onRelease(x:"<<x<<", y:"<<y<<", button:"<<button<<") - mpMouse->getDragType():"<<mpMouse->getDragType();
    
    switch(mpMouse->getDragType()){
        case DRAG_CHANNELBIN_PREDRAG_CHANNEL:   elementActivateHandler( (int) (y-this->y)/mElementHeight ); break;
        case DRAG_CHANNELBIN_CHANNEL:           addChannel(mpChannels->getChannel(mpMouse->getValue()), (int) (y-this->y)/mElementHeight); break;
        case DRAG_CHANNELBIN_FOLDER:            addFolder(mpMouse->getValue(), mpMouse->getName(), (int) (y-this->y)/mElementHeight); break;
    }
}

void ChannelSelector::addChannel(int id, std::string name, int folderId, int offset){
    if(mElements.size() == 0){
        mElements.push_back(Channel(id, name, folderId));
        return;
    }
    
    if(offset > mElements.size()){
        offset = mElements.size();
    }

    mElements.insert(mElements.begin()+offset, Channel(id, name, folderId));
}

void ChannelSelector::addChannel(Channel toadd, int offset){
    if(mElements.size() == 0){
        mElements.push_back(toadd);
        return;
    }

    if(offset > mElements.size()){
        offset = mElements.size();
    }

    mElements.insert(mElements.begin() + offset, toadd);
}

/*void ChannelSelector::addFolder(int id, std::string name, int offset){
    if(mElements.size() == 0){
        int folderId = mpChannels->mFolders.getId(name);
        std::vector<int> channelIds = mpChannels->getChannelIdByFolderId(folderId);
        for(unsigned int i = 0; i < channelIds.size(); i++){
            mElements.push_back( Channel(channelIds[i], mpChannels->getChannelName( channelIds[i] ) ) );
        }
        return;
    }
    
    if(offset > mElements.size()){
        offset = mElements.size();
    }
    
    int folderId = mpChannels->mFolders.getId(name);
    std::vector<Channel> toAdd = mpChannels->getFolderContents(folderId);
    for(unsigned int i = 0; i < toAdd.size(); i++){
        mElements.insert(mElements.begin() + i + offset, Channel(toAdd[i].mId, toAdd[i].mName, toAdd[i].mFolderId));
    }
}*/

void ChannelSelector::addFolder(int id, std::string name, int offset){
    if(mElements.size() == 0){
        int folderId = mpChannels->mFolders.getId(name);
        std::vector<int> channelIds = mpChannels->getChannelIdByFolderId(folderId);
        for(unsigned int i = 0; i < channelIds.size(); i++){
            mElements.push_back( mpChannels->getChannel(channelIds[i]) );
        }
        return;
    }
    
    if(offset > mElements.size()){
        offset = mElements.size();
    }
    
    int folderId = mpChannels->mFolders.getId(name);
    std::vector<Channel> toAdd = mpChannels->getFolderContents(folderId);
    for(unsigned int i = 0; i < toAdd.size(); i++){
        mElements.insert(mElements.begin() + i + offset, Channel(toAdd[i].mId, toAdd[i].mName, toAdd[i].mFolderId));
    }
}

void ChannelSelector::elementPressHandler(Channel & el){
    mpMouse->set( DRAG_CHANNELBIN_PREDRAG_CHANNEL, el.mName, el.mId, ofVec2f(x,y) );
}

void ChannelSelector::elementActivateHandler(int activeElementId){
    mSelectedChannel = activeElementId; 
}

void ChannelSelector::onRollout(int x, int y){
    mHoverId = -1;
}

void ChannelSelector::onMouseMove(int x, int y){
    mHoverId = (y-getTop())/mElementHeight; // Change the mHoverId to change which list element is highlighted
}

Channel ChannelSelector::getSelected(){ 
    if(mSelectedChannel >= 0){
        return mElements[mSelectedChannel]; 
    } else {
        return Channel(-1, "null", -1); // Returns -1
    }
}