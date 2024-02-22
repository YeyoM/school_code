result = []

""" 
A utility function to check if a queen can 
be placed on board[row][col]. Note that this 
function is called when "col" queens are 
already placed in columns from 0 to col -1. 
So we need to check only left side for 
attacking queens
"""


def isSafe(board, row, col):
    # Check this row on left side
    for i in range(col):
        if board[row][i]:
            return False

    # Check upper diagonal on left side
    i = row
    j = col
    while i >= 0 and j >= 0:
        if board[i][j]:
            return False
        i -= 1
        j -= 1

    # Check lower diagonal on left side
    i = row
    j = col
    while j >= 0 and i < 8:
        if board[i][j]:
            return False
        i = i + 1
        j = j - 1

    return True


""" 
A recursive utility function to solve N 
Queen problem 
"""


def solveNQUtil(board, col):
    """base case: If all queens are placed
    then return true"""
    if col == 8:
        v = []
        for i in board:
            for j in range(len(i)):
                if i[j] == 1:
                    v.append(j + 1)
        result.append(v)
        return True

    """ Consider this column and try placing 
    this queen in all rows one by one """
    res = False
    for i in range(8):
        """Check if queen can be placed on
        board[i][col]"""
        if isSafe(board, i, col):
            # Place this queen in board[i][col]
            board[i][col] = 1

            # Make result true if any placement
            # is possible
            res = solveNQUtil(board, col + 1) or res

            """ If placing queen in board[i][col] 
            doesn't lead to a solution, then 
            remove queen from board[i][col] """
            board[i][col] = 0  # BACKTRACK

    """ If queen can not be place in any row in 
        this column col then return false """
    return res


""" 
This function solves the N Queen problem using 
Backtracking. It mainly uses solveNQUtil() to 
solve the problem. It returns false if queens 
cannot be placed, otherwise return true and 
prints placement of queens in the form of 1s. 
Please note that there may be more than one 
solutions, this function prints one of the 
feasible solutions.
"""


def solveNQ(n):
    result.clear()
    board = [[0 for _ in range(n)] for _ in range(n)]
    solveNQUtil(board, 0)
    result.sort()
    return result


# Driver Code
n = 8
res = solveNQ(n)
print(res)
print(len(res))
