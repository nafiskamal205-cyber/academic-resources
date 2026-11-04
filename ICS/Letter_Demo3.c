// Program to check a character is a small or capital letter
#include <stdio.h>
int main()
{
      char ch;

      printf("Enter any letter: ");
      scanf("%c",&ch);

      if(ch>='a' && ch<='z')   // check for small letter
      {
         printf("This is a small letter\n");
      }

      else if(ch>='A' && ch<='Z')   // check for capital letter
      {
         printf("This is a capital letter\n");
      }

      else   // if it is not a letter
      {
         printf("No letter\n");
      }

      return 0;
}
