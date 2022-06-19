void LietKeBuoiSang(MSK array[], int size) //Hàm liệt kê các sự kiện diễn ra vào buổi sáng
{
	for (int i = 0; i < size; i++)
	{
		if ((array[i].TG.gio > 4 && array[i].TG.gio < 10) || (array[i].TG.gio == 4 && array[i].TG.phut == 0) || (array[i].TG.gio == 10 && array[i].TG.phut == 0))
		//Sự kiện được tính là diễn ra vào buổi sáng nếu nằm trong khoảng 4-10 giờ sáng
		{
			XuatSuKien(array, i); //Xuất các sự kiện thỏa yêu cầu trên
		}
	}
}
void xuatmang1(MSK a[], int n)
{
	cout << "Ten su kien: " << a[n].ten_su_kien << endl;
	cout << "Do quan trong: " << a[n].do_quan_trong << endl;
	cout << a[n].TG.gio << " gio " << a[n].TG.phut << " phut" << " , " << "ngay: " << a[n].TG.ngay << " thang: " << a[n].TG.thang << " nam: " << a[n].TG.nam << endl;
}