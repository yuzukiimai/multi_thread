#include <stdio.h>
#include <unistd.h>
#include <pthread.h> // スレッド関連のヘッダーファイル(Unix)
void func(int x); // プロトタイプ宣言

int main(){
  pthread_t t1; // スレッド1の処理に必要なデータ
  pthread_t t2; // スレッド2の処理に必要なデータ
  pthread_create( &t1, NULL, (void*)func, (void*)1);  // スレッド1開始
  pthread_create( &t2, NULL, (void*)func, (void*)2);  // スレッド2開始
  printf("main()\n"); // メインが開始したことを示す出力
  pthread_join( t1, NULL);  // スレッド1が終了するまで待つ
  pthread_join( t2, NULL);  // スレッド2が終了するまで待つ
  return 0;
}

void func(int x){ // スレッドで処理する関数
  int i;
  for(i = 0;i < 10;i ++){ // スレッドが実行されていることを示す出力
  printf("func(%d): %d\n", x, i);
  usleep(100000); // 100000us(=0.1s)待機
  } // 通常だとこの間は何も行わないが,マルチス
} // レッドの場合,別のスレッドに処理が移る
