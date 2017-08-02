#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE    80             //���֧���ַ�����
#define RUN         1              //�궨������
#define WAIT        1              //����wait
#define NOT_WAIT    0              //����not wait

char* history[100] = {NULL};	   //������ʷ��¼
int h = 0;			               //��ʷ��¼�±�

void printHist(){                  //��������������ʷ��¼
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
        //���ڴ��ݲ�����ָ��
		char* args[MAX_LINE / 2 + 1] = { NULL }; 
		//����������
		fflush(stdout);
		printf("input>");
        //��flag����Ƿ�wait,Ĭ����wait
		int i=0,flag=WAIT;	

        //input��ȡ������������ַ�������������β"\n"��
		fgets(input,80,stdin);
		//�����historyָ��
		if(strcmp(input,"history\n")==0 or strcmp(input,"history &\n")==0){
			printHist();
			if(*history[h-1]!='h'){
				saveHist(h,strtok(input," "));
				h++;
			}
			continue;
		}
		
		//������ʷ��¼
		if(strcmp(input,history[h-1])!=0){
			saveHist(h,input);
			h++;
		}

        //��input���ַ������տո�ֶθ�ֵ��args
		args[i] = strtok(input, " ");
		while (args[i]!= NULL){
			i++;
			args[i] = strtok(NULL, " ");
			}		
		i--;		         	

        //���һ����NULL��args��������Ч�ַ���"\n"
        //�и��"\n"
		args[i] = strtok(args[i], "\n");	                 

		
        //����ͬ�����ж�
		if (*args[i] == '&'){
        //���һ���ַ���&��without wait��flag��1��ͬʱ��args[i]��ΪNULL
			args[i] = NULL;
			flag = NOT_WAIT; 
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
			printHist();
			continue;
		}
		else{};
		

		//����flag�ж��Ƿ���Ҫ�����̵���wait()
		if (flag == NOT_WAIT){//����Ҫwait()
			printf("%s","I'm father without wait()\n");
		}
		else{//��Ҫwait()
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
