#include <stdio.h>
//#include "list_test.h"
//#include "stack_test.h"
#include "queue_test.h"

int main() {
    setbuf (stdout, NULL );
//  list_test.h:
//    Test_Sq_List();
//    Test_Link_List();
//    Test_SLink_List();
//    Test_ALink_List();

//  stack_test.h
//    Test_Sq_Stack();

//  queue_test.h
//    Test_Link_Queue();
    Test_Cir_Queue();
    return 0;
}