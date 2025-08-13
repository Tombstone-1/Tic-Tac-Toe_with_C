/* Project - Tic Tac Toe Game. non-officially assign on 23 september 2024. completed on 18 October 2024.
*   Conditional Requirements as follow :-
*   1. Game should state play rules first and show a basic board.
*   2. input can't be taken in pattern so give user ability to chose positions.
*   3. make methods for initialize, turns, score and reset.
*   4. repeat that game after every draw , win or lose.
*
*   changes have been made advice to use global.(issue for passing in function.)
*   make a counter ps_ctr for multidimensional loop. and compare with pos entered.
*   counter ps_ctr is in conflict with while x coz of same repeating position.(removed from while. solved)
*   don't use negate, gives negative value , not required.
*
*/

#include<stdio.h>
#include<string.h>

char xo_board[3][3];

void initialize_game_board();
void print_game_board();
void player_move();
int chk_whitespace();
int chk_winner();
void game_result(int);

int main(){
    char input[10];
    char start[] = "start";
    char try;

    do{
        printf("\n\n/*********** Rules of game **********/\n\n");
        printf("1.  Player 1 is assign ' X ' \n\n2.  Player 2 is assign ' O ' \n");
        printf("\n3.  Game board with position is given below :- ");
        printf("\n\n\t 1 | 2 | 3\n\t-----------\n\t 4 | 5 | 6\n\t-----------\n\t 7 | 8 | 9\n\n");
        printf(" ** select a position to fill your mark on that place. once entered, cannot be changed ! ** \n");

        printf("\n Type ' start ' or ' quit ' to begin or terminate the game : ");
        scanf("%s",&input);
        
        if(!strcmp(start, input)){
            
            /* init xo_board with empty spaces */
            initialize_game_board();

            /* take player position value */
            player_move();
        }
        else{
            printf("\n **** Game Terminated **** \n");
            return 0;
        }

        printf("\n +_+ Try again ? (y/n) : ");
        scanf(" %c", &try);

    }while(try == 'Y' || try == 'y');

    printf("\n **** Game Terminated **** \n");
}

void initialize_game_board(){
    printf("\ninitiliazing Tic Tac Toe Game Board..... \n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            xo_board[i][j] = ' ';
        }
    }

    /* tac box pattern printer code */
    print_game_board();    
    printf("Board reset complete #_#\n");
}

void print_game_board(){
/* tac box pattern printer code */
    printf("\n");
    for(int i=0; i<3; i++){
        printf("\t");
        for(int j=0; j<3; j++){
            printf(" %c ", xo_board[i][j]);
            if(j<2){
                printf("|");
            }
        }
        printf("\n\t");
        for(int k=0; k<=10; k++){
            if(i<2){
                printf("-");
            }
        }   
        printf("\n");
    }
/* ends here */
}

void player_move(){
    int pos;
    int player = 0;

    while(chk_whitespace() && chk_winner()){
        int ps_ctr=1;

        printf("Player %d Turn :  ", player+1);
        scanf("%d", &pos);
        
        player ^= 1;   // bitwise xor is needed, negate won't do good.

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(player){
                    if(pos == ps_ctr && xo_board[i][j] == ' '){
                        //printf("print ps_cntr value : %d\n", ps_ctr);
                        xo_board[i][j] = 'x';
                    }
                }
                else{
                   if(pos == ps_ctr && xo_board[i][j] == ' '){
                        //printf("print ps_cntr value : %d\n", ps_ctr);
                        xo_board[i][j] = 'o';
                    }
                }
                ps_ctr++;
            }
        }
        print_game_board();
    }

    /* send player and winner data .*/
    game_result(player);
}

int chk_whitespace(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(xo_board[i][j] == ' '){
                return 1;
            }
        }
    }
    return 0;
}

int chk_winner(){
    
    /* check rows */
    if(xo_board[0][0] != ' '){ if(xo_board[0][0] == xo_board[0][1] && xo_board[0][0] == xo_board[0][2]) return 0; }
    if(xo_board[1][0] != ' '){ if(xo_board[1][0] == xo_board[1][1] && xo_board[1][0] == xo_board[1][2]) return 0; }
    if(xo_board[2][0] != ' '){ if(xo_board[2][0] == xo_board[2][1] && xo_board[2][0] == xo_board[2][2]) return 0; }

    /* check columns */
    if(xo_board[0][0] != ' '){ if(xo_board[0][0] == xo_board[1][0] && xo_board[0][0] == xo_board[2][0]) return 0; }
    if(xo_board[0][1] != ' '){ if(xo_board[0][1] == xo_board[1][1] && xo_board[0][1] == xo_board[2][1]) return 0; }
    if(xo_board[0][2] != ' '){ if(xo_board[0][2] == xo_board[1][2] && xo_board[0][2] == xo_board[2][2]) return 0; }

    /* check diagonals */
    if(xo_board[0][0] != ' '){ if(xo_board[0][0] == xo_board[1][1] && xo_board[0][0] == xo_board[2][2]) return 0; }
    if(xo_board[2][0] != ' '){ if(xo_board[2][0] == xo_board[1][1] && xo_board[2][0] == xo_board[0][2]) return 0; }

    return 1;

}

void game_result(int player){
    player ^= 1;
    int draw = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(xo_board[i][j] == ' ' || chk_winner() == 0){
                draw++;
                break;
            }
        }
    }
    if(draw != 0){
        //printf("%d", player);
        printf("Winner : Player %d  ^_^ !\n", player+1);
    }
    else{
        printf("Game Over . It's a Draw   *_* \n");
    }  
}



