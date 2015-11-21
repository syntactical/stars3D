#pragma once

#include "ofMain.h"
#include "ofxVideoRecorder.h"

class ofApp : public ofBaseApp{
    public:
		void setup();
		void update();
		void draw();
    void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void drawStar(ofNode star);
        void drawAxes();
    void drawGrid(int limit);
    void drawStarAxes(ofNode star, int limit);
    ofVec3f translationPoint;
    
    int lastStarIndex;
    
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
    
        vector<ofNode> stars;
    
        ofEasyCam cam;
    
        float starXpoints [993] = { 1300,1300,1300,1800,2400,2500,2600,2600,2600,2600,3000,3200,3200,3300,3300,3400,3500,3500,3500,3500,3500,3600,3600,3600,3600,3600,3600,3800,3900,3900,4000,4000,4100,4100,4300,4300,4300,4300,4300,4400,4400,4400,4500,4500,4500,4500,4500,4500,4500,4600,4600,4700,4700,4700,4700,4800,4800,4900,4900,4900,4900,4900,5000,5000,5000,5000,5000,5100,5100,5100,5200,5200,5200,5400,5400,5400,5500,5500,5500,5500,5600,5700,5700,5700,5700,5700,5800,5800,5800,5800,5800,5900,5900,5900,5900,5900,5900,6000,6000,6000,6000,6000,6000,6100,6100,6100,6100,6100,6100,6100,6200,6200,6200,6200,6200,6200,6200,6200,6200,6300,6300,6300,6300,6400,6400,6400,6500,6500,6500,6500,6600,6600,6700,6700,6700,6800,6800,6800,6900,6900,7000,7000,7000,7000,7200,7200,7200,7200,7200,7300,7300,7400,7400,7500,7500,7500,7500,7500,7500,7500,7600,7600,7600,7600,7600,7600,7600,7700,7700,7700,7800,7800,7800,7800,7800,7800,7900,8000,8000,8000,8000,8000,8000,8000,8000,8100,8100,8100,8100,8100,8100,8100,8100,8100,8100,8100,8100,8100,8200,8200,8200,8200,8200,8200,8200,8200,8200,8300,8300,8400,8400,8400,8400,8400,8400,8500,8500,8500,8500,8500,8500,8500,8500,8500,8600,8600,8600,8600,8600,8600,8600,8700,8700,8700,8700,8700,8700,8800,8800,8800,8800,8800,8800,8800,8800,8800,8800,8800,8900,8900,8900,8900,8900,8900,8900,8900,9000,9000,9000,9000,9000,9000,9000,9000,9100,9100,9100,9200,9200,9200,9200,9200,9200,9200,9200,9200,9300,9300,9300,9300,9300,9400,9400,9400,9500,9500,9500,9500,9500,9500,9500,9500,9500,9600,9600,9600,9600,9600,9700,9700,9700,9800,9800,9800,9800,9800,9800,9800,9800,9800,9900,9900,9900,9900,9900,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,10100,10100,10100,10100,10100,10100,10100,10100,10200,10200,10200,10200,10200,10200,10200,10200,10200,10200,10200,10200,10200,10200,10200,10200,10200,10200,10200,10300,10300,10300,10300,10300,10300,10400,10400,10400,10400,10400,10400,10400,10400,10400,10400,10400,10400,10400,10500,10500,10500,10500,10500,10500,10500,10500,10500,10500,10600,10600,10700,10700,10700,10700,10700,10700,10700,10700,10700,10800,10800,10800,10800,10800,10800,10800,10800,10800,10800,10800,10800,10800,10800,10900,10900,10900,10900,10900,10900,10900,10900,11000,11000,11000,11000,11000,11000,11000,11100,11100,11100,11100,11100,11100,11100,11100,11100,11100,11100,11100,11100,11100,11100,11100,11200,11200,11200,11200,11200,11200,11200,11200,11200,11200,11200,11200,11200,11200,11200,11300,11300,11300,11300,11300,11300,11400,11400,11400,11400,11400,11400,11400,11400,11400,11400,11400,11400,11400,11500,11500,11500,11500,11500,11500,11500,11500,11500,11500,11500,11500,11500,11500,11600,11600,11600,11600,11600,11600,11600,11600,11600,11700,11700,11700,11700,11700,11800,11800,11800,11800,11800,11800,11800,11800,11800,11800,11800,11800,11800,11800,11800,11900,11900,11900,11900,11900,11900,11900,11900,11900,11900,12000,12000,12000,12000,12000,12000,12000,12000,12000,12000,12000,12000,12000,12000,12100,12100,12100,12100,12100,12100,12100,12200,12200,12200,12200,12200,12200,12200,12200,12200,12200,12300,12300,12300,12300,12300,12300,12300,12300,12300,12300,12300,12300,12300,12300,12300,12400,12400,12400,12400,12400,12500,12500,12500,12500,12500,12500,12500,12500,12500,12500,12500,12500,12500,12500,12500,12600,12600,12600,12600,12600,12600,12600,12600,12600,12600,12600,12700,12700,12700,12700,12700,12700,12700,12700,12700,12700,12700,12700,12700,12700,12700,12800,12800,12800,12800,12800,12800,12800,12800,12800,12800,12800,12800,12800,12800,12800,12800,12900,12900,12900,12900,12900,12900,12900,12900,12900,12900,12900,12900,12900,12900,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13000,13100,13100,13100,13100,13100,13100,13100,13100,13100,13100,13100,13100,13100,13100,13200,13200,13200,13200,13200,13200,13200,13200,13200,13200,13200,13200,13200,13300,13300,13300,13300,13300,13300,13300,13300,13300,13300,13300,13300,13300,13300,13400,13400,13400,13400,13400,13400,13400,13400,13400,13400,13400,13400,13500,13500,13500,13500,13500,13500,13500,13500,13500,13500,13500,13500,13600,13600,13600,13600,13600,13600,13600,13600,13700,13700,13700,13700,13700,13700,13700,13700,13700,13700,13700,13700,13700,13700,13700,13700,13700,13700,13700,13800,13800,13800,13800,13800,13800,13800,13800,13800,13900,13900,13900,13900,13900,13900,13900,13900,13900,13900,13900,13900,13900,13900,13900,13900,13900,13900,13900,14000,14000,14000,14000,14000,14000,14000,14000,14000,14000,14100,14100,14100,14100,14100,14100,14100,14100,14100,14100,14100,14100,14100,14100,14100,14100,14100,14100,14100,14100,14100,14200,14200,14200,14200,14200,14200,14200,14200,14200,14200,14200,14200,14200,14200,14300,14300,14300,14300,14300,14300,14300,14300,14300,14300,14300,14300,14300,14300,14300,14300,14300,14300,14300,14300,14400,14400,14400,14400,14400,14400,14400,14400,14400,14500,14500,14500,14500,14500,14500,14500,14500,14500,14500,14500,14500,14500,14500,14500,14500,14500,14500,14600,14600,14600,14600,14600,14600,14600,14600,14600,14600,14600,14600,14600,14600,14600,14600,14600,14600,14700,14700,14700,14700,14700,14700,14700,14700,14700,14700,14700,14700,14700,14700,14700,14700,14800,14800,14800,14800,14800,14800,14800,14800,14800,14800,14800,14800,14800,14900,14900,14900,14900,14900,14900,14900,14900,14900,14900,14900,14900,14900,14900,14900,14900,14900,14900,14900,14900,14900,14900,15000,15000,15000,15000,15000,15000,15000,15000,15000,15000,15000,15000,15000,15100,15100,15100,15100,15100,15100,15100,15100,15100,15100,15100,15100,15200,15200,15200,15200,15200,15200,15200,15200,15200,15200,15200,15200,15200,15200,15200,15200,15200,15300,15300,15300,15300,15300,15300,15300,15300,15300 };
    
