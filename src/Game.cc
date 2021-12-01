#include "CommonHeaders.hh"
#include "Player.hh"
#include "TileGroup.hh"
#include "Enemy.hh"


sf::CircleShape* circle{new sf::CircleShape()};

TextObject* textObj1{new TextObject(ASSETS_FONT_ARCADECLASSIC, 14, sf::Color::White, sf::Text::Bold)};

sf::Clock* gameClock{new sf::Clock()};
float deltaTime{};
Player* player1{};
Enemy* enemy{};
Enemy* enemy1{};
Enemy* enemy2{};
//GameObject* Enemy{};
GameObject* chest1{};
GameObject* chest2{};
GameObject* light1{};
GameObject* Techo{};
GameObject* Techo1{};
GameObject* Techo2{};
GameObject* Techo3{};
GameObject* Techo4{};
GameObject* Techo5{};
GameObject* Techo6{};
GameObject* Techo7{};
GameObject* Techo8{};
GameObject* Piso{};
GameObject* Piso1{};
GameObject* Piso2{};
GameObject* Piso3{};
GameObject* Piso4{};
GameObject* Piso5{};
GameObject* Piso6{};
GameObject* Piso7{};
GameObject* Piso8{};
GameObject* Pared3{};
GameObject* Pared4{};
GameObject* Pared5{};
GameObject* Pared6{};
GameObject* Pared7{};
GameObject* Pared8{};
GameObject* Plat{};
GameObject* Plat1{};
GameObject* Plat2{};
GameObject* Plat3{};
GameObject* Plat4{};
GameObject* Plat5{};
GameObject* Pared9{};
GameObject* Pared10{};
GameObject* Pared11{};
GameObject* Pared12{};
GameObject* Pared13{};
GameObject* Pared14{};
//GameObject* Antorcha{};

TileGroup* tileGroup{};
Tile* tile1{};

uint32 flags{};
    //flags += b2Draw::e_aabbBit;
    //flags += b2Draw::e_shapeBit;
    //flags += b2Draw::e_centerOfMassBit;
    //flags += b2Draw::e_pairBit;
    //flags += b2Draw::e_jointBit;

