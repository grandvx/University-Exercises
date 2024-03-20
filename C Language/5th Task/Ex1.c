#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		//Checks if the correct number of command-line arguments is provided (1st bullet)
		printf("Invalid number of parameters\n");
		return 1;
	}
	
	//Opens the input file
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Cannot read input file\n"); //(2nd bullet)
		return 1;
	}
	
	//Reads words from the file and store them in a dynamically allocated array
	int num_words = 0;
	char **words = NULL;
	char word[100];
	int line_num = 1;
	
	while (fscanf(fp, "%s\n", word) == 1)
	{
		//Validates that each character in the word of the input file is an uppercase letter(3rd bullet)
		for (int i = 0; word[i]++; i++)
		{
			if (word[i] < 'A' || word[i] > 'Z')
			{
				printf("Invalid Data in Line %07d\n", line_num);
				fclose(fp);
				
				for (int j = 0; j < num_words; j++)
				{
					free(words[j]);
				}
				free(words);
				return 1;
			}
		}
		
		//Increases the word count and reallocates memory for the words array
		num_words++;
		words = realloc(words, num_words * sizeof(char *));
		if (words == NULL)
		{
			printf("Memory Problem\n"); //(6th bullet)
			fclose(fp);
			
			for (int j = 0; j < num_words - 1; j++)
			{
				free(words[j]);
			}
			free(words);
			return 1;
		}
		words[num_words - 1] = strdup(word);
		if (words[num_words - 1] == NULL)
		{
			printf("Memory Problem\n");
			fclose(fp);
			
			for (int j = 0l; j < num_words - 1; j++)
			{
				free(words[j]);
			}
			free(words);
			return 1;
		}
		line_num++;
	}
	
	fclose(fp);
	
	//Calculates letter frequencies(4th bullet)
	int letter_counts[26] = {0};
	for (int i = 0; i < num_words; i++)
	{
		for (int j = 0; words[i][j]; j++)
		{
			letter_counts[words[i][j] - 'A']++;
		}
	}
	
	//Sorts letters by frequency in descending order
	for (int i = 0; i < 26; i++)
	{
		for (int j = i + 1; j < 26; j++)
		{
			if (letter_counts[i] < letter_counts[j])
			{
				int temp = letter_counts[i];
				letter_counts[i] = letter_counts[j];
				letter_counts[j] = temp;

				char *temp_word = words[i];
				words[i] = words[j];
				words[j] = temp_word;
			}
		}
	}
	
	
	//Prints letter frequencies
	for (int i = 0; i < 26; i++)
	{
		if (letter_counts[i] > 0)
		{
			printf("%c %07d\n", 'A' + i, letter_counts[i]);
		}
	}
	
	//Prints combinations of top 5 letters//(5th bullet)
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			printf("%c%c\n", 'A' + i, 'A' + j);
		}
	}
	
	for (int i = 0; i < num_words; i++)
	{
		free(words[i]);
	}
	free(words);
	
	getchar();
	
	return 0;
}
