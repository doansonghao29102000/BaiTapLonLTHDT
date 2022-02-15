// Doan Song Hao_20103100669
#include <iostream>
#include <iomanip>
#include <fstream>
int const MAX = 1000;
using namespace std;
class PTGT
{
	protected:
	    string HangSanXuat;
	    string NgayXuatXuong; //  dd/mm/yyyy
	    long long GiaChuaThue;
      public:
          PTGT(string HangSanXuat="xxx" , string NgayXuatXuong = "dd/mm/yyyy" , long GiaChuaThue = 1)
    	    {
          	   this->HangSanXuat = HangSanXuat;
          	   this->NgayXuatXuong = NgayXuatXuong;
          	   this->GiaChuaThue = GiaChuaThue;
          }
          ~PTGT()
    	    {
          	   HangSanXuat = NgayXuatXuong = "";
          	   GiaChuaThue = 0;
          }
          void Nhap()
          {
          	   cout<<"Nhap Hang San Xuat : ";
          	   getline(cin, HangSanXuat);
          	   cout<<"Nhap Ngay Xuat Xuong : ";  //  dd/mm/yyyy
          	   getline(cin, NgayXuatXuong);
          	   cout<<"Nhap Gia Chua Thue : ";
          	   cin>>GiaChuaThue;
          	   cin.ignore();
          }
          void In()
          {
          	   cout<<"|"<<setw(15)<<left<<HangSanXuat<<"|"<<setw(20)<<left<<NgayXuatXuong;
               cout<<"|"<<setw(15)<<left<<GiaChuaThue<<"|"<<endl;
               cout<<"----------------------------------------------------------------"<<endl;
          }
          void Doc_File(ifstream &file_in)
          {
          	   getline(file_in, HangSanXuat , ',');
          	   getline(file_in, NgayXuatXuong , ',');
          	   file_in >> GiaChuaThue;
          }
          void Ghi_File(ofstream &file_out)
          {
          	   file_out<<"|"<<setw(15)<<left<<HangSanXuat<<"|"<<setw(20)<<left<<NgayXuatXuong;
               file_out<<"|"<<setw(15)<<left<<GiaChuaThue<<"|";
          }
          
};

class XEKHACH : public PTGT
{
	private:
	    string SoTuyen;
	    int SoGhe;
	    string NoiDKKinhDoanh;
      public:
          XEKHACH(string HangSanXuat = "xxx" , string NgayXuatXuong = "dd/mm/yyyy" , long GiaChuaThue = 1 ,
          string SoTuyen = "01abc" , int SoGhe = 1 , string NoiDKKinhDoanh = "city x")
    	    {
          	   this->HangSanXuat = HangSanXuat;
          	   this->NgayXuatXuong = NgayXuatXuong;
          	   this->GiaChuaThue = GiaChuaThue;
          	   this->SoTuyen = SoTuyen;
          	   this->SoGhe = SoGhe;
          	   this->NoiDKKinhDoanh = NoiDKKinhDoanh;
          }
          ~XEKHACH()
    	    {
          	   HangSanXuat = NgayXuatXuong = SoTuyen = NoiDKKinhDoanh = "";
          	   GiaChuaThue = SoGhe = 0;
          }
          friend istream &operator >>(istream &is, XEKHACH &x)
    	    {
   	         cout<<"\n\tNhap Hang San Xuat Cua Xe Khach : ";
          	   getline(is, x.HangSanXuat);
          	   cout<<"\n\tNhap Ngay Xuat Xuong Cua Xe Khach : ";   //  dd/mm/yyyy
          	   getline(is, x.NgayXuatXuong);
          	   cout<<"\n\tNhap Gia Chua Thue Cua Xe Khach : ";
          	   is>>x.GiaChuaThue;
          	   is.ignore();
          	   cout<<"\n\tNhap So Tuyen Cua Xe Khach : ";
          	   getline(is, x.SoTuyen);
          	   cout<<"\n\tNhap So Ghe Cua Xe Khach : ";
          	   is>>x.SoGhe;
          	   is.ignore();
          	   cout<<"\n\tNhap Noi Dang Ky Kinh Doanh Cua Xe Khach : ";
          	   getline(is, x.NoiDKKinhDoanh);
          	   return is;
          }
          long long GiaSauThue()
          {
          	   return GiaChuaThue + (GiaChuaThue/100)*8; 
          }
          bool operator <(int x){
     	         return (this->SoGhe < x);
          }
          friend ostream &operator <<(ostream &os, XEKHACH x)
          {
     	         os<<"|"<<setw(15)<<left<<x.HangSanXuat<<"|"<<setw(20)<<left<<x.NgayXuatXuong;
               os<<"|"<<setw(15)<<left<<x.GiaChuaThue<<"|"<<setw(15)<<left<<x.SoTuyen;
               os<<"|"<<setw(10)<<left<<x.SoGhe<<"|"<<setw(20)<<left<<x.NoiDKKinhDoanh;
		   os<<"|"<<setw(15)<<left<<x.GiaSauThue()<<"|"<<endl;
               os<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
               return os;
          }
          string getNDKKD()
          {
     	           return NoiDKKinhDoanh;
          }
          string getHSX()
          {
          	     return HangSanXuat;
          }
          string getNXS()
          {
   	           return NgayXuatXuong;
          }
          void Doc_File(ifstream &file_in)
          {
          	   PTGT::Doc_File(file_in);
          	   file_in.ignore();
          	   getline(file_in , SoTuyen , ',');
          	   file_in >> SoGhe;
          	   file_in.ignore();
          	   getline(file_in , NoiDKKinhDoanh , '.');
          	   file_in.ignore();
          }
          void Ghi_File(ofstream &file_out)
          {
          	   PTGT::Ghi_File(file_out);
          	   file_out<<setw(15)<<left<<SoTuyen<<"|"<<setw(10)<<left<<SoGhe<<"|";
               file_out<<setw(20)<<left<<NoiDKKinhDoanh<<"|"<<setw(15)<<left<<GiaSauThue()<<"|"<<endl;
               file_out<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
          }
};

