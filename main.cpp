#include <iostream>
#include "CMatrix.cpp"

using namespace std;

void sum_int_correct_test();
void sum_float_correct_test();
void sum_int_incorrect_test();
void sum_float_incorrect_test();
void sub_float_correct_test();
void sub_int_incorrect_test();
void mult_int_correct_test();
void mult_int_incorrect_test();
void mult_by_value_test();
void read_file_and_transposition_correct_test();
void read_file_incorrect_test();
void read_float_matrix_and_square_power_test();
void get_value_test();
void scalar_product_correct_test();
void scalar_product_incorrect_test();
void column_vector_correct_test();
void column_vector_incorrect_test();
void row_vector_correct_test();
void row_vector_incorrect_test();
void read_and_add_three_matrix_test();
void change_identity_matrix_test();
void create_matrix_test();
void read_matrix_from_file(); //Divided function
void det_double_test();
void det_int_test();

int main() {
    create_matrix_test();
    sum_int_correct_test();
    sum_float_correct_test();
    sum_int_incorrect_test();
    sum_float_incorrect_test();
    sub_float_correct_test();
    sub_int_incorrect_test();
    read_file_and_transposition_correct_test();
    read_file_incorrect_test();
    read_float_matrix_and_square_power_test();
    get_value_test();
    mult_int_correct_test();
    mult_int_incorrect_test();
    mult_by_value_test();
    scalar_product_correct_test();
    scalar_product_incorrect_test();
    column_vector_correct_test();
    column_vector_incorrect_test();
    row_vector_correct_test();
    row_vector_incorrect_test();
    change_identity_matrix_test();
    read_and_add_three_matrix_test();
    read_matrix_from_file();
    det_double_test();
    det_int_test();
}

void sum_int_correct_test() {
    cout<<"Test of sum function for ints: "<<endl;
    int* error_code;
    error_code = new int();
    CMatrix<int> matrix(3, error_code);
    cout<<"Matrix: "<<endl;
    matrix.set_value_at(0, 0, 1, error_code);
    matrix.set_value_at(0,1, 2, error_code);
    matrix.set_value_at(0, 2, 3, error_code);
    matrix.set_value_at(1, 0, 4, error_code);
    matrix.set_value_at(1, 1, 5, error_code);
    matrix.set_value_at(1, 2, 6, error_code);
    matrix.set_value_at(2, 0, 7, error_code);
    matrix.set_value_at(2, 1, 8, error_code);
    matrix.set_value_at(2, 2, 9, error_code);
    matrix.print_matrix();

    CMatrix<int> matrix_2(3, error_code);
    cout<<"Matrix_2: "<<endl;
    matrix_2.set_value_at(0, 0, 11, error_code);
    matrix_2.set_value_at(0,1, 12, error_code);
    matrix_2.set_value_at(0, 2, 13, error_code);
    matrix_2.set_value_at(1, 0, 14, error_code);
    matrix_2.set_value_at(1, 1, 15, error_code);
    matrix_2.set_value_at(1, 2, 16, error_code);
    matrix_2.set_value_at(2, 0, 17, error_code);
    matrix_2.set_value_at(2, 1, 18, error_code);
    matrix_2.set_value_at(2, 2, 19, error_code);
    matrix_2.print_matrix();

    CMatrix<int> matrix_sum_result(1, error_code);
    matrix_sum_result = matrix + matrix_2;
    cout<<"Result: Matrix_sum_result = Matrix + Matrix_2"<<endl;
    matrix_sum_result.print_matrix();
    delete error_code;
    cout<<endl;

    /*Should be:
     1 2 3   11 12 13   12 14 16
     4 5 6 + 14 15 16 = 18 20 22
     7 8 9   17 18 19   24 26 28
     */
}

