// EM168887 Steve Gutfreund
// 203829478 Avshalom Tam

#ifndef PLAYER_H
#define PLAYER_H
#include "Coordinates.h"

#ifndef CELL
#define CELL
enum cell {empty, first_player, second_player};
#endif

/**
 * Representing a player in the game.
 */
class Player {
public:
    /**
     * Constructor.
     */
    Player(cell num_player);
    /**
     * Sets the name of the player for this game.
     * @param name string
     */
    void setName(string name);
    /**
     * @return name of the player
     */
    string getName() const;
    /**
     * Gets a move from the player.
     * @return coordinates
     */
    virtual Coordinates getMove() const = 0;
    /**
     * Sets had_move to be true or false according to played.
     * @param played stating if the player had a move
     */
    void hasMove(bool played);
    /**
     * Checks if the player had a move.
     * @return true if player had a move, false otherwise
     */
    bool played() const;
    /**
     * @return number of the player, 1 or 2
     */
    cell getId() const;
private:
    bool had_move_;
    cell player_id_;
    string name_;
};

#endif //PLAYER_H