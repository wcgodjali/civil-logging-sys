struct Node // Struktur data yang merupakan basis struktur database
{
    //int no;
    long nik ;
    char nama_lengkap[100];
    char tempat_lahir[100];
    char tanggal_lahir[100];
    int umur;
    char gender[2];
    char b_type[3];
    char status[20];
    char pekerjaan[100];
    struct Node *next;
    struct Node *prev;
};

// Prosedur untuk menampilkan menu user
void tampil_menu(){
    printf("\n\n");
    printf("========================================");
    printf("\n\nSELAMAT DATANG DI PROGRAM PENCATATAN DATA KEPENDUDUKAN\n\n");
    printf("========================================\n\n");
    printf("Sistem ini meggantikan pencatatan data secara manual (tulisan) menjadi sistem pencatatan data berbasis komputer\n\n");
    printf("\n");
    printf("Menu:\n");
    printf("1. Buat Data (Create Data)\n");
    printf("2. Ubah Data (Update Data)\n");
    printf("3. Hapus Data (Delete Data)\n");
    printf("4. Import Data External (Import External Data)\n");
    printf("5. Cari Data (Search Data)\n");
    printf("6. Urutkan data (Sort Data)\n");
    printf("7. Cetak Data (Print Data)\n");
    printf("8. Output Data ke CSV (Print Data)\n");
    printf("9. Keluar (Exit Program)\n\n");
    printf("Pilihan Anda:");
};


// Fungsi untuk push data external ke database insidental
struct Node* push_newdata(struct Node **last_reff, long nik, char nama_lengkap[100], char tempat_lahir[100], char tanggal_lahir[100], int umur, char gender[2], char b_type[2], char status[10], char pekerjaan[100]){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    // Memberikan initial value ke node yang baru dibuat
    //temp->no = 0;
    temp->nik = 0;
    strcpy(temp->nama_lengkap, "\0");
    strcpy(temp->tempat_lahir, "\0");
    strcpy(temp->tanggal_lahir, "\0");
    temp->umur = 0;
    strcpy(temp->gender, "\0");
    strcpy(temp->b_type,"\0");
    strcpy(temp->status, "\0");
    strcpy(temp->pekerjaan, "\0");
        if (*last_reff == NULL){ // Kondisi apabila CLL masih kosong
            // Masukan nomor
            //temp->no = (*numbering);
            //(*numbering) += 1;
            // Masukan nilai NIK
            temp->nik = nik;
            // Masukan nama lengkap
            strcat(temp->nama_lengkap, nama_lengkap);
            // Masukan tempat_lahir
            strcat(temp->tempat_lahir, tempat_lahir);
            // Masukan tanggal lahir
            strcat(temp->tanggal_lahir, tanggal_lahir);
            // Masukan Umur
            temp->umur = umur;
            // Masukan Gender
            strcat(temp->gender, gender);
            // Masukan Golongan Darah
            strcat(temp->b_type, b_type);
            // Masukan status
            strcat(temp->status, status);
            // Masukan Pekerjaan
            strcat(temp->pekerjaan, pekerjaan);
            // Atur Posisi node dengan mengatur pointer" ke node berikutnya
            *last_reff = temp; // Mengubah pointer last
            (*last_reff)->next = (*last_reff); // Next akan merujuk ke dirinya sendiri
            (*last_reff)->prev = (*last_reff); // Prev akan merujuk ke dirinya sendiri juga
            return (*last_reff); // Mengembalikan pointer last yang telah di-up
        }
        else{   // Kalo CLL sudah berisi
            // Masukan nomor
            //temp->no = (*numbering);
            //(*numbering) += 1;
            // Masukan nilai NIK
            temp->nik = nik;
            // Masukan nama lengkap
            strcat(temp->nama_lengkap, nama_lengkap);
            // Masukan tempat_lahir
            strcat(temp->tempat_lahir, tempat_lahir);
            // Masukan tanggal lahir
            strcat(temp->tanggal_lahir, tanggal_lahir);
            // Masukan Umur
            temp->umur = umur;
            // Masukan Gender
            strcat(temp->gender, gender);
            // Masukan Golongan Darah
            strcat(temp->b_type, b_type);
            // Masukan status
            strcat(temp->status, status);
            // Masukan Pekerjaan
            strcat(temp->pekerjaan, pekerjaan);
            // Atur Posisi node dengan mengatur pointer" ke node berikutnya
            temp -> next = (*last_reff)->next; // Next dari temp akan merujuk ke next dari last yg blom diupdate
            ((*last_reff)->next)->prev = temp;
            temp -> prev = (*last_reff); // prev dari temp akan merujuk ke last yang lama
            (*last_reff)->next = temp; //next dari pointer last akan di-up merujuk ke temp
            (*last_reff) = temp; //jadikan temp sebagai last yang baru
            return (*last_reff); // Mengembalikan pointer last yang telah di-up
        }
};

