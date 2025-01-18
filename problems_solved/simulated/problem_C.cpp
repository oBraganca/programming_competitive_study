#include <iostream>
#include <vector>

using namespace std;

class problem_C{
public:
    int filmFestival(vector<int>ft, int t){
        int f=0, w = 0;

        while(w < t && f < ft.size()){
            w+=ft[f];
            f++;
        }

        if(w > t){
            --f;
        }


        return f;
    }

};

int main(){

    problem_C problemC;
    int n, input, t;
    cin>>n;
    cin>>t;

    vector<int> f;
    for(int i =0; i<n; i++){
        cin >> input;
        f.push_back(input);
    }

    int q = problemC.filmFestival(f, t);
    cout << q << "\n";
    return 0;
}