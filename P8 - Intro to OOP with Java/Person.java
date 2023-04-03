import java.util.Scanner;
import java.util.ArrayList;
import java.text.DecimalFormat;

public class Person {

    private String nama;
    private int usia;
    private int tinggi;
    private double berat;

    public void Person() { nama=""; usia=0; tinggi=0; berat=0.00; }
    public void setPerson(String name, int age, int height, double weight) { nama=name; usia=age; tinggi=height; berat=weight; }
    public String getName() { return nama; }
    public int getAge() { return usia; }
    public int getHeight() { return tinggi; }
    public double getWeight() { return berat; }
    public void print() { System.out.println(this.nama + " " + this.usia); }    // untuk print nama dan usia person

    // MAIN CODE
    public static void main(String[] args) {

        // buat list untuk menampung beberapa Person
        ArrayList<Person> list_person = new ArrayList<Person>();

        // ambil input, buat instance baru dari Person, masukkan ke list
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        String nama; int usia, tinggi; double berat;
        int total_height = 0;
        for (int i=0; i<n; i++) {
            Person temp = new Person();
            nama = scanner.next();
            usia = scanner.nextInt();
            tinggi = scanner.nextInt();
            berat = scanner.nextDouble();
            temp.setPerson(nama,usia,tinggi,berat);
            list_person.add(temp);
            total_height += tinggi;
        }
        
        // untuk menghitung rataan tinggi badan
        // dan juga menghitung jumlah Person yang tingginya diatas rataan
        double avgHeight = total_height*1.0 / list_person.size();
        int totalTallPerson = 0;

        // mencetak nama dan usia masing-masing Person
        // dan juga menghitung total tinggi badan keseluruhan
        for (int i=0; i<list_person.size(); i++) {
            list_person.get(i).print();
            if (list_person.get(i).getHeight() > avgHeight) { totalTallPerson++; }
        }
        
        // untuk formatting agar ada 2 angka di belakang koma untuk rataan
        // print rataan tinggi serta total Person yang tingginya diatas rataan
        DecimalFormat df = new DecimalFormat("0.00");
        String formatted_avgHeight = df.format(avgHeight);
        System.out.println(formatted_avgHeight);
        System.out.println(totalTallPerson);

        // close scanner karena sudah tidak lagi mengambil input dari user
        scanner.close();
    }
}