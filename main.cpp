#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    int chance = 0,win = 0,lose = 0,x;
    char ans;
    while (true)
    {
        cout << "需要玩游戏吗（Y/N）？" << endl;
        cin >> ans;
        if (ans == 'Y')
        {
            ++chance;
            srand(int(time(NULL)));
            int i = 0, randnum[3] = {-1,-2,-3};
            while (i < 3)      //generate 3 random numbers
            {
                x = rand();
                randnum[i] = x%10;
                if (randnum[0] != randnum[1] && randnum[1] != randnum[2] && randnum[0] != randnum[2])   //3 different numbers
                    ++i;
            }
            int flag = 0;    //flag is used for judging whether the user get the correct answer
            for (int times=1;times <=7;++times)
            {
                cout << "请输入你猜测的数字:";
                int inputnum[3] = {0,0,0},A=0,B=0;
                cin >> inputnum[0] >> inputnum[1] >> inputnum[2];      //input the user's answer
                for (int t = 0;t<3;++t)     //search for the same number
                {
                    for (int s=0;s<3;++s)
                    {if (inputnum[t]==randnum[s])
                            {if(s==t) ++A;
                             else ++B;}}
                }
                if (A == 3)
                {flag = 1;cout << "恭喜，你猜对了" << endl;
                    ++win;
                    break;}
                else cout << A << 'A' << B << 'B' << endl;
            }
            if (flag == 0)
            {cout << "很遗憾，你没有在规定次数内猜对。答案是 " << randnum[0] << randnum[1] << randnum[2] << endl;
                ++lose;}
        }
        else
        {cout << "你一共玩了" << chance << "局，赢了" << win << "局，输了" << lose << "局" << endl;
            return 0;}
    }
}
