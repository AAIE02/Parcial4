#include "ContactEventManager.hh"
#include "GameObject.hh"
#include<iostream>

ContactEventManager::ContactEventManager(std::vector<GameObject*>*& gameObjects, std::vector<GameObject*>*& gameObjectsDeleteList)
{
  this->gameObjects = gameObjects;
  this->gameObjectsDeleteList = gameObjectsDeleteList;
}

ContactEventManager::~ContactEventManager()
{
  
}

void ContactEventManager::BeginContact(b2Contact* contact)
{
  GameObject* actorA{(GameObject*)contact->GetFixtureA()->GetBody()->GetUserData().pointer};
  GameObject* actorB{(GameObject*)contact->GetFixtureB()->GetBody()->GetUserData().pointer};

  if(actorA && actorB)
  {
    std::cout << "Collision: " << actorA->GetTagName() << ", " << actorB->GetTagName() << std::endl;
    if(actorB->GetTagName().compare("chest1")==0)
    {
      gameObjectsDeleteList->push_back(actorB);
      std::cout<< "Recolectaste todos los cofres de esta zona, !!!enhorabuena!!!" << std::endl;
    }
    std::cout << "Collision: " << actorA->GetTagName() << ", " << actorB->GetTagName() << std::endl;
    if(actorB->GetTagName().compare("chest2")==0)
    {
      gameObjectsDeleteList->push_back(actorB);
      std::cout<< "Recolectaste el 1er cofre" << std::endl;
    }
    if(actorB->GetTagName().compare("enemy") == 0)
    {
      gameObjectsDeleteList->push_back(actorA);
      std::cout << "!CAGASTE!" << std::endl;
    }
    
  }
}

void ContactEventManager::EndContact(b2Contact* contact)
{

}