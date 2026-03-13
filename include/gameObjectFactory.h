// TODO 
// Finish the declaration of GameObjectFactory that
// 1. offers some methods to create a GameObject.
// 2. encapsulates the constructor from the caller. 


#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H

#include <vector>
#include "gameObject.h"


class GameObjectFactory {
public:

	static std::vector<GameObject*> create();


};

#endif
