#include "UnorderedList.h"
#include "Point.h"

struct Viewer {
    std::string name;
    UnorderedList<std::string> watchedMovies;
};

int main() {
    setlocale(LC_ALL, "Rus");


    bool flag = true;

    while (flag) {

        int action = 0;
        std::cout << "Введите номер задания: ";
        std::cin >> action;

        if (action == -1) { break; }

        switch (action) {
        case 1: {
            try {
                UnorderedList<std::string> allMovies;
                allMovies.Add("Матрица");
                allMovies.Add("Начало");
                allMovies.Add("Интерстеллар");
                allMovies.Add("Побег из Шоушенка");
                allMovies.Add("Зеленая миля");
                allMovies.Add("Форрест Гамп");
                allMovies.Add("Список Шиндлера");

                std::cout << "Все фильмы: ";
                allMovies.Print();
                std::cout << std::endl;

                const int n = 4;
                Viewer viewers[n];

                viewers[0].name = "Анна";
                viewers[0].watchedMovies.Add("Матрица");
                viewers[0].watchedMovies.Add("Начало");
                viewers[0].watchedMovies.Add("Интерстеллар");

                viewers[1].name = "Борис";
                viewers[1].watchedMovies.Add("Матрица");
                viewers[1].watchedMovies.Add("Побег из Шоушенка");
                viewers[1].watchedMovies.Add("Интерстеллар");

                viewers[2].name = "Виктор";
                viewers[2].watchedMovies.Add("Начало");
                viewers[2].watchedMovies.Add("Интерстеллар");
                viewers[2].watchedMovies.Add("Зеленая миля");

                viewers[3].name = "Галина";
                viewers[3].watchedMovies.Add("Интерстеллар");
                viewers[3].watchedMovies.Add("Форрест Гамп");

                for (int i = 0; i < n; i++) {
                    std::cout << viewers[i].name << " : ";
                    viewers[i].watchedMovies.Print();
                }
                std::cout << std::endl;



                UnorderedList<std::string> atLeastOneWatched;
                for (int i = 0; i < n; i++) {
                    atLeastOneWatched = atLeastOneWatched.Union(viewers[i].watchedMovies);
                }

                UnorderedList<std::string> allWatched = viewers[0].watchedMovies;
                for (int i = 1; i < n; i++) {
                    allWatched = allWatched.Intersect(viewers[i].watchedMovies);
                }

                UnorderedList<std::string> noneWatched = allMovies.Except(atLeastOneWatched);
                UnorderedList<std::string> someWatched = atLeastOneWatched.Except(allWatched);

                std::cout << "=== РЕЗУЛЬТАТЫ ===\n";

                std::cout << "\n1. Фильмы, которые посмотрели ВСЕ " << n << " зрителей:\n";
                if (allWatched.count() > 0) {
                    allWatched.Print();
                }
                else {
                    std::cout << "Нет таких фильмов\n";
                }

                std::cout << "\n2. Фильмы, которые посмотрели НЕКОТОРЫЕ зрители:\n";
                if (someWatched.count() > 0) {
                    someWatched.Print();
                }
                else {
                    std::cout << "Нет таких фильмов\n";
                }

                std::cout << "\n3. Фильмы, которые НИКТО не посмотрел:\n";
                if (noneWatched.count() > 0) {
                    noneWatched.Print();
                }
                else {
                    std::cout << "Нет таких фильмов\n";
                }
            }
            catch (const std::exception& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
                return 1;
            }

        } break;
        case 3: {
            std::cout << "2D точки:" << std::endl;
            Point2D p1(1, 2);
            Point2D p2(3.5, -2);
            Point2D p3(0, 0);

            p1.show();
            p2.show();
            p3.show();

            std::cout << "\n3D точки:" << std::endl;
            Point3D p3d1(1, 2, 3);
            Point3D p3d2(4, 5, 6);
            Point3D p3d3(0, 0, 0);

            p3d1.show();
            p3d2.show();
            p3d3.show();

            std::cout << "\nРасстояния:" << std::endl;
            std::cout << "Между p3d1 и p3d2: " << p3d1.distance(p3d2) << std::endl;
            std::cout << "Между p3d1 и p3d3: " << p3d1.distance(p3d3) << std::endl;
        } break;

        default: {
            std::cout << "Такого задания нет" << std::endl;
        };
        }
    }
    

    


    
}