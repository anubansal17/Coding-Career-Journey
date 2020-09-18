public class UniqueSubSets {
    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> op = AllSubsets(new int[]{1,2,2},3);

        for(ArrayList<Integer> lst : op){
            for(Integer i : lst){
                System.out.print(i+" ");
            }
            System.out.println();
        }
    }
    public static ArrayList <ArrayList<Integer>> AllSubsets(int arr[], int n){

        HashSet<String> op = new HashSet<String>();
        String in= "";
        for(int i : arr){
            in+=i;
        }
        subsetUtil(op, new String(), in);

        HashSet<ArrayList<Integer>> output = new HashSet<>();
        for(String s : op){
            char[] c = s.toCharArray();
            ArrayList<Integer> tmp = new ArrayList<>();
            if(c.length != 0)
                for(char cr : c){
                    tmp.add(cr-'0');
                }
            output.add(tmp);
        }
        return new ArrayList<ArrayList<Integer>>(output);
    }

    static void subsetUtil(HashSet<String> op , String out, String in){
        if(in.equals("")){
            op.add(out);

            return;
        }

        subsetUtil(op, out + in.charAt(0), in.substring(1));
        subsetUtil(op, out, in.substring(1));
    }
}
