//
//  waypoint.cpp
//  Horror
//
//  Created by 高橋岳士 on 2015/01/18.
//
//

#include "waypoint.h"

void waypoint::moveWp(float _x,float _y, float _z){
    x = _x;
    y = _y;
    z = _z;
    sphere.setPosition(x, y, z);
}
void waypoint::setParam(float _x, float _y, float _z,int _num ,bool _isVisible){
    x = _x;
    y = _y;
    z = _z;
    color = ofColor(100,100,255);
    num = _num;
    isVisible = _isVisible;
    
}
void waypoint::drawWp(){
    if(isVisible){
        ofSetColor(color);
        ofFill();
        ofDrawSphere(x,y,z,40);
    }
    
    
}
//void waypoint::drawConnect(waypoint w){
//    if(w.isVisible){
//        ofLine(w.x,w.y,w.z,x,y,z);
//    }
//}