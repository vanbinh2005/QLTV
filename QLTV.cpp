#include <iostream>
#include <fstream>  //Đọc và ghi file
#include <stdlib.h> //quản lý bộ nhớ
#include <string>   // Đọc string tốt hơn
using namespace std;

int main()
{
    // lấy thông tin từ file usre
    ifstream us("test.txt"); // Tạo đối tượng us mở và đọc file usre.txt
    string A[9999], x;       // Tối đa bảy người quản lý được rồi, nhiều dễ bị tham nhũng :)))

    int run = 0; // Biến chạy cho A
    // Đối tượng ad sẽ lần lượt đọc các dòng trog file - 1 vòng là 1 dòng
    while (getline(us, x)) // Nhập thông tin từ đối tượng us vào biến x va
    {
        A[run] = x; // đưa thông tin từ x vào A;
        run++;
    }

    while (true)
    {

        system("cls");
        cout << "Tim kiem ( 1 ): Xem tat ca ( 2 ) : Chinh sua danh sach den ( 3 ) : Ket thuc ( 0 ):\n";
        int kt2;
        cin >> kt2;
        if (kt2 == 0)
        {
            system("cls");
            cout << "Ket Thuc";
            return 0;
        }

        if (kt2 == 1) // Tim kiem usre
        {
            while (true)
            {
                system("cls");
                cout << "Nhap ten can tim kiem: ";
                string name;
                cin >> name;
                int dem = 0;
                bool kt22 = false;
                for (int _ = 0; _ <= run; _++)
                {
                    if (name == A[_])
                    {
                        cout << "Da tim duoc: " << A[_] << "\n";
                        while (true)
                        {
                            cout << "Ban muon tiep tuc tim kiem khong (Y/N)"; // Tiep tuc tim kiem hoac dung tim kiem
                            char tiep;
                            cin >> tiep;
                            if (tiep == 'Y')
                            {
                                kt22 = true;
                                break;
                            }
                            else if (tiep == 'N')
                            {
                                kt22 = false;
                                break;
                            }
                            else
                            {
                                cout << "Loi !!";
                                continue;
                            }
                        }

                        break;
                    }
                    dem++;
                    if (dem == run) // Khong tim duoc
                    {
                        cout << "Khong tim duoc\n";
                        cout << "Ban muon tiep tuc tim kiem khong (Y/N)"; // Tiep tuc tim kiem hoac dung tim kiem
                        char tiep;
                        cin >> tiep;
                        if (tiep == 'Y')
                        {
                            kt22 = true;
                            break;
                        }
                        else if (tiep == 'N')
                        {
                            kt22 = false;
                            break;
                        }
                        else
                        {
                            cout << "Loi !!";
                            continue;
                        }
                    }
                }

                if (kt22) // Tiep tuc tim kiem
                {
                    continue;
                }
                else // Ket thuc tim kiem
                {
                    break;
                }
            }
        }
        if (kt2 == 2) // in tat ca danh sach
        {

            while (true)
            {
                system("cls");
                cout << "Tat ca thong tin trong danh sach den: \n";
                for (size_t i = 0; i <= run; i++)
                {
                    cout << A[i] << "\n";
                }
                cout << "Ban muon chinh sua danh sach den chu Y/N: "; // Tiep tuc hoac dung
                char chinh;    
                cin >> chinh;

                if (chinh == 'Y')
                {
                    kt2 = 3;
                    break;
                }
                else if (chinh == 'N')
                {
                    cout << "Vang! Toi se doi";
                    continue;
                }
            }
        }
        if (kt2 == 3) // Chinh sua danh sach
        {
            system("cls");
            while (true)
            {
                cout << "Ban muon xoa ( 1 ) hay them ( 2 ) usre vao danh sach den ( 0 de thoat ): ";
                int chinhsua;
                cin >> chinhsua;
                if (chinhsua == 0) // Thoat
                {
                    break;
                }
                if (chinhsua == 1) // Xoa user
                {
                    system("cls");
                    cout << "Xoa user khoi danh sach den\n";
                    while (true)
                    {
                        cout << "Nhap ten:";
                        string ten;
                        cin >> ten;
                        int dem = 0;
                        bool kt33 = false;
                        for (int _ = 0; _ <= run; _++) // Vong tim
                        {
                            if (ten == A[_])
                            {
                                cout << "Da tim duoc: " << A[_] << "\n";
                                A[_] = "";
                                while (true)
                                {
                                    cout << "Ban muon tiep tuc chu Y/N: "; // Tiep tuc hoac dung
                                    char tt;
                                    cin >> tt;
                                    if (tt == 'Y')
                                    {
                                        kt33 = true;
                                        break;
                                    }
                                    else if (tt == 'N')
                                    {
                                        kt33 = false;
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Loi!!";
                                    }
                                }
                            }
                            dem++;
                        }
                        if (kt33) // Tiep tuc xoa usre
                        {
                            continue;
                        }
                        else
                        {
                            chinhsua = 0;
                            break;
                        }
                        if (dem == run) // Khong tim duoc
                        {
                            cout << "Khong tim duoc";
                        }
                    }
                }
            }

            ofstream myfile;
            myfile.open("test.txt");
            for (int i = 0; i < run; i++)
            {
                if (A[i] == "")
                {
                    continue;
                }
                myfile << A[i] << "\n";
            }
            myfile.close();
        }
    }
    return 0;
}
