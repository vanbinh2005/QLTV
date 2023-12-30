#include <iostream>
#include <fstream>  //Đọc và ghi file
#include <stdlib.h> //quản lý bộ nhớ
#include <string>   // Đọc string tốt hơn
using namespace std;

bool admin()
{
    // lấy thông tin từ file admin
    ifstream ad("admin.txt"); // Tạo đối tượng ad mở và đọc file admin.txt
    string A[7][2], x;        // Tối đa bảy người quản lý được rồi, nhiều dễ bị tham nhũng :)))

    int run = 0; // Biến chạy cho A
    // Đối tượng ad sẽ lần lượt đọc các dòng trog file - 1 vòng là 1 dòng
    while (getline(ad, x)) // Nhập thông tin từ đối tượng ad vào biến x
    {
        // Tách phần tên và mật khẩu trong x
        string name = "", pass = "";
        bool kt = false;
        for (size_t i = 0; i < x.size(); ++i)
        {
            if (kt)
            {
                break;
            }
            if (x[i] == ' ')
            {
                for (size_t j = i + 1; j < x.size(); ++j)
                {
                    pass += x[j]; // Phần mật khẩu
                }
                kt = true;
                break;
            }
            name += x[i]; // Phần tên
        }

        // Đưa name và pass vào A
        A[run][0] = name;
        A[run][1] = pass;
        run++;
    }

    // kiểm tra người dùng đăng nhập đúng hay sai
    int kt = 0;
    while (true)
    {
        system("cls");
        string TDN, MK;
        // Yêu cầu đăng nhâp vào tài khoản admin
        if (kt == 0)
        {
            cout << "Vui long dang nhap\nChu y: Viet lien khong dau\n";
        }
        if (kt != 0)
        {
            cout << "Nhap sai lan thu: " << kt;
            cout << "\nTen dang nhap hoac mat khau khong chinh xac\nVui long nhap lai\n";
        }
        cout << "Ten dang nhap: ";
        cin >> TDN;
        cout << "Mat khau: ";
        cin >> MK;

        for (int _ = 0; _ <= 7; _++)
        {
            if (_ == 7) // Không tìm được tk hợp lệ
            {
                kt++;
                if (kt >= 3)
                {
                    return false;
                }
            }
            if (TDN == A[_][0]) // Đã tìm được tài khoảng
            {
                if (MK == A[_][1])
                {
                    return true;
                }
            }
        }
    }
}

int quanlythuvien()
{
    cout << "quan ly thu vien";
    return 0;
}

