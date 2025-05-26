constexpr auto BUFF = 256;
#include "ClassTString.h"

TString::TString()
{
  str = new char{ '\0' };
  len = 1;
}

TString::TString(const char* str_)
{
  if ((str_ == nullptr))
    throw "str_ == nullptr";
  {
    len = cstrlen(str_);
    str = new char[len + 1];

    for (int i = 0; i < len; ++i)
      str[i] = str_[i];

    str[len] = '\0';
  }
}

TString::TString(const TString& obj)
{
  len = obj.len;

  if (obj.str != nullptr)
  {
    str = new char[len];
    for (int i = 0; i < len; ++i)
      str[i] = obj.str[i];
  }
  else
    throw ("p.str == nullptr");

  str = new char[len + 1];
  for (int i = 0; i < len; ++i)

    str[i] = obj.str[i];

  str[len] = '\0';
}


TString::TString(TString&& obj) noexcept
{
  len = obj.len;
  str = obj.str;

  obj.str = nullptr;
  obj.len = 0;
}


TString::TString(const char* str_, int len_)
{
  if (len_ <= 0)
    throw ("len_ <= 0");
  if (cstrlen(str_) != len_)
    throw ("strlen(str_) != len_");

  len = len_;
  str = new char[len + 1];

  for (int i = 0; i < len; ++i)
    str[i] = str_[i];

  str[len] = '\0';
}


TString::~TString()
{
  if (str != nullptr) delete[]str;
}


char* TString::GetStr()
{
  if (str != nullptr) return str;
  else return nullptr;
}


int TString::GetLen() const
{
  return len;
}


void TString::SetStr(const char* str_)
{
  delete[] str;
  len = cstrlen(str_);
  str = new char[len + 1] {};
  for (int i = 0; i < len; ++i)
    str[i] = str_[i];

  str[len] = '\0';
}


void TString::SetLen(int len_)
{
  if (len_ <= 0)
    throw "len_ <= 0";
  if (len == len_)
    return;

  //if (len < len_)
  //  throw "len_ <= 0";

  len = len_;
  char* str_ = this->GetStr();
  str = new char[len + 1];

  for (int i = 0; i < len; ++i)
    str[i] = str_[i];

  str[len] = '\0';
}


TString TString::operator+(const TString& obj)
{
  char* nstr = new char[len + obj.len + 1];

  for (int i = 0; i < len; ++i)
    nstr[i] = str[i];
  for (int i = 0; i < obj.len; ++i)
    nstr[i + len] = obj.str[i];

  nstr[len + obj.len] = '\0';

  return TString(nstr);
}


TString TString::operator*(int rep)
{
  if (rep < 0)
    throw "rep <= 0";

  char* buf = new char[len * rep + 1];

  for (int i = 0; i < rep; ++i)
  {
    for (int j = 0; j < len; ++j)
      buf[len * i + j] = str[j];
  }

  buf[len * rep] = '\0';

  return TString(buf);
}


TString TString::operator=(const TString& line)
{
  len = line.len;
  str = new char[len + 1];

  for (int i = 0; i < len; ++i)
    str[i] = line.str[i];

  str[len] = '\0';

  return *this;
}


bool TString::operator==(const TString& line)
{
  if (len != line.len)
    return false;

  bool f = true;

  for (int i = 0; i < len; ++i)
  {
    if (str[i] != line.str[i])
      f = false;
  }

  return f;
}


bool TString::operator!=(const TString& line)
{
  if (len != line.len)
    return true;

  bool f = false;

  for (int i = 0; i < len; ++i)
  {
    if (str[i] != line.str[i])
      f = true;
  }

  return f;
}


bool TString::operator<(const TString& line)
{
  return len < line.len;
}


bool TString::operator>(const TString& line)
{
  return len > line.len;
}


char& TString::operator[](int p)
{
  if (p >= len && p < 0)
    throw "size";
  return str[p];
}


ostream& operator<<(ostream& output, TString& line)
{
  output << line.str;
  return output;
}


istream& operator>>(istream& input, TString& line)
{
  char buf[BUFF];
  input >> buf;
  line.SetStr(buf);

  return input;
}

int cstrlen(const char* str)
{
  int counter = 0;
  if (str == nullptr)
    throw "str == nullptr";
  while (str[counter] != '\0')
    counter++;
  return counter;
}

