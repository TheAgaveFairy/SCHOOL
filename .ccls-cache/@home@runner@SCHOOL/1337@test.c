#include <stdio.h>
#include <string.h>

int main(void) {

   /* Type your code here. */
   const int MAX = 50;

   //char in[MAX];
   int i,j, len;
   while(1){
      char in[MAX];
      fgets(in,MAX,stdin);
      //printf("%s",in);

      if((strcmp(in,"d")==0) || (strcmp(in,"done")==0) || (strcmp(in,"Done")==0)){
         break;
      }

      len = strlen(in);
      char out[len];

      for(i = 0, j = len-1; i<len; i++, j--){
         out[j] = in[i];
      }

      printf("%s", out);
      //printf("\n");
   }
   printf("exiting :)");


   return 0;
}
