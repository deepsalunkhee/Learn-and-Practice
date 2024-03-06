#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <string>

const double size = 20;
int label = 1;
std::vector<std::pair<double, double>> cluster;

std::pair<double, double> round_position(std::pair<double, double> position) {
    return std::make_pair(round(position.first, 2), round(position.second, 2));
}

void draw_hexagon(std::pair<double, double> cords) {
    double x = cords.first;
    double y = cords.second;

    std::vector<std::pair<double, double>> vertices = {
        {-size, 0},
        {-size / 2, -(sqrt(3) / 2) * size},
        {size / 2, -(sqrt(3) / 2) * size},
        {size, 0},
        {size / 2, (sqrt(3) / 2) * size},
        {-size / 2, (sqrt(3) / 2) * size}
    };

    std::cout << label << std::endl;

    for (int i = 0; i < vertices.size(); ++i) {
        std::cout << "(" << x + vertices[i].first << ", " << y + vertices[i].second << ")" << std::endl;
    }
}

void color_hexagon(std::pair<double, double> cords, std::string color) {
    double x = cords.first;
    double y = cords.second;

    std::vector<std::pair<double, double>> vertices = {
        {-size, 0},
        {-size / 2, -(sqrt(3) / 2) * size},
        {size / 2, -(sqrt(3) / 2) * size},
        {size, 0},
        {size / 2, (sqrt(3) / 2) * size},
        {-size / 2, (sqrt(3) / 2) * size}
    };

    std::cout << label << std::endl;
    std::cout << color << std::endl;

    for (int i = 0; i < vertices.size(); ++i) {
        std::cout << "(" << x + vertices[i].first << ", " << y + vertices[i].second << ")" << std::endl;
    }
}

void calculate_adjacent_centers(std::vector<std::pair<double, double>>& centers, std::vector<std::pair<double, double>>& visited, std::pair<double, double> cords) {
    double x = cords.first;
    double y = cords.second;

    std::vector<std::pair<double, double>> adjacent = {
        {-3 / 2 * size, -(sqrt(3) / 2) * size},
        {0, -(sqrt(3)) * size},
        {3 / 2 * size, -(sqrt(3) / 2) * size},
        {3 / 2 * size, (sqrt(3) / 2) * size},
        {0, (sqrt(3)) * size},
        {-3 / 2 * size, (sqrt(3) / 2) * size}
    };

    for (int i = 0; i < adjacent.size(); ++i) {
        std::pair<double, double> center = round_position(std::make_pair(adjacent[i].first + x, adjacent[i].second + y));
        if (std::find(visited.begin(), visited.end(), center) == visited.end()) {
            centers.push_back(center);
        }
    }
}

bool check_input(std::pair<double, double> cords, std::vector<std::pair<double, double>>& visited, std::vector<std::string>& input_clr) {
    double x = cords.first;
    double y = cords.second;

    std::vector<std::pair<double, double>> adjacent = {
        {-3 / 2 * size, -(sqrt(3) / 2) * size},
        {0, -(sqrt(3)) * size},
        {3 / 2 * size, -(sqrt(3) / 2) * size},
        {3 / 2 * size, (sqrt(3) / 2) * size},
        {0, (sqrt(3)) * size},
        {-3 / 2 * size, (sqrt(3) / 2) * size}
    };

    int center_ind = std::find(visited.begin(), visited.end(), cords) - visited.begin();

    for (int i = 0; i < adjacent.size(); ++i) {
        std::pair<double, double> center = round_position(std::make_pair(adjacent[i].first + x, adjacent[i].second + y));
        int ind = std::find(visited.begin(), visited.end(), center) - visited.begin();
        if (input_clr[center_ind] == input_clr[ind]) {
            return false;
        }
    }
    return true;
}

void draw_cluster(int n) {
    int temp = n;
    std::vector<std::pair<double, double>> centers;
    centers.push_back(std::make_pair(0, 0));
    std::vector<std::pair<double, double>> visited;
    visited.push_back(std::make_pair(0, 0));
    cluster.push_back(std::make_pair(label, std::make_pair(0, 0)));

    while (temp != 0) {
        std::pair<double, double> cords = centers.front();
        centers.erase(centers.begin());

        if (std::find(visited.begin(), visited.end(), cords) == visited.end()) {
            visited.push_back(cords);
            draw_hexagon(cords);
            label++;
            cluster.push_back(std::make_pair(label, std::make_pair(0, 0)));
            temp--;
            calculate_adjacent_centers(centers, visited, cords);
        }
    }

    std::vector<std::string> input_clr = input_colors(n);

    for (int i = 0; i < n; ++i) {
        color_hexagon(visited[i], input_clr[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (!check_input(visited[i], visited, input_clr)) {
            std::cout << "Invalid color selection!" << std::endl;
            break;
        }
    }
}

std::vector<std::string> input_colors(int n) {
    std::vector<std::string> input_clr;
    for (int i = 0; i < n; ++i) {
        std::string color;
        std::cout << "Enter color for " << i << " cell: ";
        std::cin >> color;
        input_clr.push_back(color);
    }
    return input_clr;
}

std::pair<double, double> random_color() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double r = dis(gen);
    double g = dis(gen);
    double b = dis(gen);
    return std::make_pair(r, g, b);
}

int main() {
    int i, j;
    std::cout << "Enter values of i, j: ";
    std::cin >> i >> j;
    int n = i * i + i * j + j * j;

    draw_cluster(n);

    return 0;
}
