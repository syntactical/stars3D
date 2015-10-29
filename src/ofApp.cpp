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
    
    lastStarIndex = 0;
    stars.resize(993);
    
    for (vector<ofPoint>::size_type i = 0; i < stars.size(); i++) {
        stars[i] = ofPoint(ofRandom(-50, 50), starYpoints[i]/100, starZpoints[i]/100);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    if (ofRandom(100) < 6) {
        lastStarIndex = ofClamp(lastStarIndex + 1, 0, 992);
    }
    
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
    cam.orbit(-angle,-20,150,center);
    
    cam.begin();
    
    ofSetColor(ofColor::white);
    
    ofPushMatrix();
    
    ofSetColor(ofColor::white, 40);
    
    drawGrid(1000);
    
    ofSetColor(ofColor::white, 128);
    
    for (vector<ofPoint>::size_type i = 0; i < lastStarIndex; i++) {
        drawStar(stars[i]);
        drawStarAxes(stars[i], 10000);
        ofSetColor(ofColor::white);
        ofDrawBitmapString(starNames[i], stars[i]);
    }
    
    ofSetColor(ofColor::red, 200);
    
    drawStar(stars[lastStarIndex]);
    drawStarAxes(stars[lastStarIndex], 10000);
    ofDrawBitmapString(starNames[lastStarIndex], stars[lastStarIndex]);
    
    ofPopMatrix();
    
    cam.end();
}

void ofApp::drawAxes(){
    ofLine(-1000, 0, 0, 1000, 0, 0);
    ofLine(0, -1000, 0, 0, 1000, 0);
    ofLine(0, 0, -1000, 0, 0, 1000);
}

void ofApp::drawGrid(int limit){
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

void ofApp::drawStarAxes(ofPoint star, int limit){
    ofLine(-limit, star.y, star.z, limit, star.y, star.z);
    ofLine(star.x, -limit, star.z, star.x, limit, star.z);
    ofLine(star.x, star.y, -limit, star.x, star.y, limit);
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
