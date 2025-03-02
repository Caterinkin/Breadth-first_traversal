#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

// Функция для обхода графа в ширину
void BFS(int startVertex, const std::vector<std::vector<int>>& adjacencyMatrix, std::vector<bool>& visited)
{
    // Очередь для хранения вершин, которые нужно посетить
    std::queue<int> queue;

    // Помечаем начальную вершину как посещённую и добавляем её в очередь
    visited[startVertex] = true;
    queue.push(startVertex);

    // Пока очередь не пуста
    while (!queue.empty())
    {
        // Извлекаем вершину из очереди
        int currentVertex = queue.front();
        queue.pop();

        // Выводим номер текущей вершины
        std::cout << currentVertex + 1 << " ";

        // Добавляем в очередь все смежные вершины, которые ещё не посещены
        for (int i = 0; i < adjacencyMatrix.size(); ++i)
        {
            if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}

int main()
{
    // Устанавливаем локаль для поддержки русского языка
    setlocale(LC_ALL, "rus");

    // Открываем файл для чтения
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1; // Возвращаем 1 в случае ошибки
    }

    // Читаем количество вершин графа
    int N;
    inputFile >> N;

    // Создаём матрицу смежности
    std::vector<std::vector<int>> adjacencyMatrix(N, std::vector<int>(N));

    // Заполняем матрицу смежности из файла
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            inputFile >> adjacencyMatrix[i][j];
        }
    }

    // Закрываем файл
    inputFile.close();

    // Запрашиваем у пользователя начальную вершину
    int startVertex;
    std::cout << "В графе " << N << " вершин. Введите номер вершины, с которой начнётся обход (от 1 до " << N << "): ";
    std::cin >> startVertex;

    // Проверяем корректность ввода
    if (startVertex < 1 || startVertex > N)
    {
        std::cerr << "Некорректный номер вершины!" << std::endl;
        return 1; // Возвращаем 1 в случае ошибки
    }

    // Преобразуем номер вершины в индекс (индексация с 0)
    startVertex--;

    // Создаём массив для хранения информации о посещённых вершинах
    std::vector<bool> visited(N, false);

    std::cout << "Порядок обхода вершин: ";

    // Запускаем обход графа в ширину с выбранной вершины
    BFS(startVertex, adjacencyMatrix, visited);

    std::cout << std::endl;
    
    return EXIT_SUCCESS; 
}