void sum_float_correct_test() {
    cout<<"Test of sum function for floats: "<<endl;
    int* error_code;
    error_code = new int();
    CMatrix<float> matrix(3, error_code);
    cout<<"Matrix: "<<endl;
    matrix.set_value_at(0, 0, 1.1f, error_code);
    matrix.set_value_at(0,1, 1.2f, error_code);
    matrix.set_value_at(0, 2, 1.3f, error_code);
    matrix.set_value_at(1, 0, 1.4f, error_code);
    matrix.set_value_at(1, 1, 1.5f, error_code);
    matrix.set_value_at(1, 2, 1.6f, error_code);
    matrix.set_value_at(2, 0, 1.7f, error_code);
    matrix.set_value_at(2, 1, 1.8f, error_code);
    matrix.set_value_at(2, 2, 1.9f, error_code);
    matrix.print_matrix();

    CMatrix<float> matrix_2(3, error_code);
    cout<<"Matrix_2: "<<endl;
    matrix_2.set_value_at(0, 0, 11.1f, error_code);
    matrix_2.set_value_at(0,1, 12.1f, error_code);
    matrix_2.set_value_at(0, 2, 13.1f, error_code);
    matrix_2.set_value_at(1, 0, 14.1f, error_code);
    matrix_2.set_value_at(1, 1, 15.1f, error_code);
    matrix_2.set_value_at(1, 2, 16.1f, error_code);
    matrix_2.set_value_at(2, 0, 17.1f, error_code);
    matrix_2.set_value_at(2, 1, 18.1f, error_code);
    matrix_2.set_value_at(2, 2, 19.1f, error_code);
    matrix_2.print_matrix();

    CMatrix<float> matrix_sum_result(1, error_code);
    matrix_sum_result = matrix + matrix_2;
    cout<<"Result: Matrix_sum_result = Matrix + Matrix_2"<<endl;
    matrix_sum_result.print_matrix();
    delete error_code;
    cout<<endl;

    /*Should be:
     1.1 1.2 1.3   11.1 12.1 13.1   12.2 13.3 14.4
     1.4 1.5 1.6 + 14.1 15.1 16.1 = 15.5 16.6 17.7
     1.7 1.8 1.9   17.1 18.1 19.1   18.8 19.9 21
     */
}

void sum_int_incorrect_test() {
    cout<<"Test of sum function for ints: "<<endl;
    int* error_code;
    error_code = new int();
    CMatrix<int> matrix(3, error_code);
    cout<<"Matrix: "<<endl;
    matrix.set_value_at(0, 0, 1, error_code);
    matrix.set_value_at(0,1, 2, error_code);
    matrix.set_value_at(0, 2, 3, error_code);
    matrix.print_matrix(); //Print anything

    CMatrix<int> matrix_2(3, 6, error_code);
    cout<<"Matrix_2: "<<endl;
    matrix_2.set_value_at(0, 0, 11, error_code);
    matrix_2.set_value_at(0,1, 12, error_code);
    matrix_2.set_value_at(0, 2, 13, error_code);
    matrix_2.print_matrix(); //Print anything

    CMatrix<int> matrix_sum_result(1, error_code);
    try {
        matrix_sum_result = matrix + matrix_2;
    } catch (invalid_argument) {
        cout<<"Exception was thrown. Sum<int> function."<<endl;
    }
    delete error_code;
    cout<<endl;
}

void sum_float_incorrect_test() {
    cout<<"Test of sum function for ints: "<<endl;
    int* error_code;
    error_code = new int();
    CMatrix<float> matrix(3, error_code);
    cout<<"Matrix: "<<endl;
    matrix.set_value_at(0, 0, 1.1, error_code);
    matrix.set_value_at(0,1, 2.1, error_code);
    matrix.set_value_at(0, 2, 3.1, error_code);
    matrix.print_matrix(); //Print anything

    CMatrix<float> matrix_2(2, 3, error_code);
    cout<<"Matrix_2: "<<endl;
    matrix_2.set_value_at(0, 0, 1.1, error_code);
    matrix_2.set_value_at(0,1, 1.2, error_code);
    matrix_2.set_value_at(0, 2, 1.3, error_code);
    matrix_2.print_matrix(); //Print anything

    CMatrix<float> matrix_sum_result(1, error_code);
    try {
        matrix_sum_result = matrix + matrix_2;
    } catch (invalid_argument) {
        cout<<"Exception was thrown. Sum<float> function."<<endl;
    }
    delete error_code;
    cout<<endl;
}