        float starYpoints[993] = { 900,1000,1000,1500,-600,-1100,-1800,-1800,-600,-600,2900,-2100,-1000,0,1300,1300,-2800,-2800,0,500,500,-2900,-1500,-1500,-1000,0,2200,-3200,-1100,2800,-1000,-1000,-3400,-3400,-800,400,400,3300,3900,1000,-1300,-2500,3500,4300,-600,-2600,-2900,1400,-500,2000,1200,-100,900,900,1500,-2100,-2100,-2900,-2300,3300,4100,2900,-3700,-3700,-3700,4900,-900,4300,4300,3400,100,-3700,-3700,-2500,1600,-4800,-4600,-4600,-5300,3900,-1500,-4800,5300,5300,5300,5200,-5600,-3600,-5600,5100,-1000,-4700,-2800,4600,5200,4500,4500,-3200,-3200,5900,5900,5900,-200,-1000,-1100,4100,4500,5200,5200,-4900,1800,-4400,5200,-700,-700,-5100,5000,6200,6200,-4500,4800,1600,1600,700,-6000,1900,200,-5400,5900,-2200,-2300,600,3000,3000,2200,-5200,3700,2600,1200,300,6900,6900,6900,-1000,400,-4700,-4700,-2100,3300,2100,-700,4200,4200,7300,700,3300,-2100,5800,-4200,3300,-5800,2200,-4300,-4300,3100,-3800,-6500,3700,6600,3100,-7300,-2500,7000,2800,2200,-6300,800,-7300,-7200,-2100,-2100,1500,-1300,4500,4500,2900,2000,-2300,-1400,-4500,1900,2600,1400,1400,5500,-1700,2800,2800,-7100,-2900,-200,1200,3100,7100,3500,3500,7800,-8200,-4100,3200,-1500,4600,4600,4600,2100,-6200,900,-5300,-5300,4100,8000,8000,-3700,-5400,3300,-2200,5100,3500,3500,4400,-4800,-3200,-8200,-8600,-6900,-6900,1800,-6600,-6600,-6800,-7100,8300,8300,7400,5000,3500,-1800,2200,-5200,-5200,-2400,2600,5300,-5100,1900,5500,-6000,-5600,-5600,-2300,2100,-5100,1000,1200,-4400,800,7500,-6400,-6700,2900,2900,-2500,-2500,500,6000,-8100,-600,-8900,-6200,-6300,-8600,-5600,-3100,-9000,-6800,-300,2200,2200,-2700,2900,-1800,-7200,1500,2500,8500,8900,-8500,-9000,-4700,4900,-1200,-4400,4700,-7200,-9400,400,4700,8400,4300,9200,-100,7800,1500,-1900,9200,-1300,8200,-6300,-4000,-6500,-9700,-7400,3100,6000,6000,6000,-5200,-5200,2400,-5700,5700,8000,-3100,-2000,-2700,5800,2000,2000,-9100,-2300,2700,-3500,5200,4000,4000,8100,8100,4100,4100,-6700,-5700,1500,4700,-10300,-9300,-7300,5800,3800,-7800,-7700,-5100,4900,-5300,-9900,-3600,-3600,-500,-1300,-1300,-5700,-7400,7400,-800,-8500,1700,-3800,-3800,-6400,2900,-6300,-9200,2200,-2700,-8800,6700,800,-1400,-1400,9000,4900,4900,-600,3000,-5500,-10200,-10200,-6100,2700,5000,5000,9700,9500,9500,-5100,-5100,-7800,-5300,8000,-2000,0,600,500,-5900,3900,4300,-4800,-9700,-3700,200,-3000,6800,-100,5700,-8100,-4100,-2000,-1200,7400,6900,-7000,10000,4200,8600,-2700,-6700,-10700,2400,9600,-500,-900,-8600,-8600,-7400,-7400,300,2100,2100,-100,-100,9600,9600,9300,8000,-7400,-7400,3300,3900,-5200,5300,-10800,-10500,-6300,2000,2000,5300,-2400,6500,4200,4200,4300,5600,-6600,-600,-1000,1700,-10900,-4600,-10500,-9000,-4400,-7000,5100,-1500,-7000,4700,-1600,-2600,-10200,-10200,7100,8800,8700,-2800,-6900,2800,3800,-600,-7100,-3900,1400,-500,-4700,-4700,2700,2700,8200,6300,8100,9900,6500,1400,-9200,-10300,8100,9900,-8900,1900,-3700,-4300,-4300,7300,-8700,11100,10300,6700,-1400,2600,2600,4800,6100,6800,6800,-8000,-5100,-7500,-7500,3000,3000,4500,-7900,1300,1300,-10900,8900,9300,7900,5300,-2900,-11100,-3700,-7300,-10200,-4200,-4100,-4600,6600,-11600,-4000,10800,9600,-4500,4000,-3700,-6500,-11200,-12000,-7800,7700,5400,2900,3900,-8200,-2400,-3400,-3400,-12000,-1100,-7100,-11400,-9500,-9500,-2600,4100,1300,6500,-4700,-10400,-5100,-8700,-4300,4400,-6200,-9500,-6500,-12400,-5300,-7100,-8100,11000,11000,3100,11400,9600,8400,12000,-12500,-9700,-6800,8800,8800,-3500,3600,-11700,-10200,6800,4200,7200,10200,10700,-10600,-10000,-12000,1200,1200,12100,-1400,2400,900,3300,-100,-800,2900,-200,-12400,10600,-12300,-12300,-7200,-700,-700,5000,5000,1900,12100,2400,2400,11900,3900,-10900,4500,3500,12500,12600,-8100,-3700,-9900,-12600,-5100,9300,-1300,100,-1200,-12500,-12500,-200,11000,-3800,9100,2400,-4800,-1100,-11000,-9000,2900,-500,-12700,2500,1100,1100,100,12800,-6300,-11400,-7200,-5600,4800,7500,-4000,-11600,-8900,-9300,-9300,-800,12700,12700,2900,-12700,-8000,10600,-1700,5500,-1400,7700,-1700,1300,-400,-8400,-2400,5100,5100,9900,9900,8600,-10500,-10500,-12900,-9100,-9100,-9100,-3400,-8400,8400,6100,4900,3500,2800,2800,1200,7900,7900,-11800,11600,3400,-7100,-8200,-10200,-11400,-500,-4200,-3100,-4200,-4200,2500,2500,11600,11600,9300,9300,4900,-12800,-8700,-12800,-1500,-12800,3300,3300,8600,300,-6400,-400,1800,6800,-3200,-9700,-7700,9000,11800,12700,8600,2600,-1200,-13000,-2700,1900,7400,11800,6900,3300,3700,700,-2000,-13600,-10100,-6000,-12700,-1100,12200,3700,600,200,-5100,-5200,-5200,-12400,-6800,-6800,-6300,400,-200,-200,-200,12300,-4600,-6000,-3900,-1400,10000,4600,6400,6400,-7800,-11400,-10500,-10500,5600,5600,8500,7900,7900,12400,-1200,-8700,300,-400,10200,-13300,-14000,-10100,1100,2200,2200,6000,10700,-1900,-10000,-3000,-9900,-11000,-11300,-2800,6900,10400,11700,10400,-10700,-9400,3500,4400,4400,12100,6800,5500,-13400,13800,6500,3000,9200,-6900,6600,700,700,11700,12500,10700,-5300,-5300,-900,10700,9500,7000,9600,8600,-13000,-7800,-6800,-6800,-11000,-11000,-11000,-500,-500,12100,12600,12600,11300,6700,6700,-8200,1500,14100,-11500,-14300,-14200,-7300,10800,10800,13200,11200,9900,-11200,-12000,-4100,4800,6200,11200,4300,3300,-10200,-11900,-2900,-2900,4200,6700,9800,7400,8100,8500,-4100,5700,3000,-14000,1500,11800,-11700,-3200,-8700,-9200,-6700,-9500,-9500,-12500,-10300,6400,9200,7000,-3900,-4100,2400,1500,1200,13700,-6100,-1300,-6300,-11000,-7500,-7500,-7500,-8600,6500,6500,-2800,-11000,4100,7500,-10100,-2700,-4000,-3700,1700,-1200,10300,3200,2000,2000,9500,-3500,-14600,-9700,-5400,-5400,-600,-600,13700,13700,-8500,-12600,-10500,-10000,-3900,8000,7400,900,-4200,-13000,11500,-11500,-4100,-5100,-5100,14100,-5900};
   
