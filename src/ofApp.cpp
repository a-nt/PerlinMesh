#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofEnableSmoothing();
    
    _cam.setPosition(0,0,300);
    _drawDebugStuff = false;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float w = 800.00;
    float h = 800.00;
    int yp = 160;
    int xp = 160;
    float yStep = h / yp;
    float xStep = w / xp;
    
    
    ofBackground(0);
    ofColor(255);
    
    _cam.begin();
    if (_drawDebugStuff) ofDrawGrid(1000, 10, 50, true, true, true);
    
    ofPushMatrix();
    
    ofTranslate(w/-2, h/-2);
    glPointSize(1);
    glBegin(GL_POINTS);
    
    for (int x=0; x<xp; x++) {
        for (int y=0; y<yp; y++) {
            float xPos = x*xStep;
            float yPos = y*yStep;
            float z = ofNoise(xPos/500.0f, yPos/500.0f, ofGetElapsedTimef()/2.5f )*200;
            z += ofNoise(xPos/300.0f, yPos/300.0f, ofGetElapsedTimef()/1.5f)*60;
            z += ofNoise(xPos/100.0f, yPos/100.0f, ofGetElapsedTimef())*20;
            z += ofNoise(xPos/40.0f, yPos/40.0f, ofGetElapsedTimef()*2)*2;
            glColor4f(1.0f, 1.0f, 1.0f, z / 120.0f); //282.0f
            glVertex3f(xPos, yPos, z);
        }
    }
    glEnd();
    
    ofPopMatrix();
    

    _cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == 100) // d
    {
        _drawDebugStuff = !_drawDebugStuff;
    }
    ofLog() << key << endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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