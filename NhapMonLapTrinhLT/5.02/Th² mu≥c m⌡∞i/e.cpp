
int songaytrongthang(int thang) //Hàm kiểm tra số ngày trong tháng của năm không nhuận
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

long tinhsogiokhibietthang(MSK array[], int i)  //hàm tính số phút trôi qua theo tháng (mốc là giao thừa sang năm 2021)
{                                            // tổng thời gian trôi qua của các tháng trước đó
    long temp(0);
    if (array[i].TG.thang == 1)   // nếu tháng bằng 1 thì xuất ra là 0;
    {
        return temp;
    }
    for (int j = 1; j < array[i].TG.thang; j++) //vòng lập tính từng tháng rồi cộng lại
    {
        temp = temp + (songaytrongthang(j)) * 24 * 60;
    }
    return temp;
}

long tinhsogio(MSK array[], int i)// tính số phút đã trôi qua kể từ giao thừa sang năm 2021
{
    long temp;
    temp = (array[i].TG.nam - 2021) * 365 * 24 * 60 + tinhsogiokhibietthang(array, i) + (array[i].TG.ngay - 1) * 24 * 60 + (array[i].TG.gio) * 60 + array[i].TG.phut;
    return temp;
}

void SapXepSuKien(MSK array[], int size) // hàm sắp xếp các sự kiện theo thứ tự thời gian
{
    MSK c[1]; // biến tạm
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (tinhsogio(array, i) > tinhsogio(array, j)) // so sánh sự kiện nào có số phút bé hơn ( diễn ra trước ) thì đưa lên trên
            {
                c[0] = array[i];     // hoán vị sự kiện 
                array[i] = array[j];
                array[j] = c[0];
            }
        }
    }
}