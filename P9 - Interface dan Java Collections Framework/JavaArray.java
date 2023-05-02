import java.util.Scanner;
import java.util.ArrayList;
import java.text.DecimalFormat;

public class JavaArray {

    private ArrayList<Integer> list = new ArrayList<Integer>();

    public void JavaArray() { list.clear(); }
    public void add(int n) { list.add(n); }
    public void removeAtPosition(int n) { list.remove(n-1); }
    public int getSize() { return list.size(); }
    public double getAverage() {
        int sum = 0;
        for (int i=0; i<list.size(); i++) { sum += list.get(i); }
        return (sum*1.0 / list.size());
    }

    // MAIN CODE
    public static void main(String[] args) {

        // Inisialisasi
        JavaArray list = new JavaArray();
        Scanner scanner = new Scanner(System.in);
        int size1, size2; double rataan1, rataan2;

        int num = scanner.nextInt();
        while (num != -9) {
            list.add(num);
            num = scanner.nextInt();
        }

        // Jumlah dan rataan awal
        size1 = list.getSize();
        rataan1 = list.getAverage();

        // Remove element dari array (berdasarkan posisi, bukan index)
        int removed = 0;
        num = scanner.nextInt();
        while (num != -9) {
            list.removeAtPosition(num-removed);
            removed++;
            num = scanner.nextInt();
        }

        // Jumlah dan rataan akhir
        size2 = list.getSize();
        rataan2 = list.getAverage();
        
        // Print output
        System.out.println(size1 + " " + size2);
        System.out.println(rataan1 + " " + rataan2);
    }
    
}