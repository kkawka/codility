// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
typedef long long int llint;

int solution(vector<int> &A) {
    // write your code in C++11
    auto it1 = A.begin();
    auto it2 = A.end() - 1;
    llint left = abs(static_cast<llint>(*it1));
    llint right = abs(static_cast<llint>(*it2));
    int currAbs=std::max(left,right);
    int result = 1;
    while (it1 <= it2)
    {
        left = abs(static_cast<llint>(*it1));
        if (currAbs == left)
        {
            ++it1;
            continue;
        }
        
        right = abs(static_cast<llint>(*it2));
        if (currAbs == right)
        {
            --it2;
            continue;
        }
        
        if (right < left) 
        {
            currAbs = left;
            ++it1;
        }
        else
        {
            currAbs = right;
            --it2;
        }
        ++result;
    }
    return result;
}

