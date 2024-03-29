#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WIDTH 12

char num[WIDTH+1],sol[WIDTH+1];
char dict[5000][WIDTH+1];
int nsolutions = 0;
int nwords;
int maxlen;
FILE *out;
/*int charloc stands for num digit and num digit char*/
void calc (int charloc, int low, int high) {
  printf("%d %d %d\n",charloc,low,high);
  if (charloc == maxlen) {
    //sol[charloc] = '\0';
    sol[charloc] = '\0';
    int x;
    /*there we find first maxlen char is same at the dict array*/
    for (x = low; x < high; x++) {
      if (strcmp (sol, dict[x]) == 0) {
	fprintf (out, "%s\n", sol);
	nsolutions++;
      }
    }
    return;
  }
  if (charloc > 0) {
    int j;
    for (j=low; j <= high; j++){
      /*when charloc=1 there to find all first char is sol[0] in dict array
       * we get lowest index make sol[0] is same the word in dict array
       * and highest index make sol[0] is same the word in dict array
       * this method is good!
       * */
      if (sol[charloc-1] == dict[j][charloc-1]) {
	low=j;
	while (sol[charloc-1] == dict[j][charloc-1])
	  j++;
	high=j;
	break;
      }
      /* find the highest index then return */
      if (j == high) return;
    }
  }
  if (low > high) return;
  switch(num[charloc]){
    case '2':sol[charloc] = 'A'; calc(charloc+1,low,high);
	     sol[charloc] = 'B'; calc(charloc+1,low,high);
	     sol[charloc] = 'C'; calc(charloc+1,low,high);
	     break; 
    case '3':sol[charloc] = 'D'; calc(charloc+1,low,high);
	     sol[charloc] = 'E'; calc(charloc+1,low,high);
	     sol[charloc] = 'F'; calc(charloc+1,low,high);
	     break; 
    case '4':sol[charloc] = 'G'; calc(charloc+1,low,high);
	     sol[charloc] = 'H'; calc(charloc+1,low,high);
	     sol[charloc] = 'I'; calc(charloc+1,low,high);
	     break; 
    case '5':sol[charloc] = 'J'; calc(charloc+1,low,high);
	     sol[charloc] = 'K'; calc(charloc+1,low,high);
	     sol[charloc] = 'L'; calc(charloc+1,low,high);
	     break; 
    case '6':sol[charloc] = 'M'; calc(charloc+1,low,high);
	     sol[charloc] = 'N'; calc(charloc+1,low,high);
	     sol[charloc] = 'O'; calc(charloc+1,low,high);
	     break; 
    case '7':sol[charloc] = 'P'; calc(charloc+1,low,high);
	     sol[charloc] = 'R'; calc(charloc+1,low,high);
	     sol[charloc] = 'S'; calc(charloc+1,low,high);
	     break; 
    case '8':sol[charloc] = 'T'; calc(charloc+1,low,high);
	     sol[charloc] = 'U'; calc(charloc+1,low,high);
	     sol[charloc] = 'V'; calc(charloc+1,low,high);
	     break; 
    case '9':sol[charloc] = 'W'; calc(charloc+1,low,high);
	     sol[charloc] = 'X'; calc(charloc+1,low,high);
	     sol[charloc] = 'Y'; calc(charloc+1,low,high);
	     break;
  }
}

int main(){
  FILE *in=fopen ("namenum.in.12", "r");
  FILE *in2=fopen ("dict_10.txt", "r");
  /*make out,dict array,nwords as globle variable*/
  out=fopen ("namenum.out","w");
  for (nwords = 0; fscanf (in2, "%s", dict[nwords++]) != EOF; )
    ;
  /*make num as globle variable and make num as digit string*/
  fscanf (in, "%s",num);
  maxlen = strlen(num);
  printf("max length is %d\n", maxlen);
  calc (0, 0, nwords);
  if (nsolutions == 0) fprintf(out,"NONE\n");
  return 0;
}
