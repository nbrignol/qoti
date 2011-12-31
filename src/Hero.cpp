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
	
	sf::Image imageIdle;
	sf::Image imageLeft;
	sf::Image imageRight;
	sf::Image imageFall;
	
	this->imageIdle.SetSmooth(false); //to avoid any antialias
	this->imageIdle.LoadFromFile("hero_0002_face.png");
	
	this->imageLeft.SetSmooth(false); //to avoid any antialias
	this->imageLeft.LoadFromFile("hero_0003_lookleft.png");
	
	this->imageRight.SetSmooth(false); //to avoid any antialias
	this->imageRight.LoadFromFile("hero_0001_lookright.png");
	
	this->imageFall.SetSmooth(false); //to avoid any antialias
	this->imageFall.LoadFromFile("hero_0000_fall.png");
	
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
			this->sprite.SetImage(imageRight);
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

