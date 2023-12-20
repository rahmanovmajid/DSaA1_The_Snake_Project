#include"cell.h"


struct cell C_new(int row,int col){
    struct cell c;
    c.col = col;
    c.row = row;
    return c;
}
void C_print(struct cell c,char *label){
    printf("%s",label);
    printf(" : ");
    printf("(%d,%d)\n",c.row,c.col);
}

void C_printNeighbors(struct cell c){
    if ( c.row == 1 && c.col == 1 ){
        printf("Lower : (%d,%d)\n",c.row+1,c.col);
        printf("Right : (%d,%d)\n",c.row,c.col+1);
    }
    else if ( c.row == 1 ){
        printf("Lower : (%d,%d)\n",c.row+1,c.col);
        printf("Left : (%d,%d)\n",c.row,c.col-1);
        printf("Right : (%d,%d)\n",c.row,c.col+1);
    }
    else if ( c.col == 1 ){
        printf("Upper : (%d,%d)\n",(c.row-1),c.col);
        printf("Lower : (%d,%d)\n",(c.row+1),c.col);
    }else{
        printf("Upper : (%d,%d)\n",c.row-1,c.col);
        printf("Lower : (%d,%d)\n",c.row+1,c.col);
        printf("Left : (%d,%d)\n",c.row,c.col-1);
        printf("Right : (%d,%d)\n",c.row,c.col+1);
    }

}


