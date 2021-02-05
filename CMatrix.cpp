//
// Created by Aleksandra Generowicz on 27/12/2020.
//
#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <iomanip>
#include "CMatrix.h"
using namespace std;

template<typename T>
CMatrix<T>::CMatrix() {
    size = DEFAULT_SIZE * DEFAULT_SIZE;
    matrix = new T[size];
    columns_number = DEFAULT_SIZE;
    rows_number = DEFAULT_SIZE;
    fill_matrix(T());
}

template<typename T>
CMatrix<T>::CMatrix(int n, int* error_code) {
    create_matrix(n, n, error_code);
}

template<typename T>
CMatrix<T>::CMatrix(int rows_number, int columns_number, int* error_code) {
    create_matrix(rows_number, columns_number, error_code);
}

template<typename T>
CMatrix<T>::CMatrix(const CMatrix<T> &other_matrix) {
    copy_matrix(other_matrix);
    cout<<"Copy constructor"<<endl;
}

template<typename T>
CMatrix<T>::CMatrix(CMatrix<T> &&other_matrix) {
    move_matrix(other_matrix);
    cout<<"Move constructor"<<endl;
}

template<typename T>
CMatrix<T>::~CMatrix<T>() {
    if (matrix != nullptr) delete matrix;
}

template<typename T>
void CMatrix<T>::copy_matrix(const CMatrix<T> &other_matrix) {
    if(other_matrix.matrix == nullptr) return;

    size = other_matrix.size;
    columns_number = other_matrix.columns_number;
    rows_number = other_matrix.rows_number;
    matrix = new T[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = other_matrix.matrix[i];
    }
}

template<typename T>
void CMatrix<T>::move_matrix(CMatrix<T> &other_matrix) {
    size = other_matrix.size;
    matrix = other_matrix.matrix;
    columns_number = other_matrix.columns_number;
    rows_number = other_matrix.rows_number;
    other_matrix.matrix = nullptr;
}

template<typename T>
int CMatrix<T>::count_index(int row_number, int column_number) {
    return row_number * columns_number + column_number;
}

template<typename T>
void CMatrix<T>::print_matrix() {
    std::cout<<std::setprecision(10);
    if(columns_number <= 0 || rows_number <= 0 || matrix == nullptr) return;

    for(int i = 0; i < rows_number; i++) {
        for (int j = 0; j < columns_number; j++) {
            //Counting index of element in matrix: index = rowIndex * columnsNumber + columnIndex
            std::cout << std::setw(10);
            cout<<matrix[count_index(i, j)]<<" ";
        }
        cout<<endl;
    }
    cout<<"Size: "<<rows_number<<" "<<columns_number<<endl;
}

template<>
inline void CMatrix<float>::print_matrix() {
    std::cout<<std::setprecision(6);
    if(columns_number <= 0 || rows_number <= 0 || matrix == nullptr) return;

    for(int i = 0; i < rows_number; i++) {
        for (int j = 0; j < columns_number; j++) {
            //Counting index of element in matrix: index = rowIndex * columnsNumber + columnIndex
            std::cout << std::setw(8);
            cout<<matrix[count_index(i, j)]<<" ";
        }
        cout<<endl;
    }
    cout<<"Size: "<<rows_number<<" "<<columns_number<<endl;
}

template<typename T>
bool CMatrix<T>::fill_matrix(T value) {
    if(columns_number <= 0 || rows_number <= 0 || matrix == nullptr) return false;

    for(int i = 0; i < rows_number; i++) {
        for (int j = 0; j < columns_number; j++) {
            //Counting index of element in matrix: index = rowIndex * columnsNumber + columnIndex
            matrix[count_index(i, j)] = value;
        }
    }
}

template<typename T>
bool CMatrix<T>::set_value_at(int row_index, int column_index, T value, int* error_code) {
    int code = MATRIX_CORRECT;
    if(matrix == nullptr) {
        code = MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR;
    } else if (row_index < 0 || column_index < 0 || row_index >= rows_number || column_index >= columns_number) {
        code = MATRIX_INCORRECT_SET_VALUE_ERROR;
    }
    if(error_code != nullptr) {
        *error_code = code;
    }
    if(code != MATRIX_CORRECT) return false;

    matrix[count_index(row_index, column_index)] = value;
    return true;
}

