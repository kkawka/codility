// solution 77% - 100% corr and 50% perf

#include <algorithm>
#include <map>
#include <set>
#include <vector>

using std::vector;
using std::map;
using std::set;

typedef map<int, int> map_ii;
typedef vector<set<int>> div_vec;

void calcDiv(const vector<int> &sortedA, map_ii &nonDiv)
{
    // so far O(n^2) :/
    for (unsigned int i = 0; i < sortedA.size();)
    {
        unsigned int stepSize = 1; 
        unsigned int result = 0;
        while (i + stepSize < sortedA.size() && 
            sortedA[i + stepSize] == sortedA[i])
        {
            stepSize++;
        }

        for (unsigned int j = 0; j < i; ++j)
        {
            // sortedA[j] is not a sortedA[i] divisor
            if (sortedA[i] % sortedA[j] != 0)
            {
                result++;
            }
        }
        result += sortedA.size() - (i + stepSize); 
        nonDiv[sortedA[i]] = result;
        i += stepSize;
    }
}

vector<int> solution(vector<int> &A)
{
    vector<int> copyOfA(A);
    vector<int> result;
    std::sort (copyOfA.begin(), copyOfA.end());
    map_ii nonDiv; 
    calcDiv(copyOfA, nonDiv); 
    for (auto it = A.begin(); it != A.end(); ++it)
    {
        result.push_back(nonDiv[*it]);   
    }
    return result;
}

void printVec(const vector<int> &A)
{
    printf("[");
    for (auto it = A.begin(); it != A.end(); ++it)
    {
        printf(" %d", *it);
    }
    printf("]\n");
}


int main()
{
    vector<int> A = {2};
    vector<int> B = {1,1,1,1};
    vector<int> C = {3,3,3,3};
    vector<int> D = {1,1,1,5,6};
    vector<int> E = {3,1,2,3,6};
    vector<int> F = {8,7,6,5,4,3,2,1};

    printVec(A);
    printVec(solution(A));
    printVec(B);
    printVec(solution(B));
    printVec(C);
    printVec(solution(C));

    printVec(D);
    printVec(solution(D));
    printVec(E);
    printVec(solution(E));
    printVec(F);
    printVec(solution(F));
}


