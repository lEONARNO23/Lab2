// ConsoleApplication.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

double f(float x)
{
    return exp(x) / sqrt(x * x + 3);
}

/*
double f(float x)
{
    return 1 / log(x);
}
*/

float RectangleMethod(int n, float a, float b)
{
    float h = (b - a) / n, sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += f(a + i * h + (h / 2)) * h;
    }

    return sum;
}

float RectangleMethod(float a, float b, float eps, int& iters)
{
    float n0 = 5, n1 = n0 * 2, res0, res1;

    iters = 0;

    do
    {
        res0 = RectangleMethod(n0, a, b);
        res1 = RectangleMethod(n1, a, b);
        n0 *= 2;
        n1 *= 2;
        iters++;
    } while (abs(res1 - res0) > eps);

    return res1;
}

int main()
{
    int iters;
    float res = RectangleMethod(0.4, 1.2, 0.0001, iters);

    std::cout << res;
    std::cout << "\n";
    std::cout << iters;
    std::cout << "\n";
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
