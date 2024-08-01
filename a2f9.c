/* a2f9.c
   Βιολάρη Λευκοθέα - ics21014
   Δίνεται το αρχείο κειμένου ‘i2f9.dat’ των μαθητών ενός σχολείου που περιλαμβάνει τα εξής στοιχεία για κάθε μαθητή:
    * ονοματεπώνυμο μαθητή, το οποίο δεν μπορεί να περιλαμβάνει περισσότερους από 30 χαρακτήρες
    * αριθμός απουσιών (int)
    * διάφορα στοιχεία μαθητή, τα οποία δεν μπορούν να ξεπερνάνε τους 68 χαρακτήρες
    Τα παραπάνω στοιχεία για κάθε μαθητή χωρίζονται με κόμμα.
    Ζητείται να γίνει πρόγραμμα που να δημιουργεί αρχείο μαθητών με απουσίες άνω των 100. Το πρόγραμμα
    θα ζητά τα ονόματα των αρχείων "εισόδου" (i2f9.dat) και "εξόδου" (o2f9.dat) από τον χρήστη. Από
    το αρχείο μαθητών ‘i2f9.dat’ θα δημιουργείται το αρχείο κειμένου ‘o2f9.dat’ που θα περιέχει το
    ονοματεπώνυμο (30 χαρακτήρες) και τον αριθμό απουσιών (int) κάθε μαθητή που οι απουσίες του
    ξεπερνούν τις 100. Τέλος, θα περιέχει το πλήθος όλων των μαθητών του σχολείου καθώς και το πλήθος των
    μαθητών του σχολείου που οι απουσίες τους ξεπερνούν τις 100. H εμφάνιση θα ακολουθεί στοίχιση με την
    παρακάτω μορφή:
    Το αρχείο i2f9.dat σας δίνεται και είναι το παρακάτω.
    Το αρχείο o2f9.dat που θα δημιουργηθεί
*/

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>

#define M 100

typedef struct {
  char name[30];
  int apousies;
}studentT;

void readInput (FILE *infile, studentT students[], int  *pApousies, int *pStudents);
void writeOutput (FILE *outfile,int size, studentT students[],int total);
 /*of students*/

int main ()
{
   /* Δήλωση μεταβλητών */

   FILE *infile, *outfile ;
   studentT students[M];
   int numberOfStudents,numberOfApousies;

  /* Είσοδος δεδομένων */

   infile=fopen ("i2f9.dat","r");
   if (infile==NULL)
   {
       printf ("Cannot open inout file i2f9.dat");
       exit(1);
   }
   outfile=fopen("o2f9.dat","w");
   readInput(infile,students,&numberOfApousies,&numberOfStudents);

  /* Υπολογισμός */

  /* Έξοδος */

   writeOutput (outfile,numberOfApousies,students,numberOfStudents);
   fclose (infile);
   fclose (outfile);

   return 0;
}

/*Υλοποίηση Συναρτήσεων */
void writeOutput (FILE *outfile,int size, studentT students[],int total) /*of students*/
{
 int i;
 for (i=0;i<39;i++)
    fputc ('-',outfile);
 fputc ('\n',outfile);

 fprintf (outfile, "%-30s%-9s\n", "ONOMATEPWNYMO", "APOUSIES");
 for (i=0;i<39;i++)
    fputc ('-',outfile);
 fputc ('\n',outfile);

 for (i=0;i<size;i++)
 {
    fprintf (outfile, "%-30s%9d\n",students[i].name,students[i].apousies);
 }
 for (i=0;i<39;i++)
    fputc ('-',outfile);
 fputc ('\n',outfile);
 fprintf (outfile,"%-30s%9d\n", "SYNOLO MATHITWN:",total);
 fprintf (outfile,"%-30s%9d\n", "SYNOLO APONTWN:",size);
}



//epistrefei apontes //epistrefei olous tous mathites
void readInput (FILE *infile, studentT students[], int  *pApousies, int *pStudents)
{
  char name[30],comments[68],termch ;
  /*termatikos xarakthras*/
  int nscan,apousies,line;
  line=0;
  *pApousies=0;
  *pStudents=0;
  while (TRUE)
   {
     nscan=fscanf(infile,"%30[^,],  %d, %68[^\n]%c", name, &apousies, comments, &termch);
     //name,comments ειναι πινακες, αρα ειναι κρυφοδεικτες
     if (nscan==EOF) break;
     line++;
     if (nscan!=4 || termch!='\n'){
        printf ("Error in line %d. Program termination\n",line);
        exit(1);
     }
     if (apousies>100)
     {
        students[*pApousies].apousies=apousies;
        strcpy(students[*pApousies].name,name);
        (*pApousies)++;
     }
     (*pStudents)++;
   }
}

