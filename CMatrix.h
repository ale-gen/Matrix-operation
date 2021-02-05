//
// Created by Aleksandra Generowicz on 27/12/2020.
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "matrix_constants.h"
using namespace std;

template<typename T>
class CMatrix {
    private:
        T* matrix;
        int size;
        int columns_number;
        int rows_number;
        void copy_matrix(const CMatrix<T> &other_matrix);
        void move_matrix(CMatrix<T> &other_matrix);
        int count_index(int row_number, int column_number);
        vector<T> read_matrix_row_from_file_line(string line, int* error_code = nullptr);
        void set_up_matrix_from_vectors(vector<vector<T>> vector_of_matrices);
        void create_matrix_from_file(vector<vector<T>> vector_of_rows, int* error_code = nullptr);
        T det_rec(const CMatrix<T> &mat, int* error_code = nullptr);

    public:
        CMatrix(); //Default square matrix 5x5
        CMatrix(int n, int* error_code = nullptr); //Square matrix nxn
        CMatrix(int rows_number, int columns_number, int* error_code = nullptr);
        CMatrix(const CMatrix<T> &other_matrix);
        CMatrix(CMatrix<T> &&other_matrix);
        ~CMatrix();
        bool create_matrix(int rows, int columns, int* error_code = nullptr);
        bool create_identity_matrix_from_square_matrix(int* error_code = nullptr);
        bool fill_matrix(T value);
        bool set_value_at(int row_index, int column_index, T value, int* error_code = nullptr);
        T get_value(int row_index, int column_index, int* error_code = nullptr);
        CMatrix<T> sum_matrices(const CMatrix<T> &other_matrix, int* error_code = nullptr);
        CMatrix<T> sub_matrices(const CMatrix<T> &other_matrix, int* error_code = nullptr);
        CMatrix<T> mult_matrices(const CMatrix<T> &other_matrix, int* error_code = nullptr);
        CMatrix<T> mult_matrix_by_value(T value, int* error_code = nullptr);
        T scalar_product(const CMatrix<T> &other_matrix, int* error_code = nullptr);
        CMatrix<T> transposition(int* error_code = nullptr);
        CMatrix<T> create_column_vector(int column_index, int* error_code = nullptr);
        CMatrix<T> create_row_vector(int row_index, int* error_code = nullptr);
        bool set_new_table_size(int new_size, int* error_code = nullptr);
        bool set_new_table_size(int rows_number, int columns_number, int* error_code = nullptr);
        void operator=(const CMatrix<T> &other_matrix);
        void operator=(CMatrix<T> &&other_matrix);
        CMatrix<T> operator+(const CMatrix<T> &other_matrix);
        CMatrix<T> operator-(const CMatrix<T> &other_matrix);
        CMatrix<T> operator*(const CMatrix<T> &other_matrix);
        CMatrix<T> operator*(T value);
        T operator()(int row_index, int column_index);
        void print_matrix();
        void read_matrix_from_file(string file_name, int* error_code = nullptr);
        vector<CMatrix<T>> read_matrices_from_file(string file_name, int* error_code = nullptr);
        T det(int* error_code = nullptr);
};
