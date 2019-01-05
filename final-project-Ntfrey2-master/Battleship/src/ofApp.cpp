#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 76, 255);
	mesh.setMode(OF_PRIMITIVE_LINES);
	mesh.enableColors();
	mesh.enableIndices();
	ofTrueTypeFont::setGlobalDpi(72);
	myFont.load("IRON MAN OF WAR 002 NCV.ttf", 72, true, true);
	myFont.setLineHeight(76.0f);
	myFont.setLetterSpacing(1.035);
	shipPic.load("battleship_image.jpg");

	grid();

	ships1();
	ships2();
	playerTurn = 2;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (hitCounter1 == 17 || hitCounter2 == 17) {
		endGame();
	}
	else {
		playGame();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	int column = x / 100;
	int row = y / 80;
	column--;
	row--;
	std::cout << column << " " << row << std::endl;
	if (column == -1 && row == -1) {
		if (playerTurn == 2) {
			if (hasChosen == true) {
				playerTurn = 1;
				hasChosen = false;
			}
			else {
				shipsOrAttack = !(shipsOrAttack);
			}
		}
		else {
			if (hasChosen == true) {
				playerTurn = 2;
				hasChosen = false;
			}
			else {
				shipsOrAttack = !(shipsOrAttack);
			}
		}
	}
	if (column != -1 && row != -1 && hasChosen == false) {
		if (playerTurn == 2) {
			if (shiploc1[column][row] == true && chosenloc2[column][row] == false) {
				hitCounter2++;
				std::cout << hitCounter2 << std::endl;
			}
			if (chosenloc2[column][row] == false) {
				chosenloc2[column][row] = true;
				hasChosen = true;
			}
		}
		else {
			if (shiploc2[column][row] == true && chosenloc1[column][row] == false) {
				hitCounter1++;
				std::cout << hitCounter1 << std::endl;
			}
			if (chosenloc1[column][row] == false) {
				chosenloc1[column][row] = true;
				hasChosen = true;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
//--------------------------------------------------------------
void ofApp::ships1() {
	std::string gameboard[4][10] = {
		{ "TFFFFFFFFF",
		"TFFFFFFTFF",
		"TFFFFFFTFF",
		"TFFFFFFFFF",
		"TFFFFFFFFF",
		"FFFFFTTTTF",
		"FFFFFFFFFF",
		"FFFFFFFFTF",
		"FTTTFFFFTF",
		"FFFFFFFFTF" },
		{ "FFTFFFFFFF",
		"FFTFFFFFFF",
		"FFTFFFFFFF",
		"FFFFTTTFFF",
		"FFFFFFFFFF",
		"TTTTFFFFFT",
		"FFFFFFFFFT",
		"TFFFFFFFFT",
		"TFFFFFFFFT",
		"FFFFFFFFFT" },
		{ "FFFFFFFFFF",
		"FFFFFFFTTF",
		"FFTTTTFFFF",
		"FFFFTFFFFF",
		"TTTFTFFFFF",
		"FFFFTFFFFF",
		"FFFFTFFFFF",
		"FFFFTFFFTF",
		"FFFFFFFFTF",
		"FFFFFFFFTF" },
	  { "FFTTTTTFTF",
		"FFFFFFFFTF",
		"FFFFFFFFFF",
		"FFFFFFFFFF",
		"FFFFFFFFFF",
		"FFFFTTTFFF",
		"FFFFFFFFFF",
		"FFFFFFFFFT",
		"TTTTFFFFFT",
		"FFFFFFFFFT" }
	};
	hitCounter1 = 0;
	int rand = ofRandom(0, 4);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (gameboard[rand][j].at(i) == 'T') {
				shiploc1[i][j] = true;
			}
			else {
				shiploc1[i][j] = false;
			}
		}
	}
}

void ofApp::ships2() {
	std::string gameboard[4][10] = {
	{ "FFFFFFFFFF",
	  "FFFFFFFTTT",
	  "TTFFFFFFFF",
	  "FFFFFFFFFF",
	  "FTFFFFFFFF",
	  "FTFFFFFFFF",
	  "FTFFFFTFFF",
	  "FFFFFFTFFF",
	  "FFFFFFTFFF",
	  "TTTTTFTFFF" },
	{ "FFFFFFFFFT",
	  "FFFFFFFFFT",
	  "FFFFFFFFFT",
	  "FFTTTFFFFT",
	  "FFFFFFFFFT",
	  "FFFFFFFFTF",
	  "FFFTTTFFTF",
	  "FFFFFFFFTF",
	  "FTTFFFFFTF",
	  "FFFFFFFFFF" },
	{ "TTFFFFFFFF",
	  "TFFFFFFFFF",
	  "TFFFFFTFFF",
	  "TFFFFFTFFF",
	  "TFFFFFTFFF",
	  "TFFFFFTFFF",
	  "FFFFFFFFFF",
	  "FFTTTFFFFF",
	  "FFFFFFTTTF",
	  "FFFFFFFFFF" },
	{ "FFFFFFFFFF",
	  "FFFFTTTFFF",
	  "TTTTFFFFFF",
	  "FFFFFFFFTF",
	  "FFFFFFFFTF",
	  "FFFTFFFFTF",
	  "FFFTFFTFFF",
	  "FFFTFFTFFF",
	  "FFFTFFFFFF",
	  "FFFTFFFFFF" }
	};
	hitCounter2 = 0;
	int rand = ofRandom(0, 4);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (gameboard[rand][j].at(i) == 'T') {
				shiploc2[i][j] = true;
			}
			else {
				shiploc2[i][j] = false;
			}
		}
	}
}

