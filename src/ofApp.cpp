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
   
    cam.orbit(angle, -20, 300);
    
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
    
    ofPopStyle();

    cam.end();
    
    drawStarDiagnostics(ofVec2f(ofGetWidth()-300, ofGetHeight() -150), lastStar, starNames[lastStarIndex]);
    
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

void ofApp::drawStarDiagnostics(ofVec2f startPoint, ofNode star, string starName){
    
    
    ofVec3f projectedStarCoords = cam.worldToScreen(star.getPosition());
    
    ofLine(projectedStarCoords.x, projectedStarCoords.y, startPoint.x, startPoint.y);
    
    
    ofPushMatrix();
    ofTranslate(startPoint);
    
    ofPushStyle();
    ofSetColor(ofColor::red);
    ofDrawBitmapString(starNames[lastStarIndex], 2, 5);
    ofPopStyle();
    
    ofDrawBitmapString("projected coords", 10,30);
    
    ofDrawBitmapString(ofToString(projectedStarCoords.x), 10,60);
    ofDrawBitmapString(ofToString(projectedStarCoords.y), 10,80);
    ofDrawBitmapString(ofToString(projectedStarCoords.z), 10,100);
    
    ofDrawBitmapString("actual coords", 180,30);
    ofDrawBitmapString(ofToString(star.getX()), 180,60);
    ofDrawBitmapString(ofToString(star.getY()), 180,80);
    ofDrawBitmapString(ofToString(star.getZ()), 180,100);
    
    ofPopMatrix();
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
