#pragma once

#include "ofMain.h"
#include "ofxVideoRecorder.h"

class ofApp : public ofBaseApp{
    
    std::vector<float> starXpoints(993);
    std::vector<float> starYpoints(993);
    std::vector<float> starZpoints(993);
	
    public:
		void setup();
		void update();
		void draw();
    void exit();
    void initializeStarPoints();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void drawStar(ofPoint point);
        void drawAxes();
    void instantiateStarCoordinates();
    
    ofVideoGrabber      vidGrabber;
    ofxVideoRecorder    vidRecorder;
    ofSoundStream       soundStream;
    bool bRecording;
    int sampleRate;
    int channels;
    string fileName;
    string fileExt;
    
    ofFbo recordFbo;
    ofPixels recordPixels;
    ofTexture recordTexture;
    
        vector<ofPoint> stars;
    
        ofEasyCam cam;
};
