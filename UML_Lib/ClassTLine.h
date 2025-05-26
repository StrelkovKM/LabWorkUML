#pragma once
#include "ClassTPoint.h"

template<class T, int DIM>
class TLine : public TPoint<T, DIM>
{
protected:
  TPoint<T, DIM> begin;
  TPoint<T, DIM> end;
public:
  TLine();
  TLine(T* beginc_, T* endc_, int size_, int color_);
  ~TLine();

  int GetDim();
  int GetSize();

  void SetSize(int size_);

  T Characteristic();

  template<class I, int DIM>
  friend istream& operator>>(istream& input, TLine<I, DIM>& obj);

  template<class O, int DIM>
  friend ostream& operator<<(ostream& output, TLine<O, DIM>& obj);
};

template<class T, int DIM>
inline TLine<T, DIM>::TLine()
{
  type = "Line";
}

template<class T, int DIM>
inline TLine<T, DIM>::TLine(T* beginc_, T* endc_, int size_, int color_)
{
  type = "Line";
  if (size_ <= 0)
    throw TError("size_ <= 0", __func__, __FILE__, __LINE__);
  if (color_ <= 0)
    throw TError("color_ <= 0", __func__, __FILE__, __LINE__);
  try
  {
    T a = beginc_[DIM - 1];
  }
  catch (...)
  {
    throw TError("Indexes of begin error", __func__, __FILE__, __LINE__);
  }
  try
  {
    T a = endc_[DIM - 1];
  }
  catch (...)
  {
    throw TError("Indexes of end error", __func__, __FILE__, __LINE__);
  }

  color = color_;
  begin.SetColor(color);
  end.SetColor(color);

  size = size_;
  begin.SetSize(size);
  end.SetSize(size);

  for (int i = 0; i < DIM; ++i)
  {
    begin[i] = beginc_[i];
    end[i] = endc_[i];
  }
}


template<class T, int DIM>
inline TLine<T, DIM>::~TLine()
{
}

template<class T, int DIM>
inline int TLine<T, DIM>::GetDim()
{
  return DIM;
}

template<class T, int DIM>
inline int TLine<T, DIM>::GetSize()
{
  return size;
}

template<class T, int DIM>
inline void TLine<T, DIM>::SetSize(int size_)
{
  if (size_ <= 0)
    throw TError("size_ <= 0", __func__, __FILE__, __LINE__);
  size = size_;
  begin.SetSize(size);
  end.SetSize(size);
}

template<class T, int DIM>
inline T TLine<T, DIM>::Characteristic()
{
  return begin.DistTo(end);
}

template<class I, int DIM>
inline istream& operator>>(istream& input, TLine<I, DIM>& obj)
{

  cout << "Enter the size of line:" << "\n"; input >> obj.size;
  cout << "Enter the color of line:" << "\n"; input >> obj.color;
  cout << "Enter the transparent of line:" << "\n"; input >> obj.transparent;

  cout << "Dimension of points:" << DIM << "\n";
  for (int i = 0; i < DIM; ++i)
  {
    cout << "begin[" << i << "] = "; input >> obj.begin[i];
  }
  for (int i = 0; i < DIM; ++i)
  {
    cout << "end[" << i << "] = "; input >> obj.end[i];
  }

  cout << "Enter the name of line:" << "\n"; input >> obj.name;
  cout << "Enter the title of line:" << "\n"; input >> obj.title;
  cout << "Enter the signature of line:" << "\n"; input >> obj.signature;
  cout << "Enter the filling of line:" << "\n"; input >> obj.filling;
  return input;
}

template<class O, int DIM>
inline ostream& operator<<(ostream& output, TLine<O, DIM>& obj)
{
  output
    << "Name: " << obj.GetName() << "\n"
    << "Type: " << obj.GetType() << "\n"
    << "Size: " << obj.GetSize() << "\n";

  output << "\nCoordinates of begin: (";
  for (int i = 0; i < DIM - 1; ++i)
    output << obj.begin[i] << "; ";
  output << obj.begin[DIM - 1] << ")\nCoordinates of end: (";
  for (int i = 0; i < DIM - 1; ++i)
    output << obj.end[i] << "; ";
  output << obj.end[DIM - 1] << ")\n";

  output
    << "Color: " << obj.GetColor() << "\n"
    << "Transparent: " << obj.GetTransparent() << "\n"
    << "Title: " << obj.GetTitle() << "\n"
    << "Signature: " << obj.GetSignature() << "\n"
    << "Filling: " << obj.GetFilling() << "\n";

  return output;
}