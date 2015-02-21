#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "GameConstants.h"

class StudentWorld;

class Actor: public GraphObject {
public:
    Actor(StudentWorld* world, int imageID, int startX, int startY, Direction dir = none) : GraphObject(imageID, startX, startY, dir) {
        
        setVisible(true);
        m_isAlive = true;
        m_world = world;
        
    };
    
    virtual ~Actor() { };
    
    virtual void doSomething() = 0;
    
    StudentWorld* getWorld() const {
        return m_world;
    }
    
    bool isAlive() const {
        return m_isAlive;
    }
    
private:
    bool m_isAlive;
    StudentWorld* m_world;
    
    
    
};

/* classes with hitpoints */
class LivingActor : public Actor {
public:
    LivingActor(int health, StudentWorld* world, int imageID, int startX, int startY, Direction dir = none) : Actor(world, imageID, startX, startY, dir), m_health(health) {

        
    };
    
    virtual void doSomething() {
        
    }
    
    
    
    
private:
    int m_health;
};

class Player : public LivingActor {
    
public:
    Player(StudentWorld* world, int startX, int startY) : LivingActor(20, world, IID_PLAYER, startX, startY, right), m_ammo(20) { };
    
    virtual void doSomething();
    
    int getAmmo() const {
        return m_ammo;
    }
    
private:
    int m_ammo;
};

class Wall : public Actor {
public:
    Wall(StudentWorld* world, int startX, int startY) : Actor(world, IID_WALL, startX, startY, none) { };
    
    virtual void doSomething();
    
};



#endif // ACTOR_H_
