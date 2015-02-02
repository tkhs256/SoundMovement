//
//  target.cpp
//  Horror
//
//  Created by 高橋岳士 on 2015/02/02.
//
//

#include "target.h"

void target::setup(){
    

}
void target::play(waypoint _w[50],float speed){
    int i;
    for(i = 0; i < 50; i ++){
        w[i] = _w[i];
    }
        vx = (w[num].x+w[num+1].x)/(speed*20);
        vy = (w[num].y+w[num+1].y)/(speed*20);
        vz = (w[num].z+w[num+1].z)/(speed*20);
    cout<<w[num+1].x<<endl;
    isMoving = true;
    num++;
}

void target::update(){
    if(isMoving){
        x += vx;
        y += vy;
        z += vz;
        ofSetColor(100,255,100);

        ofDrawSphere(x,y,z,50);
        
    }
}

