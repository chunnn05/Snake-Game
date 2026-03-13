#include <iostream>
#include <ctime>
#include <thread>
#include <unistd.h>
#include <termios.h>

#include "environment.h"
#include "controller.h"
#include "gameObjectFactory.h"
#include "RPSGameObject.h"



bool Controller::willCollide(const Position& targetPos, int ignoreIndex) {
	for (size_t i = 0; i < _objs.size(); ++i) {
		if ((int)i == ignoreIndex) continue; 
		if (_objs[i]->getPosition() == targetPos) {
			return true;
		}
	}
	return false;
}



Controller::Controller(View& view) : _view(view){
}

void Controller::run() {


	_objs = GameObjectFactory::create();

	// 找到第一個 Rock 當作初始控制對象
	for (size_t i = 0; i < _objs.size(); ++i) {
		if (_objs[i]->getIcon()[0][0].getColor() == RED) {
			_controlledSnakeIndex = i;
			break;
		}
	}

	srand(time(0));
	// initial setup
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);
	configure_terminal();

	// init state
	int input = -1;
	clock_t start, end;

	// Main loop
	while (true) {
		start = clock();
		// game loop goes here
		input = read_input();

		// ESC to exit program
		if(input==27){

			_view.render(); // 顯示當下畫面
			break;


		}

		this->handleInput(input);

		_view.resetLatest();


		for (size_t i = 0; i < _objs.size(); ++i) {
			GameObject* obj = _objs[i];
			Position oldPos = obj->getPosition();

			//obj->update(); // 所有物件都執行 update，玩家蛇會移動、其他靜止就不會變

RPSGameObject* snake = dynamic_cast<RPSGameObject*>(_objs[i]);
if (i == _controlledSnakeIndex || (snake && snake->getType() == SNAKE)) {
    obj->update();
}
			if (willCollide(obj->getPosition(), i)) {
				for (size_t j = 0; j < _objs.size(); ++j) {
					if (j == i) continue;
					if (_objs[j]->getPosition() == obj->getPosition()) {
						RPSGameObject* colliderA = dynamic_cast<RPSGameObject*>(_objs[i]);
						RPSGameObject* colliderB = dynamic_cast<RPSGameObject*>(_objs[j]);
						if (colliderA && colliderB) {

							colliderA->onCollision(colliderB);
colliderB->onCollision(colliderA);

// 加分判斷
if ((colliderA == _objs[_controlledSnakeIndex] && colliderA->didEatFood()) ||
    (colliderB == _objs[_controlledSnakeIndex] && colliderB->didEatFood())) {
    ++_score;
}
							_view.updateGameObject(colliderA);
							_view.updateGameObject(colliderB);

							if ((_objs[i] == _objs[_controlledSnakeIndex] || _objs[j] == _objs[_controlledSnakeIndex]) &&
									(colliderA->getType() == OTHER_SNAKE || colliderB->getType() == OTHER_SNAKE)) {
								std::cout << "Game Over! Collision with other snake.\n";
								std::cout << "Final Score: " << _score << std::endl;
								return;
							}

							// 玩家蛇碰撞後就不再移動
							if (i == _controlledSnakeIndex && colliderA->isGameOver()) {
								return;
							}
						}

					}
				}

				obj->setPosition(oldPos); // 撞到就退回
			}

			_view.updateGameObject(obj);
		}


		_view.render();

		if (checkGameOver()) {
			break;
		}


		end = clock();

		// frame rate normalization
		double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
		if (time_taken > SPF) continue;
		int frameDelay = int((SPF - time_taken) * 1000); // 0.1 seconds
		if(frameDelay > 0) std::this_thread::sleep_for(std::chrono::milliseconds(frameDelay)); // frame delay
	}
}







void Controller::handleInput(int keyInput){

	// If there is no input, do nothing.
	if (keyInput == -1 || _controlledSnakeIndex == -1) return;


	// TODO
	// handle key events.

	// 取得現在控制的 Rock

	RPSGameObject* player = dynamic_cast<RPSGameObject*>(_objs[_controlledSnakeIndex]);
	if (!player) return;

	switch (keyInput) {
		case 'w': case 'W': player->setDirection(UP); break;
		case 's': case 'S': player->setDirection(DOWN); break;
		case 'a': case 'A': player->setDirection(LEFT); break;
		case 'd': case 'D': player->setDirection(RIGHT); break;
	}
}

void Controller::update(){


	for (size_t i = 0; i < _objs.size(); ++i) {
		if (i != _controlledSnakeIndex) {
			GameObject* obj = _objs[i];
			obj->update();
			if (willCollide(obj->getPosition(),i)) {
				obj->setPosition(obj->getOldPosition());  // 碰撞就退回
			}
			_view.updateGameObject(obj);
		}
	}


}



void reset_terminal() {
	printf("\e[m"); // reset color changes
	printf("\e[?25h"); // show cursor
	fflush(stdout);
	tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
}

// terminal initial configuration setup
void configure_terminal() {
	tcgetattr(STDIN_FILENO, &old_termios);
	new_termios = old_termios; // save it to be able to reset on exit

	new_termios.c_lflag &= ~(ICANON | ECHO); // turn off echo + non-canonical mode
	new_termios.c_cc[VMIN] = 0;
	new_termios.c_cc[VTIME] = 0;

	tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

	printf("\e[?25l"); // hide cursor
	std::atexit(reset_terminal);
}


int read_input() {
	fflush(stdout);
	char buf[4096]; // maximum input buffer
	int n = read(STDIN_FILENO, buf, sizeof(buf));
	return n > 0 ? buf[n - 1] : -1;
}





bool Controller::checkGameOver() {

	if (_controlledSnakeIndex == -1 || _controlledSnakeIndex >= _objs.size()) return true;

	RPSGameObject* player = dynamic_cast<RPSGameObject*>(_objs[_controlledSnakeIndex]);
	if (!player) return true;

	Position pos = player->getPosition();
	if (pos.x() < 0 || pos.x() >= GAME_WINDOW_WIDTH ||
			pos.y() < 0 || pos.y() >= GAME_WINDOW_HEIGHT) {
		std::cout << "Final Score: " << _score << std::endl;
		std::cout << "Game Over! Collision with the wall.\n";
		return true;
	}

	return player->isGameOver();
}

