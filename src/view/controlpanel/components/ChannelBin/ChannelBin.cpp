#include "./ChannelBin.h"

void ChannelBin::setup(){
    setupWindow();
    mChannelBinList.setSize(width*0.9, height);
    mChannelBinList.setPosition(x, y);
    mChannelBinList.setup(channels, mouse);
    mChannelBinList.getChannelData();
    mChannelBinList.enableAppEvents();
    mChannelBinList.enableMouseEvents();
}

void ChannelBin::update(){

}

void ChannelBin::draw(){
    drawWindow();

}

void ChannelBin::mouseDragged(int x, int y, int button){
    ControlWindow::mouseDragged(x,y,button);

}

void ChannelBin::onRelease(int x, int y, int button){
    ControlWindow::onRelease(x,y,button);
}

void ChannelBin::updateSubComponentPositions(ofVec2f translate){
    mChannelBinList.translate(translate);
}
