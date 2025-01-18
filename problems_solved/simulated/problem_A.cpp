#include <iostream>
#include <vector>
using namespace std;


class problem_A {
public:
    int alternatedSum(vector<int> n){
        int s=0, aux=1;

        for(int i=0; i<n.size(); i++){
            s+=(n[i]*aux);
            aux*=-1;
        }

        return s;
    }

};

int main()
{
    problem_A problemA;
    vector<int> n;
    int input, qnt;
    cin >> qnt;
    for(int i =0; i<qnt; i++){
        cin >> input;
        n.push_back(input);
    }

    // Calling the print() method
    // of class main
    int s = problemA.alternatedSum(n);
    cout<< s <<"\n";
}
