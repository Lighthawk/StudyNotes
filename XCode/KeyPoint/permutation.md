```shell
do {
            cout << arr[0] << arr[1] << arr[2] << arr[3] << endl;
            if (judge(arr)) {
                found = true;
                break;
            }
        } while(prev_permutation(arr.begin(), arr.end()));
        
        next_permutation(arr.begin(), arr.end());
```