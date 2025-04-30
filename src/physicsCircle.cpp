#include "physicsCircle.h"
#include "raymath.h"

void PhysicsCircle::update(){
	move();
	
}

void PhysicsCircle::move(){
	Vector2 intendedPosition = Vector2Add(position, velocity);
	if (intendedPosition.x > GetScreenWidth() - size || intendedPosition.x  < 0 + size) {
		velocity.x *= -1;
	}
	if (intendedPosition.y > GetScreenHeight() - size || intendedPosition.y  < 0 + size) {
		velocity.y *= -1;
	}
	setPosition(intendedPosition);
}
