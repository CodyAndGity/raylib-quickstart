#pragma once
#include "shape.h"
#include "circle.h"
#include <vector>
#include <array>
class Editor {
public:
	Editor();
	~Editor();

	void update();
	void draw();
private:
	Shape* create(Shape::Type type);
	void clearAll();

private:
	//Shape* shape = nullptr;
	float size = 20;
	Shape::Type type = Shape::Type::Circle;
	const std::array<Color,6> color= { WHITE, RED, GREEN, BLUE, BLACK, *(new Color{ 125, 125, 125, 255 }) };//last is grey
	short currentColor = 0;
	Shape* shape = new Circle(Vector2{ 400,400 });


	std::vector <Shape*> shapes;

};