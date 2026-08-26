import java.util.*;

public class Points {
    public static int maxPoints(int[][] points) {
        if(points.length <= 2) {
            return points.length;
        }
        int[] firstPoint = points[0];
        int[] secondPoint = points[1];
        
    }
    public static void main(String[] args) {
        int[][] points1 = {
            {1, 1},
            {2, 2},
            {3, 3}
        };
        int[][] points2 = {
            {1, 1},
            {3, 2},
            {5, 3},
            {4, 1},
            {2, 3},
            {1, 4}
        };

        System.out.println(maxPoints(points1));
        System.out.println(maxPoints(points2));
    }
}