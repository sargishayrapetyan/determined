#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

vector<vector<int> > helper(const vector<vector<int>>& V,
							unsigned i, unsigned j)
{
	unsigned row = 0;
	unsigned col = 0;
	const size_t size = V[1].size();
	vector<vector<int> > V1(size - 1, vector<int>(size -1));
	for (unsigned k = 0; k < size; ++k) {
		if (i == k) {
			continue;
		}
		for (unsigned h = 0; h < size; ++h) {
			if (j == h) {
				continue;
			}
			V1[row][col] = V[k][h];
			++col;
		}
		++row;
		col = 0;
	}
	return V1;
}

double determinant(const vector<vector<int>>& A)
{
	double det = 0;
	const unsigned size = A.size();
	if (size == 2) {
		 det = A[0][0]*A[1][1] - A[0][1]*A[1][0];
	} else{
		for(unsigned i = 0; i < size; ++i) {
			vector<vector<int> > temp_matr = helper(A, 0, i);
			det += pow(-1, i) * determinant(temp_matr) * A[0][i];
		}
	}
	return det;
}

bool is_positive_determined(const vector<vector<int> >& v)
{
	int row = 0;
	int col = 0;
	const size_t size = v[1].size();
	vector<vector<int> > v1(size- 1, vector<int>(size - 1));
	if (size == 2) {
		return (((v[0][0] * v[1][1]) - (v[0][1] * v[1][0])) > 0);
	}
	for(unsigned i = 0; i < size - 1; ++i){
		for(unsigned j = 0; j < size - 1; ++j){
			v1[row][col] = v[i][j];
			++col;
		}
		++row;
		col = 0;
	}

	for(unsigned i = 0; i < size - 1; ++i){
		for(unsigned j = 0; j < size - 1; ++j){
			cout << v1[i][j] << " ";
		}
		cout << endl ;
	}
	int det = determinant(v1);
	cout << det << endl;
	if(det <= 0) {
		return false;
	}
	return is_positive_determined(v1);
}

bool is_positive_halfdetermined(const vector<vector<int> >& v)
{	
	int row = 0;
	int col = 0;
	const size_t size = v[1].size();
	vector<vector<int> > v1(size- 1, vector<int>(size - 1));
	if (size == 2) {
		return (((v[0][0] * v[1][1]) - (v[0][1] * v[1][0])) > 0);
	}
	for(unsigned i = 0; i < size - 1; ++i){
		for(unsigned j = 0; j < size - 1; ++j){
			v1[row][col] = v[i][j];
			++col;
		}
		++row;
		col = 0;
	}
	for(unsigned i = 0; i < size - 1; ++i){
		for(unsigned j = 0; j < size - 1; ++j){
			cout << v1[i][j] << " ";
		}
		cout << endl ;
	}
	int det = determinant(v1);
	cout << det << endl;
		if(det < 0){
			return false;
		}
		return is_positive_halfdetermined(v1); 
}

bool is_negative_determined(const vector<vector<int> >& v, bool b)
{	
	int row = 0;
	int col = 0;
	const size_t size = v[1].size();
	vector<vector<int> > v1(size- 1, vector<int>(size - 1));	
	for(unsigned i = 0; i < size - 1; ++i){
		for(unsigned j = 0; j < size - 1; ++j){
			v1[row][col] = v[i][j];
			++col;
		}
		++row;
		col = 0;
	}
	for(unsigned i = 0; i < size - 1; ++i){
		for(unsigned j = 0; j < size - 1; ++j){
			cout << v1[i][j] << " ";
		}
		cout << endl ;
	}
	int det = determinant(v1);
	cout << det << endl;
	if (v1[1].size() == 2) {
		return (pow(-1, static_cast<int>(b)) * ((v1[0][0] * v1[1][1]) - (v1[0][1] * v1[1][0])) > 0);
	}
		if(pow(-1, static_cast<int>(b)) * det <= 0){
			return false;
		}
	 return is_negative_determined(v1, !b);
}
bool is_negative_halfdetermined(const vector<vector<int> >& v, bool b)
{	
	int row = 0;
	int col = 0;
	const size_t size = v[1].size();
	vector<vector<int> > v1(size- 1, vector<int>(size - 1));	
	for(unsigned i = 0; i < size - 1; ++i){
		for(unsigned j = 0; j < size - 1; ++j){
			v1[row][col] = v[i][j];
			++col;
		}
		++row;
		col = 0;
	}
	for(unsigned i = 0; i < size - 1; ++i){
		for(unsigned j = 0; j < size - 1; ++j){
			cout << v1[i][j] << " ";
		}
		cout << endl ;
	}
	int det = determinant(v1);
	cout << det << endl;
	if (v1[1].size() == 2) {
		return (pow(-1, static_cast<int>(b)) * ((v1[0][0] * v1[1][1]) - (v1[0][1] * v1[1][0])) > 0);
	}
		if(pow(-1, static_cast<int>(b)) * det < 0){
			return false;
		}
	 return is_negative_halfdetermined(v1, !b);
}
int main()
{
	srand(time(NULL));

	unsigned n = 0;
	cin >> n;
	vector<vector<int> > matrix(n, vector<int>(n));
	for (unsigned i = 0; i < n; ++i) {
		for (unsigned j = 0; j < n; ++j) {
			matrix[i][j] = std::rand() % 100;	
		}
	}

	cout <<"MATRIX\n";
	for (unsigned i = 0; i < n; ++i) {
		for(unsigned j = 0; j < n; ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
    int det = determinant(matrix);
	cout << "det =" << det << endl;
	if(determinant(matrix) > 0 && matrix[n-1][n-1] > 0){
		if ( is_positive_determined(matrix) ){
			cout << "positive determined"  << endl;
		}
		else if(is_positive_halfdetermined(matrix)){
			cout << "positive halfdetermined" << endl;
		}
	}
	cout << endl;
	bool b = true;
	if((det > 0 && n % 2 == 0 && matrix[0][0] < 0) || 
			(det > 0 && n % 2 != 0 && matrix[0][0] > 0)){
		if(is_negative_determined(matrix, b)){
			cout << "negative determined" << endl;
		}
		else if(is_negative_halfdetermined(matrix, b)){
			cout << "negative halfdetermined" << endl;
		}
	}
	return 0;
}

