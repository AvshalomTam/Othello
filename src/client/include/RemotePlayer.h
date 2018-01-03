#ifndef OTHELLO_REMOTEPLAYER_H
#define OTHELLO_REMOTEPLAYER_H
#include "Player.h"
#include "Display.h"
#include "Listener.h"
/**
 * This class is for a player playing through a server.
 */
class RemotePlayer : public Player {
  public:
	/**
	 * Constructor.
	 * @param numplayer number of player
	 * @param clientSocket socket of the client
	 * @param gameflow Display object
	 * @param listener Listener to the game
	 */
	RemotePlayer(cell numplayer, int clientSocket, Display &gameflow, Listener& listener);
	Coordinates getMove();
	void message();
    ~RemotePlayer();
  private:
	Display& gameflow_;
	int clientSocket_;
	Listener& listener_;
};
#endif //OTHELLO_REMOTEPLAYER_H
