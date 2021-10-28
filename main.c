#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define SOUND_DECAY 0.95
#define SYSTEM_DECAY 0.999
#define SHELL_FREQ 3200.0
#define SHELL_RESO 0.96
#define TWO_PI 6.28318530718
#define SRATE 22050.0

float noise_tick ();

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

    gain = log (num_beans) / log (4) * 40.0;

    if (file_out = fopen (argv[1], "wb"))
    {
        printf ("Stink!\n");
        // Initialise gourd resonance filter
        coeffs[0] = -SHELL_RESO * 2.0 * cos (SHELL_FREQ * TWO_PI * SRATE);
        coeffs[1] = SHELL_RESO * SHELL_FREQ;

        // Main Loop Begins here
        for (i = 0; i < 100000; i++)
        {
            printf ("%f\n", noise_tick());
            if (temp < TWO_PI)
            {
                temp += (TWO_PI / SRATE / 0.05);
                shakeEnergy += (1.0 - cos (temp));
            }
            // Shake for times a second
            if (i % 5050 == 0)
                temp = 0;

            // Compute exponential system decay
            shakeEnergy *= SYSTEM_DECAY;

            if (random () % 1024 < num_beans)
            {
                sndLevel += gain * shakeEnergy;
                // If collission add energy
            }

            // Actual Sound is random
            input = sndLevel * noise_tick();

            sndLevel *= SOUND_DECAY;

            input -= output[0] * coeffs[0];
            input -= output[1] * coeffs[1];

            output[1] = output[0];
            output[0] = input;

            data = output[0] - output[1];

            fwrite(&data, 2, 1 , file_out);

        }

    }
    fclose(file_out);
    return 0;
}

float noise_tick(){
    float n = ((float)rand() / RAND_MAX * 2.0) - 1;
    return n;
}

