# Tic-Tac-Toe in C

A two-player, console-based Tic-Tac-Toe game written in C for my first-year **Programming I** final project.

Unlike the traditional 3×3 version, this game supports customizable board sizes from **5×5 to 100×100**.

## Features

- Two-player gameplay (X and O)
- Customizable square board sizes (5 to 100)
- Turn-based moves entered as row and column coordinates
- Validation for out-of-range and already occupied cells
- Win detection across rows, columns, and both diagonal directions
- A maximum of 10 moves per player; a draw is declared if neither player wins

## How to Compile and Run

You need a C compiler such as GCC.

**Compile:**

```bash
gcc "Tic Tac Toe in C.c" -o tic-tac-toe
```

**Run on Windows (PowerShell):**

```powershell
.\tic-tac-toe.exe
```

**Run on Linux/macOS:**

```bash
./tic-tac-toe
```

## How to Play

1. Enter a board size between 5 and 100.
2. Player X enters a move using `row column`, for example `2 3`.
3. Player O takes the next turn.
4. Players continue taking turns until someone wins or both have used their 10 moves.

### Win Rule in This Implementation

A player wins when **three of their marks lie on the same row, column, or diagonal without an opponent's mark between them**. Empty cells *are allowed* between those marks, so this differs from the usual consecutive-three rule.

## Project Background

Developed as a final project for my first-year Programming I course. The project practices **C functions, two-dimensional arrays, loops, conditionals, and input validation**.

## Possible Improvements

- Reject non-numeric input safely
- Improve board alignment for two- and three-digit row/column labels
- Add an optional traditional consecutive-three winning rule
- Let players start a new game without restarting the program
