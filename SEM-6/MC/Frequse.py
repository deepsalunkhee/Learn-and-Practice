import turtle
import math
import random


size = 20
label = 1
cluster = []


def round_position(position):
    return round(position[0], 2), round(position[1], 2)


def draw_hexagon(drawer, cords):
    global size, label
    x, y = cords

    vertices = [
        (-size, 0),
        (-size / 2, -(3**0.5) / 2 * size),
        (size / 2, -(3**0.5) / 2 * size),
        (size, 0),
        (size / 2, (3**0.5) / 2 * size),
        (-size / 2, (3**0.5) / 2 * size),
    ]

    drawer.penup()
    drawer.goto(x, y - 8)
    drawer.write(label, align="center")

    drawer.goto(x + vertices[0][0], y + vertices[0][1])
    drawer.pendown()

    for vertex in vertices[1:]:
        drawer.goto(x + vertex[0], y + vertex[1])

    drawer.goto(x + vertices[0][0], y + vertices[0][1])


def color_hexagon(drawer, cords, color):
    global size, label
    x, y = cords

    vertices = [
        (-size, 0),
        (-size / 2, -(3**0.5) / 2 * size),
        (size / 2, -(3**0.5) / 2 * size),
        (size, 0),
        (size / 2, (3**0.5) / 2 * size),
        (-size / 2, (3**0.5) / 2 * size),
    ]

    drawer.penup()
    drawer.goto(x, y - 8)
    drawer.write(label, align="center")
    
    drawer.fillcolor(color)
    drawer.begin_fill()
    drawer.goto(x + vertices[0][0], y + vertices[0][1])
    drawer.pendown()

    for vertex in vertices[1:]:
        drawer.goto(x + vertex[0], y + vertex[1])

    drawer.goto(x + vertices[0][0], y + vertices[0][1])
    drawer.end_fill()


def calculate_adjacent_centers(centers, visited, cords):
    global size
    x, y = cords

    adjacent = [
        (-3 / 2 * size, -(3**0.5) / 2 * size),
        (0, -(3**0.5) * size),
        (3 / 2 * size, -(3**0.5) / 2 * size),
        (3 / 2 * size, (3**0.5) / 2 * size),
        (0, (3**0.5) * size),
        (-3 / 2 * size, (3**0.5) / 2 * size),
    ]

    adjacent_centers = [
        round_position((center[0] + x, center[1] + y)) for center in adjacent
    ]

    for center in adjacent_centers:        
        if center not in visited:
            distance = round((center[0] ** 2) + (center[1] ** 2), 4)
            centers.append(center)


def check_input(cords, visited, input_clr):
    x, y = cords
    
    adjacent = [
        (-3 / 2 * size, -(3**0.5) / 2 * size),
        (0, -(3**0.5) * size),
        (3 / 2 * size, -(3**0.5) / 2 * size),
        (3 / 2 * size, (3**0.5) / 2 * size),
        (0, (3**0.5) * size),
        (-3 / 2 * size, (3**0.5) / 2 * size),
    ]

    adjacent_centers = [
        round_position((center[0] + x, center[1] + y)) for center in adjacent
    ]

    center_ind = visited.index(cords)

    for center in adjacent_centers:
        if center in visited:
            ind = visited.index(center)
            if input_clr[center_ind] == input_clr[ind]:
                return False

    return True




def draw_cluster(n):
    global cluster, label
    
    if n == 0:
        return

    temp = n
    drawer = turtle.Turtle()
    drawer.speed(0)

    centers = []
    centers.append((0, 0))
    visited = []
    cluster = [(label, (0, 0))]

    while temp != 0:
        cords = centers.pop(0)

        if cords not in visited:
            visited.append(cords)
            draw_hexagon(drawer, cords)
            label += 1
            cluster.append((label, (0, 0)))
            temp -= 1
            calculate_adjacent_centers(centers, visited, cords)

    input_clr = input_colors(n)

    for i in range(n):
        color_hexagon(drawer, visited[i], input_clr[i])

    for i in range(n):
        if not check_input(visited[i], visited, input_clr):
            print("Invalid color selection!")
            break
        


def input_colors(n):
    input_clr = []
    
    for i in range(n):
        input_clr.append(input("Enter color for {} cell: ".format(i)))

    return input_clr


def random_color():
    r = random.random()
    g = random.random()
    b = random.random()
    return (r, g, b)


def main():
    i, j = map(int, input("Enter values of i, j: ").split())
    n = i ** 2 + i * j + j ** 2

    screen = turtle.Screen()

    draw_cluster(n)

    screen.exitonclick()


if __name__ == "__main__":
    main()