// Prosedur untuk merubah database insidental
void update_menu(){
    printf("Daftar Fitur:\n");
    printf("1. NIK\n");
    printf("2. Nama Lengkap\n");
    printf("3. Tempat Lahir\n");
    printf("4. Tanggal Lahir\n");
    printf("5. Jenis Kelamin\n");
    printf("6. Golongan Darah\n");
    printf("7. Status Perkawinan\n");
    printf("8. Pekerjaan\n\n");
    printf("Fitur yang Anda ingin ubah(masukkan nomor-nya):");
};

// Fungsi untuk mengeksekusi update user
int update_data(struct Node *first, long NIK, int feat_up, int tahun_sekarang_int)
{
    struct Node *temp = first;
    struct Node *target;
    int found = 0;
    if (first != NULL)
    {
        do
        {
            if (temp->nik == NIK){
                found = 1;
                target = temp;
            }
            temp = temp->next;
        }
        while (temp != first);
    }
    else{
        printf("\nDatabase masih kosong, silahkan input data dulu!");
        return 0;
    }

    if (found == 1){
        if (feat_up == 1){
            printf("Masukkan Perbaikan NIK:");
            long new_nik;
            scanf("%ld", &new_nik);
            target->nik = new_nik;
        }
        else if (feat_up == 2){
            printf("Masukkan perbaikan nama:");
            char new_nama[100];
            gets(new_nama);
            gets(new_nama);
            strcpy(target->nama_lengkap, new_nama);
        }
        else if (feat_up == 3){
            printf("Masukkan perbaikan tempat lahir:");
            char new_tempat[100];
            gets(new_tempat);
            gets(new_tempat);
            strcpy(target->tempat_lahir, new_tempat);
        }
        else if (feat_up == 4){
            printf("Masukkan perbaikan tanggal lahir:");
            char new_tanggal[100];
            char new_tahun_lahir_subjek_str[100];
            int new_tahun_lahir_subjek_int;
            int new_umur;
            gets(new_tanggal);
            gets(new_tanggal);
            strcpy(target->tanggal_lahir, new_tanggal);
            strcpy(new_tahun_lahir_subjek_str,"\0");
            strcpy(new_tahun_lahir_subjek_str,(new_tanggal + 4));
            new_tahun_lahir_subjek_int = atoi(new_tahun_lahir_subjek_str);
            new_umur = tahun_sekarang_int - new_tahun_lahir_subjek_int;
            target->umur = new_umur;
        }
        else if (feat_up == 5){
            printf("Masukkan perbaikan jenis kelamin:");
            char new_gender[2];
            gets(new_gender);
            gets(new_gender);
            strcpy(target->gender, new_gender);
        }
        else if (feat_up == 6){
            printf("Masukkan perbaikan golongan darah:");
            char new_b_type[3];
            gets(new_b_type);
            gets(new_b_type);
            strcpy(target->b_type, new_b_type);
        }
        else if (feat_up == 7){
            printf("Masukkan perbaikan status perkawinan:");
            char new_status[100];
            gets(new_status);
            gets(new_status);
            strcpy(target->status, new_status);
        }
        else{
            printf("Masukkan perbaikan pekerjaan:");
            char new_pekerjaan[100];
            gets(new_pekerjaan);
            gets(new_pekerjaan);
            strcpy(target->pekerjaan, new_pekerjaan);
        }
        return 0;
    }
    else{
        printf("\nNIK tidak ditemukan!\n");
        return 0;
    }
}