template<typename T>
T CMatrix<T>::get_value(int row_index, int column_index, int* error_code) {
    int code = MATRIX_CORRECT;
    if(matrix == nullptr) {
        code = MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR;
    } else if (row_index >= rows_number || row_index < 0 || column_index >= columns_number || column_index < 0) {
        code = MATRIX_INCORRECT_GET_VALUE_ERROR;
    }
    if(error_code != nullptr) {
        *error_code = code;
    }
    if(code != MATRIX_CORRECT) return NULL;
    return matrix[count_index(row_index, column_index)];
}

template<typename T>
bool CMatrix<T>::set_new_table_size(int new_size, int* error_code) {
    int code = MATRIX_CORRECT;
    if(matrix == nullptr) {
        code = MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR;
    } else if (new_size <= 0) {
        code = MATRIX_INCORRECT_SIZE_ERROR;
    }
    if(error_code != nullptr) {
        *error_code = code;
    }
    if(code != MATRIX_CORRECT) return false;

    T *temp_table;
    temp_table = new T[new_size];
    for (int i = 0; i < new_size; i++) {
        if (i < size)
            temp_table[i] = matrix[i];
        else
            temp_table[i] = T();
    }
    size = new_size;
    delete[] matrix;
    matrix = temp_table;
    return true;
}

template<typename T>
bool CMatrix<T>::set_new_table_size(int rows_number, int columns_number, int* error_code) {
    int code = MATRIX_CORRECT;
    if(matrix == nullptr) {
        code = MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR;
    } else if (rows_number <= 0 || columns_number <= 0) {
        code = MATRIX_INCORRECT_SIZE_ERROR;
    }
    if(error_code != nullptr) {
        *error_code = code;
    }
    if(code != MATRIX_CORRECT) return false;

    int new_size = rows_number * columns_number;
    T *temp_table;
    temp_table = new T[new_size];
    for (int i = 0; i < new_size; i++) {
        if (i < size)
            temp_table[i] = matrix[i];
        else
            temp_table[i] = T();
    }
    size = new_size;
    this->rows_number = rows_number;
    this->columns_number = columns_number;
    delete[] matrix;
    matrix = temp_table;
    return true;
}

template<typename T>
CMatrix<T> CMatrix<T>::sum_matrices(const CMatrix<T> &other_matrix, int* error_code) {
    int code = MATRIX_CORRECT;
    if(matrix == nullptr) {
        code = MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR_DEFAULT_MATRIX_RETURNED;
    } else if(other_matrix.matrix == nullptr) {
        code = MATRIX_INCORRECT_OTHER_NOT_EXIST_ERROR_CURRENT_MATRIX_RETURNED;
    } else if (this->columns_number != other_matrix.columns_number || this->rows_number != other_matrix.rows_number) {
            code = MATRIX_INCORRECT_SIZE_ERROR;
    }

    if(error_code != nullptr) {
        *error_code = code;
    }
    if(code != MATRIX_CORRECT) {
        if(code != MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR_DEFAULT_MATRIX_RETURNED) {
            return move(*this);
        }
        return move(CMatrix<T>());
    }

    CMatrix<T> result_matrix(rows_number, columns_number, error_code);

    for(int i = 0; i < rows_number; i++) {
        for (int j = 0; j < columns_number; j++) {
            //Counting index of element in matrix: index = rowIndex * columnsNumber + columnIndex
            result_matrix.matrix[count_index(i, j)] = matrix[count_index(i, j)] + other_matrix.matrix[count_index(i, j)];
        }
    }
    return move(result_matrix);
}

