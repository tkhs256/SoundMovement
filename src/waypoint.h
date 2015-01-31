//
//  waypoint.h
//  Horror
//
//  Created by 高橋岳士 on 2015/01/18.
//
//

#ifndef Horror_waypoint_h
#define Horror_waypoint_h
#include "ofMain.h"

#pragma once


class waypoint : public ofBaseApp{
    
public:
    float x,y,z;
    int num;
    bool isVisible = false;

    void drawWp();
    void setParam(float _x , float _y , float _z,int _num ,bool _isVisible);
    void moveWp(float _x,float _y, float _z);
   // void drawConnect(waypoint w);
    ofColor color;
    ofSpherePrimitive sphere;
    
};


#endif
