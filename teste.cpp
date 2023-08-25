#include <iostream>

using namespace std;

int main()
{
    int altura = 20, largura = 20;

    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            if (i < altura && j < largura)
            {
                cout << "#";
            }
            if (j == largura - 1)
            {
                cout << endl;
            }
        }
    }

    return 0;
}
