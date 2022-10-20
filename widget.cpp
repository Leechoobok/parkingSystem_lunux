#include "widget.h"
#include "Car.h"
#include "./src/header/car.h"
#include "./src/header/parking_status.h"
#include "./ui_widget.h"

Car *live_car = new Car("spot","test", 0, 0);
car parking_car;


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPalette palette, lblpal;
    string tmp_spot;

    palette.setColor(QPalette::Window, Qt::gray);
    palette.setColor(QPalette::WindowText, Qt::white);

    ui->parkin_area->setAutoFillBackground(true);
    ui->parkin_area->setPalette(palette);
    QLabel* p_p[33] = {ui->P0, ui->P1, ui->P2, ui->P3, ui->P4, ui->P5, ui->P6, ui->P7, ui->P8, ui->P9, ui->P10, ui->P11, ui->P12, ui->P13, ui->P14, ui->P15, ui->P16, ui->P17, ui->P18, ui->P19, ui->P20, ui->P21, ui->P22, ui->P23, ui->P24, ui->P25, ui->P26, ui->P27, ui->P28, ui->P29,ui->P30, ui->P31,ui->P32};
    vector<car> spot;
    live_car->readData();

    lblpal.setColor(QPalette::Window, Qt::white);
    lblpal.setColor(QPalette::WindowText, Qt::blue);

    for(int i=0;i<live_car->Get_Count();i++){
        parking_car.setNumber(live_car->Get_default_License_plate(i));
        parking_car.setLocation(live_car->Get_default_Spot(i));

        tmp_spot=live_car->Get_default_Spot(i);
        p_p[stoi(tmp_spot.substr(1))]->setAutoFillBackground(true);
        p_p[stoi(tmp_spot.substr(1))]->setPalette(lblpal);
        p_p[stoi(tmp_spot.substr(1))]->setText(QString::fromStdString(live_car->Get_default_License_plate((i))));
    }

    QPixmap in, out;
    in.load("IN.png");
    out.load("OUT.png");
    in.scaledToHeight(ui->lbl_IN->height());
    in.scaledToWidth(ui->lbl_IN->width());
    out.scaledToHeight(ui->lbl_OUT->height());
    out.scaledToWidth(ui->lbl_OUT->width());
    ui->lbl_IN->setPixmap(in);
    ui->lbl_OUT->setPixmap(out);

    palette.setColor(QPalette::Window, Qt::gray);
    palette.setColor(QPalette::WindowText, Qt::white);

    lblpal.setColor(QPalette::Window, Qt::white);
    lblpal.setColor(QPalette::WindowText, Qt::blue);

}

Widget::~Widget()
{
    delete ui;
    delete live_car;
}


void Widget::on_into_parking_btn_clicked()
{
    QPalette palette, lblpal;
    QLabel* p[33] = {ui->P0, ui->P1, ui->P2, ui->P3, ui->P4, ui->P5, ui->P6, ui->P7, ui->P8, ui->P9, ui->P10, ui->P11, ui->P12, ui->P13, ui->P14, ui->P15, ui->P16, ui->P17, ui->P18, ui->P19, ui->P20, ui->P21, ui->P22, ui->P23, ui->P24, ui->P25, ui->P26, ui->P27, ui->P28, ui->P29,ui->P30, ui->P31,ui->P32};
    char *outText;
    QMessageBox msgbox;


    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "kor")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }


    ui->listWidget_Test->clear();
    ui->listWidget_Test->setEnabled(0);
    ui->leave_parking_btn->setEnabled(0);
    ui->lbl_title->setText("");
    QString dir = QFileDialog::getOpenFileName(this, "Open file", "./", "png(*.png)");

    if (dir.isEmpty()) return;



    // Open input image with leptonica library
    Pix *image= pixRead(dir.toStdString().c_str());
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    //outText = api->GetUNLVText();
    qDebug("OCR output:\n%s", outText);

    // Destroy used object and release memory
    api->End();
    std::string str=outText, tmp, tmp1, tmp2;
    std::string str_data="０１２３４５６７８９";
    std::string str_data1="0123456789";
    std::string plate;
    std::u16string x;


    size_t i = 0;
    size_t j = 0;
    size_t len = 0;
    size_t len_j= 0 ;

    while (i < str.size()) {
        int char_size = 0;

        if ((str[i] & 0b11111000) == 0b11110000) {
          char_size = 4;
        } else if ((str[i] & 0b11110000) == 0b11100000) {
          char_size = 3;
        } else if ((str[i] & 0b11100000) == 0b11000000) {
          char_size = 2;
        } else if ((str[i] & 0b10000000) == 0b00000000) {
          char_size = 1;
        } else {
          std::cout << "이상한 문자 발견!" << std::endl;
          char_size = 1;
        }

        tmp = str.substr(i, char_size);
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> convert;
        std::u16string wstr = convert.from_bytes(tmp);

        for (char16_t c : wstr) {
         // 유니코드 상에서 한글의 범위
        if ((0xAC00 <= c && c <= 0xD7A3)) {
            plate+=tmp;
            }
         }
        while (j < str_data.size()) {
          int char_size_j = 0;

          if ((str_data[j] & 0b11111000) == 0b11110000) {
            char_size_j = 4;
          } else if ((str_data[j] & 0b11110000) == 0b11100000) {
            char_size_j = 3;
          } else if ((str_data[j] & 0b11100000) == 0b11000000) {
            char_size_j = 2;
          } else if ((str_data[j] & 0b10000000) == 0b00000000) {
            char_size_j = 1;
          } else {
            std::cout << "이상한 문자 발견!" << std::endl;
            char_size_j = 1;
          }
            tmp1=str_data.substr(j, char_size_j);
            tmp2=str_data1[j/3];

            if(tmp==tmp1 || tmp == tmp2 ) plate+=(str_data1[j/3]);

            j += char_size_j;
            len_j++;
        }

        i += char_size;
        len++;
        j=0;
    }

      std::cout << "문자열의 실제 길이 : " << len << std::endl;
      std::cout <<plate<<std::endl;

      for(int i=0; i<live_car->Get_Count();i++)
      {
          if(plate==live_car->Get_default_License_plate(i)){
              msgbox.information(this, "오류", "이미 입차된 차량입니다!");
              return;

          }
      }

      QPixmap test_plate;
      test_plate.load(dir);
      //test_plate.scaledToWidth(ui->view->width());
      test_plate.scaledToHeight(ui->view->height());
      ui->view->setPixmap(test_plate);

    ui->InputText->setText(QString::fromStdString(plate));
    delete api;
    delete [] outText;
    pixDestroy(&image);
    live_car->Set_car(plate);

    //////////////////////////////////
    parking_car.setNumber(live_car->GetLicense_plate());
    live_car->Set_Spot(parking_car.RandLocation());
    parking_car.setLocation(live_car->Get_Spot());

    //////////////////////////////////
    live_car->writeData();
    palette.setColor(QPalette::Window, Qt::gray);
    palette.setColor(QPalette::WindowText, Qt::white);

    lblpal.setColor(QPalette::Window, Qt::white);
    lblpal.setColor(QPalette::WindowText, Qt::blue);

    ui->parkin_area->setAutoFillBackground(true);
    ui->parkin_area->setPalette(palette);
    string spot = live_car->Get_Spot();

    p[stoi(spot.substr(1))]->setAutoFillBackground(true);
    p[stoi(spot.substr(1))]->setPalette(lblpal);
    p[stoi(spot.substr(1))]->setText(QString::fromStdString(live_car->GetLicense_plate()));


}


