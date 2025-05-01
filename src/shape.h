#pragma once
#include "raylib.h"
class Shape {
public:
	enum class Type {
		Circle,
		Square,
		Rectangle,
		PhysicsCircle,
		NumShapes
	};
public:
	Shape() = default;
	Shape(const Vector2& position, float size=20, const Color& color=WHITE) {
		this->position = position;
		this->size = size;
		this->color = color;
	}
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual Type getType() = 0;
	const Vector2& getPosition() const {
		return position;
	};
	void setPosition(const Vector2& position) {
		this->position = position;
	};
	const Color& getColor() const {
		return color;
	};
	void setColor(const Color& color) {
		this->color = color;
	};
	float getSize() const {
		return size;
	};
	void setSize(float size) {
		this->size = size;
	};
protected:
	Vector2 position = { 0, 0 };
	Color color=WHITE;
	float size=20;
};