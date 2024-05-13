#pragma once
#ifndef KEY_PRESS_H
#define KEY_PRESS_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Logger.hpp>
#include <Game.hpp>
#include <Consts.hpp>


void ProcessKeyPressed(sf::RenderWindow* window, const sf::Event& event, Game* game);
void ProcessKeyReleased(sf::RenderWindow* window, const sf::Event& event, Game* game);
void ProcessMouseMoved(sf::RenderWindow* window, const sf::Event& event, Game* game);
void ProcessMousePressed(sf::RenderWindow* window, const sf::Event& event, Game* game);
void ProcessMouseReleased(sf::RenderWindow* window, const sf::Event& event, Game* game);
template<typename T>
void SetActions(const sf::Event& event, const Consts::KeyMap<T>& keyMap, uint64_t& action);
template<typename T>
void EraseActions(const sf::Event& event, const Consts::KeyMap<T>& keyMap, uint64_t& action);
#endif // EVENTS_H