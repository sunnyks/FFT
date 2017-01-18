
#ifndef __FFT_H__
#define __FFT_H__

// complex type
typedef struct { float re; float im; } complex;


// complex magnitude
#define cmp_abs(x) (sqrt( (x).re * (x).re + (x).im * (x).im ) )

#define FFT_FORWARD 1
#define FFT_INVERSE 0 

// c linkage
#if (defined( __cplusplus) || defined( _cplusplus) )
	extern "C" {
#endif

	// make the window
	void hann(float* window, unsigned long length);
	void hamming(float* window, unsigned long length);
	void blackman(float* window, unsigned long length);

	// void gaussian(float* window, unsigned long length);
	// void cosine(float* window, unsigned long length);


	// apply window
	void apply_window(float* data, float* window, unsigned long length);

	// real fft
	void rfft(float* x, long N, unsigned int forward);

	// complex fft
	void cfft(float *x, long NC, unsigned int forward);

	// c linkage
#if (defined( __cplusplus) || defined( _cplusplus) )
	}
#endif

#endif