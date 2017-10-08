#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
bool out=false;
void output(vector<int> r)
{
    cout << "result: (";
    int i = 0;
    for (; i < r.size() - 1; i++)
    {
        cout << r[i] << ',';
    }
    cout << r[i] << ')' << endl;
    out=true;
}
bool find_result(int v, vector<int> bag, int begin, vector<int> result, bool &flag)
{
    if(begin >= bag.size() - 1)
    {
        flag = false;
    }
    while (begin < bag.size())
    {
        int t = 0;
        for (auto k : result)
        {
            t += k;
        }
        t += bag[begin];
        if(t < v)
        {
            result.push_back(bag[begin]);
            if (find_result(v, bag, begin + 1, result, flag))
            {
                if(flag == true)
                {
                    result.pop_back();
                    return find_result(v, bag, begin + 1, result, flag);
                }
                else
                {
                    while(result.back() != bag[begin])
                    {
                        result.pop_back();
                    }
                    result.pop_back();
                    flag = true;
                    return find_result(v, bag, begin + 1, result, flag);
                }
            }
            else
            {
                if(flag == true)
                {
                    return 0;
                }
                else
                {
                    result.pop_back();
                    flag = true;
                    if(result.empty())
                    {
                        begin++;
                        continue;
                    }
                    return find_result(v, bag, begin + 1, result, flag);
                }
            }
        }
        else if(t == v)
        {
            result.push_back(bag[begin]);
            output(result);
            return 1;
        }
        else if(t > v)
        {
            return find_result(v, bag, begin + 1, result, flag);
        }
    }
    return 0;
}
int main()
{
    int v = 0, n = 0;
    cout << "please input bag's capacity: ";
    cin >> v;
    cout << "please input goods' number:";
    cin >> n;
    vector<int> bag;
    int good = 0;
    cout << "please input goods' volume:"<<endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> good;
        bag.push_back(good);
    }
    vector<int> result;
    int begin = 0;
    bool flag = true;
    find_result(v, bag, begin, result, flag);
    if(!out)
    {
        cout << "No result!" << endl;
    }
    system("pause");
    return 0;
}