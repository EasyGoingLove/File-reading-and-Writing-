#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char name_of_File[9] = "words.txt";
char arr[100][50];
int Total_words = 0;


struct info
{
	char word[50];
	unsigned char frequency;

};
struct info data[100];

void file_read(void);
void file_save(void);

int main()
{
	file_read();
	file_save();
	int j;
	for (j = 0; j <= Total_words; j++) {
		printf("%s\n", arr[j]);
	}
	int o;
	for (o = 0; o < Total_words; o++)
	{
		if (data[o].frequency != 0)
		{
			printf("%s<-------->%d\n", data[o].word, data[o].frequency);
		}
	}

	printf("\n\nDone, open the file you named for the result.");
	_getch();
}

void file_read(void)
{

	FILE* file;
	file = fopen(name_of_File, "r");
	int check = 0;
	int i = 0;
	while (1)
	{

		char read = (char)fgetc(file);
		int k = 0;
		while (read != ',' && !feof(file) && read != ' ' && read != '\n' && read != '.')
		{
			arr[i][k++] = read;
			read = (char)fgetc(file);
		}
		if (read == '\n')
		{
			check++;
		}
		else
		{
			check = 0;
		}
		if ((read == ' ' || read == '\n') && check < 2)
		{
			Total_words++;
		}
		arr[i][k] = 0;
		if (feof(file))
		{
			break;
		}
		i++;
	}
}

void file_save(void)
{
	int j, v;
	unsigned char repeat_counter = 1;

	for (j = 0; j <= Total_words; j++)
	{
		for (v = j + 1; v <= Total_words; v++)
		{
			if (strcmp(arr[j], arr[v]) == 0)
			{
				repeat_counter++;
			}
		}
		int p;
		int problem = 0;
		for (p = 0; p <= j; p++)
		{
			if (strcmp(arr[j], data[p].word) == 0)
			{
				problem++;
			}
		}
		if (problem == 0)
		{
			data[j].frequency = repeat_counter;
			strcat(data[j].word, arr[j]);
			repeat_counter = 1;
		}
		problem = 0;
	}
	int y;
	FILE* fp;
	char txt_add[5] = ".txt";
	char file_name[30];
	printf("\n\nEnter the name of the file where the result is going to be stored in :");
	scanf("%s", file_name);
	strcat(file_name, txt_add);
	fp = fopen(file_name, "w");
	fprintf(fp, "Word and Frequency .\n");
	for (y = 0; y < Total_words; y++)
	{
		if (data[y].frequency != 0)
		{
			fprintf(fp, "<[%s]> <--> <[%d]>\n", data[y].word, data[y].frequency);
		}
	}
	fclose(fp);
}