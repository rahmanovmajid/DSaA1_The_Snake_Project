#include<stdio.h>
#ifndef __CELLLIST_H__
#define __CELLLIST_H__

#define CL_MAX 1000

#include"ppm.h"

struct cellList{
    int size;
    struct cell snake[CL_MAX];
};

struct cellList CL_new();
struct cellList CL_add(struct cellList cl,struct cell c);
void CL_print(struct cellList cl, char *label);
struct cell CL_get(struct cellList cl,int ind);
struct cell CL_random(struct cellList cl);
struct cellList CL_neighbors(struct cell c,struct arena ar);
struct cellList CL_randomPath(struct cell start,struct arena ar);
void CL_draw(struct cellList,int nb_rows,int nb_cols,char *ppm_name);
void CL_animate(struct cellList,int nb_rows,int nb_cols,char *ppm_name);




#endif