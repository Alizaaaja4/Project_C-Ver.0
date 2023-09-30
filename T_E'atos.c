#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *data_menu;
FILE *data_menut;
FILE *data_driver;
FILE *data_drivert;
FILE *data_takeaway;
FILE *data_delivery;
FILE *data_pesan;
FILE *data_pesant;
FILE *data_pelayan;
FILE *data_user;
FILE *data_usert;

void teatos(), program(), login_admin(), menu_user(), info();
void menu_admin(), menu_pilihadmin(), menu_pilihpelayan();
void admin_takeaway(), admin_delivery(), nomor_antrian();
void registrasi_pelayan(), login_takeaway(), login_delivery(), menu_pelayantakeaway(), menu_pelayandelivery();
void tambah_menu(), baca_menu(), hapus_menu(), tambah_driver(), baca_driver(), hapus_driver();
void menu_user(), login_user(), registrasi_user(), menu_pilihuser(), user_takeaway(), user_delivery();
void pesan_takeaway(), pesan_delivery(), baca_user(), bill(), pesan_makanan();
void login_gagal(), logout(), nomore();
int i, j, n, pilihan, ulang_login, size;
char nama[100], uname[100], pass[100];

struct makanan{
    char nama[100];
    int harga;
} menu, menu2[50];

struct pesan{
    char nama[100];
    char username[100];
    char password[100];
    char makanan[100];
    int harga;
} user, tempuser[50], temp;

struct pelayan{
    char nama[100];
    char username[100];
    char password[100];
} pelayan[50];

struct driver{
    char nama[100];
    char plat[50];
    int telp;
} driver;

int main(){
    teatos();
    program();
}

void program(){
	printf("\n");
    printf("MENU: \n");
    printf("[1] ADMIN \n");
    printf("[2] USER\n");
    printf("[3] INFO\n");
    printf("[0] EXIT\n");
    printf("Pilihan: "); scanf("%d", &pilihan); getchar();

    switch(pilihan){
        case 1: ulang_login = 3; login_admin(); break;
        case 2: menu_user(); break;
        case 3: info(); break;
        case 0: return; break;
        default: printf("Pilihan tidak tersedia\n"); system("pause"); program();
    }
}

void login_admin(){
    system("cls");
    printf("Login Admin\n");
    if (ulang_login > 0){
        fflush(stdin);
        printf("Kesempatan login anda %d kali\n", ulang_login);
        printf("Username: "); gets(uname);
        printf("Password: "); gets(pass);
        
        if(strcmp("admin", uname) == 0 && strcmp("123", pass) == 0){
            printf("Login Sukses!\n");
            system("pause"); menu_admin();
            return;
        }
        system("cls"); login_gagal();
        ulang_login--;
        login_admin();
    }

    else{
        system("cls"); nomore();
        program();
    }
}

void menu_admin(){
    system("cls");
    printf("Menu Admin\n");
    printf("[1] Restaurant\n");
    printf("[2] Pelayan\n");
    printf("[0] Kembali\n");
    printf("Pilihan: "); scanf("%d", &pilihan); getchar();

    switch(pilihan){
        case 1: menu_pilihadmin(); break;
        case 2: menu_pilihpelayan(); break;
        case 0: logout(); program(); break;
        default: printf("Pilihan tidak tersedia\n"); system("pause"); menu_admin();
    }
}

void menu_pilihadmin(){
    system("cls");
    printf("Restaurant\n");
    printf("[1] Takeaway\n");
    printf("[2] Delivery\n");
    printf("[0] Kembali\n");
    printf("Pilihan: "); scanf("%d", &pilihan); getchar();

    switch(pilihan){
        case 1: admin_takeaway(); break;
        case 2: admin_delivery(); break;
        case 0: menu_admin(); break;
        default: printf("Pilihan tidak tersedia\n"); system("pause"); menu_pilihadmin();
    }
}

