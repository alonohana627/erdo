#include "erdo.h"
#include <gtest/gtest.h>
// TODO: constructor and move tests.
TEST(MatrixTest, DefaultConstructor) {
  using namespace erdo;

  // Default constructor should create a matrix with all elements set to zero
  Matrix<int, 2, 3> mat;
  Matrix<int, 2, 3> expected_mat{{{0, 0, 0}, {0, 0, 0}}};
  EXPECT_EQ(mat, expected_mat);
}

TEST(MatrixTest, VectorConstructor) {
  using namespace erdo;

  // Vector constructor should initialize the matrix with the given values
  std::vector<std::vector<int>> input_mat = {{1, 2, 3}, {4, 5, 6}};
  Matrix<int, 2, 3> mat(input_mat);
  EXPECT_EQ(mat, input_mat);
}

TEST(MatrixTest, ValueConstructor) {
  using namespace erdo;

  // Value constructor should create a matrix with all elements set to the given
  // value
  Matrix<int, 2, 3> mat(42);
  Matrix<int, 2, 3> expected_mat{{{42, 42, 42}, {42, 42, 42}}};
  EXPECT_EQ(mat, expected_mat);
}

TEST(MatrixTest, CopyAssignment) {
  using namespace erdo;

  // Copy assignment operator should copy the elements from the source matrix
  Matrix<int, 2, 3> mat1{{{1, 2, 3}, {4, 5, 6}}};
  Matrix<int, 2, 3> mat2;
  mat2 = mat1;
  EXPECT_EQ(mat1, mat2);
}

TEST(MatrixTest, MoveAssignment) {
  using namespace erdo;

  // Move assignment operator should move the elements from the source matrix
  Matrix<int, 2, 3> mat1{{{1, 2, 3}, {4, 5, 6}}};
  Matrix<int, 2, 3> mat2{{{7, 8, 9}, {10, 11, 12}}};
  mat2 = std::move(mat1);
  EXPECT_EQ(mat2, (Matrix<int, 2, 3>{{{1, 2, 3}, {4, 5, 6}}}));
}

// Access Operator [] Test
TEST(MatrixTest, AccessOperatorTest) {
  erdo::Matrix<double, 3, 3> matrix{};
  matrix[0][1] = 2.0;

  EXPECT_EQ(matrix[0][0], 0.0);
  EXPECT_EQ(matrix[0][1], 2.0);
}

TEST(MatrixTest, MultiplicationResult) {
  using namespace erdo;
  // Define the matrices for testing
  Matrix<int, 2, 3> mat1 = {{{1, 2, 3}, {4, 5, 6}}};
  Matrix<int, 3, 4> mat2{{{7, 8, 9, 10}, {11, 12, 13, 14}, {15, 16, 17, 18}}};

  // Define the expected result of matrix multiplication
  Matrix<int, 2, 4> expected_result{{{74, 80, 86, 92}, {173, 188, 203, 218}}};

  // Perform the matrix multiplication
  Matrix<int, 2, 4> result = mat1 * mat2;

  // Check if the result matches the expected result
  EXPECT_EQ(result, expected_result);
}

TEST(MatrixTest, Addition) {
  using namespace erdo;
  // Test matrix addition using the + operator
  Matrix<int, 2, 3> mat1 = {{{1, 2, 3}, {4, 5, 6}}};
  Matrix<int, 2, 3> mat2 = {{{7, 8, 9}, {10, 11, 12}}};
  Matrix<int, 2, 3> expected_result = {{{8, 10, 12}, {14, 16, 18}}};

  Matrix<int, 2, 3> result = mat1 + mat2;
  EXPECT_EQ(result, expected_result);
}

TEST(MatrixTest, Subtraction) {
  using namespace erdo;
  // Test matrix subtraction using the - operator
  Matrix<int, 2, 3> mat1 = {{{1, 2, 3}, {4, 5, 6}}};
  Matrix<int, 2, 3> mat2 = {{{7, 8, 9}, {10, 11, 12}}};
  Matrix<int, 2, 3> expected_result = {{{-6, -6, -6}, {-6, -6, -6}}};

  Matrix<int, 2, 3> result = mat1 - mat2;
  EXPECT_EQ(result, expected_result);
}

TEST(MatrixTest, ScalarMultiplication) {
  using namespace erdo;
  // Test scalar multiplication using the * operator
  Matrix<int, 2, 3> mat = {{{1, 2, 3}, {4, 5, 6}}};
  int scalar = 2;
  Matrix<int, 2, 3> expected_result = {{{2, 4, 6}, {8, 10, 12}}};

  Matrix<int, 2, 3> result = mat * scalar;
  EXPECT_EQ(result, expected_result);
}

int main(int argc, char *argv[]) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
