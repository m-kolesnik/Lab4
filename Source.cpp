#include<iostream>
#include<thread>

using namespace std;

int** product_arrays(int** array1, int **array2, int rows, int cols);
void min_array(int** array3, int rows, int cols);


int main()
{
	int rows, cols;
	cout << "Enter rows: ";
	cin >> rows;
	cout << endl;
	cout << "Enter cols: ";
	cin >> cols;
	int** array1 = new int*[rows];
	int** array2 = new int*[rows];
	int** array3 = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		array1[i] = new int[cols];
		array2[i] = new int[cols];
		array3[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array1[i][j] = rand() % 10;
			array2[i][j] = rand() % 10;
		}
	}
	array3 = product_arrays(array1, array2, rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << array3[i][j] << " ";
		}
		cout << endl;
	}
	min_array(array3,rows,cols);
	return 0;
}

int** product_arrays(int** array1, int **array2,int rows, int cols)
{
	int **temp;
	temp = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		temp[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			temp[i][j] = array1[i][j] * array2[i][j];
		}
	}
	return temp;
}
void min_array(int **array3,int rows, int cols)
{
	int values = 0;
	string *values2 = new string[2];
	values = array3[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (values > array3[i][j])
			{
				values = array3[i][j];
				values2[0] = "Row: " + i;
				values2[1] = "Col: " + j;
			}
		}
	};
	cout << "Min value: " + values << endl;
	cout << values2[0] << endl;
	cout << values2[1] << endl;
}

