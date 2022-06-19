void XDDRatQuanTrong(MSK array[], int size, int ngay, int thang, int nam, int gio, int phut)
{
	char temp[13] = "ratquantrong";
	for (int i = 0; i < size; ++i) //Vòng lặp này sẽ tìm các sự kiện có độ quan trọng là rất quan trọng trong cấu trúc MSK. Ta sẽ xét từ năm nếu cùng năm thì ta chuyển tiêp sang tháng và cứ thế sang ngày, giờ ,phút, hàm XuatSuKien sẽ in các sự kiện thỏa yêu cầu
	{
		if ((array[i].TG.nam > nam) && (sosanh(array, temp, i))) 
			XuatSuKien(array, i);
		else
		{
			if ((array[i].TG.nam == nam) && (array[i].TG.thang > thang) && (sosanh(array, temp, i))) 
				XuatSuKien(array, i);
			else
			{
				if ((array[i].TG.nam == nam) && (array[i].TG.thang == thang) && (array[i].TG.ngay > ngay) && (sosanh(array, temp, i)))
					XuatSuKien(array, i);
				else
				{
					if ((array[i].TG.nam == nam) && (array[i].TG.thang == thang) && (array[i].TG.ngay == ngay) && (array[i].TG.gio > gio) && (sosanh(array, temp, i)))
						XuatSuKien(array, i);
					else
					{
						if ((array[i].TG.nam == nam) && (array[i].TG.thang == thang) && (array[i].TG.ngay == ngay) && (array[i].TG.gio == gio) && (array[i].TG.phut > phut) && (sosanh(array, temp, i)))
							XuatSuKien(array, i);
					}
				}
			}
		}
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
void xuatmang1(MSK a[], int n)
{
	cout << "Ten su kien: " << a[n].ten_su_kien << endl;
	cout << "Do quan trong: " << a[n].do_quan_trong << endl;
	cout << a[n].TG.gio << " gio " << a[n].TG.phut << " phut" << " , " << "ngay: " << a[n].TG.ngay << " thang: " << a[n].TG.thang << " nam: " << a[n].TG.nam << endl;
}