template<typename T>
CMatrix<T> CMatrix<T>::sub_matrices(const CMatrix<T> &other_matrix, int* error_code) {
    int code = MATRIX_CORRECT;
    if(matrix == nullptr) {
        code = MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR_DEFAULT_MATRIX_RETURNED;
    } else if(other_matrix.matrix == nullptr) {
        code = MATRIX_INCORRECT_OTHER_NOT_EXIST_ERROR_CURRENT_MATRIX_RETURNED;
    } else if (this->columns_number != other_matrix.columns_number || this->rows_number != other_matrix.rows_number) {
        code = MATRIX_INCORRECT_SIZE_ERROR;
    }

    if(error_code != nullptr) {
        *error_code = code;
    }
    if(code != MATRIX_CORRECT) {
        if(code != MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR_DEFAULT_MATRIX_RETURNED) {
            return move(*this);
        }
        return move(CMatrix<T>());
    }

    CMatrix<T> result_matrix(rows_number, columns_number, error_code);

    for(int i = 0; i < rows_number; i++) {
        for (int j = 0; j < columns_number; j++) {
            //Counting index of element in matrix: index = rowIndex * columnsNumber + columnIndex
            result_matrix.matrix[count_index(i, j)] = matrix[count_index(i, j)] - other_matrix.matrix[count_index(i, j)];
        }
    }
    return move(result_matrix);
}

template<typename T>
CMatrix<T> CMatrix<T>::mult_matrices(const CMatrix<T> &other_matrix, int* error_code) {
    int code = MATRIX_CORRECT;
    if(matrix == nullptr) {
        code = MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR_DEFAULT_MATRIX_RETURNED;
    } else if(other_matrix.matrix == nullptr) {
        code = MATRIX_INCORRECT_OTHER_NOT_EXIST_ERROR_CURRENT_MATRIX_RETURNED;
    } else if(this->columns_number != other_matrix.rows_number) {
        code = MATRIX_INCORRECT_DIMENSION_ERROR;
    }

    if(error_code != nullptr) {
        *error_code = code;
    }
    if(code != MATRIX_CORRECT) {
        if(code != MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR_DEFAULT_MATRIX_RETURNED) {
            return move(*this);
        }
        return move(CMatrix<T>());
    }

    CMatrix<T> result_matrix(this->rows_number, other_matrix.columns_number, error_code);

    for (int i = 0; i < result_matrix.size; i++) {
        for (int j = i % other_matrix.columns_number, z = (i / other_matrix.columns_number) * columns_number;
        j < other_matrix.size; j += other_matrix.columns_number, z++) {
            result_matrix.matrix[i] += matrix[z] * other_matrix.matrix[j];
        }
    }
    return move(result_matrix);
}

template<typename T>
CMatrix<T> CMatrix<T>::mult_matrix_by_value(T value, int* error_code) {
    int code = MATRIX_CORRECT;
    if(matrix == nullptr) {
        code = MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR_DEFAULT_MATRIX_RETURNED;
        if(error_code != nullptr) {
            *error_code = code;
        }
        return move(CMatrix<T>());
    }

    CMatrix<T> result_matrix(rows_number, columns_number, error_code);

    for(int i = 0; i < size; i++) {
        result_matrix.matrix[i] = matrix[i] * value;
    }
    return move(result_matrix);
}

template<typename T>
T CMatrix<T>::scalar_product(const CMatrix<T> &other_matrix, int* error_code) {
    int code = MATRIX_CORRECT;
    if(matrix == nullptr) {
        code = MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR;
    } else if (other_matrix.matrix == nullptr) {
        code = MATRIX_INCORRECT_OTHER_NOT_EXIST_ERROR;
    } else if ((columns_number != 1 && rows_number != 1) || other_matrix.rows_number != rows_number || other_matrix.columns_number != columns_number) {
        code = MATRIX_INCORRECT_SIZE_VECTOR_ERROR;
    }
    if(error_code != nullptr) {
        *error_code = code;
    }
    if(code != MATRIX_CORRECT) {
        return NULL;
    }
    T result = T();

    for (int i = 0; i < size; i++) {
        result += matrix[i] * other_matrix.matrix[i];
    }
    return result;
}

template<typename T>
CMatrix<T> CMatrix<T>::transposition(int* error_code) {
    int code = MATRIX_CORRECT;
    if(matrix == nullptr) {
        code = MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR_DEFAULT_MATRIX_RETURNED;
    }
    if(error_code != nullptr) {
        *error_code = code;
    }
    if(code != MATRIX_CORRECT) return move(CMatrix<T>());

    CMatrix<T> transpositioned(columns_number, rows_number, &code);
    int current_column = 0, i = current_column, k = 1;

    for(int j = 0; j < size; j++) {
       transpositioned.matrix[i] =  matrix[j];
        if (j == (transpositioned.rows_number * k - 1)) {
            i = ++current_column;
            ++k;
        } else i += transpositioned.columns_number;
    }
    return move(transpositioned);
}

