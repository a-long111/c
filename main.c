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
        printf("**************菜单选项**************\n");
        printf("1.添加员工信息\n");
        printf("2.删除员工信息\n");
        printf("3.修改员工信息\n");
        printf("4. 查询员工信息\n");
        printf("5. 删除员工信息\n");
        printf("6. 保存记录至文件\n");
        printf("7. 从文件读取记录\n");
        printf("8. 退出\n");
        printf("************************************\n");
        //提示输入
        int choice;
        printf("\n请选择:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            //添加员工信息
        case 2:
            //删除员工信息
        case 3:
            //修改员工信息
        case 4:
            // 查询员工信息
        case 5:
            // 删除员工信息
        case 6:
            // 保存记录至文件
        case 7:
            // 从文件读取记录
        case 8:
            // 退出
            return 0;
        default:
            printf("输入错误,请重新输入!\n");
        }
    }
}