/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name Nicholas Morgan
Date 11/03/2023
*/

#include "ActionCard.hpp"

/**
         * @post: Construct a new Action Card object
        */
ActionCard::ActionCard():Card() {
    setType(ACTION_CARD);
}

        /**
         * @return true if the card is playable, false otherwise
         * For a card to be playable, it has to be drawn and the instruction has to be valid
         * Valid instructions:
         * DRAW x CARD(S) : assume x is a positive integer
         * PLAY x CARD(S) : assume x is a positive integer
         * REVERSE HAND : reverse the order of the cards in the hand
         * SWAP HAND WITH OPPONENT : swap the hand with the opponent
        */
    bool ActionCard::isPlayable() {
        if (getDrawn() == false) {
            return false;
        }
        std::string s = getInstruction().substr(0,3);
        if(s == "DRA" || s == "PLA" || s == "REV" || s == "SWA") {
            return true;
        }
        return false;
        

    }
        
        /**
         * @post: Print the ActionCard in the following format:
         * Type: [CardType]
         * Instruction: [Instruction]
         * Card: 
         * [ImageData]
         * 
         * Note: For [ImageData]: If there is no image data, print "No image data" instead
         */
        void ActionCard::Print() const {
            std::cout <<"Type: "<< getType() << std::endl 
              <<"Instruction: "<< getInstruction() << std::endl
              <<"Card:  "<<std::endl;

            if (getImageData() == nullptr) {
                std::cout << "No image data";
            }
            else
            {
                for(int i = 0; i < 80; i++) {
                    std::cout << getImageData()[i] << " ";
                }
            }

            std::cout << "\n";
        }
