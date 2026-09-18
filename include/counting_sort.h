#pragma once

#include <iostream>
#include <string>
#include "language.h"
using namespace std;

// 计数排序用到的全局数组
int a[100000000];

// 计数排序函数
void ji_shu_pai_xu()
{
    if(g_lang == 1)
        cout << "    Enter number of sequences: ";
    else if(g_lang == 2)
        cout << "    数列の個数を入力してください：";
    else if(g_lang == 3)
        cout << "    請輸入數列的個數：";
    else
        cout << "    请输入数列的个数：";
    int p;
    string ps;
    cin >> ps;
    try
    {
        p = stoi(ps);
    }
    catch(...)
    {
        if(g_lang == 1)
            cout << "    Invalid input! Back to menu.\n";
        else if(g_lang == 2)
            cout << "    入力が無効です。メニューに戻ります。\n";
        else if(g_lang == 3)
            cout << "    輸入無效！返回選單。\n";
        else
            cout << "    输入无效！返回主菜单。\n";
        return;
    }

    // 本轮开始，清空整个计数数组
    for(int i = 0; i < 100000000; i++)
        a[i] = 0;

    // 循环处理每一个独立数列
    for (int i = 1; i <= p; i++)
    {
        if(g_lang == 1)
            cout << "\n      Sequence #" << i << ":";
        else if(g_lang == 2)
            cout << "\n      " << i << "番目の数列：";
        else if(g_lang == 3)
            cout << "\n      第" << i << "個數列：";
        else
            cout << "\n      第" << i << "个数列：";
        int n;
        if(g_lang == 1)
            cout << "\n        Enter sequence length: ";
        else if(g_lang == 2)
            cout << "\n        数列の長さを入力してください：";
        else if(g_lang == 3)
            cout << "\n        請輸入數列的長度：";
        else
            cout << "\n        请输入数列的长度: ";
        string ns;
        cin >> ns;
        try
        {
            n = stoi(ns);
        }
        catch(...)
        {
            if(g_lang == 1)
                cout << "        Invalid input! Back to menu.\n";
            else if(g_lang == 2)
                cout << "        入力が無効です。メニューに戻ります。\n";
            else if(g_lang == 3)
                cout << "        輸入無效！返回選單。\n";
            else
                cout << "        输入无效！返回主菜单。\n";
            return;
        }

        // 读取数列所有数字，统计频次
        for (int j = 1; j <= n; j++)
        {
            int x;
            if(g_lang == 1)
                cout << "          Enter number #" << j << ": ";
            else if(g_lang == 2)
                cout << "          数列の" << j << "番目の数字を入力してください：";
            else if(g_lang == 3)
                cout << "          請輸入數列中的第" << j << "個數字：";
            else
                cout << "          请输入数列中的第" << j << "个数字: ";
            string xs;
            cin >> xs;
            try
            {
                x = stoi(xs);
            }
            catch(...)
            {
                if(g_lang == 1)
                    cout << "          Invalid input! Back to menu.\n";
                else if(g_lang == 2)
                    cout << "          入力が無効です。メニューに戻ります。\n";
                else if(g_lang == 3)
                    cout << "          輸入無效！返回選單。\n";
                else
                    cout << "          输入无效！返回主菜单。\n";
                return;
            }
            if(x < 0 || x >= 100000000)
            {
                if(g_lang == 1)
                    cout << "          Number out of range (0~99999999)! Back to menu.\n";
                else if(g_lang == 2)
                    cout << "          数値が範囲外です（0〜99999999）。メニューに戻ります。\n";
                else if(g_lang == 3)
                    cout << "          數字超出範圍（0~99999999）！返回選單。\n";
                else
                    cout << "          数字超出范围（0~99999999）！返回主菜单。\n";
                return;
            }
            a[x]++;
        }

        // 按计数输出排序后的结果
        if(g_lang == 1)
            cout << "        Sorted sequence: ";
        else if(g_lang == 2)
            cout << "        並べ替え後の数列：";
        else if(g_lang == 3)
            cout << "        排序後的數列：";
        else
            cout << "        排序后的数列：";
        for (int j = 0; j < 100000000; j++)
            for(int k = 0; k < a[j]; k++)
                cout << j << ' ';
        // 当前数列处理完成，清空数组，防止污染下一组数据
        for (int &x : a)
            x = 0;
        cout << '\n';
    }
}
