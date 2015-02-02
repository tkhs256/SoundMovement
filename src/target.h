//
//  target.h
//  Horror
//
//  Created by 高橋岳士 on 2015/02/02.
//
//

#ifndef __Horror__target__
#define __Horror__target__

#include <stdio.h>
#include "ofMain.h"
#include "waypoint.h"
class target{
public:
    waypoint w[50];
    float x;
    float y;
    float z;
    float vx;
    float vy;
    float vz;
    int num;
    float speed;
    bool isMoving;
    target(){
    
        x=y=z=vx=vy=vz=0;
        isMoving = false;
        speed = 0;
        num = 0;
    }
    void setup();
    void update();
    void play(waypoint w[],float speed);
};
#endif /* defined(__Horror__target__) */
