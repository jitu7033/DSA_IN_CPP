public class priorityQueue{

	private integer[]pq;
	private int n;

	priorityQueue(int capacity){
		this.pq = new Integer[capacity+1];
	}

	public void insert(int x){
		this.pq[++n] = x;
		swim(n);
	}

	public Integer delMax(){
		int max = this.pq[1];
		exch(1,n--);
		sink(1);
		this.pq[n+1]= null;
		return max;
	}

	public boolean isEmpty(){
		return this.n==0;
	}

	public Integer size(){
		return this.n;
	}

	private void swim(int k){
		while(k > 1 && this.pq[k/2] < this.pq[k]){
			this.exch(k,k/2);
			k = k/2;
		}
	}

	private void sink(int k){
		while(2*k <= n){
			int j = 2*k;
			if(j < n && this.pq[j] < this.pq[j+1]) j++;
			if(this.pq[k] >= this.pq[j]) break;
			exch(k,j);
			k = j;
		}
	}

	private void exch(int i, int j){
		int temp = pq[i];
		pq[i] = pq[j];
		pq[j] = temp;
	}
	
	public static void main(String[]args){

	}
}