void ofApp::displayPlayer1Ships() {
	ofSetColor(169, 169, 169);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (shiploc1[i][j] == true) {
				ofRect((i + 1) * 100, (j + 1) * 80, 100, 80);
			}
		}
	}
}

void ofApp::displayPlayer2Ships() {
	ofSetColor(169, 169, 169);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (shiploc2[i][j] == true) {
				ofRect((i + 1) * 100, (j + 1) * 80, 100, 80);
			}
		}
	}
}

void ofApp::displayPlayer1Attack() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (shiploc2[i][j] == true && chosenloc1[i][j] == true) {
				ofSetColor(255, 0, 0);
				ofRect((i + 1) * 100, (j + 1) * 80, 100, 80);
			}
			else if (shiploc2[i][j] == false && chosenloc1[i][j] == true) {
				ofSetColor(255, 255, 255);
				ofRect((i + 1) * 100, (j + 1) * 80, 100, 80);
			}
		}
	}
}

void ofApp::displayPlayer2Attack() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (shiploc1[i][j] == true && chosenloc2[i][j] == true) {
				ofSetColor(255, 0, 0);
				ofRect((i + 1) * 100, (j + 1) * 80, 100, 80);
			}
			else if (shiploc1[i][j] == false && chosenloc2[i][j] == true) {
				ofSetColor(255, 255, 255);
				ofRect((i + 1) * 100, (j + 1) * 80, 100, 80);
			}
		}
	}
}

void ofApp::displayEndScreen1() {
	std::string congrats = "Congratulations Player 1";
	int length = congrats.size() * 50;
	int xpos = ofGetWidth() / 2 - length / 4;
	myFont.drawString("Congratulations Player 1", xpos - 30, 100);
	myFont.drawString("You have defeated Player 2", xpos - 35, 750);
}

void ofApp::displayEndScreen2() {
	std::string congrats = "Congratulations Player 2";
	int length = congrats.size() * 50;
	int xpos = ofGetWidth() / 2 - length / 4;
	myFont.drawString("Congratulations Player 2", xpos - 30, 100);
	myFont.drawString("You have defeated Player 1", xpos - 35, 750);
}

void ofApp::playGame() {
	displayGrid();

	if (playerTurn == 2) {
		if (shipsOrAttack == false) {
			displayPlayer2Attack();
			if (hasChosen == false) {
				ofSetColor(255);
				ofDrawBitmapString("See Fleet", 10, 40);
			}
			else {
				ofSetColor(255);
				ofDrawBitmapString("End Turn", 10, 40);
			}
		}
		else {
			displayPlayer2Ships();
			ofSetColor(255);
			ofDrawBitmapString("Back", 30, 40);
		}
	}
	else {
		if (shipsOrAttack == false) {
			displayPlayer1Attack();
			if (hasChosen == false) {
				ofSetColor(255);
				ofDrawBitmapString("See Fleet", 10, 40);
			}
			else {
				ofSetColor(255);
				ofDrawBitmapString("End Turn", 10, 40);
			}
		}
		else {
			displayPlayer1Ships();
			ofSetColor(255);
			ofDrawBitmapString("Back", 30, 40);
		}
	}
}

void ofApp::endGame() {
	shipPic.draw(0, 100, 1100, 600);
	if (hitCounter1 == 17) {
	displayEndScreen1();
	}
	else if (hitCounter2 == 17) {
		displayEndScreen2();
	}
}

void ofApp::displayGrid() {
	mesh.draw();
	ofSetColor(255, 255, 255);
	int i;
	for (i = 1; i < 11; i++) {
		ofDrawBitmapString(i, (i * 100) + 50, 40);
	}
	for (char alph = 'A', i = 1; alph < 'K', i < 11; alph++, i++) {
		ofDrawBitmapString(alph, 50, (i * 80) + 40);
	}
}

void ofApp::grid() {
	int j;
	int i;
	for (i = 1, j = 0; i < 12, j < 22; i++, j++) {
		ofVec3f top(i * 100.0, 0.0, 0.0);
		ofVec3f bottom(i * 100.0, 880.0,0.0);
		mesh.addVertex(top);
		mesh.addVertex(bottom);
		mesh.addIndex(j);
		mesh.addIndex(j + 1);
		mesh.addColor(ofFloatColor(0.0, 1.0, 1.0));
		mesh.addColor(ofFloatColor(0.0, 1.0, 1.0));
		j++;
	}

	for (i = 1, j = 22; i < 12, j < 42; i++, j++) {
		ofVec3f left(0.0, i * 80, 0.0);
		ofVec3f right(1100.0, i * 80, 0.0);
		mesh.addVertex(left);
		mesh.addVertex(right);
		mesh.addIndex(j);
		mesh.addIndex(j + 1);
		mesh.addColor(ofFloatColor(0.0, 1.0, 1.0));
		mesh.addColor(ofFloatColor(0.0, 1.0, 1.0));
		j++;
	}
}
