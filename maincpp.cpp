#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

// ������� ��� ������ ����� � ������
void BFS(int startVertex, const std::vector<std::vector<int>>& adjacencyMatrix, std::vector<bool>& visited)
{
    // ������� ��� �������� ������, ������� ����� ��������
    std::queue<int> queue;

    // �������� ��������� ������� ��� ���������� � ��������� � � �������
    visited[startVertex] = true;
    queue.push(startVertex);

    // ���� ������� �� �����
    while (!queue.empty())
    {
        // ��������� ������� �� �������
        int currentVertex = queue.front();
        queue.pop();

        // ������� ����� ������� �������
        std::cout << currentVertex + 1 << " ";

        // ��������� � ������� ��� ������� �������, ������� ��� �� ��������
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
    // ������������� ������ ��� ��������� �������� �����
    setlocale(LC_ALL, "rus");

    // ��������� ���� ��� ������
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "������ �������� �����!" << std::endl;
        return 1; // ���������� 1 � ������ ������
    }

    // ������ ���������� ������ �����
    int N;
    inputFile >> N;

    // ������ ������� ���������
    std::vector<std::vector<int>> adjacencyMatrix(N, std::vector<int>(N));

    // ��������� ������� ��������� �� �����
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            inputFile >> adjacencyMatrix[i][j];
        }
    }

    // ��������� ����
    inputFile.close();

    // ����������� � ������������ ��������� �������
    int startVertex;
    std::cout << "� ����� " << N << " ������. ������� ����� �������, � ������� ������� ����� (�� 1 �� " << N << "): ";
    std::cin >> startVertex;

    // ��������� ������������ �����
    if (startVertex < 1 || startVertex > N)
    {
        std::cerr << "������������ ����� �������!" << std::endl;
        return 1; // ���������� 1 � ������ ������
    }

    // ����������� ����� ������� � ������ (���������� � 0)
    startVertex--;

    // ������ ������ ��� �������� ���������� � ���������� ��������
    std::vector<bool> visited(N, false);

    std::cout << "������� ������ ������: ";

    // ��������� ����� ����� � ������ � ��������� �������
    BFS(startVertex, adjacencyMatrix, visited);

    std::cout << std::endl;
    
    return EXIT_SUCCESS; 
}