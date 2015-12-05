#include "ofApp.h"
#define NUMBER_OF_STARS 993
//--------------------------------------------------------------

void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    ofBackground(ofColor::black);
    ofNoFill();
    
    ofSetFrameRate(60);
    
    for (vector<ofPoint>::size_type i = 0; i < NUMBER_OF_STARS; i++) {
        ofNode star;
        ofVec3f position = ofVec3f(ofRandom(-100,100),ofRandom(-100,100),ofRandom(-100,100));
        star.setPosition(position);
        stars.push_back(star);
    }
    
    lastStarIndex = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (ofRandom(100) < 5) {
        lastStarIndex = ofClamp(lastStarIndex + 1, 0, NUMBER_OF_STARS - 1);
    }
}

void ofApp::exit() {
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    ofEnableDepthTest();
    
    float time = ofGetElapsedTimef();
    float angle = time * 10;
    
    cam.begin();
    
    if (ofGetFrameNum() == 0) {
        cam.rotate(45, ofVec3f(1,0,0));
    }
    
    ofDrawGrid(4000, 10, true);
    
    for (vector<ofNode>::size_type i = 0; i < lastStarIndex; i++) {
        ofNode star = stars[i];
        
        ofPushStyle();
        
        ofSetColor(ofColor::white, 200);
        
        drawStarAndAxes(star);
        ofDrawBitmapString(starNames[i], star.getPosition());
        
        ofPopStyle();
    }
    
    ofNode lastStar = stars[lastStarIndex];
    
    ofPushStyle();
    
    ofSetColor(ofColor::red);
    
    drawStarAndAxes(lastStar);
    ofDrawBitmapString(starNames[lastStarIndex], lastStar.getPosition());
    
    ofPopStyle();
    
    ofVec3f projectedStarCoords = cam.worldToScreen(lastStar.getPosition());

    cam.end();
    
    ofLine(projectedStarCoords.x, projectedStarCoords.y, 700, 700);
    
    ofDrawBitmapString("projected coords", 100,80);
    
    ofDrawBitmapString(ofToString(projectedStarCoords.x), 100,100);
    ofDrawBitmapString(ofToString(projectedStarCoords.y), 100,125);
    ofDrawBitmapString(ofToString(projectedStarCoords.z), 100,150);
    
    ofDrawBitmapString("actual coords", 250,80);
    ofDrawBitmapString(ofToString(lastStar.getX()), 250,100);
    ofDrawBitmapString(ofToString(lastStar.getY()), 250,125);
    ofDrawBitmapString(ofToString(lastStar.getZ()), 250,150);
    
    ofDrawBitmapString(starNames[lastStarIndex], 100, 50);
    
    ofDisableAlphaBlending();
    ofDisableDepthTest();
    
}

void ofApp::drawAxes(){
    ofPushStyle();
    ofSetColor(ofColor::white, 100);
    ofLine(-1000, 0, 0, 1000, 0, 0);
    ofLine(0, -1000, 0, 0, 1000, 0);
    ofLine(0, 0, -1000, 0, 0, 1000);
    ofPopStyle();
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

void ofApp::drawStarAndAxes(ofNode star) {
    ofPushMatrix();
    ofTranslate(star.getPosition());
    drawStar(star);
    drawStarAxes(star, 1000);
    ofPopMatrix();
}

void ofApp::drawStar(ofNode node) {
    ofPushStyle();
    ofSetColor(ofColor::white);
    
    float diameter = 2;
    float radius = diameter / 2;
    
    ofLine(-diameter, 0, 0, diameter, 0, 0);
    ofLine(0, -diameter, 0, 0, diameter, 0);
    ofLine(0, 0, -diameter, 0, 0, diameter);
    
    ofCircle(0, 0, 0, radius);
    
    ofPushMatrix();
    ofRotateY(90);
    ofCircle(0, 0, 0, radius);
    ofPopMatrix();
    
    ofPushMatrix();
    ofRotateZ(90);
    ofCircle(0, 0, 0, radius);
    ofPopMatrix();
    
    ofPopStyle();
}

void ofApp::drawStarAxes(ofNode star, int limit){
    ofPushStyle();
    ofSetColor(ofColor::white, 40);
    ofLine(-limit, 0, 0, limit, 0, 0);
    ofLine(0, -limit, 0, 0, limit, 0);
    ofLine(0, 0, -limit, 0, 0, limit);
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    /*
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
    */
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
