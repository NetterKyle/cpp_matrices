#include <vector>
#include <cmath>

template <typename T>
class Matrix
{
    public:
        int num_rows;
        int num_columns;
        std::vector<T> data;

        Matrix(int num_rows, int num_columns, const T& data) 
            : num_rows(num_rows), num_columns(num_columns), data(num_rows * num_columns, data) {}

        T& operator()(int row, int column)
        {
            if ((row < 0) || (row >= num_rows) || (column < 0)|| (column >= num_columns))
            {
                throw std::out_of_range("Index out of range");
            }

            return data[(row * num_columns) + column];
        }

        double calc_norm()
        {
            double sum = 0;
            for (int i = 0; i < num_rows; i++)
            {
                for (int j = 0; j < num_columns; j++)
                {
                    T& value = data[((i * num_columns) + j)];
                    sum += value * value;
                }
            }

            return std::sqrt(sum);
        }

        Matrix<T> operator+(Matrix& mat2)
        {
            Matrix<T> sum_matrix(num_rows, mat2.num_columns, 0);
            for (int i = 0; i < num_rows; i++) // Iterate for number of rows in current matrix
            {
                for (int j = 0; j < mat2.num_columns; j++) // Iterate for number of columns in second matrix
                {
                    sum_matrix(i,j) = operator()(i,j) + mat2(i,j);
                }
            }

            return sum_matrix;
        }

        Matrix<T> operator-(Matrix& mat2)
        {
            Matrix<T> diff_matrix(num_rows, mat2.num_columns, 0);
            for (int i = 0; i < num_rows; i++) // Iterate for number of rows in current matrix
            {
                for (int j = 0; j < mat2.num_columns; j++) // Iterate for number of columns in second matrix
                {
                    diff_matrix(i,j) = operator()(i,j) - mat2(i,j);
                }
            }

            return diff_matrix;
        }

    
        Matrix<T> operator*(Matrix& mat2)
        {
            Matrix<T> multiplied_matrix(num_rows, mat2.num_columns, 0);
            for (int i = 0; i < num_rows; i++) // Iterate for number of rows in current matrix
            {
                for (int j = 0; j < mat2.num_columns; j++) // Iterate for number of columns in second matrix
                {
                    double sum = 0;
                    for (int k = 0; k < num_columns; k++) // Iterate for number of columns in current matrix
                    {
                        sum += operator()(i,k) * mat2(k,j);
                    }
                    multiplied_matrix(i, j) = sum;
                }
            }

            return multiplied_matrix;
        }

        void print_data()
        {
            for (int value : data)
            {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
};