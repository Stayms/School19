/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouchez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:07:20 by nbouchez          #+#    #+#             */
/*   Updated: 2018/11/13 22:07:22 by nbouchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	usage()
{
	write(1,"usage: ./fillit source_file\n",28);
}

/*	
**	input : adresse du tableau de piece, taille du tableau
**	output : -1 = impossible de placer une piece | 0 = Besoin de plus de place | 1 = Succes une piece | 2 = Succes end
*/

void affichage(char *workspace, int tab_size)
{
	int col;
	int lig;

	lig = 0;
	printf("\n\t [ Workspace ]\n");
	printf("\tSize : %d\n", tab_size);
	printf("+");
	while(lig < tab_size + 1)
	{
		printf("-");
		lig++;
	}
	printf("+\n");
	lig = 0;
	while(lig < tab_size)
	{
		col = 0;
		printf("|");
		while(col < tab_size + 1)
		{
			if((*workspace <= 'Z' && *workspace >= 'A') || *workspace == -1)
				printf("%c", *workspace);
			else if(*workspace == '\0')
				printf("*");
			workspace++;
			col++;
		}
		printf("|\n");
		lig++;
	}
	printf("+");
	lig = 0;
	while(lig < tab_size + 1)
	{
		printf("-");
		lig++;
	}
	printf("+\n");
}

/*	
**	input : adresse du tableau, taille carre, Adresse du tableau des elements, adresse de la 1er piece
**	output : -1 = impossible de placer la piece | 0 = Besoin de plus de place | 1 = Succes une piece | 2 = Succes end
**
**
*/

int enfiler(char *workspace, int tab_size, int *index, t_coord **piece)
{
	int result;
	int index_origin;
	int offset;

	result = -1;
	index_origin = 0;
	printf(".. Nouvelles piece\n");
	while(index_origin < tab_size * (tab_size - 1) - 1 && result != 2)
	{
		offset = index_origin;
		if(workspace[offset] == '\0')
		{
			if((offset = index_origin + piece[0]->x + (piece[0]->y) * (-tab_size)) && workspace[offset] == '\0' && offset < tab_size * (tab_size - 1) - 1) //Ajoute de x + ajout de y (lignes) * tab_size + 1
			{
				if((offset = index_origin + piece[1]->x + (piece[1]->y) * (-tab_size)) && workspace[offset] == '\0' && offset < tab_size * (tab_size - 1) - 1)
				{
					if((offset = index_origin + piece[2]->x + (piece[2]->y) * (-tab_size)) && workspace[offset] == '\0' && offset < tab_size * (tab_size - 1) - 1)
					{
						printf("J'ai trouve une place libre\n");
						workspace[index_origin] = piece[0]->lettre;
						workspace[index_origin + piece[0]->x + (piece[0]->y) * (-tab_size)] = piece[0]->lettre;
						workspace[index_origin + piece[1]->x + (piece[1]->y) * (-tab_size)] = piece[0]->lettre;
						workspace[index_origin + piece[2]->x + (piece[2]->y) * (-tab_size)] = piece[0]->lettre;
						piece[0]->etat = 1;
						affichage(workspace, tab_size - 1);
						if(piece[3])
						{
							printf("Debut de la piece suivante\n");
							result = enfiler(workspace, tab_size, index, piece + 3);
							if (result == -1)
							{
								workspace[index_origin] = '\0';
								workspace[index_origin + piece[0]->x + (piece[0]->y) * (-tab_size)] = '\0';
								workspace[index_origin + piece[1]->x + (piece[1]->y) * (-tab_size)] = '\0';
								workspace[index_origin + piece[2]->x + (piece[2]->y) * (-tab_size)] = '\0';
								piece[0]->etat = 0;
								printf("Roll Back\n");
								affichage(workspace, tab_size - 1);
							}
							printf("1\n");
						}
						else
						{
							printf("Pas de piece suivante");
							result = 2;
						}
					}
				}
			}
		}
		printf("IndexOrigin : %d\n", index_origin);
		index_origin++;
	}
	if(index_origin == tab_size * (tab_size - 1) - 1)
	{
		printf("\nResult : 0\n");
		return -1;
	}
//	if(result == -1)
//	{
//		result = enfiler(workspace, tab_size, index, piece + 3);
//	}
	//affichage(workspace, tab_size - 1);
	printf("\nResult : %d\n", result);
	return (result);
}

int fillit(t_coord **tab, int nb_piece)
{
	char *workspace;
	int end;
	int tab_size;
	int index;
	int i;

	i = 0;
	tab_size = 3;
	end = -1;
	workspace = NULL;
	index = 0;
	if(tab == NULL)
		return (0);
	while(end == -1)
	{
		printf("Agrandissement du tableau\n");
		i = 0;
		tab_size++;
		free(workspace);
		if((workspace = (char *)ft_strnew(tab_size * tab_size + tab_size)) == NULL)
			return (0);
		while(i < tab_size)
		{
			workspace[tab_size + i * (tab_size+1)] = (char)-1; //Creation de case morte
			i++;
		}
		end = enfiler(workspace , tab_size + 1, &index, tab);
		//tab_size++;
	}
	affichage(workspace, tab_size);
	return (0);
}


