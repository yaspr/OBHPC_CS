#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define MAX_BUFFER 1024

#define absv(a) ((a) < 0.0) ? (-(a)) : (a)

//
int load_data_file(char *fname, float data[], uint64_t *n)
{
  float tmp;
  FILE *fd = fopen(fname, "rb");

  *n = 0;
  
  if (fd)
    {
      while (fscanf(fd, "%f ", &tmp) != EOF)
	data[(*n)++] = tmp;
      
      fclose(fd);
      
      return *n;
    }
  else
    return -1;
}

//
float sum_float(float data[], uint64_t n)
{
  float r = 0.0;

  for (uint64_t i=  0; i < n; i++)
    r += data[i];
  
  return r;
}

//
double sum_double(float data[], uint64_t n)
{
  double r = 0.0;

  for (uint64_t i = 0; i < n; i++)
    r += (double) data[i];
  
  return r;
}

//
float sum_kahan_float(float data[], uint64_t n)
{
  float c = 0.0;
  float t = 0.0;
  float y = 0.0;
  float sum = 0.0;

  printf("Kahan trace\n\n");
  printf("Iter\tdata\t\tc\t\ty\t\tt\t\tc\t\tsum\n");

  for (uint64_t i = 0; i < n; i++)
    {
      y = data[i] - c;
      t = sum + y;
      c = (t - sum) - y;
      sum = t;

      printf("%" PRIu64 ":\t%.12f\t%.12f\t%.12f\t%.12f\t%.12f\t%.12f\n", i, data[i], c, y, t, c, sum);
    }

  return sum;
}

//
float sum_neumaeir_float(float data[], uint64_t n)
{
  float c = 0.0;
  float t = 0.0;
  float y = 0.0;
  float sum = data[0];

  printf("\nNeumaier trace\n\n");
  
  printf("Iter\tdata\t\tc\t\t\t\tt\t\tc\t\tsum\n");

  for (uint64_t i = 1; i < n; i++)
    {
      t = sum + data[i];

      if (absv(sum) >= absv(data[i]))
	c += (sum - t) + data[i];
      else
	c += (data[i] - t) + sum;

      sum = t;
      
      printf("%" PRIu64 ":\t%.12f\t%.12f\t\t\t%.12f\t%.12f\t%.12f\n", i, data[i], c, y, t, c, sum);
    }
  
  return sum + c;
}

//N is smallest block
float _sum_pairwise_float_(float *data, uint64_t n, const uint64_t N)
{
  if (n <= N)
    {
      float r = data[0];

      for (uint64_t i = 1; i < n; i++)
	r += data[i];

      return r;
    }
  else
    {
      uint64_t m = n >> 1;
      
      return _sum_pairwise_float_(data, m, N) + _sum_pairwise_float_(data + m, m, N);
    }
}

//
float sum_pairwise_float_4(float data[], uint64_t n)
{
  float *p = data;

  return _sum_pairwise_float_(p, n, 4);
}

//
float sum_pairwise_float_2(float data[], uint64_t n)
{
  float *p = data;

  return _sum_pairwise_float_(p, n, 2);
}

//
int main(int argc, char **argv)
{
  if (argc < 2)
    return printf("OUPS: %s [file name]\n", argv[0]), -1;

  uint64_t n = 0;
  float data[MAX_BUFFER];
  
  load_data_file(argv[1], data, &n);

  float  sum_k_f   = sum_kahan_float(data, n);
  float  sum_s_f   = sum_float(data, n);
  float  sum_n_f   = sum_neumaeir_float(data, n);
  float  sum_p_f_2 = sum_pairwise_float_2(data, n);
  float  sum_p_f_4 = sum_pairwise_float_4(data, n);
  double sum_s_d   = sum_double(data, n);

  printf("\nSum Kahan float\t\t: %.12f\n"
	 "Sum Neumaeir float\t: %.12f\n"
	 "Sum pairwise2 float\t: %.12f\n"
	 "Sum pairwise4 float\t: %.12f\n"
	 "Sum float\t\t: %.12f\n"
	 "Sum double\t\t: %.12lf\n", sum_k_f, sum_n_f, sum_p_f_2, sum_p_f_4, sum_s_f, sum_s_d);

  double delta_kf_sf  = absv(sum_k_f - sum_s_f);
  double delta_kf_sd  = absv(sum_k_f - sum_s_d);
  double delta_nf_sf  = absv(sum_n_f - sum_s_f);
  double delta_nf_sd  = absv(sum_n_f - sum_s_d);
  double delta_pf2_sf = absv(sum_p_f_2 - sum_s_f);
  double delta_pf2_sd = absv(sum_p_f_2 - sum_s_d);
  double delta_pf4_sf = absv(sum_p_f_4 - sum_s_f);
  double delta_pf4_sd = absv(sum_p_f_4 - sum_s_d);

  double delta_sf_sd = absv(sum_s_f - sum_s_d);
  
  printf("\nDeltas:\n");
  printf("\t\tDelta  KF, SF: %.12lf (%g)\n"
	 "\t\tDelta  KF, SD: %.12lf (%g)\n"
	 "\t\tDelta  NF, SF: %.12lf (%g)\n"
	 "\t\tDelta  NF, SD: %.12lf (%g)\n"
	 "\t\tDelta PF2, SF: %.12lf (%g)\n"
	 "\t\tDelta PF2, SD: %.12lf (%g)\n"
	 "\t\tDelta PF4, SF: %.12lf (%g)\n"
	 "\t\tDelta PF4, SD: %.12lf (%g)\n"
	 "\t\tDelta  SF, SD: %.12lf (%g)\n",
	 delta_kf_sf, delta_kf_sf,
	 delta_kf_sd, delta_kf_sd,
	 delta_nf_sf, delta_nf_sf,
	 delta_nf_sd, delta_nf_sd,
	 delta_pf2_sf, delta_nf_sf,
	 delta_pf2_sd, delta_nf_sd,
	 delta_pf4_sf, delta_nf_sf,
	 delta_pf4_sd, delta_nf_sd,
	 delta_sf_sd, delta_sf_sd);
  
  return 0;
}
