import turtle as turtle_module
import random

turtle_module.colormode(255)
tim = turtle_module.Turtle()
tim.speed("fastest")
tim.penup()
tim.hideturtle()
rgb_colors = [
    (226, 231, 237),
    (227, 217, 205),
    (232, 199, 175),
    (210, 175, 151),
    (187, 142, 114),
    (159, 112, 84),
    (135, 82, 58),
    (109, 55, 34),
]

tim.setheading(225)
tim.forward(100)
tim.setheading(0)
number_of_dots = 100

for dot_counts in range(1, number_of_dots + 1):
    tim.dot(20, random.choice(rgb_colors))
    tim.forward(50)

    if dot_counts % 10 == 0:
        tim.setheading(90)
        tim.forward(50)
        tim.setheading(180)
        tim.forward(500)
        tim.setheading(0)

screen = turtle_module.Screen()
screen.exitonclick()
