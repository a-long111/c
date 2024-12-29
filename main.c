#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// 修改 Employee 结构体定义
struct Employee {
    int uid;            // 修改：移除数组，改为单个整数
    char name[32];      // 增加名字长度限制
    bool gender;
    bool Marital_status;
    int degree;
    char department[32]; // 增加部门名称长度限制
    char position[32];   // 增加职位名称长度限制
    int salary;
    int length_of_service;
};

#define MAX_EMPLOYEES 100
struct Employee employees[MAX_EMPLOYEES];
int employee_count = 0;

// 添加数据验证函数
bool validate_uid(int uid) {
    // 检查ID是否已存在
    for (int i = 0; i < employee_count; i++) {
        if (employees[i].uid == uid) {
            return false;
        }
    }
    // 检查ID范围
    return uid > 0 && uid < 10000;
}

bool validate_name(const char* name) {
    int len = strlen(name);
    return len >= 2 && len <= 32;
}

bool validate_degree(int degree) {
    return degree >= 1 && degree <= 5;
}

bool validate_salary(int salary) {
    return salary >= 0 && salary <= 1000000;
}

bool validate_length_of_service(int length) {
    return length >= 0 && length <= 50;
}

// 修改 add_employee 函数
void add_employee(struct Employee *employee) {
    printf("请输入员工信息:\n");
    
    // 验证员工编号
    do {
        printf("员工编号(1-9999): ");
        scanf("%d", &employee->uid);
        if (!validate_uid(employee->uid)) {
            printf("编号无效或已存在，请重新输入！\n");
        }
    } while (!validate_uid(employee->uid));

    // 验证员工姓名
    do {
        printf("员工姓名(2-32字符): ");
        scanf("%s", employee->name);
        if (!validate_name(employee->name)) {
            printf("姓名长度无效，请重新输入！\n");
        }
    } while (!validate_name(employee->name));

    // 验证性别
    do {
        printf("员工性别(1为男,0为女): ");
        scanf("%d", &employee->gender);
        if (employee->gender != 0 && employee->gender != 1) {
            printf("性别输入错误，请重新输入！\n");
        }
    } while (employee->gender != 0 && employee->gender != 1);

    // 验证婚姻状况
    do {
        printf("员工婚姻状况(1为已婚,0为未婚): ");
        scanf("%d", &employee->Marital_status);
        if (employee->Marital_status != 0 && employee->Marital_status != 1) {
            printf("婚姻状况输入错误，请重新输入！\n");
        }
    } while (employee->Marital_status != 0 && employee->Marital_status != 1);

    // 验证学历
    do {
        printf("员工学历(1为高中,2为大专,3为本科,4为硕士,5为博士): ");
        scanf("%d", &employee->degree);
        if (!validate_degree(employee->degree)) {
            printf("学历输入错误，请重新输入！\n");
        }
    } while (!validate_degree(employee->degree));

    printf("员工部门: ");
    scanf("%s", employee->department);
    
    printf("员工职位: ");
    scanf("%s", employee->position);

    // 验证工资
    do {
        printf("员工工资(0-1000000): ");
        scanf("%d", &employee->salary);
        if (!validate_salary(employee->salary)) {
            printf("工资范围无效，请重新输入！\n");
        }
    } while (!validate_salary(employee->salary));

    // 验证工龄
    do {
        printf("员工工龄(0-50): ");
        scanf("%d", &employee->length_of_service);
        if (!validate_length_of_service(employee->length_of_service)) {
            printf("工龄范围无效，请重新输入！\n");
        }
    } while (!validate_length_of_service(employee->length_of_service));

    if (employee_count < MAX_EMPLOYEES) {
        employees[employee_count] = *employee;
        employee_count++;
        printf("添加成功!\n");
    } else {
        printf("员工数量已达上限!\n");
    }
}

