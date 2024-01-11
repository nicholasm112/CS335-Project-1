#include "Deck.hpp"
//Basic constructor
template <typename CardType> Deck<CardType>::Deck(){
    cards_={};//intiializes empty vector
}

//Destructor
template <typename CardType> Deck<CardType>::~Deck(){
    cards_.clear();//clears vectir
}

//Add a card to the deck
template <typename CardType> void Deck<CardType>::AddCard(const CardType& card){
    cards_.push_back(card);
}
   
/**
* @post: Draw a card from the deck
* @pre: the deck is not empty
* @return the right hand value of type CardType 
*/      
template <typename CardType> CardType&& Deck<CardType>::Draw(){    
    cards_.front().setDrawn(true);//card is drawn
    CardType&& temp = std::move(cards_.back());
    cards_.pop_back();//take card out deck
    return std::move(temp);//return card as rvalue ref
       

}
//@return: bool value on whether deck has any cards or not
template <typename CardType> bool Deck<CardType>::IsEmpty() const{
    return cards_.empty();
}

/*
* @post: Shuffle the deck
* Create a random number generator using std::mt19937 with seed 2028358904,
* then call std::shuffle on the vector of cards, and with the random number generator as the third argument.
* https://en.cppreference.com/w/cpp/algorithm/random_shuffle
* https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine*/
template <typename CardType> void Deck<CardType>::Shuffle(){
std::mt19937 rand(2028358904);
std::shuffle(cards_.begin(),cards_.end(),rand);
}
//getter for deck size
//@return : int size of deck
template <typename CardType> int Deck<CardType>::getSize() const{
return cards_.size();
}
//getter for entire deck
//@return :vector holding the deck/cards
template <typename CardType> std::vector<CardType> Deck<CardType>::getDeck() const{
return cards_;
}