        float starZpoints [993] = {-900,-900,-900,900,-1200,-100,-1900,-1900,100,100,600,-600,2800,-1700,100,1400,-1900,-1900,3200,3400,3500,-900,3000,3000,100,3300,-1000,-2000,-3000,200,3900,3900,-2200,-2200,-2500,-1300,-1300,-1600,200,-300,2000,-900,-1700,-1300,3800,1600,-2400,-4300,-3400,-4100,1700,1800,4600,4600,1900,400,400,700,-1700,-600,-2600,3200,-1400,-1400,-1400,-1200,4800,2500,2500,3800,1200,-1900,-1900,3400,-200,-2200,2900,2900,-300,2300,-2900,-2400,1000,1000,1000,-700,-1400,-4100,-300,-2400,5200,-3400,-5100,-1800,-2700,3800,3800,5000,5000,-200,-200,-200,3300,5200,-3200,-1600,-2600,500,500,-2400,-5800,1200,-500,4800,4800,-3200,-2400,-300,-300,1200,-500,4800,4800,-400,100,-6100,-2000,-3100,1200,6100,-1700,4800,1300,1300,5800,-3500,-2900,600,-6400,5400,-1000,-1000,-1000,6800,3700,1400,1400,-4500,-5700,5500,6400,5800,5800,1800,400,-4700,3400,-2300,3700,2800,3000,-1100,6100,6100,900,-1400,3200,-6200,3000,1100,-2200,-5400,3200,6800,-1200,3100,1000,-2900,-1500,-7400,-7400,5600,7600,4200,4200,-7100,4100,7000,-5600,6700,-2300,-4600,-3900,-3900,5000,6900,2100,7100,200,1800,7300,-2100,-1800,-1400,7200,7200,0,-1300,-4600,-7700,1500,6000,6000,6000,-7100,500,-3900,-4800,-4800,-4600,-2500,-2500,4400,2800,-4200,100,6900,2700,2700,-4900,-6100,-3000,-2100,-1300,-5300,-5300,2200,-5500,-5500,-3200,-3300,-2700,-2700,2100,6700,5100,-2500,-7500,-7200,-7200,-8500,-5800,7100,2900,-5800,-4000,-2000,-6000,-6000,-8000,-7700,7400,8300,2600,4100,1800,-4800,-5700,200,-8100,-8100,500,500,500,-3700,2300,9100,0,-5000,-4800,2600,6400,-400,0,-1800,-9400,-8200,-8200,-200,7700,-2000,-3400,7400,-1100,2300,-3500,1000,600,-6400,-8100,5700,-600,8200,4100,-2700,-9800,1600,2000,6200,-3000,900,1700,-1900,6400,2400,1000,4500,7700,1500,7600,1400,3100,6600,5400,700,-7300,8600,8600,-8600,8300,4000,6200,3100,5600,-8800,8300,-7000,-7000,4600,-1400,-8000,5400,-2400,2600,2600,1600,1600,5300,5300,4500,-3500,-10000,-6100,-500,-2000,2100,6100,6900,6700,900,-300,4000,-1100,3200,-1000,-1000,-3900,3600,3600,2300,5800,7200,-8200,6100,-10300,-8600,-8600,3800,-9400,8100,-700,3200,7600,4100,8300,-9000,8100,8200,4800,9600,9600,8100,8200,2700,-3500,-3500,9000,-4300,6500,6500,2700,3300,3300,9200,9200,6000,-2000,7400,-6200,-5300,2400,-5100,-9100,5800,4800,9600,-4700,1300,8600,9600,-3000,-6700,-3900,-4200,7300,-10900,-3400,-3100,3600,8500,2800,9200,7000,-900,3600,1300,-10900,-3800,6700,-8700,6900,6900,-1100,-1100,-11000,-1000,-1000,4500,4500,5400,5400,2900,7600,5500,5500,300,1000,3400,9600,-2700,-500,-5400,-2200,9700,-6300,-2800,-5300,9600,9600,10500,3400,-8400,-9200,-5000,-7400,900,10000,-500,4500,-10400,5500,2200,-11400,6000,7200,-10600,7200,1800,1800,-3700,7600,7100,6000,-9400,4600,10800,-9300,5600,-3100,6000,-100,10200,10300,-5000,-5000,-8500,3000,2300,-1900,5000,10600,7100,-1800,-8400,-1900,1600,11600,-4800,-1400,-1400,-3800,7700,-200,-3000,-1600,-8300,1000,1000,9700,-10400,7800,7800,9000,8000,-6900,-6900,-6800,-6800,8700,8700,-8100,-8100,-2400,-7600,-2400,5800,8000,10200,4400,-11600,-4000,4000,-11100,-10900,-800,-5500,-2200,-8300,-4900,-7500,2400,9400,6300,-5600,-600,-900,4000,-8300,10900,11300,-200,-6200,-3200,9600,9600,-2400,-8800,8400,4500,-2900,-2900,-9400,-11300,12400,4500,9800,200,-11400,5800,-10900,-11700,8300,-8000,-3700,2700,9200,-10000,8800,-3900,-3900,11100,-4900,6200,9000,4100,-800,-8100,-7400,5900,5900,-2400,-7500,-400,-6200,-7600,11100,-8200,5300,-6300,-6100,-4700,-3200,6800,6800,-4000,10600,9400,-9200,-8900,11400,10100,-100,-11100,3500,5200,3900,3900,3500,-10600,-10600,-11900,-11900,-8000,-4000,3900,3900,-200,-10400,-5400,-12200,-100,-2200,2800,10200,-1100,500,1500,6700,6100,8200,-7300,-9300,3900,3900,-300,-1500,9700,8900,12300,12200,-11900,3400,5900,1200,-800,300,1700,-10400,-10400,2300,3200,11200,5300,6400,7000,-600,9900,-11400,6500,-6300,-7000,-7000,4700,-500,-500,-200,-500,2400,-1900,10500,8400,4600,-3200,-8100,-4100,7100,10500,11900,12300,12300,-5600,-5600,-100,8500,8500,400,-1200,2400,2400,-3300,9400,7700,2200,-5000,-9400,7800,7800,-4300,-3000,-3000,5500,5300,11500,10600,10000,-900,6400,-13700,-10900,-10700,-7600,10700,1800,1800,-7400,-6700,9700,9700,12300,-2200,7100,3800,13300,3800,-700,-700,8000,8500,11600,8300,400,-1400,10500,6100,3700,-10400,400,-2600,4100,4200,2600,4800,-7700,7400,10900,7200,10900,9900,10400,-12600,-4600,300,5000,-2300,5800,6000,1000,7100,7600,-9000,11200,-5100,-5100,-4600,-200,-200,500,-700,11900,11900,11900,6900,13300,9300,-13500,8200,8800,12600,2400,2400,-4700,6700,-9300,-9300,-4500,-4500,-7100,4200,4200,3800,12900,-3500,-10200,-5800,-3700,900,-1800,5700,-2800,-1400,-1400,1200,7800,13900,9800,-3500,0,-400,-7600,2500,-300,-9200,-6100,-500,-9300,3600,3500,8500,8500,-7600,10100,13100,300,-3800,-12300,-300,-8700,-11200,-4600,10900,10900,8200,-5300,9600,4500,4500,-12200,-4300,500,3500,8200,9900,3500,-12100,-11900,-11900,1600,1600,1600,7300,7300,-7800,2200,2200,4400,10000,10000,-10600,-13800,-3500,-8700,-1800,-3400,8100,1800,1800,-6000,4100,-2400,-1800,-4000,-4400,-4200,-2900,-2000,11900,3700,600,-8400,-14000,-14000,-11000,-5900,7600,11200,-6300,-11400,13400,13500,-4200,-1200,13400,6700,-8700,-13500,-2300,1800,6300,11500,11500,5300,-3600,1400,10100,13100,14400,13500,4500,-8700,-12500,-1100,12500,-10400,-11700,-9100,-11500,-11500,-11500,12400,13000,13000,14500,4200,10300,-7100,-1600,-13700,-13900,5100,-4600,12100,11100,14700,14900,14900,-1500,-5200,3900,-10200,-14200,-14100,900,900,-5800,-5800,12300,7900,-1900,-3200,5900,7800,8800,5800,10500,7300,5400,7400,-1400,5100,5100,-5100,5900};
    
