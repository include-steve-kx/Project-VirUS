#include "titlescreen.h"


Titlescreen::Titlescreen(QWidget *parent)
    : QWidget(parent)
{
    //create widgets on the title page
    title_page = new QWidget();
    QPushButton* start_button = new QPushButton("START");
    start_button->setFixedSize(200,60);
    QPushButton* levels_button = new QPushButton("LEVEL");
    levels_button->setFixedSize(200,60);
    QPushButton* instru_button = new QPushButton("INSTRUCTION");
    instru_button->setFixedSize(200,60);
    QPushButton* quit_button = new QPushButton("QUIT");
    quit_button->setFixedSize(200,60);
    start_button->setStyleSheet("QPushButton{border-image:url(:/Pictures/face_mask.png); font: 12pt  'Press Start K';}");
    levels_button->setStyleSheet("QPushButton{border-image:url(:/Pictures/face_mask.png); font: 12pt  'Press Start K';}");
    instru_button->setStyleSheet("QPushButton{border-image:url(:/Pictures/face_mask.png); font: 12pt  'Press Start K';}");
    quit_button->setStyleSheet("QPushButton{border-image:url(:/Pictures/face_mask.png); font: 12pt  'Press Start K';}");
    QGridLayout* titlepage_layout = new QGridLayout(title_page);

    //set the title page widgets layout
    titlepage_layout->addWidget(start_button);
    titlepage_layout->addWidget(levels_button);
    titlepage_layout->addWidget(instru_button);
    titlepage_layout->addWidget(quit_button);
    titlepage_layout->setContentsMargins(200,200,200,0);
    titlepage_layout->setAlignment(Qt::AlignCenter);

   //creating stacked widgets for window transitions
    titlescreen_stacked = new QStackedWidget();
    titlescreen_stacked->addWidget(title_page);
    main_page = new Mainscreen();
    titlescreen_stacked->addWidget(main_page);
    Levels* levels_page = new Levels();
    titlescreen_stacked->addWidget(levels_page);
    Instructions* instru_page = new Instructions();
    titlescreen_stacked->addWidget(instru_page);
    results_page=new Results();
    titlescreen_stacked->addWidget(results_page);

    QVBoxLayout* central_layout = new QVBoxLayout();
    central_layout->addWidget(titlescreen_stacked);
    setLayout(central_layout); //transfer ownership

    //setting up connections for window transitions
    connect(start_button, SIGNAL(clicked()), this, SLOT(get_started()));
    connect(start_button, SIGNAL(clicked()), main_page, SLOT(start_game()));
    connect(start_button, SIGNAL(clicked()), main_page, SLOT(easy_value_handler()));
    connect(levels_button, SIGNAL(clicked()), this, SLOT(get_levels()));
    connect(instru_button, SIGNAL(clicked()), this, SLOT(get_instru()));
    connect(quit_button, SIGNAL(clicked()), this, SLOT(quit()));

    connect(main_page, SIGNAL(escape_key_pressed()), this, SLOT(get_titlescreen()));
    connect(main_page, SIGNAL(time_out(int)), this, SLOT(get_results(int)));

    connect(levels_page->get_button(), SIGNAL(clicked()), this, SLOT(get_titlescreen()));
    connect(instru_page->get_button(), SIGNAL(clicked()), this, SLOT(get_titlescreen()));
    connect(results_page->get_button(), SIGNAL(clicked()), this, SLOT(get_titlescreen()));

    connect(levels_page->get_easybutton(), SIGNAL(clicked()), main_page, SLOT(start_game()));
    connect(levels_page->get_easybutton(), SIGNAL(clicked()), this, SLOT(get_started()));
    connect(levels_page->get_easybutton(), SIGNAL(clicked()), main_page, SLOT(easy_value_handler()));
    connect(levels_page->get_mediumbutton(), SIGNAL(clicked()), main_page, SLOT(start_game()));
    connect(levels_page->get_mediumbutton(), SIGNAL(clicked()), this, SLOT(get_started()));
    connect(levels_page->get_mediumbutton(), SIGNAL(clicked()), main_page, SLOT(medium_value_handler()));
    connect(levels_page->get_hardbutton(), SIGNAL(clicked()), main_page, SLOT(start_game()));
    connect(levels_page->get_hardbutton(), SIGNAL(clicked()), this, SLOT(get_started()));
    connect(levels_page->get_hardbutton(), SIGNAL(clicked()), main_page, SLOT(hard_value_handler()));

    //setting up music and volume
    bgm_playlist=new QMediaPlaylist();
    bgm_playlist->addMedia(QUrl("qrc:/music/BGM.mp3"));
    bgm_playlist->setPlaybackMode(QMediaPlaylist::Loop);
    bgm_music = new QMediaPlayer();
    bgm_music->setPlaylist(bgm_playlist);
    bgm_music->play();

    volume=new QSlider(Qt::Horizontal);
    volume->setValue(100);
    QObject::connect(volume, SIGNAL(valueChanged(int)), bgm_music, SLOT(setVolume(int)));
    volume_label=new QLabel("VOLUME");
    QFont volume_font("Press Start K", 10);
    volume_label->setFont(volume_font);
    titlepage_layout->addWidget(volume, 4, 0);
    titlepage_layout->addWidget(volume_label,5,0,Qt::AlignCenter);
    volume->setFixedWidth(200);

    //set font for the whole program
    QFont font("Press Start K", 15);
    font.setStyleHint(QFont::Monospace);
    QWidget::setFont(font);
}

Titlescreen::~Titlescreen()
{

}

void Titlescreen::paintEvent(QPaintEvent* e)
{
    Q_UNUSED(e);
    background = QPixmap(":/Pictures/titlescreen_bg-min.png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);
}


void Titlescreen::get_titlescreen()
{
    titlescreen_stacked->setCurrentIndex(0);
}

void Titlescreen::get_started()
{
    titlescreen_stacked->setCurrentIndex(1);
}

void Titlescreen::get_levels()
{
    titlescreen_stacked->setCurrentIndex(2);
}

void Titlescreen::get_instru()
{
    titlescreen_stacked->setCurrentIndex(3);
}

void Titlescreen::get_results(int score)
{
    titlescreen_stacked->setCurrentIndex(4);
    results_page->setScore(score);
}
void Titlescreen::quit()
{
    close();
}
