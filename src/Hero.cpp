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

	this->setCurrentStatus(Idle, true);
	
	this->imageIdle.SetSmooth(false); //to avoid any antialias
	this->imageIdle.LoadFromFile("hero_idle1.png");
	
	sf::Image image1;	
	sf::Image image2;	
	sf::Image image3;	
	sf::Image image4;
	
	image1.SetSmooth(false); //to avoid any antialias
	image1.LoadFromFile("hero_walkright1.png");
	image2.SetSmooth(false); //to avoid any antialias
	image2.LoadFromFile("hero_walkright2.png");
	image3.SetSmooth(false); //to avoid any antialias
	image3.LoadFromFile("hero_walkright3.png");
	image4.SetSmooth(false); //to avoid any antialias
	image4.LoadFromFile("hero_walkright4.png");
	
	images.push_back(image1);
	images.push_back(image2);
	images.push_back(image3);
	images.push_back(image4);
	currentImage = 0;
	
	this->imageLeft.SetSmooth(false); //to avoid any antialias
	this->imageLeft.LoadFromFile("hero_walkleft1.png");
	
	this->imageRight.SetSmooth(false); //to avoid any antialias
	this->imageRight.LoadFromFile("hero_walkright1.png");
	
	this->imageFall.SetSmooth(false); //to avoid any antialias
	this->imageFall.LoadFromFile("hero_fall1.png");
	
	this->sprite.SetImage(imageIdle);
};

void Hero::center(int width, int height){
	this->sprite.SetX((width - this->imageIdle.GetWidth()) / 2);
	this->sprite.SetY((height - this->imageIdle.GetHeight()) / 2);
};

void Hero::moveLeft(float elapsedTime){
	this->setCurrentStatus(WalkingLeft, true);
	this->sprite.Move(-1 * Hero::speed * elapsedTime, 0);
};

void Hero::moveRight(float elapsedTime){
	this->setCurrentStatus(WalkingRight, true);
	this->sprite.Move(1 * Hero::speed * elapsedTime, 0);
};

void Hero::moveDown(float elapsedTime){
	this->sprite.Move(0, 1 * Hero::speed * elapsedTime);
	this->setCurrentStatus(Falling, false);
};

void Hero::stayInLimits(int width, int height){
	
	int spriteX = this->sprite.GetPosition().x;
	int spriteY = this->sprite.GetPosition().y;
	int spriteWidth = this->sprite.GetSize().x;
	int spriteHeight = this->sprite.GetSize().y;
	
	if (spriteX < 0){
		this->sprite.SetX(0);
		this->restoreLastStableStatus();
	} else if (spriteX > width - spriteWidth){
		this->sprite.SetX(width - spriteWidth);
		this->restoreLastStableStatus();
	}
	
	if (spriteY >= height - spriteHeight){
		this->sprite.SetY(height - spriteHeight);
		this->restoreLastStableStatus();
	}
};

void Hero::setCurrentStatus(HeroStatus newStatus, bool isStable){
	if (isStable) {
		this->lastStableStatus = newStatus;
	}
	
	this->currentStatus = newStatus;
};

void Hero::restoreLastStableStatus(){
	this->currentStatus = this->lastStableStatus;
}

sf::Sprite& Hero::getSprite(){
	
	switch (currentStatus) {
		case WalkingLeft:
			this->sprite.SetImage(imageLeft);
			break;
		case WalkingRight:
			this->sprite.SetImage(this->images.at(currentImage/100));
			break;
		case Falling:
			this->sprite.SetImage(imageFall);
			break;
		case Idle:
			this->sprite.SetImage(imageIdle);
			break;
		default:
			break;
	}
	
	return this->sprite;
};

void Hero::animate(){
	currentImage++;
	if (currentImage > 390) currentImage=0;
}

