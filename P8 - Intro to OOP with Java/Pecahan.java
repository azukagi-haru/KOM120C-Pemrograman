import java.util.Scanner;
import java.math.BigInteger;    // untuk menghitung GCD

public class Pecahan {
    private int a, b, c;
    private void simplify() {   // menyederhanakan pecahan
        this.a = this.a + this.b/this.c;
        this.b = this.b % this.c;
        int gcd = BigInteger.valueOf(this.b).gcd(BigInteger.valueOf(this.c)).intValue();
        this.b = this.b/gcd;
        this.c = this.c/gcd;
    }

    public void Pecahan() { a=0; b=0; c=1; }    // c=1 karena pembagian dengan 0 tidak bisa
    public void set(int x, int y, int z) { a=x; b=y; c=z; simplify(); }
    public void add(Pecahan other) {
        this.a = this.a + other.a;
        this.b = this.b*other.c + other.b*this.c;
        this.c = this.c*other.c;
        simplify();
    }
    public void mul(Pecahan other) {
        this.a = 0;
        this.b = ((this.a*this.c) + this.b) * ((other.a*other.c) + other.b);
        this.c = this.c * other.c;
        simplify();
    }
    public void inc() { this.a++; }
    public void dec() { this.a--; }
    public void print() {   // mencetak pecahan sesuai format
        if (this.b == 0) { System.out.println(this.a); }
        else if (this.a == 0) { System.out.println(this.b + "/" + this.c); }
        else { System.out.println(this.a + " " + this.b + "/" + this.c); }
    }

    // MAIN CODE
    public static void main(String[] args) {
        Pecahan frac = new Pecahan(); String input;
        Scanner scanner = new Scanner(System.in);
        int a,b,c;

        while (true) {
            input = scanner.next();
            if (input.equals("set")) {
                a = scanner.nextInt();
                b = scanner.nextInt();
                c = scanner.nextInt();
                frac.set(a,b,c);
            }
            else if (input.equals("p")) { frac.print(); }
            else if (input.equals("add")) {
                a = scanner.nextInt();
                b = scanner.nextInt();
                c = scanner.nextInt();
                Pecahan temp = new Pecahan(); temp.set(a,b,c);
                frac.add(temp);
            }
            else if (input.equals("mul")) {
                a = scanner.nextInt();
                b = scanner.nextInt();
                c = scanner.nextInt();
                Pecahan temp = new Pecahan(); temp.set(a,b,c);
                frac.mul(temp);
            }
            else if (input.equals("inc")) { frac.inc(); }
            else if (input.equals("dec")) { frac.dec(); }
            else if (input.equals("end")) { break; }
            else { continue; }
        }

        scanner.close();
    }
}