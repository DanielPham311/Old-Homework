#include "func.h"
#include "nhapxuat.h"
#include <iostream>

using namespace std;

void Xoa(char array[], int &size, int pos) //Hàm xóa ký tự tại một vị trí pos
{
    for (int i=pos; i<size; ++i)
    {
        array[i] = array[i+1];
    }    
    array[size-1] = '\0';
}

void XoaKhoangTrang(char array[], int size) //Hàm xóa các khoảng trắng dư thừa
{   
    for (int i=0; i<size;++i)
    {
        if (array[i]==' ' && array[i+1]==' ') //nếu xét tại ký tự hiện tại và kế tiếp đều là khoảng trắng
        {
            Xoa(array,size,i);//xóa khoảng trắng tại vị trí hiện tại
            i--; //giảm biến đếm để tiếp tục kiểm tra
        }
    }

    if (array[0]==' ') //nếu ký tự đầu tiên của chuỗi là khoảng trắng
        Xoa(array,size,0); //ta xóa khoảng trắng đó

    if (array[size-1]==' ') //nếu ký tự cuối cùng của chuỗi là khoảng trắng
        Xoa(array,size,size-1); //ta xóa khoảng trắng đó     
}

void ChuyenSangTitleCase(char array[], int size) //Hàm chuyển đổi chuỗi sang dạng Title Case
{
    for (int i=0; i<size; ++i)
    {
        if (islower(array[0])) array[0] = toupper(array[0]);//nếu ký tự đầu tiên của chuỗi là chữ thường thì chuyển sang hoa
        if (array[i-1]==' ') array[i] = toupper(array[i]);//xét một ký tự nếu ký tự trước nó là khoảng trắng thì chuyển sang hoa
        else array[i] = tolower(array[i]); //các ký tự còn lại ta sẽ để ở dạng chữ thường   
    }
}

void XoaNKyTu(char array[], int &size, int pos, int amount) //Hàm xóa n ký tự từ vị trí pos
{
    for (int i=0; i<amount; ++i) //ta tạo vòng lặp để xóa amount(số lượng) ký tự
    {
        Xoa(array,size,pos-1); //xóa ở vị trí pos - 1
        i--;
        amount--; //giảm amount và i cho đến khi xóa đủ số lượng
    }
}

void XoaTu(char array1[], int &size1, char array2[], int size2, int pos) //Hàm xóa các từ giống một từ có sẵn trong một xâu ký tự
{
    int n = 0; //khởi tạo biến đếm cho mảng tạm (mảng array2) là mảng sẽ chứa từ để dựa vào đó quét tìm trong mảng chính (array1) chứa câu được nhập
    int temp = 0; //biến tạm
    for (int i=pos; i<size1; ++i) //ta lặp từ vị trí ngay sau từ cần tìm
    {
        if (array1[i] == array2[n])
        {
            temp++; //ta đối chiếu từng ký tự với nhau, nếu giống thì ta tăng biến tạm
            if (temp==size2) //đến khi biến tạm bằng kích thước mảng tạm (tìm được từ)
            {
                XoaNKyTu(array1,size1,i-temp+1,temp+1); //Xóa từ đó trong mảng chính
            }
            n++; //tăng n để tiếp tục quét những ký tự sau
        }
    
        else //nếu không thỏa điều kiện trên, ta khởi tạo lại biến tạm và biến đếm của mảng tạm
        {
            temp = 0;
            n = 0;
        }
    } 
}

void XoaTuGiongNhau(char array[], int &size) ////Hàm xóa từ giống nhau, chỉ giữ lại một từ trong chuỗi
{
    char temparray[MAX];
    int tempsize = 0; //khởi tạo mảng tạm và biến kích thước mảng tạm
    for (int i=0; i<size; ++i)
    {
        if (array[i]!=' ')
        {
            temparray[tempsize] = array[i];
            tempsize++; //quét cho đến khi gặp khoảng trắng thì dừng (quét lấy từ) và đưa vào mảng 
        }
        
        else 
        {
            if (tempsize>0) //trường hợp quét được từ
            {
                XoaTu(array,size,temparray,tempsize,i);//gọi hàm xóa các từ giống với nó về sau
            }
            tempsize = 0;//khởi tạo lại kích thước mảng tạm để quét từ kế trong câu
        }
        
    }
}



