void sub_float_correct_test() {
    cout<<"Test of sub function for floats: "<<endl;
    int* error_code;
    error_code = new int();
    CMatrix<float> matrix(3, error_code);
    cout<<"Matrix: "<<endl;
    matrix.set_value_at(0, 0, 1.1f, error_code);
    matrix.set_value_at(0,1, 1.2f, error_code);
    matrix.set_value_at(0, 2, 1.3f, error_code);
    matrix.set_value_at(1, 0, 1.4f, error_code);
    matrix.set_value_at(1, 1, 1.5f, error_code);
    matrix.set_value_at(1, 2, 1.6f, error_code);
    matrix.set_value_at(2, 0, 1.7f, error_code);
    matrix.set_value_at(2, 1, 1.8f, error_code);
    matrix.set_value_at(2, 2, 1.9f, error_code);
    matrix.print_matrix();

    CMatrix<float> matrix_2(3, error_code);
    cout<<"Matrix_2: "<<endl;
    matrix_2.set_value_at(0, 0, 11.1f, error_code);
    matrix_2.set_value_at(0,1, 12.1f, error_code);
    matrix_2.set_value_at(0, 2, 13.1f, error_code);
    matrix_2.set_value_at(1, 0, 14.1f, error_code);
    matrix_2.set_value_at(1, 1, 15.1f, error_code);
    matrix_2.set_value_at(1, 2, 16.1f, error_code);
    matrix_2.set_value_at(2, 0, 17.1f, error_code);
    matrix_2.set_value_at(2, 1, 18.1f, error_code);
    matrix_2.set_value_at(2, 2, 19.1f, error_code);
    matrix_2.print_matrix();

    CMatrix<float> matrix_sum_result(1, error_code);
    matrix_sum_result = matrix - matrix_2;
    cout<<"Result: Matrix_sum_result = Matrix - Matrix_2"<<endl;
    matrix_sum_result.print_matrix();
    delete error_code;
    cout<<endl;

    /*Should be:
     1.1 1.2 1.3   11.1 12.1 13.1   -10   -10.9 -11.8
     1.4 1.5 1.6 + 14.1 15.1 16.1 = -12.7 -13.6 -14.5
     1.7 1.8 1.9   17.1 18.1 19.1   -15.4 -16.3 -17.2
     */
}

void sub_int_incorrect_test() {
    cout<<"Test of sum function for ints: "<<endl;
    int* error_code;
    error_code = new int();
    CMatrix<int> matrix(3, error_code);
    cout<<"Matrix: "<<endl;
    matrix.set_value_at(0, 0, 1, error_code);
    matrix.set_value_at(0,1, 2, error_code);
    matrix.set_value_at(0, 2, 3, error_code);
    matrix.print_matrix(); //Print anything

    CMatrix<int> matrix_2(3, 6, error_code);
    cout<<"Matrix_2: "<<endl;
    matrix_2.set_value_at(0, 0, 11, error_code);
    matrix_2.set_value_at(0,1, 12, error_code);
    matrix_2.set_value_at(0, 2, 13, error_code);
    matrix_2.print_matrix(); //Print anything

    CMatrix<int> matrix_sum_result(1, error_code);
    try {
        matrix_sum_result = matrix - matrix_2;
    } catch (invalid_argument) {
        cout<<"Exception was thrown. Sub function."<<endl;
    }
    delete error_code;
    cout<<endl;
}

void read_file_and_transposition_correct_test() {
    cout<<"Test for reading int matrix from file and transponse it: "<<endl;
    int* error_code;
    error_code = new int();
    cout<<"Reading int matrix from the file: "<<endl;
    CMatrix<int> file_matrix(3, error_code);
    cout<<"Creating some matrix, for example 3x3:"<<endl;
    file_matrix.print_matrix();
    const char *file_name = "int_matrix.txt";
    file_matrix.read_matrix_from_file(file_name, error_code);
    if(*error_code == MATRIX_CORRECT) {
        cout<<"After reading the file: "<<endl;
        file_matrix.print_matrix();
    } else cout<<"The operation failed. Error code: "<<*error_code<<endl;
    cout<<"Transposition: "<<endl;
    file_matrix = file_matrix.transposition();
    file_matrix.print_matrix();
    delete error_code;
    cout<<endl;
}

