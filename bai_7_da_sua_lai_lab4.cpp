#include <iostream>
#include <iomanip>
#include <math.h>
#include <set>
using namespace std;
const int MAX = 1000;
class HangHoa
{
	protected:
	    int Ma;
	    string TenHang;
	    long DonGia;
      public:
          HangHoa(int Ma = 0 , string TenHang = "xxx" , long DonGia = 0)
          {
          	this->Ma = Ma;
          	this->TenHang = TenHang;
          	this->DonGia = DonGia;
          }
          ~HangHoa()
          {
          	Ma = 0;
          	TenHang = "";
          	DonGia = 0;
          }
          friend istream& operator >>(istream &in , HangHoa &x)
          {
          	cout<<"Nhap Ma Hang Hoa : ";
         	in>>x.Ma;
         	cin.ignore();
         	cout<<"Nhap Ten Hang Hoa : ";
         	in>>x.TenHang;
         	cout<<"Nhap Don Gia : ";
         	in>>x.DonGia;
         	return in;
          }
          friend ostream& operator <<(ostream &out , HangHoa x)
          {
          	out<<"|"<<setw(10)<<left<<x.Ma<<"|"<<setw(20)<<left<<x.TenHang<<"|"<<setw(10)<<left<<x.DonGia<<"|";
          	return out;
          }
};
class MayTinh : public HangHoa
{
	protected:
	    float TocDo;
	    int SoLuong;
      public:
          MayTinh(int Ma = 0 , string TenHang = "xxx" , long DonGia = 0 , float TocDo = 0 , int SoLuong = 0)
          {
          	this->Ma = Ma;
          	this->TenHang = TenHang;
          	this->DonGia = DonGia;
          	this->TocDo = TocDo;
          	this->SoLuong = SoLuong;
          }
          ~MayTinh()
          {
          	Ma = 0;
          	TenHang = "";
          	DonGia = 0;
          	TocDo = 0;
	      SoLuong = 0;
          }
          friend istream& operator >>(istream &in , MayTinh &y)
          {
          	cout<<"Nhap Ma May Tinh : ";
         	in>>y.Ma;
         	cin.ignore();
         	cout<<"Nhap Ten May Tinh : ";
         	in>>y.TenHang;
         	cout<<"Nhap Don Gia : ";
         	in>>y.DonGia;
         	cout<<"Nhap Toc Do : ";
         	in>>y.TocDo;
         	cout<<"Nhap So Luong : ";
         	in>>y.SoLuong;
         	return in;
          }
          friend ostream& operator <<(ostream &out , MayTinh y)
          {
          	out<<"|"<<setw(10)<<left<<y.Ma<<"|"<<setw(20)<<left<<y.TenHang<<"|"<<setw(10)<<left<<y.DonGia;
            out<<"|"<<setw(10)<<left<<y.TocDo<<"|"<<setw(10)<<left<<y.SoLuong<<"|";          	
          	return out;
          }
          long long ThanhTien()
          {
          	return SoLuong*DonGia;
          }
           
};
class MayTinhXachTay : public MayTinh
{
	private:
	    float TrongLuong;
      public:
          MayTinhXachTay(int Ma = 0 , string TenHang = "xxx" , long DonGia = 0 , float TocDo = 0 , 
	    int SoLuong = 0 , float TrongLuong = 0)
          {
          	this->Ma = Ma;
          	this->TenHang = TenHang;
          	this->DonGia = DonGia;
          	this->TocDo = TocDo;
          	this->SoLuong = SoLuong;
          	this->TrongLuong = TrongLuong;
          }
          ~MayTinhXachTay()
          {
          	Ma = 0;
          	TenHang = "";
          	DonGia = 0;
          	TocDo = 0;
            SoLuong = 0;
          	TrongLuong = 0;
          }
          long PhiBaoTri()
          {
          	 return (DonGia*5)/100;
          }
          friend istream& operator >>(istream &in , MayTinhXachTay &z)
          {
          	cout<<"Nhap Ma May Tinh : ";
         	in>>z.Ma;
         	cin.ignore();
         	cout<<"Nhap Ten May Tinh : ";
         	in>>z.TenHang;
         	cout<<"Nhap Don Gia : ";
         	in>>z.DonGia;
         	cout<<"Nhap Toc Do : ";
         	in>>z.TocDo;
         	cout<<"Nhap So Luong : ";
         	in>>z.SoLuong;
         	cout<<"Nhap Trong Luong : ";
         	in>>z.TrongLuong;
         	cin.ignore();
         	return in;
          }
          friend ostream& operator <<(ostream &out , MayTinhXachTay z)
          {
          	out<<"|"<<setw(10)<<left<<z.Ma<<"|"<<setw(20)<<left<<z.TenHang<<"|"<<setw(10)<<left<<z.DonGia;
            out<<"|"<<setw(10)<<left<<z.TocDo<<"|"<<setw(10)<<left<<z.SoLuong<<"|"<<setw(10)<<left<<z.TrongLuong<<"|"<<endl;
		cout<<"-----------------------------------------------------------------------------"<<endl;          	
          	return out;
          }
          bool operator ==(int M)
 	    {
          	return this->Ma == M;
          }
          int getMa()
          {
          	return this->Ma;
          }
          string getName(){
          	   return this->TenHang;
          }
          float getTocDo(){
          	   return this->TocDo;
          }
          int setMa(int M)
          {
          	return this->Ma = M;
          }
          string setName(string T)
          {
          	return this->TenHang = T;
          }
          long setDonGia(long D)
          {
          	return this->DonGia = D;
          }
          float setTocDo(float TD)
 	    {
          	   return this->TocDo = TD;
          }
          int setSoLuong(int SL){
          	return this->SoLuong = SL;
          }
          float setTrongLuong(float TL)
 	    {
          	   return this->TrongLuong = TL;
          }
          
};
class CongTyMTXT
{
	private:
	    int n;
	    MayTinhXachTay ds_MTXT[MAX];
      public:
          void OutPut1();
          void OutPut2();
          void OutPut3();
          void OutPut4();
          void OutPut5();
          void OutPut6();
          void OutPut7();
          void OutPut8();
          void OutPut9();
};
void CongTyMTXT::OutPut1()
{
	cout<<"-->Nhap Vao So Luong May Tinh Xach Tay : ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"\n[+] Nhap Thong Tin Cho May Tinh Thu "<<i+1<<endl;
		cin>>ds_MTXT[i];
	}
	cout<<"\n                  *DANH SACH THONG TIN MAY TINH XACH TAY*                  "<<endl;
	cout<<"_____________________________________________________________________________"<<endl;
	cout<<"|"<<setw(10)<<left<<"MA"<<"|"<<setw(20)<<left<<"Ten MT";
      cout<<"|"<<setw(10)<<left<<"Don Gia"<<"|"<<setw(10)<<left<<"TocDo";
      cout<<"|"<<setw(10)<<left<<"SoLuong"<<"|"<<setw(10)<<left<<"TrongLuong"<<"|"<<endl;
      cout<<"-----------------------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		cout<<ds_MTXT[i];
	}
	
}
void CongTyMTXT::OutPut2()
{
	int Ma_X;
	cout<<"\n-->Nhap Vao Ma May Tinh Xach Tay Can Tim : ";
	cin >> Ma_X;
	cout<<"\n           *DANH SACH THONG TIN MAY TINH CO MAY DUOC NHAP VAO*           "<<endl;
	cout<<"_____________________________________________________________________________"<<endl;
	cout<<"|"<<setw(10)<<left<<"MA"<<"|"<<setw(20)<<left<<"Ten MT";
      cout<<"|"<<setw(10)<<left<<"Don Gia"<<"|"<<setw(10)<<left<<"TocDo";
      cout<<"|"<<setw(10)<<left<<"SoLuong"<<"|"<<setw(10)<<left<<"TrongLuong"<<"|"<<endl;
      cout<<"-----------------------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		if(ds_MTXT[i] == Ma_X) cout<<ds_MTXT[i];
	}
}
void CongTyMTXT::OutPut3()
{
	set<string> s;
	for(int i=0;i<n;i++){
		s.insert(ds_MTXT[i].getName());
	}
	for(set<string>::iterator it = s.begin() ; it != s.end() ; it++){
		cout<<"\n[+] May Tinh  "<<*it<<endl;
	      cout<<"_____________________________________________________________________________"<<endl;
		cout<<"|"<<setw(10)<<left<<"MA"<<"|"<<setw(20)<<left<<"Ten MT";
	      cout<<"|"<<setw(10)<<left<<"Don Gia"<<"|"<<setw(10)<<left<<"TocDo";
	      cout<<"|"<<setw(10)<<left<<"SoLuong"<<"|"<<setw(10)<<left<<"TrongLuong"<<"|"<<endl;
	      cout<<"-----------------------------------------------------------------------------"<<endl;
		for(int i=0;i<n;i++){
			if(*it == ds_MTXT[i].getName()){
				cout<<ds_MTXT[i];
			}
		}
	}
	
}
void CongTyMTXT::OutPut4()
{
	long  sum = 0;
	for(int i=0;i<n;i++){
		sum = sum + ds_MTXT[i].PhiBaoTri();
	}
	cout<<"\n[+] Tong Phi Bao Tri Cua Cac May Tinh La : "<<sum<<endl;
}
void CongTyMTXT::OutPut5()
{
	float x = ds_MTXT[0].getTocDo();
	for(int i=1;i<n;i++){
		if(x > ds_MTXT[i].getTocDo()){
			x = ds_MTXT[i].getTocDo();
		}
	}
	cout<<"\n            *DANH SACH THONG TIN MAY TINH CO TOC DO NHO NHAT*            "<<endl;
	cout<<"_____________________________________________________________________________"<<endl;
	cout<<"|"<<setw(10)<<left<<"MA"<<"|"<<setw(20)<<left<<"Ten MT";
      cout<<"|"<<setw(10)<<left<<"Don Gia"<<"|"<<setw(10)<<left<<"TocDo";
      cout<<"|"<<setw(10)<<left<<"SoLuong"<<"|"<<setw(10)<<left<<"TrongLuong"<<"|"<<endl;
      cout<<"-----------------------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		if(x == ds_MTXT[i].getTocDo()){
			cout<<ds_MTXT[i];
		}
	}
}
void CongTyMTXT::OutPut6()
{
	int k;
	cout<<"\n[+] Nhap Vao So May Thu K Can Sua : ";
	cin >> k;
	while(true)
	{
		cout<<"\n+----Cac Muc Co The Sua-----+"<<endl;
		cout<<"|1. Sua Ma May Tinh         |"<<endl;
		cout<<"|2. Sua Ten May Tinh        |"<<endl;
		cout<<"|3. Sua Don Gia             |"<<endl;
		cout<<"|4. Sua Toc Do              |"<<endl;
		cout<<"|5. Sua So Luong            |"<<endl;
		cout<<"|6. Sua Trong Luong         |"<<endl;
		cout<<"|0. Thoat                   |"<<endl;
		cout<<"+---------------------------+"<<endl;
		int luachon;
		cout<<"[+] Chon Muc Can Sua Cua May Tinh : ";
		cin>>luachon;
		cin.ignore();
		if(luachon == 1){
			int MaD;
			cout<<"\n[+] Nhap Vao Thong Tin Ma Can Sua : ";
			cin>>MaD;
			ds_MTXT[k-1].setMa(MaD);
		}
		else if(luachon == 2){
			string TenMT;
			cout<<"\n[+] Nhap Vao Thong Tin Ten Can Sua : ";
			getline(cin , TenMT);
			ds_MTXT[k-1].setName(TenMT);
		}
		else if(luachon == 3){
			long DG;
			cout<<"\n[+] Nhap Vao Thong Tin Don Gia Can Sua : ";
			cin>>DG;
			ds_MTXT[k-1].setDonGia(DG);
		}
		else if(luachon == 4){
			float TC;
			cout<<"\n[+] Nhap Vao Thong Tin Toc Do Can Sua : ";
			cin>>TC;
			ds_MTXT[k-1].setTocDo(TC);
		}
		else if(luachon == 5){
			int SL;
			cout<<"\n[+] Nhap Vao Thong Tin So Luong Can Sua : ";
			cin>>SL;
			ds_MTXT[k-1].setSoLuong(SL);
		}
		else if(luachon == 6){
			float TL;
			cout<<"\n[+] Nhap Vao Thong Tin Trong Luong Can Sua : ";
			cin>>TL;
			ds_MTXT[k-1].setTrongLuong(TL);
		}
		else if(luachon == 0){
			break;
		}
		else{
			cout<<"\n[+] Lua Chon Khong Hop Le. Moi Ban Nhap Lai Lua Chon !!"<<endl;
		}
	}
	cout<<"\n             *DANH SACH THONG TIN MAY TINH SAU KHI SUA LAI*                "<<endl;
	cout<<"_____________________________________________________________________________"<<endl;
	cout<<"|"<<setw(10)<<left<<"MA"<<"|"<<setw(20)<<left<<"Ten MT";
      cout<<"|"<<setw(10)<<left<<"Don Gia"<<"|"<<setw(10)<<left<<"TocDo";
      cout<<"|"<<setw(10)<<left<<"SoLuong"<<"|"<<setw(10)<<left<<"TrongLuong"<<"|"<<endl;
      cout<<"-----------------------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		cout<<ds_MTXT[i];
	}

}
void CongTyMTXT::OutPut7()
{
	int MaS;
	cout<<"\n[+] Nhap Vao Ma Cua May Tinh Can Xoa : ";
	cin>>MaS;
	for(int i=0;i<n;i++){
		if(ds_MTXT[i] == MaS){
			for(int j=i;j<n-1;j++){
				ds_MTXT[j] = ds_MTXT[j+1];
			}
			n--;
			if(ds_MTXT[i] == MaS) i--;
		}
	}
	cout<<"\n           *DANH SACH THONG TIN MAY TINH SAU KHI XOA THEO MA*              "<<endl;
	cout<<"_____________________________________________________________________________"<<endl;
	cout<<"|"<<setw(10)<<left<<"MA"<<"|"<<setw(20)<<left<<"Ten MT";
      cout<<"|"<<setw(10)<<left<<"Don Gia"<<"|"<<setw(10)<<left<<"TocDo";
      cout<<"|"<<setw(10)<<left<<"SoLuong"<<"|"<<setw(10)<<left<<"TrongLuong"<<"|"<<endl;
      cout<<"-----------------------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		cout<<ds_MTXT[i];
	}
}
void CongTyMTXT::OutPut8()
{
	int k;
	cout<<"\n[+] Nhap Vi Tri Can Chen Them 1 May Tinh Xach Tay : ";
	cin>>k;
	MayTinhXachTay x;
	cout<<"\n[+] Nhap Thong Tin Cua May Tinh Xach Tay Can Chen"<<endl;
	cin>>x;
	n++;
	int z = k-1;
	for(int i=n-1;i>z;i--){
		ds_MTXT[i] = ds_MTXT[i-1];
	}
	ds_MTXT[z]=x;
	cout<<"\n             *DANH SACH THONG TIN MAY TINH SAU KHI CHEN *                  "<<endl;
	cout<<"_____________________________________________________________________________"<<endl;
	cout<<"|"<<setw(10)<<left<<"MA"<<"|"<<setw(20)<<left<<"Ten MT";
      cout<<"|"<<setw(10)<<left<<"Don Gia"<<"|"<<setw(10)<<left<<"TocDo";
      cout<<"|"<<setw(10)<<left<<"SoLuong"<<"|"<<setw(10)<<left<<"TrongLuong"<<"|"<<endl;
      cout<<"-----------------------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		cout<<ds_MTXT[i];
	}
}
void CongTyMTXT::OutPut9()
{
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(ds_MTXT[i].getMa() > ds_MTXT[j].getMa()) swap(ds_MTXT[i],ds_MTXT[j]);
		}
	}
	cout<<"\n   *DANH SACH THONG TIN MAY TINH SAU KHI SAP XEP TANG DAN THEO MA *        "<<endl;
	cout<<"_____________________________________________________________________________"<<endl;
	cout<<"|"<<setw(10)<<left<<"MA"<<"|"<<setw(20)<<left<<"Ten MT";
      cout<<"|"<<setw(10)<<left<<"Don Gia"<<"|"<<setw(10)<<left<<"TocDo";
      cout<<"|"<<setw(10)<<left<<"SoLuong"<<"|"<<setw(10)<<left<<"TrongLuong"<<"|"<<endl;
      cout<<"-----------------------------------------------------------------------------"<<endl;
	for(int i=0;i<n;i++){
		cout<<ds_MTXT[i];
	}
}
int main()
{
	CongTyMTXT *x = new CongTyMTXT;
	while(true)
	{
		cout<<"\n+-------------------MENU--------------------------+"<<endl;
		cout<<"|1.[+] Nhap Danh Sach MTXT , Hien Thi Danh Sach   |"<<endl;
		cout<<"|2.[+] Tim Thong Tin MTXT Theo Ma Nhap Vao        |"<<endl;
		cout<<"|3.[+] Liet Ke MTXT Theo Ten                      |"<<endl;
		cout<<"|4.[+] Tinh Tong Chi Phi Bao Tri Cua Cac MTXT     |"<<endl;
		cout<<"|5.[+] Tim MTXT Co Toc Do Nho Nhat                |"<<endl;
		cout<<"|6.[+] Sua Thong Tin Mot May Tinh XT              |"<<endl;
		cout<<"|7.[+] Xoa Mot MTXT Theo Ma Cho Truoc             |"<<endl;
		cout<<"|8.[+] Chen Mot MTXT Tai Vi Tri K                 |"<<endl;
		cout<<"|9.[+] Sap Xep Danh Sach MTXT Tang Dan Theo Ma    |"<<endl;
		cout<<"|0.[+] thoat                                      |"<<endl;
		cout<<"+-------------------------------------------------+"<<endl;
		int luachon;
		cout<<"\n--> Nhap Lua Chon : ";
		cin>>luachon;
		cin.ignore();
		if(luachon == 1){
			x->OutPut1();
		}
		else if(luachon == 2){
			x->OutPut2();
		}
		else if(luachon == 3){
			x->OutPut3();
		}
		else if(luachon == 4){
			x->OutPut4();
		}
		else if(luachon == 5){
			x->OutPut5();
		}
		else if(luachon == 6){
			x->OutPut6();
		}
		else if(luachon == 7){
			x->OutPut7();
		}
		else if(luachon == 8){
			x->OutPut8();
		}
		else if(luachon == 9){
			x->OutPut9();
		}
		else if(luachon == 0){
			break;
		}
		else{
			cout<<"[+] Lua Chon Cua Ban Khong Hop Le!!! Xin Moi Nhap Lai"<<endl;
		}
		 
	}
	return 0;
}