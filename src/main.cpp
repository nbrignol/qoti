
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include "Hero.h"
#include <iostream>

int main()
{
   
	// Create main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "The Quest of the Incrementalist 7", sf::Style::Titlebar | sf::Style::Close);
	sf::Color backgroundColor = sf::Color(50, 50, 50);
		
	Hero hero;
	hero.center(window.GetWidth(), window.GetHeight());
	
    // Start game loop
    while (true)
    {
        // Process events
        sf::Event Event;
        window.GetEvent(Event);
		
		// Get elapsed time for this frame
		float elapsedTime = window.GetFrameTime();
		
		// Move the sprite
		if (window.GetInput().IsKeyDown(sf::Key::Left)){
			hero.moveLeft(elapsedTime);
		} else if (window.GetInput().IsKeyDown(sf::Key::Right)){
			hero.moveRight(elapsedTime);
		} else {
			hero.wait();
		}

		
		hero.moveDown(elapsedTime);
		hero.stayInLimits(window.GetWidth(), window.GetHeight());
		
		hero.animate();
		
        window.Clear(backgroundColor);
		window.Draw(hero.getSprite());
        window.Display();
    }

    return EXIT_SUCCESS;
}