class QUANLYXEKHACH
{
	private:
	    int n; // so luong cac xe khach 
	    XEKHACH arr[MAX]; // mang chua thong tin so luong cac xe khach
	    int k; // nhap vi tri can tren xe co hang san xuat TOYOTA vao danh danh theo yeu cau cua y 4 trong de bai
	    XEKHACH TOYOTA;// bien de gan thong tin cua xe co hang san xuat TOYOTA nhap tu file theo yeu cao cua y 4 trong de bai
      public:
          void Input();
          void OutPut1();
          void OutPut2();
          void OutPut3();
          void OutPut4();
          void OutPut5();
          void DocTep();
	    void GhiTep();   
};
void QUANLYXEKHACH::Input()
{
	cout<<"\n ===> NHAP VAO SO LUONG XE KHACH : ";cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++){
		cout<<"\n + Nhap Vao Thong Tin Xe Khach Thu "<<i+1<<endl;
		cin >> arr[i];
	}
}
void QUANLYXEKHACH::OutPut1()
{
      cout<<"\n\n                                   * DANH SACH THONG TIN CAC XE KHACH DA NHAP *                                       "<<endl;
	cout<<"______________________________________________________________________________________________________________________"<<endl;
	cout<<"|"<<setw(15)<<left<<"HangSanXuat"<<"|"<<setw(20)<<left<<"NgayXuatXuong";
      cout<<"|"<<setw(15)<<left<<"GiaChuaThue"<<"|"<<setw(15)<<left<<"SoTuyen";
      cout<<"|"<<setw(10)<<left<<"SoGhe"<<"|"<<setw(20)<<left<<"NoiDangKyKinhDoanh";
	cout<<"|"<<setw(15)<<left<<"GiaSauThue"<<"|"<<endl;
      cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		cout << arr[i];
	}
}
void QUANLYXEKHACH::OutPut2()
{
	cout<<"\n\n                         * DANH SACH THONG TIN CAC XE KHACH DANG KY KINH DOANH TAI NAM DINH *                        "<<endl;
	cout<<"______________________________________________________________________________________________________________________"<<endl;
	cout<<"|"<<setw(15)<<left<<"HangSanXuat"<<"|"<<setw(20)<<left<<"NgayXuatXuong";
      cout<<"|"<<setw(15)<<left<<"GiaChuaThue"<<"|"<<setw(15)<<left<<"SoTuyen";
      cout<<"|"<<setw(10)<<left<<"SoGhe"<<"|"<<setw(20)<<left<<"NoiDangKyKinhDoanh";
	cout<<"|"<<setw(15)<<left<<"GiaSauThue"<<"|"<<endl;
      cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
      for(int i=0;i<n;i++){
		if(arr[i].getNDKKD() == "Nam Dinh"){
			cout << arr[i];
		}
	}
}
void QUANLYXEKHACH::OutPut3()
{
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			if(arr[i].GiaSauThue() > arr[j].GiaSauThue()){
				XEKHACH tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	cout<<"\n\n                     * DANH SACH THONG TIN CAC XE KHACH THEO THU TU TANG DAN CUA GIA SAU THUE *                      "<<endl;
	cout<<"______________________________________________________________________________________________________________________"<<endl;
	cout<<"|"<<setw(15)<<left<<"HangSanXuat"<<"|"<<setw(20)<<left<<"NgayXuatXuong";
      cout<<"|"<<setw(15)<<left<<"GiaChuaThue"<<"|"<<setw(15)<<left<<"SoTuyen";
      cout<<"|"<<setw(10)<<left<<"SoGhe"<<"|"<<setw(20)<<left<<"NoiDangKyKinhDoanh";
	cout<<"|"<<setw(15)<<left<<"GiaSauThue"<<"|"<<endl;
      cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		cout << arr[i];
	}
}
void QUANLYXEKHACH::OutPut4()
{
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(arr[i].getHSX() == "TOYOTA"){
			cnt++;
		}
	}
	if(cnt != 0) cout<<"Da Co Xe Khach Co Hang San Xuat La TOYOTA Trong Danh Sach!!"<<endl; 
	else{
		cout<<"Nhap Vao Vi Tri Dung Truoc Vi Tri Can Chen : ";cin>>k; // vi tri chen tinh tu 1,2,3..n
		cin.ignore();
		if(k < 1 || k > n) cout<<"\n\n\t*NODE: Vi Tri Chen Khong Hop Le!!!"<<endl;
		else{
			cin >> TOYOTA ;// Nhap hang san xua la :TOYOTA
			for(int i=n;i>=k;i--){
				arr[i] = arr[i-1];
			}
			arr[k] = TOYOTA;
			n++;
			cout<<"\n\n                  * DANH SACH THONG TIN CAC XE KHACH SAU KHI DA CHEN XE CO HANG SAN XUAT LA TOYOTA *              "<<endl;
			cout<<"______________________________________________________________________________________________________________________"<<endl;
			cout<<"|"<<setw(15)<<left<<"HangSanXuat"<<"|"<<setw(20)<<left<<"NgayXuatXuong";
		      cout<<"|"<<setw(15)<<left<<"GiaChuaThue"<<"|"<<setw(15)<<left<<"SoTuyen";
		      cout<<"|"<<setw(10)<<left<<"SoGhe"<<"|"<<setw(20)<<left<<"NoiDangKyKinhDoanh";
			cout<<"|"<<setw(15)<<left<<"GiaSauThue"<<"|"<<endl;
		      cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
			for(int i=0;i<n;i++){
				cout << arr[i];
			}
			
		}
	}
}
void QUANLYXEKHACH::OutPut5()
{
	for(int i=0;i<n;i++){
		string s = arr[i].getNXS();
		if(int(s[s.size()-4]) < 50){
			int vitrixoa = i;
			for(int j=vitrixoa;j<n;j++){
				arr[j] = arr[j+1];
			}
			n--;
			if(int(s[s.size()-4]) < 50){
				i--;
			}
		}
	}
	cout<<"\n\n                     * DANH SACH THONG TIN CAC XE KHACH CO NGAY XUAT XUONG SAU 01/01/2000 *                       "<<endl;
	cout<<"______________________________________________________________________________________________________________________"<<endl;
	cout<<"|"<<setw(15)<<left<<"HangSanXuat"<<"|"<<setw(20)<<left<<"NgayXuatXuong";
      cout<<"|"<<setw(15)<<left<<"GiaChuaThue"<<"|"<<setw(15)<<left<<"SoTuyen";
      cout<<"|"<<setw(10)<<left<<"SoGhe"<<"|"<<setw(20)<<left<<"NoiDangKyKinhDoanh";
	cout<<"|"<<setw(15)<<left<<"GiaSauThue"<<"|"<<endl;
      cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		cout << arr[i];
	}	
}
void QUANLYXEKHACH::DocTep()
{
	ifstream file_in;
	file_in.open("DoanSongHao_input.txt", ios_base::in);
	file_in >> n;
	file_in.ignore();
	for(int i=0;i<n;i++){
		arr[i].Doc_File(file_in);
	}
	file_in >> k; // cac vi tri co the tren vao sau la 1,2,...,n
	file_in.ignore();
	TOYOTA.Doc_File(file_in);
	file_in.close();
}
void QUANLYXEKHACH::GhiTep()
{
	ofstream file_out;
	file_out.open("DoanSongHao_output.txt", ios_base::out);
	
	// y 1 de bai
	file_out<<"\n\n                                   * DANH SACH THONG TIN CAC XE KHACH DA NHAP *                                       "<<endl;
	file_out<<"______________________________________________________________________________________________________________________"<<endl;
	file_out<<"|"<<setw(15)<<left<<"HangSanXuat"<<"|"<<setw(20)<<left<<"NgayXuatXuong";
      file_out<<"|"<<setw(15)<<left<<"GiaChuaThue"<<"|"<<setw(15)<<left<<"SoTuyen";
      file_out<<"|"<<setw(10)<<left<<"SoGhe"<<"|"<<setw(20)<<left<<"NoiDangKyKinhDoanh";
	file_out<<"|"<<setw(15)<<left<<"GiaSauThue"<<"|"<<endl;
      file_out<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		arr[i].Ghi_File(file_out);
	}
	
	// y 2 de bai
	file_out<<"\n\n                         * DANH SACH THONG TIN CAC XE KHACH DANG KY KINH DOANH TAI NAM DINH *                        "<<endl;
	file_out<<"______________________________________________________________________________________________________________________"<<endl;
	file_out<<"|"<<setw(15)<<left<<"HangSanXuat"<<"|"<<setw(20)<<left<<"NgayXuatXuong";
      file_out<<"|"<<setw(15)<<left<<"GiaChuaThue"<<"|"<<setw(15)<<left<<"SoTuyen";
      file_out<<"|"<<setw(10)<<left<<"SoGhe"<<"|"<<setw(20)<<left<<"NoiDangKyKinhDoanh";
	file_out<<"|"<<setw(15)<<left<<"GiaSauThue"<<"|"<<endl;
      file_out<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
      for(int i=0;i<n;i++){
		if(arr[i].getNDKKD() == "Nam Dinh"){
			file_out<<arr[i];
		}
	}
	
	// y 3 de bai
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			if(arr[i].GiaSauThue() > arr[j].GiaSauThue()){
				XEKHACH tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	file_out<<"\n\n                     * DANH SACH THONG TIN CAC XE KHACH THEO THU TU TANG DAN CUA GIA SAU THUE *                      "<<endl;
	file_out<<"______________________________________________________________________________________________________________________"<<endl;
	file_out<<"|"<<setw(15)<<left<<"HangSanXuat"<<"|"<<setw(20)<<left<<"NgayXuatXuong";
      file_out<<"|"<<setw(15)<<left<<"GiaChuaThue"<<"|"<<setw(15)<<left<<"SoTuyen";
      file_out<<"|"<<setw(10)<<left<<"SoGhe"<<"|"<<setw(20)<<left<<"NoiDangKyKinhDoanh";
	file_out<<"|"<<setw(15)<<left<<"GiaSauThue"<<"|"<<endl;
      file_out<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		file_out<<arr[i];
	}
	// y 4 de bai
	
      int cnt = 0;
	for(int i=0;i<n;i++){
		if(arr[i].getHSX() == "TOYOTA"){
			cnt++;
		}
	}
	if(cnt != 0) file_out<<"\n\n\t*NOTE: Da Co Xe Khach Co Hang San Xuat La TOYOTA Trong Danh Sach!!!"<<endl; 
	else{
		if(k < 1 || k > n) cout<<"\n\n\t*NOTE: Vi Tri Chen Khong Hop Le!!!"<<endl;
		else{
			for(int i=n;i>=k;i--){
				arr[i] = arr[i-1];
			}
			arr[k] = TOYOTA;
			n++;
			file_out<<"\n\n                  * DANH SACH THONG TIN CAC XE KHACH SAU KHI DA CHEN XE CO HANG SAN XUAT LA TOYOTA *              "<<endl;
			file_out<<"______________________________________________________________________________________________________________________"<<endl;
			file_out<<"|"<<setw(15)<<left<<"HangSanXuat"<<"|"<<setw(20)<<left<<"NgayXuatXuong";
		      file_out<<"|"<<setw(15)<<left<<"GiaChuaThue"<<"|"<<setw(15)<<left<<"SoTuyen";
		      file_out<<"|"<<setw(10)<<left<<"SoGhe"<<"|"<<setw(20)<<left<<"NoiDangKyKinhDoanh";
			file_out<<"|"<<setw(15)<<left<<"GiaSauThue"<<"|"<<endl;
		      file_out<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
			for(int i=0;i<n;i++){
				file_out << arr[i];
			}
			
		}
	}
	// y 5 de bai
	for(int i=0;i<n;i++){
		string s = arr[i].getNXS();
		if(int(s[s.size()-4]) < 50){
			int vitrixoa = i;
			for(int j=vitrixoa;j<n;j++){
				arr[j] = arr[j+1];
			}
			n--;
			if(int(s[s.size()-4]) < 50){
				i--;
			}
		}
	}
	file_out<<"\n\n                     * DANH SACH THONG TIN CAC XE KHACH CO NGAY XUAT XUONG SAU 01/01/2000 *                       "<<endl;
	file_out<<"______________________________________________________________________________________________________________________"<<endl;
	file_out<<"|"<<setw(15)<<left<<"HangSanXuat"<<"|"<<setw(20)<<left<<"NgayXuatXuong";
      file_out<<"|"<<setw(15)<<left<<"GiaChuaThue"<<"|"<<setw(15)<<left<<"SoTuyen";
      file_out<<"|"<<setw(10)<<left<<"SoGhe"<<"|"<<setw(20)<<left<<"NoiDangKyKinhDoanh";
	file_out<<"|"<<setw(15)<<left<<"GiaSauThue"<<"|"<<endl;
      file_out<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		file_out << arr[i];
	}
	file_out.close();	
}

