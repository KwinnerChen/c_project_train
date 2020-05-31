//
//  main.c
//  queue
//
//  Created by hafu on 2020/5/20.
//  Copyright © 2020 hafu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
   char name[100];
   char *description;
 
   strcpy(name, "Zara Ali");
 
   /* 动态分配内存 */
   description = (char *)malloc( 30 * sizeof(char) );
   if( description == NULL )
   {
      fprintf(stderr, "Error - unable to allocate required memory\n");
   }
   else
   {
      strcpy( description, "Zara ali a DPS student.");
   }
   /* 假设您想要存储更大的描述信息 */
   strncat( description, "She is in class 10th", 30-strlen(description)-1);
   
   
   printf("Name = %s\n", name );
   printf("Description: %s\n", description );
    printf("description's lenght: %lu\n", strlen(description));
   /* 使用 free() 函数释放内存 */
   free(description);
}
