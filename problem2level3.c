
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

char stack[max][50];
int top=-1;
int timestamp=-1;

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
		printf("Enter website\n");
        scanf("%s",reg);
        top=top+1;
        timestamp=top;
        printf("\n%d\n",timestamp);
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
        timestamp=top;
        printf("\n%d\n",timestamp);
        return 0;
    }

}

int peek(){
    if (!isEmpty()){
    printf("the top element:%s\n",stack[timestamp]);
    }

    else{
        printf("Empty\n");
    }

    return 0;
}

int display(){
    int i;
    printf("\nBackward Stack\n");
    if(timestamp==-1){
        printf("backward stack is empty\n");
    }
    else{
    for(i=timestamp;i>=0;i--){
        printf("%s\n",stack[i]);
    }
    }

    printf("\nForward Stack\n");
    if(timestamp==max){
        printf("forward stack is empty\n");
    }
    else{
    for(i=timestamp+1;i<=top;i++){
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
        printf("YES the student %s has submitted the assignment\n",stack[i]);
        }
        else if(flag==2){
        printf("NO the student %s has not submitted the assignment\n",stack[i]);
        }




    return 1;
}

void displayn(int n){

	if(timestamp>=n){
            while(timestamp>n){
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
                  printf("4-forward \n");
                   printf("5-query\n");
                   printf("6-Display\n");
                   printf("7-to exit\n");

                   scanf("%d",&ch);
                 switch(ch){
                       case 1:push(reg);
                            display();
                              break;
                       case 2:timestamp--;
                            display();
                              break;
                        case 4:timestamp++;
                                display();
                              break;

                       case 3:peek();
                              break;

                       case 5:printf("ENTER THE REG NO. OF STUDENT\n");
                              scanf("%s",stu);
                              query(stu);
                              break;
                            case 6:display(); break;

                       case 7:printf("EXIT");loop=0;
                              break;
                       default:printf("invalid statement\n");
                               loop=0;
                              break;
                   }






    }while(loop);

    return 1;
}

