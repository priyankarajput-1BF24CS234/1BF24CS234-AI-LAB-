import random

board = [" "] * 9

def print_board():
    print(f"\n {board[0]} | {board[1]} | {board[2]} ")
    print("-----------")
    print(f" {board[3]} | {board[4]} | {board[5]} ")
    print("-----------")
    print(f" {board[6]} | {board[7]} | {board[8]} \n")

def check_win(p):
    wins = [(0,1,2), (3,4,5), (6,7,8), (0,3,6), (1,4,7), (2,5,8), (0,4,8), (2,4,6)]
    return any(board[a] == board[b] == board[c] == p for a, b, c in wins)

print("Tic-Tac-Toe! You are X, AI is O. Positions: 0-8")

while " " in board:
    print_board()
   
    # Human turn
    try:
        move = int(input("Your move (0-8): "))
        if board[move] != " ":
            print("Spot taken! Try again.")
            continue
    except (ValueError, IndexError):
        print("Invalid input! Enter a number from 0 to 8.")
        continue

    board[move] = "X"
    if check_win("X"):
        print_board()
        print("You win!")
        break

    if " " not in board:
        print_board()
        print("It's a tie!")
        break

    # AI turn (random empty spot)
    ai_move = random.choice([i for i, spot in enumerate(board) if spot == " "])
    board[ai_move] = "O"
    print(f"AI chose position {ai_move}")
   
    if check_win("O"):
        print_board()
        print("AI wins!")
        break
