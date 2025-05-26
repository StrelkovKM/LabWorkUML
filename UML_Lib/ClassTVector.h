#pragma once
#include "ClassTObject.h"

template<class T>
class TVector : public TObject<T>
{
protected:
  int len;
  T* vector;
public:
  TVector();
  TVector(int len_);
  TVector(const TVector& obj);
  TVector(TVector&& obj) noexcept;
  ~TVector();

  int GetLen();
  void GetVector(T** array);

  void SetLen(int len_);
  void SetVector(T* array, int len_);

  void SaveInTxt();

  TVector operator+(const TVector<T>& line);
  TVector operator-(const TVector<T>& line);
  T operator*(const TVector<T>& line);
  TVector operator*(T num);
  TVector operator/(T num);

  TVector& operator=(const TVector<T>& line);
  TVector& operator=(TVector<T>&& line) noexcept;
  bool operator==(const TVector<T>& line);

  T& operator[](int index) const;

  TVector BublleSort();
  TVector QuickSort(int left, int right);
  TVector InsertionSort();

  TVector<T> Normalisation();
  T FirstNorm();
  T SecondNorm();
  T InfinityNorm();
  T HelderNorm();

  T Characteristic();

  template <class O>
  friend ostream& operator<<(ostream& output, TVector<O>& obj);
  template <class I>
  friend istream& operator>>(istream& input, TVector<I>& obj);
};


template<class T>
inline TVector<T>::TVector()
{
  name = " ";
  len = 0;
  vector = nullptr;
  type = "Vector";
}

template<class T>
inline TVector<T>::TVector(int len_)
{
  if (len_ < 0)
    throw TError("len_ < 0", __func__, __FILE__, __LINE__);
  else if (len = 0)
    vector = nullptr;
  else
  {
    len = len_;
    vector = new T[len]{ 0 };
  }
}

template<class T>
inline TVector<T>::TVector(const TVector& obj)
{
  len = obj.len;
  if (len == 0)
    vector = nullptr;
  else
  {
    vector = new T[len];
    for (int i = 0; i < len; ++i)
      vector[i] = obj.vector[i];
  }
}

template<class T>
inline TVector<T>::TVector(TVector&& obj) noexcept
{
  vector = obj.vector;
  len = obj.len;

  obj.len = 0;
  obj.vector = nullptr;
}

template<class T>
inline TVector<T>::~TVector()
{
  if (len != 0)
    delete[] vector;
  vector = nullptr;
  len = 0;
}

template<class T>
inline int TVector<T>::GetLen()
{
  return len;
}

template<class T>
inline void TVector<T>::GetVector(T** array)
{
  (*array) = new T[len];
  for (int i = 0; i < len; ++i)
    *array = vector[i];
}


template<class T>
inline void TVector<T>::SetLen(int len_)
{
  if (len_ < 0)
    throw TError("len_ < 0", __func__, __FILE__, __LINE__);
  else if (len == len_)
    return;
  else if (len_ == 0)
  {
    delete[] vector;
    len = len_;
    vector = nullptr;
  }
  else if (len_ < len)
  {
    TVector reserv = *this;
    delete[] vector;
    len = len_;
    vector = new T[len_];
    for (int i = 0; i < len_; ++i)
      vector[i] = reserv[i];
  }
  else
  {
    TVector reserv = *this;
    delete[] vector;
    vector = new T[len_]{ 0 };
    for (int i = 0; i < len; ++i)
      vector[i] = reserv[i];
    len = len_;
  }

}

template<class T>
inline void TVector<T>::SetVector(T* array, int len_)
{
  if (len_ < 0)
    throw TError("len_ < 0", __func__, __FILE__, __LINE__)
  else if (len_ == 0)
    return;
  else
  {
    for (int i = 0; i < min(len, len_); i++)
      vector[i] = array[i];
  }
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& line)
{
  if (len != line.len)
    throw TError("len != line.len", __func__, __FILE__, __LINE__);
  else if (len == 0)
  {
    return TVector();
  }
  else
  {
    TVector<T> res(len);
    for (int i = 0; i < len; ++i)
      res.vector[i] = vector[i] + line.vector[i];
    return res;
  }
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& line)
{
  if (len != line.len)
    throw TError("len != line.len", __func__, __FILE__, __LINE__);
  else if (len == 0)
  {
    return TVector();
  }
  else
  {
    TVector<T> res(len);
    for (int i = 0; i < len; ++i)
      res.vector[i] = vector[i] - line.vector[i];
    return res;
  }
}


