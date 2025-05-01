#include "physicsCircle.h"
#include "raymath.h"

void PhysicsCircle::update(){
	move();
	
}

void PhysicsCircle::draw(){
	
		DrawCircleGradient(position.x, position.y, size, colors[0], colors[1]);
	
}

void PhysicsCircle::move(){
	Vector2 intendedPosition = Vector2Add(position, velocity);
	if (intendedPosition.x > GetScreenWidth() - size || intendedPosition.x  < 0 + size) {
		velocity.x *= -1;
	}
	if (intendedPosition.y > GetScreenHeight() - size || intendedPosition.y  < 0 + size) {
		velocity.y *= -1;
	}
	intendedPosition = Vector2Add(position, velocity);
	if (intendedPosition.x > GetScreenWidth() - size  ) {
		position.x -= 100;
	}
	else if (intendedPosition.x < 0 + size) {
		position.x += 100;

	}
	if (intendedPosition.y > GetScreenHeight() - size ) {
		position.y -= 100;

	}
	else if (intendedPosition.y < 0 + size) {
		position.y += 100;

	}
	intendedPosition = Vector2Add(position, velocity);

	if (intendedPosition.x > 10000) {
		intendedPosition.x = 40;
		velocity.x = 5;
	}
	if (intendedPosition.y > 10000) {
		intendedPosition.y = 40;
		velocity.y = 5;

	}
	setPosition(intendedPosition);
	
	//DrawText(TextFormat("Ball velocity: %i x, %i y", (int)velocity.x, (int)velocity.y), 10, 10, 20, WHITE);
}
