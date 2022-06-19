int length(char a[]) { //Hàm tính độ dài của một chuỗi ký tự
	int dem = 0; //khởi tạo biến đếm độ dài
	for (int i = 0; a[i] != '\0'; i++) { //vòng lặp đến khi gặp ký tự kết thúc chuỗi
		dem++; //tăng biến đếm
	}
	return dem;
}

bool sosanh(MSK array1[], char array2[], int i) //Hàm so sánh hai chuỗi ký tự với nhau
{
	int n = 0; //khởi tạo biến để truy cập từng ký tự của xâu do_quan_trong
	int temp(1); //khởi tạo biến tạm = 1
	while (array1[i].do_quan_trong[n] != '\0') { //vòng lặp này sẽ kiểm tra xâu thứ i từng ký tự một bắt đầu từ ký tự thứ n=0 và tăng dần
		if (array1[i].do_quan_trong[n] != array2[n]) { //nếu có ký tự khác nhau giữa hai xâu cần so sánh
			temp = 0; //biến temp gán = 0
			break; 
		}
		n++; //tăng biến đếm
	}
	if (length(array1[i].do_quan_trong) != length(array2)) //nếu độ dài của hai xâu cần so sánh khác nhau
		return false;
	if (temp == 0) //nếu biến temp phía trên có giá trị là 0, trả về false
		return false;
	else
		return true;
}

void kiemtraquantrong(MSK a[], int i) //Hàm kiểm tra độ quan trọng có nhập đúng không
{
	char temp1[15] = "khongquantrong"; //Các độ quan trọng hợp lệ
	char temp2[16] = "cochutquantrong";
	char temp3[13] = "khaquantrong";
	char temp4[13] = "ratquantrong";
	int count(0); //khởi tạo biến tạm để thoát vòng lặp
	while (count == 0)
	{
		if (sosanh(a, temp1, i) || sosanh(a, temp2, i) || sosanh(a, temp3, i) || sosanh(a, temp4, i)) //nếu thuộc vào các trường hợp hợp lệ
		{
			count = 1; //cập nhật biến thành 1 để thoát vòng lặp
		}
		else //nếu không hợp lệ
		{
			cout << "Vui long nhap dung theo yeu cau!" << endl;
			cout << "Nhap vao do quan trong cua su kien (ko/cochut/quantrong/rat): ";
			cin.getline(a[i].do_quan_trong, 81, '\n'); //cho người dùng nhập lại cho đến khi hợp lệ thì thoát vòng lặp
		}
	}
}

int songaytrongthang(int thang)
{
	int songay(0);
	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		songay = 31;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		songay = 30;
		break;
	}
	case 2:
		songay = 28;
	}
	return songay;
}

bool kiemtrantn(int n, int t, int N)
{
	if (N < 2021 || N > 2022)
		return false;
	else if (t > 12 || t < 1)
		return false;
	else if (n < 1 || n >songaytrongthang(t))
		return false;
	else
		return true;
}

bool kiemtragp(int a, int b)
{
	if (a > 24 || a < 0 || b > 60 || b < 0)
		return false;
	else
		return true;
}


void kiemtraTG(MSK a[], int i, thoi_diem b[])
{
	while (!kiemtragp(a[i].TG.gio, a[i].TG.phut) || !kiemtrantn(a[i].TG.ngay, a[i].TG.thang, a[i].TG.nam))
	{
		cout << "Vui long nhap dung thoi gian!" << endl;
		cout << "Nhap vao lan luot ngay thang nam gio phut: ";
		cin >> a[i].TG.ngay >> a[i].TG.thang >> a[i].TG.nam >> a[i].TG.gio >> a[i].TG.phut;
	}
}

void nhapmang(MSK array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cin.ignore();//dùng để xóa phần tử được nhập vào trước đó
		cout << "Nhap vao ten su kien: ";
		cin.getline(array[i].ten_su_kien, 81, '\n');//nhập tên sự kiện, tối đa 81 ký tự và ấn enter để hoàn tất nhập
		cout << "Nhap vao do quan trong cua su kien (ko/cochut/quantrong/rat): ";
		cin.getline(array[i].do_quan_trong, 81, '\n');//nhập độ quan trọng, tối đa 81 ký tự và ấn enter để hoàn tất nhập
		kiemtraquantrong(array, i);//Hàm kiểm tra tính hợp lệ của độ quan trọng được nhập vào
		cout << "Nhap vao lan luot ngay thang nam gio phut: ";
		cin >> array[i].TG.ngay >> array[i].TG.thang >> array[i].TG.nam >> array[i].TG.gio >> array[i].TG.phut;
		kiemtraTG(array, i, b);
	}
}

