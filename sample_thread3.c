#include <stdio.h>
#include <pthread.h>

void func(int x);
int count = 0;

int main(){
  pthread_t t1;
  pthread_t t2;
  pthread_create( &t1, NULL, (void*)func, (void*)1);
  pthread_create( &t2, NULL, (void*)func, (void*)2);
  printf("main()\n");
  pthread_join( t1, NULL);
  pthread_join( t2, NULL);
  printf("count = %d\n",count);
  return 0;
}

void func(int x){
  int i;
  for(i = 0;i < 10000000;i ++){
    count ++;
  }
}
