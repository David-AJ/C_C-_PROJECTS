#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE		80 /* 80 chars per line, per command */
char history[100][80];			//������ʷ��¼
int h = 0;			        	//��ʷ��¼�±�
void print(){                  //��������������ʷ��¼
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
        //���ڴ��ݲ�����ָ��
		char *args[MAX_LINE / 2 + 1] = { NULL }; 
		printf("osh>");
		fflush(stdout); 
        //��flag����Ƿ�wait
		int i,j,flag = 1;	
		i = j = 0;
        //input����������������ַ����������˿ո�ͽ�β"\r\n"��
		fgets(input,80,stdin);
		if(input=="history\r\n"){
			print();
			continue;
		}
        //��input���浽history��
		while (j < sizeof(input)){   
			history[h][j] = input[j];
			j++;
		}
		h++;

        //��input���ַ������տո�ֶθ�ֵ��args
		args[i] = strtok(input, " ");
		while (args[i]!= NULL){
			i++;
			args[i] = strtok(NULL, " ");
			}		
		i--;		         	

        //���һ����NULL��args��������Ч�ַ���"\r\n"
        //�и��"\r\n"
		args[i] = strtok(args[i], "\r\n");	                 

		
        //����ͬ�����ж�
		if (*args[i] == '&'){
        //���һ���ַ���&��without wait��flag��1��ͬʱ��args[i]��ΪNULL
			args[i] = NULL;
			flag = 0; 
		}
		else if (*args[i] == '!'&*(args[i] + 1) == '!'){
			printf("%s",history[h-2]);
			continue;
		}
		else if (*args[i] == '!'&*(args[i] + 1) != '!'){ 
        //atoi()����ʵ��char��ת��Ϊint��
			int num = atoi(args[i] + 1);	
			printf("%s", history[num-1]);
			continue;
		}
		else if(*args[i]=='h'&*(args[i]+1)=='i'&*(args[i]+2)=='s'){
			print();
			continue;
		}
		else{};
		

		//����flag�ж��Ƿ���Ҫ�����̵���wait()
		if (flag == 0){//����Ҫwait()
			int pid;
			pid = fork();
			if (pid < 0)
				printf("fork error!");
			else if (pid == 0){
				execvp(args[0], args);//���ݲ�����execvp()
				}
			else{
				printf("%s","I'm father without wait()");
				continue;
				}
		}
		else{//��Ҫwait()
			int pid;
			pid = fork();
			if (pid < 0)
				printf("fork error!");
			else if (pid == 0){
				execvp(args[0], args);//���ݲ�����execvp()
				}
			else{
				wait(NULL);
				printf("%s","I'm father with wait()");
				continue;
			}
		}

	}
	return 0;
}
