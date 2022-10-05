import numpy as np

ROW_COUNT=6
COLUMN_COUNT=7

def create_board():
    board=np.zeros((ROW_COUNT,COLUMN_COUNT))
    return board

def drop_piece(board, row, col, piece):
    board[row][col] = piece

def valid_location(board, col):
    return board[ROW_COUNT-1][col]==0

def get_next_open_row(board,col):
    for r in range(ROW_COUNT):
        if board[r][col]==0:
            return r

def print_board(board):
    print(np.flip(board,0))
    
def wining_move(board, piece):
    #Horizontal
    for c in range(COLUMN_COUNT-3):
        for r in range(ROW_COUNT):
            if board[r][c]== piece and board[r][c+1] == piece and board[r][c+2] == piece and board[r][c+3] == piece:
                return True
            
    #vertical
    for c in range(COLUMN_COUNT):
        for r in range(ROW_COUNT-3):
            if board[r][c]== piece and board[r+1][c] == piece and board[r+2][c] == piece and board[r+3][c] == piece:
                return True
            
    #Diagonal positiva
    for c in range(COLUMN_COUNT-3):
        for r in range(ROW_COUNT-3):
            if board[r][c]== piece and board[r+1][c+1] == piece and board[r+2][c+2] == piece and board[r+3][c+3] == piece:
                return True
            
    
    #Diagonal negativa
    for c in range(COLUMN_COUNT-3):
        for r in range(3,ROW_COUNT):
            if board[r][c]== piece and board[r-1][c+1] == piece and board[r-2][c+2] == piece and board[r-3][c+3] == piece:
                return True
    
    
            
        
    
    
board=create_board()
print(board)
game_over=False
turn=0


while not game_over:
    #P1
    if turn ==0:
        col=int(input("Jugador 1: Selecciones un valor (0-6):"))
        
        if valid_location(board, col):
            row=get_next_open_row(board, col)
            drop_piece(board, row, col, 1)
            
            if wining_move(board, 1):
                print("Jugador 1 Gana!!!")
                game_over=True
    
    
    #P2
    else:
        col=int(input("Jugador 2: Selecciones un valor (0-6):"))
        
        if valid_location(board, col):
            row=get_next_open_row(board, col)
            drop_piece(board, row, col, 2)
            
            if wining_move(board, 2):
                print("Jugador 2 Gana!!!")
                game_over=True
                
            
    print_board(board)
        
        
    turn+=1
    turn=turn%2
    