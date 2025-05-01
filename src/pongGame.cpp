#include "pongGame.h"
#include "raymath.h"
#include <stdlib.h>//for rand

void PongGame::update(){
	//screen edge collsion dedection and handling
	for (Shape* shape : shapes) {
		shape->update();
	}
	handleLeftBoard();
	handleRightBoard();
	
}


void PongGame::handleLeftBoard(){
	//collsion detection
	//bool ballIsTouchingBoard = CheckCollisionPointRec(circle->getPosition(), playerBoard->getRectangle());
	bool ballIsTouchingLeftBoardHorizontally = ball->getPosition().x - ball->getSize() <=
		leftPlayerBoard->getPosition().x + leftPlayerBoard->getSize();
	//does not account for the ball radius
	bool strictBallIsTouchingLeftBoardVertically = ball->getPosition().y >= leftPlayerBoard->getPosition().y &&
		ball->getPosition().y <= leftPlayerBoard->getPosition().y + leftPlayerBoard->getSize() * 5;
	//accounts for the ball radius
	bool ballIsTouchingLeftBoardVertically = ball->getPosition().y + ball->getSize() >= leftPlayerBoard->getPosition().y &&
		ball->getPosition().y - ball->getSize() <= leftPlayerBoard->getPosition().y + leftPlayerBoard->getSize() * 5;


	//collsion handling
	if (ballIsTouchingLeftBoardHorizontally && strictBallIsTouchingLeftBoardVertically) {
		ball->setVelocity({ -ball->getVelocity().x, ball->getVelocity().y });
	}
	//coner case
	else if (ballIsTouchingLeftBoardHorizontally && ballIsTouchingLeftBoardVertically) {

		Vector2 newVelocity = { 0,0 };
		int upDown = 0;//whether or not the ball needs to go up or down
		if (ball->getPosition().y > leftPlayerBoard->getPosition().y) {
			upDown = -1;
		}
		else {
			upDown = 1;
		}
		float tempx = rand();
		tempx = (int)tempx % 5;
		tempx += 1;
		tempx /= 5;

		float tempy = ball->getVelocity().x - (ball->getVelocity().x * tempx);
		//the velocity that was lost combines with the y velocity
		newVelocity = { -ball->getVelocity().x * tempx, ball->getVelocity().y + (upDown * tempy) };

		//ball->setVelocity({ -ball->getVelocity().x, ball->getVelocity().y });
		ball->setVelocity(newVelocity);
	}
}

void PongGame::handleRightBoard(){
	//collsion detection
	//bool ballIsTouchingBoard = CheckCollisionPointRec(circle->getPosition(), playerBoard->getRectangle());
	bool ballIsTouchingRightBoardHorizontally = ball->getPosition().x + ball->getSize() >=
		rightPlayerBoard->getPosition().x;
		//+ rightPlayerBoard->getSize();
	
		//does not account for the ball radius
	bool strictBallIsTouchingRightBoardVertically = ball->getPosition().y >= rightPlayerBoard->getPosition().y &&
		ball->getPosition().y <= rightPlayerBoard->getPosition().y + rightPlayerBoard->getSize() * 5;
	//accounts for the ball radius
	bool ballIsTouchingRightBoardVertically = ball->getPosition().y + ball->getSize() >= rightPlayerBoard->getPosition().y &&
		ball->getPosition().y - ball->getSize() <= rightPlayerBoard->getPosition().y + rightPlayerBoard->getSize() * 5;


	//collsion handling
	if (ballIsTouchingRightBoardHorizontally && strictBallIsTouchingRightBoardVertically) {
		ball->setVelocity({ -ball->getVelocity().x, ball->getVelocity().y });
	}
	//coner case
	else if (ballIsTouchingRightBoardHorizontally && ballIsTouchingRightBoardVertically) {

		Vector2 newVelocity = { 0,0 };
		int upDown = 0;//whether or not the ball needs to go up or down
		if (ball->getPosition().y > rightPlayerBoard->getPosition().y) {
			upDown = -1;
		}
		else {
			upDown = 1;
		}
		float tempx = rand();
		tempx = (int)tempx % 5;
		tempx += 1;
		tempx /= 5;

		float tempy = ball->getVelocity().x - (ball->getVelocity().x * tempx);
		//the velocity that was lost combines with the y velocity
		newVelocity = { -ball->getVelocity().x * tempx, ball->getVelocity().y + (upDown * tempy) };

		//ball->setVelocity({ -ball->getVelocity().x, ball->getVelocity().y });
		ball->setVelocity(newVelocity);
	}
}
void PongGame::draw(){
	for (Shape* shape : shapes) {
		shape->draw();
	}
}
