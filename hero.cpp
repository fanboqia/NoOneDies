#include "hero.h"

bool hero::init()
{
    Sprite::init();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    //repeat action forever
    runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("Hero.json", 0.3f)));
    
    setPhysicsBody(PhysicsBody::createBox(Size(44,52)));
    setContentSize(Size(44,52));
    
    //不旋转
    getPhysicsBody()->setRotationEnable(false);
    
    getPhysicsBody()->setContactTestBitmask(1);
    
    return true;
}

 void hero::Jump()
{
    getPhysicsBody()->setVelocity(Vec2(0,400));
}