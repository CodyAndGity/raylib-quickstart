#include "pongGame.h"
#include "raymath.h"
#include <stdlib.h>//for rand

void PongGame::update(){
	//screen edge collsion dedection and handling
	for (Shape* shape : shapes) {
		shape->update();
	}
	if (handleLeftBoard()) {
		setBallRandomColor();
		if (scoreIsValid) {
			scores[0]++;
		}
		scoreIsValid = false;
	};
	if (handleRightBoard()) {
		setBallRandomColor();
		if (scoreIsValid) {
			scores[1]++;
		}
		scoreIsValid = false;

	}
	

	if (ball->getVelocity().y >= 8|| ball->getVelocity().y <= -8) {
		ball->setVelocity({ ball->getVelocity().x,(ball->getVelocity().y) * .998f });
	}else if (ball->getVelocity().y >= 6 || ball->getVelocity().y <= -6) {
		ball->setVelocity({ ball->getVelocity().x,(ball->getVelocity().y) * .9998f });
	}
	
	if (ball->getVelocity().x >= 8 || ball->getVelocity().x <= -8) {
		ball->setVelocity({ ball->getVelocity().x * .998f,(ball->getVelocity().y) });
	}else if (ball->getVelocity().x > 7 || ball->getVelocity().x < -7) {
		ball->setVelocity({ ball->getVelocity().x * .9998f,(ball->getVelocity().y)  });
	}

	if (IsKeyDown(KEY_I)) {
		ball->setVelocity({ ball->getVelocity().x,(ball->getVelocity().y) * 1.1f });
	}
	if (IsKeyDown(KEY_O)) {
		ball->setVelocity({ ball->getVelocity().x * 1.1f,(ball->getVelocity().y)  });
	}

	shapes.push_back(shape);
	shape = new Circle(ball->getPosition(), ball->getSize(), ball->getSecondColor());

	if (ball->getPosition().x > 300 && ball->getPosition().x < GetScreenWidth() - 300) {
		scoreIsValid = true;
	}
	if (shapes.size() > 2000) {
		
		for (short i = 0; i< shapes.size(); i++) {
			if (shapes[i]->getType() == Shape::Type::Circle) {
				auto it = shapes[i];
				shapes.erase(shapes.begin()+i);
				break;
			}
		}
	}
}


bool PongGame::handleLeftBoard(){
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
		if (IsKeyDown(KEY_W) || IsKeyDown(KEY_S)  || IsKeyPressed(KEY_Q) || IsKeyPressed(KEY_E)) {
			if (ball->getVelocity().x > -10.0f) {
				ball->setVelocity({ -ball->getVelocity().x * 1.2f, ball->getVelocity().y });
			}
			else {
				ball->setVelocity({ 10, ball->getVelocity().y });

			}

		}
		else {
			ball->setVelocity({ -ball->getVelocity().x, ball->getVelocity().y });
		}
		return true;
	}
	//corner case
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
		return true;

	}
	return false;

}

bool PongGame::handleRightBoard(){
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
		if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN) || IsKeyPressed(KEY_PAGE_UP) || IsKeyPressed(KEY_PAGE_DOWN)) {
			if (ball->getVelocity().x < 10.0f) {
				ball->setVelocity({ -ball->getVelocity().x * 1.2f, ball->getVelocity().y });
			}
			else {
				ball->setVelocity({ -10, ball->getVelocity().y });

			}

		}
		else {
			ball->setVelocity({ -ball->getVelocity().x, ball->getVelocity().y });
		}
		return true;

	}
	//corner case
	else if (ballIsTouchingRightBoardHorizontally && ballIsTouchingRightBoardVertically) {

		Vector2 newVelocity = { 0,0 };
		int upDown = 0;//whether or not the ball needs to go up or down
		if (ball->getPosition().y > rightPlayerBoard->getPosition().y) {
			upDown = 1;
		}
		else {
			upDown = -1;
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
		return true;

	}
	return false;

}
void PongGame::setBallRandomColor(){
	ball->cycleColors(Color{ (unsigned char)(rand() % 255), (unsigned char)(rand() % 255),(unsigned char)(rand() % 255), 255 });

}
void PongGame::draw(){
	//mess is to draw the bars and main ball on top of everything
	for (short i = 3; i < shapes.size(); i++) {
		if (i == shapes.size()-1) {
			for (short j = 0; j < 3; j++) {
				shapes[j]->draw();
			}
		}else {
			shapes[i]->draw();
		}
	}
	
	DrawText(TextFormat("%i                  %i", (int)scores[0], (int)scores[1]), (GetScreenWidth()/2)-80, 10, 20, WHITE);
}
