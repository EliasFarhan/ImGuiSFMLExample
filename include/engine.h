#ifndef ENGINE_H
#define ENGINE_H

#include <utility.h>
#include <SFML/Graphics.hpp>
#include <console.h>

class Engine : public Singleton<Engine>
{
public:
	void Init();
	void Start();

protected:
	friend class Singleton;
	friend class Log;
	using Singleton::Singleton;
	sf::RenderWindow* window;
	sf::Clock deltaClock;
	sf::CircleShape shape;

	Console console;


};

#endif
