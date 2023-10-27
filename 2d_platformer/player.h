#ifndef PLAYER_H
#define PLAYER_H

#include "one_way_tile.h"
#include "solid_tile.h"
#include <sfml/Graphics.hpp>
#include <vector>

class Player {
  public:
    Player(float acceleration, float maxSpeed, float gravity, float jumpVelocity, float fallMultiplier,
           float jumpFallMultiplier, float maxFallSpeed, float coyoteTime, float jumpBufferTime,
           sf::Color color, sf::Vector2f size, sf::Vector2f pos);

    void update(sf::RenderWindow &window, float deltaTime, std::vector<SolidTile> &solidTileGroup, std::vector<OneWayTile> &oneWayTileGroup);

    void draw(sf::RenderWindow &window);

  private:
    float acceleration;
    float maxSpeed;
    float gravity;
    float jumpVelocity;
    float fallMultiplier;
    float jumpFallMultiplier;
    float maxFallSpeed;
    float coyoteTime;
    float jumpBufferTime;

    bool isGrounded;
    bool holdingSpace;
    float coyoteTimeTimer;
    float jumpBufferTimer;
    sf::Vector2f direction;
    sf::RectangleShape rect;
    sf::RectangleShape rectBottom;

    void collisionOneWayTile(std::vector<OneWayTile> &oneWayTileGroup);

    void horizontalMovement(float deltaTime);

    void horizontalCollisionsSolidTile(std::vector<SolidTile> &solidTileGroup);

    void verticalMovement(float deltaTime);

    void verticalCollisionsSolidTile(std::vector<SolidTile> &solidTileGroup);

    void followCamera(float horizontalDeadZone, float verticalDeadZone, sf::RenderWindow &window);

    void stationaryCamera(sf::RenderWindow &window);

    void horizontalCamera(sf::RenderWindow &window);

    void verticalCamera(sf::RenderWindow &window);

    void camera(sf::RenderWindow &window);
};
#endif
