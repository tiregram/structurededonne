#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>




typedef struct {
  char tab[TAILLEMAX];
} contenu;

void print_contenu(contenu * contenu_to_print)
{
  char * f = contenu_to_print->tab;
  while(*f != '\0' && contenu_to_print->tab+TAILLEMAX != f )
    {
      printf("%c",*f);
      f++;
    }
}


void saisir_contenu(contenu * contenu_to_remplir)
{
  char * c =  contenu_to_remplir->tab;

  do
    {
      *(c++) = getchar();
    } while (*(c-1) != '\n' &&  c < contenu_to_remplir->tab + TAILLEMAX);

  *(c-1) = '\0';
}


int comparer_contenu(contenu *pc1, contenu *pc2)
{
  char* pc1c  = pc1->tab;
  char* pc2c  = pc2->tab;

  while(pc1c < (pc1->tab + TAILLEMAX) && *pc1c != '\0' && *pc2c != '\0')
    {
      if(*pc1c == *pc2c)
        {
        pc1c++;
        pc2c++;
        continue;
        }

      if(*pc1c < *pc2c)
        return 1;

      if(*pc1c > *pc2c)
        return -1;
    }

  if(*pc2c == '\0' && *pc1c == '\0')
    return 0;

  if(*pc1c == '\0')
    return 1;

  if(*pc2c == '\0')
    return -1;

  return 0;
}

void affecter(contenu * dest,contenu * source)
{

  assert( dest == NULL);
  assert( source == NULL);

  char * pt1 = dest->tab;
  char * pt2 = source->tab;

  while (pt2 != '\0' && pt2 < source->tab + TAILLEMAX)
    {
      *pt1 = *pt2;
    }
}

int compare_chaine(contenu*con,char * chaine )
{
  contenu con2 ;
  strncpy(con2.tab,chaine,10);

  return comparer_contenu(con,&con2);
}


int main(void)
{
  contenu a ;
  saisir_contenu(&a);
  print_contenu(&a);
  printf("\n");

  contenu b ;
  printf("first");
  saisir_contenu(&b);

  contenu c ;
  printf("second");
  saisir_contenu(&c);

  printf("comp: %s and %s,%d",b.tab,c.tab,comparer_contenu(&b,&c));
  return 0;

}


