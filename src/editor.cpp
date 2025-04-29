#include "editor.h"
#include "square.h"
#include "circle.h"

Editor::Editor(){
	Shape* shape = create(type);

}

Editor::~Editor() {
	clearAll();
	delete shape;


}

void Editor::update(){
	//input->update->draw
	if (IsKeyDown(KEY_RIGHT)) {
		size += 0.5f;
		size = std::min(size, 100.0f);
	};if (IsKeyDown(KEY_LEFT)) {
		size -= 0.5f;
		size = std::max(size, 1.0f);
		
	};
	shape->setSize(size);


	if (IsKeyPressed(KEY_UP)) {
		currentColor++;
		currentColor %=  color.size();
		shape->setColor(color[currentColor]);
	}
	if (IsKeyPressed(KEY_DOWN)) {
		currentColor--;
		currentColor %= color.size();
		shape->setColor(color[currentColor]);
	}

	//shape select
	if (IsKeyPressed(KEY_TAB)) {
		type = static_cast<Shape::Type>((static_cast<int>(type)+1) % static_cast<int>(Shape::Type::NumShapes));
		delete shape;
		shape = create(type);
	}

	if (IsKeyPressed(KEY_W)) {
		clearAll();
	}


	//place shape
	if (IsMouseButtonPressed(0)||(IsMouseButtonDown(1) && IsKeyDown(KEY_LEFT_CONTROL))) {
		//add curcnet shape
		shapes.push_back(shape);
		//create new shape
		shape = create(type);
	};
	//if (IsMouseButtonDown(1)) {
	//	//add curcnet shape
	//	shapes.push_back(shape);
	//	//create new shape
	//	shape = new Square(Vector2{ 400,400 }, size, *(new Color{ 125, 125, 125, 255 }));
	//};

	
	shape->setPosition(GetMousePosition());

	for (Shape* shape : shapes) {
		shape->update();
	};

	shape->update();
	
}

void Editor::draw(){
	//draw placed shapes
	for (Shape* shape : shapes) {
		shape->draw();
	};
	//draw current shape
	shape->draw();

}

Shape* Editor::create(Shape::Type type){
	Shape* shape = nullptr;
	switch (type) {
	case Shape::Type::Circle:
		shape = new Circle(GetMousePosition(), size, color[currentColor]);
		break;
	case Shape::Type::Square:
		shape = new Square(GetMousePosition(), size, color[currentColor]);

		break;
	}
	return shape;
}

void Editor::clearAll(){
	for (Shape* shape : shapes) {
		delete shape;
	};
	shapes.clear();
}
