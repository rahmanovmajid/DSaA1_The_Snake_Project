/*==========================================================*\
  Sunday March the 10th 2019
  cellList.c
\*==========================================================*/

#include "cellList.h"

//----------------------------------------------------
// Returns an empty stack of cells

struct cellList CL_new()
{

}

//----------------------------------------------------
// Adds cell (row,col) on top of the stack cell

struct cellList CL_add(struct cellList cl, struct cell c)
{
}

//----------------------------------------------------
// Returns the value of cell index i.

struct cell CL_get(struct cellList cl, int i)
{

}

//----------------------------------------------------
// Prints the contents of the cell list.

void CL_print(struct cellList cl, char *label)
{
}

//----------------------------------------------------
// Returns an element at random in cl (unless cl is empty)

struct cell CL_random(struct cellList cl)
{
}

//----------------------------------------------------
// Returns a list of cells corresponding to the neighbors
// of c (Each neighbor has c neighbors)

struct cellList CL_neighbors(struct cell c, struct arena ar)
{
}

//----------------------------------------------------
// Returns a cell list obtained by choosing random neighbors
// of start, then, random neighbors of this neighbor and so on,
// until there are nb_cells cells in the cell list.

struct cellList CL_randomPath(struct cell start, struct arena ar)
{

}

//----------------------------------------------------
// Draws a series of ppm image files. In the first file
// can be seen the first cell of cl, in the second file,
// the first and the second. In the last file, all of
// the elements can be seen.

void CL_draw(struct cellList cl, int nb_rows, int nb_cols, char *ppm_name)
{
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


//----------------------------------------------------
// Draws a series of ppm image files. In the first file
// can be seen the first cell of cl, in the second file,
// the first and the second. In the last file, all of
// the elements can be seen.

void CL_animate(struct cellList cl, int nb_rows, int nb_cols, char *ppm_name)
{
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



//----------------------------------------------------
// Tests the behaviour of a cell stack.

void CL_test(int nb_rows, int nb_cols)
{
}
