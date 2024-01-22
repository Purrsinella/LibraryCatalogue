#include <UI.h>
#include <string>
WINDOW * UI::shape(int height)
{
    //делает окошко, в котором отобразится меню, а потом обводит это окошко
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    // 1е знач - высота окна; 2е - чем больше минус, тем длиннее окно; 3е - чем больше минус, тем выше окно; 4е - отступ слева
    WINDOW *menuWin = newwin(height+2, xMax - 12, yMax - 30, 5);
    box(menuWin, 0, 0);
    refresh();
    wrefresh(menuWin);
    return menuWin;
}

void UI::cleanWin(WINDOW *menuWin)
{
    //чистит окно и заново отрисовывает вокруг него коробку
    wclear(menuWin);
    wrefresh(menuWin);
    box(menuWin, 0, 0);
}

int UI::options(std::vector<std::string> &vec, WINDOW *menuWin)
{
    cleanWin(menuWin);

    int choice;
    int highlight = 0;

    while(true)
    {
        for(int i = 0; i < vec.size(); i++)
        {
            if(i == highlight)
                wattron(menuWin, A_REVERSE);
            mvwprintw(menuWin, i + 1, 1, "%s", vec[i].c_str());
            wattroff(menuWin, A_REVERSE);
        }

        choice = wgetch(menuWin);

        switch (choice) {
            case KEY_UP:
                highlight--;
                if(highlight == -1)
                    highlight = vec.size()-1;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == vec.size())
                    highlight = 0;
                break;
            default:
                break;
        }

        if(choice == 10)
            break;

    }
    return highlight;
}

void UI::menu() {
    curs_set(0); //невидно курсор

    std::vector<std::string> optSet_1 = {"Books", "Authors", "Publishers"};
    std::vector<std::string> optSet_2 = {"Add", "Delete", "Show All", "Back to main menu"};

    WINDOW *menuWin;

    int option_1;
    int option_2 = 3;

    for(;option_2 == 3;)
    {
        menuWin = shape(optSet_1.size());
        keypad(menuWin, true);
        option_1 = options(optSet_1, menuWin);
        menuWin = shape(optSet_2.size());
        keypad(menuWin, true); // нужно повторно, тк меняется размер окна, а без этого не позволяет ввод со стрелок
        option_2 = options(optSet_2, menuWin);
        clear(); // чтобы удалить контур бОльшего окна, тк его видно при возврате назад
    }

}

//получить ввод
//вызвать option.processInput и передать в него нажатую клавишу
//вызвать option.Display
//зациклить