#include "Edge1.h"

bool Edge::init()
{
    Node::init();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    setPhysicsBody(PhysicsBody::createEdgeBox(visibleSize,PHYSICSBODY_MATERIAL_DEFAULT,3));
    setContentSize(visibleSize);
    return true;
}