void admin_takeaway(){
    system("cls");
    printf("Admin Takeaway\n");
    printf("[1] Tambah Menu\n");
    printf("[2] Hapus Menu\n");
    printf("[3] No. Antrian\n");
    printf("[0] Kembali\n");
    printf("Pilihan: "); scanf("%d", &pilihan); getchar();

    switch(pilihan){
        case 1: tambah_menu(); break;
        case 2: hapus_menu(); break;
        case 3: nomor_antrian(); break;
        case 0: menu_pilihadmin(); break;
        default: printf("Pilihan tidak tersedia\n"); system("pause"); admin_takeaway();
    }
}

void admin_delivery(){
    system("cls");
    printf("Admin Delivery\n");
    printf("[1] List Driver\n");
    printf("[2] Bill User Delivery\n");
    printf("[0] Kembali\n");
    printf("Pilihan: "); scanf("%d", &pilihan); getchar();

    switch(pilihan){
        case 1: baca_driver(); break;
        case 2: baca_user(); break;
        case 0: menu_pilihadmin(); break;
        default: printf("Pilihan tidak tersedia\n"); system("pause"); admin_delivery();
    }
}

void menu_pilihpelayan(){
    system("cls");
    printf("Pelayan\n");
    printf("[1] Registrasi Pelayan\n");
    printf("[2] Login Pelayan Takeaway\n");
    printf("[3] Login Pelayan Delivery\n");
    printf("[0] Kembali\n");
    printf("Pilihan: "); scanf("%d", &pilihan); getchar();

    switch(pilihan){
        case 1: registrasi_pelayan(); break;
        case 2: ulang_login = 3; login_takeaway(); break;
        case 3: ulang_login = 3; login_delivery(); break;
        case 0: menu_admin(); break;
        default: printf("Pilihan tidak tersedia\n"); system("pause"); menu_pilihpelayan();
    }
}

void registrasi_pelayan(){
    int n;
    system("cls");
    data_pelayan = fopen("T_Eatos_Pelayan.dat", "ab");
    printf("Registrasi Pelayan\n");
    printf("Masukkan 0 untuk membatalkan\n");
    printf("Jumlah akun : "); scanf("%d", &n); getchar();
    printf("\n");
    
    if(n == 0){
        fclose(data_pelayan); menu_pilihpelayan();
    }
    else{
        for(i=0; i<n; i++){
            printf("Nama        : "); gets(pelayan[i].nama);
            printf("Username    : "); gets(pelayan[i].username);
            printf("Password    : "); gets(pelayan[i].password);
            fwrite(&pelayan, sizeof(pelayan), 1, data_pelayan);
            printf("\n");
        }
    }
    fclose(data_pelayan);
    printf("Akun berhasil didaftarkan!\n");
    system("pause");
    menu_pilihpelayan();
}

void login_takeaway(){
    system("cls");
    printf("Login Pelayan Takeaway\n");

    if(ulang_login > 0){
        fflush(stdin);
        data_pelayan = fopen("T_Eatos_Pelayan.dat", "rb");
        printf("Kesempatan login anda %d kali\n", ulang_login);
        printf("Nama        : "); gets(nama);
        printf("Username    : "); gets(uname);
        printf("Password    : "); gets(pass);
        printf("\n");

        while(fread(&pelayan, sizeof(pelayan), 1, data_pelayan))
        {
            size++;
        }

        for(i=0; i<size; i++){
            if((strcmp(uname, pelayan[i].username) == 0 && strcmp(pass, pelayan[i].password)) == 0){
                printf("Login Sukses!\n"); fclose(data_pelayan);
                system("pause"); menu_pelayantakeaway();
                return;
            }
            system("cls"); login_gagal();
            ulang_login--;
            login_takeaway();
        }
    }

    else{
        system("cls"); nomore();
        menu_pilihpelayan();
    }
}

void login_delivery(){
    system("cls");
    printf("Login Pelayan Delivery\n");

    if(ulang_login > 0){
        fflush(stdin);
        data_pelayan = fopen("T_Eatos_Pelayan.dat", "rb");
        printf("Kesempatan login anda %d kali\n", ulang_login);
        printf("Nama        : "); gets(nama);
        printf("Username    : "); gets(uname);
        printf("Password    : "); gets(pass);
        printf("\n");

        while(fread(&pelayan, sizeof(pelayan), 1, data_pelayan))
        {
            size++;
        }

        for(i=0; i<size; i++){
            if((strcmp(uname, pelayan[i].username) == 0 && strcmp(pass, pelayan[i].password)) == 0){
                printf("Login Sukses!\n"); fclose(data_pelayan);
                system("pause"); menu_pelayandelivery();
                return;
            }
            system("cls"); login_gagal();
            ulang_login--;
            login_delivery();
        }
    }

    else{
        system("cls"); nomore();
        menu_pilihpelayan();
    }
}

