#define MAX 100
#include<string.h>
#include<stdio.h>
int* calculate1(int w[],int test[],int re[],int len){
	int i,j;
	for(i=0;i<len;i++)
		re[i]=0;
	for(i=0;i<len;i++){
		for(j=0;j<len;j++){
			re[i]+=test[j]*w[i*len+j];
		}

	}
	return re;
}

int* calculate2(int w[],int test[],int re[],int len,int index){
	int i,j;
	for(j=0;j<len;j++){
		re[index]+=test[j]*w[index*len+j];
	}

	return re;
}

int cmp(int a[],int b[],int len){
	int i;
	for(i=0;i<len;i++){
		if(a[i]!=b[i])
			return 0;
	}
	return 1;
}

void put_sperate(int len){
	int i;
	for(i=0;i<len;i++)
		printf("---");
	printf("\n");
}

void pintary(int a[],int len){
	int i;
	for(i=0;i<len;i++){
		printf("%+d ",a[i]);
	}
}

int init(int input[],int resault[],int len){
	int i;
	for(i=0;i<len;i++){
		if(input[i]>=0)
			resault[i]=1;
		else if(input[i]<0)
			resault[i]=-1;
	}
	return 0;
}

int main(int argc,char **argv){

	int step=1;
	int i,j;
	int len=*argv[2]-48;
	int a[len],b[len],test[len],re[len],one[len];
	int w[len*len];

	for(i=0;i<len;i++)
		one[i]=0;

	for(i=0;i<len;i++){
		test[i]=*argv[4+i]-48;
		if(test[i]==0)
			test[i]=-1;
	}

	for(i=0;i<len;i++)
		re[i]=test[i];

	for(i=0;i<len;i++)
		printf("%+d ",test[i]);
	putchar('\n');
	putchar('\n');

	for(i=0;i<len;i++)
		a[i]=1;

	for(i=0;i<len;i++)
		b[i]=-1;

	/* init w[][] */
	for(i=0;i<len;i++){
		for(j=0;j<len;j++){
			if(i==j){
				w[i*len+j]=0;
			}
			else{
				w[i*len+j]=a[i]*a[i]+b[j]*b[j];
			}

		}

	}

	if(!strcmp(argv[3],"-asyn")){
		while(!cmp(a,one,len)&&!cmp(b,one,len)&&step<MAX){
			int *tmp;
			tmp=re;
			tmp=calculate1(w,test,tmp,len);
			init(re,one,len);
			for(i=0;i<len;i++){
				for(j=0;j<len;j++){
					printf("%+d ",w[i*len+j]);
				}
				putchar('\n');

			}
			put_sperate(len);
			pintary(re,len);
			printf("    -->step:%d\n",step++);
			put_sperate(len);
			pintary(one,len);
			putchar('\n');
			put_sperate(len);
		}
	}
	else if(!strcmp(argv[3],"-syn")){
		int index=0;
		while(!cmp(a,one,len)&&!cmp(b,one,len)&&step<MAX){

			for(j=0;j<len;j++){
				re[index]+=test[j]*w[index*len+j];
			}
			for(i=0;i<index;i++)
				printf("   ");
			printf(">%d\n",index+1);
			index=(++index)%len; // index~[0,len)
			init(re,one,len);
			init(re,re,len);
			for(i=0;i<len;i++){
				for(j=0;j<len;j++){
					printf("%+d ",w[i*len+j]);
				}
				putchar('\n');

			}
			put_sperate(len);
			pintary(re,len);
			printf("    -->step:%d\n",step++);
			put_sperate(len);
			pintary(one,len);
			putchar('\n');
			put_sperate(len);
		}
	}

	putchar('\n');
	return 0;
}
