#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <termios.h>
#include <vector>
#include "view.h"
#include "gameObject.h"

class Controller{

public:
       
    Controller(View&);
    void run();
	void setObjects(const std::vector<GameObject*>& objs) {
    _objs = objs;
}
private:

    void handleInput(int);
    void update();
	bool willCollide(const Position& targetPos, int ignoreIndex);
    bool checkGameOver();
    // Model
    std::vector<GameObject*> _objs;

    // View
    View& _view;
    int _controlledSnakeIndex = -1;	
    int _score = 0;
};

static struct termios old_termios, new_termios;
void reset_terminal();
void configure_terminal();
int read_input();

#endif
