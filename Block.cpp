#include "Block.h"

bool Block::init()
{
    Sprite::init();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    Size size = Size(rand()%20+5, rand()%30+10);
    
    setPhysicsBody(PhysicsBody::createBox(size));
    setTextureRect(Rect(0,0,size.width,size.height));
    setColor(Color3B(0,0,0));
    setContentSize(size);
    
    setPositionX(visibleSize.width);
    scheduleUpdate();
    
    //平滑移动 不受重力影响
    getPhysicsBody()->setDynamic(false);
    
    getPhysicsBody()->setContactTestBitmask(1);
    
    return true;
}

void Block::update(float dt)
{
    this->setPositionX(getPositionX()-8);
    
    if(getPositionX() < 0){
        unscheduleUpdate();
        removeFromParent();
    }
}