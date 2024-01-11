/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name Nicholas Morgan
Date 11/03/2023
*/

#include "Card.hpp"

/**
* Destructor
* @post: Destroy the Card object
*/
Card::~Card() {
    delete[] bitmap_;
    bitmap_ = nullptr;
}
/**
* Copy Constructor
* @post: Construct a new Card object
* @param: const reference to a Card object
*/
Card::Card(const Card& rhs) {

    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;
    if(rhs.bitmap_ == nullptr) {
        bitmap_ = nullptr;
    }
    else
    {
	    bitmap_ = new int[80];//creates a bitmap of size 80 as per project specifications
	    for(int i = 0; i < 80; ++i){
		    bitmap_[i] = rhs.bitmap_[i];
	    }
}
}
/**
* Copy Assignment Operator
* @param const reference to a Card object
* @return this Card object
*/
Card& Card::operator=(const Card& rhs) {
    
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;
    delete[] bitmap_;
    bitmap_ = nullptr;
    
    if(rhs.bitmap_ == nullptr) {
            bitmap_ = nullptr;
    }
        else
        {
		    bitmap_ = new int[80];
		    for(int i = 0; i < 80; ++i){
			    bitmap_[i] = rhs.bitmap_[i];
		    }
    return *this;
}
}
/**
* Move Constructor
* @param: rvalue reference to a Card object
*/
Card::Card(Card&& rhs) {
    instruction_ = std::move(rhs.instruction_); 
    drawn_ = std::move(rhs.drawn_);
    cardType_ = std::move(rhs.cardType_);
    bitmap_ = std::move(rhs.bitmap_);
    rhs.bitmap_ = nullptr;
    rhs.instruction_ = "";
    rhs.drawn_ = false;
}
/**
* Move assignment operator
* @param: rvalue reference to a Card object
* @return this card object
*/
Card& Card::operator=(Card&& rhs) {
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;
    bitmap_ = rhs.bitmap_;
    rhs.bitmap_ = nullptr;
    rhs.instruction_ = "";
    rhs.drawn_ = false;
    return *this;
}
/**
* Default Constructor
* @post: Construct a new Card object
*/
Card::Card() { 
    instruction_ = "";
    bitmap_ = nullptr;
    drawn_ = false;
    cardType_ = ACTION_CARD;

}
/**
* @return the string representation of the card type
*/
std::string Card::getType() const {
    if(cardType_ == ACTION_CARD) {
        return "ACTION_CARD";
    }
    return "POINT_CARD";
}
/**
* @post: set the card type
* @param const reference to a CardType object
*/
void Card::setType(const CardType& type) {
    cardType_ = type;
}

/**
* @return the string representation of the card instruction
*/
const std::string& Card::getInstruction() const {
    return instruction_;
}
/**
* @post: set the card instruction
* @param: const reference to an instruction
*/
void Card::setInstruction(const std::string& instruction) {
    instruction_ = instruction;
}
/**
* @return the image data
*/
const int* Card::getImageData() const {
    return bitmap_;

}
/**
* @post: Set the image data
* @param pointer to an array of integers
*/
void Card::setImageData(int* data) {
    bitmap_ = data;
}
/**
* @return the drawn status of the card
*/
bool Card::getDrawn() const {
    return drawn_;
}
/**
* @post: set the drawn status of the card
*
* @param: const reference to a boolean
*/
void Card::setDrawn(const bool& drawn) {
    drawn_ = drawn;
}
