/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name Nicholas Morgan
Date 11/03/2023
*/

#include "Player.hpp"

//constructor @post: Construct a new Player object
Player::Player(){
    score_=0;
    opponent_=nullptr;
    actiondeck_=nullptr;
    pointdeck_=nullptr;
}

//destructor @post: Destroy the Player object
Player::~Player(){
    delete opponent_;
    opponent_=nullptr;
    delete actiondeck_;
    actiondeck_=nullptr;
    delete pointdeck_;
    pointdeck_=nullptr;
}

/**
 * @return the player's hand
*/
const Hand& Player::getHand() const{
    return hand_;
}

/**
 * @post: Set the player's hand
 * @param const reference to a hand object
*/
void Player::setHand(const Hand& hand){
    hand_ = hand;
}

/**
 * @return the Player's current score
*/
int Player::getScore() const{
    return score_;
}


/**
 * @post: Set the player's score
 * @param: score 
*/
void Player::setScore(const int& score){
    score_ = score;
}


/**
* @post: Play a given action card
* @param: an Actioncard object
* Begin the function by reporting the instruction of the card:
* PLAYING ACTION CARD: [instruction]
*/
void Player::play(ActionCard&& card){
    // cout the played action card's instruction
    std::cout << "PLAYING ACTION CARD: "<< card.getInstruction() << std::endl;
    // get the instruction from the card
    std::string instruction = card.getInstruction();
    // check the type of action card and do the actions
    if(instruction == "REVERSE HAND"){
        // reverses the order of cards in the player's hand
        hand_.Reverse();
    }
    else if(instruction == "SWAP HAND WITH OPPONENT"){
        // swaps hands with the opponent
        Hand temp = hand_;
        setHand(opponent_->getHand());
        opponent_->setHand(temp);

    }
    else{
        //here we process and carry out the actions on the cards

        //break down the isntruction string
        std::vector<std::string> line;
        std::string word="";
        int size = instruction.size();
        for(int i=0; i<size; i++){
            if(instruction[i] == ' '){
                line.push_back(word);
                word="";
            }
            else{
                word+= instruction[i];
            }
        }
        if(line[0] == "PLAY"){
            // plays a specific number of point cards from the player's hand
            for(int i=0; i<std::stoi(line[1]); i++){
                playPointCard();
            }
        }
        else if(line[0] == "DRAW"){
            // draws a specific number of point cards and adds them to the player's hand
            for(int i=0; i<std::stoi(line[1]); i++){
                drawPointCard();
            }
        }
    }   
}

//@post: Draw a point card and place it in the player's hand

void Player::drawPointCard(){
    // add the drawn point card to the player's hand
    if(pointdeck_ != nullptr){
        hand_.addCard(std::move(pointdeck_->Draw()));
    }
}

//@post: Play a point card from the player's hand and update the player's score
void Player::playPointCard(){
    if(!hand_.isEmpty()){
        // play a point card from the player's hand and update the player's score
        setScore(getScore() + hand_.PlayCard());
    }
    
}

/**
* @post: Set the opponent of the player
* @param a pointer to a Player opponent 
*/
void Player::setOpponent(Player* opponent){
    opponent_ = opponent;
}


//@return: a pointer to the player's opponent

Player* Player::getOpponent(){
    return opponent_;
}


//return a pointer to the player's action deck 
Deck<ActionCard>* Player::getActionDeck(){
    return actiondeck_;
}
/**
 * @post: set the action deck of the player 
 * @param: A pointer to a deck holding Action cards 
*/
void Player::setActionDeck(Deck<ActionCard>* actiondeck){
    actiondeck_= actiondeck;
}

/**
* @post: set the point deck of the player
* @param: A pointer to a deck holding Point cards
*/
void Player::setPointDeck(Deck<PointCard>* pointdeck){
    pointdeck_ = pointdeck;
}

/**
 * @return: a pointer to the player's point deck
*/
Deck<PointCard>* Player::getPointDeck(){
    return pointdeck_;
}