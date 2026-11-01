#include <stdio.h>

int main()
{
 int marks;

 printf("Enter marks: ");
 scanf78("%d" , &marks);

 if (marks >=75)
  printf("Grade:A");

  else if (marks >= 65)
   printf("Grade: B");

   else if (marks >= 55)
   printf("Grade: c");

   else if (marks >= 45)
   printf("Grade: D");

    else 
     printf("Grade:F");

     return 0;

}