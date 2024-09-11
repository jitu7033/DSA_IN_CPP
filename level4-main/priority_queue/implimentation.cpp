#include<bits/stdc++.h>
using namespace std;

class prority_queue{
	private:
		int n;
		vector<int>pq;
		void exch(int i, int j){
			int temp = pq[i];
			pq[i] = pq[j];
			pq[j] = temp;
		}
		void swim(int k){
			while(k > 1 && this->pq[k/2] < this->pq[k]){
				exch(k,k/2);
				k /= 2;
			}
		}
		void sink(int k){
			while(2*k <= n){ // is this atleast one child are left 
				int j = 2*k;
				if(j < n && this->pq[j] < this->pq[j+1]) j++; // if right child is grater than the left child then shift then right child 
				if(this->pq[k] >= this->pq[j])break;
				exch(k,j);
				k = j;
			}
		}
	public:
		prority_queue(int capacity){
			this->pq = vector<int>(capacity+1);
			this->n = 0;
		}
		void push(int val){
			this->pq[++n] = val;
			swim(n);
		}
		int pop(){
			if(!size()){
				throw std::out_of_range("Priority queue is empty");
			}
			int max = pq[1];
			exch(1,n--);
			sink(1);
			// pq[n+1] = ;
			return max;
		}
		int  peek(){
			if(!size()){
				throw std::out_of_range("Priority queue is empty");
			}
			return pq[1];
		}

		int size(){
			return this->n;
		}

		int empty(){
			if(n==0)return 1;
			return 0;
	    }

	    void print(){
	    	for(int i = 1; i <= n; i++){
	    		cout<<pq[i]<<" ";
	    	}
	    	cout<<endl;
	    }
};

int main(){
	prority_queue pq(5);
	pq.push(10);
	pq.push(1);
	pq.push(11);
	pq.push(100);
	cout<<pq.peek()<<endl;;

	cout<<pq.pop()<<endl;

	pq.print();
	cout<<pq.peek()<<endl;
}
