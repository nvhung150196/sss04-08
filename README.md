# Snake Game - Group Exam Project

## Overview
This is a classic Snake game implementation built with C++ as part of a group student examination project. The game features a console-based interface with an interactive main menu, player name input, score tracking, and persistent high score leaderboard.

## Game Description
The Snake game is a classic arcade game where the player controls a snake that moves around the screen. The objective is to eat food items (*) that appear randomly, which makes the snake grow longer. The game ends when the snake collides with the walls or its own body.

## Main Menu
When you start the game, you'll see the main menu with the following options:

```
========================================
       WELCOME TO SNAKE GAME!
========================================

1. Play Game
2. View High Scores
3. Exit

Enter your choice (1-3):
```

**Menu Options:**
- **Option 1 (Play Game):** Start a new game session
- **Option 2 (View High Scores):** Display the top 10 highest scores without playing
- **Option 3 (Exit):** Quit the application

## Game Display
```
##########################################
#                                        #
#       *                                #
#                                        #
#                                        #
#                                        #
#                                        #
#                                        #
#                                        #
#                                        #
#                                        #
#                                        #
#                                        #
#    o                                   #
#    O                                   #
#                                        #
#                                        #
#                                        #
#                                        #
#                                        #
#                                        #
##########################################
Player: YourName | Score: 10
Controls: W=Up, A=Left, S=Down, D=Right, X=Exit
```

**Legend:**
- `#` - Walls (boundaries)
- `O` - Snake head
- `o` - Snake body
- `*` - Food

## Features
- **Interactive Main Menu** - Easy navigation between playing, viewing scores, and exiting
- **Player name input system** - Personalize your gameplay experience
- **Classic snake gameplay** - Smooth controls with WASD keys
- **Real-time score tracking** - 10 points per food item collected
- **Persistent score saving** - All scores automatically saved to file
- **Top 10 high scores leaderboard** - View best scores anytime from the menu
- **Collision detection** - Accurate wall and self-collision detection
- **Snake growth mechanics** - Snake grows with each food item eaten
- **Multiple game sessions** - Play again without restarting the application
- **Cross-platform terminal support** - Works on macOS and Linux

## Requirements
- C++ compiler with C++11 support (g++, clang++)
- POSIX-compliant terminal (macOS, Linux, Unix)
- Standard C++ libraries

## How to Build and Run
```bash
# Compile the game
g++ -std=c++11 snake_game.cpp -o snake_game

# Run the game
./snake_game
```

## Controls
- **W** - Move Up
- **A** - Move Left
- **S** - Move Down
- **D** - Move Right
- **X** - Exit game

## How to Play
1. Run the game executable (`./snake_game`)
2. Select an option from the main menu:
   - **Option 1:** Play a new game
   - **Option 2:** View high scores
   - **Option 3:** Exit
3. If you choose to play:
   - Enter your player name (or press Enter for "Anonymous")
   - Press W, A, S, or D to start moving the snake
   - Guide the snake to eat the food (*)
   - Each food eaten adds 10 points and grows the snake
   - Avoid hitting the walls (#) or your own body (o)
4. When the game ends:
   - Your score is automatically saved
   - Top 10 high scores are displayed
   - Press Enter to return to the main menu
5. Play again or view high scores from the menu

## Game Rules
1. The snake continuously moves in the current direction
2. You can change direction but cannot move backward into yourself
3. Eating food increases your score by 10 points
4. Each food eaten makes the snake grow by one segment
5. Game over occurs when:
   - The snake hits the wall boundaries
   - The snake collides with its own body
6. Try to achieve the highest score possible!

## Score System
- Scores are saved to `snake_scores.txt` file
- Each score record includes: player name, score, and timestamp
- Top 10 scores are displayed after each game
- High scores can be viewed anytime from the main menu (Option 2)
- All historical scores are preserved in the file
- Leaderboard shows player names and their highest scores

**High Scores Display Example:**
```
========================================
          HIGH SCORES
========================================
1. Hồng Hạnh - 150 points
2. Văn Hùng - 120 points
3. Gia Mẫn - 100 points
4. Anonymous - 80 points
...
========================================
```

## Group Members
- Nguyễn Văn Hùng
- Ngô Thị Hồng Hạnh
- Lục Gia Mẫn

## File Structure
```
.
├── snake_game.cpp      # Main game source code
├── snake_game          # Compiled executable
├── snake_scores.txt    # Score data file (auto-generated)
├── README.md           # This file
└── .gitignore         # Git ignore configuration
```

## Technical Details
- Language: C++11
- Platform: macOS/Linux (POSIX terminals)
- Terminal control: termios, fcntl
- File I/O: Standard C++ streams
- Data format: CSV (name, score, timestamp)

## License
This project is created for educational purposes.
