#include"cellList.h"


struct arena A_new(int nb_rows, int nb_cols){
    struct arena ar;
    ar.nb_rows = nb_rows;
    ar.nb_cols = nb_cols;
    return ar;
}

int A_isInside(struct cell c, struct arena ar){
    if ( c.row < ar.nb_rows && c.row >= 0 && c.col < ar.nb_cols && c.col >= 0 ){
        return 1;
    }
    else{
        return 0;
    }
}