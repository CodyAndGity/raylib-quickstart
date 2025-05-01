# Raylib-Quickstart
A simple cross platform template for setting up a project with the bleeding edge raylib code.
Works with C or C++.

## Simpliy run In VS Code


## Controls
   For the left player/bar, W/S to scroll up and down, with Q/E for fine adjustments
   For the right player/bar, Up/Down to scroll up and down, with Page Up/Page Down for fine adjustments
   There are also 2 dev buttons; I for y velocity, O for x velocity, that continually increase their velocity respectivly.
## Game
  The game is pong, with some changes
  The ball has a trail(with a max length)
  The ball changes color with each hit of a player board
  Score is increased when the ball hits you board
  Score does not decrement when hitting behind a players board
  Moving the board while a ball hits it cleanly(not on the corner) slightly inceases its speed
  A ball hitting a corner will convert some x velocity into y velocity
  There is a soft speed cap for both veleocities, with a constant that is less that 1 being multiplied to them if too high
  There are multiple checks to keep the ball in bounds, but if it reaches 10,000 or more away from the screen, it will be teleported back
