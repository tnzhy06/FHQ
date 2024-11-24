#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Xs, Ys, Xd, Yd, Xo, Yo;
    scanf("%d %d %d %d %d %d", &Xs, &Ys, &Xd, &Yd, &Xo, &Yo);
    int step = abs(Xd - Xs) + abs(Yd - Ys);

    if ((Xs == Xo && Xd == Xo && ((Ys < Yo && Yo < Yd) || (Yd < Yo && Yo < Ys))) ||
        (Ys == Yo && Yd == Yo && ((Xs < Xo && Xo < Xd) || (Xd < Xo && Xo < Xs))))
    {
        step += 2;
    }

    printf("%d", step);
    return 0;
}