void menu_pelayantakeaway(){
    system("cls");
    printf("Pelayan Takeaway\n");
    printf("[1] Bill User Takeaway\n");
    printf("[2] No. Antrian\n");
    printf("[0] Kembali\n");
    printf("Pilihan: "); scanf("%d", &pilihan); getchar();

    switch(pilihan){
        case 1: baca_user(); break;
        case 2: nomor_antrian(); break;
        case 0: menu_pilihpelayan(); break;
        default: printf("Pilihan tidak tersedia\n"); system("pause"); menu_pelayantakeaway();
    }
}

void menu_pelayandelivery(){
    system("cls");
    printf("Pelayan Delivery\n");
    printf("[1] Tambah Driver\n");
    printf("[2] Hapus Driver\n");
    printf("[3] List Customer\n");
    printf("[0] Kembali\n");
    printf("Pilihan: "); scanf("%d", &pilihan); getchar();

    switch(pilihan){
        case 1: tambah_driver(); break;
        case 2: hapus_driver(); break;
        case 3: baca_user(); menu_pelayandelivery(); break;
        case 0: menu_pilihpelayan(); break;
        default: printf("Pilihan tidak tersedia\n"); system("pause"); menu_pelayandelivery();
    }
}

void menu_user(){
    system("cls");
    printf("Menu User\n");
    printf("[1] Sign Up\n");
    printf("[2] Login\n");
    printf("[0] Kembali\n");
    printf("Pilihan: "); scanf("%d", &pilihan);

    switch(pilihan){
        case 1: registrasi_user(); break;
        case 2: ulang_login = 3; login_user(); break;
        case 0: program(); break;
        default: printf("Pilihan tidak tersedia\n"); system("pause"); menu_user();
    }
}

void registrasi_user(){
    int n;
    system("cls");
    data_user = fopen("T_Eatos_User.dat", "ab");
    printf("Registrasi User\n");
    printf("Masukkan 0 untuk membatalkan\n");
    printf("Jumlah akun : "); scanf("%d", &n); getchar();
    printf("\n");

    if(n == 0){
        fclose(data_user); menu_user();
    }
    else{
        for(i=0; i<n; i++){
            printf("Nama        : "); gets(user.nama);
            printf("Username    : "); gets(user.username);
            printf("Password    : "); gets(user.password);
            fwrite(&user, sizeof(user), 1, data_user);
            printf("\n");
        }
    }
    fclose(data_user);
    printf("Akun berhasil didaftarkan!\n");
    system("pause");
    menu_user();
}

void login_user(){
    system("cls");
    printf("Login User\n");

    if(ulang_login > 0){
        fflush(stdin);
        data_user = fopen("T_Eatos_User.dat", "rb");
        printf("Kesempatan login anda %d kali\n", ulang_login);
        printf("Nama        : "); gets(nama);
        printf("Username    : "); gets(uname);
        printf("Password    : "); gets(pass);
        printf("\n");

        while(fread(&user, sizeof(user), 1, data_user) == 1)
        {
            size++;
        }

        for(i=0; i<size; i++){
            if((strcmp(uname, user.username) == 0 && strcmp(pass, user.password)) == 0){
                printf("Login Sukses!\n"); fclose(data_user);
                system("pause"); menu_pilihuser();
                return;
            }
            system("cls");
            ulang_login--;
            login_user();
        }
    }

    else{
        system("cls"); nomore();
        menu_user();
    }
}

void menu_pilihuser(){
    system("cls");
    printf("Menu Pemesanan\n");
    printf("[1] Takeaway\n");
    printf("[2] Delivery\n");
    printf("[0] Kembali\n");
    printf("Pilihan: "); scanf("%d", &pilihan); getchar();

    switch(pilihan){
        case 1: user_takeaway(); system("pause");bill(); break;
        case 2: user_delivery(); break;
        case 0: menu_user(); break;
        default: printf("Pilihan tidak tersedia\n"); system("pause"); menu_pilihuser();
    }
}

