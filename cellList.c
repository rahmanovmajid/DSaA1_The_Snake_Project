#include"cellList.h"


struct cellList CL_new(){
    struct cellList cl;
    cl.size = 0;
    return cl;
}

struct cellList CL_add(struct cellList cl,struct cell c){
    cl.snake[cl.size] = c;
    cl.size++;
    return cl;
}

void CL_print(struct cellList cl, char *label){
    printf("%s : \n",label);
    for ( int i = 0 ; i < cl.size ; i++ ){
        printf("%d : ",i);
        printf("(%d,%d)",cl.snake[i].row,cl.snake[i].col);
        printf("\n");
    }
}

struct cell CL_get(struct cellList cl,int ind){
    if ( cl.size <= ind ){
        return C_new(0,0);
    }else{
        return cl.snake[ind];
    }
    
}

struct cell CL_random(struct cellList cl){
   // srand(time(NULL));
    int random = rand() % cl.size;
    if ( cl.size == 0 ){
        printf("Error! The cellList cl is EMPTY.\n");
        return C_new(0,0);
    }
    else{
        return cl.snake[random];
    }
}


struct cellList CL_neighbors(struct cell c,struct arena ar){
    struct cellList cl = CL_new();
    if ( c.row-1 < ar.nb_rows && c.row-1 >= 0 ) cl = CL_add(cl,C_new(c.row-1,c.col));
    if ( c.row+1 < ar.nb_rows && c.row+1 >= 0 ) cl = CL_add(cl,C_new(c.row+1,c.col));
    if ( c.col-1 >= 0 && c.col-1 < ar.nb_cols ) cl = CL_add(cl,C_new(c.row,c.col-1));
    if ( c.col+1 >= 0 && c.col+1 < ar.nb_cols ) cl = CL_add(cl,C_new(c.row,c.col+1));
    return cl;
}


struct cellList CL_randomPath(struct cell start,struct arena ar){
    struct cellList cl = CL_new();
    struct cellList neighbList = CL_new();
    struct cellList cleanNeighbList = CL_new();
    do{
       cl = CL_add(cl,start);
       neighbList =  CL_neighbors(start,ar);
       cleanNeighbList = CL_new();
       for ( int i = 0 ; i < neighbList.size ; i++ ){
           printf("hello i am in FOR 1\n");
           for( int j = 0 ; j < cl.size ; j++) {
               printf("%d",cl.size);
               printf("hello i am in FOR 2\n");
               if (neighbList.snake[i].row != cl.snake[j].row || neighbList.snake[i].col != cl.snake[j].col){
                   cleanNeighbList = CL_add(cleanNeighbList,neighbList.snake[i]);
               }
           }


           
        }
      
        start = CL_random(cleanNeighbList);
    
    } while ( cleanNeighbList.size != 0);
    return cl;
}


void CL_draw(struct cellList cl, int nb_rows, int nb_cols, char *ppm_name) {
	int pixels_per_cell = 20;
	char ppm_file_name[50];
	float proportion_serpent = 0.7;
	struct ppm img = PPM_new(nb_rows, nb_cols, pixels_per_cell, proportion_serpent);
	img = PPM_drawBG(img);

	struct cell c = CL_get(cl,0);
	img = PPM_drawCell(img, c.row, c.col);

	for(int i=1; i<cl.size;i++)
	{
		struct cell c = CL_get(cl,i);
		struct cell c2 = CL_get(cl,i-1);
		img = PPM_drawLink(img, c.row, c.col, c2.row, c2.col);
		img = PPM_drawCell(img, c.row, c.col);
	}
	sprintf(ppm_file_name,"%s.ppm",ppm_name);
	PPM_save(img,ppm_file_name);
}



void CL_animate(struct cellList cl, int nb_rows, int nb_cols, char *ppm_name) {
	int pixels_per_cell = 20;
	char ppm_file_name[50];
	float proportion_serpent = 0.7;
	struct ppm img = PPM_new(nb_rows, nb_cols, pixels_per_cell, proportion_serpent);
	img = PPM_drawBG(img);

	struct cell c = CL_get(cl,0);
	img = PPM_drawCell(img, c.row, c.col);
	sprintf(ppm_file_name,"%s_%02d.ppm",ppm_name,0);
	PPM_save(img,ppm_file_name);

	for(int i=1; i<cl.size;i++)
	{
		struct cell c = CL_get(cl,i);
		struct cell c2 = CL_get(cl,i-1);
		img = PPM_drawLink(img, c.row, c.col, c2.row, c2.col);
		img = PPM_drawCell(img, c.row, c.col);

		sprintf(ppm_file_name,"%s_%02d.ppm",ppm_name,i);
		PPM_save(img,ppm_file_name);
	}
}