template<typename T>
CMatrix<T> CMatrix<T>::create_row_vector(int row_index, int* error_code) {
    int code = MATRIX_CORRECT;
    if(matrix == nullptr) {
        code = MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR_DEFAULT_MATRIX_RETURNED;
    } else if (row_index < 0 || row_index >= rows_number) {
        code = MATRIX_INCORRECT_SIZE_ERROR;
    }
    if(error_code != nullptr) {
        *error_code = code;
    }
    if(code != MATRIX_CORRECT) {
        if(code != MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR_DEFAULT_MATRIX_RETURNED) {
            return move(*this);
        }
        return move(CMatrix<T>());
    }

    CMatrix<T> result_matrix(1, columns_number, error_code);

    for (int i = 0; i < columns_number; i++) {
        result_matrix.matrix[i] = matrix[count_index(row_index, i)];
    }
    return move(result_matrix);
}

template<typename T>
CMatrix<T> CMatrix<T>::create_column_vector(int column_index, int* error_code) {
    int code = MATRIX_CORRECT;
    if(matrix == nullptr) {
        code = MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR_DEFAULT_MATRIX_RETURNED;
    } else if (column_index < 0 || column_index >= columns_number) {
        code = MATRIX_INCORRECT_SIZE_ERROR;
    }
    if(error_code != nullptr) {
        *error_code = code;
    }
    if(code != MATRIX_CORRECT) {
        if(code != MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR_DEFAULT_MATRIX_RETURNED) {
            return move(*this);
        }
        return move(CMatrix<T>());
    }

    CMatrix<T> result_matrix(rows_number, 1, error_code);

    for (int i = column_index, j = 0; j < result_matrix.size; i += columns_number, j++) {
        result_matrix.matrix[j] = matrix[i];
    }
    return move(result_matrix);
}

template<typename T>
void CMatrix<T>::operator=(const CMatrix<T> &other_matrix) {
    if(matrix != nullptr) delete matrix;
    copy_matrix(other_matrix);
    cout<<"Copy = (operator)"<<endl;
}

template<typename T>
void CMatrix<T>::operator=(CMatrix<T> &&other_matrix) {
    if(this == &other_matrix) return;

    if(matrix != nullptr) delete matrix;
    move_matrix(other_matrix);
    cout<<"Operator = (move)"<<endl;
}

template<typename T>
CMatrix<T> CMatrix<T>::operator+(const CMatrix<T> &other_matrix) {
    int code = 0;
    CMatrix<T> result_matrix(1,1, &code);
    result_matrix = sum_matrices(other_matrix, &code);
    cout<<"Operator + (copy)"<<endl;
    if(code != MATRIX_CORRECT) throw invalid_argument(MATRIX_EXCEPTION_INVALID_DATA + " Code: " + to_string(code));
    else return move(result_matrix);
}

template<typename T>
CMatrix<T> CMatrix<T>::operator-(const CMatrix<T> &other_matrix) {
    int code = 0;
    CMatrix<T> result_matrix(1,1, &code);
    result_matrix = sub_matrices(other_matrix, &code);
    if(code != MATRIX_CORRECT) throw invalid_argument(MATRIX_EXCEPTION_INVALID_DATA + " Code: " + to_string(code));
    cout<<"Operator - (copy)"<<endl;
    return move(result_matrix);
}

template<typename T>
CMatrix<T> CMatrix<T>::operator*(const CMatrix<T> &other_matrix) {
    int code = 0;
    CMatrix<T> result_matrix(1,1, &code);
    result_matrix = mult_matrices(other_matrix, &code);
    if(code != MATRIX_CORRECT) throw invalid_argument(MATRIX_EXCEPTION_INVALID_DATA + " Code: " + to_string(code));
    cout<<"Operator * (copy)"<<endl;
    return move(result_matrix);
}

template<typename T>
CMatrix<T> CMatrix<T>::operator*(T value) {
    int code = 0;
    CMatrix<T> result_matrix(rows_number,columns_number, &code);
    result_matrix = mult_matrix_by_value(value, &code);
    if(code != MATRIX_CORRECT) throw invalid_argument(MATRIX_EXCEPTION_INVALID_DATA + " Code: " + to_string(code));
    cout<<"Operator * (copy)"<<endl;
    return move(result_matrix);
}

