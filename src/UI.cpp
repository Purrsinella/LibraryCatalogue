#include <UI.h>
#include <string>
WINDOW * UI::shape()
{
    //делает окошко, в котором отобразится меню, а потом обводит это окошко
    // TODO динамический расчет размера окошка (под 3 и 4 пункта это подходит, но нужно как-то интереснее, а то Ваня грустит)
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    WINDOW *menu_win = newwin(6, xMax - 12, yMax - 8, 5);
    box(menu_win, 0, 0);
    refresh();
    wrefresh(menu_win);
    return menu_win;
}

void UI::cleanScreen(WINDOW *menu_win)
{
    //чистит окно и заново отрисовывает вокруг него коробку
    wclear(menu_win);
    wrefresh(menu_win);
    box(menu_win, 0, 0);
}

int UI::options(std::vector<std::string> &vec, WINDOW *menu_win)
{
    cleanScreen(menu_win);

    int choice;
    int highlight = 0;

    while(true)
    {
        for(int i = 0; i < vec.size(); i++)
        {
            if(i == highlight)
                wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, i+1, 1, "%s", vec[i].c_str());
            wattroff(menu_win, A_REVERSE);
        }

        choice = wgetch(menu_win);

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

    WINDOW *menu_win = shape();

    keypad(menu_win, true);

    std::vector<std::string> optSet_1 = {"Books", "Authors", "Publishers"};
    std::vector<std::string> optSet_2 = {"Add", "Delete", "Show All", "Back to main menu"};

    int option_1;
    int option_2 = 3;

    for(;option_2 == 3;)
    {
        option_1 = options(optSet_1, menu_win);
        option_2 = options(optSet_2, menu_win);
    }

    clear();
}