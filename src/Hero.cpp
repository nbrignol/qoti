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
#include <sstream>

const int Hero::speed = 200;


sf::Image& Hero::getImage(sf::Image& image, std::string prefix, int number){
	
	std::ostringstream oss;
	oss << prefix << number << ".png";
	std::string filename = oss.str();
	
	image.SetSmooth(false); //to avoid any antialias
	image.LoadFromFile(oss.str());
	
	return image;
}


Hero::Hero(){

	this->setCurrentStatus(Idle, true);
	
	for (int i=1; i<5; i++) {
		sf::Image image;
		animationIdle.push_back(this->getImage(image, "hero_idle", i));
	}

	for (int i=1; i<5; i++) {
		sf::Image image;
		animationWalkLeft.push_back(this->getImage(image, "hero_walkleft", i));
	}
	
	for (int i=1; i<5; i++) {
		sf::Image image;
		animationWalkRight.push_back(this->getImage(image, "hero_walkright", i));
	}
	

	for (int i=1; i<3; i++) {
		sf::Image image;
		animationFall.push_back(this->getImage(image, "hero_fall", i));
	}
	
	currentIdleImage = 0;
	currentWalkLeftImage = 0;
	currentWalkRightImage = 0;
	currentFallImage = 0;
	
	//this->sprite.SetImage(imageIdle);
};

void Hero::center(int width, int height){
	//this->sprite.SetX((width - this->imageIdle.GetWidth()) / 2);
	//this->sprite.SetY((height - this->imageIdle.GetHeight()) / 2);
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

void Hero::wait(){
	this->setCurrentStatus(Idle, true);
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
			this->sprite.SetImage(this->animationWalkLeft.at(currentWalkLeftImage/100));
			break;
		case WalkingRight:
			this->sprite.SetImage(this->animationWalkRight.at(currentWalkRightImage/100));
			break;
		case Falling:
			this->sprite.SetImage(this->animationFall.at(currentFallImage/1000));
			break;
		case Idle:
			this->sprite.SetImage(this->animationIdle.at(currentIdleImage/1000));
			break;
		default:
			break;
	}
	
	return this->sprite;
};

void Hero::animate(){
	currentWalkRightImage++;
	if (currentWalkRightImage > 390) currentWalkRightImage=0;
	
	currentWalkLeftImage++;
	if (currentWalkLeftImage > 390) currentWalkLeftImage=0;
	
	currentIdleImage++;
	if (currentIdleImage > 3900) currentIdleImage=0;
	
	currentFallImage++;
	if (currentFallImage > 1900) currentFallImage=0;
}

