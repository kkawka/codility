// solution 100% - 100% corr and 100% perf

#include <algorithm>
#include <vector>

using std::vector;

void calcDiv(const vector<int> &sortedA, const vector<int> &dVec, vector<int> &nonDiv)
{
    int size = sortedA.size();
    for (auto it = sortedA.begin(); it != sortedA.end(); ++it)
    { 
        unsigned int result = 0;
        int num = *it; 
        result += size - dVec[num]; 
        nonDiv[num] = result;
    }
}

void fillDivVec(const vector<int> &sortedA, vector<int> &dVec)
{
    for (auto it = sortedA.begin(); it != sortedA.end();)
    {
        int repeats = 1;
        int num = *it;
        int size = dVec.size();
        auto next = it + 1;
        while ( next != sortedA.end() && *next == num )
        {
            ++repeats;
            ++next; 
        }

        for (unsigned int j = 1; num*j < size; ++j)
        {
            dVec[num*j] += repeats;
        }
        it = next;
    } 
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

vector<int> solution(vector<int> &A)
{
    vector<int> sortedfA(A);
    vector<int> result;
    vector<int> dVec(2*A.size() + 1, 0);  
    vector<int> nonDiv(2*A.size() + 1, 0); 

    std::sort (sortedfA.begin(), sortedfA.end());

    fillDivVec(sortedfA, dVec);
    //printVec(dVec);

    calcDiv(sortedfA, dVec, nonDiv); 
    for (auto it = A.begin(); it != A.end(); ++it)
    {
        result.push_back(nonDiv[*it]);   
    }
    return result;
}



int main()
{
    vector<int> A = {2};
    vector<int> B = {1,1,1,1};
    vector<int> C = {3,3,3,3};
    vector<int> D = {1,1,1,5,6};
    vector<int> E = {3,1,2,3,6};
    vector<int> F = {8,7,6,5,4,3,2,1};
    vector<int> massive; 
    vector<int> same; 

    for (int i = 1; i < 50000; ++i)
    {
        massive.push_back(i);
        same.push_back(47);
    }  


 /*   printVec(A);
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
*/

    for (int i = 0; i < 20; ++i)
    {
        printf("%d%%\n",i*5);
        solution(massive);
        solution(same);
    }
}