int pop_data(struct Node *first, long NIK){
    struct Node *temp = first;
    struct Node *target;
    int found = 0;
    if (first != NULL)
    {
        do
        {
            if (temp->nik == NIK){
                found = 1;
                target = temp;
            }
            temp = temp->next;
        }
        while (temp != first);
    }
    else{
        printf("\nDatabase masih kosong, silahkan input data dulu!");
        return 0;
    }
    if (found == 1){
        ((target->prev)->next) = (target->next);
        ((target->next)->prev) = (target->prev);
        free(target);
        return 0;
    }
    else{
        printf("\nNIK tidak ditemukan!\n");
        return 0;
    }
}

void search_menu(){
    printf("Daftar Fitur:\n");
    printf("1. NIK\n");
    printf("2. Nama Lengkap\n");
    printf("3. Tempat Lahir\n");
    printf("4. Tanggal Lahir\n");
    printf("5. Umur\n");
    printf("6. Jenis Kelamin\n");
    printf("7. Golongan Darah\n");
    printf("8. Status Perkawinan\n");
    printf("9. Pekerjaan\n\n");
    printf("Cari data berdasarkan fitur(masukkan nomor-nya):");
};

void search_data(struct Node *first, int feat_up){
    if (feat_up == 1){
        printf("Masukkan NIK yang ingin dicari:");
        long new_nik;
        scanf("%ld", &new_nik);
        struct Node *temp = first;
        //struct Node *target;
        if (first != NULL)
        {
        printf("\n");
        printf("NIK\t       NamaLengkap\t   TempatLahir    TanggalLahir    Umur  JenisKelamin   GolonganDarah\t   Status        Pekerjaan");
            do
            {
                if (temp->nik == new_nik){
                    printf("\n%10ld%20s%20s%14s%10d%12s%12s%23s%20s\n", temp->nik, temp->nama_lengkap, temp->tempat_lahir, temp->tanggal_lahir, temp->umur, temp->gender, temp->b_type, temp->status, temp->pekerjaan);
                }
                temp = temp->next;
            }
            while (temp != first);
        }
        else{
            printf("\nData yang dicari tidak ditemukan!\n");
        }
    }
    else if (feat_up == 2){
        printf("Masukkan nama yang ingin dicari:");
        char new_nama[100];
        gets(new_nama);
        gets(new_nama);
        struct Node *temp = first;
        //struct Node *target;
        if (first != NULL)
        {
            printf("\n");
        printf("NIK\t       NamaLengkap\t   TempatLahir    TanggalLahir    Umur  JenisKelamin   GolonganDarah\t   Status        Pekerjaan");
            do
            {
                if (strcmp((temp->nama_lengkap),new_nama) == 0){
                    printf("\n%10ld%20s%20s%14s%10d%12s%12s%23s%20s\n", temp->nik, temp->nama_lengkap, temp->tempat_lahir, temp->tanggal_lahir, temp->umur, temp->gender, temp->b_type, temp->status, temp->pekerjaan);
                }
                temp = temp->next;
            }
            while (temp != first);
        }
        else{
            printf("\nData yang dicari tidak ditemukan!\n");
        }
    }
    else if (feat_up == 3){
        printf("Masukkan tempat lahir yang ingin dicari:");
        char new_tempat[100];
        gets(new_tempat);
        gets(new_tempat);
        struct Node *temp = first;
        //struct Node *target;
        if (first != NULL)
        {
            printf("\n");
        printf("NIK\t       NamaLengkap\t   TempatLahir    TanggalLahir    Umur  JenisKelamin   GolonganDarah\t   Status        Pekerjaan");
            do
            {
                if (strcmp((temp->tempat_lahir),new_tempat) == 0){
                    printf("\n%10ld%20s%20s%14s%10d%12s%12s%23s%20s\n", temp->nik, temp->nama_lengkap, temp->tempat_lahir, temp->tanggal_lahir, temp->umur, temp->gender, temp->b_type, temp->status, temp->pekerjaan);
                }
                temp = temp->next;
            }
            while (temp != first);
        }
        else{
            printf("\nData yang dicari tidak ditemukan!\n");
        }
    }
    else if (feat_up == 4){
        printf("Masukkan tanggal lahir yang dicari:");
        char new_tanggal[100];
        gets(new_tanggal);
        gets(new_tanggal);
        struct Node *temp = first;
        //struct Node *target;
        if (first != NULL)
        {
            printf("\n");
        printf("NIK\t       NamaLengkap\t   TempatLahir    TanggalLahir    Umur  JenisKelamin   GolonganDarah\t   Status        Pekerjaan");
            do
            {
                if (strcmp((temp->tanggal_lahir),new_tanggal) == 0){
                    printf("\n%10ld%20s%20s%14s%10d%12s%12s%23s%20s\n", temp->nik, temp->nama_lengkap, temp->tempat_lahir, temp->tanggal_lahir, temp->umur, temp->gender, temp->b_type, temp->status, temp->pekerjaan);
                }
                temp = temp->next;
            }
            while (temp != first);
        }
        else{
            printf("\nData yang dicari tidak ditemukan!\n");
        }
    }
    else if (feat_up == 5){
        printf("Masukkan umur yang ingin dicari:");
        int new_umur;
        scanf("%d", &new_umur);
        struct Node *temp = first;
        //struct Node *target;
        if (first != NULL)
        {
            printf("\n");
        printf("NIK\t       NamaLengkap\t   TempatLahir    TanggalLahir    Umur  JenisKelamin   GolonganDarah\t   Status        Pekerjaan");
            do
            {
                if (temp->umur == new_umur){
                    printf("\n%10ld%20s%20s%14s%10d%12s%12s%23s%20s\n", temp->nik, temp->nama_lengkap, temp->tempat_lahir, temp->tanggal_lahir, temp->umur, temp->gender, temp->b_type, temp->status, temp->pekerjaan);
                }
                temp = temp->next;
            }
            while (temp != first);
        }
        else{
            printf("\nData yang dicari tidak ditemukan!\n");
        }
    }
    else if (feat_up == 6){
        printf("Masukkan jenis kelamin yang ingin dicari:");
        char new_gender[2];
        gets(new_gender);
        gets(new_gender);
        struct Node *temp = first;
        //struct Node *target;
        if (first != NULL)
        {
            printf("\n");
        printf("NIK\t       NamaLengkap\t   TempatLahir    TanggalLahir    Umur  JenisKelamin   GolonganDarah\t   Status        Pekerjaan");
            do
            {
                if (strcmp((temp->gender),new_gender) == 0){
                    printf("\n%10ld%20s%20s%14s%10d%12s%12s%23s%20s\n", temp->nik, temp->nama_lengkap, temp->tempat_lahir, temp->tanggal_lahir, temp->umur, temp->gender, temp->b_type, temp->status, temp->pekerjaan);
                }
                temp = temp->next;
            }
            while (temp != first);
        }
        else{
            printf("\nData yang dicari tidak ditemukan!\n");
        }
    }
    else if (feat_up == 7){
        printf("Masukkan golongan darah yang ingin dicari:");
        char new_b_type[3];
        gets(new_b_type);
        gets(new_b_type);
        struct Node *temp = first;
        //struct Node *target;
        if (first != NULL)
        {
            printf("\n");
        printf("NIK\t       NamaLengkap\t   TempatLahir    TanggalLahir    Umur  JenisKelamin   GolonganDarah\t   Status        Pekerjaan");
            do
            {
                if (strcmp((temp->b_type),new_b_type) == 0){
                    printf("\n%10ld%20s%20s%14s%10d%12s%12s%23s%20s\n", temp->nik, temp->nama_lengkap, temp->tempat_lahir, temp->tanggal_lahir, temp->umur, temp->gender, temp->b_type, temp->status, temp->pekerjaan);
                }
                temp = temp->next;
            }
            while (temp != first);
        }
        else{
            printf("\nData yang dicari tidak ditemukan!\n");
        }
    }
    else if (feat_up == 8){
        printf("Masukkan status perkawinan yang ingin dicari:");
        char new_status[100];
        gets(new_status);
        gets(new_status);
        struct Node *temp = first;
        //struct Node *target;
        if (first != NULL)
        {
            printf("\n");
        printf("NIK\t       NamaLengkap\t   TempatLahir    TanggalLahir    Umur  JenisKelamin   GolonganDarah\t   Status        Pekerjaan");
            do
            {
                if (strcmp((temp->status),new_status) == 0){
                    printf("\n%10ld%20s%20s%14s%10d%12s%12s%23s%20s\n", temp->nik, temp->nama_lengkap, temp->tempat_lahir, temp->tanggal_lahir, temp->umur, temp->gender, temp->b_type, temp->status, temp->pekerjaan);
                }
                temp = temp->next;
            }
            while (temp != first);
        }
        else{
            printf("\nData yang dicari tidak ditemukan!\n");
        }
    }
    else{
        printf("Masukkan pekerjaan yang ingin dicari:");
        char new_pekerjaan[100];
        gets(new_pekerjaan);
        gets(new_pekerjaan);
        struct Node *temp = first;
        //struct Node *target;
        if (first != NULL)
        {
            printf("\n");
        printf("NIK\t       NamaLengkap\t   TempatLahir    TanggalLahir    Umur  JenisKelamin   GolonganDarah\t   Status        Pekerjaan");
            do
            {
                if (strcmp((temp->pekerjaan),new_pekerjaan) == 0){
                    printf("\n%10ld%20s%20s%14s%10d%12s%12s%23s%20s\n", temp->nik, temp->nama_lengkap, temp->tempat_lahir, temp->tanggal_lahir, temp->umur, temp->gender, temp->b_type, temp->status, temp->pekerjaan);
                }
                temp = temp->next;
            }
            while (temp != first);
        }
        else{
            printf("\nData yang dicari tidak ditemukan!\n");
        }
    }
}

