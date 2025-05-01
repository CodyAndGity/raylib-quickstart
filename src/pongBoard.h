#pragma once
#include "shape.h"
class PongBoard :public Shape {



public:
	PongBoard() = default;

	PongBoard(const bool isLeftPlayer)
		:Shape(Vector2{ 100,500 }, 20, WHITE),
		isLeftPlayer{ isLeftPlayer } {
		if (isLeftPlayer) {
			this->position = Vector2{ 75,350 };
		}
		else {
			this->position = Vector2{ (float)GetScreenWidth() - 75-size,350 };
		}
	};
	void update() override;
	void draw() override;
	Type getType() override { return Type::Rectangle; };
private:
	bool isLeftPlayer = false;
};