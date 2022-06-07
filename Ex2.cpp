#include <iostream>

using namespace std;

template<class CharT, class Traits>
basic_ostream<CharT, Traits>& endll(basic_ostream<CharT, Traits>& ostr)
{
    ostr.put(ostr.widen('\n'));
    ostr.put(ostr.widen('\n'));
    ostr.flush();

    return ostr;
}

int main()
{
    cout << "Тест" << endll;
    cout << "Тест2" << endll;
    return 0;
}
