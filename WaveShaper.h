/*
 *	WaveShaper.h
 *  Kuassa
 *
 *
 */

#ifndef WAVESHAPER_H
#define WAVESHAPER_H

#include "math.h"
//#include "FxBase.h"
//#include "ModuleBase.h"

namespace WAVESHAPER {
	enum INVERT {OFF, ON};
	enum t
	{
		kAtanPos = 0,
		kAtanNeg,
		kStages,
		kInvertStages,
		kNumParams
	};
};

class WaveShaper
{
public:
	WaveShaper();
	~WaveShaper();

	void setSampleRate(float sampleRate);
	void setParameter(int index, float value);

	void resetBuffer();
	void resetCoeffs();

	void setAtanPos(float value);
	void setAtanNeg(float value);
	void setStages(float value);
	void setInvertStages(float value);

	void process(float &in);
    void process(float &inL, float &inR);
	void process(double &in);
    void process(double &inL, double &inR);

private:
	float sampleRate_;

	float arcTanPos;
	float arcTanNeg;

	unsigned int invertStages;
	float stages_;

	float *parameter_;
};

#endif