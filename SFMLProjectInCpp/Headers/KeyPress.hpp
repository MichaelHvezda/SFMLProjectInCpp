#pragma once
#ifndef KEY_PRESS_H
#define KEY_PRESS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Logger.hpp>
#include <Game.hpp>
#include <Consts.hpp>


void ProcessKeyPressed(const sf::Event& event, Game* game);
void ProcessKeyReleased(const sf::Event& event, Game* game);
void ProcessMouseMoved(const sf::Event& event, Game* game);
void ProcessMousePressed(const sf::Event& event, Game* game);
void ProcessMouseReleased(const sf::Event& event, Game* game);
template<typename T>
void SetActions(const Consts::KeyMap<T>& keyMap, std::vector<T>& list);
template<typename T>
void EraseActions(const Consts::KeyMap<T>& keyMap, std::vector<T>& list);
#endif // EVENTS_H