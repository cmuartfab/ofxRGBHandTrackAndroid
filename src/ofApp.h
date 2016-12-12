#pragma once

#include "ofMain.h"
#include "ofxAndroid.h"

#include "ofxOpenCv.h"
#include "ofxPerPixelSegment.h"

#include <vector>

#define VID_WIDTH 320
#define VID_HEIGHT 240
#define VID_SPACE  20

class ofApp : public ofxAndroidApp{
	
	public:
		
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void windowResized(int w, int h);

		void touchDown(int x, int y, int id);
		void touchMoved(int x, int y, int id);
		void touchUp(int x, int y, int id);
		void touchDoubleTap(int x, int y, int id);
		void touchCancelled(int x, int y, int id);
		void swipe(ofxAndroidSwipeDir swipeDir, int id);

		void pause();
		void stop();
		void resume();
		void reloadTextures();

		bool backPressed();
		void okPressed();
		void cancelPressed();

		ofVideoGrabber grabber;
		ofxCvColorImage colorImg;
		ofxCvGrayscaleImage grayDiff;
		//ofxCvHaarFinder faceFinder;
		//std::vector<ofxCvBlob> faces;

		ofxPerPixelSegment segmenter;
		ofImage foregroundMask;

		int one_second_time;
		int camera_fps;
		int frames_one_sec;
		long long int start;
		long long int  set_pixels;
		long long int  detectt;
		long long int  getFGmark;
		long long int  updatee;
		long long int  setfrompixels;
};
