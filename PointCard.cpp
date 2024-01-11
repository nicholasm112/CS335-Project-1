/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name Nicholas Morgan
Date 11/03/2023
*/

#include "PointCard.hpp"

/**
 * @post: Construct a new Point Card object
 */
PointCard::PointCard():Card() {
    setType(POINT_CARD);

}
/**
 * @return true if the card is playable, false otherwise
 * For a card to be playable, it has to be drawn and the instruction has
    to be a valid number
*/
bool PointCard::isPlayable()  {
    if(getDrawn() == false) {
        return false;
    }
    std::string s = getInstruction();
    int n = std::stoi(s);
    if(n >= 1 and n <=99) {
        return true;
    }
    return false;
}
/**
 * @post: Print the Point Card in the following format:
 * Type: [CardType]
 * Points: [Instruction]
 * Card:
 * [ImageData]
 *
 * Note: For [ImageData]: If there is no image data, print "No image data
" instead
 */
void PointCard::Print() const {
    std::cout << "Type: " << getType() << std::endl; 
    std::cout << "Points: " << getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;
    if(getImageData() == nullptr) {
        std::cout << "No image data";
    }
    else {
        for(int i = 0; i < 80; i++) {
            std::cout << getImageData()[i] << " ";
        }
    }
    std::cout << "\n";
    }
