#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Employee{
    int uid[15];
    char name[10];
    bool gender;//1 for male, 0 for female
    bool Marital_status;//1 for married, 0 for unmarried
    int degree;
    char department[10];
    char position[10];
    int salary;
    int length_of_service;
};

int main(){
    for(;;){
        printf("**************菜单选项**************\n1. Add Employee\n************************************");
        //提示输入
        int choice;
        printf("请选择:");
        scanf("%d",&choice);
    }
}