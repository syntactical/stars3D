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
        ofVec3f position = ofVec3f(ofRandom(-100,100),ofRandom(-100,100),ofRandom(-100,100));
        
        stars[i] = ofNode();
        stars[i].setPosition(position);
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

    cam.begin();
    
    translationPoint = ofVec3f(-100,-100,-100);
    
    ofPushMatrix();
    
//    ofRotateX(45);
//    ofRotateY(-angle);
    
//    ofDrawGrid(4000, 10, true);
    
    ofDrawAxis(1000);
    
    ofSetColor(ofColor::white, 40);
    
    for (vector<ofNode>::size_type i = 0; i < lastStarIndex; i++) {
        ofNode star = stars[i];
        
        ofPushMatrix();
    
        ofTranslate(star.getPosition());
        
        drawStarAxes(stars[i], 10000);
        drawStar(stars[i]);
        ofDrawBitmapString(starNames[i], stars[i].getPosition());
        
        ofPopMatrix();
    }
    
    ofVec3f constantPoint = cam.screenToWorld(ofVec3f(600, 600, 0));
    
    ofSetColor(ofColor::red, 200);
    
    ofNode lastStar = stars[lastStarIndex];
    
    //ofDrawGridPlane(400);
    
    drawStar(lastStar);
    drawStarAxes(lastStar, 10000);
    ofDrawBitmapString(starNames[lastStarIndex], lastStar.getPosition());
    ofPopMatrix();
    cam.end();
    
//    ofNode hjisaojodsa
    
    ofVec3f projectedStarCoords = cam.worldToScreen(lastStar.getGlobalPosition() * lastStar.getGlobalTransformMatrix());
    ofVec3f pr = cam.worldToScreen(stars[lastStarIndex].getPosition());
    ofLine(projectedStarCoords.x, projectedStarCoords.y, 700, 700);
    
    ofDrawBitmapString("projected coords", 100,80);
    
    ofDrawBitmapString(ofToString(pr.x), 100,100);
    ofDrawBitmapString(ofToString(pr.y), 100,125);
    ofDrawBitmapString(ofToString(pr.z), 100,150);
    
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

void ofApp::drawStar(ofNode node) {
    ofPushStyle();
    ofSetColor(ofColor::white);
    
    float diameter = 2;
    float radius = diameter / 2;
    
    ofPushMatrix();
    
    ofTranslate(node.getX(), node.getY(), node.getZ());
    
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

void ofApp::drawStarAxes(ofNode star, int limit){
//    ofPushStyle();
//    ofSetColor(ofColor::white);
//    ofLine(-limit, star.y, star.z, limit, star.y, star.z);
//    ofLine(star.x, -limit, star.z, star.x, limit, star.z);
//    ofLine(star.x, star.y, -limit, star.x, star.y, limit);
//    ofPopStyle();
}

ofVec2f ofApp::getProjectedCoords(float x, float y, float z, ofEasyCam cam) {
    float projected_x = translationPoint.x + ((cam.getNearClip()-translationPoint.z)*(x-translationPoint.x))/(z-translationPoint.z);
    float projected_y = translationPoint.y + ((cam.getNearClip()-translationPoint.z)*(y-translationPoint.y))/(z-translationPoint.z);
    
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
