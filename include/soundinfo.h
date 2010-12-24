#ifndef SOUNDINFO_H
#define SOUNDINFO_H

#include <ostream>

struct SOUNDINFO
{
	int samples, frequency, bytespersample, channels;
	
	SOUNDINFO(int numsamples, int freq, int chan, int bytespersamp) : samples(numsamples), frequency(freq), bytespersample(bytespersamp), channels(chan) { }
	
	void DebugPrint(std::ostream & out) const
	{
		out << "Samples: " << samples << std::endl;
		out << "Frequency: " << frequency << std::endl;
		out << "Channels: " << channels << std::endl;
		out << "Bits per sample: " << bytespersample*8 << std::endl;
	}
	
	bool operator==(const SOUNDINFO & other) const
	{
		return (samples == other.samples &&
				frequency == other.frequency &&
				channels == other.channels &&
				bytespersample == other.bytespersample);
	}
};

#endif // SOUNDINFO_H
