# 🎮 Rock, Paper, Scissors Game (C++)

This is a simple console-based **Rock, Paper, Scissors** game written in C++. The user plays against the computer over a number of rounds, and the final winner is announced based on the round results.

---

## 📌 Features

- Play Rock, Paper, Scissors against the computer.
- Choose how many rounds to play (1 to 10).
- Random computer moves.
- Colored output to indicate win/loss/draw.
- Final game summary showing total results.
- Option to replay the game.

---

## 🛠️ How It Works

1. The user chooses how many rounds to play (between 1 and 10).
2. For each round:
   - The player chooses Rock, Paper, or Scissors.
   - The computer randomly chooses one of the three.
   - The winner is determined according to classic RPS rules.
3. After all rounds are completed:
   - The game displays a summary with total wins, losses, and draws.
   - The overall winner is announced.
4. The user is asked if they want to play again.

---

## 🧠 Game Logic

- Rock beats Scissors  
- Scissors beats Paper  
- Paper beats Rock  
- If both choose the same, it's a draw

---

## 🖥️ How to Run

1. **Clone or download the project** to your local machine.
2. **Compile the code** using any C++ compiler like `g++`:
   
```bash
g++ rps_game.cpp -o rps_game
./rps_game
```


---

## 🗂️ File Structure

```
📁 Project
│
├── rps_game.cpp       # Main C++ source file
├── README.md          # Project documentation
```

---

## 🔧 Functions Overview

| Function Name         | Purpose |
|----------------------|---------|
| `ReadPositiveNumber` | Reads a valid number of rounds (1–10). |
| `ReadPlayerChoice`   | Reads player's RPS choice. |
| `ComputerRPSChoice`  | Generates computer’s random RPS choice. |
| `Winner`             | Determines the winner of the round. |
| `PrintGameOver`      | Displays final game summary. |
| `NumberOfRounds`     | Runs the game logic for specified rounds. |
| `StartGame`          | Starts the entire game and handles replay logic. |

---

## 🧪 Sample Output

```
Round [1] begins:

Your Choice: [1]:Rock, [2]:Paper, [3]:Scissors ? 1

Player1  Choice: Rock
Computer Choice: Scissors
Round Winner   : [Player1]

Do You Want to Play More ? [y]:yes, [n]:no ? n
```

---

## 🎨 Color Codes

- ✅ Green: Player win
- ❌ Red: Computer win
- ⚪ Yellow: Draw

> Note: `system("color XY")` is Windows-specific and may not work on all systems.

▶️ [Watch Demo Video](https://youtu.be/u5WOGHhUt8k)

---

## 📄 License

This project is for educational purposes and does not include a license. Feel free to modify or use it in your learning projects.
