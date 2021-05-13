#include <stdio.h>
#include <stdlib.h>
#include <time.h>  //randomの生成

//ランダムに2か4を追加する
void make_random(char board[5][6]){
  //数字がないマスの数の計算
  int a=0;
  for (int i = 0; i<5; i++){
    for (int j = 0; j<5; j++){
      if (board[i][j]=='a'){
        a++;
      }
    }
  }
  srand((unsigned)time(NULL));
  //1からaまでのランダムな数字をbに代入
  int b;
  b = rand() % a +1;
  //1または2をランダムにcに代入
  int c;
  c = rand() % 2 +1;
  //b番目をaから2または4の値に変更
  int d = 0;
  for (int i = 0; i<5; i++){
    for (int j = 0; j<5; j++){
      if (board[i][j]=='a'){
        d++;
        if (d == b){
          if (c==1){
            board[i][j]='b';
          }else{
            board[i][j] ='c';
          }  
        }
      }
    }
  }
}
//ランダムに2か4か@を追加する
void make_random2(char board[5][6]){
  //数字がないマスの数の計算
  int a=0;
  for (int i = 0; i<5; i++){
    for (int j = 0; j<5; j++){
      if (board[i][j]=='a'){
        a++;
      }
    }
  }
  srand((unsigned)time(NULL));
  //1からaまでのランダムな数字をbに代入
  int b;
  b = rand() % a +1;
  //1または2をランダムにcに代入
  int c;
  c = rand() % 3 +1;
  //b番目をaから2または4または@の値に変更
  int d = 0;
  for (int i = 0; i<5; i++){
    for (int j = 0; j<5; j++){
      if (board[i][j]=='a'){
        d++;
        if (d == b){
          if (c==1){
            board[i][j]='b';
          }else if (c==2){
            board[i][j] ='c';
          }else if (c==3){
            board[i][j] ='z';
          }  
        }
      }
    }
  }
}
//数字を上側に詰める
void pack_on_top(char board[5][6]){
  //列ごとにforループ
  for (int i = 0; i<5; ++i){
    for (int j = 1; j<5; ++j){
      if (board[j][i]!='a'&&board[j-1][i]=='a'){
        board[j-1][i] = board[j][i];
        board[j][i]='a';
        for (int b = j-1; b>0; b--){
          if(board[b-1][i] == 'a'){
            board[b-1][i]=board[b][i];
            board[b][i]='a';
          }else break;
        }
      }
    }
  }
}
//数字を下側に詰める
void pack_under(char board[5][6]){
  for (int i = 4; i>=0; --i){
    for (int j = 3; j>=0; --j){
      if (board[j][i]!='a'&&board[j+1][i]=='a'){
        board[j+1][i] = board[j][i];
        board[j][i]='a';
        for (int b = j+1; b<4; b++){
          if(board[b+1][i] == 'a'){
            board[b+1][i]=board[b][i];
            board[b][i]='a';
          }else break;
        }
      }
    }
  }
}
//数字を左側に詰める
void pack_left(char board[5][6]){
  for (int j = 0; j<5; ++j){
    for (int i = 1; i<5; ++i){
      if (board[j][i]!='a'&&board[j][i-1]=='a'){
        board[j][i-1] = board[j][i];
        board[j][i]='a';
        for (int b = i-1; b>0; b--){
          if(board[j][b-1] == 'a'){
            board[j][b-1]=board[j][b];
            board[j][b]='a';
          }else break;
        }
      }
    }
  }
}
//数字を右側に詰める
void pack_right(char board[5][6]){
  for (int j = 4; j>=0; --j){
    for (int i = 3; i>=0; --i){
      if (board[j][i]!='a'&&board[j][i+1]=='a'){
        board[j][i+1] = board[j][i];
        board[j][i]='a';
        for (int b = i+1; b<4; b++){
          if(board[j][b+1] == 'a'){
            board[j][b+1]=board[j][b];
            board[j][b]='a';
          }else break;
        }
      }
    }
  }
}
//上側に詰めた時の数字の合体
void top_coalescence(char board[5][6]){
  for (int i=0; i<5; i++){
    if (board[0][i]!='a'&&board[0][i]==board[1][i]){ //printf("succeed\r\n");
      board[0][i]=board[0][i]+1;
      board[1][i]='a';
      if (board[2][i]!='a'&&board[2][i]==board[3][i]){
        board[2][i]=board[2][i]+1;
        board[3][i]='a';
      }else{
        if (board[3][i]!='a'&&board[3][i]==board[4][i]){
        board[3][i]=board[3][i]+1;
        board[4][i]='a';
        }
      }
    }else {
      if (board[1][i]!='a'&&board[1][i]==board[2][i]){
        board[1][i]=board[1][i]+1;
        board[2][i]='a';
        if (board[3][i]!='a'&&board[3][i]==board[4][i]){
          board[3][i]=board[3][i]+1;
          board[4][i]='a';
        }
      }else{
        if (board[2][i]!='a'&&board[2][i]==board[3][i]){
          board[2][i]=board[2][i]+1;
          board[3][i]='a';
        }else if (board[3][i]!='a'&&board[3][i]==board[4][i]){
          board[3][i]=board[3][i]+1;
          board[4][i]='a';
        }
      }
    }
  }
}
//上側に詰めた時の数字の合体 (@あり)
void top_coalescence2(char board[5][6]){
  for (int i=0; i<5; i++){
    if (board[0][i]!='a'&&(board[0][i]==board[1][i]||board[0][i]=='z'||board[1][i]=='z')){ //printf("succeed\r\n");
      //@関連の分岐
      if (board[0][i]!='z'){
        board[0][i]=board[0][i]+1;
        board[1][i]='a';
      }else if(board[1][i]!='z'){
        board[0][i]=board[1][i]+1;
        board[1][i]='a';
      }else{
        board[0][i]='b';
        board[1][i]='a';
      }
      
      if (board[2][i]!='a'&&(board[2][i]==board[3][i]||board[2][i]=='z'||board[3][i]=='z')){
        //@関連の分岐
        if (board[2][i]!='z'){
          board[2][i]=board[2][i]+1;
          board[3][i]='a';
        }else if(board[3][i]!='z'){
          board[2][i]=board[3][i]+1;
          board[3][i]='a';
        }else{
          board[2][i]='b';
          board[3][i]='a';
        }
      }else{
        if (board[3][i]!='a'&&(board[3][i]==board[4][i]||board[3][i]=='z'||board[3][i]=='z')){
        //@関連の分岐
          if (board[3][i]!='z'){
            board[3][i]=board[3][i]+1;
            board[4][i]='a';
          }else if(board[4][i]!='z'){
            board[3][i]=board[4][i]+1;
            board[4][i]='a';
          }else{
            board[3][i]='b';
            board[4][i]='a';
          }
        }
      }
    }else {
      if (board[1][i]!='a'&&(board[1][i]==board[2][i]||board[1][i]=='z'||board[2][i]=='z')){
        //@関連の分岐
        if (board[1][i]!='z'){
          board[1][i]=board[1][i]+1;
          board[2][i]='a';
        }else if(board[2][i]!='z'){
          board[1][i]=board[2][i]+1;
          board[2][i]='a';
        }else{
          board[1][i]='b';
          board[2][i]='a';
        }
        if (board[3][i]!='a'&&(board[3][i]==board[4][i]||board[3][i]=='z'||board[4][i]=='z')){
          //@関連の分岐
          if (board[3][i]!='z'){
            board[3][i]=board[3][i]+1;
            board[4][i]='a';
          }else if(board[4][i]!='z'){
            board[3][i]=board[4][i]+1;
            board[4][i]='a';
          }else{
            board[3][i]='b';
            board[4][i]='a';
          }
        }
      }else{
        if (board[2][i]!='a'&&(board[2][i]==board[3][i]||board[2][i]=='z'||board[3][i]=='z')){
          //@関連の分岐
          if (board[2][i]!='z'){
            board[2][i]=board[2][i]+1;
            board[3][i]='a';
          }else if(board[3][i]!='z'){
            board[2][i]=board[3][i]+1;
            board[3][i]='a';
          }else{
            board[2][i]='b';
            board[3][i]='a';
          }
        }else if (board[3][i]!='a'&&(board[3][i]==board[4][i]||board[3][i]=='z'||board[4][i]=='z')){
          //@関連の分岐
          if (board[3][i]!='z'){
            board[3][i]=board[3][i]+1;
            board[4][i]='a';
          }else if(board[4][i]!='z'){
            board[3][i]=board[4][i]+1;
            board[4][i]='a';
          }else{
            board[3][i]='b';
            board[4][i]='a';
          }
        }
      }
    }
  }
}
//下側に詰めた時の数字の合体
void under_coalescence(char board[5][6]){
  for (int i=0; i<5; i++){
    if (board[4][i]!='a'&&board[4][i]==board[3][i]){ //printf("succeed\r\n");
      board[4][i]=board[4][i]+1;
      board[3][i]='a';
      if (board[2][i]!='a'&&board[2][i]==board[1][i]){
        board[2][i]=board[2][i]+1;
        board[1][i]='a';
      }else{
        if (board[1][i]!='a'&&board[1][i]==board[0][i]){
        board[1][i]=board[1][i]+1;
        board[0][i]='a';
        }
      }
    }else {
      if (board[3][i]!='a'&&board[3][i]==board[2][i]){
        board[3][i]=board[3][i]+1;
        board[2][i]='a';
        if (board[1][i]!='a'&&board[1][i]==board[0][i]){
          board[1][i]=board[1][i]+1;
          board[0][i]='a';
        }
      }else{
        if (board[2][i]!='a'&&board[2][i]==board[1][i]){
          board[2][i]=board[2][i]+1;
          board[1][i]='a';
        }else if (board[1][i]!='a'&&board[1][i]==board[0][i]){
          board[1][i]=board[1][i]+1;
          board[0][i]='a';
        }
      }
    }
  }
}
//下側に詰めた時の数字の合体(@あり)
void under_coalescence2(char board[5][6]){
  for (int i=0; i<5; i++){
    if (board[4][i]!='a'&&(board[4][i]==board[3][i]||board[3][i]=='z'||board[4][i]=='z')){ 
      //@関連の分岐
      if (board[4][i]!='z'){
            board[4][i]=board[4][i]+1;
            board[3][i]='a';
          }else if(board[3][i]!='z'){
            board[4][i]=board[3][i]+1;
            board[3][i]='a';
          }else{
            board[4][i]='b';
            board[3][i]='a';
          }
      if (board[2][i]!='a'&&(board[2][i]==board[1][i]||board[2][i]=='z'||board[1][i]=='z')){
        //@関連の分岐
        if (board[2][i]!='z'){
            board[2][i]=board[2][i]+1;
            board[1][i]='a';
          }else if(board[1][i]!='z'){
            board[2][i]=board[1][i]+1;
            board[1][i]='a';
          }else{
            board[2][i]='b';
            board[1][i]='a';
          }
      }else{
        if (board[1][i]!='a'&&(board[1][i]==board[0][i]||board[1][i]=='z'||board[0][i]=='z')){
        //@関連の分岐
          if (board[1][i]!='z'){
              board[1][i]=board[1][i]+1;
              board[0][i]='a';
            }else if(board[0][i]!='z'){
              board[1][i]=board[0][i]+1;
              board[0][i]='a';
            }else{
              board[1][i]='b';
              board[0][i]='a';
            }
          }
      }
    }else {
      if (board[3][i]!='a'&&(board[3][i]==board[2][i]||board[3][i]=='z'||board[2][i]=='z')){
        //@関連の分岐
        if (board[3][i]!='z'){
            board[3][i]=board[3][i]+1;
            board[2][i]='a';
          }else if(board[2][i]!='z'){
            board[3][i]=board[2][i]+1;
            board[2][i]='a';
          }else{
            board[3][i]='b';
            board[2][i]='a';
          }
        if (board[1][i]!='a'&&(board[1][i]==board[0][i]||board[1][i]=='z'||board[0][i]=='z')){
          //@関連の分岐
          if (board[1][i]!='z'){
            board[1][i]=board[1][i]+1;
            board[0][i]='a';
          }else if(board[0][i]!='z'){
            board[1][i]=board[0][i]+1;
            board[0][i]='a';
          }else{
            board[1][i]='b';
            board[0][i]='a';
          }
        }
      }else{
        if (board[2][i]!='a'&&(board[2][i]==board[1][i]||board[2][i]=='z'||board[1][i]=='z')){
          //@関連の分岐
          if (board[2][i]!='z'){
            board[2][i]=board[2][i]+1;
            board[1][i]='a';
          }else if(board[1][i]!='z'){
            board[2][i]=board[1][i]+1;
            board[1][i]='a';
          }else{
            board[2][i]='b';
            board[1][i]='a';
          }
        }else if (board[1][i]!='a'&&(board[1][i]==board[0][i]||board[1][i]=='z'||board[0][i]=='z')){
          //@関連の分岐
          if (board[1][i]!='z'){
            board[1][i]=board[1][i]+1;
            board[0][i]='a';
          }else if(board[0][i]!='z'){
            board[1][i]=board[0][i]+1;
            board[0][i]='a';
          }else{
            board[1][i]='b';
            board[0][i]='a';
          }
        }
      }
    }
  }
}
//左側に詰めた時の数字の合体
void left_coalescence(char board[5][6]){
  for (int i=0; i<5; i++){
    if (board[i][0]!='a'&&board[i][0]==board[i][1]){ //printf("succeed\r\n");
      board[i][0]=board[i][0]+1;
      board[i][1]='a';
      if (board[i][2]!='a'&&board[i][2]==board[i][3]){
        board[i][2]=board[i][2]+1;
        board[i][3]='a';
      }else{
        if (board[i][3]!='a'&&board[i][3]==board[i][4]){
        board[i][3]=board[i][3]+1;
        board[i][4]='a';
        }
      }
    }else {
      if (board[i][1]!='a'&&board[i][1]==board[i][2]){
        board[i][1]=board[i][1]+1;
        board[i][2]='a';
        if (board[i][3]!='a'&&board[i][3]==board[i][4]){
          board[i][3]=board[i][3]+1;
          board[i][4]='a';
        }
      }else{
        if (board[i][2]!='a'&&board[i][2]==board[i][3]){
          board[i][2]=board[i][2]+1;
          board[i][3]='a';
        }else if (board[i][3]!='a'&&board[i][3]==board[i][4]){
          board[i][3]=board[i][3]+1;
          board[i][4]='a';
        }
      }
    }
  }
}
//左側に詰めた時の数字の合体(@あり)
void left_coalescence2(char board[5][6]){
  for (int i=0; i<5; i++){
    if (board[i][0]!='a'&&(board[i][0]==board[i][1]||board[i][0]=='z'||board[i][1]=='z')){ 
      //@関連の分岐
      if (board[i][0]!='z'){
        board[i][0]=board[i][0]+1;
        board[i][1]='a';
      }else if(board[i][1]!='z'){
        board[i][0]=board[i][1]+1;
        board[i][1]='a';
      }else{
        board[i][0]='b';
        board[i][1]='a';
      }
      if (board[i][2]!='a'&&(board[i][2]==board[i][3]||board[i][2]=='z'||board[i][3]=='z')){
        //@関連の分岐
        if (board[i][2]!='z'){
          board[i][2]=board[i][2]+1;
          board[i][3]='a';
        }else if(board[i][3]!='z'){
          board[i][2]=board[i][3]+1;
          board[i][3]='a';
        }else{
          board[i][2]='b';
          board[i][3]='a';
      }
      }else{
        if (board[i][3]!='a'&&(board[i][3]==board[i][4]||board[i][3]=='z'||board[i][4]=='z')){
        //@関連の分岐
          if (board[i][3]!='z'){
            board[i][3]=board[i][3]+1;
            board[i][4]='a';
          }else if(board[i][4]!='z'){
            board[i][3]=board[i][4]+1;
            board[i][4]='a';
          }else{
            board[i][3]='b';
            board[i][4]='a';
          }
        }
      }
    }else {
      if (board[i][1]!='a'&&(board[i][1]==board[i][2]||board[i][1]=='z'||board[i][2]=='z')){
        //@関連の分岐
        if (board[i][1]!='z'){
          board[i][1]=board[i][1]+1;
          board[i][2]='a';
        }else if(board[i][2]!='z'){
          board[i][1]=board[i][2]+1;
          board[i][2]='a';
        }else{
          board[i][1]='b';
          board[i][2]='a';
        }
        if (board[i][3]!='a'&&(board[i][3]==board[i][4]||board[i][3]=='z'||board[i][4]=='z')){
          //@関連の分岐
          if (board[i][3]!='z'){
            board[i][3]=board[i][3]+1;
            board[i][4]='a';
          }else if(board[i][4]!='z'){
            board[i][3]=board[i][4]+1;
            board[i][4]='a';
          }else{
            board[i][3]='b';
            board[i][4]='a';
          }
        }
      }else{
        if (board[i][2]!='a'&&(board[i][2]==board[i][3]||board[i][2]=='z'||board[i][3]=='z')){
          //@関連の分岐
          if (board[i][2]!='z'){
            board[i][2]=board[i][2]+1;
            board[i][3]='a';
          }else if(board[i][3]!='z'){
            board[i][2]=board[i][3]+1;
            board[i][3]='a';
          }else{
            board[i][2]='b';
           board[i][3]='a';
          }
        }else if (board[i][3]!='a'&&(board[i][3]==board[i][4]||board[i][3]=='z'||board[i][4]=='z')){
          //@関連の分岐
          if (board[i][3]!='z'){
            board[i][3]=board[i][3]+1;
            board[i][4]='a';
          }else if(board[i][4]!='z'){
            board[i][3]=board[i][4]+1;
            board[i][4]='a';
          }else{
            board[i][3]='b';
            board[i][4]='a';
          }
        }
      }
    }
  }
}
//右側に詰めた時の数字の合体
void right_coalescence(char board[5][6]){
  for (int i=0; i<5; i++){
    if (board[i][4]!='a'&&board[i][4]==board[i][3]){ //printf("succeed\r\n");
      board[i][4]=board[i][4]+1;
      board[i][3]='a';
      if (board[i][2]!='a'&&board[i][2]==board[i][1]){
        board[i][2]=board[i][2]+1;
        board[i][1]='a';
      }else{
        if (board[i][1]!='a'&&board[i][1]==board[i][0]){
        board[i][1]=board[i][1]+1;
        board[i][0]='a';
        }
      }
    }else {
      if (board[i][3]!='a'&&board[i][3]==board[i][2]){
        board[i][3]=board[i][3]+1;
        board[i][2]='a';
        if (board[i][1]!='a'&&board[i][1]==board[i][0]){
          board[i][1]=board[i][1]+1;
          board[i][0]='a';
        }
      }else{
        if (board[i][2]!='a'&&board[i][2]==board[i][1]){
          board[i][2]=board[i][2]+1;
          board[i][1]='a';
        }else if (board[i][1]!='a'&&board[i][1]==board[i][0]){
          board[i][0]=board[i][1]+1;
          board[i][0]='a';
        }
      }
    }
  }
}
//右側に詰めた時の数字の合体(@あり)
void right_coalescence2(char board[5][6]){
  for (int i=0; i<5; i++){
    if (board[i][4]!='a'&&(board[i][4]==board[i][3]||board[i][4]=='z'||board[i][3]=='z')){ 
      //@関連の分岐
      if (board[i][4]!='z'){
        board[i][4]=board[i][4]+1;
        board[i][3]='a';
      }else if(board[i][3]!='z'){
        board[i][4]=board[i][3]+1;
        board[i][3]='a';
      }else{
        board[i][4]='b';
        board[i][3]='a';
      }
      if (board[i][2]!='a'&&(board[i][2]==board[i][1]||board[i][2]=='z'||board[i][1]=='z')){
        //@関連の分岐
        if (board[i][2]!='z'){
          board[i][2]=board[i][2]+1;
          board[i][1]='a';
        }else if(board[i][1]!='z'){
          board[i][2]=board[i][1]+1;
          board[i][1]='a';
        }else{
          board[i][2]='b';
          board[i][1]='a';
        }
      }else{
        if (board[i][1]!='a'&&(board[i][1]==board[i][0]||board[i][1]=='z'||board[i][0]=='z')){
        //@関連の分岐
          if (board[i][1]!='z'){
            board[i][1]=board[i][1]+1;
            board[i][0]='a';
          }else if(board[i][0]!='z'){
            board[i][1]=board[i][0]+1;
            board[i][0]='a';
          }else{
            board[i][1]='b';
            board[i][0]='a';
          }
        }
      }
    }else {
      if (board[i][3]!='a'&&(board[i][3]==board[i][2]||board[i][3]=='z'||board[i][2]=='z')){
        //@関連の分岐
        if (board[i][3]!='z'){
          board[i][3]=board[i][3]+1;
          board[i][2]='a';
        }else if(board[i][2]!='z'){
          board[i][3]=board[i][2]+1;
          board[i][2]='a';
        }else{
          board[i][3]='b';
          board[i][2]='a';
        }
        if (board[i][1]!='a'&&(board[i][1]==board[i][0]||board[i][1]=='z'||board[i][0]=='z')){
          //@関連の分岐
          if (board[i][1]!='z'){
            board[i][1]=board[i][1]+1;
            board[i][0]='a';
          }else if(board[i][0]!='z'){
            board[i][1]=board[i][0]+1;
            board[i][0]='a';
          }else{
            board[i][1]='b';
            board[i][0]='a';
          }
        }
      }else{
        if (board[i][2]!='a'&&(board[i][2]==board[i][1]||board[i][2]=='z'||board[i][1]=='z')){
          //@関連の分岐
          if (board[i][2]!='z'){
            board[i][2]=board[i][2]+1;
            board[i][1]='a';
          }else if(board[i][1]!='z'){
            board[i][2]=board[i][1]+1;
            board[i][1]='a';
          }else{
            board[i][2]='b';
            board[i][1]='a';
          }
        }else if (board[i][1]!='a'&&(board[i][1]==board[i][0]||board[i][1]=='z'||board[i][0]=='z')){
          //@関連の分岐
          if (board[i][1]!='z'){
            board[i][1]=board[i][1]+1;
            board[i][0]='a';
          }else if(board[i][0]!='z'){
            board[i][1]=board[i][0]+1;
            board[i][0]='a';
          }else{
            board[i][1]='b';
            board[i][0]='a';
          }
        }
      }
    }
  }
}
//ボードのプリント
void board_print(char board[5][6]){
  for (int n = 0; n < 5; ++n) {
    for (int m = 0; m < 5; ++m) {
      if (board[n][m]=='a'){
        printf("%c    ", 'a');
      }else if (board[n][m]=='b'){
        printf("%c    ", '2');
      }else if (board[n][m]=='c'){
        printf("%c    ", '4');
      }else if (board[n][m]=='d'){
        printf("%c    ", '8');
      }else if (board[n][m]=='e'){
        printf("%d   ", 16);
      }else if (board[n][m]=='f'){
        printf("%d   ", 32);
      }else if (board[n][m]=='g'){
        printf("%d   ", 64);
      }else if (board[n][m]=='h'){
        printf("%d  ", 128);
      }else if (board[n][m]=='i'){
        printf("%d  ", 256);
      }else if (board[n][m]=='j'){
        printf("%d  ", 512);
      }else if (board[n][m]=='k'){
        printf("%d ", 1024);
      }else if (board[n][m]=='l'){
        printf("%d ", 2048);
      }else if (board[n][m]=='m'){
        printf("%d ", 4096);
      }else if (board[n][m]=='l'){
        printf("%d ", 8192);
      }
    }printf("\r\n");
  }
}
//ボードのプリント(@ver)
void board_print2(char board[5][6]){
  for (int n = 0; n < 5; ++n) {
    for (int m = 0; m < 5; ++m) {
      if (board[n][m]=='a'){
        printf("%c    ", 'a');
      }else if (board[n][m]=='b'){
        printf("%c    ", '2');
      }else if (board[n][m]=='c'){
        printf("%c    ", '4');
      }else if (board[n][m]=='d'){
        printf("%c    ", '8');
      }else if (board[n][m]=='e'){
        printf("%d   ", 16);
      }else if (board[n][m]=='f'){
        printf("%d   ", 32);
      }else if (board[n][m]=='g'){
        printf("%d   ", 64);
      }else if (board[n][m]=='h'){
        printf("%d  ", 128);
      }else if (board[n][m]=='i'){
        printf("%d  ", 256);
      }else if (board[n][m]=='j'){
        printf("%d  ", 512);
      }else if (board[n][m]=='k'){
        printf("%d ", 1024);
      }else if (board[n][m]=='l'){
        printf("%d ", 2048);
      }else if (board[n][m]=='m'){
        printf("%d ", 4096);
      }else if (board[n][m]=='l'){
        printf("%d ", 8192);
      }else if (board[n][m]=='z'){
        printf("%c    ", '@');
      }
    }printf("\r\n");
  }
}

