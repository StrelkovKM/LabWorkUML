#include "ClassTObject.h"
#include "ClassTPoint.h"
#include "ClassTVector.h"
#include "ClassTLine.h"
#include "ClassTString.h"

template<class T>
void TypeOfObj(TObject<T>& a)
{
	cout << a.GetType() << " ";
}

int main()
{
	TVector<int> M;
	TPoint<int, 3> N;
	TLine<int, 3> T;
	TypeOfObj(M);
	TypeOfObj(N);
	TypeOfObj(T);
}