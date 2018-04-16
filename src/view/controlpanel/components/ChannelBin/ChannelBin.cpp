#include "./ChannelBin.h"

void ChannelBin::setup(){
    setupWindow();

    mListElementLimit = height / dListElHeight;

    mToDisplay.resize(12);
    populateChannelList();
}

void ChannelBin::update(){

}

void ChannelBin::draw(){
    drawWindow();

}

void ChannelBin::populateChannelList(){
    for(unsigned int i = 0; i < channels->getFoldersSize(); i++){
        FolderStruct tempFolder;
        tempFolder.mFolderName = channels->getFolderName(i);
        tempFolder.mFolderId = i;
        
        for(unsigned int j = 0; j < channels->getChannelSize(); j++){
            if(i == channels->getChannel(j).mFolderId){
                ChannelStruct tempChannel;
                tempChannel.mChannelName = channels->getChannel(j).mName;
                tempChannel.mChannelId = channels->getChannel(j).mId;
                tempFolder.mChannels.push_back(tempChannel);
            }
        }

        mFolders.push_back(tempFolder);

        updateListElements(-1, 0);
    }
}

void ChannelBin::updateListElements(int folder, int offset){

    // IF no folder open
    if(folder == -1){

        for(unsigned int i = 0; i < mFolders.size(); i++){
            if(i<16){
                ChannelBinListElement temp;
                mToDisplay[i] = temp;
                mToDisplay[i].setPosition(x,y+dListElHeight * i);
                mToDisplay[i].setSize(width, dListElHeight);
                mToDisplay[i].enableAppEvents();
                mToDisplay[i].enableMouseEvents();
                mToDisplay[i].setupElement(mouse, CHANNEL_BIN_FOLDER, mFolders[i+offset].mFolderName, mFolders[i+offset].mFolderId, i);

            }
        }
        
    } else {

        for(unsigned int i = 0; i + offset < mFolders[folder].mChannels.size(); i++){
            if(i < 16){
                ChannelBinListElement temp;
                mToDisplay[i] = temp;
                mToDisplay[i].setPosition(x,y+dListElHeight * i);
                mToDisplay[i].setSize(width, dListElHeight);
                mToDisplay[i].enableAppEvents();
                mToDisplay[i].enableMouseEvents();
                mToDisplay[i].setupElement(mouse, CHANNEL_BIN_CHANNEL, mFolders[folder].mChannels[i+offset].mChannelName, mFolders[folder].mChannels[i+offset].mChannelId, i);
            }
        }

    }

}

void ChannelBin::mouseDragged(int x, int y, int button){
    ControlWindow::mouseDragged(x,y,button);
    if(mouse->getDragType() == DRAG_CHANNELBIN_PREDRAG_CHANNEL){
        if( mouse->getOffset().distance(ofVec3f(getMouseX(), getMouseY())) > 5 ){
            mouse->set(DRAG_CHANNELBIN_CHANNEL, mouse->getName(), mouse->getValue(), mouse->getOffset());
        }
    } else if(mouse->getDragType() == DRAG_CHANNELBIN_PREDRAG_FOLDER){
        if( mouse->getOffset().distance(ofVec3f(getMouseX(), getMouseY())) > 5 ){
            mouse->set(DRAG_CHANNELBIN_FOLDER, mouse->getName(), mouse->getValue(), mouse->getOffset());
        }
    }
}

void ChannelBin::onRelease(int x, int y, int button){
    ControlWindow::onRelease(x,y,button);
    for(unsigned int i = 0; i < mToDisplay.size(); i++){
        if(mToDisplay[i].mbClicked){
            elementClickHandler(i);
            mToDisplay[i].mbClicked = false;
        }
    }
}

void ChannelBin::elementClickHandler(int index){
    if(mToDisplay[index].mListElementType == CHANNEL_BIN_FOLDER){
        updateListElements(index, 0);
    }    
}