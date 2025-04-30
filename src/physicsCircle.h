#pragma once
#include "circle.h"
class PhysicsCircle :public Circle {
public:
	PhysicsCircle() = default;
	PhysicsCircle(const Vector2& position, float size = 20, const Color& color = WHITE, Vector2 velocity = { 1,11 })
		:Circle(position, size, color)
		, velocity(velocity){};
	void update() override;
private:
	void move();
private:
	Vector2 velocity{ 0,0 };
};