Game::Game()
{
  window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_NAME);
  event = new sf::Event();
  gravity = new b2Vec2(0.f, 0.f);
  world = new b2World(*gravity);
  drawPhysics = new DrawPhysics(window);
  gameObjects = new std::vector<GameObject*>();
  gameObjectsDeleteList = new std::vector<GameObject*>();

  player1 = new Player(ASSETS_SPRITES, 4.f, 16, 16, 0, 5, 13, 640, 200.f, b2BodyType::b2_dynamicBody, world, window);
  player1->SetTagName("Player");
  //Enemy = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 0, 2, 170, 280,  b2BodyType::b2_staticBody, world, window);
  //Enemy->SetTagName("Enemigo");
  enemy1 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 0, 270, 280, 100.f, b2BodyType::b2_dynamicBody, world, window, 2.f, sf::Vector2f(1, 0));
  enemy1->SetTagName("enemy");
  enemy2 = new Enemy(ASSETS_SPRITES, 4.f, 16, 16, 0, 0, 270, 450, 100.f, b2BodyType::b2_dynamicBody, world, window, 2.f, sf::Vector2f(1, 0));
  enemy2->SetTagName("enemy");
  chest1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 1, 85, 280, b2BodyType::b2_staticBody, world, window);
  chest1->SetTagName("chest1");
  chest2 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 1, 680, 675, b2BodyType::b2_staticBody, world, window);
  chest2->SetTagName("chest2");
  light1 = new GameObject(ASSETS_SPRITES, 4.f, 16, 16, 6, 3, 85, 80, b2BodyType::b2_staticBody, world, window);
  light1->SetTagName("light");
  Techo = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 1, 1, b2BodyType::b2_staticBody, world, window);
  Techo->SetTagName("Techo");
  Techo1 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 100, 1, b2BodyType::b2_staticBody, world, window);
  Techo1->SetTagName("Techo");
  Techo2 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 200, 1, b2BodyType::b2_staticBody, world, window);
  Techo2->SetTagName("Techo");
  Techo3 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 300, 1, b2BodyType::b2_staticBody, world, window);
  Techo3->SetTagName("Techo");
  Techo4 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 400, 1, b2BodyType::b2_staticBody, world, window);
  Techo4->SetTagName("Techo");
  Techo5 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 500, 1, b2BodyType::b2_staticBody, world, window);
  Techo5->SetTagName("Techo");
  Techo6 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 600, 1, b2BodyType::b2_staticBody, world, window);
  Techo6->SetTagName("Techo");
  Techo7 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 700, 1, b2BodyType::b2_staticBody, world, window);
  Techo7->SetTagName("Techo");
  Techo8 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 800, 1, b2BodyType::b2_staticBody, world, window);
  Techo8->SetTagName("Techo");
  Piso = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 1, 707, b2BodyType::b2_staticBody, world, window);
  Piso->SetTagName("Piso");
  Piso1 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 100, 707, b2BodyType::b2_staticBody, world, window);
  Piso1->SetTagName("Piso");
  Piso2 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 200, 707, b2BodyType::b2_staticBody, world, window);
  Piso2->SetTagName("Piso");
  Piso3 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 300, 707, b2BodyType::b2_staticBody, world, window);
  Piso3->SetTagName("Piso");
  Piso4 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 400, 707, b2BodyType::b2_staticBody, world, window);
  Piso4->SetTagName("Piso");
  Piso5 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 500, 707, b2BodyType::b2_staticBody, world, window);
  Piso5->SetTagName("Piso");
  Piso6 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 600, 707, b2BodyType::b2_staticBody, world, window);
  Piso6->SetTagName("Piso");
  Piso7 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 701, 707, b2BodyType::b2_staticBody, world, window);
  Piso7->SetTagName("Piso");
  Piso8 = new GameObject(ASSETS_TILES, 4.f, 25, 25, 0, 0, 801, 707, b2BodyType::b2_staticBody, world, window);
  Piso8->SetTagName("Piso");
  Pared3 = new GameObject(ASSETS_TILES, 4.f, 20, 35, 0, 0, 13, 410, b2BodyType::b2_staticBody, world, window);
  Pared3->SetTagName("Pared");
  Pared4 = new GameObject(ASSETS_TILES, 4.f, 20, 35, 0, 0, 13, 330, b2BodyType::b2_staticBody, world, window);
  Pared4->SetTagName("Pared");
  Pared5 = new GameObject(ASSETS_TILES, 4.f, 20, 35, 0, 0, 13, 280, b2BodyType::b2_staticBody, world, window);
  Pared5->SetTagName("Pared");
  Pared6 = new GameObject(ASSETS_TILES, 4.f, 20, 35, 0, 0, 13, 190, b2BodyType::b2_staticBody, world, window);
  Pared6->SetTagName("Pared");
  Pared7 = new GameObject(ASSETS_TILES, 4.f, 20, 35, 0, 0, 13, 100, b2BodyType::b2_staticBody, world, window);
  Pared7->SetTagName("Pared");
  Pared8 = new GameObject(ASSETS_TILES, 4.f, 20, 35, 0, 0, 13, 50, b2BodyType::b2_staticBody, world, window);
  Pared8->SetTagName("Pared");
  Plat = new GameObject(ASSETS_TILES, 4.f, 20, 25, 0, 0, 90, 310, b2BodyType::b2_staticBody, world, window);
  Plat->SetTagName("Plataforma");
  Plat1 = new GameObject(ASSETS_TILES, 4.f, 20, 25, 0, 0, 165, 310, b2BodyType::b2_staticBody, world, window);
  Plat1->SetTagName("Plataforma");
  Plat2 = new GameObject(ASSETS_TILES, 4.f, 20, 25, 0, 0, 240, 310, b2BodyType::b2_staticBody, world, window);
  Plat2->SetTagName("Plataforma");
  Plat3 = new GameObject(ASSETS_TILES, 4.f, 20, 25, 0, 0, 390, 400, b2BodyType::b2_staticBody, world, window);
  Plat3->SetTagName("Plataforma");
  Plat4 = new GameObject(ASSETS_TILES, 4.f, 20, 25, 0, 0, 470, 400, b2BodyType::b2_staticBody, world, window);
  Plat4->SetTagName("Plataforma");
  Plat5 = new GameObject(ASSETS_TILES, 4.f, 20, 25, 0, 0, 600, 500, b2BodyType::b2_staticBody, world, window);
  Plat5->SetTagName("Plataforma");
  Pared9 = new GameObject(ASSETS_TILES, 4.f, 20, 35, 0, 0, 750, 410, b2BodyType::b2_staticBody, world, window);
  Pared9->SetTagName("Pared");
  Pared10 = new GameObject(ASSETS_TILES, 4.f, 20, 35, 0, 0, 750, 330, b2BodyType::b2_staticBody, world, window);
  Pared10->SetTagName("Pared");
  Pared11 = new GameObject(ASSETS_TILES, 4.f, 20, 35, 0, 0, 750, 280, b2BodyType::b2_staticBody, world, window);
  Pared11->SetTagName("Pared");
  Pared12 = new GameObject(ASSETS_TILES, 4.f, 20, 35, 0, 0, 750, 640, b2BodyType::b2_staticBody, world, window);
  Pared12->SetTagName("Pared");
  Pared13 = new GameObject(ASSETS_TILES, 4.f, 20, 35, 0, 0, 750, 560, b2BodyType::b2_staticBody, world, window);
  Pared13->SetTagName("Pared");
  Pared14 = new GameObject(ASSETS_TILES, 4.f, 20, 35, 0, 0, 750, 480, b2BodyType::b2_staticBody, world, window);
  Pared14->SetTagName("Pared");
  //Antorcha = new GameObject(ASSETS_TILES, 4.f, 25, 25, 8, 6, 350, 550, b2BodyType::b2_staticBody, world, window);
  //Antorcha->SetTagName("Antorcha");

  tileGroup = new TileGroup(window, 12, 12, ASSETS_MAPS, 4.f, 16, 16, ASSETS_TILES);
  contactEventManager = new ContactEventManager(gameObjects, gameObjectsDeleteList);
}