void read_file_incorrect_test() {
    cout<<"Test for reading int matrix from file: (Should be error)"<<endl;
    int* error_code;
    error_code = new int();
    cout<<"Reading int matrix from the file: "<<endl;
    CMatrix<int> file_matrix(3, error_code);
    cout<<"Creating some matrix, for example 3x3:"<<endl;
    file_matrix.print_matrix();
    const char *file_name = "int_matrix2.txt";
    file_matrix.read_matrix_from_file(file_name, error_code);
    if(*error_code == MATRIX_CORRECT) {
        cout<<"After reading the file: "<<endl;
        file_matrix.print_matrix();
    } else cout<<"The operation failed. Error code: "<<*error_code<<endl;
    file_matrix.print_matrix();
    delete error_code;
    cout<<endl;
    //If current matrix doesn't exist - we get the default matrix;
    //else we get current matrix without change;
    //In this case - current matrix
}

void read_float_matrix_and_square_power_test() {
    int *error_code;
    error_code = new int();
    CMatrix<float> matrix_from_file_10x10;
    const char *file_name = "float_matrix_10x10.txt";
    matrix_from_file_10x10.read_matrix_from_file(file_name, error_code);
    if(*error_code == MATRIX_CORRECT) {
        cout<<"After reading the file: "<<endl;
        matrix_from_file_10x10.print_matrix();
    } else cout<<"The operation failed. Error code: "<<*error_code<<endl;
    cout<<endl;

    cout<<"Result = Matrix_10x10 * Matrix10x10: "<<endl;
    CMatrix<float> result(2, error_code);
    result = matrix_from_file_10x10 * matrix_from_file_10x10;
    result.print_matrix();
    delete error_code;
    cout<<endl;
    /*
      1.9 1.2 1.45 1.67 1.89 0.45 0.2 0.3 0.7 1.1      1.9 1.2 1.45 1.67 1.89 0.45 0.2 0.3 0.7 1.1     13.129 30.968 33.8744 4.5898 10.4506 17.3478 8.956 7.506 5.714 14.728
      2.4 5.0 5.67 -1.2 -0.2 3.09 5.6 1.2 0.3 1.2      2.4 5.0 5.67 -1.2 -0.2 3.09 5.6 1.2 0.3 1.2     44.757 62.974 65.4768 11.8479 23.3273 34.9026 68.218 15.279 12.426 32.545
      1.9 1.2 1.45 1.67 1.89 0.45 0.2 0.3 0.7 1.3      1.9 1.2 1.45 1.67 1.89 0.45 0.2 0.3 0.7 1.3     12.649 31.968 35.0084 4.3498 10.4106 17.9658 10.076 7.746 5.774 14.948
     0.3 5.0 5.67 -1.2 -0.2 3.09 -5.6 1.2 0.3 1.4     0.3 5.0 5.67 -1.2 -0.2 3.09 -5.6 1.2 0.3 1.4     19.007 48.014 47.3258 -10.6031 -1.8497 29.5356 66.678 11.529 3.176 11.415
      1.9 1.2 1.45 1.67 1.89 0.45 0.2 0.3 0.7 1.5  *   1.9 1.2 1.45 1.67 1.89 0.45 0.2 0.3 0.7 1.5  =  12.169 32.968 36.1424 4.1098 10.3706 18.5838 11.196 7.986 5.834 15.168
      2.4 5.0 5.67 -1.2 -0.2 3.09 5.6 1.2 0.3 1.6      2.4 5.0 5.67 -1.2 -0.2 3.09 5.6 1.2 0.3 1.6     43.797 64.974 67.7448 11.3679 23.2473 36.1386 70.458 15.759 12.546 32.985
      1.9 1.2 1.45 1.67 1.89 0.45 0.2 0.3 0.7 1.7      1.9 1.2 1.45 1.67 1.89 0.45 0.2 0.3 0.7 1.7     11.689 33.968 37.2764 3.8698 10.3306 19.2018 12.316 8.226 5.894 15.388
      2.4 5.0 -0.3 -1.2 -0.9 3.09 5.6 1.2 0.3 1.8      2.4 5.0 -0.3 -1.2 -0.9 3.09 5.6 1.2 0.3 1.8     30.644 57.97 59.2073 -0.0110009 10.601 33.7551 70.244 13.998 7.937 24.394
     0.36 1.2 1.45 1.67 1.89 0.45 0.2 0.3 0.7 1.9     0.36 1.2 1.45 1.67 1.89 0.45 0.2 0.3 0.7 1.9     8.283 33.12 36.1774 1.058 7.38 19.1268 13.128 8.004 4.876 13.914
    -2.4 5.0 5.67 -1.2 -0.2 3.09 5.6 1.2 0.3 1.10    -2.4 5.0 5.67 -1.2 -0.2 3.09 5.6 1.2 0.3 1.10     35.877 56.714 57.9498 3.9519 14.2753 32.4336 66.698 13.719 9.036 27.155
     */
}

