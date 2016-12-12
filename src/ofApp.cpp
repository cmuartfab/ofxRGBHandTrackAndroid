#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255,255,255);
	ofSetLogLevel(OF_LOG_NOTICE);
	ofSetOrientation(OF_ORIENTATION_90_LEFT);

	int grabberWidth = VID_WIDTH;
	int grabberHeight = VID_HEIGHT;
	grabber.setup(grabberWidth,grabberHeight);

	//colorCv.allocate(grabberWidth, grabberHeight);
	//colorCvSmall.allocate(grabberWidth/4, grabberHeight/4);
	//grayCv.allocate(grabberWidth/4, grabberHeight/4);
	
	//faceFinder.setup("haarcascade_frontalface_default.xml");
	//faceFinder.setNeighbors(1);
	//faceFinder.setScaleHaar(1.5);

	LOGD("Models are being loaded\n");
	//segmenter.setPath("/sdcard/handtracking");
	segmenter.loadModels();
	LOGD("Models have been loaded\n");
	ofLogNotice("ofxHandTrack") << "Models have been loaded\n";
	ofLog() << "C++ Method called from Java" << endl;
	ofLogVerbose("ofxHandTrack") << "Models have been loaded\n";

	colorImg.allocate(VID_WIDTH,VID_HEIGHT);
	grayDiff.allocate(VID_WIDTH,VID_HEIGHT);

	one_second_time = ofGetSystemTime();
	camera_fps = 0;
	frames_one_sec = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	ofLogNotice("ofxHandTrack") << "Update\n";
	if(grabber.isFrameNew()){
		frames_one_sec++;
		if( ofGetSystemTime() - one_second_time >= 1000){
			camera_fps = frames_one_sec;
			frames_one_sec = 0;
			one_second_time = ofGetSystemTime();
		}
		start = ofGetSystemTime();
		colorImg.setFromPixels(grabber.getPixels());
		set_pixels = ofGetSystemTime() - start;
		segmenter.detect(colorImg);
		detectt = ofGetSystemTime() - start - set_pixels;
		segmenter.getForegroundMask(foregroundMask);
		getFGmark = ofGetSystemTime() - start - set_pixels - detectt;
		foregroundMask.update();
		updatee = ofGetSystemTime() - start - set_pixels - detectt - getFGmark;
		grayDiff.setFromPixels(foregroundMask.getPixels());
		setfrompixels = ofGetSystemTime() - start- set_pixels - detectt - getFGmark - updatee;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetHexColor(0xFFFFFF);
	ofLogNotice("ofxHandTrack") << "Draw\n";

	grabber.draw(VID_SPACE,VID_SPACE);
	grayDiff.draw(VID_SPACE+VID_WIDTH,VID_SPACE);

	ofSetHexColor(0x000000);
	ofDrawBitmapString("fps: " + ofToString(ofGetFrameRate()),VID_SPACE+VID_WIDTH,VID_HEIGHT+2*VID_SPACE);
	ofDrawBitmapString("camera fps: " + ofToString(camera_fps),VID_SPACE+VID_WIDTH,VID_HEIGHT+3*VID_SPACE);
	ofDrawBitmapString("set_pixels: " + ofToString(set_pixels),VID_SPACE+VID_WIDTH,VID_HEIGHT+4*VID_SPACE);
	ofDrawBitmapString("detect: " + ofToString(detectt),VID_SPACE+VID_WIDTH,VID_HEIGHT+5*VID_SPACE);
	ofDrawBitmapString("getFGmark: " + ofToString(getFGmark),VID_SPACE+VID_WIDTH,VID_HEIGHT+6*VID_SPACE);
	ofDrawBitmapString("update: " + ofToString(updatee),VID_SPACE+VID_WIDTH,VID_HEIGHT+7*VID_SPACE);
	ofDrawBitmapString("setfrompixels: " + ofToString(setfrompixels),VID_SPACE+VID_WIDTH,VID_HEIGHT+8*VID_SPACE);

}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::touchDown(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchMoved(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchUp(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::swipe(ofxAndroidSwipeDir swipeDir, int id){

}

//--------------------------------------------------------------
void ofApp::pause(){

}

//--------------------------------------------------------------
void ofApp::stop(){

}

//--------------------------------------------------------------
void ofApp::resume(){

}

//--------------------------------------------------------------
void ofApp::reloadTextures(){

}

//--------------------------------------------------------------
bool ofApp::backPressed(){
	return false;
}

//--------------------------------------------------------------
void ofApp::okPressed(){

}

//--------------------------------------------------------------
void ofApp::cancelPressed(){

}
