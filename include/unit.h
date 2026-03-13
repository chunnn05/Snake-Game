#ifndef UNIT_H
#define UNIT_H
struct Vec2{
	int e1;
	int e2;
	int& x(){ return e1;}
	int& y(){ return e2;}
	int& width(){return e1;}
	int& height(){return e2;}
	int x() const { return e1; }
    int y() const { return e2; }

	Vec2() : e1(0), e2(0) {}
	Vec2(int x_, int y_) : e1(x_), e2(y_) {}
	bool operator==(const Vec2& other) const {
		return e1 == other.e1 && e2 == other.e2;
	}



};

using Position = Vec2;

enum Color {BLACK=0, RED, GREEN, YELLOW, BLUE, PINK, CYAN, WHITE, NOCHANGE};
enum Direction { RIGHT = -2, DOWN = -1, NONE = 0, UP = 1, LEFT = 2 };

#endif
