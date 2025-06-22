#include<iostream>
using namespace std;

int main()
{
  cout << "Pattern 1" << endl;
  for(int row = 1; row <= 5; row++){
    for(int col = 1; col <= 5; col++){
      cout << row << " " ;
    }
    cout << endl;
  }
  
  cout << endl;
  cout << "Pattern 2" << endl;
  for(int row = 1; row <= 5; row++){
    for(int col = 1; col <= 5; col++){
      cout << col << " " ;
    }
    cout << endl;
  }
 
  cout << endl;
  cout << "Pattern 3" << endl;
  for(int row = 1; row <= 5; row++){
    for(int col = 5; col >= 1; col--){
      cout << col << " " ;
    }
    cout << endl;
  }

  cout << endl;
  cout << "Pattern 4" << endl;
  for(int row = 1; row <= 5; row++){
    for(int col = 1; col <= 5; col++){
      cout << col*col << " " ;
    }
    cout << endl;
  }

  cout << endl;
  cout << "Pattern 5" << endl;
  char ch = 'a';
  for(int row = 1; row <= 5; row++){
    for(int col = 1; col <= 5; col++){
      cout << ch << " " ;
      ch++;
    }
    cout << endl;
  }

  cout << endl;
  cout << "Pattern 6" << endl;
  for(int row = 1; row <=5 ; row++){
    char a = 'a'+(row-1);
    for(int col = 1; col <= 5; col++){
      cout << a << " " ;
    }
    cout << endl;
  }
  
  cout << endl;
  cout << "Pattern 7" << endl;
  for(int row = 1; row <=5 ; row++){
    for(char a = 'a'; a <= 'e'; a++){
      cout << a << " " ;
    }
    cout << endl;
  }

  cout << endl;
  cout << "Pattern 8" << endl;
  int n = 1;
  for(int row = 1; row <= 5 ; row++){
    for(int col = 1; col <= 5; col++){
      cout << n << " " ;
      n++;
    }
    cout << endl;
  }

  cout << endl;
  cout << "Pattern 9" << endl;
  for(int row = 1; row <= 5 ; row++){
    for(int col = 1; col <= row; col++){
      cout << "* " ;
    }
    cout << endl;
  }

  cout << endl;
  cout << "Pattern 10" << endl;
  for(int row = 1; row <= 5 ; row++){
    for(int col = 1; col <= row; col++){
      cout << col << " " ;
    }
    cout << endl;
  }

  cout << endl;
  cout << "Pattern 11" << endl;
  for(int row = 1; row <= 5 ; row++){
    for(int col = 1; col <= row; col++){
      cout << row << " " ;
    }
    cout << endl;
  }

  cout << endl;
  cout << "Pattern 12" << endl;
  for(int row = 1; row <= 5 ; row++){
    for(int col = row; col >= 1; col--){
      cout << col << " " ;
    }
    cout << endl;
  }

  cout << endl;
  cout << "Pattern 13" << endl;
  for(int row = 1; row <= 5 ; row++){
    for(char col = 1; col <= row; col++){
      char name = 'a'+row-1;
      cout << name << " " ;
    }
    cout << endl;
  }

  cout << endl;
  cout << "Pattern 14" << endl;
  for(int row = 1; row <= 5 ; row++){
    for(int col = 1; col <= 5-row; col++){
      cout <<"  ";
    }
    for(int col = 1; col <= row; col++){
      cout << "* " ;
    }
    cout << endl;
  }

  cout << endl;
  cout << "Pattern 15" << endl;
  for(int row = 1; row <= 5 ; row++){
    for(int col = 1; col <= 5-row; col++){
      cout <<" ";
    }
    for(int col = 1; col <= row; col++){
      cout << row ;
    }
    cout << endl;
  }

  cout << endl;
  cout << "Pattern 16" << endl;
  for(int row = 1; row <= 5 ; row++){
    for(int col = 1; col <= 5-row; col++){
      cout <<" ";
    }
    for(int col = 1; col <= row; col++){
      cout << col ;
    }
    cout << endl;
  }

  cout << endl;
  cout << "Pattern 17" << endl;
  for(int row = 1; row <= 5; row++){
    for(int col = 1; col <= 5-row; col++){
      cout << "  ";
    }
    for(int col =1; col <= (row*2)-1; col++){
      cout <<"* ";
    }
    cout <<endl;
  }

  cout << endl;
  cout << "Pattern 18" << endl;
  for(int row = 1; row <= 5; row++){
    for(int col = 1; col <= 5-row; col++){
      cout <<"  ";
    }
    for(int col = 1; col <= row; col++){
      cout << col << " ";
    }
    for(int col = row-1; col >= 1; col--){
      cout << col <<" ";
    }
    cout << endl;
  }

  cout << endl;
  cout << "Pattern 19" << endl;
  for(int row = 5; row >= 1; row--){
    for(int col = 1; col <= 5-row; col++){
      cout <<"  ";
    }
    for(int col = 1; col <= 2*row-1 ; col++){
      cout << "* ";
    }
    cout << endl;
  }


  cout << endl;
  cout << "Pattern 20" << endl;
  int num = 5;
  for(int row = num; row >=1; row--){
    for(int col = 1; col <= row; col++){
      cout << "* ";
    }
    for(int col = 1; col <= 2*num-2*row; col++){
      cout << "  ";
    }
    for(int col = 1; col <= row; col++){
      cout << "* ";
    }
    cout << endl;
  }
  for(int row = 1; row <= num; row++){
    for(int col = 1; col <= row; col++){
      cout << "* ";
    }
    for(int col = 1; col <= 2*num-2*row; col++){
      cout << "  ";
    }
    for(int col = 1; col <= row; col++){
      cout << "* ";
    }
    cout << endl;
  }
}