// 修改查找员工的逻辑
void delete_employee(int uid) {
    for (int i = 0; i < employee_count; i++) {
        if (employees[i].uid == uid) {  // 修改：直接比较整数
            for (int j = i; j < employee_count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employee_count--;
            printf("删除成功!\n");
            return;
        }
    }
    printf("未找到该员工!\n");
}

// 修改其他函数中的 uid 比较
void modify_employee(int uid) {
    for (int i = 0; i < employee_count; i++) {
        if (employees[i].uid == uid) {  // 修改：直接比较整数
            printf("请输入新的员工信息:\n");
            add_employee(&employees[i]);
            return;
        }
    }
    printf("未找到该员工!\n");
}

void query_employee(int uid) {
    for (int i = 0; i < employee_count; i++) {
        if (employees[i].uid == uid) {  // 修改：直接比较整数
            printf("\n员工信息:\n");
            printf("编号: %d\n", employees[i].uid);
            printf("姓名: %s\n", employees[i].name);
            printf("性别: %s\n", employees[i].gender ? "男" : "女");
            printf("婚姻: %s\n", employees[i].Marital_status ? "已婚" : "未婚");
            printf("学历: %d\n", employees[i].degree);
            printf("部门: %s\n", employees[i].department);
            printf("职位: %s\n", employees[i].position);
            printf("工资: %d\n", employees[i].salary);
            printf("工龄: %d\n", employees[i].length_of_service);
            return;
        }
    }
    printf("未找到该员工!\n");
}

// 修改文件存储格式为文本格式，提高可读性
void save_to_file() {
    FILE *fp = fopen("employees.txt", "w");
    if (fp == NULL) {
        printf("无法打开文件!\n");
        return;
    }
    
    fprintf(fp, "员工数量: %d\n\n", employee_count);
    for (int i = 0; i < employee_count; i++) {
        fprintf(fp, "员工编号: %d\n", employees[i].uid);
        fprintf(fp, "姓名: %s\n", employees[i].name);
        fprintf(fp, "性别: %s\n", employees[i].gender ? "男" : "女");
        fprintf(fp, "婚姻状况: %s\n", employees[i].Marital_status ? "已婚" : "未婚");
        fprintf(fp, "学历: %d\n", employees[i].degree);
        fprintf(fp, "部门: %s\n", employees[i].department);
        fprintf(fp, "职位: %s\n", employees[i].position);
        fprintf(fp, "工资: %d\n", employees[i].salary);
        fprintf(fp, "工龄: %d\n\n", employees[i].length_of_service);
    }
    
    fclose(fp);
    printf("保存成功!\n");
}

// 修改文件读取函数以匹配新的存储格式
void load_from_file() {
    FILE *fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        printf("无法打开文件!\n");
        return;
    }

    fscanf(fp, "员工数量: %d\n\n", &employee_count);
    
    for (int i = 0; i < employee_count; i++) {
        fscanf(fp, "员工编号: %d\n", &employees[i].uid);
        fscanf(fp, "姓名: %s\n", employees[i].name);
        fscanf(fp, "性别: %s\n", employees[i].gender ? "男" : "女");
        fscanf(fp, "婚姻状况: %s\n", employees[i].Marital_status ? "已婚" : "未婚");
        fscanf(fp, "学历: %d\n", &employees[i].degree);
        fscanf(fp, "部门: %s\n", employees[i].department);
        fscanf(fp, "职位: %s\n", employees[i].position);
        fscanf(fp, "工资: %d\n", &employees[i].salary);
        fscanf(fp, "工龄: %d\n\n", &employees[i].length_of_service);
    }
    
    fclose(fp);
    printf("读取成功!\n");
}