void user_takeaway(){
    system("cls");
    printf("Menu Pemesanan Takeaway\n");
    printf("[1] Pesan Makanan\n");
    printf("[2] Bill Pemesanan\n");
    printf("[0] Kembali\n");
    printf("Pilihan: "); scanf("%d", &pilihan); getchar();

    switch(pilihan){
        case 1: pesan_makanan(); break;
        case 2: bill();
        case 0: menu_pilihuser(); break;
        default: printf("Pilihan tidak tersedia\n"); system("pause"); user_takeaway();
    }
}

void user_delivery(){
    system("cls");
    printf("Menu Pemesanan Delivery\n");
    printf("[1] Pesan Makanan\n");
    printf("[2] Bill Pemesanan\n");
    printf("[0] Kembali\n");
    printf("Pilihan: "); scanf("%d", &pilihan); getchar();

    switch(pilihan){
        case 1: pesan_makanan(); break;
        case 2: //bill
        case 0: menu_pilihuser(); break;
        default: printf("Pilihan tidak tersedia\n"); system("pause"); user_delivery();
    }
}

void pesan_makanan(){
    int s; char pilih[100]; char choice;
    system("cls");
    data_menu = fopen("T_Eatos_Menu.dat", "rb");
    while(fread(&menu, sizeof(menu), 1, data_menu) == 1){
        printf("Nama    : %s\n", menu.nama);
        printf("Harga   : %d\n", menu.harga);
        printf("\n");
        i++;
    }
    fclose(data_menu);
    
    printf("Pilih menu: "); gets(pilih);
        data_menu = fopen("T_Eatos_Menu.dat", "rb");
        data_pesan = fopen("T_Eatos_Pesan.dat", "ab");
    while(fread(&menu, sizeof(menu), 1, data_menu) == 1){
        if(strcmp(pilih, menu.nama) == 0){
        	if(strcmp(uname, user.username) == 0){
        		s=1;
              	strcpy(user.makanan, pilih);
                fwrite(&user, sizeof(user), 1, data_pesan);
                system("pause");
                break;
        	}
    	}
	}
        fclose(data_pesan);
        fclose(data_menu);
	if (s==1){
        printf("Menu berhasil dipesan\n");
        printf("Ingin memesan lagi? (y/n): "); scanf("%c", &choice); getchar();
        switch(choice){
            case 'y': printf("Tekan enter\n"); system("pause"); pesan_makanan(); break;
            case 'n': printf("Lanjut ke bill\n"); system("pause"); bill(); break;
            default: printf("Pilihan tidak tersedia\n"); system("pause"); pesan_makanan();
        }
    }
    else{
        printf("User salah\n");
        system("pause"); pesan_makanan();
    }
}

void bill(){
    char pesanan[100];
    int banyakpesan=0;
    int total;
    system("cls"); i=0;
    data_pesan = fopen("T_Eatos_Pesan.dat", "rb");
    while(fread(&user, sizeof(user), 1, data_pesan) == 1){
        if(strcmp(uname, user.username) == 0){
        	banyakpesan++;
        }
    }
        fclose(data_pesan);
    for(i=0;i<banyakpesan;i++) {
    	    printf("Nama User   : %s\n", user.nama);
            printf("Pesanan     : %s\n", user.makanan);
            printf("Total:		: %d\n", user.harga);
	}

	
}

