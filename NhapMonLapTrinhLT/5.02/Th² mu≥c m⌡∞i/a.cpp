int length(char a[]) {
	int dem = 0;
	for (int i = 0; a[i] != '\0'; i++) {
		dem++;
	}
	return dem;
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
void XuatSuKien(MSK array[], int n) //Hàm xuất sự kiện tại vị trí thứ n trong cấu trúc
{
	cout << "Ten su kien: " << array[n].ten_su_kien << endl; //Xuất tên sự kiện
	cout << "Do quan trong: " << array[n].do_quan_trong << endl; //Xuất độ quan trọng
	cout << array[n].TG.gio << " gio " << array[n].TG.phut << " phut" << " , " << "ngay: " << array[n].TG.ngay << " thang: " << array[n].TG.thang << " nam: " << array[n].TG.nam << endl;
	//Xuất thời điểm của sự kiện
}

void KhaVaRatQuanTrong(MSK array[], int size) //Hàm xuất các sự kiện có mức khá và rất quan trọng
{
	char ans1[13] = "ratquantrong";
	char ans2[13] = "khaquantrong"; //hai key cần tìm trong cấu trúc
	for (int i = 0; i < size; i++)
	{
		if (sosanh(array, ans1, i) || sosanh(array, ans2, i)) //so sánh độ quan trọng của các sự kiện với 2 key
		{
			XuatSuKien(array, i); //Nếu tìm được, xuất sự kiện ra
		}
	}
}
