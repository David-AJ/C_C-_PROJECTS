#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE    80             //最大支持字符长度
#define RUN         1              //宏定义运行
#define WAIT        1              //定义wait
#define NOT_WAIT    0              //定义not wait

char* history[100] = {NULL};	   //保存历史记录
int h = 0;			               //历史记录下标

void printHist(){                  //按序号输出所有历史记录
	int i = 0;
	while(history[i]!=NULL)
	{
		printf("%d : %s", i+1 , history[i]);
		i++;
	}
}

void saveHist(int h, char* input){
	char* temp = new char[MAX_LINE];
	strcpy(temp,input);
	history[h] = temp;
}


int main(){
	char input[MAX_LINE] = {NULL} ;		
	while (RUN){ 
        //用于传递参数的指针
		char* args[MAX_LINE / 2 + 1] = { NULL }; 
		//清空输出缓存
		fflush(stdout);
		printf("input>");
        //用flag标记是否wait,默认是wait
		int i=0,flag=WAIT;	

        //input获取命令行输入的字符串（不包含结尾"\n"）
		fgets(input,80,stdin);
		//如果是history指令
		if(strcmp(input,"history\n")==0 or strcmp(input,"history &\n")==0){
			printHist();
			if(*history[h-1]!='h'){
				saveHist(h,strtok(input," "));
				h++;
			}
			continue;
		}
		
		//保存历史记录
		if(strcmp(input,history[h-1])!=0){
			saveHist(h,input);
			h++;
		}

        //把input的字符串按照空格分段赋值给args
		args[i] = strtok(input, " ");
		while (args[i]!= NULL){
			i++;
			args[i] = strtok(NULL, " ");
			}		
		i--;		         	

        //最后一个非NULL的args保存了有效字符和"\n"
        //切割掉"\n"
		args[i] = strtok(args[i], "\n");	                 

		
        //按不同命令判断
		if (*args[i] == '&'){
        //最后一个字符是&，without wait，flag置1，同时将args[i]置为NULL
			args[i] = NULL;
			flag = NOT_WAIT; 
		}
		else if (*args[i] == '!'&*(args[i] + 1) == '!'){
			printf("%s",history[h-2]);
			continue;
		}
		else if (*args[i] == '!'&*(args[i] + 1) != '!'){ 
        //atoi()函数实现char型转化为int型
			int num = atoi(args[i] + 1);	
			printf("%s", history[num-1]);
			continue;
		}
		else if(*args[i]=='h'&*(args[i]+1)=='i'&*(args[i]+2)=='s'){
			printHist();
			continue;
		}
		else{};
		

		//根据flag判断是否需要父进程调用wait()
		if (flag == NOT_WAIT){//不需要wait()
			printf("%s","I'm father without wait()\n");
		}
		else{//需要wait()
			printf("%s","I'm father with wait()\n");
		}
		i = 0;
		while(args[i]!=NULL){
			printf("#%d args:%s\n",i+1,args[i]);
			i++;
		}
	}
	return 0;
}
