// X87360   INTERSECCIÓ DE LLISTES ORDENADES

#include <iostream>
#include <list>
using namespace std;

void inter(list<int>& uno, const list<int>& dos)
/* Pre: uno = U */
/* Post: uno pasa a ser la interseccion de U y dos */
{
    auto index1{ uno.begin() };
    auto index2{ dos.begin() };

    if (uno.empty() or dos.empty())
    {
        // need to empty uno if one of the list
        // has no elemenets (empty set intersection)
        while (index1 != uno.end())
            index1 = uno.erase(index1);
    }

    for ( ; index1 != uno.end() and index2 != dos.end(); )
    {
        if (*index1 < *index2)
            index1 = uno.erase(index1);
        else if (*index1 > *index2)
            ++index2;
        else
        {
            ++index1;
            ++index2;
        }

        // if it they are equal we keep the element inside "uno" list
    }

    while (index1 != uno.end())
        index1 = uno.erase(index1);
}

#if false
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::list<T>& list_)
{
    for(const auto& objects : list_)
        out << objects << ' ';

    return out;
}

int main(int, char**)
{
    std::list<int> first{ -7, 1, 5, 12 };
    std::list<int> second{ 1, 3, 4, 5 };

    std::cout << first << std::endl;
    std::cout << second << std::endl;

    inter(first, second);
    std::cout << first << std::endl;

    return 0;
}
#endif
