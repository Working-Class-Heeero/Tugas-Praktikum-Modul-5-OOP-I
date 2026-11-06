#include <iostream>
#include <vector>
using namespace std;

//Superclass
class Vehicle{
    protected:
        string name, type;
        int PricePerDay;
    public:
        Vehicle(string name, string type, int PricePerDay){ //Constructor superclass
            this->name = name;
            this->type = type;
            this-> PricePerDay = PricePerDay;
        }

        void showInfo(){ //Method untuk melihat info
            cout << "Nama kendaraan: " << name << endl;
            cout << "Tipe kendaraan: " << type << endl;
            cout << "Harga rental per hari: " << PricePerDay << endl;
        }

        long calculateRent(int Hari){return PricePerDay*Hari;} //Hitung sewa
};

//Subclass
class Car : public Vehicle{ //Untuk mobil
    public:
        Car(string name) : Vehicle(name, "Car", 300000){} //Constructor
};

class Motorcycle : public Vehicle{ //Untuk motor
    public:
        Motorcycle(string name) : Vehicle(name, "Motorcycle", 100000){} //Constructor
};

//Program utama
class programUtama{
    private: //Attribute
        vector<Vehicle> Vehicles;
        string namaKendaraan;
        int tipeKendaraan;
        int index;

    public:
        void addVehicle(){ //Untuk menambah kendaraan
            cout << "\n== Punya kendaraan baru? Data saja di sini! ==" << endl;
            cin.ignore();
            cout << "Masukkan nama kendaraan: ";
            getline(cin >> ws, namaKendaraan);
            if(namaKendaraan.empty() == true){ //Nama tidak boleh kosong
                cout << "Error! Nama kendaraan tidak boleh kosong!" << endl;
                return;
            }
            cout << "\nAda dua tipe kendaraan yang Anda bisa masukkan." << endl;
            cout << "Silahkan masukkan 1 untuk kendaraan bertipe mobil, dan 2 untuk kendaraan bertipe motor." << endl;
            cout << "Masukkan tipe kendaraan: ";
            cin >> tipeKendaraan;
            if(tipeKendaraan == 1){ //Mobil
                Car c(namaKendaraan);
                Vehicles.push_back(c);
            }
            else if(tipeKendaraan == 2){ //Motor
                Motorcycle m(namaKendaraan);
                Vehicles.push_back(m);
            }
            else{ //???
                cout << "Error! Silahkan masukkan data yang valid!" << endl;
                return;
            }
        }

        void viewVehicle(){ //Melihat kendaraan
            if(Vehicles.empty() == true){ //Kendaraan kosong
                cout << "\nBelum ada kendaraan. Silahkan tambahkan kendaraan sebelum melanjutkan." << endl;
                return;
            }
            else{ //Kendaraan ada
                cout << "\n== Sudah ada kendaraan? Silahkan lihat! ==" << endl;
                for(int i = 0; i < Vehicles.size(); i++){
                    cout << "\nIndex ke-" << i << endl;
                    Vehicles.at(i).showInfo();
                    cout << "\n== Garis Pembatas ==" << endl;
                }
            }
        }

        //method untuk menghitung harga sewa
        void calculateRent(){
            int Hari;
            if(Vehicles.empty() == true){ //Kendaraan kosong
                cout << "\nMasih belum ada kendaraan, silahkan coba lagi." << endl;
                return;
            }
            else{ //Menghitung sewa
                cout << "\n== Saatnya menghitung total biaya sewa kendaraan ==" << endl;
                cout << "Tetapi, sebelum memulai, harus ada beberapa hal yang perlu diisi terlebih dahulu." << endl;
                cout << "Index kendaraan yang akan diakses: ";
                cin >> index;
                if(isValidIndex(index) == false){ //Jika index tidak ada dalam list, maka program akan gagal
                    showInvalidIndex();
                    return;
                }
                cout << "Lama sewa kendaraan dalam hari: ";
                cin >> Hari;
                if(Hari <= 0){ //Program juga akan gagal jika hari sewa kurang dari 1
                    cout << "Error! Lama sewa harus lebih dari 0 hari!" << endl;
                    return;
                }
                Vehicle v = Vehicles.at(index);
                cout << "\nAnda memilih kendaraan berindex ke-" << index << " dengan spesifikasi berikut: " << endl;
                v.showInfo();
                cout << "Harga sewa yang perlu dibayar adalah: " << v.calculateRent(Hari) << endl;
            }
        }

