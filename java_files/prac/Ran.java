import java.util.*;


public class RandomizedSet {
    private HashSet<Integer> set;
    public RandomizedSet() {
        set = new HashSet<>();
    }
    public boolean insert(int val) {
        if(set.contains(val)) {
            return false;
        }
        set.add(val);
    }
    public boolean remove(int val) {
        if(set.contains(val)) {
            set.remove(val);
            return true;
        }
        return false;
    }
    public int getRandom() {
        if(set.size() == 0) {
            throw new Exception("Empty Set");
        }
        
    }
}
public class Random {
    
    public static void main(String[] args) {
        
    }
}