int TString::FindFirstIndex(const char* word)
{
  int lenW = cstrlen(word);

  if (lenW > len) throw ("lenW > len");

  for (int i = 0; i < len - lenW + 1; i++)
  {
    if (str[i] == word[0])
    {
      if (lenW == 1) return i;

      bool flag = false;

      for (int k = 1; k < lenW; k++)
      {
        if (str[k + i] == word[k]) flag = true;
        else
        {
          flag = false;
          break;
        }
      }

      if (flag == true) return i;
    }
  }

  cout << "Not founded ";
  return -404;
}

int* TString::FindAllInclude(const char* word)
{
  int lenW = cstrlen(word), k = 0;
  int* include = new int[FindCountInclude(word)] {};

  for (int i = 0; i < len - lenW + 1; ++i)
  {
    bool flag = true;

    for (int j = 0; j < lenW; ++j)
    {
      if (str[i + j] == word[j]);
      else
      {
        flag = false;
        break;
      }
    }

    if (flag == true)
    {
      include[k++] = i;
    }
  }

  return include;
}

char** TString::SplitString(const char* word)
{
  int* divider = FindAllInclude(word), countWords{}, k{};

  for (int i = 1; i < FindCountInclude(word); ++i)
    if (divider[i] - divider[i - 1] > 1) countWords++;

  char** split = new char* [countWords];

  for (int i = 1; i < FindCountInclude(word); ++i)
  {
    if (divider[i] - divider[i - 1] > 1)
    {
      split[k] = new char[divider[i] - divider[i - 1]];

      for (int j = divider[i - 1] + 1, f = 0; j < divider[i]; j++, f++)
      {
        split[k][f] = str[j];
        cout << split[k][f];
      }
      split[k++][divider[i] - divider[i - 1]] = '\0';
      cout << " ";
    }
  }
  return split;
}

int TString::FindCountInclude(const char* word)
{
  int lenW = cstrlen(word), k{ 0 };
  for (int i = 0; i < len - lenW + 1; ++i)
  {
    bool flag = true;

    for (int j = 0; j < lenW; ++j)
    {
      if (str[i + j] == word[j]);
      else
      {
        flag = false;
        break;
      }
    }

    if (flag == true)
    {
      k++;
    }
  }
  return k;
}

char TString::FindFreqSymbol()
{
  int* symbols = new int[127] {}, max = 0;
  char res;
  for (int i = 0; i < len; i++)
    symbols[int(str[i])]++;
  for (int i = 33; i <= 127; i++)
  {
    if (max < symbols[i])
    {
      max = symbols[i];
      res = char(i);
    }
  }
  return res;
}

char* TString::StrSingleInclude()
{
  int* symbols = new int[127] {}, counter = 0, k = 0;
  for (int i = 0; i < len; i++)
  {
    symbols[int(str[i])]++;
    if (symbols[int(str[i])] == 1) counter++;
  }

  char* single = new char[counter];

  for (int i = 0; i < 127; ++i)
    if (symbols[i] > 0)
    {
      cout << char(i) << "\n";
      single[k++] = char(i);

    }
  single[counter] = '\0';
  return single;
}

char** TString::CountSymbolInclude()
{
  int* symbols = new int[127] {}, counter = 0, k = 0;
  for (int i = 0; i < len; i++)
  {
    symbols[int(str[i])]++;
    if (symbols[int(str[i])] == 1) counter++;
  }

  char** countSymbols = new char* [counter];
  for (int i = 0; i < 127; ++i)
    if (symbols[i] > 0)
    {
      int copy = symbols[i], check = 0, m = 2;
      while (copy != 0)
      {
        check++;
        copy /= 10;
      }
      copy = symbols[i];

      countSymbols[k] = new char[3 + check] {};

      countSymbols[k][0] = char(i);
      countSymbols[k][1] = '-';
      while (copy != 0)
      {
        countSymbols[k][m++] = '0' + copy % 10;
        copy /= 10;
      }
      countSymbols[k][m] = '\0';

      for (int j = 0; j < m; j++)
        cout << countSymbols[k][j];
      cout << "\n";
      k++;
    }

  return countSymbols;
}