void pesan_takeaway(){
    char pilih[100];
    system("cls");
    data_menu = fopen("T_Eatos_Menu.dat", "rb");
    printf("Pesan Takeaway\n");
    while(fread(&menu, sizeof(menu), 1, data_menu) == 1){
        printf("Nama    : %s\n", menu.nama);
        printf("Harga   : %d\n", menu.harga);
        i++;
        printf("\n");
    }
    fclose(data_menu);

    data_menu = fopen("T_Eatos_Menu.dat", "rb");
    data_pesan = fopen("T_Eatos_BillT.dat", "wb");
    printf("Pilih Menu: "); gets(pilih);
    while(fread(&menu, sizeof(menu), 1, data_menu) == 1){
        if(strcmp(menu.nama, pilih) == 0){
            fwrite(&user, sizeof(user), 1, data_user);
        }
    }
    fclose(data_menu);
    fclose(data_pesan);

    i=0;
    data_pesan = fopen("T_Eatos_BillT.dat", "rb");
    while(fread(&menu, sizeof(menu), 1, data_pesan) == 1){
        printf("Nama    : %s\n", menu.nama);
        i++;
    }
    fclose(data_pesan);

}

void pesan_delivery(){

}

void tambah_menu(){
    system("cls");
    int banyakmenu;
    data_menu = fopen("T_Eatos_Menu.dat", "ab");
    printf("Tambah Menu\n");
    printf("Masukkan 0 untuk kembali\n");
    printf("Banyak Menu: "); scanf("%d", &banyakmenu); getchar();
    printf("\n");

    if(banyakmenu == 0){
        fclose(data_menu); admin_takeaway();
    }
    else{
        for(i=0; i<banyakmenu; i++){
            printf("Nama    : "); gets(menu.nama);
            printf("Harga   : "); scanf("%d", &menu.harga); getchar();
            fwrite(&menu, sizeof(menu), 1, data_menu);
            printf("\n");
        }
    }
    fclose(data_menu);
    printf("Menu berhasil ditambahkan!\n");
    system("pause");
    admin_takeaway();
}

void baca_menu(){
    system("cls"); i=0;
    data_menu = fopen("T_Eatos_Menu.dat", "rb");
    printf("List Menu Makanan\n");
    while(fread(&menu, sizeof(menu), 1, data_menu) == 1){
        printf("Nama    : %s\n", menu.nama);
        printf("Harga   : %d\n", menu.harga);
        printf("\n");
        i++;
    }
    fclose(data_menu);
    system("pause");
}

void hapus_menu(){
    char hapus[100];
    system("cls");
    data_menu = fopen("T_Eatos_Menu.dat", "rb");
    while(fread(&menu, sizeof(menu), 1, data_menu) == 1){
        printf("Nama    : %s\n", menu.nama);
        i++;
    }
    fclose(data_menu);

    data_menu = fopen("T_Eatos_Menu.dat", "rb");
    data_menut = fopen("T_Eatos_Menut.dat", "wb");
    printf("Menu yang ingin dihapus: "); gets(hapus);
    i=0;

    while(fread(&menu, sizeof(menu), 1, data_menu) == 1){
        if(strcmp(hapus, menu.nama) != 0){
            fwrite(&menu, sizeof(menu), 1, data_menut);
        }
    }
    fclose(data_menu);
    fclose(data_menut);

    remove("T_Eatos_Menu.dat");
    rename("T_Eatos_Menut.dat", "T_Eatos_Menu.dat");
    printf("Menu berhasil dihapus!\n");
    data_menu = fopen("T_Eatos_Menu.dat", "rb");
    while(fread(&menu, sizeof(menu), 1, data_menu) == 1){
        printf("Nama    : %s\n", menu.nama);
        i++;
    }
    fclose(data_menu);

    system("pause"); admin_takeaway();
}

void tambah_driver(){
    system("cls");
    int banyakdriver;
    data_driver = fopen("T_Eatos_Driver.dat", "ab");
    printf("Tambah Driver\n");
    printf("Masukkan 0 untuk kembali\n");
    printf("Banyak Driver: "); scanf("%d", &banyakdriver); getchar();
    printf("\n");

    if(banyakdriver == 0){
        fclose(data_driver); menu_pelayandelivery();
    }
    else{
        for(i=0; i<banyakdriver; i++){
            printf("Nama    : "); gets(driver.nama);
            printf("Plat    : "); gets(driver.plat);
            printf("No Telp : "); scanf("%d", &driver.telp); getchar();
            fwrite(&driver, sizeof(driver), 1, data_driver);
            printf("\n");
        }
    }
    fclose(data_driver);
    printf("Driver berhasil ditambahkan!\n");
    system("pause");
    menu_pelayandelivery();
}

