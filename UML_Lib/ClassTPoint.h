#pragma once
#include "ClassTObject.h"


template<class T, int DIM>
class TPoint : public TObject<T>
{
protected:
  T coordinates[DIM];
  int size;
public:
  TPoint();
  TPoint(T* coordinates_, int color_, int size_);
  virtual ~TPoint();

  int GetDim();
  int GetSize();

  void SetSize(int size_);

  T& operator[](int index);

  double DistToOrigin();
  double DistTo(TPoint<T, DIM>& obj);

  T Characteristic();

  template<class I, int DIM>
  friend istream& operator>>(istream& input, TPoint<I, DIM>& obj);

  template<class O, int DIM>
  friend ostream& operator<<(ostream& output, TPoint<O, DIM>& obj);
};

template<class T, int DIM>
inline TPoint<T, DIM>::TPoint()
{
  TString type_("Point");
  SetType(type_);
  size = 1;
  for (int i = 0; i < DIM; ++i)
    coordinates[i] = 0;
}

template<class T, int DIM>
inline TPoint<T, DIM>::TPoint(T* coordinates_, int color_, int size_)
{
  TString type_("Point");
  SetType(type_);
  if (size_ <= 0)
    throw TError("size_ <= 0", __func__, __FILE__, __LINE__);
  try
  {
    T a = coordinates_[DIM - 1];
  }
  catch (...)
  {
    throw TError("Indexes error", __func__, __FILE__, __LINE__);
  }
  size = size_;
  for (int i = 0; i < DIM; ++i)
    coordinates[i] = coordinates_[i];
}

template<class T, int DIM>
inline TPoint<T, DIM>::~TPoint()
{
}

template<class T, int DIM>
inline int TPoint<T, DIM>::GetDim()
{
  return DIM;
}

template<class T, int DIM>
inline int TPoint<T, DIM>::GetSize()
{
  return size;
}


template<class T, int DIM>
inline void TPoint<T, DIM>::SetSize(int size_)
{
  if (size_ <= 0)
    throw TError("size_ <= 0", __func__, __FILE__, __LINE__);
  size = size_;
}

template<class T, int DIM>
inline T& TPoint<T, DIM>::operator[](int index)
{
  if (index >= DIM)
    throw TError("index >= DIM", __func__, __FILE__, __LINE__);
  return coordinates[index];
}

template<class T, int DIM>
inline double TPoint<T, DIM>::DistToOrigin()
{
  T res = 0;
  for (int i = 0; i < DIM; ++i)
    res += coordinates[i] * coordinates[i];
  return pow(res, 0.5);
}

template<class T, int DIM>
inline double TPoint<T, DIM>::DistTo(TPoint<T, DIM>& p)
{
  T res = 0;
  for (int i = 0; i < DIM; ++i)
    res += (coordinates[i] - p[i]) * (coordinates[i] - p[i]);
  return pow(res, 0.5);
}

template<class T, int DIM>
T TPoint<T, DIM>::Characteristic()
{
  return T();
}

template<class I, int DIM>
inline istream& operator>>(istream& input, TPoint<I, DIM>& obj)
{
  cout << "Enter the name of point: "; input >> obj.name;
  cout << "Enter the size of point: "; input >> obj.size;
  cout << "Enter the color of point: "; input >> obj.color;
  cout << "Enter the transparent of point: "; input >> obj.transparent;
  cout << "Enter dimension of point: " << DIM << "\n";
  for (int i = 0; i < DIM; ++i)
  {
    cout << "p[" << i << "] = ";
    input >> obj.coordinates[i];
  }
  cout << "Enter the title of point: "; input >> obj.title;
  cout << "Enter the signature of point: "; input >> obj.signature;
  cout << "Enter the filling of point: "; input >> obj.filling;

  return input;
}

template<class O, int DIM>
inline ostream& operator<<(ostream& output, TPoint<O, DIM>& obj)
{
  output
    << "Name: " << obj.GetName() << "\n"
    << "Type: " << obj.GetType() << "\n"
    << "Size: " << obj.GetSize() << "\n"
    << "Coordinates: (";

  for (int i = 0; i < DIM - 1; ++i)
    output << obj[i] << "; ";
  output << obj[DIM - 1] << ")" << "\n";

  output 
    << "Color: " << obj.GetColor() << "\n"
    << "Transparent: " << obj.GetTransparent() << "%" << "\n"
    << "Title: " << obj.GetTitle() << "\n"
    << "Signature: " << obj.GetSignature() << "\n"
    << "Filling: " << obj.GetFilling() << "\n";
  return output;
}

