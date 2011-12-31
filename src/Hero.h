/*
 *  Hero.h
 *  The-Quest-of-the-Incrementalist
 *
 *  Created by Nicolas Brignol on 29/12/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <SFML/Graphics.hpp>
#include <vector>

enum HeroStatus {
	Idle,
	WalkingLeft,
	WalkingRight,
	Falling
};

class Hero {

protected:
	static const int speed; 
	
	std::vector<sf::Image> images;
	int currentImage;
	
	sf::Sprite sprite;
	sf::Image imageIdle;
	sf::Image imageLeft;
	sf::Image imageRight;
	sf::Image imageFall;
	
	HeroStatus lastStableStatus;
	HeroStatus currentStatus;
	
	
public:
	Hero();
	
	void moveLeft(float elapsedTime);
	void moveRight(float elapsedTime);
	void moveDown(float elapsedTime);
	void center(int width, int height);
	void stayInLimits(int width, int height);
	
	void setCurrentStatus(HeroStatus newStatus, bool isStable);
	void restoreLastStableStatus();
	void animate();
	
	sf::Sprite& getSprite();
};
