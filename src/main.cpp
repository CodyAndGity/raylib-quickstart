/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/
//#include "shape.h"
//#include "circle.h"
//#include "square.h"
//#include <vector>
#include "editor.h"
#include "physicsCircle.h"
#include "pongBoard.h"
#include "raylib.h"
#include "raymath.h"	// for sin function
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
//#define canvas 1
#define pong 1


int main (){
	
	const int screenWidth = 1280;
	const int screenHeight = 800;
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	
	// Create the window and OpenGL context
	InitWindow(screenWidth, screenHeight, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	//Texture wabbit = LoadTexture("wabbit_alpha.png");
#if canvas
	Editor editor;
#endif
#if pong
	PhysicsCircle* circle = new PhysicsCircle(Vector2{ 400,400 }, 20.0f, WHITE, Vector2{ 5,0 });
	PongBoard* playerBoard = new PongBoard(true);
#endif
	
#if demo
	Texture Niko = LoadTexture("Niko.jpg");
#endif
	
	// game loop
	while (!WindowShouldClose())	// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		#if canvas
			editor.update();
		#endif
			//circle update
#if pong
		circle->update();
		playerBoard->update();
		//bool ballIsTouchingBoard = CheckCollisionPointRec(circle->getPosition(), playerBoard->getRectangle());
		bool ballIsTouchingBoardHorizontally = circle->getPosition().x - circle->getSize()<=
			playerBoard->getPosition().x +playerBoard->getSize() ;
		bool ballIsTouchingBoardVertically = circle->getPosition().y >= playerBoard->getPosition().y &&
			  circle->getPosition().y<= playerBoard->getPosition().y + playerBoard->getSize() * 5;
		//if circle is near baord
		//like if circle X-radius <= baord x+width
		
		//Auto complete made this mess
		/*if(circle->getPosition().x < playerBoard->getPosition().x + playerBoard->getSize() && circle->getPosition().x > playerBoard->getPosition().x) {
			if (circle->getPosition().y > playerBoard->getPosition().y && circle->getPosition().y < playerBoard->getPosition().y + playerBoard->getSize() * 5) {
				circle->setVelocity({ -circle->getVelocity().x, circle->getVelocity().y });
			}
		}*/
#endif
		// drawing
		BeginDrawing();
		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// draw some text using the default font
		/*Vector2 mousePos = GetMousePosition();
		DrawText(TextFormat("Mouse Position: %i, %i", (int)mousePos.x, (int)mousePos.y), 10, 10, 20, WHITE);*/
		//DrawText("Hello Raylib", 200, 200, 20, WHITE);

		// draw our texture to the screen
		//DrawTexture(wabbit, 400,200, WHITE);
		#if canvas
			editor.draw();
		#endif
#if pong
			if (ballIsTouchingBoardHorizontally) {
				circle->setColor(GREEN);
			}else			if (ballIsTouchingBoardVertically) {
				circle->setColor(BLUE);
			}else			if (ballIsTouchingBoardHorizontally && ballIsTouchingBoardVertically) {
				//circle->setVelocity({ -circle->getVelocity().x, circle->getVelocity().y });
				circle->setColor(RED);
			}
			else {
				circle->setColor(WHITE);
			}
			
		circle->draw();
		playerBoard->draw();
#endif

#if demo
		// draw our texture to the screen
		const int sizeFactor = 5;
		for (short i = 0;i < 100;i++) {
		//DrawTexture(wabbit, GetMouseX() + GetRandomValue(0, screenWidth / sizeFactor) - (screenWidth / (sizeFactor*2)), GetMouseY() + GetRandomValue(0, screenHeight / sizeFactor) - (screenHeight / (sizeFactor*2)), WHITE);
		};
		for (short i = 0;i < screenWidth;i+=50) {
			int y = screenHeight  / 2+(sinf(((GetTime()*3) )+i/(100.0f))*200);
			//DrawTexture(Niko, i, y, WHITE);
			float scale = 0.5f + sinf(GetTime()) / 2;
			DrawTextureEx(Niko, (Vector2) { i, y }, (GetTime()*1115), scale, MAGENTA);
		};
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
#endif

		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	//UnloadTexture(wabbit);
#if pong
	delete circle;
#endif
	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
