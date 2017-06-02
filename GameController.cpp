#include "GameController.h"

GameController* GameController::create(Layer* layer,float positionY)
{
    auto _ins = new GameController();
    _ins->init(layer, positionY);
    _ins->autorelease();
    return _ins;
}

bool GameController::init(Layer *layer, float positionY)
{
    _layer = layer;
    _positionY = positionY;
    visibleSize = Director::getInstance()->getVisibleSize();
    
    edge = Edge::create();
    edge->setPosition(visibleSize.width/2,visibleSize.height/2 + positionY);
    edge->setContentSize(visibleSize);
    layer->addChild(edge);
    
    //floor
    auto ground = Sprite::create();
    ground->setColor(Color3B(0,0,0));
    ground->setTextureRect(Rect(0,0,visibleSize.width,3));
    ground->setPosition(visibleSize.width/2,1.5 + positionY);
    layer->addChild(ground);
    
    hero = hero::create();
    hero->setPosition(Point(22,26 + positionY));
    layer->addChild(hero);
    
    resetFrames();
    
    return true;
}

void GameController::onUpdate()
{
    currentFrameIndex++;
    if(currentFrameIndex >= nexFrameCount)
    {
        resetFrames();
        
        addBlock();
    }
}

void GameController::resetFrames()
{
    currentFrameIndex = 0;
    nexFrameCount = rand()%120 +  100;
}

void GameController::addBlock()
{
        auto block = Block::create();
        block->setPositionY(block->getContentSize().height/2 + _positionY);
        _layer->addChild(block);
}

bool GameController::hitTestPoint(Vec2 point)
{
    return edge->getBoundingBox().containsPoint(point);
}

void GameController::onTouch()
{
    hero->getPhysicsBody()->setVelocity(Vec2(0,400));
}
