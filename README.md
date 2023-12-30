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

    //In ra tất cả thông tin trong thư viện
    for (int _ = 0; _ < sizeof(A) / sizeof(A[0]); _++)
    {
        if (A[_][0] == "")
        {
            continue;
        }
        cout << A[_][0] << " | " << A[_][1] << " | " << A[_][2] << " | " << A[_]\
        [3] << " | " << A[_][4] << " | " << A[_][5] << " | " << A[_][6] << " | " << A[_][7] << "\n";
    }
}
