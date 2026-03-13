// TODO implementation



#include "gameObjectFactory.h"
#include "iconFactory.h"
#include "RPSGameObject.h"

std::vector<GameObject*> GameObjectFactory::create() {
	std::vector<GameObject*> objs;


	Icon redIcon = IconFactory::createRedIcon();

	RPSGameObject* r1 = new RPSGameObject(IconFactory::createRedIcon(1, 1), Position(8, 8));
	r1->setType(SNAKE);
	objs.push_back(r1);




	RPSGameObject* c1 = new RPSGameObject(IconFactory::createCyanIcon(1, 1), Position(2, 2));
	c1->setType(FOOD);
	objs.push_back(c1);

	RPSGameObject* c2 = new RPSGameObject(IconFactory::createCyanIcon(1, 1), Position(6, 4));
	c2->setType(FOOD);
	objs.push_back(c2);

	RPSGameObject* c3 = new RPSGameObject(IconFactory::createCyanIcon(1, 1), Position(4, 8));
	c3->setType(FOOD);
	objs.push_back(c3);

	RPSGameObject* c4 = new RPSGameObject(IconFactory::createCyanIcon(1, 1), Position(8, 12));
	c4->setType(FOOD);
	objs.push_back(c4);

	RPSGameObject* c5 = new RPSGameObject(IconFactory::createCyanIcon(1, 1), Position(17, 6));
	c5->setType(FOOD);
	objs.push_back(c5);

	RPSGameObject* c6 = new RPSGameObject(IconFactory::createCyanIcon(1, 1), Position(4, 18));
	c6->setType(FOOD);
	objs.push_back(c6);

	RPSGameObject* c7 = new RPSGameObject(IconFactory::createCyanIcon(1, 1), Position(13, 10));
	c7->setType(FOOD);
	objs.push_back(c7);

	RPSGameObject* c8 = new RPSGameObject(IconFactory::createCyanIcon(1, 1), Position(18, 12));
	c8->setType(FOOD);
	objs.push_back(c8);

	RPSGameObject* c9 = new RPSGameObject(IconFactory::createCyanIcon(1, 1), Position(18, 4));
	c9->setType(FOOD);
	objs.push_back(c9);

	RPSGameObject* c10 = new RPSGameObject(IconFactory::createCyanIcon(1, 1), Position(11, 11));
	c10->setType(FOOD);
	objs.push_back(c10);

	RPSGameObject* c11 = new RPSGameObject(IconFactory::createCyanIcon(1, 1), Position(7, 2));
	c11->setType(FOOD);
	objs.push_back(c11);







	RPSGameObject* g1 = new RPSGameObject(IconFactory::createGreenIcon(1, 1), Position(11, 2));
	g1->setType(OTHER_SNAKE);
	objs.push_back(g1);

	RPSGameObject* g2 = new RPSGameObject(IconFactory::createGreenIcon(1, 1), Position(2, 10));
	g2->setType(OTHER_SNAKE);
	objs.push_back(g2);


	RPSGameObject* g3 = new RPSGameObject(IconFactory::createGreenIcon(1, 1), Position(6, 18));
	g3->setType(OTHER_SNAKE);
	objs.push_back(g3);


	RPSGameObject* g4 = new RPSGameObject(IconFactory::createGreenIcon(1, 1), Position(17, 16));
	g4->setType(OTHER_SNAKE);
	objs.push_back(g4);

	RPSGameObject* g5 = new RPSGameObject(IconFactory::createGreenIcon(1, 1), Position(15, 7));
	g5->setType(OTHER_SNAKE);
	objs.push_back(g5);


	RPSGameObject* g6 = new RPSGameObject(IconFactory::createGreenIcon(1, 1), Position(12, 2));
	g6->setType(OTHER_SNAKE);
	objs.push_back(g6);

	RPSGameObject* g7 = new RPSGameObject(IconFactory::createGreenIcon(1, 1), Position(17, 17));
	g7->setType(OTHER_SNAKE);
	objs.push_back(g7);












	return objs;
}
