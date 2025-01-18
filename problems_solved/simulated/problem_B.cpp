#include <iostream>
#include <vector>
using namespace std;


class problem_B {
public:
    void gameWords(string s){
        int size = s.size();
        for(int i =0; i<size/2; i++){
            if(s[i] != s[size-1 - i]){
                cout << "Não" <<"\n";
                return;
            }
        }

        cout << "Sim" <<"\n";
    }

};

int main()
{
    problem_B problemB;
    string s;
    cin >> s;

    problemB.gameWords(s);
}
