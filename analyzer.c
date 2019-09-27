#include<stdio.h>


int main()
{
	char fname[100] = "time.log";
	FILE* fp;
	int min, sec, time, max = 0, mean, sum = 0, number_of_file = 0;

	fp = fopen(fname, "r");
	
	if (fp == NULL) {
		printf("Failed to open file\n");
		return 0;
	}

	while(!feof(fp)) {
		fscanf(fp, "(%d:%d)\n", &min, &sec);
		printf("min = %d, sec = %d\n", min, sec);
		
		time =(min * 60) + sec;
		if(time > max)
			max = time;
		sum += time;
		number_of_file += 1;
		// get min, max, avg access time 
	}
	 mean = sum / number_of_file;
	 printf("최대 접속시간:%d분 %d초",max / 60,max % 60);
	 printf("평균 접속시간:%d분 %d초",mean / 60,mean % 60);
	return 0;
}

