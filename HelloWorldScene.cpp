#include "HelloWorldScene.h"
#include "Edge1.h"
#include "hero.h"
#include "Block.h"
#include "GameOverScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    // physics world
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0,-1000));
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void HelloWorld::update(float dt){
    for(auto it = gcs.begin(); it!= gcs.end(); it++)
    {
        (*it)->onUpdate();
        
    }
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    //white background
    if ( !LayerColor::initWithColor(Color4B(255,255,255,255) ))
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
//    gcs.pushBack(GameController::create(this, 30));
//    gcs.pushBack(GameController::create(this, 200));
//    gcs.pushBack(GameController::create(this, 370));
    //gcs.pushBack(GameController::create(this, 480));
    gcs.insert(0, GameController::create(this, 30));
    gcs.insert(0, GameController::create(this, 200));
    
    auto listener = EventListenerPhysicsContact::create();
    listener->onContactBegin = [this](PhysicsContact& contact){
        
        Director::getInstance()->replaceScene(TransitionFade::create(0.5, GameOver::createScene()));
        
        return true;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [this](Touch * touch, Event * event){
        
        for(auto it = gcs.begin(); it!= gcs.end(); it++)
        {
            //(*it)->hero->Jump();
            if((*it)->hitTestPoint(touch->getLocation()))
               {
                   (*it)->onTouch();
                   break;
               }
        }
        
        return false;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    scheduleUpdate();
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