int main()
{
	QUANLYXEKHACH *x = new QUANLYXEKHACH;
	while(true){
		cout<<"\n================================MENU=================================="<<endl;
		cout<<"|1.Nhap Thong Tin Danh Sach Xe Khach Tu Ban Phim                     |"<<endl;
		cout<<"|2.In Ra Thong Tin Danh Sach Xe Khach                                |"<<endl;
		cout<<"|3.In Ra Thong Tin Danh Sach Xe Khach Dang Ky Kinh Doanh Tai Nam Dinh|"<<endl;
		cout<<"|4.In Ra Thong Tin Danh Sach Xe Khach Tang Dan Theo Gia Sau Thue     |"<<endl;
		cout<<"|5.Chen Mot Xe Khach Co Hang San Xuat TOYOTA Vao Sao Vi Tri Thu K    |"<<endl;
		cout<<"|6.Xoa Khoi Danh Sach Cac Xe Khach Xuat Xuong Truoc Ngay 01/01/2000  |"<<endl;
		cout<<"|7.Doc Thong Tin Danh Sach Xe Khach Tu File DoanSongHao_input.txt    |"<<endl;
		cout<<"|8.Ghi Thong Tin Danh Sach Xe Khach Vao File DoanSongHao_output.txt  |"<<endl;
		cout<<"|0.Thoat                                                             |"<<endl;
		cout<<"================================END==================================="<<endl;
		int luachon;
		cout<<"\n\tNhap Lua Chon : ";cin>>luachon;
		cin.ignore();
		if(luachon == 1){
			x->Input();
		}
		else if(luachon == 2){
		      x->OutPut1();
		}
		else if(luachon == 3){
			x->OutPut2();
		}
		else if(luachon == 4){
			x->OutPut3();
		}
		else if(luachon == 5){
			x->OutPut4();
		}
		else if(luachon == 6){
			x->OutPut5();
		}
		else if(luachon == 7){
                  x->DocTep();
		}
		else if(luachon == 8){
			x->GhiTep();
		}
		else if(luachon == 0){
			break;
		}
		else{
			cout<<"\n\tLua Chon Khong Hop Le. Moi Ban Nhap Lai Lua Chon!!!";
		}
	}
	return 0;
}