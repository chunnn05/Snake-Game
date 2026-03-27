#include "RPSGameObject.h"
#include "environment.h"
#include "icon.h"


RPSGameObject::RPSGameObject(const Icon& icon, const Position& position)
	: GameObject(icon, position), _dir(UP) {

		_body.push_front(position);
		std::string content = icon[0][0].ascii;
		Color color = icon[0][0].getColor();

		if (content == "SK" && color == RED) {
			_type = SNAKE;
		} else if (content == "OS" && color == GREEN) {
			_type = OTHER_SNAKE;
		} else if (content == "FD" && color == CYAN) {
			_type = FOOD;
		} else {
			_type = SNAKE;  
		}
	}


void RPSGameObject::update() {

	if (_type != SNAKE||!_isMoving) return;

	Position head = _body.front();
	Position newHead = head;

	switch (_dir) {
		case UP:    newHead = Position(head.x(), head.y() - 1); break;
		case DOWN:  newHead = Position(head.x(), head.y() + 1); break;
		case LEFT:  newHead = Position(head.x() - 1, head.y()); break;
		case RIGHT: newHead = Position(head.x() + 1, head.y()); break;
	}


	_body.push_front(newHead);
	if (!_grow) {
		_body.pop_back(); 
	} else {
		_grow = false;
	}

	this->setPosition(newHead); 


}

bool RPSGameObject::intersect(ICollider *other) {
	auto *otherObj = dynamic_cast<RPSGameObject*>(other);
	if (!otherObj) return false;

	return this->getPosition() == otherObj->getPosition();
}



void RPSGameObject::onCollision(ICollider *other) {

auto *otherObj = dynamic_cast<RPSGameObject*>(other);
    if (!otherObj) return ;

	_ateFood = false;

    if (_type != SNAKE) return ;

    RPSType otherType = otherObj->getType();

    if (otherType == FOOD) {
        otherObj->setVisible(false);

        _grow = true;
		_ateFood = true;

    } else if (otherType == OTHER_SNAKE || otherType == SNAKE) {
        _gameOver = true;
    }

}

RPSType RPSGameObject::getType() const {
	return _type;
}

void RPSGameObject::setType(RPSType type) {
	_type = type; 
	if (_type == SNAKE) {
		_icon[0][0] = Cell(Color::RED, "SK");
	} else if (_type == OTHER_SNAKE) {
		_icon[0][0] = Cell(Color::GREEN, "OS");
	} else if (_type == FOOD) {
		_icon[0][0] = Cell(Color::CYAN, "FD");
	}
}

void RPSGameObject::setDirection(Direction dir) {
	_dir = dir;
	_isMoving = true;
}


