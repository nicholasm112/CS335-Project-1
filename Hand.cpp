/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name Nicholas Morgan
Date 11/03/2023
*/

#include "Hand.hpp"

//constructor
Hand::Hand(){

}

//destructor
Hand::~Hand(){

}
//copy constructor
Hand::Hand(const Hand& other){
    cards_=other.cards_;
}

//copy assignment operator
Hand& Hand::operator=(const Hand& other){
    if(this!=&other){
        cards_=other.cards_;
    }
    return *this;
}

//move Constructor @Param:other hand object
Hand::Hand(Hand&& other){
    cards_=std::move(other.cards_);
}

/**move assignment operator @param: other Hand object
  @return this Hand
**/
Hand& Hand:: operator=(Hand&&other){
    if(this !=&other){
        cards_=std::move(other.cards_);
    }
    return *this;
}

//@return Hand
const std::deque<PointCard>& Hand::getCards() const{
    return cards_;
}

/**
* @post: Add a card to the hand
* @param PointCard object
*/
void Hand::addCard(PointCard&& card){
    card.setDrawn(true);
    cards_.push_back(std::move(card));
}

//@return true if hand is empty, false otherwise
bool Hand::isEmpty() const{
    return (cards_.empty()); //stl library
}

//@post: Reverse the hand
void Hand::Reverse(){
    int i =0;
    int j=cards_.size()-1;
    while(i<j){
        std::swap(cards_[i],cards_[j]);
        i++;
        j--;
    }
}

/**
* @post: Play the card at the front of the hand, removing it from the hand
* Throws an exception if the hand is empty or the card is not playable
* If the card is not playable, the card is removed from the hand
* @return the points earned from playing the card
*/
int Hand::PlayCard(){
     if(cards_.empty()){
        throw std::runtime_error("Empty Hand");
    }
    int my_score=0;
    if(cards_.front().isPlayable()){
        my_score = std::stoi(cards_.front().getInstruction());
        cards_.pop_front();
    }
    else{
        cards_.pop_front();
    }
    return my_score;
}