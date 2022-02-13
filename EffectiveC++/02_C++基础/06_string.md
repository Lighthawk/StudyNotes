# string

- #include <string>

- ```c++
  string str;
  
  // 单行输入
  cin >> str;
  
  // 整行输入
  getline(cin, str);				// 读入整行
  getline(cin, str, ',');			// 读入整行时，已何种字符作为字符串结束标记
  									 //（不是读入一整行，按第三个参数分割成多段）
  ```

  