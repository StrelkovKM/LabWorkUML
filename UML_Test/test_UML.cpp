#include <iostream>
#include <gtest.h>
#include "ClassTVector.h"

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