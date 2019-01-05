#pragma once

#include "ofMain.h"
#include "ofMesh.h"
#include "ofxGui.h"
#include <string>
#define width 11  
#define height 11  


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void grid();
		void displayGrid();
		void ships1();
		void ships2();
		void displayPlayer1Attack();
		void displayPlayer1Ships();
		void displayPlayer2Attack();
		void displayPlayer2Ships();
		void displayEndScreen1();
		void displayEndScreen2();
		void playGame();
		void endGame();

		ofMesh mesh;
		ofxPanel gui;
		bool shiploc1[10][10];
		bool shiploc2[10][10];
		bool chosenloc1[10][10];
		bool chosenloc2[10][10];
		int playerTurn;
		bool shipsOrAttack;
		bool hasChosen;
		int hitCounter1;
		int hitCounter2;
		ofTrueTypeFont myFont;
		ofImage shipPic;
		
};
