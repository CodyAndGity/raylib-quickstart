#include "square.h"

void Square::update(){
	//empty
}

void Square::draw(){
	Vector2 size = { this->size, this->size };
	 DrawRectangleV( position, size,  color);
}


