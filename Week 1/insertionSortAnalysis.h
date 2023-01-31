//
// Created by magzu on 01.02.2023.
//

using namespace std;

int runningTime(vector<int> arr) {
    int counter = 0;
    for(int i = 1; i < arr.size(); i++){
        for(int j = i; j>0 && arr[j-1] > arr[j]; j--){
            counter++;
            int tmp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=tmp;
        }
    }
    return counter;
}

#ifndef ALGO_DS_INSERTIONSORTANALYSIS_H
#define ALGO_DS_INSERTIONSORTANALYSIS_H

#endif //ALGO_DS_INSERTIONSORTANALYSIS_H