int main (int argc, char *argv[]) {
    int z = 2;
    printf("easy; input 1\n");
    printf("normal; input 2\n");
    z = getchar();
    int c;

    system("/bin/stty raw onlcr");  // enterを押さなくてもキー入力を受け付けるようになる

    char board[5][6] = {
      "aaaaa",
      "aaaaa",
      "aaaaa",
      "aaaaa",
      "aaaaa"
    };
    
    if (z=='2'){
      while((c = getchar()) != '.') {
          system("clear");
          printf("Press '.' to close\r\n");

          //数字を詰めてランダムな数字を追加
          if (c=='A'){
            pack_on_top(board);
            top_coalescence(board);
            pack_on_top(board);
            //ランダムに2か4を追加
            make_random(board);
          }else if (c=='B'){
            pack_under(board);
            under_coalescence(board);
            pack_under(board);
            //ランダムに2か4を追加
            make_random(board);
          }else if (c=='D'){
            pack_left(board);
            left_coalescence(board);
            pack_left(board);
            //ランダムに2か4を追加
            make_random(board);
          }else if (c=='C'){
            pack_right(board);
            right_coalescence(board);
            pack_right(board);
            //ランダムに2か4を追加
            make_random(board);
          }
        
        
          //ボードの表示
          board_print(board);

          printf("You pressed '%c'\r\n", c);
      }
    }else{
      while((c = getchar()) != '.') {
          system("clear");
          printf("Press '.' to close\r\n");

          //数字を詰めてランダムな数字を追加
          if (c=='A'){
            pack_on_top(board);
            top_coalescence2(board);
            pack_on_top(board);
            //ランダムに2か4を追加
            make_random2(board);
          }else if (c=='B'){
            pack_under(board);
            under_coalescence2(board);
            pack_under(board);
            //ランダムに2か4を追加
            make_random2(board);
          }else if (c=='D'){
            pack_left(board);
            left_coalescence2(board);
            pack_left(board);
            //ランダムに2か4を追加
            make_random2(board);
          }else if (c=='C'){
            pack_right(board);
            right_coalescence2(board);
            pack_right(board);
            //ランダムに2か4を追加
            make_random2(board);
          }
        
        
          //ボードの表示
          board_print2(board);

          printf("You pressed '%c'\r\n", c);
      }
    }

    system("/bin/stty cooked");  // 後始末

    return 0;
}
