#include <iostream>
#include <stack>

using namespace std;

int max_area(int arr[],int n){
	stack<int> s;
	int max_ar = 0;
	int tp,area_with_top;
	int i=0;
	while(i<n){
        if(s.empty() || arr[s.top()]<=arr[i]){
            cout<<"push "<<i<<" "<<arr[i]<<" i \n";
            s.push(i++);
        }
        else{
            tp = s.top();
            cout<<"tp "<<tp<<"\n";
            s.pop();
            if(!s.empty())
            cout<<s.top()<<" top "<<arr[s.top()]<<" \n";
            area_with_top = arr[tp]*(s.empty()?i:i-s.top()-1);
            cout<<area_with_top<<" ar_top "<<i<<" i\n";
            if(max_ar<area_with_top){
                max_ar = area_with_top;
            }
        }
	}
	while(!s.empty()){
        tp = s.top();
        cout<<"tp "<<tp<<"\n";
        s.pop();
        area_with_top = arr[tp]*(s.empty()?i:i-s.top()-1);
        cout<<area_with_top<<" ar_top \n";
        if(max_ar<area_with_top)
            max_ar = area_with_top;
	}
	return max_ar;
}

int main(){
	int hist[] = {6, 2, 5, 4, 5, 1, 6};
	int n = sizeof(hist)/sizeof(hist[0]);
	cout<<max_area(hist,n);
	return 0;
}
