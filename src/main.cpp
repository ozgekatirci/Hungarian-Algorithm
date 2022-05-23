#include<iostream>
#include<stdio.h>
#include<time.h>
#define SIZE 7

using namespace std;
void main()
{
	srand(time(NULL));
	int i, j, k, A[SIZE][SIZE], O[SIZE][SIZE], B[SIZE][SIZE], minr, minc, rcount = 0, ccount = 0, a = 0, rkey[20], count, result = 0, flag = 0, min, flagx = 0, flagy = 0, control = 0, value = 0, temp=0;
	int y = 0,T[SIZE][SIZE];
	int  row[100],rcarpý[100],ccarpý[100];
	cout << "ORIGINAL MATRIX" << endl << "---------------------" << endl;

//If you want to enter the matrices manually, this part should be uncomment and the 
//for loop section below should be comment and the size of the matrix can be 
//adjusted using the SIZE variable.

	//for ( i = 0; i < SIZE; i++)
	//{
	//	for ( j = 0; j < SIZE; j++)
	//	{
	//		cin >> A[i][j];
	//		O[i][j] = A[i][j];
	//	}
	//	cout << endl;
	//}

	for ( i = 0; i <SIZE; i++)
	{
		for ( j = 0; j < SIZE; j++)
		{
			A[i][j] = rand() % 101;
			O[i][j] = A[i][j];
			cout << O[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	for ( i = 0; i < SIZE; i++)
	{
		minr = A[i][0];
		for ( j = 0; j < SIZE; j++)
		{
			if (A[i][j] < minr)
			{
				 minr=A[i][j];
			}
		}
		cout <<"Min Row-"<<i<<":" << minr << endl;
		for ( k = 0; k <SIZE; k++)
		{
			A[i][k] = A[i][k]- minr;
		}
	}
	cout <<endl<< "Matrix after row substract" <<endl<< "------------------------------" << endl;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	for (j= 0; j < SIZE; j++)
	{
		minc = A[0][j];
		for (i = 0; i< SIZE; i++)
		{
			if (A[i][j] < minc)
			{
				 minc=A[i][j];
			}	
		}
		cout << "Min Column-"<<j<<":"<< minc << endl;
		for (k = 0; k < SIZE; k++)
		{
			A[k][j] = A[k][j]- minc;
		}
	}
	cout <<endl<< "Matrix after column substract"<< endl<<"------------------------------"<<endl;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			B[i][j] = A[i][j];
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	while (1)
	{
		for (i = 0; i < SIZE; i++)
		{
			for (j = 0; j < SIZE; j++)
			{
				T[i][j] = B[i][j];
			}
		}
		a = 0;
		for (i = 0; i < SIZE; i++)
		{
			for (j = 0; j < SIZE; j++)
			{
				if (T[i][j] == 0) {
					for (int n = 0; n < SIZE; n++)
					{
						if (T[i][n] == 0) {
							rcount++;
						}
					}
					for (k = 0; k < SIZE; k++)
					{
						if (T[k][j] == 0) {
							ccount++;
						}
					}
					if (rcount == 1) {
						row[a++] = i;
						for (k = 0; k < SIZE; k++)
						{
							T[k][j] = -1;
						}
						for (k = 0; k < SIZE; k++)
						{
							T[i][k] = -1;
						}
					}
					if (rcount > 1 && ccount == 1) {
						row[a++] = i;
						for (k = 0; k < SIZE; k++)
						{
							T[k][j] = -1;
						}
						for (k = 0; k < SIZE; k++)
						{
							T[i][k] = -1;
						}
					}
					rcount = 0;
					ccount = 0;
				}
			}
		}
		int temp2 = 0;
		while (1) {
			temp2 = 0;
			for (i = 0; i < SIZE; i++)
			{
				for (j = 0; j < SIZE; j++)
				{
					if (T[i][j] == 0) {
						temp2 = 1;
						for (int n = 0; n < SIZE; n++)
						{
							if (T[i][n] == 0) {
								rcount++;
							}
						}
						for (k = 0; k < SIZE; k++)
						{
							if (T[k][j] == 0) {
								ccount++;
							}
						}
						if (rcount == 1) {
							row[a++] = i;
							for (k = 0; k < SIZE; k++)
							{
								T[k][j] = -1;
							}
							for (k = 0; k < SIZE; k++)
							{
								T[i][k] = -1;
							}
						}
						if (rcount > 1 && ccount <= 1) {
							row[a++] = i;
							for (k = 0; k < SIZE; k++)
							{
								T[k][j] = -1;
							}
							for (k = 0; k < SIZE; k++)
							{
								T[i][k] = -1;
							}
						}
						if (rcount > 1 && ccount > 1)
						{
							row[a++] = i;
							for (k = 0; k < SIZE; k++)
							{
								T[k][j] = -1;
							}
							for (k = 0; k < SIZE; k++)
							{
								T[i][k] = -1;
							}
						}
						rcount = 0;
						ccount = 0;
					}
				}
			}
			if (temp2 == 0)
			{
				break;
			}
		}
		int m = 0;
		int n = 0;
		int flag1 = 0;
		for (i = 0; i < SIZE; i++)
		{
			flag1 = 0;
			for (j = 0; j < SIZE; j++)
			{
				for (k = 0; k < a; k++)
				{
					if (i == row[k])
					{
						flag1 = 1;
					}
				}
			}
			if (flag1 == 0) {
				rcarpý[m++] = i;
			}
			flag1 = 0;
		}
		for (i = 0; i < SIZE; i++)
		{
			for (j = 0; j < SIZE; j++)
			{
				for (k = 0; k < m; k++)
				{
				  if (rcarpý[k] == i) {
					if (B[i][j] == 0) {
						ccarpý[n++] = j;
						for (int p = 0; p < n - 1; p++) {

							if (j == ccarpý[p])
							{
								n--;
							}
						}
					}
				  }
			    }
			}
		}
		int flagc = 0;
		int flagt = 0;
		for (i = 0; i < SIZE; i++)
		{
			for (j = 0; j < SIZE; j++)
			{

				for (k = 0; k < a; k++)
				{
					if (B[i][j] == 0) {

						if (i == row[k])
						{
							for ( int t = 0;  t< n; t++)
							{
								if (ccarpý[t] == j)
								{
									flagc = 1;
								}
							}
						}
					}
				}
			}
			if (flagc == 1) {

				for (int p = 0; p < m; p++)
				{
					if (rcarpý[p] != i) {
						flagt = 1;
					}
				}
			}
			if (flagt== 1) {
				rcarpý[m++] = i;
			}
			flagt = 0;
			flagc = 0;
		}
		int p = 0;
		int flaga = 0;
		
		for ( i = 0; i <SIZE ; i++)
		{
			for ( j = 0; j <m; j++)
			{
				if (i == rcarpý[j])
				{
					flaga = 1;
				}
			}
			if (flaga == 0) {
				rkey[p++] = i;
			}
			flaga = 0;
		}
		count = p +n;
		for (i = 0; i < SIZE; i++)
		{
			flagt = 0;
			for (j = 0; j < SIZE; j++)
			{
				for (k = 0; k < n; k++)
				{
					if (j == ccarpý[k]) {
						B[i][j] = -1;
					}
				}
				for (int t = 0; t < p; t++)
				{
					if (i == rkey[t]) {
						B[i][j] = -1;
					}
				}
			}
		}
		cout << endl;
		cout << "Lines:" << "\t";
		for ( j = 0; j < p; j++)
		{
			cout << "Row-" << rkey[j] << "\t";
		}
		for ( i = 0; i < n; i++)
		{
			cout << "Col-" << ccarpý[i] << "\t";
		}
		cout <<endl<< "Number Of Lines :" << count << endl;
			if (count == SIZE)
			{
				do {
					for (i = 0; i < SIZE; i++)
					{
						for (j = 0; j < SIZE; j++)
						{
							if (A[i][j] == 0)
							{
								for (k = 0; k < SIZE; k++)
								{
									if (A[k][j] == 0)
										flagx++;
								}
								for (int n = 0; n < SIZE; n++)
								{
									if (A[i][n] == 0)
										flagy++;
								}
								if (flagx == 1 && flagy == 1) {
									result += O[i][j];
									control = 1;
									value++;
								}
								if (flagx == 1 && flagy > 1)
								{
									result += O[i][j];
									control = 1;
									value++;
								}
								if (flagx > 1 && flagy == 1)
								{
									result += O[i][j];
									control = 1;
									value++;
								}
								if (control == 1)
								{
									temp++;
									for (int m = 0; m < SIZE; m++)
									{
										A[m][j] = -1;

									}
									for (int n = 0; n < SIZE; n++)
									{
										A[i][n] = -1;
									}
								}
								control = 0;
								flagx = 0;
								flagy = 0;
							}
							int p;
						}
					}
					int temp1 = 0;
					if (temp == 0)
					{
						for (k = 0; k < SIZE; k++)
						{
							for (p = 0; p < SIZE; p++)
							{
								if (A[k][p] == 0){
							
									result += O[k][p];
									value++;
									temp1 = 0;
									for (int m = 0; m < SIZE; m++)
									{
										A[m][p] = -1;
									}
									for (int n = 0; n < SIZE; n++)
									{
										A[k][n] = -1;
									}
									
									temp1 = 1;
									break;
								}
							}
							if (temp1 == 1)
							{
								break;
							}
						}
					}
					temp = 0;
					y = 0;
					for (int p = 0; p < SIZE; p++)
					{
						for (int v = 0; v < SIZE; v++)
						{
							if (A[p][v] == 0) {
								y = 1;
							}
						}
					}
					if (y == 0)
					{
						break;
					}
					temp = 0;
					
				} while (1);
				cout << endl<<" RESULT:" << result << endl;
			    break;
			}
			else {
				min = 101;
				for (i = 0; i < SIZE; i++)
				{
					for (int j = 0; j < SIZE; j++)
					{
						if (B[i][j] > 0)
						{
							if (B[i][j] < min)
							{
								min = B[i][j];
							}
						}
					}
				}
				cout << endl << "min:" << min<<endl;
				flag = 0;
				for ( i = 0; i < SIZE; i++)
				{
					for ( j = 0; j <SIZE ; j++)
					{
						if (B[i][j] > 0)
						{
							A[i][j] = A[i][j] - min;
						}
					}
				}
				for ( i = 0; i < SIZE; i++)
				{
					for ( j = 0; j < SIZE; j++)
					{
						if (B[i][j] == -1)
						{
							for (int k = 0; k <p; k++) {
								if (rkey[k] == i) {
									for (int t= 0; t <n ; t++)
									{
										if (ccarpý[n] == j) {
											A[i][j] += min;
										}
									}
								}
							}
						}
					}
				}
				cout << endl;
				cout << "Matrix after process" << endl << "------------------------------" << endl;
				for (i = 0; i < SIZE; i++)
				{
					for (j = 0; j < SIZE; j++)
					{
						B[i][j] = A[i][j];
						cout << A[i][j] << "\t";
					}
					cout << endl;
				}
				flag = 0;
				cout << endl;
			}
	}//end while
	cout << endl << endl;
	system("pause");
}