void get_value_test() {
    cout<<"Test for getting value: "<<endl;
    int* error_code;
    error_code = new int();
    cout<<"Matrix: "<<endl;
    CMatrix<double> double_matrix(5,3, error_code);
    double_matrix.set_value_at(0, 0, 1.1, error_code);
    double_matrix.set_value_at(0, 1, 1.2, error_code);
    double_matrix.set_value_at(0, 2, 1.3, error_code);
    double_matrix.set_value_at(1, 0, 1.4, error_code);
    double_matrix.set_value_at(1, 1, 1.5, error_code);
    double_matrix.set_value_at(1, 2, 1.6, error_code);
    double_matrix.set_value_at(2, 0, 1.7, error_code);
    double_matrix.set_value_at(2, 1, 1.8, error_code);
    double_matrix.set_value_at(2, 2, 1.9, error_code);
    double_matrix.set_value_at(3, 0, 2.0, error_code);
    double_matrix.set_value_at(3, 1, 2.1, error_code);
    double_matrix.set_value_at(3, 2, 2.2, error_code);
    double_matrix.set_value_at(4, 0, 2.3, error_code);
    double_matrix.set_value_at(4, 1, 2.4, error_code);
    double_matrix.set_value_at(4, 2, 2.5, error_code);
    double_matrix.print_matrix();
    cout<<"Getting value from position in matrix: "<<endl;
    //Using get_value method
    double value_1 = double_matrix.get_value(2,1, error_code);
    if(*error_code == MATRIX_CORRECT) cout<<"Row: 2, column: 1 = "<<value_1<<endl;
    else cout<<"Impossible operation. Error code: "<<*error_code<<endl;
    //Using operator()
    double value_2 = double_matrix(1,2);
    if(*error_code == MATRIX_CORRECT) cout<<"Row: 1, column: 2 = "<<value_2<<endl;
    else cout<<"Impossible operation. Error code: "<<*error_code<<endl;
    //Should return a error, using operator()
    try {
        double value_3 = double_matrix(5, 1);
        cout<<"Row: 5, column: 1 = "<<value_3<<endl;
    } catch(invalid_argument) {
        cout<<"Impossible operation. Exception: Invalid_argument was thrown. "<<endl;
    }
    //Should return a error, using get_value method
    double value_4 = double_matrix.get_value(4,3, error_code);
    if(*error_code == MATRIX_CORRECT) cout<<"Row: 4, column: -8 = "<<value_4<<endl;
    else cout<<"Impossible operation. Error code: "<<*error_code<<endl;
    delete error_code;
    cout<<endl;
}

void mult_int_correct_test() {
    int* error_code;
    error_code = new int();
    cout<<"Matrix_1:"<<endl;
    CMatrix<int> matrix(7,1, error_code);
    matrix.set_value_at(0, 0, 7, error_code);
    matrix.set_value_at(1, 0, -1, error_code);
    matrix.set_value_at(2,0, 9, error_code);
    matrix.set_value_at(3, 0, -2, error_code);
    matrix.set_value_at(5, 0, 8, error_code);
    matrix.set_value_at(6, 0, 5, error_code);
    matrix.print_matrix();
    cout<<"Matrix_2: "<<endl;
    CMatrix<int> matrix_2(3,7, error_code);
    matrix_2.set_value_at(0, 0, 1, error_code);
    matrix_2.set_value_at(0,2, 2, error_code);
    matrix_2.set_value_at(0, 4, 3, error_code);
    matrix_2.set_value_at(1, 1, 4, error_code);
    matrix_2.set_value_at(1, 3, 5, error_code);
    matrix_2.set_value_at(1, 6, 6, error_code);
    matrix_2.set_value_at(2, 0, 7, error_code);
    matrix_2.set_value_at(2, 4, 8, error_code);
    matrix_2.set_value_at(2, 2, 9, error_code);
    matrix_2.print_matrix();
    cout<<"Result: Matrix_2 * Matrix_1"<<endl;
    CMatrix<int> result(2, error_code);
    result = matrix_2 * matrix;
    result.print_matrix();
    delete error_code;
    cout<<endl;
    /*
                        7
                       -1
     1 0 2 0 3 0 0      9       25
     0 4 0 5 0 0 6  *  -2  =    16
     7 0 9 0 8 0 0      0      130
                        8
                        5
     */
}

