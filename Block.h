#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class Block : public Sprite{
public:
    virtual bool init();
    CREATE_FUNC(Block);
    virtual void update(float dt);
    
};

#endif // __BLOCK_H__
