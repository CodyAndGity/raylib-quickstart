#include "pongBoard.h"

void PongBoard::update() {
	if (isPlayer) {
		if (IsKeyDown(KEY_W)) {
			position.y -= 5;
		}
		if (IsKeyDown(KEY_S)) {
			position.y += 5;
		}
		if (position.y < 0) {
			position.y = 0;
		}
		if (position.y > GetScreenHeight() - size * 5) {
			position.y = GetScreenHeight() - size * 5;
		}
	}
	
		
	//position = Vector2{ 100, (float)GetMouseY()-((size * 5)/2)};
	
}

void PongBoard::draw(){
	
	//Vector2 sizeV = { this->size, this->size };
	//DrawRectangleV(position - Vector2{ (size / 2),(size / 2) }, sizeV, color);
	if (isPlayer) {
		DrawRectangle(position.x, position.y, size, size * 5, WHITE);
	}
	
}
