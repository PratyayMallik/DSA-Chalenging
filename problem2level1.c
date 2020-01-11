#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

char stack[max][50];
int top=-1;

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if(top==max-1){
        return 1;
    }
    else{
        return 0;
    }
}

int push(){
    if (isFull()){
        printf("The stack is full\n");
        return 0;
    }
    else{
		char reg[50];
		printf("enter the website\n");
        scanf("%s",reg);
        top=top+1;
        strcpy(stack[top],reg);
        return 0;
    }
}

int pop(){
    if (isEmpty()){
        printf("the stack is empty\n");
        return 0;
    }
    else
    {
        printf("item poped:%s\n",stack[top]);
        top=top-1;
        return 0;
    }

}

int peek(){
    if (!isEmpty()){
    printf("the top element:%s\n",stack[top]);
    }

    else{
        printf("No one submitted assignment\n");
    }

    return 0;
}

int display(){
    int i;
    printf("Backward stack")
    if(isEmpty()){
        printf("Backward empty\n");
    }
    else{
    for(i=top;i>=0;i--){
        printf("%s\n",stack[i]);
    }
    }


    return 0;
}

int query(char stu[50]){
    int flag=0;

        int i;
        for(i=0;i<top+1;i++){
            if(!strcmp(stu,stack[i])){
                flag=1;
                break;
            }
            else{
                flag=2;
            }
        }
        if(flag==1){
        printf("YES the website %s has been searched\n",stack[i]);
        }
        else if(flag==2){
        printf("NO the website %s has not been searched\n",stack[i]);
        }




    return 1;
}

void displayn(int n){

	if(top>=n){
            while(top>n){
		printf("\n\tthe student %s is poped",stack[top]);
		top--;
		}
	}
	else{
        printf("\n\tThe stack contains less than %d assignments",n);
	}
}


int main(){
    int login,ch,chh;
    int a;
    int loop=1;
    char reg[50];
    char pass[50];
    char stu[50];
    do{ printf("\n1-Browse \n");
                   printf("2-Backward \n");
                   printf("3-Last searched website\n");
                   printf("4-Display the first n searched website\n");
                   printf("5-query\n");
                   printf("6-Display\n");
                   printf("7-to exit\n");

                   scanf("%d",&ch);
                 switch(ch){
                       case 1:push(reg);
                              break;
                       case 2:pop();
                              break;

                       case 3:peek();
                              break;
                       case 4:printf("first n students submitted\n");
                       scanf("%d",&a);
                              displayn(a);
                              break;
                       case 5:printf("ENTER THE REG NO. OF STUDENT\n");
                              scanf("%s",stu);
                              query(stu);
                              break;
                            case 6:display();

                       case 7:printf("EXIT");loop=0;
                              break;
                       default:printf("invalid statement\n");
                               loop=0;
                              break;
                   }






    }while(loop);

    return 1;
}

