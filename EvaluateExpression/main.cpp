#include <iostream>

#define TRUE 1 ;
#define FALSE 2;
#define  OK 3;
#define  ERROR 4;
#define  INFEASIBLE 5;
#define  OVERFLOW 6;

typedef int Status;

typedef struct {
    int *base;
    int *top;
    int stacksize;
} SqStack;


#define  STACK_INIT_SIZE 100;//初始化存储空间大小
#define STACK_INCREASEMENT_SIZE 10;//存储空间分配增量



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}