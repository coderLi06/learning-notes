import java.util.ArrayList;

public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型ArrayList
     * @return long长整型
     */
    public long calArray(ArrayList<Integer> nums) {
        // write code here
        if (nums.size() <= 1)
            return 0;
        int[] arr = new int[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            arr[i] = nums.get(i);
        }
        return smallSum(arr, 0, arr.length - 1);
    }

    public static long smallSum(int[] arr, int l, int r){
        if(l >= r) return 0;
        int m = (l + r) / 2;
        return smallSum(arr, l, m) + smallSum(arr, m+1,r)
        +merge(arr, l, m, r);
    }

    public static long merge(int[] arr, int l, int m, int r){
        long ans = 0;
        //功能一：计算小和
        for(int i = l, j = m+1, sum = 0; j <= r; j++){
            while(i <= m && arr[i] <= arr[j]){
                sum += arr[i];
                i++;
            }
            ans += sum;
        }
        //功能二：把arr[l...r]变有序
        int[] help = new int[r-l+1];
        int a = l, b = m+1, k = 0;
        while(a<= m&&b<=r){
            if (arr[a] <= arr[b]) {
                help[k++] = arr[a++];
            } else {
                help[k++] = arr[b++];
            }
        }
        while(a  <= m) help[k++] = arr[a++];
        while(b <= r) help[k++] = arr[b++];
        for(int i = 0; i < r-l+1; i++){
            arr[l+i] = help[i];
        }
        return ans;
    }
}