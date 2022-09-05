#include<iostream>
using namespace std;

int getPower(int m,int n ){
    /*
    Function returns m to the power n
    using recursion

   */
    if (n ==1){
        // Base Case
        return m;
    }
    else {
        return m * getPower(m,n-1);
         }  
}


int getFactorial(int n){
    /*
    function to generate factoral of n
    using recursion
    */
    if(n==0){
        // Base Case
        return 1;

    }
    else{
        // recursive relation
        return n * getFactorial(n-1);
    }
}


void printCounting(int n){
    if (n==0){
        cout<<n<<" ";
        return ;
    }
    else{
        printCounting(n-1);
        cout<<n<<" ";
        // printCounting(n-1);
    }
}

int getFibonacci(int n){
    /*
    Function to generate fibonacci series upto n elements 
    using recursion
    */

// Base Case

if(n==1){
    return 1;
}    
else if(n==0){
    return 0;
}
else{
    //	Recursive Relation
    return getFibonacci(n-1) + getFibonacci(n-2);
}
}

int climbStairs(int n){
	/*
	Function to find out number of ways we can climb n stairs
	with moving only 1 or 2 stairs at a time
	using Recursion
	*/

// Base Case
if(n<0){
	return 0 ;

}
else if(n==0){
	return 1;
}
else{
	// Recursive Relation
	return climbStairs(n-1) + climbStairs(n-2);
}
}
void numberToText(int n){
	
	if(n==0){
		cout<<"Zero ";
		return;
	}
	else if(n==1){
		cout<<"One ";
		return;
	}
	else if(n==2){
		cout<<"two ";
		return;
	}
	else if(n==3){
		cout<<"three ";
		return;
	}
	else if(n==4){
		cout<<"four ";
		return;
	}
	else if(n==5){
		cout<<"five ";
		return;
	}
	else if(n==6){
		cout<<"six ";
		return;
	}
	else if(n==7){
		cout<<"seven ";
		return;
	}
	else if(n==8){
		cout<<"eight ";
		return;
	}
	else if(n==9){
		cout<<"nine ";
		return;
	}
	else{
		return numberToText(n%10);
	}
	

}





int main(){
    // cout<<getPower(2,10)<<endl;
    // cout<<getFactorial(5);
    // printCounting(5);
    // cout<<getFibonacci(1)<<endl;
	cout<<climbStairs(3);
	cout<<numberToText(10);


    return 0;
}