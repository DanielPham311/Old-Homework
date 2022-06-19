//yêu cầu người dùng nhập thời điểm để ta kiếm trong cấu trúc sự kiện cần sửa độ quan trọng
void SuaDoQuanTrong(MSK array[], int size, int ngay, int thang, int nam, int gio, int phut) //Hàm sửa độ quan trọng của một sự kiện (biết trước thời điểm )
{
	int count(0); //khởi tạo biến đếm tạm = 0
	for (int i = 0; i < size; ++i)
	{
		if ((array[i].TG.nam == nam) && (array[i].TG.thang == thang) && (array[i].TG.ngay == ngay) && (array[i].TG.gio == gio) && (array[i].TG.phut == phut)) //nếu tìm thấy sự kiện thỏa thời điểm được nhập vào
		{
			count = 1; //gán biến count = 1
			cin.ignore(); // xóa phần tử được nhập vào trước đó
			cout << "Nhap vao do quan trong cua su kien (ko/cochut/quantrong/rat): ";
			cin.getline(a[i].do_quan_trong, 81, '\n'); //ghi đè độ quan trọng lên độ quan trọng của sự kiện tìm được
			kiemtraquantrong(a, i); //kiểm tra xem lúc ghi đè dữ kiện được nhập có hợp lệ không
			break; //nếu hợp lệ thoát vòng lặp
		}
		else //nếu không kiếm được sự kiện nào theo người dùng đã nhập
			count = 0; //gán biến count = 0
	}
	if (count == 0) { 
		cout << "Khong co su kien nao dien ra" << endl;
	}
}
bool sosanh(MSK a[], char b[], int i)
{
	int n = 0;
	int temp(1);
	while (a[i].do_quan_trong[n] != '\0') {
		if (a[i].do_quan_trong[n] != b[n]) {
			temp = 0;
			break;
		}
		n++;
	}
	if (length(a[i].do_quan_trong) != length(b))
		return false;
	if (temp == 0)
		return false;
	else
		return true;
}
void kiemtraquantrong(MSK a[], int i)
{
	char temp1[3] = "ko";
	char temp2[7] = "cochut";
	char temp3[10] = "quantrong";
	char temp4[4] = "rat";
	int count(0);
	while (count == 0)
	{
		if (sosanh(a, temp1, i) || sosanh(a, temp2, i) || sosanh(a, temp3, i) || sosanh(a, temp4, i))
		{
			count = 1;
		}
		else
		{
			cout << "Vui long nhap dung theo yeu cau!" << endl;
			cout << "Nhap vao do quan trong cua su kien (ko/cochut/quantrong/rat): ";
			cin.getline(a[i].do_quan_trong, 81, '\n');
		}
	}
}
int length(char a[]) {
	int dem = 0;
	for (int i = 0; a[i] != '\0'; i++) {
		dem++;
	}
	return dem;
}