void baca_driver(){
    system("cls");
    data_driver = fopen("T_Eatos_Driver.dat", "rb");
    printf("List Driver\n");
    while(fread(&driver, sizeof(driver), 1, data_driver) == 1){
        printf("Nama    : %s\n", driver.nama);
        printf("Plat    : %s\n", driver.plat);
        printf("No Telp : %d\n", driver.telp);
        printf("\n");
    }
    fclose(data_driver);
    system("pause");
    menu_pelayandelivery();
}

void hapus_driver(){
    char hapus[100];
    system("cls");
    data_driver = fopen("T_Eatos_Driver.dat", "rb");
    while(fread(&driver, sizeof(driver), 1, data_driver) == 1){
        printf("Nama    : %s\n", driver.nama);
        i++;
    }
    fclose(data_driver);

    data_driver = fopen("T_Eatos_Driver.dat", "rb");
    data_drivert = fopen("T_Eatos_Drivert.dat", "wb");
    printf("Driver yang ingin dihapus: "); gets(hapus);
    i=0;

    while(fread(&driver, sizeof(driver), 1, data_driver) == 1){
        if(strcmp(hapus, driver.nama) != 0){
            fwrite(&driver, sizeof(driver), 1, data_drivert);
        }
    }
    fclose(data_driver);
    fclose(data_drivert);

    remove("T_Eatos_Driver.dat");
    rename("T_Eatos_Drivert.dat", "T_Eatos_Driver.dat");
    printf("Driver berhasil dihapus!\n");
    data_driver = fopen("T_Eatos_Driver.dat", "rb");
    while(fread(&driver, sizeof(driver), 1, data_driver) == 1){
        printf("Nama    : %s\n", driver.nama);
        i++;
    }
    fclose(data_driver);

    system("pause"); menu_pelayandelivery();
}

void baca_user(){
    system("cls");
    data_user = fopen("T_Eatos_User.dat", "rb");
    printf("List User\n");
    while(fread(&user, sizeof(user), 1, data_user) == 1){
        strcpy(tempuser[i].nama, user.nama);
        strcpy(tempuser[i].username, user.username);
        strcpy(tempuser[i].password, user.password);
        i++;
        n=i;
    }
    fclose(data_menu);

    i=0, j=0;
    for(i=n-1; i>=1; i--){
        for(j=1; j<=i; j++){
            if(strcmp(tempuser[j-1].nama, tempuser[j].nama) > 0){
                temp = tempuser[j-1];
                tempuser[j-1] = tempuser[j];
                tempuser[j] = temp;
            }
        }
    }

    for(i=0; i<n; i++){
        printf("%d. %s\n", i+1, tempuser[i].nama);
    }
    printf("\n");
    system("pause");
}

void nomor_antrian(){

}

void info(){
    system("cls");
    printf("    ============ Anggota Kelompok 2 ============\n\n");
    printf("    1. 1101223392 - Safira Arrahma\n");
    printf("    2. 1101223022 - M. Ikhsan\n");
    printf("    3. 1101223083 - Aliza Nurfitrian Meizahra\n");
    printf("    4. 1101223396 - Andi Muh. Yusuf Fauzan Mahir\n");
    printf("    5. 1101220176 - Mohamad Reski Ramadhani\n");
    printf("    =============================================\n");
    system("pause");
    program();
}

void logout(){
    printf("Logout\n");
    system("pause");
}

void login_gagal(){
    printf("Login gagal\n");
    system("pause");
}

void nomore(){
    printf("Kesempatan anda habis\n");
    system("pause");
}

void teatos(){
    printf("  _______ _ ______       _______ ____   _____ \n");
    printf("|__   __( )  ____|   /\\|__   __/ __ \\ / ____|\n");
    printf("    | |  |/| |__     /  \\  | | | |  | | (___  \n");
    printf("    | |    |  __|   / /\\ \\ | | | |  | |\\___ \\ \n");
    printf("    | |    | |____ / ____ \\| | | |__| |____) |\n");
    printf("    |_|    |______/_/    \\_\\_|  \\____/|_____/\n");

    return 0;
}
    


