#include <iostream>
#include "Game.h"

Game::Game()
    : window(sf::VideoMode(800, 600), "Breakout"),
      ball(400, 300, "assets/ball.png"),
      paddle(350, 550, "assets/paddle.png"),
      score(0),
      lives(3) {
    if (!ballTexture.loadFromFile("assets/ball.png") ||
        !paddleTexture.loadFromFile("assets/paddle.png") ||
        !brickTexture.loadFromFile("assets/brick.png")) {
        std::cerr << "Error loading textures" << std::endl;
    }

    // Initialize bricks (example initialization)
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            bricks.emplace_back(i * 80 + 20, j * 30 + 20, "assets/brick.png");
        }
    }
}
