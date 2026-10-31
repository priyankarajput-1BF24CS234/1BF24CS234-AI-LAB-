import random

N = 8

def heuristic(board):
    conflicts = 0

    for i in range(N):
        for j in range(i + 1, N):
            if board[i] == board[j] or abs(board[i] - board[j]) == abs(i - j):
                conflicts += 1

    return conflicts


def print_board(board):
    for row in range(N):
        for col in range(N):
            if board[col] == row:
                print("Q", end=" ")
            else:
                print(".", end=" ")
        print()


def hill_climbing():
    restarts = 0

    while True:
        board = [random.randint(0, N - 1) for _ in range(N)]
        current_h = heuristic(board)

        while current_h != 0:
            best_board = board[:]
            best_h = current_h

            for col in range(N):
                original_row = board[col]

                for row in range(N):
                    if row == original_row:
                        continue

                    board[col] = row
                    h = heuristic(board)

                    if h < best_h:
                        best_h = h
                        best_board = board[:]

                board[col] = original_row

            if best_h >= current_h:
                break

            board = best_board
            current_h = best_h

        if current_h == 0:
            print("Solution found!")
            print("Number of random restarts:", restarts)
            print_board(board)
            return

        restarts += 1


hill_climbing()
