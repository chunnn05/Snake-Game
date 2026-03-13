#ifndef RPS_H
#define RPS_H

#include "collider.h"
#include "gameObject.h"
#include "unit.h"
#include <deque>

enum RPSType { SNAKE, FOOD, OTHER_SNAKE };

class RPSGameObject : public GameObject, public ICollider {

	public:

		RPSGameObject();
		RPSGameObject(const Icon& icon, const Position& position);
		void update() override;
		void onCollision(ICollider *other) override;
		bool intersect(ICollider *other) override;

		RPSType getType() const;
		void setType(RPSType type);
		void setDirection(Direction);

		bool _grow = false;
		bool _gameOver = false;

		bool _isMoving = false;
		bool isGameOver() const { return _gameOver; }
		const std::deque<Position>& getBody() const { return _body; }
		void addBodyPart(const Position& pos) {
        _body.push_back(pos);
        }
		bool didEatFood() const { return _ateFood; }

	private:
		RPSType _type;
		Direction _dir;
		std::deque<Position> _body;
		bool _ateFood = false;
		
};
#endif
