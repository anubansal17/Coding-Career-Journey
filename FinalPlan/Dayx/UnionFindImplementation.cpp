// Time complexity: O(n) for 1 find query, for n such queries: O(n^2) 
/*Complete the functions below*/
int find(int a[],int x)
{
    if(a[x] != x) {
        a[x] = find(a, a[x]);
    }
    return a[x];
}
void unionSet(int a[],int x,int z)
{
	int par1 = find(a, x);
	int par2 = find(a, z);
	a[par1] = par2;
}