Game::~Game()
{
}

//Starting things
void Game::Start()
{
  flags += b2Draw::e_shapeBit;
  world->SetDebugDraw(drawPhysics);
  drawPhysics->SetFlags(flags);
  world->SetContactListener(contactEventManager);

  AddGameObject(player1);
  AddGameObject(enemy1);
  AddGameObject(enemy2);
  AddGameObject(chest1);
  AddGameObject(chest2);
  AddGameObject(light1);
  AddGameObject(Techo);
  AddGameObject(Techo1);
  AddGameObject(Techo2);
  AddGameObject(Techo3);
  AddGameObject(Techo4);
  AddGameObject(Techo5);
  AddGameObject(Techo6);
  AddGameObject(Techo7);
  AddGameObject(Techo8);
  AddGameObject(Piso);
  AddGameObject(Piso1);
  AddGameObject(Piso2);
  AddGameObject(Piso3);
  AddGameObject(Piso4);
  AddGameObject(Piso5);
  AddGameObject(Piso6);
  AddGameObject(Piso7);
  AddGameObject(Piso8);
  AddGameObject(Pared3);
  AddGameObject(Pared4);
  AddGameObject(Pared5);
  AddGameObject(Pared6);
  AddGameObject(Pared7);
  AddGameObject(Pared8);
  AddGameObject(Plat);
  AddGameObject(Plat1);
  AddGameObject(Plat2);
  AddGameObject(Plat3);
  AddGameObject(Plat4);
  AddGameObject(Plat5);
  AddGameObject(Pared9);
  AddGameObject(Pared10);
  AddGameObject(Pared11);
  AddGameObject(Pared12);
  AddGameObject(Pared13);
  AddGameObject(Pared14);
  //AddGameObject(Antorcha);

  textObj1->SetTextStr("Dungeon Jump");

  /*circle->setRadius(2.f);
  circle->setFillColor(sf::Color::Green);
  circle->setOutlineColor(sf::Color::Green);*/
}

void Game::Initialize()
{
  Start();
  MainLoop();
}

void Game::UpdatePhysics()
{
  world->ClearForces();
  world->Step(deltaTime, 8, 8);
}

//Logic, animations, etc
void Game::Update()
{
  deltaTime = gameClock->getElapsedTime().asSeconds();
  gameClock->restart();

  for(auto &gameObject : *gameObjects)
  {
    gameObject->Update(deltaTime);
  }

  //circle->setPosition(player1->GetSprite()->getPosition());

  //lightIdle->Play(deltaTime);

  /*if(std::abs(InputSystem::Axis().x) > 0 || std::abs(InputSystem::Axis().y) > 0)
  {
    runAnimation->Play(deltaTime);
  }
  else
  {
    idleAnimation->Play(deltaTime);
  }*/
}

void Game::MainLoop()
{
  while (window->isOpen())
  {
    while(window->pollEvent(*event))
    {
      if(event->type == sf::Event::Closed)
      {
        window->close();
      }
    }

    UpdatePhysics();
    Input();
    Update();
    Render();
  }
  Destroy();
}

void Game::Render()
{
  for(auto& gameobject: *gameObjectsDeleteList)
  {
      gameObjects->erase(std::remove(gameObjects->begin(), gameObjects->end(), gameobject), gameObjects->end());
      delete gameobject;
  }
  gameObjectsDeleteList->clear();

  window->clear(sf::Color::Black);
  Draw();
  window->display();
}

//Drawing sprites or geometry.
void Game::Draw()
{
  //player1->Draw();
  //window->draw(*circle);

  tileGroup->Draw();

  for(auto &gameObject : *gameObjects)
  {
    gameObject->Draw();
  }

  window->draw(*textObj1->GetText());
  //world->DebugDraw();
}

//Keyboard, joysticks, etc.
void Game::Input()
{
}

void Game::Destroy()
{
  delete window;
  delete event;
}

void Game::AddGameObject(GameObject* gameObject)
{
  gameObjects->push_back(gameObject);
}