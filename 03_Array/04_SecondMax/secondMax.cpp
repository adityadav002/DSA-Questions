  #include<iostream>
  using namespace std;
  int main()
  {
    int n;
    cout << "Enter Array Size : ";
    cin >> n;
    cout << "Enter Array Elements : " << endl;
    int arr[n];
    for(int i=0; i<n; i++){
      cin >> arr[i];
    }

    int max = 0;
    for(int i =0; i<n; i++){
    if(arr[i] > max){
      max = arr[i];
     }
    }

   int secondMax = 0;
    for(int i =0; i<n; i++){
      if(arr[i] > secondMax && arr[i] != max){
        secondMax = arr[i];
      }
    }
 
   cout << "Second Maximum Element is : " << secondMax << endl;

    return 0;
  }

