
import java.util.*;

class Main {
    private static int size;

    static class Team implements Comparable<Team> {
        char teamName;
        int[] rank = new int[size];

        public Team(char teamName) {
            this.teamName = teamName;

        }

        @Override
        public int compareTo(Team t2) {
            int idx = 0;
            while (idx < size && this.rank[idx] == t2.rank[idx]) {
                idx++;
            }
            if (idx == size) {
                return Character.compare(this.teamName, t2.teamName);
            }
            return t2.rank[idx] - this.rank[idx];
        }
    }

    public static String rankTeams(String[] votes) {
        PriorityQueue<Team> pq = new PriorityQueue<>();
        Map<Character, Team> map = new HashMap<>();
        size = votes[0].length();
        for (String str : votes) {

            for (int i = 0; i < size; i++) {
                char teamName = str.charAt(i);

                Team team = map.getOrDefault(
                        teamName,
                        new Team(teamName));

                team.rank[i]++;

                map.put(teamName, team);
            }
        }
        for (Character key : map.keySet()) {
            Team t = map.get(key);
            pq.add(t);
        }
        StringBuilder result = new StringBuilder("");
        while (!pq.isEmpty()) {
            Team t = pq.poll();
            result.append(t.teamName);
        }
        return result.toString();
    }

    public static void main(String[] args) {
        // String votes[] = {"ABC", "ACB", "ABC", "ACB", "ACB"};
        String votes[] = { "WXYZ", "XYZW" };
        System.out.println(rankTeams(votes));

    }
}
