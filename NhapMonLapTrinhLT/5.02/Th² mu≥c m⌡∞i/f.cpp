void xoaphantu(MSK array[], int& size, int vitri) //Hàm để xóa phần tử tại một vị trí
{
	for (int i = vitri; i < size; i++)
	{
		array[i] = array[i + 1];
	}
	size--;
}
void XoaKhongQT(MSK array[], int& size) //Hàm xóa sự kiện không quan trọng
{
	char ans[15] = "khongquantrong";
	for (int i = 0; i < size; i++)
	{
		if (sosanh(array, ans, i)) //kiểm tra nếu không quan trọng
		{
			xoaphantu(array, size, i); //nếu thỏa điều kiện trên ta xóa sự kiện đó
			i--;
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
int length(char a[]) {
	int dem = 0;
	for (int i = 0; a[i] != '\0'; i++) {
		dem++;
	}
	return dem;
}