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
        stars[i] = ofPoint(ofRandom(-100,100),ofRandom(-100,100),ofRandom(-100,100));
//        stars[i] = ofPoint(starXpoints[i]/100, starYpoints[i]/100, starZpoints[i]/100);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    if (ofRandom(100) < 1) {
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
    ofEnableAlphaBlending();
    ofEnableDepthTest();
    
    float time = ofGetElapsedTimef();
    float angle = time * 10;

    ofVec3f center=ofVec3f(0,0,0);
    
    cam.begin();
    
    ofPushMatrix();
    
    ofTranslate(1000,1000,1000);
    
    ofDrawGrid(4000, 10, true);
    
    ofSetColor(ofColor::white, 40);
    
    for (vector<ofPoint>::size_type i = 0; i < lastStarIndex; i++) {
        ofVec3f star = stars[i];
        
        ofPushMatrix();
    
        ofTranslate(star.x, star.y, star.z);
        
        drawStarAxes(stars[i], 10000);
        drawStar(stars[i]);
        ofDrawBitmapString(starNames[i], stars[i]);
        
        ofPopMatrix();
    }
    
    ofSetColor(ofColor::red, 200);
    
    ofPoint lastStar = stars[lastStarIndex];
    
    drawStar(lastStar);
    drawStarAxes(lastStar, 10000);
    ofDrawBitmapString(starNames[lastStarIndex], lastStar);
    
    ofPopMatrix();
    
//    ofVec2f lastStarProjectedCoords = getProjectedCoords(lastStar.x, lastStar.y, lastStar.z, cam);
//    ofSetColor(ofColor::white);
//    ofLine(lastStarProjectedCoords.x, lastStarProjectedCoords.y, ofGetWindowWidth() - 100, ofGetWindowHeight() - 100);
//    ofDrawBitmapString(ofToString(lastStarProjectedCoords.x), 100, 100);
//    ofDrawBitmapString(ofToString(lastStarProjectedCoords.y), 100, 130);
    
    cam.end();
    
    ofDisableAlphaBlending();
    
    ofDisableDepthTest();
    
    
    ofDrawBitmapString(ofToString(ofGetFrameRate()), ofGetWindowWidth() - 100, ofGetWindowHeight() - 100);
//    ofDrawBitmapString(ofToString(cam.getNearClip()), ofGetWindowWidth() - 100, ofGetWindowHeight() - 100);
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
    ofPushStyle();
    ofSetColor(ofColor::white);
    
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
    ofPopStyle();
}

void ofApp::drawStarAxes(ofPoint star, int limit){
    ofPushStyle();
    ofSetColor(ofColor::white, 10);
    ofLine(-limit, star.y, star.z, limit, star.y, star.z);
    ofLine(star.x, -limit, star.z, star.x, limit, star.z);
    ofLine(star.x, star.y, -limit, star.x, star.y, limit);
    ofPopStyle();
}

ofVec2f ofApp::getProjectedCoords(float x, float y, float z, ofEasyCam cam) {
    float projected_x = cam.getX() + ((cam.getNearClip()-cam.getZ())*(x-cam.getX()))/(z-cam.getZ());
    float projected_y = cam.getY() + ((cam.getNearClip()-cam.getZ())*(y-cam.getY()))/(z-cam.getZ());
    
    return ofVec2f(projected_x, projected_y);
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