void mult_int_incorrect_test() {
    int* error_code;
    error_code = new int();
    cout<<"Matrix_1:"<<endl;
    CMatrix<int> matrix(7,1, error_code);
    matrix.print_matrix();
    cout<<"Matrix_2: "<<endl;
    CMatrix<int> matrix_2(3,7, error_code);
    matrix_2.print_matrix();
    cout<<"Result: Matrix_1 * Matrix_2"<<endl;
    CMatrix<int> result(2, error_code);
    try {
        result = matrix * matrix_2;
        result.print_matrix();
    } catch(invalid_argument) {
        cout<<"Exception: invalid argument was thrown"<<endl;
    }
    delete error_code;
    cout<<endl;
}

void mult_by_value_test() {
    cout<<"Test for multiplication by value: "<<endl;
    int* error_code;
    error_code = new int();
    cout<<"Matrix: "<<endl;
    CMatrix<float> matrix(6, 1, error_code);
    matrix.set_value_at(0, 0, 4.5f, error_code);
    matrix.set_value_at(1, 0, 0.9f, error_code);
    matrix.set_value_at(2, 0, -3.4f, error_code);
    matrix.set_value_at(3, 0, 1.9f, error_code);
    matrix.set_value_at(4, 0, 0.2f, error_code);
    matrix.set_value_at(5, 0, -8.7f, error_code);
    matrix.print_matrix();
    int value = 2;
    cout<<"Result = Matrix * value(2) "<<endl;
    CMatrix<float> result(2, 1, error_code);
    result = matrix * value;
    result.print_matrix();
    /*
    4.5              9
    0.9            1.8
    -3.4  *  2 =  -6.8
    1.9            3.8
    0.2            0.4
    -8.7         -17.4
     */
}

void scalar_product_correct_test() {
    int* error_code;
    error_code = new int();
    cout<<"Scalar product: Matrix * Matrix_2: "<<endl;
    cout<<"Matrix: "<<endl;
    CMatrix<float> matrix(6, 1, error_code);
    matrix.set_value_at(0, 0, 4.5f, error_code);
    matrix.set_value_at(1, 0, 0.9f, error_code);
    matrix.set_value_at(2, 0, -3.4f, error_code);
    matrix.set_value_at(3, 0, 1.9f, error_code);
    matrix.set_value_at(4, 0, 0.2f, error_code);
    matrix.set_value_at(5, 0, -8.7f, error_code);
    matrix.print_matrix();
    cout<<"Matrix_2: "<<endl;
    CMatrix<float> matrix_2(6, 1, error_code);
    matrix_2.set_value_at(0, 0, -4.5f, error_code);
    matrix_2.set_value_at(1, 0, -0.9f, error_code);
    matrix_2.set_value_at(2, 0, -3.4f, error_code);
    matrix_2.set_value_at(3, 0, -1.9f, error_code);
    matrix_2.set_value_at(4, 0, -0.2f, error_code);
    matrix_2.set_value_at(5, 0, -8.7f, error_code);
    matrix_2.print_matrix();
    float result = matrix.scalar_product(matrix_2, error_code);
    cout<<"Result: "<<result<<endl;
    cout<<endl;
    delete error_code;
    /*
     4.5     -4.5
     0.9     -0.9
    -3.4  *  -3.4  = 62.54
     1.9     -1.9
     0.2     -0.2
    -8.7     -8.7
     */
}