void generateur_piece(t_coord **tab, int nb_piece)
{
	int i;

	i = 0;
	printf("%p = %p\n", *tab, tab[i]);
	//while(i < nb_piece * 3)
	//{
		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 1;
		tab[i]->y = 0;
		tab[i]->etat = 0;
		tab[i]->lettre = 'A';
		i++;
		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 1;
		tab[i]->y = -1;
		tab[i]->etat = 0;
		tab[i]->lettre = 'A';
		i++;
		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 0;
		tab[i]->y = -1;
		tab[i]->etat = 0;
		tab[i]->lettre = 'A';
		printf("Piece %d : %d,%d | %d,%d | %d,%d\n", i/3 + 1, tab[i-2]->x, tab[i-2]->y, tab[i-1]->x, tab[i-1]->y, tab[i]->x, tab[i]->y);
		i++;

		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 0;
		tab[i]->y = -1;
		tab[i]->etat = 0;
		tab[i]->lettre = 'B';
		i++;
		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 0;
		tab[i]->y = -2;
		tab[i]->etat = 0;
		tab[i]->lettre = 'B';
		i++;
		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = -1;
		tab[i]->y = -2;
		tab[i]->etat = 0;
		tab[i]->lettre = 'B';
		printf("Piece %d : %d,%d | %d,%d | %d,%d\n", i/3 + 1, tab[i-2]->x, tab[i-2]->y, tab[i-1]->x, tab[i-1]->y, tab[i]->x, tab[i]->y);
		i++;

		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 0;
		tab[i]->y = -1;
		tab[i]->etat = 0;
		tab[i]->lettre = 'C';
		i++;
		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 0;
		tab[i]->y = -2;
		tab[i]->etat = 0;
		tab[i]->lettre = 'C';
		i++;
		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 1;
		tab[i]->y = -2;
		tab[i]->etat = 0;
		tab[i]->lettre = 'C';
		printf("Piece %d : %d,%d | %d,%d | %d,%d\n", i/3 + 1, tab[i-2]->x, tab[i-2]->y, tab[i-1]->x, tab[i-1]->y, tab[i]->x, tab[i]->y);
		i++;

		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 1;
		tab[i]->y = 0;
		tab[i]->etat = 0;
		tab[i]->lettre = 'D';
		i++;
		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 2;
		tab[i]->y = 0;
		tab[i]->etat = 0;
		tab[i]->lettre = 'D';
		i++;
		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 1;
		tab[i]->y = -1;
		tab[i]->etat = 0;
		tab[i]->lettre = 'D';
		printf("Piece %d : %d,%d | %d,%d | %d,%d\n", i/3 + 1, tab[i-2]->x, tab[i-2]->y, tab[i-1]->x, tab[i-1]->y, tab[i]->x, tab[i]->y);
		i++;

		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = -1;
		tab[i]->y = -1;
		tab[i]->etat = 0;
		tab[i]->lettre = 'E';
		i++;
		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 0;
		tab[i]->y = -1;
		tab[i]->etat = 0;
		tab[i]->lettre = 'E';
		i++;
		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 1;
		tab[i]->y = -1;
		tab[i]->etat = 0;
		tab[i]->lettre = 'E';
		printf("Piece %d : %d,%d | %d,%d | %d,%d\n", i/3 + 1, tab[i-2]->x, tab[i-2]->y, tab[i-1]->x, tab[i-1]->y, tab[i]->x, tab[i]->y);
		i++;

		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 0;
		tab[i]->y = -1;
		tab[i]->etat = 0;
		tab[i]->lettre = 'F';
		i++;
		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 0;
		tab[i]->y = -2;
		tab[i]->etat = 0;
		tab[i]->lettre = 'F';
		i++;
		tab[i] = (t_coord*)malloc(sizeof(t_coord));
		tab[i]->x = 0;
		tab[i]->y = -3;
		tab[i]->etat = 0;
		tab[i]->lettre = 'F';
		printf("Piece %d : %d,%d | %d,%d | %d,%d\n", i/3 + 1, tab[i-2]->x, tab[i-2]->y, tab[i-1]->x, tab[i-1]->y, tab[i]->x, tab[i]->y);
		i++;
	//}
	tab[i] = NULL;
	printf("Piece %d : %p\n", i/3+1, tab[i]);
}


int main(int argc, char const *argv[])
{
	t_coord coord;
	t_coord *tab_coord[78];//Pour exemple
	int nb_piece = 5;
	printf("%p\n", &tab_coord[0]);
	generateur_piece(tab_coord, nb_piece);

	if(argc != 2)
	{
		usage();
		return (0);
	}
	//fillit(read_in(argv[1]));
	printf("Argument fillit : %p\nAdresse [0] : %p\nValue :%d,%d | %d,%d | %d,%d\n", tab_coord, tab_coord[0], tab_coord[0]->x, tab_coord[0]->y, tab_coord[1]->x, tab_coord[1]->y, tab_coord[2]->x, tab_coord[2]->y);
	fillit(tab_coord, nb_piece);

	return (0);
}

