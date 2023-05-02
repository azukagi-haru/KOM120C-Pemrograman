import java.util.*;

// Class untuk pasangan x, y (titik)
// Implementasi "Comparable" supaya ter-sort ketika masuk set
class Titik implements Comparable<Titik> {
	private int x;
	private int y;

	public Titik(int a, int b) {
		this.x = a;
		this.y = b;
	}

	public int getX() { return x; }
	public int getY() { return y; }

	// Override karena kita meng-override method compareTo() dari Comparable
	// Titik yang sama, cuma satu yang masuk set (no duplicate)
	// Compare sedemikian sehingga yang kanan atas urutannya lebih duluan
	@Override
	public int compareTo(Titik other) {
		if ((this.x == other.x) && (this.y == other.y)) return 0;									// return 0 -> gak masuk set
		else if ( (this.x > other.x) || ((this.x == other.x) && (this.y > other.y)) ) return -1;	// return -1 -> urutannya duluan
        else return 1;																				// return 1 -> urutannya belakangan
	}
}

// Class untuk kumpulan titik
public class Hotspot {
	Set<Titik> koordinat = new TreeSet<>();
	
	public void Hotspot() { koordinat.clear(); }
	public void add(int a, int b) { koordinat.add(new Titik(a, b)); }
	public int getSize() { return koordinat.size(); }

	// Print hanya titik yang berada di kuadran 1 dan 2, dan bukan di sumbu-x
	// Intinya, y > 0
	public void printEligibleTitik() {
		for (Titik titik : koordinat) {
			if (titik.getY() > 0) {
				System.out.print("(" + titik.getX() + "," + titik.getY() + ")");
			}
		}
		System.out.println();
	}

	// MAIN CODE
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Hotspot hotspot = new Hotspot(); 

		// Scan dan masukkan titik ke hotspot
		int n = scanner.nextInt(); int a, b;
		for (int i=0; i<n; i++) {
			a = scanner.nextInt();
			b = scanner.nextInt();
			hotspot.add(a, b);
		}

		// Print output
		System.out.println(hotspot.getSize());
		hotspot.printEligibleTitik();
	}
}