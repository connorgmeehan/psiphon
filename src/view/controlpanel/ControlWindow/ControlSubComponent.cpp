#include "view/controlpanel/ControlWindow/ControlSubComponent.h"

ofTrueTypeFont ControlSubComponent::textFont;
Mouse* ControlSubComponent::mouse;
Channels* ControlSubComponent::channels;
Input* ControlSubComponent::input;
Beats* ControlSubComponent::beats;

void ControlSubComponent::drawDebug(){
    if(mDrawDebug){
        ofSetColor(100, 100, 255);

        ofDrawSphere(getCenter(), 2);
        ofSetLineWidth(0.5);
        ofDrawLine(0, getTop(), 10000, getTop());
        ofDrawLine(0, getBottom(), 10000, getBottom());
        ofDrawLine(getLeft(), 0, getLeft(), 10000);
        ofDrawLine(getRight(), 0, getRight(), 10000);
    }
}

void ControlSubComponent::setBounds(ofRectangle toSet){
    mBounds = toSet;
}

void ControlSubComponent::setBounds(int x, int y, int width, int height){
    mBounds.set(x,y,width,height);
}

void ControlSubComponent::reinsertInHorizontalBoundaries(){
    if(x < mBounds.x){
        setX( mBounds.x );
    } else if(getRight() > mBounds.getRight()){
        setX(mBounds.getRight()-width);
    }
}

void ControlSubComponent::reinsertInVerticalBoundaries(){  
    if(y < mBounds.y){
        setY(mBounds.y);
    } else if(getBottom() > mBounds.getBottom()){
        setY(mBounds.getBottom() - height);
    }
}

void ControlSubComponent::onKeyPress(int key){
    if(key = 'd'){
        mDrawDebug = !mDrawDebug;
    }
}
