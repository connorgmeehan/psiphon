#pragma once

#include "ofMain.h"

// Model Classes
#include "model/Input.h"
#include "model/Beats.h"
#include "model/Mouse.h"
#include "model/Channels.h"

// Engine components
#include "engine/ModelConfig/ModelConfig.h"
#include "engine/Analyser.h"

// Control Panel
#include "view/controlpanel/ControlPanel.h"

//DisplayManager
#include "view/displaymanager/DisplayManager.h"


class ofApp : public ofBaseApp{
	private:
		// Model
		Input* mpIn;
		Beats* mpBeats;
		Mouse* mpMouse;
		Channels* mpChannels;
		// Controller
		Analyser mAnalyser;
		// View
		ControlPanel mControlPanel;
		DisplayManager mDisplayManager;

	public:
		void setup();
		void update();
		void updateView(ofEventArgs & args);
		void draw();
		void drawView(ofEventArgs & args);
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void exit();
};
