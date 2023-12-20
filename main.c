#include"cellList.h"


int main(){

    struct cell a = C_new(3,5);
    // C_print(a,"My First Cell");
    // C_printNeighbors(a);
    struct cell b =  C_new(3,6);
    struct cell c = C_new(3,7);
    struct cell d = C_new(3,8);
    struct cell e = C_new(4,8);
    struct cell f = C_new(5,8);
    struct cell g = C_new(6,8);
    struct cell h = C_new(2,4);

    struct cellList cl = CL_new();
    cl = CL_add(cl,a);
    cl = CL_add(cl,b);
    cl = CL_add(cl,c);
    cl = CL_add(cl,d);
    cl = CL_add(cl,e);
    cl = CL_add(cl,f);
    cl = CL_add(cl,g);
    cl = CL_add(cl,h);


    // CL_print(cl,"My First List");

    // if ( CL_get(cl,7).row == 0 && CL_get(cl,7).col == 0 ) {
    //     printf("Error! This cellList contains less elements than index of IND\n");
    // }
    // else{
    //     C_print(CL_get(cl,7),"The cell you want");
    // }

    //CL_print(CL_neighbors(C_new(2,4)),"Haaaaaaa: ");   

    //C_print(CL_random(CL_neighbors(h)),"Zehrimar");


    //CL_print(CL_randomPath(a,10),"Aydede");

    
    // struct cellList cl1=CL_new();
    // cl1=CL_randomPath(a,10);
    // CL_print(cl1,"salam");
    // CL_animate(cl1,10,10,"snake");

    struct arena ar = A_new(10,10);

    //printf("%d\n",A_isInside(a,ar));

    //CL_print(CL_neighbors(C_new(8,9),ar),"Haaaaaaa: ");
    struct cellList path = CL_randomPath(C_new(3,5),ar);
    CL_animate(path,10,10,"snake");   

    return 0;
}