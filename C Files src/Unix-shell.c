#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LINE		80 /* 80 chars per line, per command */
char history[100][80];			//保存历史记录
int h = 0;			        	//历史记录下标
void print(){                  //按序号输出所有历史记录
	int i = 0;
	while( i < h - 1)
	{
		printf("%d : %s", i+1 , history[i]);
		i++;
	}
}

int main(void)
{
    int should_run = 1;
	char input[80] ;		
	while (should_run){ 
        //用于传递参数的指针
		char *args[MAX_LINE / 2 + 1] = { NULL }; 
		printf("osh>");
		fflush(stdout); 
        //用flag标记是否wait
		int i,j,flag = 1;	
		i = j = 0;
        //input保存命令行输入的字符串（包含了空格和结尾"\n"）
		fgets(input,80,stdin);
		if(strcmp(input,"history\n")==0 or strcmp(input,"history &\n")==0){
			print();
			continue;
		}
        //把input保存到history里
		while (j < sizeof(input)){   
			history[h][j] = input[j];
			j++;
		}
		h++;

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
			flag = 0; 
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
			print();
			continue;
		}
		else{};
		

		//根据flag判断是否需要父进程调用wait()
		if (flag == 0){//不需要wait()
			int pid;
			pid = fork();
			if (pid < 0)
				printf("fork error!\n");
			else if (pid == 0){
				execvp(args[0], args);//传递参数给execvp()
				}
			else{
				printf("%s","I'm father without wait()\n");
				continue;
				}
		}
		else{//需要wait()
			int pid;
			pid = fork();
			if (pid < 0)
				printf("fork error!\n");
			else if (pid == 0){
				execvp(args[0], args);//传递参数给execvp()
				}
			else{
				wait(NULL);
				printf("%s","I'm father with wait()\n");
				continue;
			}
		}

	}
	return 0;
}
