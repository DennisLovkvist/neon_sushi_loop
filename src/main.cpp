/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2021-10-18)
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include "canvas.h"
#include <SFML/Audio.hpp>

int main()
{

	sf::RenderWindow window(sf::VideoMode(1920,1080), "SFML works!", sf::Style::Close);

	sf::Clock clock;
	float dt = 1.f / 30.f;
	float accumulator = 0.f;
	float t = 0;

	Canvas* world = new	Canvas();

	LoadTextures(*world);

	InitCanvas(*world);

	sf::Shader shader;
	sf::Shader shader_perlin;

	sf::Shader shader_blend;

	shader.loadFromFile("content/shaders/shader_distortion.frag", sf::Shader::Fragment);
	shader_perlin.loadFromFile("content/shaders/shader_water_surface.frag", sf::Shader::Fragment);

	sf::SoundBuffer buffer_rain;
	buffer_rain.loadFromFile("content/sound/rain_loop.ogg");
	sf::SoundBuffer buffer_music;
	buffer_music.loadFromFile("content/sound/music.ogg");

	sf::Sound sound_rain;
	sound_rain.setLoop(true);
	sound_rain.setBuffer(buffer_rain);
	sound_rain.play();

	sf::Sound sound_music;
	sound_music.setLoop(true);
	sound_music.setBuffer(buffer_music);
	sound_music.setVolume(10);
	sound_music.play();


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if(event.type == sf::Event::KeyPressed)
			{
                if(event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
			}
		}
		while (accumulator >= dt)
		{

			t += dt;
			UpdateCanvas(*world, dt,t);

			accumulator -= dt;

			DrawWorld(window, shader,shader_perlin,*world);
			window.display();
		}


		accumulator += clock.getElapsedTime().asSeconds();

		clock.restart();

			

	}

	return 0;
}
