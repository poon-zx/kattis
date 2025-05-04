import java.io.*;
import java.util.*;

class humancannonball {
    public static void main(String args[]) {
        Kattio kattio = new Kattio(System.in);
        double startX = kattio.getDouble();
        double startY = kattio.getDouble();
        double endX = kattio.getDouble();
        double endY = kattio.getDouble();
        int numCannons = kattio.getInt();
        double[][] cannons = new double[numCannons][2];
        for (int i = 0; i < numCannons; i++) {
            double cannonX = kattio.getDouble();
            double cannonY = kattio.getDouble();
            cannons[i][0] = cannonX;
            cannons[i][1] = cannonY;
        }
        ArrayList<ArrayList<ArrayList<Double>>> adjList = new ArrayList<ArrayList<ArrayList<Double>>>();

        ArrayList<ArrayList<Double>> startList = new ArrayList<ArrayList<Double>>();
        for (int i = 1; i < numCannons + 1; i++) {
            double distance = Math.hypot(cannons[i-1][0] - startX, cannons[i-1][1] - startY) / 5.0;
            startList.add(new ArrayList<Double>(Arrays.asList((double)i, distance)));
        }
        double distance = Math.hypot(endX - startX, endY - startY) / 5.0;
        startList.add(new ArrayList<Double>(Arrays.asList((double)numCannons+1, distance)));
        adjList.add(startList);

        for (int i = 1; i < numCannons+1; i++) {
            ArrayList<ArrayList<Double>> tempList = new ArrayList<ArrayList<Double>>();
            double distanceEnd = Math.abs(Math.hypot(cannons[i-1][0] - endX, cannons[i-1][1] - endY) - 50.0) / 5.0 + 2.0;
            tempList.add(new ArrayList<Double>(Arrays.asList((double)numCannons+1, distanceEnd)));
            for (int j = 1; j < numCannons+1; j++) {
                if (i == j) {
                    continue;
                }
                double distanceTemp = Math.abs(Math.hypot(cannons[i-1][0] - cannons[j-1][0], cannons[i-1][1] - cannons[j-1][1]) - 50.0) / 5.0 + 2.0;
                tempList.add(new ArrayList<Double>(Arrays.asList((double)j, distanceTemp)));
            }
            adjList.add(tempList);
        }
        adjList.add(new ArrayList<ArrayList<Double>>());
        
        ArrayList<Double> D = new ArrayList<Double>();
        D.addAll(Collections.nCopies(numCannons+2, 1000000000.0));
        D.set(0, 0.0);

        for (int i = 0; i < numCannons+1; i++) {
            for (int u = 0; u < numCannons + 2; u++) {
                for (int j = 0; j < adjList.get(u).size(); j++) {
                    ArrayList<Double> v = adjList.get(u).get(j);
                    double temp = v.get(0);
                    relax(u, (int)temp, v.get(1), D);
                }
            }
        }

        kattio.println(D.get(numCannons+1));
        kattio.close();
    }

    static void relax(int u, int v, double w_u_v, ArrayList<Double> D) {
        if (D.get(u) != 1000000000.0 && D.get(v) > D.get(u) + w_u_v) { 
          D.set(v, D.get(u) + w_u_v); 
        }
    }

}
class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
        super(new BufferedOutputStream(System.out));
        r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
        super(new BufferedOutputStream(o));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
        return peekToken() != null;
    }

    public int getInt() {
        return Integer.parseInt(nextToken());
    }

    public double getDouble() {
        return Double.parseDouble(nextToken());
    }

    public long getLong() {
        return Long.parseLong(nextToken());
    }

    public String getWord() {
        return nextToken();
    }

    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null)
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}
