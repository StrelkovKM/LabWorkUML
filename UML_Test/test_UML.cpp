#include <iostream>
#include <gtest.h>
#include "ClassTVector.h"
#include "ClassTMatrix.h"



TEST(TMatrix, can_create_matrix_with_nonegative_parametrs)
{
  ASSERT_NO_THROW(TMatrix <double> table(3, 3));
}


TEST(TMatrix, throw_create_matrix_with_negative_strings)
{
  ASSERT_ANY_THROW(TMatrix<double> table(-3, 2));
}


TEST(TMatrix, throw_create_matrix_with_negative_columns)
{
  ASSERT_ANY_THROW(TMatrix<double> table(3, -2));
}


TEST(TMatrix, can_copy)
{
  TMatrix<double> table(2, 3);
  TMatrix<double> tablec(table);
  EXPECT_NEAR(1, table == tablec, 0.000001);
}


TEST(TMatrix, can_get_n)
{
  TMatrix<int> a(2, 3);
  EXPECT_NEAR(2, a.GetRow(), 0.000001);
}


TEST(TMatrix, can_get_m)
{
  TMatrix<int> a(2, 3);
  EXPECT_NEAR(3, a.GetCol(), 0.000001);
}


TEST(TMatrix, can_set_n)
{
  TMatrix<int> s(2, 3);
  s.SetRow(4);
  EXPECT_NEAR(4, s.GetRow(), 0.000001);
}


TEST(TMatrix, throw_set_n)
{
  TMatrix<int> s(2, 3);
  ASSERT_ANY_THROW(s.SetCol(-2));
}


TEST(TMatrix, can_set_m)
{
  TMatrix<int> s(2, 3);
  s.SetCol(4);
  EXPECT_NEAR(4, s.GetCol(), 0.000001);
}


TEST(TMatrix, throw_set_m)
{
  TMatrix<int> s(2, 3);
  ASSERT_ANY_THROW(s.SetCol(-2));
}


