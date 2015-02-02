#pragma once

#include "ofMain.h"
#include <stdlib.h>
#include "waypoint.h"
#include "ofxGui.h"
#include "ofxUI.h"
#include "target.h"
#include "ofx3DModelLoader.h"
class ofApp : public ofBaseApp{
    
public:
    waypoint wp[50];
    target t;
    ofxUICanvas *gui;
    float posX;
    float posY;
    float posZ;
   

    
     bool isAdded;
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void exit();
    void guiEvent(ofxUIEventArgs &e);
    void Play(bool flag);
    ofx3DModelLoader model;
    ofxPanel gui_old;
    ofxButton add;
    ofxVec3Slider position;
    int i;
    ofEasyCam cam;
};
