#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

char backward[max][50];
char forward[max][50];
int backtop=-1;
int fortop=-1;

int backisEmpty(){
    if(backtop==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int forisEmpty(){
    if(fortop==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int forisFull(){
    if(fortop==max-1){
        return 1;
    }
    else{
        return 0;
    }
}

int backisFull(){
    if(backtop==max-1){
        return 1;
    }
    else{
        return 0;
    }
}

int browse(){
    if (backisFull()){
        printf("The stack is full\n");
        return 0;
    }
    else{
		char reg[50];
		printf("enter website\n");
        scanf("%s",reg);
        backtop=backtop+1;
        strcpy(backward[backtop],reg);
        return 0;
    }
}



int backpop(){

    if (backisEmpty()){
        printf("the stack is empty\n");
        return 0;

    }
    else
    {
        printf("item poped:%s\n",backward[backtop]);


        if (forisFull()){
        printf("The forward stack is full\n");
        return 0;
    }
    else{
		fortop=fortop+1;
        strcpy(forward[fortop],backward[backtop]);

    }

        backtop=backtop-1;
        return 0;
    }

}

int forpop(){

    if (forisEmpty()){
        printf("the stack is empty\n");

    }
    else
    {
        printf("item poped: %s\n",forward[fortop]);

        if (backisFull()){
        printf("The backward stack is full\n");
        return 0;
    }
    else{

        backtop=backtop+1;
        strcpy(backward[backtop],forward[fortop]);

    }

        fortop=fortop-1;
        return 0;
    }

}

int peek(){
    if (!backisEmpty()){
    printf("the top element:%s\n",backward[backtop]);
    }

    else{
        printf("No one submitted assignment\n");
    }

    return 0;
}

int display(){
    int i;
    printf("\nBackward stack\n");
    if(backisEmpty()){
        printf("Backward stack is empty\n");
    }

    else{
    for(i=backtop;i>=0;i--){
        printf("%s\n",backward[i]);
    }
    }
    printf("\nForward stack\n");
    if(forisEmpty()){
        printf("Forward stack is empty\n");
    }

    else{
    for(i=fortop;i>=0;i--){
        printf("%s\n",forward[i]);
    }
    }

    return 0;
}

int query(char stu[50]){
    int flag=0;

        int i;
        for(i=0;i<backtop+1;i++){
            if(!strcmp(stu,backward[i])){
                flag=1;
                break;
            }
            else{
                flag=2;
            }
        }
        if(flag==1){
        printf("Website %s has been searched\n",backward[i]);
        }
        else if(flag==2){
        printf("NO the website %s has not been searched\n",backward[i]);
        }




    return 1;
}

void displayn(int n){

	if(backtop>=n){
            while(backtop>n){
		printf("\n\tthe student %s is poped",backward[backtop]);
		backtop--;
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

                    printf("5-forward\n");
                   printf("6-Display\n");
                   printf("7-to exit\n");

                   scanf("%d",&ch);
                 switch(ch){
                       case 1:browse();
                                display();
                              break;
                       case 2:backpop();
                                display();
                              break;

                       case 3:peek();
                              break;
                       /*case 4:printf("first n students submitted\n");
                       scanf("%d",&a);
                              displayn(a);
                              break;*/
                        case 5:forpop();
                                display();
                              break;
                       case 6:display();
                            break;

                       case 7:printf("EXIT");loop=0;
                              break;
                       default:printf("invalid statement\n");
                               loop=0;
                              break;
                   }






    }while(loop);

    return 1;
}