template<typename T>
T CMatrix<T>::operator()(int row_index, int column_index) {
    int code = 0;
    T value = get_value(row_index, column_index, &code);
    if(code != MATRIX_CORRECT) throw invalid_argument(MATRIX_EXCEPTION_INVALID_DATA + " Code: " + to_string(code));
    cout<<"Operator * (copy)"<<endl;
    return value;
}

template<typename T>
bool CMatrix<T>::create_matrix(int rows, int columns, int* error_code) {
    int code = MATRIX_CORRECT;
    if (rows <= 0 || columns <= 0) {
        code = MATRIX_INCORRECT_SIZE_ERROR;
        rows_number = 0;
        columns_number = 0;
        size = 0;
        matrix = nullptr;
    }
    if(error_code != nullptr) {
        *error_code = code;
    }
    if(code != MATRIX_CORRECT) return false;

    size = rows * columns;
    matrix = new T[size];
    this->columns_number = columns;
    this->rows_number = rows;
    fill_matrix(T());
    return true;
}

template<typename T>
bool CMatrix<T>::create_identity_matrix_from_square_matrix(int* error_code) {
    int code = 0;
    if(matrix == nullptr) {
       code = MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR;
    } else if (rows_number != columns_number) {
        code = MATRIX_INCORRECT_SIZE_ERROR;
    }
    if(error_code != nullptr) {
        *error_code = code;
    }
    if(code != MATRIX_CORRECT) return false;

    for (int i = 0; i < size; i++) {
        if (i % (rows_number + 1) == 0) matrix[i] = 1;
        else matrix[i] = 0;
    }
    return true;
}

template<typename T>
void CMatrix<T>::read_matrix_from_file(string file_name, int *error_code) {
    int code = MATRIX_CORRECT;
    fstream file;
    vector<vector<T>> vector_of_rows;
    file.open(file_name, ios::in);
    if (file.good()) {
        string line;
        while(getline(file, line) && !line.empty()) {
            vector_of_rows.push_back(read_matrix_row_from_file_line(line));
        }
    } else {
        code = MATRIX_INCORRECT_FILE_READING_ERROR;
    }
    file.close();

    if(code != MATRIX_CORRECT) {
        if(error_code != nullptr) *error_code = code;
        return;
    }
    create_matrix_from_file(vector_of_rows);
}

template<typename T>
void CMatrix<T>::create_matrix_from_file(vector<vector<T>> vector_of_rows, int *error_code) {
    int code = MATRIX_CORRECT;
    columns_number = 0;
    rows_number = vector_of_rows.size();
    for(int i = 0; i < vector_of_rows.size(); i++) {
        if(vector_of_rows[i].size() > columns_number) columns_number = vector_of_rows[i].size();
    }
    set_new_table_size(rows_number, columns_number, &code);
    if(code != MATRIX_CORRECT) {
        if(error_code != nullptr) *error_code = code;
        return;
    }

    for(int i = 0; i < vector_of_rows.size(); i++) {
        for(int j = 0; j < vector_of_rows[i].size(); j++) {
            matrix[count_index(i, j)] = vector_of_rows[i][j];
        }
    }
}

template<typename T>
vector<T> CMatrix<T>::read_matrix_row_from_file_line(string line, int* error_code) {
    int code = MATRIX_CORRECT;
    vector<T> row;
    string number;
    bool space = true;
    if(line.empty()) return row;

    for(char ch : line) {
        if(ch == ' ') {
            if(!space) {
                row.push_back(atof(number.c_str()));
                number = "";
                space = true;
                code = MATRIX_INCORRECT_SIZE_FORMAT_COMPLETE_WITH_DEFAULT_VALUE;
            }
        } else if(ch > 47 && ch < 58 || ch == '.' || ch == '-') {
            number += ch;
            space = false;
        } else {
            number += '0';
            space = false;
            code = MATRIX_INCORRECT_VALUE_FORMAT_COMPLETE_WITH_DEFAULT_VALUE;
        }
    }
    if(error_code != nullptr) {
        *error_code = code;
    }

    if(!space) {
        row.push_back(atof(number.c_str()));
    }
    return row;
}

