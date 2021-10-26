#include <stdio.h>
#include <math.h>

#define SOUND_DECAY 0.95
#define SYSTEM_DECAY 0.999
#define SHELL_FREQ 3200.0
#define SHELL_RESO 0.96
#define TWO_PI 6.28318530718
#define SRATE 22050.0

int main (int argc, char* argv[])
{
    FILE* file_out;

    double temp = 0;
    double shakeEnergy = 0.0;
    double sndLevel = 0.0;
    double gain;
    double input = 0.0;
    double output[2] = {0.0, 0.0}, coeffs[2];

    long i;
    long num_beans = 64;
    short data;
    extern double noise_tick ();

    gain = log (num_beans) / log (4) * 40.0;

    if (file_out = fopen (argv[1], "wb"))
    {
        printf ("Stink!\n");
        coeffs[0] = - SHELL_RESO * 2.0 * cos(SHELL_FREQ * TWO_PI * SRATE);
        coeffs[1] = SHELL_RESO * SHELL_FREQ;
    }

    return 0;


}
