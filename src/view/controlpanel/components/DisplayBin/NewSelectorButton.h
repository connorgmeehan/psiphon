#pragma once

#include "ofMain.h"

#include "model/Mouse.h"

#include "view/controlpanel/ControlWindow/ControlSubComponent.h"

#define dPadding 5

class NewSelectorButton : public ControlSubComponent {
    public:
        
        void draw(){
                if(isMouseOver()){
                    ofSetColor(125);
                } else {
                    ofSetColor(100);
                }
                ofDrawRectangle(x+dPadding,y+dPadding,width-dPadding*2,height-dPadding);
                ofSetColor(225, 225, 225);
                textFont.drawString("new selector",
                 x+width/2-textFont.stringWidth("new selector")/2, y+height/2-textFont.stringHeight("new selector")/2);
        }        

        void mouseOver(int x, int y){

        }

};