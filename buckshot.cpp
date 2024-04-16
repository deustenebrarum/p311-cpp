// написать консольное приложение-игру
// у врага и вас по выбранному вами количеству жизней
// в обойме рандомное количество патронов от 3х до 8
// рандомная часть патронов холостые, они не наносят урона
// если патроны закончились, обойма обновляется
// по очереди сначала игрок, потом враг, выбирают
// выстрелить в себя или в противника
// игра оканчивается при смерти игрока или врага
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

void backshot()
{
    srand((uint32_t)time(NULL));

    int player_hp, enemy_hp;
    std::cout << "Input hit points:\n";
    std::cin >> player_hp;
    enemy_hp = player_hp;

    const int min_active_bullets = 2;
    const int min_blank_bullets = 2;
    const int max_bullets = 8;

    while (enemy_hp > 0 && player_hp > 0)
    {
        int active_bullets = rand() %
            (max_bullets - min_active_bullets - min_blank_bullets + 1) +
            min_active_bullets;
        int blank_bullets = min_blank_bullets;

        if (active_bullets < max_bullets - min_active_bullets) {
            blank_bullets += rand() % (max_bullets - active_bullets - min_active_bullets);
        }

        std::cout << "There is " << active_bullets
            << " fire bullets and " << blank_bullets << " blanks\n";

        for (int turn = 0; active_bullets > 0 || blank_bullets > 0; ++turn) {
            int choice;

            const bool is_player_turn = turn % 2 == 0;

            if (is_player_turn) {
                std::cout << "You have " << player_hp << " lifes, he has " << enemy_hp << '\n'
                    << "Whom to shoot at?\n"
                    << "1) Self\n"
                    << "2) Him\n";
                std::cin >> choice;
                std::cout << "You ";
            }
            else {
                choice = rand() % 2 + 1;
                std::cout << "He ";
                const int wait_time_ms = 2000;
                std::this_thread::sleep_for(std::chrono::milliseconds(wait_time_ms));
            }

            std::cout << (choice == 1 ? "choosen self" : "choosen opponent") << '\n';

            bool is_blank = rand() % 2 == 0 && blank_bullets > 0;

            if (active_bullets <= 0) is_blank = true;

            if (is_blank) {
                std::cout << "Bullet is blank\n";
                blank_bullets -= 1;
                continue;
            }

            std::cout << "Bullet is fired\n";
            system("color 4F");
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            system("color 0F");

            active_bullets -= 1;

            if (
                (is_player_turn && choice == 1) ||
                (!is_player_turn && choice == 2)
                ) {
                std::cout << "You is damaged\n";
                if (!is_player_turn) ++turn;
                --player_hp;
            }
            else {
                std::cout << "Enemy is damaged\n";
                if (is_player_turn) ++turn;
                --enemy_hp;
            }

            if (enemy_hp <= 0) {
                std::cout << "He's dead\n";
                break;
            }
            else if (player_hp <= 0) {
                std::cout << "You're ded\n";
                break;
            }
            system("cls");
        }
        std::cout << "rifle is empty\n";
    }
}

//void rpg_1() {
//    int player_hp = 20;
//    int enemy_hp = 20;
//    int enemies_killed = 0;
//
//    const int attack_damage = 1;
//    const int super_attack_damage = 2;
//
//    while (player_hp != 0) {
//        system("cls");
//        std::cout << "player hp: " << player_hp << " | " << enemy_hp << " :enemy hp\n";
//        std::cout << "1) Attack\n"
//            << "2) Super attack\n";
//
//        int choice;
//        std::cin >> choice;
//
//        int player_damage = choice == 1 ? attack_damage : super_attack_damage;
//        int enemy_damage = choice == 1 ? attack_damage : super_attack_damage;
//
//        int enemy_choice = rand() % 2 + 1;
//
//        if (enemy_choice == choice) {
//            enemy_hp -= player_damage;
//            player_hp -= enemy_damage;
//            system("color 40");
//        }
//        else if (enemy_choice == 2 && choice == 1) {
//            player_hp -= enemy_damage;
//            system("color 4F");
//        }
//        else if (enemy_choice == 1 && choice == 2) {
//            enemy_hp -= player_damage;
//            system("color 0F");
//        }
//
//        if (enemy_hp <= 0) {
//            std::cout << "You killed an enemy\n";
//            ++enemies_killed;
//            enemy_hp = 20;
//        }
//    }
//
//    std::cout << "You killed " << enemies_killed << " enemies\n";
//}