// 添加显示所有员工信息的函数
void display_all_employees() {
    if (employee_count == 0) {
        printf("暂无员工信息！\n");
        return;
    }

    printf("\n当前共有 %d 名员工:\n", employee_count);
    printf("----------------------------------------\n");
    for (int i = 0; i < employee_count; i++) {
        printf("\n第 %d 号员工信息:\n", i + 1);
        printf("编号: %d\n", employees[i].uid);
        printf("姓名: %s\n", employees[i].name);
        printf("性别: %s\n", employees[i].gender ? "男" : "女");
        printf("婚姻: %s\n", employees[i].Marital_status ? "已婚" : "未婚");
        printf("学历: ");
        switch(employees[i].degree) {
            case 1: printf("高中\n"); break;
            case 2: printf("大专\n"); break;
            case 3: printf("本科\n"); break;
            case 4: printf("硕士\n"); break;
            case 5: printf("博士\n"); break;
        }
        printf("部门: %s\n", employees[i].department);
        printf("职位: %s\n", employees[i].position);
        printf("工资: %d\n", employees[i].salary);
        printf("工龄: %d\n", employees[i].length_of_service);
        printf("----------------------------------------\n");
    }
}

// 修改查询功能，支持多种查询方式
void query_employee_menu() {
    printf("\n查询方式：\n");
    printf("1. 按工号查询\n");
    printf("2. 按姓名查询\n");
    printf("3. 按部门查询\n");
    printf("请选择查询方式: ");
    
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            int uid;
            printf("请输入工号: ");
            scanf("%d", &uid);
            query_employee(uid);
            break;
        }
        case 2: {
            char name[32];
            printf("请输入姓名: ");
            scanf("%s", name);
            int found = 0;
            for (int i = 0; i < employee_count; i++) {
                if (strcmp(employees[i].name, name) == 0) {
                    query_employee(employees[i].uid);
                    found = 1;
                }
            }
            if (!found) printf("未找到该员工！\n");
            break;
        }
        case 3: {
            char dept[32];
            printf("请输入部门: ");
            scanf("%s", dept);
            int found = 0;
            for (int i = 0; i < employee_count; i++) {
                if (strcmp(employees[i].department, dept) == 0) {
                    query_employee(employees[i].uid);
                    found = 1;
                }
            }
            if (!found) printf("未找到该部门的员工！\n");
            break;
        }
        default:
            printf("选择错误！\n");
    }
}

// 修改 main 函数中的菜单
int main() {
    FILE *fp = fopen("employees.txt", "r");
    if (fp != NULL) {
        load_from_file();
        fclose(fp);
    }
    else {
        //创建文件
        fp = fopen("employees.txt", "w");
    }

    while (1) {
        system("cls");  // 清屏
        printf("\n**************员工管理系统**************\n");
        printf("1. 增加员工信息\n");
        printf("2. 修改员工信息\n");
        printf("3. 显示员工信息\n");
        printf("4. 查询员工信息\n");
        printf("5. 删除员工信息\n");
        printf("6. 保存至记录文件\n");
        printf("7. 从记录文件读取员工信息\n");
        printf("8. 退出\n");
        printf("**************************************\n");

        int choice;
        printf("\n请选择: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("输入错误,请重新输入!\n");
            continue;
        }

        int uid;
        struct Employee emp;
        
        switch (choice) {
            case 1:
                add_employee(&emp);
                break;
            case 2:
                printf("请输入要修改的员工编号: ");
                scanf("%d", &uid);
                modify_employee(uid);
                break;
            case 3:
                display_all_employees();
                break;
            case 4:
                query_employee_menu();
                break;
            case 5:
                printf("请输入要删除的员工编号: ");
                scanf("%d", &uid);
                delete_employee(uid);
                break;
            case 6:
                save_to_file();
                break;
            case 7:
                load_from_file();
                break;
            case 8:
                printf("是否保存更改？(1:是 0:否): ");
                scanf("%d", &choice);
                if (choice == 1) {
                    save_to_file();
                }
                printf("感谢使用！\n");
                system("pause");  // 添加暂停
                return 0;
            default:
                printf("输入错误,请重新输入!\n");
        }
        
        printf("\n按任意键继续...");
        getchar();  // 清除之前的回车
        getchar();  // 等待用户按键
    }
}