void scalar_product_incorrect_test() {
    int* error_code;
    error_code = new int();
    cout<<"Scalar product: Matrix * Matrix_2: "<<endl;
    cout<<"Matrix: "<<endl;
    CMatrix<float> matrix(6, 2, error_code);
    matrix.print_matrix();
    cout<<"Matrix_2: "<<endl;
    CMatrix<float> matrix_2(1, 1, error_code);
    matrix_2.print_matrix();
    float result = matrix.scalar_product(matrix_2, error_code);
    if(*error_code == MATRIX_CORRECT) {
        cout<<"Result: "<<result<<endl;
    } else {
        cout<<"There was appeared a error: "<<*error_code<<endl;
    }
    cout<<endl;
    delete error_code;
}

void column_vector_correct_test() {
    int* error_code;
    error_code = new int();
    CMatrix<float> matrix(3, 6, error_code);
    const char *file_name = "int_matrix.txt";
    matrix.read_matrix_from_file(file_name, error_code);
    if(*error_code == MATRIX_CORRECT) {
        cout<<"After reading the file: "<<endl;
        matrix.print_matrix();
    } else cout<<"The operation failed. Error code: "<<*error_code<<endl;
    cout<<endl;
    cout<<"Creating vector from choosing the column: "<<endl;
    cout<<"(Column 1) "<<endl;
    CMatrix<float> column_vector = matrix.create_column_vector(1, error_code);
    column_vector.print_matrix();
    delete error_code;
    cout<<endl;
    /*
    1     2 3123 4    5    6
    9 11231    2 3 4123    6
    5     6  723 8    9 9900

     Should return:
         2
     11231
         6
     */
}

void column_vector_incorrect_test() {
    int* error_code;
    error_code = new int();
    CMatrix<float> matrix(3, 6, error_code);
    const char *file_name = "int_matrix.txt";
    matrix.read_matrix_from_file(file_name, error_code);
    if(*error_code == MATRIX_CORRECT) {
        cout<<"After reading the file: "<<endl;
        matrix.print_matrix();
    } else cout<<"The operation failed. Error code: "<<*error_code<<endl;
    cout<<endl;
    cout<<"Creating vector from choosing the column: "<<endl;
    cout<<"(Column 9) "<<endl;
    CMatrix<float> column_vector = matrix.create_column_vector(9, error_code);
    if(*error_code == MATRIX_CORRECT) {
        column_vector.print_matrix();
    } else cout<<"The operation failed. Error code: "<<*error_code<<endl;
    delete error_code;
    cout<<endl;
}

void row_vector_correct_test() {
    int* error_code;
    error_code = new int();
    CMatrix<int> matrix(3, 6, error_code);
    const char *file_name = "int_matrix.txt";
    matrix.read_matrix_from_file(file_name, error_code);
    if(*error_code == MATRIX_CORRECT) {
        cout<<"After reading the file: "<<endl;
        matrix.print_matrix();
    } else cout<<"The operation failed. Error code: "<<*error_code<<endl;
    cout<<endl;
    cout<<"Creating vector from choosing the column: "<<endl;
    cout<<"(Row 1) "<<endl;
    CMatrix<int> row_vector = matrix.create_row_vector(1, error_code);
    if(*error_code == MATRIX_CORRECT) {
        row_vector.print_matrix();
    } else cout<<"The operation failed. Error code: "<<*error_code<<endl;
    delete error_code;
    cout<<endl;
    /*
    1     2 3123 4    5    6
    9 11231    2 3 4123    6
    5     6  723 8    9 9900

     Should return:
     9 11231 2 3 4123 6
     */
}

void row_vector_incorrect_test() {
    int* error_code;
    error_code = new int();
    CMatrix<int> matrix(3, 6, error_code);
    const char *file_name = "int_matrix.txt";
    matrix.read_matrix_from_file(file_name, error_code);
    if(*error_code == MATRIX_CORRECT) {
        cout<<"After reading the file: "<<endl;
        matrix.print_matrix();
    } else cout<<"The operation failed. Error code: "<<*error_code<<endl;
    cout<<endl;
    cout<<"Creating vector from choosing the column: "<<endl;
    cout<<"(Row 9) "<<endl;
    CMatrix<int> row_vector = matrix.create_row_vector(9, error_code);
    if(*error_code == MATRIX_CORRECT) {
        row_vector.print_matrix();
    } else cout<<"The operation failed. Error code: "<<*error_code<<endl;
    delete error_code;
    cout<<endl;
}

