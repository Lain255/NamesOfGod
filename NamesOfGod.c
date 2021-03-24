#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//NameOfGodFunc prints every word with given letter length and less
void NameOfGodFunc(int LengthOfGodsName)
{
	//print all words with less letters recursivly
	if(LengthOfGodsName > 1)
		NameOfGodFunc(LengthOfGodsName-1);

	//allocate space for NameOfGod
	char* NameOfGod = malloc(LengthOfGodsName+1);

	//fill NameofGod with 'A's
	for(int i = 0; i < LengthOfGodsName+1; i++)
	{
		NameOfGod[i] = 'A';
	}

	//put '\0' at end so printf knows when to stop reading NameOfGod
	NameOfGod[LengthOfGodsName] = '\0';

	//while first letter of NameOfGod isnt overflown
	while(NameOfGod[0] != 'Z'+1)
	{
		//print NameOfGod
		printf("%s ", NameOfGod);
		
		//increment last letter in NameOfGod
		NameOfGod[LengthOfGodsName-1]++;

		//for each letter in NameOfGod
		//if letter after is overflown, increment letter and reset letter after
		for(int j = 0; j < LengthOfGodsName-1; j++)
		{
			NameOfGod[LengthOfGodsName-2-j] += ((NameOfGod[LengthOfGodsName-1-j] - 'A') / 26);
			NameOfGod[LengthOfGodsName-1-j]  =  (NameOfGod[LengthOfGodsName-1-j] - 'A') % 26 + 'A';
		}
	}
	//free space allocated for NameOfGod
	free(NameOfGod);
	return;
}

//where the program starts
int main()
{
	//call to NameOfGodFunc, printing every 1-7 letter word in english prints about 8.3 billion words
	NameOfGodFunc(7);
	return 0;
}
