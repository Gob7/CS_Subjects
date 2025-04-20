#include<stdio.h>
#include<string.h>

/*

//2's complement (incomplete concept, but machine works)

void q1(char str[],int i);
void q2(char str[],int i);
void q0(char str[],int i){
    if (str[i]=='$') q1(str,i-1);
    else q0(str,i+1);
}
void q1(char str[],int i){
    if (str[i]=='0') q1(str,i-1);
    else if(str[i]=='1') q2(str,i-1);
}
void q2(char str[],int i){
    if (str[i]=='0') str[i]='1';
    else if(str[i]=='1') str[i]='0';
    else return;
    q2(str,i-1);
}
void print(char str[]){
    int i=1;
    printf("2's complement: ");
    while(str[i]!='$') printf("%c",str[i++]);
}
void main(){
    char str[100];
    while(1){
        printf("\n\nEnter string: ");
        gets(str);
        int l=strlen(str);
        for (int i=l;i>0;i--) str[i]=str[i-1];
        str[0]='$';
        str[l+1]='$';
        q0(str,1);
        print(str);
    }
}

*/

//reverse a string

void q1(char str[],int i);
void q2(char str[],int i);
void q3(char str[],int i);
void q4(char str[],int i);
void q5(char str[],int i);      //final state
void q0(char str[],int i){      //initial state
    if (str[i]=='0'){
        str[i]='0';
        q0(str,i+1);
    }
    else if(str[i]=='1'){
        str[i]='1';
        q0(str,i+1);
    }
    else if(str[i]=='$'){
        str[i]='y';
        q1(str,i-1);
    }
}
void q1(char str[],int i){
    if (str[i]=='0'){
        str[i]='x';
        q2(str,i+1);
    }
    else if(str[i]=='1'){
        str[i]='x';
        q4(str,i+1);
    }
    else if(str[i]=='$'){
        str[i]='$';
        q5(str,i+1);
    }
    else if(str[i]=='x'){
        str[i]='x';
        q1(str,i-1);
    }
}
void q2(char str[],int i){
    if (str[i]=='0'){
        str[i]='0';
        q2(str,i+1);
    }
    else if(str[i]=='1'){
        str[i]='1';
        q2(str,i+1);
    }
    else if(str[i]=='$'){
        str[i]='0';
        q3(str,i-1);
    }
    else if(str[i]=='x'){
        str[i]='x';
        q2(str,i+1);
    }
    else if(str[i]=='y'){
        str[i]='y';
        q2(str,i+1);
    }
}
void q3(char str[],int i){
    if (str[i]=='0'){
        str[i]='0';
        q3(str,i-1);
    }
    else if(str[i]=='1'){
        str[i]='1';
        q3(str,i-1);
    }
    else if(str[i]=='y'){
        str[i]='y';
        q1(str,i-1);
    }
}
void q4(char str[],int i){
    if (str[i]=='0'){
        str[i]='0';
        q4(str,i+1);
    }
    else if(str[i]=='1'){
        str[i]='1';
        q4(str,i+1);
    }
    else if(str[i]=='$'){
        str[i]='1';
        q3(str,i-1);
    }
    else if(str[i]=='x'){
        str[i]='x';
        q4(str,i+1);
    }
    else if(str[i]=='y'){
        str[i]='y';
        q4(str,i+1);
    }
}
void q5(char str[],int i){
    return;
}
void print(char str[],int l){
    printf("\nReverse: ");
    for(int i=0;i<=2*l+1;i++) 
        printf("%c",str[i]);
}
void main(){
    char str[100];
    while(1){
        printf("\n\nEnter string: ");
        gets(str);
        int l=strlen(str);
        for (int i=l;i>0;i--) str[i]=str[i-1];
        str[0]='$';
        for (int i=l+1;i<=2*l+1;i++) str[i]='$';
        for(int i=0;i<=2*l+1;i++) 
            printf("%c",str[i]);
        q0(str,1);
        print(str,l);
    }
}