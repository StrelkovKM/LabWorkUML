#pragma once

#include "ClassTString.h"
#include "ClassTError.h"

#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;


template <class T>
class TObject
{
protected:
  TString name = " ";
  TString type = " ";
  int transparent = 0;
  bool filling = false;
  int color = 0;
  TString title = " ";
  TString signature = " ";
public:
  ~TObject();

  TString GetName();
  TString GetType();
  int GetTransparent();
  bool GetFilling();
  int GetColor();
  TString GetTitle();
  TString GetSignature();

  void SetName(TString name_);
  void SetType(TString type_);
  void SetTransparent(int transparent_);
  void SetFilling(bool filling_);
  virtual void SetColor(int color_);
  void SetTitle(TString title_);
  void SetSignature(TString signature_);

  virtual T Characteristic() = 0;
};

template<class T>
inline TObject<T>::~TObject()
{
}

template<class T>
void TObject<T>::SetName(TString name_)
{
  name = name_;
}

template<class T>
void TObject<T>::SetType(TString type_)
{
  type = type_;
}

template<class T>
inline void TObject<T>::SetTransparent(int transparent_)
{
  if (transparent_ < 0 || transparent_>100)
    throw TError("transparent_ < 0% || transparent_ > 100%", __func__, __FILE__, __LINE__);
  transparent = transparent_;
}

template<class T>
void TObject<T>::SetFilling(bool filling_)
{
  filling = filling_;
}

template<class T>
inline void TObject<T>::SetColor(int color_)
{
  if (color_ < 0 || color_>255)
    throw TError("color_ < 0 || color_ > 255", __func__, __FILE__, __LINE__);
  color = color_;
}

template<class T>
void TObject<T>::SetTitle(TString title_)
{
  title = title_;
}

template<class T>
void TObject<T>::SetSignature(TString signature_)
{
  signature = signature_;
}

template<class T>
TString TObject<T>::GetName()
{
  return name;
}

template<class T>
TString TObject<T>::GetType()
{
  return type;
}

template<class T>
int TObject<T>::GetTransparent()
{
  return transparent;
}

template<class T>
bool TObject<T>::GetFilling()
{
  return filling;
}

template<class T>
int TObject<T>::GetColor()
{
  return color;
}

template<class T>
TString TObject<T>::GetTitle()
{
  return title;
}

template<class T>
TString TObject<T>::GetSignature()
{
  return signature;
}
