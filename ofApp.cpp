#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofTranslate(0, 0, -2048);

	int len = ofGetWidth() / 2;
	ofColor line_color;
	for (int i = 0; i < 32; i++) {

		int deg = ofRandom(360) + ofNoise(i * 0.1, ofGetFrameNum() * 0.005) * 360;
		int deg_end = deg + ofRandom(45, 225);
		int z = ((int)ofRandom(2048) + ofGetFrameNum() * 10) % 2048;

		line_color.setHsb(ofRandom(255), 239, 239);
		ofSetColor(line_color, ofMap(z, 0, 2048, 0, 128));

		ofBeginShape();
		for (; deg < deg_end; deg += 1) {

			ofVertex(make_rect_point(len, deg, z));
		}
		ofEndShape(true);
	}
	
	this->cam.end();
}

//--------------------------------------------------------------
ofPoint ofApp::make_rect_point(int len, int deg, int z) {

	deg += 45;
	int param = deg / 90;

	switch (param % 4) {

	case 0:

		return ofPoint(len, ofMap(deg % 90, 0, 89, -len, len), z);
	case 1:

		return ofPoint(ofMap(deg % 90, 0, 89, len, -len), len, z);
	case 2:

		return ofPoint(-len, ofMap(deg % 90, 0, 89, len, -len), z);
	case 3:

		return ofPoint(ofMap(deg % 90, 0, 89, -len, len), -len, z);
	}

	return ofPoint();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}