import java.util.HashMap;
import java.util.Map;

public class TwoSum {
    public static int[] findMatches(int[] array, int targetSum) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < array.length; i++) {
            map.put(array[i], i);
        }
        for (int i = 0; i < array.length; i++) {
            if(map.containsKey(targetSum - array[i])){
                return new int[] {i, map.get(targetSum - array[i])};
            } 
        }
        throw new IllegalArgumentException("No Match found");
    }
}
