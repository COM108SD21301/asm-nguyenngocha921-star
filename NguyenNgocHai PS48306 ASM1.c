#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int luaChon;
	printf("\nChào mừng bạn đến với ASM của tôi");
	printf("\nNhập 1: Lựa chọn chức năng Số nguyên");
	printf("\nNhập 2: Lựa chọn chức năng tìm UCLN và BCNN");
	printf("\nNhập 3: Lựa chọn chức năng Tính tiền quán Karaoke");
	printf("\nNhập 4: Lựa chọn chức năng Tính tiền điện");
	printf("\nNhập 6: Lựa chọn chức năng Tính lãi suất vay ngân hàng trả góp 12 tháng");
	printf("\nNhập 8: Lựa chọn chức năng Sắp xếp thông tin sinh viên");
	printf("\nNhập 10: Lựa chọn chức năng Tính toán phân số");
	printf("\nNhập 0: Thoát chương trình");
	printf("\nMời bạn nhập lựa chọn: ");
	scanf("%d",&luaChon);

	switch(luaChon){

		case 1:{
			printf("Bạn chọn CN1\n");
			float x;
			printf("Mời bạn nhập số x: "); 
			scanf("%f",&x);

			if (x==(int)x){
				printf("%.0f là số nguyên\n",x);

				for(int i=1; i<=x/2; i++){
					if (i*i==x) {
						printf("%.0f là số chính phương\n",x);
					}
				}
			}
			else 
				printf("%.2f là số thực\n",x);

			break;
		}

		case 2:{
			printf("Bạn chọn CN2: Tìm UCLN và BCNN của 2 số\n");

			int x, y;
			printf("Nhập số thứ nhất: ");
			scanf("%d", &x);
			printf("Nhập số thứ hai: ");
			scanf("%d", &y);

			if(x == 0 || y == 0){
				printf("Không thể tính UCLN/BCNN với số 0!\n");
				break;
			}

			// Tính UCLN bằng thuật toán Euclid
			int a = x, b = y;
			while(b != 0){
				int temp = b;
				b = a % b;
				a = temp;
			}
			int ucln = a;

			// Tính BCNN
			int bcnn = (x * y) / ucln;

			printf("UCLN(%d,%d) = %d\n", x, y, ucln);
			printf("BCNN(%d,%d) = %d\n", x, y, bcnn);

			break;
		}

		case 3:{
			printf("Bạn chọn CN3\n");

			int bd, kt;
			printf("Nhập giờ bắt đầu: ");
			scanf("%d", &bd);
			printf("Nhập giờ kết thúc: ");
			scanf("%d", &kt);

			if(bd < 12 || kt > 23 || bd >= kt){
				printf("Giờ không hợp lệ! Quán mở từ 12h đến 23h.\n");
				break;
			}

			int sogio = kt - bd;
			int tien = 0;

			if(sogio <= 3){
				tien = sogio * 150000;
			} else {
				tien = 3 * 150000 + (sogio - 3) * (150000 * 0.7);
			}

			if(bd >= 14 && bd <= 17){
				tien = tien * 0.9;
			}

			printf("Tổng tiền phải trả: %d VND\n", tien);
			break;
		}

		case 4:{
			printf("Bạn chọn CN4\n");

			int kwh;
			printf("Nhập số kWh đã sử dụng: ");
			scanf("%d", &kwh);

			if(kwh < 0){
				printf("Số kWh không hợp lệ!\n");
				break;
			}

			float tien = 0;

			if(kwh <= 50){
				tien = kwh * 1678;
			}
			else if(kwh <= 100){
				tien = 50 * 1678 + (kwh - 50) * 1734;
			}
			else if(kwh <= 200){
				tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
			}
			else if(kwh <= 300){
				tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
			}
			else if(kwh <= 400){
				tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
			}
			else{
				tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;
			}

			printf("Tiền điện phải trả: %.0f VND\n", tien);
			break;
		}

		case 6:{
			printf("Bạn chọn CN6: Tính lãi suất vay ngân hàng trả góp 12 tháng\n");

			double tienVay;
			printf("Nhập số tiền muốn vay: ");
			scanf("%lf", &tienVay);

			if (tienVay <= 0) {
				printf("Số tiền vay không hợp lệ!\n");
				break;
			}

			double laiSuatThang = 0.05;
			double gocTra = tienVay / 12;
			double conLai = tienVay;

			printf("Kỳ\tLãi\t\tGốc\t\tTổng\t\tCòn lại\n");
			for (int ky = 1; ky <= 12; ky++) {
				double laiThang = conLai * laiSuatThang;
				double tongTra = gocTra + laiThang;
				conLai -= gocTra;

				if (ky == 12) conLai = 0;

				printf("%2d\t%.0f\t\t%.0f\t\t%.0f\t\t%.0f\n", ky, laiThang, gocTra, tongTra, conLai);
			}

			break;
		}

		case 8:{
			printf("Bạn chọn CN8: Sắp xếp thông tin sinh viên\n");

			int n = 2;
			char ten[10][50];
			float diem[10];
			char hocLuc[10][20];

			for(int i=0; i<n; i++){
				printf("Nhập tên sinh viên %d: ", i+1);
				getchar();
				fgets(ten[i], sizeof(ten[i]), stdin);
				size_t len = strlen(ten[i]);
				if(len > 0 && ten[i][len-1] == '\n') ten[i][len-1] = '\0';

				printf("Nhập điểm sinh viên %d: ", i+1);
				scanf("%f", &diem[i]);

				if(diem[i] >= 9.0) strcpy(hocLuc[i], "Xuat sac");
				else if(diem[i] >= 8.0) strcpy(hocLuc[i], "Gioi");
				else if(diem[i] >= 6.5) strcpy(hocLuc[i], "Kha");
				else if(diem[i] >= 5.0) strcpy(hocLuc[i], "Trung binh");
				else strcpy(hocLuc[i], "Yeu");
			}

			for(int i=0; i<n-1; i++){
				for(int j=i+1; j<n; j++){
					if(diem[i] < diem[j]){
						float tmpDiem = diem[i];
						diem[i] = diem[j];
						diem[j] = tmpDiem;

						char tmpTen[50];
						strcpy(tmpTen, ten[i]);
						strcpy(ten[i], ten[j]);
						strcpy(ten[j], tmpTen);

						char tmpHocLuc[20];
						strcpy(tmpHocLuc, hocLuc[i]);
						strcpy(hocLuc[i], hocLuc[j]);
						strcpy(hocLuc[j], tmpHocLuc);
					}
				}
			}

			printf("\nThong tin sinh vien sau khi sap xep:\n");
			printf("STT\tTen\t\tDiem\tHoc luc\n");
			for(int i=0; i<n; i++){
				printf("%d\t%s\t\t%.1f\t%s\n", i+1, ten[i], diem[i], hocLuc[i]);
			}

			break;
		}

		case 10:{
			printf("Bạn chọn CN10: Tính toán phân số\n");

			int tu1, mau1, tu2, mau2;
			printf("Nhập phân số thứ nhất (tử / mẫu): ");
			scanf("%d/%d", &tu1, &mau1);
			printf("Nhập phân số thứ hai (tử / mẫu): ");
			scanf("%d/%d", &tu2, &mau2);

			if(mau1 == 0 || mau2 == 0){
				printf("Mẫu số không hợp lệ!\n");
				break;
			}

			int tongTu = tu1*mau2 + tu2*mau1;
			int tongMau = mau1 * mau2;

			int hieuTu = tu1*mau2 - tu2*mau1;
			int hieuMau = mau1 * mau2;

			int tichTu = tu1 * tu2;
			int tichMau = mau1 * mau2;

			int thuongTu = tu1 * mau2;
			int thuongMau = tu2 * mau1;
			if(thuongMau == 0){
				printf("Không thể chia cho 0!\n");
			}

			printf("\nKet qua:\n");
			printf("Tong: %d/%d\n", tongTu, tongMau);
			printf("Hieu: %d/%d\n", hieuTu, hieuMau);
			printf("Tich: %d/%d\n", tichTu, tichMau);
			if(thuongMau != 0)
				printf("Thuong: %d/%d\n", thuongTu, thuongMau);

			break;
		}

		case 0:{
			return 0;
		}

		default: 
			printf("\nYou chose wrong\n"); 
			break;  
	}

	system("pause"); 
	return 0;
}
