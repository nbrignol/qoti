/*
 *  Hero.cpp
 *  The-Quest-of-the-Incrementalist
 *
 *  Created by Nicolas Brignol on 29/12/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Hero.h"
#include <iostream>

const int Hero::speed = 200;

Hero::Hero(){

	image.SetSmooth(false); //to avoid any antialias
	
	if (! image.LoadFromFile("hero.png")) {
		return;
	}
	
	this->sprite.SetImage(image);
};

void Hero::center(int width, int height){
	this->sprite.SetX((width - this->image.GetWidth()) / 2);
	this->sprite.SetY((height - this->image.GetHeight()) / 2);
};

void Hero::moveLeft(float elapsedTime){
	this->sprite.Move(-1 * Hero::speed * elapsedTime, 0);
	
};

void Hero::moveRight(float elapsedTime){
	this->sprite.Move(1 * Hero::speed * elapsedTime, 0);
};

void Hero::stayInLimits(int width, int height){
	
	int spriteX = this->sprite.GetPosition().x;
	int spriteWidth = this->sprite.GetSize().x;
	
	if (spriteX < 0){
		this->sprite.SetX(0);
	} else if (spriteX > width - spriteWidth){
		this->sprite.SetX(width - spriteWidth);
	}
}


sf::Sprite& Hero::getSprite(){
	return this->sprite;
};

