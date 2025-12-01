#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unistd.h>     // For usleep()
#include <termios.h>    // For terminal control
#include <fcntl.h>      // For non-blocking input

using namespace std;

// Game constants
const int WIDTH = 40;
const int HEIGHT = 20;

// Direction enumeration
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

// Game variables
int score;
bool gameOver;

// Snake head position
int headX, headY;

// Food position
int foodX, foodY;

// Snake tail
vector<pair<int, int>> tail;

// Current direction
Direction dir;

// Terminal settings
struct termios oldSettings, newSettings;

// Function prototypes
void Setup();
void Draw();
void Input();
void Logic();
void EnableRawMode();
void DisableRawMode();
int kbhit();

int main() {
    EnableRawMode();
    Setup();

    while (!gameOver) {
        Draw();
        Input();
        Logic();
        usleep(150000); // 150ms delay (control game speed)
    }

    DisableRawMode();
    cout << "\n\nGame Over! Final Score: " << score << endl;
    cout << "Press any key to exit..." << endl;
    cin.get();

    return 0;
}

void EnableRawMode() {
    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);

    // Set non-blocking input
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}

void DisableRawMode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);

    // Restore blocking input
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags & ~O_NONBLOCK);
}

int kbhit() {
    char ch;
    int nread = read(STDIN_FILENO, &ch, 1);
    if (nread == 1) {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

void Setup() {
    gameOver = false;
    dir = STOP;
    headX = WIDTH / 2;
    headY = HEIGHT / 2;
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;
    score = 0;
    srand(time(0));
    tail.clear();
}

void Draw() {
    // Clear screen - use system command for better compatibility
    system("clear");

    // Top border
    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;

    // Game area
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == 0)
                cout << "#"; // Left border

            // Check if this is the snake head
            if (x == headX && y == headY)
                cout << "O";
            // Check if this is food
            else if (x == foodX && y == foodY)
                cout << "*";
            else {
                // Check if this is part of the tail
                bool isTail = false;
                for (auto& segment : tail) {
                    if (segment.first == x && segment.second == y) {
                        cout << "o";
                        isTail = true;
                        break;
                    }
                }
                if (!isTail)
                    cout << " ";
            }

            if (x == WIDTH - 1)
                cout << "#"; // Right border
        }
        cout << endl;
    }

    // Bottom border
    for (int i = 0; i < WIDTH + 2; i++)
        cout << "#";
    cout << endl;

    // Display score and controls
    cout << "Score: " << score << endl;
    cout << "Controls: W=Up, A=Left, S=Down, D=Right, X=Exit" << endl;
    if (dir == STOP) {
        cout << "Press W to start!" << endl;
    }
    cout << flush; // Force output
}

void Input() {
    char key;
    if (read(STDIN_FILENO, &key, 1) == 1) {
        switch (key) {
            case 'a':
            case 'A':
                if (dir != RIGHT) dir = LEFT;
                break;
            case 'd':
            case 'D':
                if (dir != LEFT) dir = RIGHT;
                break;
            case 'w':
            case 'W':
                if (dir != DOWN) dir = UP;
                break;
            case 's':
            case 'S':
                if (dir != UP) dir = DOWN;
                break;
            case 'x':
            case 'X':
                gameOver = true;
                break;
        }
    }
}

void Logic() {
    // Store previous head position for tail
    if (dir != STOP) {
        int prevX = headX;
        int prevY = headY;

        // Move snake head based on direction
        switch (dir) {
            case LEFT:
                headX--;
                break;
            case RIGHT:
                headX++;
                break;
            case UP:
                headY--;
                break;
            case DOWN:
                headY++;
                break;
        }

        // Update tail positions
        if (!tail.empty()) {
            tail.insert(tail.begin(), make_pair(prevX, prevY));
            tail.pop_back();
        }

        // Check collision with walls
        if (headX < 0 || headX >= WIDTH || headY < 0 || headY >= HEIGHT) {
            gameOver = true;
        }

        // Check collision with tail
        for (auto& segment : tail) {
            if (segment.first == headX && segment.second == headY) {
                gameOver = true;
            }
        }

        // Check if snake ate food
        if (headX == foodX && headY == foodY) {
            score += 10;
            foodX = rand() % WIDTH;
            foodY = rand() % HEIGHT;

            // Grow the tail
            if (!tail.empty()) {
                tail.push_back(tail.back());
            } else {
                tail.push_back(make_pair(prevX, prevY));
            }
        }
    }
}
