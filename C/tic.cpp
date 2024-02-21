#include <iostream>

using namespace std;

// Declaring the individual nodes' makeup
struct Node {
    int position;
    char symbol;
    Node* next;
};

Node* create_nodes() {
    // Allocating memory for head
    Node* head = new Node;
    head->position = 1;
    head->symbol = ' '; // empty cell
    head->next = nullptr;

    // Creating remaining nodes and linking them
    Node* current = head;
    for (int i = 2; i <= 9; i++) {
        Node* newNode = new Node;
        newNode->position = i;
        newNode->symbol = ' ';
        newNode->next = nullptr;
        current->next = newNode;
        current = current->next;
    }
    return head;
}

void displayBoardState(Node* head) {
    Node* current = head;

    // For first 3 nodes
    for (int i = 1; i <= 3; i++) {
        cout << current->symbol << " | ";
        current = current->next;
        if (i % 3 == 0) {
            cout << endl;
        }
    }

    cout << "---" << endl;

    // For fourth to sixth nodes
    for (int i = 4; i <= 6; i++) {
        cout << current->symbol << " | ";
        current = current->next;
        if (i % 3 == 0) {
            cout << endl;
        }
    }

    cout << "---" << endl;

    // For last 3 nodes
    for (int i = 7; i <= 9; i++) {
        cout << current->symbol << " | ";
        current = current->next;
        if (i % 3 == 0) {
            cout << endl;
        }
    }
}

bool makeMove(Node* head, int position, char symbol) {
    Node* current = head;

    // Checking position of node
    while (current != nullptr && current->position != position) {
        current = current->next;
    }

    // Checking if node position is valid
    if (current == nullptr || current->symbol != ' ') {
        return false;
    }

    // Updating node symbol
    current->symbol = symbol;
    return true;
}

bool checkWin(Node* head, char symbol) {
    // Checking Rows
    if (head->symbol == symbol &&
      head->next->symbol == symbol &&
      head->next->next->symbol == symbol) {
    return true;
  }
        head = head->next->next->next;


    head = head->next->next->next->next;

    // Checking columns
    for (int i = 1; i <= 3; i++) {
        if (head->symbol == symbol &&
            head->next->next->next->symbol == symbol &&
            head->next->next->next->next->next->next->symbol == symbol) {
            return true;
        }
        head = head->next->next->next->next->next;
    }

    // Checking first diagonal
    if (head->symbol == symbol &&
        head->next->next->symbol == symbol &&
        head->next->next->next->
        next->
        next->
        next->
        next->
        next->
        symbol == symbol) {

        return true;
    }

   // Checking last diagonal
   if (head->symbol == symbol &&
       head->next->next->next->next->symbol == symbol &&
       head->next->next->next->next->next->symbol) {

        return true;
   }

   return false;
}

enum class Player { X, O };
ostream& operator<<(ostream& os, Player player) {
  switch (player) {
    case Player::X:
      os << 'X';
      break;
    case Player::O:
      os << 'O';
      break;
  }
  return os;
};

enum class GameState { PLAYING, WON_X, WON_O, DRAW };

Player currentPlayer = Player::X;
Player nextPlayer = Player::O;
GameState gameState = GameState::PLAYING;
char winnerSymbol = ' ';
int turnCount = 0;

bool isPositionEmpty(Node* head, int position) {
    Node* current = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    return current != nullptr && current->symbol == ' ';
}

bool isValidPosition(int position) {
    // Check if the position is within the valid range (1-9)
    return (position >= 1 && position <= 9);
}

int getPlayerInput(Node* head) {
    int position;
    do {
        cout << "Player " << currentPlayer << ", Enter move (1-9): ";
        cin >> position;
    } while (!isPositionEmpty(head, position) || !isValidPosition(position));

    return position;
}

void playGame(Node* head) {
    while (gameState == GameState::PLAYING) {
        int position = getPlayerInput(head);

        if (makeMove(head, position, currentPlayer)) {
            if (checkWin(head, currentPlayer)) {
                gameState = (currentPlayer == Player::X) ? GameState::WON_X : GameState::WON_O;
                winnerSymbol = currentPlayer;
            } else if (turnCount == 9) {
                gameState = GameState::DRAW;
            } else {
                currentPlayer = nextPlayer;
                nextPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
            }

            displayBoardState(head);
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    if (gameState == GameState::WON_X) {
        cout << "Player X wins!" << endl;
    } else if (gameState == GameState::WON_O) {
        cout << "Player O wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
}

int main() {
    Node* head = create_nodes();
    displayBoardState(head);
    playGame(head);

    return 0;
}
