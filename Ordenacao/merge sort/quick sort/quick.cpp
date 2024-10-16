#include <iostream>
#include <vector>
using namespace std;



int main(){
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    quickSort(v, 0, v.size() - 1);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    
    return 0;
}