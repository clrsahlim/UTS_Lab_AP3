#include <iostream> //Header untuk input/output standar C++
#include <math.h> //Header untuk fungsi matematika
using namespace std;

int luhn1 (long long angka) //Membuat fungsi algoritma luhn tahap pertama
{
    int i,satuan,checksum; //Deklarasi tipe data 
    checksum = 0; //Inisialisasikan checksum
    for (i=1;i<=8;i++) //Perulangan program sebanyak 8 kali
    {
        satuan = (angka % 100) / 10; //Menentukan digit kedua terakhir
        angka /= 100; //Menghapus dua digit terakhir
        satuan *= 2; //Digit kedua terakhir dikali dua sesuai aturan algoritma luhn
        if (satuan >= 10) //Jika hasil perkalian satuan menghasilkan 2 digit bilangan, maka :
        {
            checksum += satuan / 10; //Untuk menambah angka puluhan dari hasil perkalian satuan dengan checksum
            checksum += satuan % 10; //Untuk menambah angka satuan dari hasil perkalian satuan dengan checksum
        }
        else 
        checksum += satuan; //Jika hasil perkalian satuan satu digit, maka satuan langsung ditambahkan ke checksum
    }
    return checksum; //Mengembalikan hasil penjumlahan checksum ke tempat dimana fungsi 'luhn1' dipanggil
}

int luhn2 (long long angka)//Membuat fungsi algoritma luhn tahap kedua
{
    int i,satuan,checksum;//Deklarasi tipe data
    checksum = 0;//Inisialisasikan checksum
    for (i=1;i<=8;i++)//Perulangan program sebanyak 8 kali
    {
        satuan = angka % 10;//Menentukan digit terakhir
        angka /= 100; //Menghapus dua digit terakhir
        checksum += satuan; //Menambahkan satuan ke checksum
    }
    return checksum;//mengembalikan hasil penjumlahan checksum ke tempat dimana fungsi 'luhn2' dipanggil
}

int main ()
{
    long long angka; //Deklarasi tipe data angka sebagai long long (untuk menampung lebih banyak angka)
    int digit_depan,dua_digit_depan,checksum; //Deklarasi tipe data
    string tipe_kartu; //Deklarasi tipe data
    cout << "Masukkan angka kartu : "; //Meminta input pengguna
    cin >> angka; //Memasukkan input pengguna ke variabel angka
    cout << "Nomor kartu anda : "<< angka <<endl; ///Menampilkan nomor kartu customer
    checksum = luhn1 (angka) + luhn2 (angka); //Menambahkan checksum pada fungsi luhn1 dengan fungsi luhn2

    if ((checksum % 10) == 0) //Jika checksum dibagi 10 bersisa 0, maka kartu valid, dan kemudia dicek untuk menentukan jenis kartu
    {
        digit_depan = (angka / pow (10,15)); //Menentukan digit pertama angka kartu (16 angka)
        if ((digit_depan > 0) && (digit_depan <= 9)) //Jika sisa pembagian digit pertama tidak lebih dari satu digit (syarat terpenuhi karena jumlah angka pada kartu tidak lebih dari 16), maka :
        {
            if (digit_depan == 5) //Jika digit pertama adalah 5, maka :
            {
                dua_digit_depan = angka / pow (10,14);//Menentukan dua digit pertama (51-55 adalah MASTERCARD)
                switch (dua_digit_depan)
                {
                case 51 : tipe_kartu = "MASTERCARD";break;
                case 52 : tipe_kartu = "MASTERCARD";break;
                case 53 : tipe_kartu = "MASTERCARD";break;
                case 54 : tipe_kartu = "MASTERCARD";break;
                case 55 : tipe_kartu = "MASTERCARD";break;
                default : tipe_kartu = "TIDAK DIKETAHUI";break; //Jika bukan 51-55, maka tipe kartu tidak diketahui
                }
            }
            else if (digit_depan == 4) //Jika digit pertama adalah 4, maka :
                tipe_kartu = "VISA"; //tipe kartu adalah VISA
            else
                tipe_kartu = "TIDAK DIKETAHUI"; //Jika digit pertama bukan 4 atau 5, maka tipe kartu tidak diketahui
        }

        else if ((digit_depan == 0) && ((angka / pow (10,12)) > 0) && ((angka / pow (10,12)) <= 9))//Pengecekan angka kartu untuk 13 digit
        {
            digit_depan = angka / pow (10,12);//Menentukan digit pertama kartu
            if (digit_depan == 4)//Jika digit pertama kartu adalah 4, maka :
                tipe_kartu = "VISA"; //Tipe kartu adalah VISA
            else
                tipe_kartu = "TIDAK DIKETAHUI"; //Jika digit kartu bukan 4, maka tipe kartu tidak diketahui
        }
        else
        {
            tipe_kartu = "TIDAK DIKETAHUI"; //Jika tidak sesuai dengan seluruh kriteria sebelumnya (walaupun checksum dibagi 10 bersisa 0), maka tipe kartu tidak diketahui
        }
    }
    else 
        tipe_kartu = "TIDAK VALID"; //Jika checksum dibagi 10 bersisa bukan 0, maka tipe kartu tidak valid
    cout << "Tipe kartu anda : "<< tipe_kartu <<endl; //Menampilkan tipe kartu customer
    cout << "Checksum : "<< checksum; //Menampilkan checksum
    return 0; //Mengembalikan nilai 0 ke sistem operasi untuk menunjukkan bahwa program telah berakhir tanpa kesalahan.
}