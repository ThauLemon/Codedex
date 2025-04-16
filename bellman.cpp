#include"bellman.h"

void BF(int Graph[][20], int num_vertices, char Start, int ValueArr[], int PreviousArr[])
{
	int a = Start - 'A';
	ValueArr[a] = 0;
	int Value[20];
	int Previous[20];


	for (int i = 0; i < num_vertices; i++)
	{
		Value[i] = ValueArr[i];
		Previous[i] = PreviousArr[i];
	}
	for (int i = 0; i < num_vertices; i++)
	{
		for (int j = 0; j < num_vertices; j++)
			if (Graph[j][i] > 0)
			{
				if (Value[i] < 0 && Value[j] >= 0 && ValueArr[i] < 0)
				{
					ValueArr[i] = Value[j] + Graph[j][i];
					PreviousArr[i] = j;
				}
				if (Value[j] >= 0 && Value[j] + Graph[j][i] < ValueArr[i])
				{
					ValueArr[i] = Value[j] + Graph[j][i];
					PreviousArr[i] = j;			
				}

			}

	}
}

void Initial(int ValueArr[], int PreviousArr[], int num_vertices)
{
	for (int i = 0; i < num_vertices; i++)
	{
		ValueArr[i] = -1;
		PreviousArr[i] = -1;
	}
}
string PrintPath(int PreviousArr[], char Start, char End)
{
	char a;
	string str = "";
	int i = End - 'A';
	while (PreviousArr[i] >= 0)
	{
		a = 'A' + i;
		str = str + a + " ";
		i = PreviousArr[i];
	}
	str += Start;
	string reverseString = "";
	for (int i = str.length() - 1; i >= 0; i--)
		reverseString += str[i];
	return reverseString;
}
string BF_Path(int Graph[][20], int num_vertices, char Start, char End)
{
	int ValueArr[30];
	int PreviousArr[30];
	Initial(ValueArr, PreviousArr, num_vertices);

	for (int i = 0; i < num_vertices; i++)
	{
		BF(Graph, num_vertices, Start, ValueArr, PreviousArr);
	}
				
	return PrintPath(PreviousArr, Start, End);

}