// Prosedur untuk menampilkan pilihan dasar pengurutan
void sort_menu(){
    printf("\nDaftar Fitur:\n");
    printf("1. NIK\n");
    printf("2. Umur\n");
    printf("Urutkan data berdasarkan fitur(masukkan nomor-nya):");
};

void sort_trend_menu (){
    printf("\nTrend Pengurutan:\n");
    printf("1. Ascending (A-Z)\n");
    printf("2. Descending (Z-A)\n");
    printf("Trend pengurutan(masukkan nomor-nya):");
};

// Prosedur untuk menukar 2 buah node
void tukar(struct Node *a, struct Node *b)
{
    // Masuk ke temp
    long temp_nik = a->nik ;
    char temp_nama_lengkap[100];
    strcpy(temp_nama_lengkap, a->nama_lengkap);
    char temp_tempat_lahir[100];
    strcpy(temp_tempat_lahir, a->tempat_lahir);
    char temp_tanggal_lahir[100];
    strcpy(temp_tanggal_lahir, a->tanggal_lahir);
    int temp_umur = a->umur;
    char temp_gender[2];
    strcpy(temp_gender, a->gender);
    char temp_b_type[3];
    strcpy(temp_b_type, a->b_type);
    char temp_status[20];
    strcpy(temp_status, a->status);
    char temp_pekerjaan[100];
    strcpy(temp_pekerjaan, a->pekerjaan);
    // A digantikan oleh B
    a->nik = b->nik;
    strcpy(a->nama_lengkap, b->nama_lengkap);
    strcpy(a->tempat_lahir, b->tempat_lahir);
    strcpy(a->tanggal_lahir, b->tanggal_lahir);
    a->umur = b->umur;
    strcpy(a->gender, b->gender);
    strcpy(a->b_type, b->b_type);
    strcpy(a->status, b->status);
    strcpy(a->pekerjaan, b->pekerjaan);
    // B digantikan oleh temp
    b->nik = temp_nik;
    strcpy(b->nama_lengkap, temp_nama_lengkap);
    strcpy(b->tempat_lahir, temp_tempat_lahir);
    strcpy(b->tanggal_lahir, temp_tanggal_lahir);
    b->umur = temp_umur;
    strcpy(b->gender, temp_gender);
    strcpy(b->b_type, temp_b_type);
    strcpy(b->status, temp_status);
    strcpy(b->pekerjaan, temp_pekerjaan);
}

