#pragma once
#include "shape.h"
#include "physicsCircle.h"
#include "pongBoard.h"
#include <vector>
class PongGame {
public:
	PongGame() = default;
	~PongGame() {
		for (short i = 0; i < shapes.size(); i++) {
			delete shapes[i];
		}
		shapes.clear();
	}
	void update();
	void draw();
private:
	bool handleLeftBoard();
	bool handleRightBoard();
	void setBallRandomColor();
private:
	PhysicsCircle* ball = new PhysicsCircle(Vector2{ (float)(GetScreenWidth()/2),400 }, 20.0f, WHITE, Vector2{ 5,0 });
	PongBoard* leftPlayerBoard = new PongBoard(true);
	PongBoard* rightPlayerBoard = new PongBoard(false);
	std::vector <Shape*> shapes = { ball,leftPlayerBoard,rightPlayerBoard };
	Shape* shape = new Circle(Vector2{ (float)(GetScreenWidth() / 2),400 });
	
	int scores[2] = { 0,0 };
	bool scoreIsValid = true;

};