void Widget::on_rate_check_btn_clicked()
{
    ui->view->clear();
    ui->listWidget_Test->clear();
    ui->listWidget_Test->setEnabled(1);
    ui->leave_parking_btn->setEnabled(1);
    ui->rate_check_btn->setEnabled(0);

    ui->lbl_title->setText("차량번호\t\t\t이용시간\t\t\t이용요금");
    ui->listWidget_Test->addItem(QString::fromStdString(live_car->GetLicense_plate())+"\t\t"+QString::number(live_car->GetParkingtime())+"\t\t"+QString::number(live_car->rate_check()));
    //else 요금체크 함수가 돌아갑니다아아아~~
}

void Widget::on_leave_parking_btn_clicked()
{
    QString tmp = ui->InputText->text();
    QPalette lblpal;
    QLabel* p[33] = {ui->P0, ui->P1, ui->P2, ui->P3, ui->P4, ui->P5, ui->P6, ui->P7, ui->P8, ui->P9, ui->P10, ui->P11, ui->P12, ui->P13, ui->P14, ui->P15, ui->P16, ui->P17, ui->P18, ui->P19, ui->P20, ui->P21, ui->P22, ui->P23, ui->P24, ui->P25, ui->P26, ui->P27, ui->P28, ui->P29,ui->P30, ui->P31,ui->P32};


    lblpal.setColor(QPalette::Window, Qt::gray);
    lblpal.setColor(QPalette::WindowText, Qt::white);
    p[stoi(live_car->Get_Spot().substr((1)))]->setAutoFillBackground(true);
    p[stoi(live_car->Get_Spot().substr((1)))]->setPalette(lblpal);
    p[stoi(live_car->Get_Spot().substr((1)))]->setText("");

    ui->listWidget_Test->clear();
    ui->leave_parking_btn->setEnabled(0);
    ui->listWidget_Test->setEnabled(0);
    ui->rate_check_btn->setEnabled(0);
    live_car->deleteData(tmp.toStdString());

}


void Widget::on_end_btn_clicked()
{

    QWidget::close();

}

void Widget::on_search_btn_clicked()
{
    QString tmp = ui->InputText->text();
    QMessageBox msgbox;
    int r_data;
    if(tmp.isEmpty()){
        msgbox.information(this, "오류", "차량번호를 입력해 주세요");
    }
    else{
        r_data = live_car->readData(tmp.toStdString());
        if (r_data==1){
            ui->view->clear();
            ui->listWidget_Test->clear();
            ui->listWidget_Test->setEnabled(1);
            ui->leave_parking_btn->setEnabled(0);
            ui->rate_check_btn->setEnabled(1);

            ui->lbl_title->setText("차량번호\t\t\t입차시간");
            ui->listWidget_Test->addItem(QString::fromStdString(live_car->GetLicense_plate())+"\t\t"+QString::number(live_car->Getinto_timeH())+"시"+QString::number(live_car->Getinto_timeM())+"분");
        } else{
            msgbox.information(this, "오류", "주차된 차량이 없습니다.");
        }
    //차량 검색 함수 돌아갑시다아아~~
    }

}

void Widget::on_listWidget_Test_itemClicked(QListWidgetItem *item)
{
    QString tmp;
    string tmp_slice;
    tmp=ui->listWidget_Test->currentItem()->text();
    tmp_slice = tmp.toStdString();
    ui->InputText->setText(QString::fromStdString(tmp_slice.substr(0,tmp_slice.find("\t"))));
    live_car->readData(tmp_slice.substr(0,tmp_slice.find("\t")));
}

