#include <iostream>
#include <iomanip>
using namespace std;

void InitArray(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 90 + 10;
        }
    }
}
void ShowArray(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(4) << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "===============================" << endl;
}

void FillOneRow(int* arr, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        arr[i] = 1;
    }
}

int** AddFirstRow(int** arr, int& rows, int cols)
{
    int** temp = new int* [rows + 1];

    temp[0] = new int[cols];
    FillOneRow(temp[0], cols);
    for (int i = 0; i < rows + 1; i++)
    {
        temp[i + 1] = arr[i];
    }
    delete[]arr;
    rows++;
    return temp;
}

int** DeleteFirstRow(int** arr, int& rows, int cols)
{
    int** temp = new int* [rows - 1];

    for (int i = 0; i < rows; i++)
    {
        temp[i] = arr[i + 1];
    }
    delete[]arr[0];
    delete[]arr;
    rows--;
    return temp;
}

int** DeleteChosenRow(int** arr, int& rows, int cols, int pos)
{
    int** temp = new int* [rows - 1];

    for (int i = 0; i < pos; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = pos + 1; i < rows; i++)
    {
        temp[i - 1] = arr[i];
    }
    delete[]arr[pos];
    delete[]arr;
    rows--;
    return temp;
}

int** AddColToStart(int** arr, int rows, int& cols)
{
    int** temp = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        temp[i] = new int[cols + 1];
    }
    for (int i = 0; i < rows; i++)
    {
        temp[i][0] = 1;
        for (int j = 0; j < cols; j++)
        {
            temp[i][j + 1] = arr[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        delete[]arr[i];
    }

    delete[]arr;
    cols++;
    return temp;
}

int main()
{
    int rows = 3;
    int cols = 4;
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    InitArray(arr, rows, cols);
    ShowArray(arr, rows, cols);

    arr = AddFirstRow(arr, rows, cols);
    ShowArray(arr, rows, cols);
    arr = AddFirstRow(arr, rows, cols);
    ShowArray(arr, rows, cols);


    arr = DeleteFirstRow(arr, rows, cols);
    ShowArray(arr, rows, cols);

    arr = DeleteChosenRow(arr, rows, cols, 2);
    ShowArray(arr, rows, cols);

    arr = AddColToStart(arr, rows, cols);
    ShowArray(arr, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        delete[]arr[i];
    }

    delete[]arr;
}