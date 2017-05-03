#include <stdio.h>
#include <string.h>

char data_of_numbers[10][5][3];

void init_data_of_numbers();
void print_char_with_count (int, char);
void print_specific_char_for_number(int, char);
void print_char_formatted_lcd(int, char *, int);
void print_space_between_number(int, char *);

int main (){
  init_data_of_numbers();
  int s;
  char number[100];
  while (1){
      scanf (" %d %s",&s,number);
      if (s == 0 && number[0] == '0') break;
      for (int j = 0; j < 5; j++){
          if (j == 0 || j == 2 || j == 4){
              print_char_formatted_lcd(s,number, j);
              printf("\n");
          }else{
              for (int k = 0; k < s; k++){
                  print_char_formatted_lcd(s,number,j);
                 printf("\n");
              }
          }
      }
      printf("\n");
  }

  return 0;
}

void print_char_formatted_lcd(int count , char * number, int j){
  for (int i = 0; i < strlen(number); i++){
      int pos_number = number[i] - '0';
      for (int x = 0; x < 3; x++){
          char choose = data_of_numbers[pos_number][j][x];
          print_specific_char_for_number(count,choose);
      }
      print_space_between_number(i, number);
  }
}

void print_space_between_number(int i , char * number){
  if (i + 1 != strlen(number)){
      printf(" ");
  }
}

void print_specific_char_for_number(int count , char c){
  switch(c){
      case 'S':
          print_char_with_count(1,' ');
          break;
      case 'Y':
          print_char_with_count(count,' ');
          break;
      case '-':
          print_char_with_count(count,'-');
          break;
      case '|':
          print_char_with_count(1,'|');
          break;
  }
}

