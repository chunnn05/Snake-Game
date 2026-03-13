// TODO implementation




#include "gameObject.h"
#include "environment.h"


GameObject::GameObject() {}

GameObject::GameObject(const Icon& icon, const Position& position)
	: _icon(icon), _pos(position) {} 

	Icon GameObject::getIcon() const {
		return _icon;
	}

Position GameObject::getPosition() const {
	return _pos; 
}

void GameObject::setPosition(const Position& pos) { 
	_pos = pos;
}

void GameObject::setIcon(const Icon& icon) {
	_icon = icon;
}



Position GameObject::getOldPosition() const {
    return _oldPos;
}

void GameObject::setOldPosition(const Position& pos) {
    _oldPos = pos;
}


void GameObject::update() {
}
