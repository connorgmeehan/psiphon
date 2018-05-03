#pragma once

#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"

class Dragable : public ofxMSAInteractiveObject{
    protected:
        unsigned int mEnumIndex;
        ofVec2f mMouseOffset;
        ofTrueTypeFont mFont;
        std::string mName;
        int mValue;

        ofPath mFolderPath;
    public:

        void setup(){
            mFolderPath.rectangle(0,0,width,height);
            mFolderPath.moveTo(width,0);
            mFolderPath.lineTo(width, 0);
            mFolderPath.lineTo(width, -5);
            mFolderPath.lineTo(width-15, -5);
            mFolderPath.lineTo(width-18, 0);
            

        }

        void set(int enumIndex, std::string name, int value, ofVec2f offset){
            mEnumIndex = enumIndex;
            mName = name;
            mValue = value;
            mMouseOffset = offset;

            if(!mFont.isLoaded()){
                mFont.load("HelveticaNeueCyr-Light.otf", 9, true, false);
            }

            if(enumIndex == 7 || enumIndex == 8){
                setWidth(mFont.stringWidth(mName)+6);
                setHeight(30);
            }
        }

        void updatePosition(int mx, int my){
            x = mx; //+mMouseOffset.x;
            y = my; //+mMouseOffset.y;
        }
        void draw(){
            switch(mEnumIndex){
                case 0: drawEmpty(); break; // DRAG_EMPTY
                // 1: DRAG_WINDOW
                // 2: DRAG_BEAT_AMPLITUDE_SLIDER
                // 3: DRAG_BEAT_VELOCITY_SLIDEr
                // 4: DRAG_FOURIER_BEAT
                // 5: DRAG_CHANNELBIN_PREDRAG_CHANNEL
                // 6: DRAG_CHANNELBIN_PREDRAG_FOLDER
                // 7: DRAG_CHANNELBIN_PREDRAG_ROOT
                case 8: drawChannel(); break; // DRAG_CHANNELBIN_CHANNEL
                case 9: drawFolder(); break; // DRAG_CHANNELBIN_FOLDER

            }
        }
        void setType(unsigned int enumId){
            mEnumIndex = enumId;
        }

        void drawEmpty(){
            ofSetColor(0,255,0);
            ofNoFill();
            ofDrawCircle(x,y,5);
            // GENERAL DRAGABLE IS NOT RENDERABLE
        }

        void drawChannel(){
            ofFill();
            ofSetColor(65);
            ofDrawRectangle(x-width/2,y-height/2,width,height);

            ofSetColor(225);
            ofNoFill();
            // TODO: RESET LINE WIDTH
            ofDrawRectangle(x-width/2,y-height/2,width,height);

            mFont.drawString(mName,x-width/2+32,y);
        }

        void drawFolder(){
            ofFill();
            ofSetColor(65);
            
            mFolderPath.draw(x,y);
            ofSetColor(225);
            ofNoFill();
            // TODO: RESET LINE WIDTH
            mFolderPath.draw(x-width/2,y-height/2);

            mFont.drawString(mName,x-width/2+32,y);
        }
};