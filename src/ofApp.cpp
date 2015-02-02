//--------------------------------------------------------------
#include "ofApp.h"
//--------------------------------------------------------------
int num;
bool isPressed = false;
bool flag = false;
ofVec2f colors;
void ofApp::setup(){
//      ofToggleFullscreen();
    ofBackground(255,255,255);
    cam.setDistance(600);
    num = 0;
    gui = new ofxUICanvas();
    gui->addSlider("BACKGROUND", 0, 255, 100);
    posX = 0;
    posY = 0;
    posZ = 0;
    gui->addLabel("press 'h' to hide menu");
    gui->add2DPad("PAD", ofPoint(-ofGetWidth(),ofGetWidth()), ofPoint(ofGetHeight(),-ofGetHeight()), ofPoint(posX,posZ));
    gui->addSlider("X", -ofGetWidth(), ofGetWidth(), &posX);
    gui->addSlider("Y", -ofGetHeight(), ofGetHeight(),&posY);
    gui->addSlider("Z", -ofGetWidth(), ofGetWidth(), &posZ);
    gui->addSlider("Camera Distance", 0, 2000, 600);
    
    gui->addButton("add", isAdded);
    gui->autoSizeToFitWidgets();
    
    ofAddListener(gui->newGUIEvent, this, &ofApp::guiEvent);
    gui ->loadSettings("settings.xml");
    
//    glClearDepth(1.0);
//    glClear(GL_DEPTH_BUFFER_BIT);
//    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LEQUAL);
//    
    model.loadModel("test.3ds",20);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofLight();

    cam.begin();
    glPushMatrix();
//    glTranslate(ofGetWidth()/2,ofGetHeight()/2);
    
    glPopMatrix();
 //   model.draw();
    glPushMatrix();
    int i = 0;
    for(i = 0 ; i < (sizeof(wp) / sizeof(wp[0]))-2;i++){
        wp[i].drawWp(wp[i+2]);
        
    }
    ofSetColor(255, 0, 0);
    ofLine(-ofGetWidth(), 0, 0, ofGetWidth(), 0, 0);
    ofLine(-ofGetWidth(), 0, ofGetWidth(), ofGetWidth(), 0, ofGetWidth());
    
    ofSetColor(0, 255, 0);

    ofLine(0, -ofGetHeight(), 0,0, ofGetHeight(), 0);
    ofSetColor(0, 0, 255);

    ofLine(0, 0, -ofGetWidth(), 0, 0, ofGetWidth());
    glPopMatrix();
    ofSetColor(150, 150, 150,150);
    ofFill();
    ofDrawSphere(posX, posY, posZ, 50);
    if(flag){
    Play(true);
    }else{
        Play(false);
    }
    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'h':
            gui -> toggleVisible();
            break;
        case ' ':
            flag = !flag;
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
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
//--------------------------------------------------------------

void ofApp::exit(){
    gui -> saveSettings("setting.xml");
    delete gui;
}
//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e){
    
    if(e.getName()=="BACKGROUND"){
        ofxUISlider *slider = e.getSlider();
        ofBackground(slider ->getScaledValue());
    
    }if(e.getName()=="PAD"){
        ofxUI2DPad *pad = (ofxUI2DPad *)e.widget;
        colors = pad ->getScaledValue();
        posX = colors.x;
        posY = colors.y;
        
       // ofBackground(colors.x, colors.y, 255);
    }if(e.getName() == "add"&&e.getButton()){
        if(num%2==0){
            wp[num].setParam(posX,posY,posZ, num/2, true);
            cout<<num/2;
        }
        num++;
        
    }if(e.getName()=="X"){
        ofxUISlider *slider = e.getSlider();
        posX = slider ->getScaledValue();
    }if(e.getName()=="Y"){
        ofxUISlider *slider = e.getSlider();
        posY = slider ->getScaledValue();

    }if(e.getName()=="Z"){
        ofxUISlider *slider = e.getSlider();
        posZ = slider ->getScaledValue();

    }if(e.getName()=="Camera Distance"){
        ofxUISlider *slider = e.getSlider();
        cam.setDistance(slider ->getScaledValue());
        
    }
}


void ofApp::Play(bool flag){
    if(flag){
        cout<<"read"<<endl;
        float X = 0;
        float Y = 0;
        float Z = 0;
        
        ofSetColor(100, 255, 100);
        ofDrawSphere(X, Y, Z, 50);
    }else{
    
    }

}
