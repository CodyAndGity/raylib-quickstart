#include "square.h"
#include "raymath.h"

void Square::update(){
	//empty
}

void Square::draw(){
	Vector2 sizeV = { this->size, this->size };
	 DrawRectangleV( position- Vector2{(size/2),(size/2)}, sizeV, color);
}


