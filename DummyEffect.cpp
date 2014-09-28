#include "DummyEffect.h"

using namespace WAVESHAPER;

DummyEffect::DummyEffect()
{
	parameter_ = new float[kNumParams];

	for(int i = 0; i < kNumParams; ++i)
	{
		parameter_[i] = 0;
	}
}

DummyEffect::~DummyEffect()
{
	if(parameter_)
		delete[] parameter_;
	parameter_ = 0;
}

void DummyEffect::resetBuffer()
{
	waveShaper_.resetBuffer();
}

void DummyEffect::resetCoeffs()
{
	waveShaper_.resetCoeffs();
}

void DummyEffect::calc()
{	
//	waveShaper_.calc();
}

void DummyEffect::setSampleRate(float sampleRate)
{
	//sampleRate_ = sampleRate;
	waveShaper_.setSampleRate(sampleRate);
}

void DummyEffect::setParameter(int index, float value)
{
	parameter_[index] = value;
	waveShaper_.setParameter(index, value);
}

 void DummyEffect::process(float *in, int sampleFrames)
 {
	 double _in;
	
	 for(int i = 0; i < sampleFrames; i++)
	 {
		 _in = in[i];
		 
		 waveShaper_.process(_in);

		 in[i] = (float)_in; 
	 }
 }
 void DummyEffect::process(float *inL, float *inR, int sampleFrames)
 {
	 double _inL, _inR;

//	 if(parameter_[kFreq]!=lastFreq_)
//	 {
//		 lastFreq_ = paramSmooth1.process(parameter_[kFreq]);
//	
//		 directOscillator_.setFrequency(lastFreq_);
//		 directOscillator_.calc();
//		 
//		 //lastFreq_ = parameter_[kFreq];
//	 }
	 for(int i = 0; i < sampleFrames; i++)
	 {
		 //LR
		 _inL = inL[i];
		 _inR = inR[i];

		 waveShaper_.process(_inL,_inR);


		 inL[i] = (float)_inL;
		 inR[i] = (float)_inR;
	 }
 }

 void DummyEffect::process(double *in, int sampleFrames)
{
	double _in;
	
	for(int i = 0; i < sampleFrames; i++)
	{
		_in = in[i];
		
		waveShaper_.process(_in);
		
		in[i] = (float)_in; 
	}
 }

 void DummyEffect::process(double *inL, double *inR, int sampleFrames)
 {
	 double _inL, _inR;
//	 if(parameter_[kFreq]!=lastFreq_)
//	 {
//		 lastFreq_ = paramSmooth1.process(parameter_[kFreq]);
//		 
//		 directOscillator_.setFrequency(lastFreq_);
//		 directOscillator_.calc();
//		 
//		 //lastFreq_ = parameter_[kFreq];
//	 }

	 for(int i = 0; i < sampleFrames; i++)
	 {
		 //LR
		 _inL = inL[i];
		 _inR = inR[i];
		 
		 waveShaper_.process(_inL,_inR);
		 
		 
		 inL[i] = (float)_inL;
		 inR[i] = (float)_inR;
	 }
 }