class Solution {
    public int[] decimalRepresentation(int n) {
        int count = 0;
        int temp = n;

        while(temp > 0){
            if(temp % 10 != 0){
                count++;
            }
            temp /= 10;
        }

        int result[] = new int[count];
        int index = count-1;
        int place = 1;

        while(n > 0){
            int digit = n % 10;
            if(n % 10 != 0){
                result[index--] = digit * place;
            }
            place = place * 10;
            n = n / 10;
        }
        return result;
    }
}