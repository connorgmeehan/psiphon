#include "view/controlpanel/ControlWindow/ControlWindow.h"

ofTrueTypeFont ControlWindow::nameFont;
Input* ControlWindow::in = nullptr;
Beats* ControlWindow::beats = nullptr;
Mouse* ControlWindow::mouse = nullptr;
Channels* ControlWindow::channels = nullptr;

void ControlWindow::setName(std::string name){
    ofLog(OF_LOG_VERBOSE) << "ControlWindow::setName(name: "<< name <<", position("<<x<<", "<<y<<") );";
    mName = name;
}

//getters and setters
void ControlWindow::setPointers(Beats* _beats, Input* _input, Mouse* _mouse, Channels* _channels){
    ofLog(OF_LOG_VERBOSE) << "static ControlWindow::setPointers( Beats* "<< typeid(_beats).name() <<", Input* "<< typeid(_input).name() <<", Mouse* "<< typeid(_mouse).name() << ", Channels* " << typeid(_channels).name() << ")";
    beats = _beats;
    in = _input;
    mouse = _mouse;
    channels = _channels;
}

void ControlWindow::setId(int id){ mId = id; }

void ControlWindow::setupWindow(){
    mUseWindow = true;
    mWindowBar.setSize(width, 12);
    mWindowBar.setPosition(x,y-12);
    mWindowBar.enableMouseEvents();

    // Check if the title font has been loaded
    if(!nameFont.isLoaded()){
        nameFont.load("HelveticaNeueCyr-Light.otf", 9, true, false);
    }
}

void ControlWindow::drawWindow(){
    if(!enabled || !mUseWindow) return;

    //Draw Window Background
    ofFill();

    if(isMouseOver()){
        ofSetColor( CW_HOVER_BACKGROUND );
    } else {
        ofSetColor( CW_BACKGROUND );
    }
    ofDrawRectangle(x, y, width, height);
    
    //Draw Window Border
    if(mWindowBar.isMouseOver() || isMouseOver()){
        ofSetColor( CW_HOVER_BORDER );
    } else {
        ofSetColor( CW_BORDER );
    }
    ofDrawRectangle(mWindowBar.x, mWindowBar.y, width, 12);
    ofSetColor(CW_TEXT_COLOUR);
    nameFont.drawString(mName, x+3, y-2);

    if(mShowDebug){ drawDebug(); }
}

void ControlWindow::drawDebug(){
    ofSetColor(100, 100, 255);

    ofDrawSphere(getCenter(), 2);
    ofSetLineWidth(0.5);
    ofDrawLine(0, getTop(), 10000, getTop());
    ofDrawLine(0, getBottom(), 10000, getBottom());
    ofDrawLine(getLeft(), 0, getLeft(), 10000);
    ofDrawLine(getRight(), 0, getRight(), 10000);

    if(mUseWindow){
        ofSetColor(100, 255, 100);
        ofDrawLine(0, mWindowBar.getTop(), 10000, mWindowBar.getTop());
        ofDrawLine(0, mWindowBar.getBottom(), 10000, mWindowBar.getBottom());
        ofDrawLine(mWindowBar.getLeft(), 0, mWindowBar.getLeft(), 10000);
        ofDrawLine(mWindowBar.getRight(), 0, mWindowBar.getRight(), 10000);   
    } 
 
    ofSetColor(255);
    nameFont.drawString( "name: " + ofToString(mName) + ", id: " + ofToString(mId), getRight(), getTop() );
    nameFont.drawString( "x: " + ofToString(x)+ ", y: " + ofToString(y), getRight(), getTop() + 12 );
    nameFont.drawString( "mouseOver?: " + ofToString(isMouseOver()), getRight(), getTop() + 24 );
    nameFont.drawString( "windowBar mouseOver?: " + ofToString(mWindowBar.isMouseOver()), getRight(), getTop() + 36 );

    if(!mouse->isActive()){
        ofDrawCircle(getPosition() + mouse->getOffset(), 2);
    } else if(mouse->getDragType() == DRAG_WINDOW){
        ofSetColor(255,100,100);
        ofDrawCircle(getPosition() + mouse->getOffset(), 2);
        nameFont.drawString( "type: " + ofToString(mouse->getDragType()), getLeft() + mouse->getOffset().x, getTop() + mouse->getOffset().y - 12);
        nameFont.drawString( "name: " + ofToString(mouse->getName()), getLeft() + mouse->getOffset().x, getTop() + mouse->getOffset().y );
        nameFont.drawString( "value: " + ofToString(mouse->getValue()), getLeft() + mouse->getOffset().x, getTop() + mouse->getOffset().y + 12);
        nameFont.drawString( "offset: (" + ofToString(mouse->getOffset().x) + ", "+ ofToString(mouse->getOffset().y) + ")", getLeft() + mouse->getOffset().x, getTop() + mouse->getOffset().y + 24);
    }
}

void ControlWindow::onKeyPress(int key){
    if(key == 'd'){
        mShowDebug = !mShowDebug;
    }
}

void ControlWindow::onPress(int x, int y, int button){
    if(ofGetKeyPressed(OF_KEY_LEFT_SHIFT)){
        if(!mouse->isActive()){
            mouse->set(DRAG_WINDOW, mName, mId, ofVec2f(x-getLeft(), y-getTop()));
        }
    }
}

void ControlWindow::mouseDragged(int x, int y, int button){
    if(ofGetKeyPressed(OF_KEY_LEFT_SHIFT)){
        if(mouse->getDragType() == DRAG_WINDOW && mouse->getValue() == mId){
            ofVec2f prevPosition = getPosition();
            setPosition(x - mouse->getOffset().x, y - mouse->getOffset().y);
            mWindowBar.setPosition(getLeft(),getTop()-12);
            updateSubComponentPositions(getPosition() - prevPosition);
        }
    }
}