void print_char_with_count (int count , char c){
  for (int i = 0; i < count; i++){
      printf("%c",c);
  }
}
void init_data_of_numbers(){
  //0
  data_of_numbers[0][0][0] = 'S';data_of_numbers[0][0][1] = '-';data_of_numbers[0][0][2] = 'S';
  data_of_numbers[0][1][0] = '|';data_of_numbers[0][1][1] = 'Y';data_of_numbers[0][1][2] = '|';
  data_of_numbers[0][2][0] = 'S';data_of_numbers[0][2][1] = 'Y';data_of_numbers[0][2][2] = 'S';
  data_of_numbers[0][3][0] = '|';data_of_numbers[0][3][1] = 'Y';data_of_numbers[0][3][2] = '|';
  data_of_numbers[0][4][0] = 'S';data_of_numbers[0][4][1] = '-';data_of_numbers[0][4][2] = 'S';
  //end 0

  //1
  data_of_numbers[1][0][0] = 'S';data_of_numbers[1][0][1] = 'Y';data_of_numbers[1][0][2] = 'S';
  data_of_numbers[1][1][0] = 'S';data_of_numbers[1][1][1] = 'Y';data_of_numbers[1][1][2] = '|';
  data_of_numbers[1][2][0] = 'S';data_of_numbers[1][2][1] = 'Y';data_of_numbers[1][2][2] = 'S';
  data_of_numbers[1][3][0] = 'S';data_of_numbers[1][3][1] = 'Y';data_of_numbers[1][3][2] = '|';
  data_of_numbers[1][4][0] = 'S';data_of_numbers[1][4][1] = 'Y';data_of_numbers[1][4][2] = 'S';
  //end 1

  //2
  data_of_numbers[2][0][0] = 'S';data_of_numbers[2][0][1] = '-';data_of_numbers[2][0][2] = 'S';
  data_of_numbers[2][1][0] = 'S';data_of_numbers[2][1][1] = 'Y';data_of_numbers[2][1][2] = '|';
  data_of_numbers[2][2][0] = 'S';data_of_numbers[2][2][1] = '-';data_of_numbers[2][2][2] = 'S';
  data_of_numbers[2][3][0] = '|';data_of_numbers[2][3][1] = 'Y';data_of_numbers[2][3][2] = 'S';
  data_of_numbers[2][4][0] = 'S';data_of_numbers[2][4][1] = '-';data_of_numbers[2][4][2] = 'S';
  //end2

  //3
  data_of_numbers[3][0][0] = 'S';data_of_numbers[3][0][1] = '-';data_of_numbers[3][0][2] = 'S';
  data_of_numbers[3][1][0] = 'S';data_of_numbers[3][1][1] = 'Y';data_of_numbers[3][1][2] = '|';
  data_of_numbers[3][2][0] = 'S';data_of_numbers[3][2][1] = '-';data_of_numbers[3][2][2] = 'S';
  data_of_numbers[3][3][0] = 'S';data_of_numbers[3][3][1] = 'Y';data_of_numbers[3][3][2] = '|';
  data_of_numbers[3][4][0] = 'S';data_of_numbers[3][4][1] = '-';data_of_numbers[3][4][2] = 'S';
  //end3

  //4
  data_of_numbers[4][0][0] = 'S';data_of_numbers[4][0][1] = 'Y';data_of_numbers[4][0][2] = 'S';
  data_of_numbers[4][1][0] = '|';data_of_numbers[4][1][1] = 'Y';data_of_numbers[4][1][2] = '|';
  data_of_numbers[4][2][0] = 'S';data_of_numbers[4][2][1] = '-';data_of_numbers[4][2][2] = 'S';
  data_of_numbers[4][3][0] = 'S';data_of_numbers[4][3][1] = 'Y';data_of_numbers[4][3][2] = '|';
  data_of_numbers[4][4][0] = 'S';data_of_numbers[4][4][1] = 'Y';data_of_numbers[4][4][2] = 'S';
  //end4

  //5
  data_of_numbers[5][0][0] = 'S';data_of_numbers[5][0][1] = '-';data_of_numbers[5][0][2] = 'S';
  data_of_numbers[5][1][0] = '|';data_of_numbers[5][1][1] = 'Y';data_of_numbers[5][1][2] = 'S';
  data_of_numbers[5][2][0] = 'S';data_of_numbers[5][2][1] = '-';data_of_numbers[5][2][2] = 'S';
  data_of_numbers[5][3][0] = 'S';data_of_numbers[5][3][1] = 'Y';data_of_numbers[5][3][2] = '|';
  data_of_numbers[5][4][0] = 'S';data_of_numbers[5][4][1] = '-';data_of_numbers[5][4][2] = 'S';
  //end5

  //6
  data_of_numbers[6][0][0] = 'S';data_of_numbers[6][0][1] = '-';data_of_numbers[6][0][2] = 'S';
  data_of_numbers[6][1][0] = '|';data_of_numbers[6][1][1] = 'Y';data_of_numbers[6][1][2] = 'S';
  data_of_numbers[6][2][0] = 'S';data_of_numbers[6][2][1] = '-';data_of_numbers[6][2][2] = 'S';
  data_of_numbers[6][3][0] = '|';data_of_numbers[6][3][1] = 'Y';data_of_numbers[6][3][2] = '|';
  data_of_numbers[6][4][0] = 'S';data_of_numbers[6][4][1] = '-';data_of_numbers[6][4][2] = 'S';
  //end6

  //7
  data_of_numbers[7][0][0] = 'S';data_of_numbers[7][0][1] = '-';data_of_numbers[7][0][2] = 'S';
  data_of_numbers[7][1][0] = 'S';data_of_numbers[7][1][1] = 'Y';data_of_numbers[7][1][2] = '|';
  data_of_numbers[7][2][0] = 'S';data_of_numbers[7][2][1] = 'Y';data_of_numbers[7][2][2] = 'S';
  data_of_numbers[7][3][0] = 'S';data_of_numbers[7][3][1] = 'Y';data_of_numbers[7][3][2] = '|';
  data_of_numbers[7][4][0] = 'S';data_of_numbers[7][4][1] = 'Y';data_of_numbers[7][4][2] = 'S';
  //end7

  //8
  data_of_numbers[8][0][0] = 'S';data_of_numbers[8][0][1] = '-';data_of_numbers[8][0][2] = 'S';
  data_of_numbers[8][1][0] = '|';data_of_numbers[8][1][1] = 'Y';data_of_numbers[8][1][2] = '|';
  data_of_numbers[8][2][0] = 'S';data_of_numbers[8][2][1] = '-';data_of_numbers[8][2][2] = 'S';
  data_of_numbers[8][3][0] = '|';data_of_numbers[8][3][1] = 'Y';data_of_numbers[8][3][2] = '|';
  data_of_numbers[8][4][0] = 'S';data_of_numbers[8][4][1] = '-';data_of_numbers[8][4][2] = 'S';
  //end8

  //9
  data_of_numbers[9][0][0] = 'S';data_of_numbers[9][0][1] = '-';data_of_numbers[9][0][2] = 'S';
  data_of_numbers[9][1][0] = '|';data_of_numbers[9][1][1] = 'Y';data_of_numbers[9][1][2] = '|';
  data_of_numbers[9][2][0] = 'S';data_of_numbers[9][2][1] = '-';data_of_numbers[9][2][2] = 'S';
  data_of_numbers[9][3][0] = 'S';data_of_numbers[9][3][1] = 'Y';data_of_numbers[9][3][2] = '|';
  data_of_numbers[9][4][0] = 'S';data_of_numbers[9][4][1] = '-';data_of_numbers[9][4][2] = 'S';
  //end9
}