//Additional function to read few matrices from file
template<typename T>
vector<CMatrix<T>> CMatrix<T>::read_matrices_from_file(string file_name, int *error_code) {
    *error_code = MATRIX_CORRECT;
    fstream file;
    int index = 0;
    vector<T> row;
    vector<vector<T>> vector_of_matrix;
    vector<CMatrix<T>> vector_of_matrices;
    std::error_code ec{};
    size = std::__fs::filesystem::file_size(file_name, ec);
    if (ec != std::error_code{}) {
        *error_code = MATRIX_INCORRECT_FILE_READING_ERROR;
        return vector_of_matrices;
    }
    if(matrix != nullptr) delete matrix;
    matrix = new T[size];
    rows_number = 0;
    file.open(file_name, ios::in);
    if(file.good()) {
        string line;
        string number;
        char current_char;
        bool enter;
        bool space;
        while(file.get(current_char)) {
            if(current_char == ' ') {
                if(!space) {
                    row.push_back(atof(number.c_str()));
                    space = true;
                    number = "";
                }
                enter = false;
            } else if(current_char == '\n') {
                if(!enter) {
                    enter = true;
                    row.push_back(atof(number.c_str()));
                    vector_of_matrix.push_back(row);
                    row.clear();
                    number = "";
                } else {
                    set_up_matrix_from_vectors(vector_of_matrix);
                    vector_of_matrices.push_back(*this);
                    vector_of_matrix.clear();
                    row.clear();
                }
                space = false;
            } else {
                number += current_char;
                space = false;
                enter = false;
            }
        }
        row.push_back(atof(number.c_str()));
        vector_of_matrix.push_back(row);
        set_up_matrix_from_vectors(vector_of_matrix);
        vector_of_matrices.push_back(*this);
    }
    file.close();
    return vector_of_matrices;
}

template<typename T>
void CMatrix<T>::set_up_matrix_from_vectors(vector<vector<T>> vector_of_matrix) {
    int max = 0;
    for(int i = 0; i < vector_of_matrix.size(); i++) {
        if(vector_of_matrix[i].size() > max) max = vector_of_matrix.at(i).size();
    }
    columns_number = max;
    rows_number = vector_of_matrix.size();
    size = columns_number * rows_number;
    int index = 0;
    for(int i = 0; i < vector_of_matrix.size(); i++) {
        for (int j = 0; j < vector_of_matrix[i].size(); j++) {
            matrix[index++] = vector_of_matrix[i][j];
        }
        if(vector_of_matrix[i].size() < columns_number) {
            for(int j = vector_of_matrix[i].size(); j < columns_number; j++) {
                matrix[index++] = T();
            }
        }
    }
}

template<typename T>
T CMatrix<T>::det(int *error_code) {
    int code = MATRIX_CORRECT;
    if(matrix == nullptr) {
        code = MATRIX_INCORRECT_CURRENT_NOT_EXIST_ERROR;
    } else if(columns_number != rows_number) {
        code = MATRIX_INCORRECT_SIZE_ERROR;
    }
    if(error_code != nullptr) {
        *error_code = code;
    }
    if(code != MATRIX_CORRECT) return NULL;

    return det_rec(*this, error_code);
}

template<typename T>
T CMatrix<T>::det_rec(const CMatrix<T> &mat, int *error_code) {

    if(mat.size == 1) {
        return mat.matrix[0];
    } else if(mat.size == 4) {
        return mat.matrix[0] * mat.matrix[3] - mat.matrix[1] * mat.matrix[2];
    }
    int sign;
    T det = 0;

    for(int i = 0; i < mat.columns_number; i++) {
        CMatrix<T> temp(mat.rows_number-1, mat.columns_number-1, error_code);
        int index = 0;
        for(int row = 0; row < mat.rows_number; row++) {
            for(int col = 0; col < mat.columns_number; col++) {
                if(row != 0 && col != i) {
                    temp.matrix[index++] = mat.matrix[row * mat.columns_number + col];
                }
            }
        }
        if(i % 2 == 0) sign = 1;
        else sign = -1;
        det += sign * mat.matrix[i] * det_rec(temp, error_code);
    }
    return det;
}
