/*
** EPITECH PROJECT, 2018
** 101pong_2018
** File description:
** 101_pong
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

const	float	PI =  3.14159265358979323846;

int	usage_h(int ac, char **av)
{
    printf("USAGE\n");
    printf("\t./101pong x0 y0 z0 x1 y1 z1 n \n");
    printf("\nDESCRIPTION\n");
    printf("\tx0   ball abscissa at time t - 1 \n");
    printf("\ty0   ball ordinate at time t - 1 \n");
    printf("\tz0   ball altitude at time t - 1 \n");
    printf("\tx1   ball abscissa at time t\n");
    printf("\ty1   ball ordinate at time t\n");
    printf("\tz1   ball altitude at time t\n");
    printf("\tn    time shift (greater than or equal to zero, integer)\n");
    return (0);
}

int	velocity_ball(int ac, char **av)
{
    float	x;
    float	y;
    float	z;
    float	x2;
    float	y2;
    float	z2;

    x = atof(av[4]) - atof(av[1]);
    y = atof(av[5]) - atof(av[2]);
    z = atof(av[6]) - atof(av[3]);
    printf("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)\n",x,y,z);
    x2 = atof(av[4]) + (atof(av[7]) * x);
    y2 = atof(av[5]) + (atof(av[7]) * y);
    z2 = atof(av[6]) + (atof(av[7]) * z);
    printf("At time t + %d, ball coordinates will be:\n(%.2f, %.2f, %.2f)\n"
           ,atoi(av[7]), x2, y2, z2);
    return (0);
}

int	angle_ball(int ac, char **av)
{
    float	y = atof(av[5]) - atof(av[2]);
    float	z = atof(av[6]) - atof(av[3]);
    float	x = atof(av[4]) - atof(av[1]);
    float	angle;
    float	a;

    velocity_ball(ac, av);
    a = atof(av[6])/z;
    if (-a <= 0 || angle < 0 || angle > 90)
        printf("The ball won't reach the bat.\n");
    else {
        angle = ((180*(acos(z/(sqrt(pow(x,2)+pow(y,2)+pow(z,2))))))/PI) - 90;
        printf("The incidence angle is:\n%.2f degrees\n", angle);
    }
    return (0);
}

int	main(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            usage_h(ac, av);
            return (0);
        }
        else
            write(2, "ERROR!\n", 7);
        return (84);
    } else if (ac == 8) {
        if (*av[7] < '0') {
            write(2, "NEGATIVE NUMBER!\n", 17);
            return (84);
        } else {
            angle_ball(ac, av);
            return (0);
        }
    } else
        write(2, "ERROR!\n", 7);
    return (84);
}
