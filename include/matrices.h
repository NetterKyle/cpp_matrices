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
};