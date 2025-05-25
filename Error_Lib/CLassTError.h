#pragma once
#include <iostream>
#include <utility>
#include "ClassTString.h"

class TError
{
protected:
  TString error, function, file;
  int line;
public:
  TError(char* error_, char* function_, 
    char* file_, int line_)
  {
    error = error_;
    function = function_;
    file = file_;
    line = line_;
    //message = er + prob + func + prob + fi;
    //cout << "\nError: " << error << "Function: " << function << "File: " << file <<"Line:"<< line << "\n";
  }
};

#define THROW_ERROR(err, ...) throw TError(err, __func__, __FILE__, __LINE__)