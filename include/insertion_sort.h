#pragma once

#include <iostream>
#include <string>
#include "language.h"
using namespace std;

// 插入排序函数
void cha_ru_pai_xu()
{
    int arr[1000];
    int num_count = 0;
    int x;

    if(g_lang == 1)
        cout << "  Enter numbers one by one, type n to finish\n";
    else if(g_lang == 2)
        cout << "  数字を1つずつ入力してください。n で終了\n";
    else if(g_lang == 3)
        cout << "  逐個輸入數字，輸入 n 結束當前數列錄入\n";
    else
        cout << "  逐个输入数字，输入 n 结束当前数列录入\n";
    while (true)
    {
        if(g_lang == 1)
            cout << "  Enter number: ";
        else if(g_lang == 2)
            cout << "  数字を入力してください：";
        else if(g_lang == 3)
            cout << "  請輸入數字：";
        else
            cout << "  请输入数字：";
        string xs;
        cin >> xs;
        try
        {
            x = stoi(xs);
            // 插入新数字
            int j;
            for(j = num_count - 1; j >= 0 && arr[j] > x; j--)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = x;
            num_count++;

            // 每输入一个，立刻输出当前有序数列
            if(g_lang == 1)
                cout << "  Current sorted: ";
            else if(g_lang == 2)
                cout << "  現在の並べ替え結果：";
            else if(g_lang == 3)
                cout << "  當前有序數列：";
            else
                cout << "  当前有序数列：";
            for(int i = 0; i < num_count; i++)
            {
                cout << arr[i] << ' ';
            }
            cout << '\n';
        }
        catch(...)
        {
            // 输入 n / N 结束录入；其他字母提示后继续（不崩溃）
            if(xs == "n" || xs == "N")
                break;
            if(g_lang == 1)
                cout << "  Please enter a number, or n to finish\n";
            else if(g_lang == 2)
                cout << "  数字を入力するか、n で終了してください\n";
            else if(g_lang == 3)
                cout << "  請輸入數字，或輸入 n 結束\n";
            else
                cout << "  请输入数字，或输入 n 结束\n";
        }
    }

    // 输出最终排序结果
    if(g_lang == 1)
        cout << "  Final sorted sequence: ";
    else if(g_lang == 2)
        cout << "  最終的な並べ替え結果：";
    else if(g_lang == 3)
        cout << "  最終排序後的數列：";
    else
        cout << "  最终排序后的数列：";
    for(int j = 0; j < num_count; j++)
    {
        cout << arr[j] << ' ';
    }
    cout << '\n';
}