template<class T>
inline TVector<T>& TVector<T>::operator=(TVector<T>&& obj) noexcept
{
  if (this == &obj)
    return *this;

  if (vector != nullptr)
    delete[] vector;

  vector = obj.vector;
  len = obj.len;
  obj.vector = nullptr;
  obj.len = 0;
  return *this;
}

template<class T>
inline T TVector<T>::operator*(const TVector<T>& line)
{
  if (len != line.len)
    throw TError("len != line.len", __func__, __FILE__, __LINE__);
  else if (len == 0)
  {
    return 0;
  }
  else
  {
    T res = 0;
    for (int i = 0; i < len; ++i)
      res += vector[i] * line.vector[i];
    return res;
  }
}

template<class T>
inline TVector<T> TVector<T>::operator*(T num)
{
  if (vector == nullptr)
  {
    return TVector();
  }
  else
  {
    TVector<T> res(len);
    for (int i = 0; i < len; ++i)
      res.vector[i] = vector[i] * num;
    return res;
  }
}

template<class T>
inline TVector<T> TVector<T>::operator/(T num)
{
  if (num == 0) throw TError("vector / 0", __func__, __FILE__, __LINE__);
  if (vector == nullptr)
  {
    return TVector();
  }
  else
  {
    TVector<T> res(len);
    for (int i = 0; i < len; ++i)
      res.vector[i] = vector[i] / num;
    return res;
  }
}
template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& obj)
{
  if (this == &obj)
    return *this;

  if (len != obj.len)
  {
    delete[] vector;
    vector = new T[obj.len];
  }
  len = obj.len;
  for (int i = 0; i < len; i++)
    vector[i] = obj.vector[i];

  return *this;
}

template<class T>
inline T& TVector<T>::operator[](int index) const
{
  if (vector == nullptr)
    throw TError("vector==nullptr", __func__, __FILE__, __LINE__);
  else if (index >= len)
    throw TError("index >= len", __func__, __FILE__, __LINE__);
  else
    return vector[index];
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& line)
{
  if (len != line.len)
    throw("len!=line.len");
  else if (len == 0)
  {
    return true;
  }
  else
  {
    for (int i = 0; i < len; ++i)
    {
      if (vector[i] != line.vector[i])
        return false;
    }
    return true;
  }
}

template<class T>
inline TVector<T> TVector<T>::BublleSort()
{
  if (len == 0)
    throw TError("len == 0", __func__, __FILE__, __LINE__);
  T copy;
  TVector<T> res(*this);
  for (int i = 0; i < len; ++i)
  {
    for (int j = 0; j < (len - 1); ++j)
    {
      if (res[j] > res[j + 1])
      {
        copy = res[j];
        res[j] = res[j + 1];
        res[j + 1] = copy;
      }
    }
  }
  return res;
}

template<class T>
inline TVector<T> TVector<T>::QuickSort(int left, int right)
{
  if (len == 0)
    throw TError("len == 0", __func__, __FILE__, __LINE__);
  TVector<T> res(*this);

  if (left < right)
  {
    T pivot = res[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j)
    {
      while (res[i] < pivot) i++;
      while (res[j] > pivot) j--;

      if (i <= j)
      {
        T reserv = res[i];
        res[i] = res[j];
        res[j] = reserv;
        i++;
        j--;
      }
    }
    if (left < j)
      res = res.QuickSort(left, j);
    if (i < right)
      res = res.QuickSort(i, right);
  }

  return res;
}

template<class T>
inline TVector<T> TVector<T>::InsertionSort()
{
  if (len == 0)
    throw TError("len == 0", __func__, __FILE__, __LINE__);
  TVector res(*this);
  int this_index = 0, last_index = 0;
  T key = 0;
  for (this_index = 1; this_index < res.len; ++this_index)
  {
    key = res[this_index];
    last_index = this_index - 1;

    while (last_index >= 0 && res[last_index] > key)
    {
      res[last_index + 1] = res[last_index];
      --last_index;
    }
    res[last_index + 1] = key;
  }

  return res;
}

