import java.util.*;

// greatest common division
class Gcd {
	public static void main(String[] args) {
		Gcd g = new Gcd();
		System.out.println(g.gcd(10, 4));
	}

	public int gcd(int a, int b) {
		return b > 0 ? gcd(b, a % b) : a;
	}
}