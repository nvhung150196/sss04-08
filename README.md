# Snake Game - Group Exam Project

## Overview
This is a classic Snake game implementation built with C++ as part of a group student examination project. The game features a console-based interface with player name input, score tracking, and persistent high score leaderboard.

## Game Description
The Snake game is a classic arcade game where the player controls a snake that moves around the screen. The objective is to eat food items (*) that appear randomly, which makes the snake grow longer. The game ends when the snake collides with the walls or its own body.

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
- Player name input system
- Classic snake gameplay with smooth controls
- Real-time score tracking (10 points per food)
- Persistent score saving to file
- Top 10 high scores leaderboard
- Collision detection (walls and self)
- Snake growth mechanics
- Cross-platform terminal support (macOS/Linux)

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
1. Run the game executable
2. Enter your player name (or press Enter for "Anonymous")
3. Press W, A, S, or D to start moving
4. Guide the snake to eat the food (*)
5. Each food eaten adds 10 points and grows the snake
6. Avoid hitting the walls (#) or your own body (o)
7. When the game ends, your score is automatically saved
8. View the top 10 high scores leaderboard

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
- All historical scores are preserved in the file

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
