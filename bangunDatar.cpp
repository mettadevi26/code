#include <stdio.h>

int main () {
  //persegi
  int s;
  printf ("Masukkan Panjang Sisi Persegi = ");
  scanf ("%d", &s);
  int keliling = 4 * s;
  int luas = s * s;
  printf ("luas persegi = %d\nkeliling persegi = %d\n" , luas, keliling);

  //persegi panjang
  int p, l;
  printf ("\nMasukkan Panjang Persegi Panjang = ");
  scanf ("%d", &p);
  printf ("Masukkan Lebar Persegi Panjang = ");
  scanf ("%d", &l);
  keliling = 2 * (p + l);
  luas = p * l;
  printf ("luas persegi panjang = %d\nkeliling persegi panjang = %d\n" , luas, keliling);

  //lingkaran
  int r;
  printf ("\nMasukkan jari-jari Lingkaran = ");
  scanf ("%d", &r);
  keliling = 3.14 * 2 * r;
  luas = 3.14 * r * r;
  printf ("luas lingkaran = %d\nkeliling lingkaran = %d\n" , luas, keliling);

  //segitiga
  int a, t, s1, s2;
  printf ("\nMasukkan alas segitiga = ");
  scanf ("%d", &a);
  printf ("Masukkan tinggi segitiga = ");
  scanf ("%d", &t);
  printf ("Masukkan sisi 1 segitiga = ");
  scanf ("%d", &s1);
  printf ("Masukkan sisi 2 segitiga = ");
  scanf ("%d", &s2);
  keliling = a + s1 + s2;
  luas = (a * t) / 2;
  printf ("luas segitiga = %d\nkeliling segitiga = %d\n" , luas, keliling);
}
