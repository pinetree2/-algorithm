#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
  element stack[MAX_STACK_SIZE];
  int top;
}StackType;


void init(StackType *s)
{
  s->top = -1;
}

int is_empty(StackType *s){
  if (s->top ==  -1){
    printf("1");
    return 1;
  }
  else{
    printf("0");
    return 0;
  }
}

void push(StackType *s,element item){
  
   s-> stack[++(s->top)] = item;

}

element pop(StackType *s){
  if(is_empty(s) == 1){
    printf("-1");
  }
  else{
    printf("%d",s->stack[(s->top)]);
    return s-> stack[(s->top)--];
    
  } 
}

void size(StackType *s){
  printf("%d",(s->top)+1); 
}

void top(StackType *s){
  if(is_empty(s) == 1){
    printf("-1");
  }
  printf("%d",s->stack[(s->top)]) ;
}

int main(){
  char str[MAX_STACK_SIZE] = "/0";
  StackType *stack;
  init(stack);
  int N,res;
  scanf("%d",&N);
  for(int i=0; i<N; i++){
    scanf("%s",str);
    if(strcmp(str,"push")){
      for(int i=0; i<strlen(str); i++){ //문자열의 길이만큼 반복
          if(str[i] > 47 && str[i] < 58) 
            res = res*10 + str[i]-48; // ASCII코드 상 숫자 범위 안일때만 실행         
             }
             push(stack,res);

    }

    else if(strcmp(str,"pop")){
      pop(stack);
    }
    else if(strcmp(str,"size")){
      size(stack);
    }
    else if(strcmp(str,"empty")){
      is_empty(stack);
    }
    else if(strcmp(str,"top")){
      top(stack);
    }


  }
}