#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
const float length = 800;
const float width = 600;
const float length_bat = 20;
const float width_bat = 80;
const float ballradius = 10;
const float otstup = 50;
const float ball_posx = length / 2 - 10;
const float ball_posy = width / 2 - 10;
const Color batcolor1(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
const Color batcolor2(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
const Vector2f batsize(length_bat, width_bat);
const float batSpeed = 5.f;
const float LeftScore_posx = 88.f;
const float LeftScore_posy = 50.f;
const float RightScore_posx = 680.f;
const float RightScore_posy = 50.f;
const Vector2f leftBatStartPos{ otstup, width / 2 - 40 };
const Vector2f rightBatStartPos{ length - otstup - 20, width / 2 - 40 };
const Vector2f ballStartPos{ ball_posx,ball_posy };
const Vector2f rightScorePos{ RightScore_posx, RightScore_posy };
const Vector2f leftScorePos{ LeftScore_posx, LeftScore_posy };