TEST(TMatrix, can_add)
{
  TMatrix<int> s(2, 2), u(2, 2), add(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;

  add[0][0] = 6;
  add[0][1] = 8;
  add[1][0] = 10;
  add[1][1] = 6;
  EXPECT_NEAR(1, s + u == add, 0.000001);
}


TEST(TMatrix, throw_add_first_matrix_is_nullptr)
{
  TMatrix<int> s, u(2, 2);
  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;
  ASSERT_ANY_THROW(u + s);
}


TEST(TMatrix, throw_add_second_matrix_is_nullptr)
{
  TMatrix<int> s, u(2, 2);
  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;
  ASSERT_ANY_THROW(s + u);
}


TEST(TMatrix, throw_add_size_error)
{
  TMatrix<int> s(2, 3), u(2, 2);
  ASSERT_ANY_THROW(s + u);
}


TEST(TMatrix, can_sub)
{
  TMatrix<int> s(2, 2), u(2, 2), add(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;

  add[0][0] = -4;
  add[0][1] = -4;
  add[1][0] = -4;
  add[1][1] = -4;
  EXPECT_NEAR(1, s - u == add, 0.000001);
}


TEST(TMatrix, throw_sub_first_matrix_is_nullptr)
{
  TMatrix<int> s, u(2, 2);
  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;
  ASSERT_ANY_THROW(u - s);
}


TEST(TMatrix, throw_sub_second_matrix_is_nullptr)
{
  TMatrix<int> s, u(2, 2);
  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;
  ASSERT_ANY_THROW(s - u);
}


TEST(TMatrix, throw_sub_size_error)
{
  TMatrix<int> s(2, 3), u(2, 2);
  ASSERT_ANY_THROW(s - u);
}


TEST(TMatrix, can_mul_by_matrix)
{
  TMatrix<int> s(2, 2), u(2, 2), add(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;

  add[0][0] = 19;
  add[0][1] = 16;
  add[1][0] = 22;
  add[1][1] = 23;
  EXPECT_NEAR(1, s * u == add, 0.000001);
}


TEST(TMatrix, throw_mul_by_matrix_first_matrix_is_nullptr)
{
  TMatrix<int> s, u(2, 2);
  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;
  ASSERT_ANY_THROW(u * s);
}

TEST(TMatrix, can_div_by_matrix)
{
  TMatrix<double> s(2, 2), u(2, 2), add(2, 2);
  s[0][0] = 1;
  s[0][1] = 3;
  s[1][0] = 2;
  s[1][1] = 4;

  u[0][0] = 1;
  u[0][1] = 3;
  u[1][0] = 2;
  u[1][1] = 4;

  add[0][0] = 1;
  add[0][1] = 0;
  add[1][0] = 0;
  add[1][1] = 1;
  EXPECT_NEAR(1, s / u == add, 0.000001);
}

TEST(TMatrix, throw_mul_by_matrix_second_matrix_is_nullptr)
{
  TMatrix<int> s, u(2, 2);
  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;
  ASSERT_ANY_THROW(s * u);
}


TEST(TMatrix, throw_mul_by_matrix_size_error)
{
  TMatrix<int> s(2, 3), u(2, 2);
  ASSERT_ANY_THROW(s * u);
}


TEST(TMatrix, can_mul_by_num)
{
  TMatrix<int> s(2, 2), add(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  add[0][0] = 3;
  add[0][1] = 6;
  add[1][0] = 9;
  add[1][1] = 3;
  EXPECT_NEAR(1, s * 3 == add, 0.000001);
}


TEST(TMatrix, throw_mul_by_num_matrix_is_nullptr)
{
  TMatrix<int> u;
  ASSERT_ANY_THROW(u * 2);
}


TEST(TMatrix, can_devide_by_num)
{
  TMatrix<int> s(2, 2), add(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  add[0][0] = 3;
  add[0][1] = 6;
  add[1][0] = 9;
  add[1][1] = 3;
  EXPECT_NEAR(1, add / 3 == s, 0.000001);
}


TEST(TMatrix, throw_devide_by_num_matrix_is_nullptr)
{
  TMatrix<int> u;
  ASSERT_ANY_THROW(u / 2);
}


TEST(TMatrix, throw_devide_by_zero)
{
  TMatrix<int> u(2, 2);
  u[0][0] = 5;
  u[0][1] = 6;
  u[1][0] = 7;
  u[1][1] = 5;
  ASSERT_ANY_THROW(u / 0);
}


TEST(TMatrix, can_equip_by_num)
{
  TMatrix<int> s(2, 2), add(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  add[0][0] = 1;
  add[0][1] = 2;
  add[1][0] = 3;
  add[1][1] = 1;
  EXPECT_NEAR(1, add == s, 0.000001);
}


TEST(TMatrix, throw_equip_first_nullptr)
{
  TMatrix<int> s, add(2, 2);

  add[0][0] = 1;
  add[0][1] = 2;
  add[1][0] = 3;
  add[1][1] = 1;
  ASSERT_ANY_THROW(s == add);
}


TEST(TMatrix, throw_equip_second_nullptr)
{
  TMatrix<int> s, add(2, 2);

  add[0][0] = 1;
  add[0][1] = 2;
  add[1][0] = 3;
  add[1][1] = 1;
  ASSERT_ANY_THROW(add == s);
}


TEST(TMatrix, can_equipment)
{
  TMatrix<int> s(2, 2), add;
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;
  add = s;
  EXPECT_NEAR(1, add == s, 0.000001);
}


TEST(TMatrix, can_get_by_index)
{
  TMatrix<int> s(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;
  EXPECT_NEAR(2, s[0][1], 0.000001);
}


TEST(TMatrix, throw_get_index_by_nullptr)
{
  TMatrix<int> s;
  ASSERT_ANY_THROW(s[0]);
}


TEST(TMatrix, throw_get_index_more_than_in_matrix)
{
  TMatrix<int> s(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;
  ASSERT_ANY_THROW(s[3]);
}


TEST(TMatrix, can_transposition)
{
  TMatrix<int> s(2, 2), u(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  u[0][0] = 1;
  u[0][1] = 3;
  u[1][0] = 2;
  u[1][1] = 1;
  EXPECT_NEAR(1, s.Transposition() == u, 0.000001);
}


TEST(TMatrix, throw_transposition_by_nullptr)
{
  TMatrix<int> s;
  ASSERT_ANY_THROW(s.Transposition());
}


TEST(TMatrix, can_get_minor)
{
  TMatrix<int> s(2, 2), u(1, 1);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  u[0][0] = 1;
  EXPECT_NEAR(1, s.Minor(1, 1) == u, 0.000001);
}


TEST(TMatrix, throw_minor_by_nullptr)
{
  TMatrix<int> s;
  ASSERT_ANY_THROW(s.Minor(0, 0));
}


TEST(TMatrix, throw_minor_by_nonquadro)
{
  TMatrix<int> s(2, 5);
  ASSERT_ANY_THROW(s.Minor(0, 0));
}


TEST(TMatrix, can_get_attached)
{
  TMatrix<int> s(2, 2), u(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 4;

  u[0][0] = 4;
  u[0][1] = -3;
  u[1][0] = -2;
  u[1][1] = 1;
  EXPECT_NEAR(1, s.Attached() == u, 0.000001);
}


TEST(TMatrix, throw_attached_by_nullptr)
{
  TMatrix<int> s;
  ASSERT_ANY_THROW(s.Attached());
}


TEST(TMatrix, throw_attached_by_nonquadro)
{
  TMatrix<int> s(2, 5);
  ASSERT_ANY_THROW(s.Attached());
}


TEST(TMatrix, can_get_inverse)
{
  TMatrix<double> s(2, 2), u(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 4;

  u[0][0] = -2;
  u[0][1] = 1;
  u[1][0] = 1.5;
  u[1][1] = -0.5;
  EXPECT_NEAR(1, s.Inverse() == u, 0.000001);
}


TEST(TMatrix, throw_inverse_by_nullptr)
{
  TMatrix<int> s;
  ASSERT_ANY_THROW(s.Inverse());
}


TEST(TMatrix, throw_inverse_by_nonquadro)
{
  TMatrix<int> s(2, 5);
  ASSERT_ANY_THROW(s.Inverse());
}


TEST(TMatrix, throw_inverse_zero)
{
  TMatrix<int> s(2, 2);
  ASSERT_ANY_THROW(s.Inverse());
}


TEST(TMatrix, can_get_Gauss)
{
  TMatrix<double> s(2, 2);
  TVector<double> z(2), r(2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 4;

  z[0] = 1;
  z[1] = 2;

  r[0] = 0;
  r[1] = 0.5;
  EXPECT_NEAR(1, s.Gauss(z) == r, 0.000001);
}


TEST(TMatrix, throw_Gauss_by_nullptr)
{
  TMatrix<double> s;
  TVector<double> z;
  ASSERT_ANY_THROW(s.Gauss(z));
}


TEST(TMatrix, throw_Gauss_by_nonquadro)
{
  TMatrix<double> s(2, 5);
  TVector<double> z(2);
  ASSERT_ANY_THROW(s.Gauss(z));
}


TEST(TMatrix, throw_Gauss_by_nan)
{
  TMatrix<double> s(5, 2);
  TVector<double> z(10);
  ASSERT_ANY_THROW(s.Gauss(z));
}


TEST(TMatrix, throw_Gauss_by_zero)
{
  TMatrix<double> s(2, 2);
  TVector<double> z(2);
  ASSERT_ANY_THROW(s.Gauss(z));
}


TEST(TMatrix, can_get_determinant)
{
  TMatrix<double> s(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 4;
  EXPECT_NEAR(-2, s.Determinant(), 0.000001);
}


TEST(TMatrix, throw_determinant_by_nullptr)
{
  TMatrix<double> s;
  ASSERT_ANY_THROW(s.Determinant());
}


TEST(TMatrix, throw_determinant_by_nonquadro)
{
  TMatrix<double> s(2, 5);
  ASSERT_ANY_THROW(s.Determinant());
}


TEST(TMatrix, can_get_count_of_includes)
{
  TMatrix<double> s(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;
  EXPECT_NEAR(2, s.CountOfIncludes(1), 0.000001);
}


TEST(TMatrix, throw_count_of_includes_by_nullptr)
{
  TMatrix<double> s;
  ASSERT_ANY_THROW(s.CountOfIncludes(2));
}


TEST(TMatrix, can_get_pow)
{
  TMatrix<double> s(2, 2), u(2, 2);
  s[0][0] = 1;
  s[0][1] = 2;
  s[1][0] = 3;
  s[1][1] = 1;

  u[0][0] = 7;
  u[0][1] = 4;
  u[1][0] = 6;
  u[1][1] = 7;

  EXPECT_NEAR(1, s.Pow(2) == u, 0.000001);
}


TEST(TMatrix, throw_pow_by_nullptr)
{
  TMatrix<double> s;
  ASSERT_ANY_THROW(s.Pow(2));
}


TEST(TMatrix, throw_pow_by_nonquadro)
{
  TMatrix<double> s(2, 3);
  ASSERT_ANY_THROW(s.Pow(2));
}


TEST(TVector, can_create_vector_with_positive_len)
{
  ASSERT_NO_THROW(TVector <double> table(3));
}


TEST(TVector, throw_create_vector_with_negative_len)
{
  ASSERT_ANY_THROW(TVector<double> table(-3));
}


TEST(TVector, can_get_len)
{
  TVector<double> s(2);
  EXPECT_NEAR(2, s.GetLen(), 0.000001);
}


TEST(TVector, can_set_len)
{
  TVector<double> s(2);
  s.SetLen(4);
  EXPECT_NEAR(4, s.GetLen(), 0.000001);
}


TEST(TVector, throw_set_negative_len)
{
  TVector<double> s(2);
  ASSERT_ANY_THROW(s.SetLen(-4));
}


TEST(TVector, can_add)
{
  TVector<double> s(2), c(2), res(2);

  s[0] = 1;
  s[1] = 2;

  c[0] = 3;
  c[1] = 4;

  res[0] = 4;
  res[1] = 6;

  EXPECT_NEAR(1, res == c + s, 0.000001);
}


TEST(TVector, throw_add)
{
  TVector<double> s(2), u(3);
  ASSERT_ANY_THROW(s + u);
}


TEST(TVector, can_sub)
{
  TVector<double> s(2), c(2), res(2);

  s[0] = 1;
  s[1] = 2;

  c[0] = 3;
  c[1] = 4;

  res[0] = 2;
  res[1] = 2;

  EXPECT_NEAR(1, res == c - s, 0.000001);
}


TEST(TVector, throw_sub)
{
  TVector<double> s(2), u(3);
  ASSERT_ANY_THROW(s - u);
}


TEST(TVector, can_mul)
{
  TVector<double> s(2), c(2), res(2);

  s[0] = 1;
  s[1] = 2;

  c[0] = 3;
  c[1] = 4;
  EXPECT_NEAR(11, c * s, 0.000001);
}


TEST(TVector, throw_mul)
{
  TVector<double> s(2), u(3);
  ASSERT_ANY_THROW(s * u);
}


TEST(TVector, can_mul_by_num)
{
  TVector<double> s(2), c(2);

  s[0] = 1;
  s[1] = 2;

  c[0] = 2;
  c[1] = 4;
  EXPECT_NEAR(1, c == s * 2, 0.000001);
}


TEST(TVector, can_devide_by_num)
{
  TVector<double> s(2), c(2), res(2);

  s[0] = 2;
  s[1] = 6;

  c[0] = 1;
  c[1] = 3;
  EXPECT_NEAR(1, c == s / 2, 0.000001);
}


TEST(TVector, throw_devide_by_zero)
{
  TVector<double> s(2), u(3);
  ASSERT_ANY_THROW(s / 0);
}


TEST(TVector, can_equipment)
{
  TVector<double> s(2), c(2);

  s[0] = 2;
  s[1] = 6;

  c = s;
  EXPECT_NEAR(1, c == s, 0.000001);
}


TEST(TVector, can_equip)
{
  TVector<double> s(2), c(2);

  s[0] = 2;
  s[1] = 6;

  c[0] = 2;
  c[1] = 6;
  EXPECT_NEAR(1, c == s, 0.000001);
}


TEST(TVector, can_get_by_index)
{
  TVector<double> s(2);

  s[0] = 2;
  s[1] = 6;
  EXPECT_NEAR(6, s[1], 0.000001);
}


TEST(TVector, throw_more_index)
{
  TVector<double> s(2);
  ASSERT_ANY_THROW(s[2]);
}


TEST(TVector, throw_index_by_nullptr)
{
  TVector<double> s;
  ASSERT_ANY_THROW(s[2]);
}


TEST(TVector, can_bubblesort)
{
  TVector<double> s(2), c(2);

  s[0] = 6;
  s[1] = 2;

  c[0] = 2;
  c[1] = 6;
  EXPECT_NEAR(1, s.BublleSort() == c, 0.000001);
}


TEST(TVector, throw_bubblesort)
{
  TVector<double> s;
  ASSERT_ANY_THROW(s.BublleSort());
}


TEST(TVector, can_quicksort)
{
  TVector<double> s(2), c(2);

  s[0] = 6;
  s[1] = 2;

  c[0] = 2;
  c[1] = 6;
  EXPECT_NEAR(1, s.QuickSort(0, 1) == c, 0.000001);
}


TEST(TVector, throw_quicksort)
{
  TVector<double> s;
  ASSERT_ANY_THROW(s.QuickSort(0, 34));
}


TEST(TVector, can_insertsort)
{
  TVector<double> s(2), c(2);
  int flag = 0;
  s[0] = 6;
  s[1] = 2;

  c[0] = 2;
  c[1] = 6;
  if (s.InsertionSort() == c) flag = 1;
  EXPECT_NEAR(1, flag , 0.000001);
}


TEST(TVector, throw_insertsort)
{
  TVector<double> s;
  ASSERT_ANY_THROW(s.InsertionSort());
}


TEST(TVector, can_firstnorm)
{
  TVector<double> s(2);

  s[0] = 6;
  s[1] = 2;
  EXPECT_NEAR(8, s.FirstNorm(), 0.000001);
}


TEST(TVector, throw_firstnorm)
{
  TVector<double> s;
  ASSERT_ANY_THROW(s.FirstNorm());
}


TEST(TVector, can_secondnorm)
{
  TVector<double> s(2);

  s[0] = 4;
  s[1] = 3;
  EXPECT_NEAR(5, s.SecondNorm(), 0.000001);
}


TEST(TVector, throw_secondnorm)
{
  TVector<double> s;
  ASSERT_ANY_THROW(s.FirstNorm());
}


TEST(TVector, can_infinitynorm)
{
  TVector<double> s(2);

  s[0] = 4;
  s[1] = 3;
  EXPECT_NEAR(4, s.InfinityNorm(), 0.000001);
}


TEST(TVector, throw_infinitynorm)
{
  TVector<double> s;
  ASSERT_ANY_THROW(s.InfinityNorm());
}


TEST(TVector, can_heldernorm)
{
  TVector<double> s(2);

  s[0] = 4;
  s[1] = 3;
  EXPECT_NEAR(5, s.HelderNorm(), 0.000001);
}


TEST(TVector, throw_heldernorm)
{
  TVector<double> s;
  ASSERT_ANY_THROW(s.HelderNorm());
}


TEST(TVector, can_normalisation)
{
  TVector<double> s(2), c(2);

  s[0] = 4;
  s[1] = 2;

  c[0] = 1;
  c[1] = 0.5;
  EXPECT_NEAR(1, s.Normalisation() == c, 0.000001);
}


TEST(TVector, throw_normalisation)
{
  TVector<double> s;
  ASSERT_ANY_THROW(s.Normalisation());
}