int quanlyusre()
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
                            cout << "Ban muon tiep tuc tim kiem khong (Y/N): "; // Tiep tuc tim kiem hoac dung tim kiem
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
                        cout << "Ban muon tiep tuc tim kiem khong (Y/N):"; // Tiep tuc tim kiem hoac dung tim kiem
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
            system("cls");
            cout << "Tat ca thong tin trong danh sach den: \n";
            for (size_t i = 0; i <= run; i++)
            {
                cout << A[i] << "\n";
            }
            cout << "Nhap mot tu bat ki de quay lai: ";
            char Yn;
            cin >> Yn;
            if (Yn)
            {
                continue;
            }
        }
        if (kt2 == 3) // Chinh sua danh sach
        {
            system("cls");
            while (true)
            {
                cout << "Ban muon xoa ( 1 ) hay them ( 2 ) usre vao danh sach den ( 0 de thoat ): \n";
                int chinhsua;
                cin >> chinhsua;
                if (chinhsua == 0) // Thoat
                {
                    break;
                }
                if (chinhsua == 1) // Xoa user
                {
                    system("cls");
                    cout << "Xoa user danh sach den\n";
                    while (true)
                    {
                        cout << "Nhap ten: ";
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
                            if (dem == run) // Khong tim duoc
                            {
                                cout << "Khong tim duoc\n";
                                cout << "Ban muon tiep tuc tim kiem khong (Y/N):"; // Tiep tuc
                                char tiep;
                                cin >> tiep;
                                if (tiep == 'Y')
                                {
                                    kt33 = true;
                                    break;
                                }
                                else if (tiep == 'N')
                                {
                                    kt33 = false;
                                    break;
                                }
                                else
                                {
                                    cout << "Loi !!";
                                    continue;
                                }
                            }
                        }
                        if (kt33) // Tiep tuc tim kiem
                        {
                            continue;
                        }
                        else // Ket thuc xoa user
                        {
                            ofstream myfile;
                            myfile.open("test.txt");
                            for (int i = 0; i < run; i++)
                            {
                                if (A[i] == "")
                                {
                                    break;
                                    ;
                                }
                                myfile << A[i] << "\n";
                            }
                            myfile.close();
                            break;
                        }
                    }
                }
                else if (chinhsua == 2) // Them user
                {
                    system("cls");
                    cout << "Them user vao danh sach den\n";
                    while (true)
                    {
                        cout << "Nhap ten: ";
                        string ten;
                        cin >> ten;
                        int dem = 0;
                        bool kt33 = false;
                        for (int _ = 0; _ <= run; _++) // Vong tim
                        {
                            if (ten == A[_])
                            {
                                cout << "Da ton tai: " << A[_] << "\n";
                                break;
                            }
                            else
                            {
                                kt33 = true;
                            }
                        }
                        bool kt44 = false;
                        if (kt33)
                        {
                            for (int _ = 0; _ < 9999; _++)
                            {
                                if (A[_] == "")
                                {
                                    A[_] = ten;
                                    cout << "Da them " << A[_] << " vao danh sach den\n";
                                    cout << "Ban muon tiep khong (Y/N):"; // Tiep tuc tim kiem hoac dung tim kiem
                                    char tiep;
                                    cin >> tiep;
                                    if (tiep == 'Y')
                                    {
                                        break;
                                    }
                                    else if (tiep == 'N')
                                    {
                                        kt44 = true;
                                        break;
                                    }
                                    else
                                    {
                                        cout << "Loi !!";
                                        continue;
                                    }
                                    break;
                                }
                            }
                            if (kt44)
                            {
                                ofstream myfile;
                                myfile.open("test.txt");
                                for (int i = 0; i < 9999; i++)
                                {
                                    if (A[i] == "")
                                    {
                                        break;
                                    }
                                    myfile << A[i] << "\n";
                                }
                                myfile.close();
                                cout << "Ket thuc";
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int xem_va_timkiem()
{
    // lấy thông tin từ file admin
    ifstream xvtk("books.txt"); // Tạo đối tượng ad mở và đọc file admin.txt
    string A[100][8], x;

    int run = 0; // Biến chạy cho A

    // Đối tượng ad sẽ lần lượt đọc các dòng trog file 1 vòng là 1 dòng
    while (getline(xvtk, x)) // Nhập thông tin từ đối tượng ad vào biến x
    {
        // Tách phần các thành phần trên 1 dòng của books ra
        string isbn = "", title = "", subject = "",
               author = "", publisher = "", date = "", pages = "", copies = "";

        int kt = 0;
        for (size_t i = 0; i < x.size(); ++i)
        {
            // Chuyển giao giữa các đối tượng
            if (x[i] == ' ')
            {
                if (kt == 0)
                {
                    kt = 1;
                    continue;
                }
                if (kt == 1)
                {
                    kt = 2;
                    continue;
                }
                if (kt == 2)
                {
                    kt = 3;
                    continue;
                }
                if (kt == 3)
                {
                    kt = 4;
                    continue;
                }
                if (kt == 4)
                {
                    kt = 5;
                    continue;
                }
                if (kt == 5)
                {
                    kt = 6;
                    continue;
                }
                if (kt == 6)
                {
                    kt = 7;
                    continue;
                }
            }

            if (kt == 0)
            {
                isbn += x[i];
            }
            if (kt == 1)
            {
                title += x[i];
            }
            if (kt == 2)
            {
                subject += x[i];
            }
            if (kt == 3)
            {
                author += x[i];
            }
            if (kt == 4)
            {
                publisher += x[i];
            }
            if (kt == 5)
            {
                date += x[i];
            }
            if (kt == 6)
            {
                pages += x[i];
            }
            if (kt == 7)
            {
                copies += x[i];
            }
        }

        // Đưa name và pass vào A
        A[run][0] = isbn;
        A[run][1] = title;
        A[run][2] = subject;
        A[run][3] = author;
        A[run][4] = publisher;
        A[run][5] = date;
        A[run][6] = pages;
        A[run][7] = copies;
        run++;
    }

    // In ra tất cả thông tin trong thư viện
    for (int _ = 0; _ < sizeof(A) / sizeof(A[0]); _++)
    {
        if (A[_][0] == "")
        {
            continue;
        }
        cout << A[_][0] << " | " << A[_][1] << " | " << A[_][2] << " | " << A[_][3] << " | " << A[_][4] << " | " << A[_][5] << " | " << A[_][6] << " | " << A[_][7] << "\n";
    }
    return 0;
}

int main()
{
    bool ad = false;
    system("cls"); // Xóa output
    cout << "Xin Chao!!!";
    while (true)
    {

        int kt;
        cout << "\n( admin: 1; user: 2; end: 0 )\
         \nBan la: ";
        cin >> kt;

        if (kt == 0) // Kết thúc chương trình
        {
            system("cls");
            cout << "Hen gap lai!!";
            return 0;
        }
        else if (kt == 1) // Danh tính admin
        {
            system("cls");
            ad = admin();
            if (ad) // Đang nhập thành công
            {
                cout << "dang nhap thanh cong";
                int kt = 99999999;
                while (true)
                {
                    if (kt == 99999999)
                    {
                        cout << "Ban muon kiem tra thu vien ( 1 ) \n\
                    : chinh sua thu vien ( 2 ) \n\
                    : quan ly usre ( 3 ): ";
                        cin >> kt;
                    }
                    if (kt == 1) // Kiểm tra
                    {
                        system("cls");
                        cout << "Kiem tra thu vien\n";
                        kt = xem_va_timkiem();
                        if (kt = 0)
                        {
                            system("cls");
                            cout << "Tam biet!!";
                            return 0;
                        }
                    }
                    else if (kt == 2) // Chỉnh sửa thư viện
                    {
                        system("cls");
                        cout << "Chinh sua thu vien\n";
                        kt = quanlythuvien();
                        if (kt = 0)
                        {
                            system("cls");
                            cout << "Tam biet!!";
                            return 0;
                        }
                    }
                    else if (kt == 3) // Chỉnh sửa usre
                    {
                        system("cls");
                        cout << "Quan ly usre\n";
                        kt = quanlyusre();
                        if (kt = 0)
                        {
                            system("cls");
                            cout << "Tam biet!!";
                            return 0;
                        }
                    }
                    else // Lỗi và bắt đầu vòng lập mới
                    {
                        system("cls");
                        cout << "Loi sai cu phap!! vui long nhap lai";
                        continue;
                    }
                }
            }
            else
            {
                cout << "Ban da nhap sai nhieu lan\nTam biet!!";
                return 0;
            }
        }
        else if (kt == 2) // Danh tính người dùng
        {
            system("cls");
            cout << "Xin chao quy khach";
            break;
        }
        else // Input không hợp lệ
        {
            system("cls");
            cout << "Khong hop le vui long nhap lai\n";
            continue;
        }
    }

    return 0;
}
