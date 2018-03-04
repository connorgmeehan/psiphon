#pragma once

#include "ofMain.h"

// Model Classes
#include "model/Input.h"
#include "model/Beats.h"

// Engine components
#include "engine/Analyser.h"

// Control Panel
#include "view/ControlPanel.h"


class ofApp : public ofBaseApp{
	private:
		Input mIn;
		Beats mBeats;
		Analyser mAnalyser;
		ControlPanel mControlPanel;

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
};
