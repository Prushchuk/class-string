#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
class Matrix
{
private:
	int rows;
	int cols;
	T* data;

public:
	Matrix() : rows{ 0 }, cols{ 0 }, data{nullptr} {}
	Matrix(int rows, int cols) : rows{ rows }, cols{ cols } {
		data = new T[rows * cols];
	}
	~Matrix() {
		delete[]data;
	}

	T& operator()(int row, int col) {
		return data[row * cols + col];
	}

	void fillFromKeyboard() {
		cout << "Enter matrix elements: " << endl;
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				cin >> data[i * cols + j];
			}
		}
	}

	void fillRandom() {
		srand(time(nullptr));
		for (size_t i = 0; i < rows * cols; i++)
		{
			data[i] = static_cast<T>(rand() % 100);
		}
	}

	void display() {
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				cout << data[i * cols + j] << " ";
			}
			cout << endl;
		}
	}

	Matrix<T> operator+(const Matrix<T>& other) {
		if (rows != other.rows || cols != other.cols)
			return Matrix<T>();

		Matrix<T> result(rows, cols);
		for (size_t i = 0; i < rows * cols; i++)
		{
			result.data[i] = data[i] + other.data[i];
		}
		return result;
	}

	Matrix<T> operator-(const Matrix<T>& other) {
		if (rows != other.rows || cols != other.cols)
			return Matrix<T>();

		Matrix<T> result(rows, cols);
		for (size_t i = 0; i < rows * cols; i++)
		{
			result.data[i] = data[i] - other.data[i];
		}
		return result;
	}

	Matrix<T> operator*(const Matrix<T>& other) {
		if (cols != other.rows)
			return Matrix<T>();

		Matrix<T> result(rows, other.cols);
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < other.cols; j++)
			{
				for (size_t k = 0; k < cols; k++)
				{
					result(i, j) += data[i * cols + k] * other.data[k * other.cols + j];
				}
			}
		}
		return result;
	}

	Matrix<T> operator/(const Matrix<T>& other) {
		if (cols != other.rows)
			return Matrix<T>();

		Matrix<T> result(rows, other.cols);
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < other.cols; j++)
			{
				for (size_t k = 0; k < cols; k++)
				{
					result(i, j) += data[i * cols + k] / other.data[k * other.cols + j];
				}
			}
		}
		return result;
	}

	T findMax() {
		T maxElement = data[0];
		for (size_t i = 0; i < rows * cols; i++)
		{
			if (data[i] > maxElement)
				maxElement = data[i];
		}
		return maxElement;
	}

	T findMin() {
		T minElement = data[0];
		for (size_t i = 0; i < rows * cols; i++)
		{
			if (data[i] < minElement)
				minElement = data[i];
		}
		return minElement;
	}
};

int main()
{
	Matrix<int> mat1(2, 3);
	mat1.fillRandom();
	cout << "Matrix 1: " << endl;
	mat1.display();

	Matrix<int> mat2(2, 3);
	mat2.fillFromKeyboard();
	cout << "Matrix 2:" << endl;
	mat2.display();

	Matrix<int> mat3 = mat1 + mat2;
	cout << "Matrix 1 + Matrix 2:" << endl;
	mat3.display();

	cout << "Max element in Matrix 1: " << mat1.findMax() << endl;
	cout << "Min element in Matrix 2: " << mat2.findMin() << endl;
}