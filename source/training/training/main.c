//
//  main.c
//  training
//
//  Created by hafu on 2020/4/13.
//  Copyright © 2020 hafu. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    float pi = 3.14;
    float * ppi;
    ppi = &pi;
    printf("value %.2f, location %p\n", *ppi, ppi);
    return 0;
}

