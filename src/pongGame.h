#pragma once
#include "shape.h"
#include "physicsCircle.h"
#include "pongBoard.h"
#include <vector>
class PongGame {
public:
	PongGame() = default;
	~PongGame() {
		delete ball;
		delete leftPlayerBoard;
	}
	void update();
	void draw();
private:
	void handleLeftBoard();
	void handleRightBoard();
private:
	PhysicsCircle* ball = new PhysicsCircle(Vector2{ 400,400 }, 20.0f, WHITE, Vector2{ 5,0 });
	PongBoard* leftPlayerBoard = new PongBoard(true);
	PongBoard* rightPlayerBoard = new PongBoard(false);
	std::vector <Shape*> shapes = { ball,leftPlayerBoard,rightPlayerBoard };
};