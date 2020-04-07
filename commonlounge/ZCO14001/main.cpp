#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,H;
    cin>>N>>H;
    int stack[N];
    for(int i=0; i<N;i++) cin>>stack[i];
    vector<int> commands;
    int temp;
    do{
        cin>>temp;
        commands.push_back(temp);
    }while(temp);
    bool picked_box = false;
    int i=0,position=0;
    while(commands[i]){
        switch(commands[i]){
            case 1:
                if(position)    position--;
                break;
            case 2:
                if(position != N-1)    position++;
                break;
            case 3:
                if(!picked_box && stack[position]){
                    stack[position]--; picked_box = true;
                }
                break;
            case 4:
                if(picked_box && stack[position]<H){
                    stack[position]++; picked_box=false;
                }
                break;
        }
        i++;
    }
    for(int i=0; i<N;i++){
        cout << stack[i]<< " ";
    }
    return 0;
}