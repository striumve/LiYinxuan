//简易餐厅管理系统
//Li Yinxuan
//代码参考自《C程序设计（第5版）学习辅导》，谭浩强，清华大学出版社

#include <stdio.h>
#include <string.h>
#define MaxSize 20

struct guest_info {
	char name[8]; 
	int sum; 
	char time[10]; 
	int number; 
} GuestList[MaxSize]; 

void Insert(int *); 
void Search(int ); 
void Update(int); 
void Delete(int *); 
void Show(int); 

int main() {
	int i; 
	int count = 0; 
	do {
		printf("\n"); 
		printf("1--插入(Insert)\n");
		printf("2--查询(Search)\n");
		printf("3--修改(Update)\n");
		printf("4--删除(Delete)\n");
		printf("5--显示(Show)\n");
		printf("6--退出(Exit)\n");
		scanf_s("%d", &i);
		switch(i)
		{
			case 1: Insert(&count);
			        break; 
			case 2: Search(count);
			        break; 
			case 3: Update(count);
			        break;
			case 4: Delete(&count);
			        break;
			case 5: Show(count);
			        break;
			case 6: break;
			default: printf("错误选择");
			         break; 
		}
	} while(i != 6); 
	return 0; 
}

void Insert(int *count) {
	int i, in_number; 
	if(*count == MaxSize) {
		printf("空间已满");
		return; 
	}
	printf("输入编号：");
	scanf_s("%d", &in_number);
	for(i = 0;i < *count;i++) {
	if(GuestList[i].number == in_number) {
		printf("已经有相同编号\n");
		return; 
	}}
	GuestList[i].number = in_number; 
	printf("输入姓名："); 
	scanf_s("%s", &GuestList[i].name,8);
	printf("输入人数："); 
	scanf_s("%d", &GuestList[i].sum);
	printf("输入用餐时间："); 
	scanf_s("%s", &GuestList[i].time,10);
	(*count)++; 
	printf("插入成功\n");
}
	 
void Search(int count) {
	int i, number, flag = 1; 
	printf("要查询的编号：");
	scanf_s("%d", &number);
	for(i = 0;i < count && flag;i++) {
	    if(GuestList[i].number == number) {
		    printf("姓名：%s\n", GuestList[i].name);
		    printf("人数：%d\n", GuestList[i].sum);
		    printf("时间：%s\n", GuestList[i].time);
		    flag = 0; 
	    }
	}
	if(flag != 0) {
		printf("没有查询到数据\n");
	}
}

void Update(int count) {
	int i, number, flag = 1; 
	printf("要修改的编号：");
	scanf_s("%d", &number);
	for(i = 0;i < count && flag;i++) {
	    if(GuestList[i].number == number) {
	    	printf("输入人数：");
	    	scanf_s("%d", &GuestList[i].sum);
	    	printf("输入用餐时间：");
		    scanf_s("%s", &GuestList[i].time,10);
		    flag = 0; 
			printf("已修改\n");
	    }
	}
	if(flag != 0) {
		printf("没有查询到可以修改的数据\n");
	}
}
	
void Delete(int *count) {
	int i, j, number, flag=1; 
	printf("输入要删除数据的编号：");
	scanf_s("%d", &number);
	for(i = 0;i < *count && flag;i++) {
		if(GuestList[i].number == number) {
			for(j = i;j < *count;j++) {
				GuestList[j] = GuestList[j+1]; 
			}
			flag = 0; 
			(*count)--; 
			printf("已删除\n");
		}
	}
	if(flag != 0){
		printf("没有可以删除的数据\n");
	}
	
}

void Show(int count) {
	int i;
	printf("\n");
	printf("编号\t姓名\t人数\t用餐时间\n");
	for (i = 0; i < count; i++)
	{
		printf("%d\t", GuestList[i].number);
		printf("%s\t", GuestList[i].name);
		printf("%d\t", GuestList[i].sum);
		printf("%s\n", GuestList[i].time);
	}
}
