/*
 *  Hero.h
 *  The-Quest-of-the-Incrementalist
 *
 *  Created by Nicolas Brignol on 29/12/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <SFML/Graphics.hpp>

class Hero {

protected:
	static const int speed; 
	
	sf::Sprite sprite;
	sf::Image image;
	
public:
	Hero();
	
	void moveLeft(float elapsedTime);
	void moveRight(float elapsedTime);
	void moveDown(float elapsedTime);
	void center(int width, int height);
	void stayInLimits(int width, int height);
	
	sf::Sprite& getSprite();
};
