#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    ofBackground(ofColor::black);
    ofNoFill();
    
    ofSetFrameRate(60);
    
    fileName = "testMovie";
    fileExt = ".mov";
    
    vidRecorder.setVideoCodec("mpeg4");
    vidRecorder.setVideoBitrate("800k");
    
    bRecording = false;
    
    recordPixels.allocate(ofGetWindowWidth(), ofGetWindowHeight(), OF_PIXELS_RGBA);
    
    stars.resize(993);
    
    for (vector<ofPoint>::size_type i = 0; i < stars.size(); i++) {
        stars[i] = ofPoint(starXpoints[i]/100, starYpoints[i]/100, starZpoints[i]/100);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    if(bRecording){
        cout << recordPixels.size();
        recordTexture.readToPixels(recordPixels);
        
        cout << recordPixels.size();
        bool success = vidRecorder.addFrame(recordPixels);
        if (!success) {
            ofLogWarning("This frame was not added!");
        }
    }
    
    // Check if the video recorder encountered any error while writing video frame or audio smaples.
    if (vidRecorder.hasVideoError()) {
        ofLogWarning("The video recorder failed to write some frames!");
    }
    
    if (vidRecorder.hasAudioError()) {
        ofLogWarning("The video recorder failed to write some audio samples!");
    }
}

void ofApp::exit() {
    vidRecorder.close();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    
    float time = ofGetElapsedTimef();
    float angle = time * 10;

    ofVec3f center=ofVec3f(0,0,0);
    cam.orbit(-angle,-20,300,center);
    
    cam.begin();
    
    ofSetColor(ofColor::white);
    
    ofPushMatrix();
    
    ofSetColor(ofColor::gray);
    
    drawGrid();
    
    ofSetColor(ofColor::white);
    
    for (vector<ofPoint>::size_type i = 0; i < stars.size(); i++) {
        drawStar(stars[i]);
        ofDrawBitmapString(starNames[i], stars[i]);
    }
    
    ofPopMatrix();
    
    cam.end();
}

void ofApp::drawAxes(){
    ofLine(-1000, 0, 0, 1000, 0, 0);
    ofLine(0, -1000, 0, 0, 1000, 0);
    ofLine(0, 0, -1000, 0, 0, 1000);
}

void ofApp::drawGrid(){
    int limit = 1000;
    
    ofSetColor(ofColor::white, 100);
    
    for (int i = -limit; i <= limit; i += 20) {
        ofLine(-limit, i, 0, limit, i, 0);
        ofLine(i, -limit, 0, i, limit, 0);
        
        ofLine(-limit, 0, i, limit, 0, i);
        ofLine(i, 0, -limit, i, 0, limit);
        
        ofLine(0, -limit, i, 0, limit, i);
        ofLine(0, i, -limit, 0, i, limit);
    }
}

void ofApp::drawStar(ofPoint point) {
    float diameter = 2;
    float radius = diameter / 2;
    
    ofPushMatrix();
    
    ofTranslate(point.x, point.y, point.z);
    
    ofLine(-diameter, 0, 0, diameter, 0, 0);
    ofLine(0, -diameter, 0, 0, diameter, 0);
    ofLine(0, 0, -diameter, 0, 0, diameter);
    
    ofCircle(0, 0, 0, radius);
    
    ofPushMatrix();
    
    ofRotateY(90);
    
    //ofCircle(0, 0, 0, radius);
    
    ofPopMatrix();
    
    ofPushMatrix();
    
    ofRotateZ(90);
    
    //ofCircle(0, 0, 0, radius);
    
    ofPopMatrix();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key=='r'){
        bRecording = !bRecording;
        if(bRecording && !vidRecorder.isInitialized()) {
            vidRecorder.setup(fileName+ofGetTimestampString()+fileExt, ofGetWindowWidth(), ofGetWindowHeight(), 30);
            //          vidRecorder.setup(fileName+ofGetTimestampString()+fileExt, vidGrabber.getWidth(), vidGrabber.getHeight(), 30); // no audio
            //            vidRecorder.setup(fileName+ofGetTimestampString()+fileExt, 0,0,0, sampleRate, channels); // no video
            //          vidRecorder.setupCustomOutput(vidGrabber.getWidth(), vidGrabber.getHeight(), 30, sampleRate, channels, "-vcodec mpeg4 -b 1600k -acodec mp2 -ab 128k -f mpegts udp://localhost:1234"); // for custom ffmpeg output string (streaming, etc)
            
            // Start recording
            vidRecorder.start();
        }
        else if(!bRecording && vidRecorder.isInitialized()) {
            vidRecorder.setPaused(true);
        }
        else if(bRecording && vidRecorder.isInitialized()) {
            vidRecorder.setPaused(false);
        }
    }
    if(key=='c'){
        bRecording = false;
        vidRecorder.close();
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
