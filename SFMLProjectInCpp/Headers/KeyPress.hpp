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
template<typename T>
void SetActions(const Consts::KeyMap<T>& keyMap, std::vector<T>& list);
template<typename T>
void EraseActions(const Consts::KeyMap<T>& keyMap, std::vector<T>& list);
#endif // EVENTS_H