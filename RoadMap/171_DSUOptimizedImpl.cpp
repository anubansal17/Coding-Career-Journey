/*Complete the functions below*/
int find(int a[],int x)
{
    if(a[x] == x){
        return x;
    }
    return a[x] = find(a, a[x]);
}
void unionSet(int a[],int x,int z)
{
    int parX = find(a, x);
    int parZ = find(a, z);
    if(rank[parX] > rank[parZ]) {
        a[parZ] = parX;
    } else if(rank[parZ] > rank[parX]) {
        a[parX] = parZ;
    } else{
        rank[parX] ++;
        a[parZ] = parX;
    }
    a[parX] = parZ;
}
