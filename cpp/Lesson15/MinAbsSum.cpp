// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++11 
    if (A.size() == 0)
    {
        return 0;
    }
    
    vector<int> flags(201,0);
    vector<int> result(201,0);
    vector<int> nextV(201,0);
    
    result[abs(A.front())] = 1;
    
    for (unsigned i = 1; i < A.size(); ++i)
    {
        int num = A[i];
        for (int j = 0; j < 200; ++j)
        {
            if (result[j] > 0)
            {
                int n1 = abs(num - j);
                int n2 = abs(num + j);
                if (n1 < 201)
                {
                    nextV[n1] = 1;
                }
                if (n2 < 201)
                {
                    nextV[n2] = 1;
                }
            }        
        }
        result = nextV;
        nextV = flags;
    }
    
    for (unsigned i = 0; i < 101; ++i)
    {
        if (result[i] > 0)
        {
            return i;
        }
    }
    return 0;
}   

int main()
{

 vector <int> A = {18,  99,  -50,  100,  4,  18,  99,  -50,  100,  4,  18,  99,  -50,  100,  4,  18,  99,  -50,  100,  4};
 
  solution(A);
  return 0; 
}

//16  -61  94  85  -7  33  -57  -56  -43  39  -58  95  -86  -62  -83  54  -27  -6  -35  28  -19  -59  -14  -39  -78  65  36  33  77  -21  -24  -15  -19  34  -99  -7  7  -31  -96  41  -99  13  -70  -94  -64  -87  -70  37  46  -28  31  -5  0  76  -38  74  38  37  -99  -84  -94  -31  90  76  68  -77  41  55  62  59  -72  -65  59  48  79  -11  78  -72  92  77  -33  -87  10  38  -30  -89  -44  65  -82  88  -50  -59  -78  97  81  -36  -81  31  78  -98 