template<class T>
inline TVector<T> TVector<T>::Normalisation()
{
  if (len == 0)
    throw TError("len == 0", __func__, __FILE__, __LINE__);
  TVector<T> res(*this);
  return TVector <T>(res / res.InfinityNorm());
}

template<class T>
inline T TVector<T>::FirstNorm()
{
  if (len == 0)
    throw TError("len == 0", __func__, __FILE__, __LINE__);
  T first_norma = 0;
  for (int i = 0; i < len; ++i)
    first_norma += vector[i];
  return first_norma;
}

template<class T>
inline T TVector<T>::SecondNorm()
{
  if (len == 0)
    throw TError("len == 0", __func__, __FILE__, __LINE__);
  T second_norma = 0;
  for (int i = 0; i < len; ++i)
    second_norma += (vector[i] * vector[i]);
  return sqrt(second_norma);
}

template<class T>
inline T TVector<T>::InfinityNorm()
{
  if (len == 0)
    throw TError("len == 0", __func__, __FILE__, __LINE__);
  T maxi = vector[0];
  for (int i = 1; i < len; ++i)
  {
    if (vector[i] > maxi)
      maxi = vector[i];
  }
  return maxi;
}

template<class T>
inline T TVector<T>::HelderNorm()
{
  if (len == 0)
    throw TError("len == 0", __func__, __FILE__, __LINE__);
  T sum = 0;
  for (int i = 0; i < len; ++i)
    sum += pow(vector[i], (double)len);
  return pow(sum, 1 / (double)len);
}

template<class T>
inline T TVector<T>::Characteristic()
{
  return len;
}

template<class O>
inline ostream& operator<<(ostream& output, TVector<O>& obj)
{
  if (obj.vector == nullptr)
    output << "Len of vector: " << obj.len << "\n" << "Vector: []" << "\n";
  else
  {
    output
      << "Name: " << obj.name << "\n"
      << "Type: " << obj.GetType() << "\n";

    output << "Len of vector: " << obj.len << "\n"
      << "Vector: [";
    for (int i = 0; i < obj.len - 1; ++i)
      output << obj.vector[i] << " ";
    output << obj.vector[obj.len - 1] << "]\n";

    output
      << "Color: " << obj.GetColor() << "\n"
      << "Transparent: " << obj.GetTransparent() << "%" << "\n"
      << "Title: " << obj.GetTitle() << "\n"
      << "Signature: " << obj.GetSignature() << "\n"
      << "Filling: " << obj.GetFilling() << "\n";
  }
  return output;
}

template<class I>
inline istream& operator>>(istream& input, TVector<I>& obj)
{
  int l;
  cout << "Enter name of vector: "; input >> obj.name;
  cout << "Enter the len of vector: ";
  input >> l;
  if (l == 0)
  {
    obj.SetLen(l);
    return input;
  }
  else
  {
    obj.SetLen(l);
    for (int k = 0; k < obj.len; ++k)
    {
      cout << "vector[" << k << "] = ";
      input >> obj.vector[k];
    }
    cout << "Enter the color of vector: "; input >> obj.color;
    cout << "Enter the transparent of vector: "; input >> obj.transparent;
    cout << "Enter the title of vector: "; input >> obj.title;
    cout << "Enter the signature of vector: "; input >> obj.signature;
    cout << "Enter the filling of vector: "; input >> obj.filling;
    return input;
  }
}

template<class T>
inline void TVector<T>::SaveInTxt()
{
  string name;
  cout << "Enter name of file: "; cin >> name;

  ofstream outFile;
  outFile.open(name);
  if (!outFile.is_open()) throw TError("File is open", __func__, __FILE__, __LINE__);
  else
  {
    outFile << "len - " << len << "\n" << "[";
    for (int i = 0; i < len - 1; i++) outFile << vector[i] << " ";
    outFile << vector[len - 1] << "]";
  }
  outFile.close();
}