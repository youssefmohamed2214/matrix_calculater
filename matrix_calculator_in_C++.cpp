#include<iostream>
#include<string>
#include<vector>
void mode1();
void mode2();
using namespace std;
int main()
{
	int mode;
	cout << "==================matrix calculater==================\n";
	while (true)
	{
		cout << "choose number of mode from the following modes \n";
		cout << "(1) 1st mode for operation on one matrix\n";
		cout << "(2) 2nd mode for operation on two matrix\n";
		cout << "(0) exit program\n";
		cout << "enter number of mode : ";
		cin >> mode;
		if (mode == 1) {
			mode1();
		}
		else if (mode == 2)
		{
			mode2();
		}
		else if (mode == 0)
		{
			exit(0);
		}
		else {
			cout << "error of mode\n";
		}
	}
}
void mode1() {
	cout << "==================operation on one matrix==================\n";
	int choice;
	do
	{
		cout << "choose one of the following operation \n";
		cout << "(1) transpose \n";
		cout << "(2) determinant matrix must be 2x2 or 3x3 \n";
		cout << "(3) inverse with gauss jordan\n";
		cout << "(4) rank matrix must be 2x2 or 3x3 \n";
		cout << "(0) for exit program\n";
		cout << "====> ";
		cin >> choice;
		if (choice == 0) {
			exit(0);
		}
		string dim;
		string s_r_mat, s_c_mat;
		float    r_mat, c_mat;
		int index;
		index = 0;
		cout << "enter dimentions of matrix : ";
		cin >> dim;
		for (int i = 0; i < dim.length(); i++)
		{
			if (dim[i] != 'x' && index == 0) {
				s_r_mat += dim[i];
			}
			if (dim[i] == 'x')
			{
				index++;
				continue;
			}
			if (dim[i] != 'x' && index == 1) {
				s_c_mat += dim[i];
			}
		}
		r_mat = stoi(s_r_mat);
		c_mat = stoi(s_c_mat);
		if (choice == 1) {
			cout << "==================transpose of matrix==================\n";
			//input matrix
			vector<vector<float>> mat;
			vector<vector<float>> result;
			float temp;
			cout << "enter matrix : \n";
			mat.resize(r_mat);
			for (int i = 0; i < r_mat; i++) {
				mat[i].resize(c_mat);
			}
			for (int i = 0; i < r_mat; i++)
			{
				for (int j = 0; j < c_mat; j++)
				{
					cout << "Enter index " << "(" << i + 1 << "," << j + 1 << ")" << " : ";
					cin >> temp;
					mat[i][j] = temp;
					temp = 0;
				}
			}
			result.resize(c_mat);
			for (int i = 0; i < c_mat; i++) {
				result[i].resize(r_mat);
			}
			//transpose of matrix
			for (int i = 0; i < r_mat; i++)
			{
				for (int j = 0; j < c_mat; j++)
				{
					result[j][i] = mat[i][j];
				}
			}
			//print mat one
			cout << "mat : " << "\n";
			for (int i = 0; i < r_mat; i++)
			{
				cout << "|";
				for (int j = 0; j < c_mat; j++)
				{
					cout << mat[i][j] << " ";
				}
				cout << "|" << "\n";
			}
			//print result matrix
			cout << "result : " << "\n";
			for (int i = 0; i < c_mat; i++)
			{
				cout << "|";
				for (int j = 0; j < r_mat; j++)
				{
					cout << result[i][j] << " ";
				}
				cout << "|" << "\n";
			}
		}
		else if (choice == 2) {
			cout << "==================determinant of matrix==================\n";
			if (r_mat == 2 && c_mat == 2)
			{
				vector<vector<float>> mat;
				float temp;
				float result = 0;
				cout << "enter matrix : \n";
				mat.resize(r_mat);
				for (int i = 0; i < r_mat; i++) {
					mat[i].resize(c_mat);
				}
				for (int i = 0; i < r_mat; i++)
				{
					for (int j = 0; j < c_mat; j++)
					{
						cout << "Enter index " << "(" << i + 1 << "," << j + 1 << ")" << " : ";
						cin >> temp;
						mat[i][j] = temp;
						temp = 0;
					}
				}
				cout << "mat : " << "\n";
				result = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
				cout << "|" << mat[0][0] << " " << mat[0][1] << "|\n";
				cout << "|" << mat[1][0] << " " << mat[1][1] << "|" << "\nresult = " << result << "\n";
			}
			else if (r_mat == 3 && c_mat == 3) {
				vector<vector<float>> mat;
				float temp;
				float result = 0;
				cout << "enter matrix : \n";
				mat.resize(r_mat);
				for (int i = 0; i < r_mat; i++) {
					mat[i].resize(c_mat);
				}
				for (int i = 0; i < r_mat; i++)
				{
					for (int j = 0; j < c_mat; j++)
					{
						cout << "Enter index " << "(" << i + 1 << "," << j + 1 << ")" << " : ";
						cin >> temp;
						mat[i][j] = temp;
						temp = 0;
					}
				}
				cout << "mat : " << "\n";
				for (int i = 0; i < r_mat; i++)
				{
					cout << "|";
					for (int j = 0; j < c_mat; j++)
					{
						cout << mat[i][j] << " ";
					}
					cout << "|" << "\n";
				}

				result = mat[0][0] * ((mat[1][1] * mat[2][2]) - (mat[1][2] * mat[2][1])) - mat[0][1] * ((mat[1][0] * mat[2][2]) - (mat[1][2] * mat[2][0])) + mat[0][2] * ((mat[1][0] * mat[2][1]) - (mat[1][1] * mat[2][0]));
				cout << "result = " << result << "\n";
			}
			else {
				cout << "error dimention \n";
				cout << "dimention must be 2x2 or 3x3\n";
			}
		}
		else if (choice == 3) {
			//guass-jordon
			cout << "==================inverse with guass-jordan==================\n";
			if (r_mat == c_mat)
			{
				float tmp;
				float result = 0;
				vector<vector<float>> mat;
				vector<vector<float>> I;
				//resize of matrix
				I.resize(r_mat);
				for (int i = 0; i < r_mat; i++)
				{
					I[i].resize(r_mat);
				}
				mat.resize(r_mat);
				for (int i = 0; i < r_mat; i++)
				{
					mat[i].resize(c_mat);
				}
				// input matrix 
				cout << "enter matrix : \n";
				for (int i = 0; i < r_mat; i++)
				{
					for (int j = 0; j < c_mat; j++)
					{
						cout << "Enter index " << "(" << i + 1 << "," << j + 1 << ")" << " : ";
						cin >> tmp;
						mat[i][j] = tmp;
						tmp = 0;
					}

				}
				// matrix I
				for (int i = 0; i < r_mat; i++)
				{
					for (int j = 0; j < c_mat; j++)
					{
						if (i == j) {
							I[i][j] = 1;
							continue;
						}
						I[i][j] = 0;
					}
				}
				//output matrix
				cout << "entered matrix" << "\n";
				for (int i = 0; i < r_mat; i++)
				{
					cout << "|";
					for (int j = 0; j < c_mat; j++)
					{
						cout << mat[i][j] << " ";
					}
					cout << "|";
					for (int k = 0; k < c_mat; k++)
					{
						cout << I[i][k] << " ";
					}
					cout << "|" << "\n";
				}
				//guass-jordan 
				float temp = 0;
				float temp1 = 0;
				float temp2 = 0;
				float I_temp1 = 0;
				float I_temp2 = 0;
				for (int i = 0; i < r_mat; i++)
				{
					for (int j = 0; j < c_mat; j++)
					{

						if (mat[i][j] == 0 && i == j)
						{
							for (int k = 0; (k < r_mat) && (mat[i][i] == 0); k++)
							{
								for (int n = 0; n < c_mat; n++)
								{
									//swap of two row of matrix
									temp1 = mat[i][n];
									temp2 = mat[k][n];
									mat[i][n] = temp2;
									mat[k][n] = temp1;
									//swap of two row of I
									I_temp1 = I[i][n];
									I_temp2 = I[k][n];
									I[i][n] = I_temp2;
									I[k][n] = I_temp1;
								}
							}
						}
					}
				}
				//adding of two rows to avoid zero in main diagonal
				for (int i = 0; i < r_mat; i++)
				{
					for (int j = 0; j < c_mat; j++)
					{

						if (mat[i][j] == 0 && i == j)
						{
							for (int k = 0; (k < r_mat) && (mat[i][i] == 0); k++)
							{
								for (int n = 0; n < c_mat; n++)
								{
									mat[i][n] = mat[k][n] + mat[i][n];
								}
							}
						}
					}
				}
				for (int i = 0; i < r_mat; ++i) {
					float pivot = mat[i][i];
					// Make the diagonal element 1
					for (int j = 0; j < r_mat; ++j) {
						mat[i][j] /= pivot;
						I[i][j] /= pivot;
					}
					// Eliminate other elements in the column
					for (int k = 0; k < r_mat; ++k) {
						if (k != i) {
							float factor = mat[k][i];
							for (int l = 0; l < r_mat; ++l) {
								mat[k][l] = mat[k][l] - (factor * mat[i][l]);
								I[k][l] = I[k][l] - (factor * I[i][l]);
							}
						}
					}
				}
				//output result
				cout << "result\n";
				for (int i = 0; i < r_mat; i++)
				{
					cout << "|";
					for (int k = 0; k < c_mat; k++)
					{
						cout << I[i][k] << " ";
					}
					cout << "|" << "\n";
				}
			}
			else
			{
				cout << "dimension error\n";
				cout << "matrix must be square matrix\n";
			}


		}
		else if (choice == 4) {
			cout << "==================rank of matrix==================\n";
			if (r_mat == 2 && c_mat == 2)
			{
				vector<vector<float>> mat;
				float temp;
				float temp1 = 0;
				float temp2 = 0;
				int check;
				float result = 0;
				cout << "enter matrix : \n";
				mat.resize(r_mat);
				for (int i = 0; i < r_mat; i++) {
					mat[i].resize(c_mat);
				}
				for (int i = 0; i < r_mat; i++)
				{
					for (int j = 0; j < c_mat; j++)
					{
						cout << "Enter index " << "(" << i + 1 << "," << j + 1 << ")" << " : ";
						cin >> temp;
						mat[i][j] = temp;
						temp = 0;
					}
				}
				result = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
				if (result == 0)
				{
					for (int i = 0; i < 2; i++)
					{
						for (int j = 0; j < 2; j++)
						{
							if (mat[i][j] != 0)
							{
								check = 1;
								break;
							}
							else {
								check = 0;
							}
						}
					}
				}
				else {
					check = 2;
				}
				cout << "rank equal : " << check << "\n";
			}
			else if (r_mat == 3 && c_mat == 3) {
				vector<vector<float>> mat;
				float temp;
				int check;
				float result = 0;
				float temp1, temp2, temp3, temp4, temp5, temp6;
				cout << "enter matrix : \n";
				mat.resize(r_mat);
				for (int i = 0; i < r_mat; i++) {
					mat[i].resize(c_mat);
				}
				for (int i = 0; i < r_mat; i++)
				{
					for (int j = 0; j < c_mat; j++)
					{
						cout << "Enter index " << "(" << i + 1 << "," << j + 1 << ")" << " : ";
						cin >> temp;
						mat[i][j] = temp;
						temp = 0;
					}
				}
				cout << "mat : " << "\n";
				for (int i = 0; i < r_mat; i++)
				{
					cout << "|";
					for (int j = 0; j < c_mat; j++)
					{
						cout << mat[i][j] << " ";
					}
					cout << "|" << "\n";
				}
				result = mat[0][0] * ((mat[1][1] * mat[2][2]) - (mat[1][2] * mat[2][1])) - mat[0][1] * ((mat[1][0] * mat[2][2]) - (mat[1][2] * mat[2][0])) + mat[0][2] * ((mat[1][0] * mat[2][1]) - (mat[1][1] * mat[2][0]));
				temp1 = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
				temp2 = (mat[0][1] * mat[1][2]) - (mat[0][2] * mat[1][1]);
				temp3 = (mat[0][0] * mat[1][2]) - (mat[0][2] * mat[1][0]);
				temp4 = (mat[1][0] * mat[2][1]) - (mat[1][1] * mat[2][0]);
				temp5 = (mat[1][1] * mat[2][2]) - (mat[1][2] * mat[2][1]);
				temp6 = (mat[1][0] * mat[2][2]) - (mat[1][2] * mat[2][0]);
				if (result == 0)
				{
					if (temp1 != 0 || temp2 != 0 || temp3 != 0 || temp4 != 0 || temp5 != 0 || temp6 != 0) {
						check = 2;
					}
					else {
						for (int i = 0; i < 3; i++) {
							for (int j = 0; j < 3; j++)
							{
								if (mat[i][j] != 0) {
									check = 1;
									i = 4;
									j = 8;
									break;
								}
								else {
									check = 0;
								}
							}
						}
					}
				}
				else {
					check = 3;
				}
				cout << "rank equal : " << check << "\n";
			}
			else {
				cout << "matrix must be 2x2 or 3x3 \n";
			}
		}
		else {
			cout << "unsigned choice\n";
			cout << "please enter choice from the following\n";
		}
	} while (true);
}
void mode2() {
	cout << "==================operation on two matrix==================\n";
	int choice;
	do
	{
		cout << "enter number of operation from the following :\n";
		cout << "(1) for addition of two matrix \n";
		cout << "(2) for subtraction of two matrix \n";
		cout << "(3) for multiply of two matrix \n";
		cout << "(0) exit program \n";
		cout << "====> ";
		cin >> choice;
		if (choice == 0) {
			exit(0);
		}
		string dim1, dim2;
		string s_r_mat1, s_c_mat1, s_r_mat2, s_c_mat2;
		float    r_mat1, c_mat1, r_mat2, c_mat2;
		int index;
		index = 0;
		cout << "enter dimentions of 1st matrix : ";
		cin >> dim1;
		cout << "enter dimentions of 2nd matrix : ";
		cin >> dim2;
		for (int i = 0; i < dim1.length(); i++)
		{
			if (dim1[i] != 'x' && index == 0) {
				s_r_mat1 += dim1[i];
			}
			if (dim1[i] == 'x')
			{
				index++;
				continue;
			}
			if (dim1[i] != 'x' && index == 1) {
				s_c_mat1 += dim1[i];
			}
		}
		index = 0;
		for (int i = 0; i < dim2.length(); i++)
		{
			if (dim2[i] != 'x' && index == 0) {
				s_r_mat2 += dim2[i];
			}
			if (dim2[i] == 'x')
			{
				index++;
				continue;
			}
			if (dim2[i] != 'x' && index == 1) {
				s_c_mat2 += dim2[i];
			}
		}
		r_mat1 = stoi(s_r_mat1);
		c_mat1 = stoi(s_c_mat1);
		r_mat2 = stoi(s_r_mat2);
		c_mat2 = stoi(s_c_mat2);
		if (choice == 1)
		{
			cout << "==================addition of two matrix==================\n";
			if (r_mat1 == r_mat2 && c_mat1 == c_mat2)
			{
				//input mat1
				vector<vector<float>> mat1;
				vector<vector<float>> mat2;
				vector<vector<float>> result;
				float temp1;
				cout << "enter matrix 1 : \n";
				mat1.resize(r_mat1);
				for (int i = 0; i < r_mat1; i++) {
					mat1[i].resize(c_mat1);
				}
				for (int i = 0; i < r_mat1; i++)
				{
					for (int j = 0; j < c_mat1; j++)
					{
						cout << "Enter index " << "(" << i + 1 << "," << j + 1 << ")" << " : ";
						cin >> temp1;
						mat1[i][j] = temp1;
						temp1 = 0;
					}
				}
				//input mat2
				float temp2;
				cout << "enter matrix 2 : \n";
				mat2.resize(r_mat2);
				for (int i = 0; i < r_mat2; i++) {
					mat2[i].resize(c_mat2);
				}
				for (int i = 0; i < r_mat2; i++)
				{
					for (int j = 0; j < c_mat2; j++)
					{
						cout << "Enter index " << "(" << i + 1 << "," << j + 1 << ")" << " : ";
						cin >> temp2;
						mat2[i][j] = temp2;
						temp2 = 0;
					}
				}
				result.resize(r_mat1);
				for (int i = 0; i < r_mat1; i++) {
					result[i].resize(c_mat1);
				}
				//adding operation
				for (int i = 0; i < r_mat1; i++)
				{
					for (int j = 0; j < c_mat1; j++)
					{
						result[i][j] = mat1[i][j] + mat2[i][j];
					}
				}
				//print mat1 matrix
				cout << "mat1 : " << "\n";
				for (int i = 0; i < r_mat1; i++)
				{
					cout << "|";
					for (int j = 0; j < c_mat1; j++)
					{
						cout << mat1[i][j] << " ";
					}
					cout << "|" << "\n";
				}
				cout << " + \n";
				//print mat2 matrix
				cout << "mat2 : " << "\n";
				for (int i = 0; i < r_mat2; i++)
				{
					cout << "|";
					for (int j = 0; j < c_mat2; j++)
					{
						cout << mat2[i][j] << " ";
					}
					cout << "|" << "\n";
				}
				//print result matrix
				cout << "result : " << "\n";
				for (int i = 0; i < r_mat1; i++)
				{
					cout << "|";
					for (int j = 0; j < c_mat1; j++)
					{
						cout << result[i][j] << " ";
					}
					cout << "|" << "\n";
				}
			}
			else {
				cout << "can not exit \n";
			}
		}
		else if (choice == 2)
		{
			cout << "==================subtraction of two matrix==================\n";
			if (r_mat1 == r_mat2 && c_mat1 == c_mat2)
			{
				//input mat1
				vector<vector<float>> mat1;
				vector<vector<float>> mat2;
				vector<vector<float>> result;
				float temp1;
				cout << "enter matrix 1 : \n";
				mat1.resize(r_mat1);
				for (int i = 0; i < r_mat1; i++) {
					mat1[i].resize(c_mat1);
				}
				for (int i = 0; i < r_mat1; i++)
				{
					for (int j = 0; j < c_mat1; j++)
					{
						cout << "Enter index " << "(" << i + 1 << "," << j + 1 << ")" << " : ";
						cin >> temp1;
						mat1[i][j] = temp1;
						temp1 = 0;
					}
				}
				//input mat2
				float temp2;
				cout << "enter matrix 2 : \n";
				mat2.resize(r_mat2);
				for (int i = 0; i < r_mat2; i++) {
					mat2[i].resize(c_mat2);
				}
				for (int i = 0; i < r_mat2; i++)
				{
					for (int j = 0; j < c_mat2; j++)
					{
						cout << "Enter index " << "(" << i + 1 << "," << j + 1 << ")" << " : ";
						cin >> temp2;
						mat2[i][j] = temp2;
						temp2 = 0;
					}
				}
				result.resize(r_mat1);
				for (int i = 0; i < r_mat1; i++) {
					result[i].resize(c_mat1);
				}
				//subtraction operation
				for (int i = 0; i < r_mat1; i++)
				{
					for (int j = 0; j < c_mat1; j++)
					{
						result[i][j] = mat1[i][j] - mat2[i][j];
					}
				}
				//print mat1 matrix
				cout << "mat1 : " << "\n";
				for (int i = 0; i < r_mat1; i++)
				{
					cout << "|";
					for (int j = 0; j < c_mat1; j++)
					{
						cout << mat1[i][j] << " ";
					}
					cout << "|" << "\n";
				}
				cout << " - \n";
				//print mat2 matrix
				cout << "mat2 : " << "\n";
				for (int i = 0; i < r_mat2; i++)
				{
					cout << "|";
					for (int j = 0; j < c_mat2; j++)
					{
						cout << mat2[i][j] << " ";
					}
					cout << "|" << "\n";
				}
				//print result matrix
				cout << "result : " << "\n";
				for (int i = 0; i < r_mat1; i++)
				{
					cout << "|";
					for (int j = 0; j < c_mat1; j++)
					{
						cout << result[i][j] << " ";
					}
					cout << "|" << "\n";
				}
			}
			else {
				cout << "can not exit \n";
			}
		}
		else if (choice == 3) {
			cout << "==================multiplication of two matrix==================\n";
			//check
			if (c_mat1 == r_mat2)
			{
				//input mat1
				vector<vector<float>> mat1;
				vector<vector<float>> mat2;
				vector<vector<float>> result;
				float temp1;
				cout << "enter matrix 1 : \n";
				mat1.resize(r_mat1);
				for (int i = 0; i < r_mat1; i++) {
					mat1[i].resize(c_mat1);
				}
				for (int i = 0; i < r_mat1; i++)
				{
					for (int j = 0; j < c_mat1; j++)
					{
						cout << "Enter index " << "(" << i + 1 << "," << j + 1 << ")" << " : ";
						cin >> temp1;
						mat1[i][j] = temp1;
						temp1 = 0;
					}
				}
				//input mat2
				float temp2;
				cout << "enter matrix 2 : \n";
				mat2.resize(r_mat2);
				for (int i = 0; i < r_mat2; i++) {
					mat2[i].resize(c_mat2);
				}
				for (int i = 0; i < r_mat2; i++)
				{
					for (int j = 0; j < c_mat2; j++)
					{
						cout << "Enter index " << "(" << i + 1 << "," << j + 1 << ")" << " : ";
						cin >> temp2;
						mat2[i][j] = temp2;
						temp2 = 0;
					}
				}
				result.resize(r_mat1);
				for (int i = 0; i < r_mat1; i++) {
					result[i].resize(c_mat2);
				}
				//multiplication
				for (int i = 0; i < r_mat1; ++i) {
					for (int j = 0; j < c_mat2; ++j) {
						for (int k = 0; k < c_mat1; ++k)
						{
							result[i][j] += mat1[i][k] * mat2[k][j];
						}
					}
				}
				//print mat1 matrix
				cout << "mat1 : " << "\n";
				for (int i = 0; i < r_mat1; i++)
				{
					cout << "|";
					for (int j = 0; j < c_mat1; j++)
					{
						cout << mat1[i][j] << " ";
					}
					cout << "|" << "\n";
				}
				cout << "x\n";
				//print mat2 matrix
				cout << "mat2 : " << "\n";
				for (int i = 0; i < r_mat2; i++)
				{
					cout << "|";
					for (int j = 0; j < c_mat2; j++)
					{
						cout << mat2[i][j] << " ";
					}
					cout << "|" << "\n";
				}
				//print result matrix
				cout << "result : " << "\n";
				for (int i = 0; i < r_mat1; i++)
				{
					cout << "|";
					for (int j = 0; j < c_mat2; j++)
					{
						cout << result[i][j] << " ";
					}
					cout << "|" << "\n";
				}
			}
			else {
				cout << "can not exit \n";
			}
		}
		else {
			cout << "unsigned choice\n";
			cout << "please enter choice from the following\n";
		}
	} while (true);
}