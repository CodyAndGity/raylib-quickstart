#pragma once
#include "circle.h"
class PhysicsCircle :public Circle {
public:
	PhysicsCircle() = default;
	PhysicsCircle(const Vector2& position, float size = 20, const Color& color = WHITE, Vector2 velocity = { 1,11 })
		:Circle(position, size, color)
		, velocity(velocity){};
	void update() override;
	void draw() override;
	void setColors(Color colors[2]) {
		this->colors[0] = colors[0];
		this->colors[1] = colors[1];
	}
	Color getFirstColor() {
		return colors[0];
	}
	Color getSecondColor() {
		return colors[1];
	}
	void cycleColors(Color color) {
		colors[0] = colors[1];
		colors[1] = color;
	}
	void setVelocity(const Vector2& velocity) {
		if (velocity.x >= minSpeed || velocity.x<=-minSpeed) {
			this->velocity = velocity;
		}
		else {
			if (velocity.x > 0) {
				this->velocity = { minSpeed, velocity.y };
			}
			else {
				this->velocity = { -minSpeed, velocity.y };

			}

		}
	};
	Vector2 getVelocity() const {
		return velocity;
	};
	Type getType() override { return Type::PhysicsCircle; };

private:
	void move();
private:
	Vector2 velocity{ 0,0 };
	float minSpeed = 5;
	Color colors[2] = { WHITE,WHITE };
};