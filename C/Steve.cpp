#include <iostream>

using namespace std;

// Define Player
enum class Player { X, O };

// Overload operator<< for Player
ostream& operator<<(ostream& os, Player player) {
  return os << (player == Player::X ? "X" : "O");
}

// Define GameState
enum class GameState { PLAYING, WON_X, WON_O, DRAW };

// Node structure for the board representation
struct Node {
  int position;
  char symbol;
  Node* next;
};

// Function to create the linked list representation of the board
Node* create_nodes() {
  Node* head = new Node;
  head->position = 1;
  head->symbol = ' ';
  head->next = nullptr;

  Node* current = head;
  for (int i = 2; i <= 9; ++i) {
    Node* newNode = new Node;
    newNode->position = i;
    newNode->symbol = ' ';
    newNode->next = nullptr;
    current->next = newNode;
    current = current->next;
  }

  return head;
}

// Function to display the current board state
void displayBoardState(const Node* head) {
  Node* current = head;
  for (int i = 1; i <= 9; ++i) {
    cout << current->symbol << " | ";
    current = current->next;
    if (i % 3 == 0) {
      cout << endl;
    }
  }
}

// Function to check if a specific position is empty
bool isPositionEmpty(const Node* head, int position) {
  const Node* current = head;
  while (current != nullptr && current->position != position) {
    current = current->next;
  }
  return current != nullptr && current->symbol == ' ';
}

// Function to check if a position is valid (within 1-9)
bool isValidPosition(int position) {
  return (position >= 1 && position <= 9);
}

// Function to make a move on the board for a given player
bool makeMove(Node* head, int position, char symbol) {
  Node* current = head;
  while (current != nullptr && current->position != position) {
    current = current->next;
  }

  if (current == nullptr || current->symbol != ' ') {
    return false; // Invalid move
  }

  current->symbol = symbol;
  return true;
}

// Function to check if a player has won
bool checkWin(const Node* head, char symbol) {
  // Check rows
  for (int i = 1; i <= 3; ++i) {
    if (head->symbol == symbol && head->next->symbol == symbol && head->next->next->symbol == symbol) {
      return true;
    }
    head = head->next->next->next;
  }

  // Check columns
  head = head->next->next->next->next; // Reset head to start of second column
  for (int i = 1; i <= 3; ++i) {
    if (head->symbol == symbol && head->next->next->next->symbol == symbol && head->next->next->next->next->next->next->symbol == symbol) {
      return true;
    }
    head = head->next->next->next->next->next;
  }

  // Check diagonals
  if (head->symbol == symbol && head->next->next->symbol == symbol && head->next->next->next->next->next->next->next->symbol == symbol) {
    return true;
  }
  head = head->next->next->next->next->next; // Reset head to start of second diagonal
  if (head->symbol == symbol && head->next->next->next->next->symbol == symbol && head->next->next->next->next->next->symbol == symbol) {
    return true;
  }

  return false;
}

Player currentPlayer = Player::X;
// Function to get valid player input
int getPlayerInput(const Node* head) {
  int position;
  do {
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> position;
  } while (!isPositionEmpty(head, position) && !isValidPosition(position));
  return position;
}

// Main game loop
int main() {
  // Create the game board
  Node* head = create_nodes();

  // Initialize game state variables
  Player currentPlayer = Player::X;
  Player nextPlayer = Player::O;
  GameState gameState = GameState::PLAYING;
  char winnerSymbol = ' ';
  int turnCount = 0;

  // Start the game loop
  while (gameState == GameState::PLAYING) {
    // Display the current board state
    displayBoardState(head);

    // Get valid player input
    int position = getPlayerInput(head);

    // Make the move
    if (makeMove(head, position, currentPlayer)) {
      // Check if the move resulted in a win
      if (checkWin(head, currentPlayer)) {
        gameState = (currentPlayer == Player::X) ? GameState::WON_X : GameState::WON_O;
        winnerSymbol = currentPlayer;
        break; // Exit the loop if someone wins
      }

      // Check if it's a draw
      if (++turnCount == 9) {
        gameState = GameState::DRAW;
        break; // Exit the loop if it's a draw
      }

      // Switch to the next player
      currentPlayer = nextPlayer;
      nextPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
    } else {
      cout << "Invalid move. Try again." << endl;
    }
  }

  // Display the final game state
  displayBoardState(head);

  if (gameState == GameState::WON_X) {
    cout << "Player X wins!" << endl;
  } else if (gameState == GameState::WON_O) {
    cout << "Player O wins!" << endl;
  } else {
    cout << "It's a draw!" << endl;
  }

  // Free the allocated memory for the board
  Node* current = head;
  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  }

  return 0;
}