// Fungsi untuk mengurutkan linked list berdasarkan parameter tertentu (ascending)
void bubbleSort_a(struct Node *start, int sort_up)
{
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = start;

    /* Checking for empty list */
    if (start == NULL)
        return;
    if(sort_up == 1){
    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->nik > ptr1->next->nik)
            {
                tukar(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
    }
    else {
        do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->umur > ptr1->next->umur)
            {
                tukar(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
    }
}

// Fungsi untuk mengurutkan linked list berdasarkan parameter tertentu (descending)
void bubbleSort_d(struct Node *start, int sort_up)
{
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = start;

    /* Checking for empty list */
    if (start == NULL)
        return;
    if(sort_up == 1){
    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->nik < ptr1->next->nik)
            {
                tukar(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
    }
    else {
        do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->umur < ptr1->next->umur)
            {
                tukar(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
    }
}


// Fungsi untuk mencetak isi database insidental
void printList(struct Node *first)
{
    int numbering = 1;
    struct Node *temp = first;
    printf("No    NIK\t       NamaLengkap\t   TempatLahir    TanggalLahir    Umur  JenisKelamin   GolonganDarah\t   Status        Pekerjaan");
    // If linked list is not empty
    if (first != NULL)
    {
        // Keep printing nodes till we reach the first node again
        do
        {
            printf("\n%3d %10ld%20s%20s%14s%10d%12s%12s%23s%20s\n",numbering, temp->nik, temp->nama_lengkap, temp->tempat_lahir, temp->tanggal_lahir, temp->umur, temp->gender, temp->b_type, temp->status, temp->pekerjaan);
            temp = temp->next;
            numbering += 1;
        }
        while (temp != first);
    }
}

// Print to File
void printFile(struct Node *first, FILE* fp)
{
    int numbering = 1;
    struct Node *temp = first;
    fprintf(fp,"No;NIK;NamaLengkap;TempatLahir;TanggalLahir;Umur;JenisKelamin;GolonganDarah;Status;Pekerjaan");
    // If linked list is not empty
    if (first != NULL)
    {
        // Keep printing nodes till we reach the first node again
        do
        {
            fprintf(fp, "%d;%ld;%s;%s;%s;%d;%s;%s;%s;%s\n",numbering, temp->nik, temp->nama_lengkap, temp->tempat_lahir, temp->tanggal_lahir, temp->umur, temp->gender, temp->b_type, temp->status, temp->pekerjaan);
            temp = temp->next;
            numbering += 1;
        }
        while (temp != first);
    }
}


void parse_external(FILE* fp, struct Node** last_reff)
{
    int len;
    char buffer[1000];
    int parsing_feat ;
    char* temp_pointer;
    long temp_nik ;
    char temp_nama_lengkap[100];
    char temp_tempat_lahir[100];
    char temp_tanggal_lahir[100];
    int temp_umur;
    char temp_gender[2];
    char temp_b_type[3];
    char temp_status[20];
    char temp_pekerjaan[100];
    fgets(buffer, 1000, fp) ;
    while(fgets(buffer, 1000, fp) != NULL) //Ambil baris per baris
        {
        parsing_feat = 1;
        char* token = strtok(buffer, ";"); //Ambil token pada baris tsb.
        while (token != NULL) //Apabila ada
        {
            if (parsing_feat == 1){
                parsing_feat += 1;
                token = strtok(NULL, ";");
                continue;
            }
            else if (parsing_feat == 2){
                parsing_feat += 1;
                len = strlen(token); // Cek panjang token
                if (strcmp(token+len-1, "\n") != 0)
                {
                    temp_nik = atol(token);
                }
                else if ((len > 1) && (strcmp(token+len-1, "\n") == 0))
                {
                    temp_pointer = strchr(token,'\n');
                    *temp_pointer = '\0';
                    temp_nik = atol(token);
                }
            }
            else if (parsing_feat == 3){
                parsing_feat += 1;
                len = strlen(token); // Cek panjang token
                if (strcmp(token+len-1, "\n") != 0)
                {
                    strcpy(temp_nama_lengkap, token);
                }
                else if ((len > 1) && (strcmp(token+len-1, "\n") == 0))
                {
                    temp_pointer = strchr(token,'\n');
                    *temp_pointer = '\0';
                    strcpy(temp_nama_lengkap, token);
                }
            }
             else if (parsing_feat == 4){
                 parsing_feat += 1;
                len = strlen(token); // Cek panjang token
                if (strcmp(token+len-1, "\n") != 0)
                {
                    strcpy(temp_tempat_lahir, token);
                }
                else if ((len > 1) && (strcmp(token+len-1, "\n") == 0))
                {
                    temp_pointer = strchr(token,'\n');
                    *temp_pointer = '\0';
                    strcpy(temp_tempat_lahir, token);
                }
            }
             else if (parsing_feat == 5){
                 parsing_feat += 1;
                len = strlen(token); // Cek panjang token
                if (strcmp(token+len-1, "\n") != 0)
                {
                    strcpy(temp_tanggal_lahir, token);
                }
                else if ((len > 1) && (strcmp(token+len-1, "\n") == 0))
                {
                    temp_pointer = strchr(token,'\n');
                    *temp_pointer = '\0';
                    strcpy(temp_tanggal_lahir, token);
                }
            }
             else if (parsing_feat == 6){
                 parsing_feat += 1;
                len = strlen(token); // Cek panjang token
                if (strcmp(token+len-1, "\n") != 0)
                {
                    temp_umur = atoi(token);
                }
                else if ((len > 1) && (strcmp(token+len-1, "\n") == 0))
                {
                    temp_pointer = strchr(token,'\n');
                    *temp_pointer = '\0';
                    temp_umur = atoi(token);
                }
            }
             else if (parsing_feat == 7){
                 parsing_feat += 1;
                len = strlen(token); // Cek panjang token
                if (strcmp(token+len-1, "\n") != 0)
                {
                    strcpy(temp_gender, token);
                }
                else if ((len > 1) && (strcmp(token+len-1, "\n") == 0))
                {
                    temp_pointer = strchr(token,'\n');
                    *temp_pointer = '\0';
                    strcpy(temp_gender, token);
                }
            }
             else if (parsing_feat == 8){
                 parsing_feat += 1;
                len = strlen(token); // Cek panjang token
                if (strcmp(token+len-1, "\n") != 0)
                {
                    strcpy(temp_b_type, token);
                }
                else if ((len > 1) && (strcmp(token+len-1, "\n") == 0))
                {
                    temp_pointer = strchr(token,'\n');
                    *temp_pointer = '\0';
                    strcpy(temp_b_type, token);
                }
            }
             else if (parsing_feat == 9){
                 parsing_feat += 1;
                len = strlen(token); // Cek panjang token
                if (strcmp(token+len-1, "\n") != 0)
                {
                    strcpy(temp_status, token);
                }
                else if ((len > 1) && (strcmp(token+len-1, "\n") == 0))
                {
                    temp_pointer = strchr(token,'\n');
                    *temp_pointer = '\0';
                    strcpy(temp_status, token);
                }
            }
             else if (parsing_feat == 10){
                 parsing_feat += 1;
                len = strlen(token); // Cek panjang token
                if (strcmp(token+len-1, "\n") != 0)
                {
                    strcpy(temp_pekerjaan, token);
                }
                else if ((len > 1) && (strcmp(token+len-1, "\n") == 0))
                {
                    temp_pointer = strchr(token,'\n');
                    *temp_pointer = '\0';
                    strcpy(temp_pekerjaan, token);
                }
            }
            token = strtok(NULL, ";");
        }
        push_newdata(last_reff, temp_nik, temp_nama_lengkap, temp_tempat_lahir, temp_tanggal_lahir, temp_umur, temp_gender, temp_b_type, temp_status, temp_pekerjaan);
    }
    fclose(fp);
    }