    string starNames [993] = {"Sol","Proxima Centauri","Rigel Kentaurus A","Rigel Kentaurus B","Barnard's Star","Gl 406","Lalande 21185","Sirius","Gl 244 B","UV Ceti A","UV Ceti B","Gl 729","18 Epsilon Eridani","Gl 905","Gl 447","Lacaille 9352","EZ Aquarii","Procyon","Gl 280 B","Gl 725 B","61 Cygni A","61 Cygni B","DX Cancri","GX Andromedae","GQ Andromedae","52 Tau Ceti","Gl 725","Epsilon Indi","Luyten's Star","Kapteyn's Star","Lacaille 8760","Kroger 60","DO Cephei","V577 Monocerotis A","V577 Monocerotis B","GJ 1061","FL Virginis A","FL Virginis B","Gl 563.2B","BD-12-4523","Gl 1","Van Maanen's Star","Hip 15689","Gl 563.2","Gl 674","Gl 687","Gl 83.1","NN 3522","Innes' Star","NN 3622","Gl 440","Hip 114110","GJ 1002","V1581 Cygni","GJ 1245 B","IL Aquarii","Gl 412","WX Ursae Majoris","Groombridge 1618","AD Leonis","Gl 832","Hip 82725","Hip 85605","40 Omicron 2 Eridani","40 Eridani B","DY Eridani","Gl 682","EV Lacertae","70 Ophiuchi","Gl 702 B","Altair","GJ 1005","GJ 1116","GJ 1116 B","Gl 445","BD+15-2620","NN 3379","Gl 169.1","Gl 169.1B","Hip 33226","Hip 103039","Gl 402","BD-03-1123","V1054 Ophiuchi","Gl 644 B","Gl 644 C","Gl 754","Gl 213","BD-21-1377","Gl 251","Gl 693","61 Sigma Draconis","YZ Canis Minoris","Gl 300","Gl 570","Gl 588","Gl 752","Gl 752 B","24 Eta Cassiopeiae","Gl 34 B","36 Ophiuchi","Gl 663 B","Gl 664","Gl 908","GJ 1221","82 Eridani","BD-11-3759","Delta Pavonis","Gl 783","Gl 783 B","NN 3323","GJ 1128","Gl 338","Gl 784","EQ Pegasi","Gl 896 B","NN 3454","NN 3877","Hip 86961","Hip 86963","Gl 338 B","BD-07-4003","BD+45-2505","Gl 661 B","GJ 2097","Gl 268","Hip 54298","GJ 1156","Gl 223.2","Gl 643","Gl 892","Gl 408","Gl 625","37 Xi Bootis","Gl 566 B","Gl 829","Gl 299","NN 4285","Hip 114176","Gl 293","BD+15-4733","Gl 667","Gl 667 B","Gl 667 C","Gl 809","GJ 1286","Gl 105","Gl 105 B","BD+01-2447","NN 3737","NN 3991","NN 4053","GJ 1230","GJ 1230 B","GJ 1224","GJ 2005","Beta Hydri","BD+04-123","BD-20-4123","107 Piscium","NN 4274","Gl 109","BD+11-2576","30 Mu Cassiopeiae","Gl 53 B","TW Piscis Austrini","NN 3193 B","NN 3378","Gl 480.1","BD+02-3312","Fomalhaut","GJ 1093","BD-03-2870","BD-03-4233","Vega","Gl 915","NN 3417","NN 3789","GJ 1087","1 Pi 3 Orionis","Gl 257","Gl 257 B","Gl 623","Gl 793","Gl 831","Gl 831 B","GJ 1123","GJ 1276","GJ 1289","GJ 2034","Gl 48","Gl 493.1","Gl 54","Gl 66","p Eridani","BD+18-3421","44 Chi Draconis","Gl 884","NN 4063","GJ 1105","GJ 1151","GJ 1227","Gl 486","Gl 518","Gl 595","Gl 747","Gl 747 B","Hip 93449","Gl 232","Hip 20968","Gl 438","8 Beta Canum Venaticorum","86 Mu Herculis","Gl 695 B","Gl 695 C","Hip 31292","GJ 1057","GJ 1154","BD-21-1051","Gl 185 B","61 Virginis","Gl 618","Gl 618 B","NN 3076","NN 3146","Zeta Tucanae","BD+36-2219","Gl 745","FK Aquarii","Gl 867 B","Gl 877","NN 3517","GJ 1054 B","Gl 203","54 Chi 1 Orionis","BD-05-1844","Gl 250 B","NN 3839","GJ 1103","GJ 1103 B","GJ 2069 B","Gl 183","41 Arae","Gl 666 B","Gl 785","HU Delphini","BD-05-5715","NN 3667","Hip 31293","Gl 283","Gl 283 B","Gl 318","Gl 465","Gl 745 B","NN 3128","NN 3707","NN 3820","23 Delta Eridani","13 Gamma Leporis","Gl 216 B","Gl 357","Gl 433","Gl 51","NN 4247","NN 4360","SZ Ursae Majoris","NN 3801","Hip 82724","GJ 2066","96 Kappa 1 Ceti","Gl 442","Gl 442 B","Groombridge 1830","CF Ursae Majoris","43 Beta Comae Berenices","Gamma Pavonis","NN 3421","GJ 1253","Gl 176","Gl 190","NN 3325","NN 3380","Gl 226","Gl 84","BD+18-683","GJ 1065","Gl 358","Gl 432","Gl 432 B","61 Ursae Majoris","BD+43-2796","NN 3135","NN 3306","NN 3988","GJ 1001","GJ 1207","Gl 633","NN 3253","NN 3275","GJ 1125","Gl 479","NN 3855","GJ 1138","GJ 1256","Gl 102","Gl 239","Gl 367","CE Bootis","12 Ophiuchi","BD+33-2777","Gl 680","GJ 2012","AU Microscopii","NN 3049","Wo 9492","Hip 84581","GJ 1028","BD+05-3409","Gl 75","NN 3119","NN 3126","NN 3304","NN 3512","NN 3959","NN 3976","NN 4248","Hip 76362","V547 Cassiopeiae","Gl 22 B","Alpha Mensae","BD+61-195","Gl 609","Gl 748","NN 3079","BD+62-1325","GJ 1129","GJ 1235","Gl 127.1","Gl 127.1B","BD+52-857","Gl 436","Gl 453","Gl 487","BD-01-2892","Gl 568","Gl 568 B","AT Microscopii","Gl 799 B","Gl 852","Gl 852 B","NN 3526","NN 3571","Hip 50798","Hip 117828","GJ 1083","Pollux","Gl 339.1","BD+25-3173","BD+00-4810","NN 3182","GJ 1119","GJ 1134","GJ 1265","Gl 117","Gl 170","53 Xi Ursae Majoris A","53 Xi Ursae Majoris B","Gl 452.1","Gl 508","Gl 508 B","Gl 87","NN 3147","NN 4071","GJ 2036 B","Iota Persei","Gl 341","Gl 352","Gl 352 B","BD+63-869","Gl 431","NN 3125","NN 3270","NN 3849","NN 3010","NN 3412","GJ 1232","Gl 413.1","Gl 617","Gl 617 B","BD+03-3465","Gl 766","Gl 766 B","NN 4333","Hip 109119","GJ 1041 B","BD+10-1032","Gl 228 B","Gl 47","BD+00-2989","40 Zeta Herculis","Gl 635 B","Gl 653","Gl 660","Gl 660 B","Gl 909","Gl 909 B","8 Delta Trianguli","NN 3192","GJ 1236","Gl 145","5 Beta Virginis","BD+36-2393","Gl 86","NN 3459","NN 3928","NN 4281","GJ 1004","GJ 1086","GJ 1148","GJ 1206","GJ 1238","Gl 545","NN 3210","GJ 1277","BD-11-916","54 Piscium","Gl 320","Denebola","Gl 553.1","41 Gamma Serpentis","Gl 63","Gl 654","BD+38-3095","BD+05-3993","Gl 79","NN 3140","NN 3396","NN 3592","NN 4078","GJ 1187","GJ 2036","13 Theta Persei","Gl 107 B","11 Leonis Minoris","Gl 356 B","Gl 370","Gl 505","Gl 505 B","Gl 537","Gl 537 B","Gl 754.1","Gl 754.1B","NN 3967","NN 4065","Gl 325","Gl 325 B","8 Eta Bootis","Arcturus","Gl 70","NN 4070","BD+11-878","Gl 277 B","Gl 361","DT Virginis","Gl 851","Gl 902","NN 3149 B","NN 3804","NN 4048","NN 4049 B","NN 4122","Wo 9520","Hip 29052","GJ 1075","CC Eridani","Gl 118","BD+21-652","BD+44-4548","VV Lyncis","Gl 277.1","Gl 317","Gl 362","Gl 567","NN 3500","NN 3550","NN 3966","Hip 48659","Gl 12","Gl 275.2","Gl 275.2B","Gl 540.2","Gl 735","Gl 772","NN 3039","NN 3442","NN 3873","GJ 1234","Zeta Doradus","Gl 360","BD+22-2302","BD+45-2247","GJ 2020","Gl 4","Gl 4 B","29 Gamma Virginis","Gl 482 B","Gl 542","Gl 585","27 Lambda Serpentis","Gl 773.6","49 Delta Capricorni","24 Iota Pegasi","NN 3266","Hip 21000","Hip 69454","Hip 98681","GJ 1055","GJ 1243","Gl 403","Gl 414","Gl 414 B","Gl 842","BD+47-612","NN 3954","NN 4106","Wo 9780","GJ 1140","GJ 1179","GJ 1179 B","GJ 1223","GJ 2092","Gl 669","Gl 669 B","Gl 82","NN 3060","NN 3331","NN 3332 B","NN 3727","NN 3728 B","NN 3992","GJ 1053","Zeta 1 Reticuli","Zeta 2 Reticuli","Gl 179","Zeta Trianguli Australis","Gl 798","Gl 821","GJ 1263","GJ 1288","Gl 211","Gl 309","Gl 359","NN 3435","NN 3518","NN 3533","NN 3647","NN 3800","BD+27-1348","Gl 381","Gl 590","Beta Trianguli Australis","Gl 64","Gl 671","NN 3052","NN 3263","NN 3285","NN 3333","NN 3567","NN 4004","NN 4098","NN 4201","NN 4350","Gl 180","Gl 91","85 Pegasi","Gl 914 B","NN 3356","GJ 1068","GJ 1101","Gl 212","55 Rho 1 Cancri","Gl 324 B","BD-09-3070","Gl 435","Gl 806","Gl 843","NN 3028","NN 3250","NN 3466","NN 3497","NN 3543","Hip 55042","GJ 1029","GJ 1097","Gl 142","15 Lambda Aurigae","Gl 26","BD-12-2449","BD+41-328","Gl 737","Gl 737 B","Gl 836.5","Hip 84051","GJ 1215","GJ 1248","GJ 2138","Gl 192","Gl 261","BD+06-2182","Gl 810","Gl 810 B","Gl 95","NN 3112","NN 3292","NN 3357","NN 3780","NN 4062","NN 4154","GJ 1210","GJ 1218","GJ 2045","GJ 2069","Gl 206","44 Bootis","Gl 575 B","Gl 620.1B","BD+67-1014","BD+08-4887","NN 3668","NN 3708","NN 4054","NN 4326","NN 4387","Hip 27887","GJ 1073","GJ 1214","Capella","Gl 194 B","36 Ursae Majoris","Gl 401","Gl 401 B","Gl 428","Gl 428 B","BD-09-3413","Gl 620.1","Gl 897","Gl 897 B","Hip 95326","GJ 1077","BD-03-1110","Gl 422","Gl 525","Gl 707","BD-21-5081","NN 3106","NN 3131","NN 3224","NN 3309","NN 3722","NN 3981","NN 4368","Gl 114.1","Gl 167","Gl 195","Gl 195 B","Gl 46","Gl 592","Gl 597","BD+02-4076","BD+27-4120","BD+57-2735","NN 3403","NN 3452","NN 3506","Hip 67593","GJ 1031","GJ 1092","GJ 1180","SZ Crateris","Gl 425 B","Gl 507","BD-18-4986","NN 3036","NN 3372 B","NN 3612","NN 3704","NN 3817","NN 4044","GJ 1088","Gl 164","58 Eridani","Gl 319","Gl 319 C","BD+46-1889","Gl 732","Gl 732 B","NN 3001","NN 3423","NN 3586","NN 3900","NN 3971","NN 4239","GJ 1012","GJ 1267","Gl 146","BD+09-2636","Gl 556","BD+63-229","Gl 742","BD+31-3767","Gl 767 B","Gl 774","Gl 774 B","NN 4224","Gl 130.1","Gl 130.1B","Gl 174","BD+36-1970","25 Theta Ursae Majoris","Gl 354 B","Gl 427","50 Upsilon Andromedae","Gl 655","Gl 868","NN 3009","NN 3709 B","GJ 1194","GJ 1194 B","Gl 469","Gl 853","Gl 853 B","NN 3371","NN 4006","NN 4040","GJ 1035","Gl 133","10 Tauri","BD+62-780","Gl 333","Gl 369","Gl 386","Gl 398","Gl 5","BD+27-2296","Gl 528 B","Gl 615","Gl 656","60 Beta Aquilae","Gl 771 B","Gl 813","NN 3326","NN 3520","Hip 19337","GJ 1270","Gl 162","Gl 516","Gl 516 B","Gl 816","ZZ Piscium","35 Gamma Cephei","17 Iota Piscium","NN 3779","GJ 1182","GJ 1292","Gl 310","Gl 394","Gl 524","BD-07-4156","Gl 739","Gl 836","Gl 898","NN 3053","NN 3336","NN 3637","NN 3898","NN 4055","NN 4056","NN 4169","NN 4279","Wo 9773","Hip 52596","GJ 1046","GJ 1072","Gl 104","1 Tau 1 Eridani","Gl 184","BD+50-2030","18 Scorpii","BD-07-5871","Gl 899","Hip 56157","GJ 1220","Alpha Fornacis","Gl 127 B","Gl 289","BD+39-2376","Gl 400 B","47 Ursae Majoris","Gl 42","26 Draconis","Gl 684 B","Gl 685","BD-03-4380","Gl 878","NN 3061 B","NN 3490 B","NN 3861","NN 4038","NN 4073","NN 4288","NN 4289 B","Hip 17420","Gl 116","Gl 282","Gl 282 B","Gl 512","Gl 512 B","Gl 529","Gl 589","Gl 589 B","Gl 770","Gl 875.1","NN 3564","NN 3655","NN 3693","Wo 9716","Gl 168.1","BD+17-917","3 Pi 1 Ursae Majoris","BD+16-2404","42 Alpha Comae Berenices","42 Alpha Comae Berenices","Gl 552","Rasalhague","3 Eta Cephei","NN 3136","NN 3148","NN 3211","NN 3237","NN 3467","NN 3729","NN 3846","NN 3943","NN 4060","Wo 9724","BD-02-2198","Gl 363","BD+30-2512","Gl 611","Gl 611 B","Gl 613","72 Herculis","Gl 794","NN 3438","Hip 81935","GJ 1157","GJ 1171","GJ 1177 B","BD-08-2582","Gl 521.1","Gl 630.1","Gl 630.1B","Gl 712","Gl 714","BD+04-4157","NN 3093","NN 3094 B","NN 3614","NN 3866","NN 3892","NN 3893","NN 3997","NN 4026","BD+25-613","Gl 259","Gl 326","Gl 326 B","9 Iota Ursae Majoris","Gl 331 B","Gl 331 C","23 Theta Bootis","Gl 549 B","Nu 2 Lupi","Gl 781.1","Gl 781.1B","Gl 796","NN 4203","NN 4204 B","Hip 28035","Hip 52190","Hip 82926","GJ 1099","111 Tauri","Gl 233","Gl 420","23 Psi Serpentis","Gl 596.1B","Gl 604","16 Psi Capricorni","Gl 833","NN 3252","NN 3305","NN 3649","NN 3775","NN 3809","NN 3894","NN 4228","GJ 1284","BD+01-543","Gl 231.3","Gl 269","Gl 269 B","1 Alpha Corvi","Gl 514.1","Gl 811.1","Gl 818","Gl 865","NN 3770","NN 4338 B","Hip 101516","GJ 1021","GJ 1096","GJ 1228","GJ 2128","BD+02-1729","Gl 364","20 Leonis Minoris","Gl 378","NN 3097","NN 3117","NN 3118 B","NN 3208","NN 3256","NN 3856","NN 4029","NN 4109","NN 4276","NN 4337","NN 4352","Hip 12261","Hip 25647","Hip 79431","Gl 14","Gl 163","Gl 218","16 Eta Leporis","Gl 225.2","Gl 225.2B","Gl 225.2C","Gl 52","Gl 738","Gl 738 B","Alderamin","NN 3181","NN 3965","GJ 1279","Gl 141","Gl 240","Gl 264.1B","Gl 483","Nu Phoenicis","19 Draconis","31 Aquilae","Gl 792","Gl 815","Gl 815 B","Gl 838.6","GJ 1050","GJ 1081","GJ 2070","Gl 288","Gl 288 B","Gl 40","Gl 40 B","Gl 599","Gl 599 B","NN 3069","NN 3213","NN 3235","NN 3247","NN 3753","NN 3953","NN 4216","NN 4367","GJ 1006 B","GJ 1059","GJ 1204","Gl 258","Gl 433.1","BD+55-1519","Gl 458 B","Mu Arae","NN 3084"};
};
