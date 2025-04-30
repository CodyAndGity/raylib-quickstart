#pragma once
#include "shape.h"
class PongBoard :public Shape {



public:
	PongBoard() = default;
	/*PongBoard(const Vector2& position={100,500}, float size = 20, const Color& color = WHITE, const bool isPlayer = false)
		:Shape(position, size, color),
		isPlayer{ isPlayer } {
	};*/
	PongBoard(const bool isPlayer)
		:Shape(Vector2{ 100,500 }, 20, WHITE),
		isPlayer{ isPlayer } {
		if (isPlayer) {
			this->position = Vector2{ 75,350 };
		}
		else {
			this->position = Vector2{ (float)GetScreenWidth() - 75,500 };
		}
	};
	void update() override;
	void draw() override;
	Type getType() override { return Type::Square; };
private:
	bool isPlayer = false;
};