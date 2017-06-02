#ifndef __HERO_H__
#define __HERO_H__

#include <stdio.h>
#include "cocos2d.h"
#include "FlashTool.h"

USING_NS_CC;

class hero : public Sprite{
public:
    virtual bool init();
    CREATE_FUNC(hero);
    
    void Jump();
    
};

#endif // __HERO_H__
