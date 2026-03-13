#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include "unit.h"
#include "icon.h"
#include <iostream>
class GameObject{

public:

	GameObject(); 
    GameObject(const Icon& icon, const Position& position); 														
    Position getPosition() const;
    Icon getIcon() const;
    virtual void update();
	void setPosition(const Position& pos);
	void setIcon(const Icon& icon);
	Position getOldPosition() const;
    void setOldPosition(const Position& pos);
	bool isVisible() const { return _visible; }
    void setVisible(bool visible) { _visible = visible; }
protected:

    Position _pos;
	Position _oldPos;
    Icon _icon;
	bool _visible = true;
};

#endif
