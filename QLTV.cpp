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

int quanly()
{
}

void xem_va_timkiem()
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

    for (int _ = 0; _ < sizeof(A) / sizeof(A[0]); _++)
    {
        cout << A[_][0] << " | " << A[_][1] << " | " << A[_][2] << " | " << A[_][3] << " | " << A[_][4] << " | " << A[_][5] << " | " << A[_][6] << " | " << A[_][7];
    }
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
            if (ad)
            {
                break;
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

    if (ad)
    {
        cout << "dang nhap thanh cong";
        xem_va_timkiem();
    }

    return 0;
}