        void deleteVehicle(){ //Menghapus kendaraan
            if(Vehicles.empty() == true){ //Tidak ada kendaraan
                cout << "\nMasih belum ada kendaraan, silahkan coba lagi." << endl;
                return;
            }
            else{ //Bye-bye
                cout << "\n== Apakah Anda tidak sayang dengan kendaraan Anda? ==" << endl;
                cout << "Tidak perlu khawatir, Anda bisa menghapus kendaraan Anda." << endl;
                cout << "Silahkan masukkan index kendaraan Anda: ";
                cin >> index;
                if(isValidIndex(index) == false){ //Salah Index
                    showInvalidIndex();
                    return;
                }
                Vehicle removed = Vehicles.at(index); //Kendaraan dihapus
                Vehicles.erase(Vehicles.begin() + index);
                cout << "\nKendaraan dengan spesifikasi:" << endl;
                removed.showInfo();
                cout << "Telah dihapus." << endl;
            }
        }

        bool isValidIndex(int index){return index >= 0 && index < Vehicles.size();} //Untuk failsafe agar tidak ada index yang keliru

        void showInvalidIndex(){ //Jika kamu salah index
            cout << "Error! Index yang dimasukkan tidak valid! Silahkan masukkan dari index 0 hingga " << (Vehicles.size() - 1) << "." << endl;
        }
};

//Main function
int main(){

    //Identitas kelompok!
    cout << "== WE ARE ==" << endl << endl;
    cout << "== Kelompok 32 ==" << endl << endl;
    cout << "Nama: Revano Bimaputra Wiradhani" << endl;
    cout << "NIM: 21120126130097" << endl << endl;
    cout << "Nama : Daffa Hilmy Muhammad" << endl;
    cout << "NIM : 21120126140162" << endl << endl;
    cout << "Nama : Mochammad Fiqry Ramadani" << endl;
    cout << "NIM : 21120126140178" << endl << endl;
    cout << "Nama: Benyamin Maulana Pasha" << endl;
    cout << "21120126130090" << endl << endl;
    cout << "== Shift 5 ==" << endl;

    //Beberapa variabel dan satu objek, akan berguna nanti
    int opsi;
    bool programJalan = true;
    programUtama objek1;

    //Loop utama
    do{
        cout << "\n===== VEHICLE RENTAL =====" << endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. View Vehicles" << endl;
        cout << "3. Calculate Rent" << endl;
        cout << "4. Delete Vehicle" << endl;
        cout << "5. Exit" << endl;
        cout << "==========================" << endl << endl;
        cout << "Silahkan masukkan opsi: ";
        cin >> opsi;
        switch(opsi){
            case 1: //Menambah kendaraan
                objek1.addVehicle();
                break;
            case 2: //Melihat data kendaraan
                objek1.viewVehicle();
                break;
            case 3: //Menghitung biaya sewa kendaraan
                objek1.calculateRent();
                break;
            case 4: //Menghapus kendaraan
                objek1.deleteVehicle();
                break;
            case 5: //Exit
                cout << "Semoga kita bertemu lagi!" << endl;
                programJalan = false;
                break;
            default: //Jika input salah
                cout << "Error, silahkan masukkan opsi yang valid." << endl;
                break;
        }
    }while(programJalan == true); //Agar program terulang
}
