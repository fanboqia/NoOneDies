#ifndef __GAMECONTROLLER_H__
#define __GAMECONTROLLER_H__

#include <stdio.h>
#include "cocos2d.h"
#include "Edge1.h"
#include "hero.h"
#include "Block.h"
USING_NS_CC;

int globalVar = 0;

class GameController : public Ref{
public:
    
    static int counter;
    
    virtual bool init(Layer *layer, float positionY);
    static GameController* create(Layer* layer, float positionY);
    //CREATE_FUNC(GameController);
    void onUpdate();
    int currentFrameIndex;
    int nexFrameCount;
    bool hitTestPoint(Vec2 point);
    hero *hero;
    void onTouch();
    
private:
    Edge *edge;
    Size visibleSize;
    Layer *_layer;
    float _positionY;
    

    void addBlock();
    void resetFrames();
};

static int counter = 0;

#endif // __BLOCK_H__