void change_identity_matrix_test() {
    int* error_code;
    error_code = new int();
    CMatrix<int> matrix(3, 6, error_code);
    const char *file_name = "int_matrix_2.txt";
    matrix.read_matrix_from_file(file_name, error_code);
    if(*error_code == MATRIX_CORRECT) {
        cout<<"After reading the file: "<<endl;
        matrix.print_matrix();
        matrix.create_identity_matrix_from_square_matrix(error_code);
        matrix.print_matrix();
    } else cout<<"The operation failed. Error code: "<<*error_code<<endl;
    delete error_code;
    cout<<endl;
}

void create_matrix_test() {
    int* error_code;
    error_code = new int();
    CMatrix<double> matrix_1(4,6, error_code);
    int code = 0;
    matrix_1.create_matrix(4, -2, &code);
    if(code != MATRIX_CORRECT) cout<<"Matrix wasn't created by incorrect size input."<<endl;
    else matrix_1.print_matrix();
}

void read_and_add_three_matrix_test() {
    int *error_code;
    error_code = new int();
    CMatrix<int> matrix;
    const char *file_name = "few_matrix.txt";
    vector<CMatrix<int>> vector_matrix = matrix.read_matrices_from_file(file_name, error_code);
    if (*error_code == MATRIX_CORRECT) {
        cout << "After reading the file: " << endl;
        for(int i = 0; i < vector_matrix.size(); i++) {

            cout<<"Current matrix: "<<endl;
            matrix.print_matrix();
            cout<<"Matrix to add: "<<endl;
            vector_matrix[i].print_matrix();
            matrix = matrix + vector_matrix[i];
            cout<<"Current result: "<<endl;
            matrix.print_matrix();
        }
    } else cout << "The operation failed. Error code: " << *error_code << endl;
    delete error_code;
    cout << endl;
}

void read_matrix_from_file() {
    int* error_code;
    error_code = new int();
    CMatrix<double> matrix(3, 6, error_code);
    const char *file_name = "double_matrix.txt";
    matrix.read_matrix_from_file(file_name, error_code);
    if(*error_code == MATRIX_CORRECT) {
        cout<<"After reading the file: "<<endl;
        matrix.print_matrix();
    } else cout<<"The operation failed. Error code: "<<*error_code<<endl;
    delete error_code;
    cout<<endl;
}

void det_double_test() {
    cout<<"Test of det function for floats: "<<endl;
    int* error_code;
    error_code = new int();
    CMatrix<double> matrix(3, error_code);
    cout<<"Matrix: "<<endl;
    matrix.set_value_at(0, 0, 1.1, error_code);
    matrix.set_value_at(0,1, 1.2, error_code);
    matrix.set_value_at(0, 2, 1.3, error_code);
    matrix.set_value_at(1, 0, 1.4, error_code);
    matrix.set_value_at(1, 1, 1.5, error_code);
    matrix.set_value_at(1, 2, 1.6, error_code);
    matrix.set_value_at(2, 0, 1.7, error_code);
    matrix.set_value_at(2, 1, 1.8, error_code);
    matrix.set_value_at(2, 2, 1.9, error_code);
    matrix.print_matrix();
    double value = matrix.det(error_code);
    cout<<"Determinant of our matrix is equal: "<<value<<endl;
    delete error_code;
}

void det_int_test() {
    int* error_code;
    error_code = new int();
    CMatrix<int> matrix(5, error_code);
    cout<<"Matrix: "<<endl;
    const char *file_name = "int_matrix_5x5.txt";
    matrix.read_matrix_from_file(file_name, error_code);
    if(*error_code == MATRIX_CORRECT) {
        cout<<"After reading the file: "<<endl;
        matrix.print_matrix();
    } else cout<<"The operation failed. Error code: "<<*error_code<<endl;
    int value = matrix.det(error_code);
    cout<<"Determinant of our matrix is equal: "<<value<<endl;
    delete error_code;
}

