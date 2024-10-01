# HyperSpectral-Imaging-Of-Food-Quality
NIR Spectrometer
Purpose of the Project:
The project aims to develop a Handheld Arduino-Based Near-Infrared (NIR) Spectrometer for Non-Destructive Quality Evaluation of Food. The spectrometer operates by measuring the Visible to Near-Infrared Reflectance of food samples (410 nm – 940 nm), utilizing the reflectance properties of light to determine compositional traits such as sugar, moisture, and other quality parameters.

What is Light Spectroscopy?
Spectroscopy is a technique that uses electromagnetic radiation to analyse the structure and properties of matter. 

How does it Work?
When light is presented to samples high in chemical compounds containing these bonds, some of energy is absorbed by the sample in these specific wavelengths, and thus the reflected light has less intensity in these regions.  The differences in the reflected signal (spectrum) can be correlated to chemical concentration differences, and this forms the basis of an calibration.  Once this calibration is established, it can be used to predict the chemical concentration of unknown samples.

 ![image](https://github.com/user-attachments/assets/f62ecb23-d8c7-49eb-8254-79f5d6ab64dc)


How is Calibration Made?
•	Gather samples that represent future unknown samples, considering factors like constituent range, origin, and seasonal variation.
•	Ensure sufficient sample variety for full-spectrum instruments (50-100+ samples).
•	Selected samples are sent for reference analysis using approved methods
•	The reference data is combined with the raw sample spectra. These data sets are regressed against each other, commonly using Partial Least Squares (PLS) regression, Back Propagation Neural Networks (BPNN), Multiple Linear Regression (MLR) etc.
•	The output of the regression is a linear equation that can predict the constituents of interest in future unknown samples.
•	Apply calibration to unknown samples for analysis.
•	Use outlier indicators to ensure sample similarity for accuracy.

 

Why and where do we need to do this?
NIR has become a popular and widespread analytical technique for the analysis of food, agricultural, pharmaceutical and chemical products.  NIR analysers have the following benefits

1.	Easy to use - normal operation consists of loading a sample cell and starting the instrument.
2.	Little sample preparation - most samples can be analysed as-is or with simple grinding or particle size reduction.
3.	No hazardous chemical waste - no chemicals are used at all.
4.	Fast analysis - typical analysis times are 10 seconds - 2 minutes.
5.	Simultaneous results for multiple parameters - multiple constituents are predicted with one sample analysis.
6.	Cost effective - one analyst can typically analyse several hundred samples in a day with no consumable costs.


MOTIVATION
The motivation behind this project stems from the growing need for non-destructive, real-time food quality evaluation. Traditional methods of assessing food quality, like chemical tests, are often destructive, time-consuming, and expensive. By developing a handheld Arduino-based NIR spectrometer, I aim to create a cost-effective and portable solution that leverages visible to near-infrared reflectance to evaluate essential food parameters such as sugar content, moisture, and adulteration. This technology can have significant applications in agriculture and the food industry, helping improve food safety, quality control, and nutrient monitoring. Ultimately, this project can contribute to advancements in precision agriculture, supply chain management, and even consumer-level food testing by making hyperspectral imaging accessible in a compact, affordable form.

What Is NIR AS7265x?
1.	The AS7265x chipset consists of three sensor devices AS72651 with master capability, AS72652 and AS72653
2.	The multispectral sensors can be used for spectral identification in a range from Visible to Near Infrared. 
3.	The Triad contains a 5700k white LED, a 405nm UV LED, and a 875nm IR LED mounted alongside the sensors. These LEDs were chosen to illuminate the target. If the On-board LEDs are not satisfactory, external LEDs can also be used.
           
     ![image](https://github.com/user-attachments/assets/b4c7e0a3-083e-4249-b400-69fc4203fde5)
     

4.	Every of the three sensor devices has 6 in dependent on-device optical filters whose spectral response is defined in a range from 410nm to 940nm with FWHM of 20nm
5.	The components AS72651, AS72652 and AS72653 are pre-calibrated with a specific light source.
•	This means that the sensors are exposed to a controlled known light source during manufacturing. The sensors are then adjusted or calibrated to ensure that the measurement they produce are accurate
6.	The AS7265x gives 18 Channel Spectral Responsivity (410nm-940nm)
7.	The output of each channel is the measured light intensity in that particular spectral band (Expressed in terms of counts or raw ADC values corresponding to the amount of light detected.
 ![image](https://github.com/user-attachments/assets/04b0237d-1043-4a19-9985-1d4cfc18611f)

 ![image](https://github.com/user-attachments/assets/01d5311a-07ae-48ca-be6c-3d5a7590b4e9)

8.	Optical Characteristics
All optical characteristics are optimized for diffused light. When using a point light source or collimated light on the sensor, the sensor opening must be covered by Lambertian diffuser with achromatic characteristics.
![image](https://github.com/user-attachments/assets/f66d7b49-1303-437f-b2cb-b902347d4600)

![image](https://github.com/user-attachments/assets/d281b3a8-e86c-4a5f-b254-bd22a8f0c597)

 ![image](https://github.com/user-attachments/assets/10ce9052-505a-40b8-9a8e-bdf1d7527b97)



9.	The accuracy of the AS7265x sensor’s optical filters depends on the angle of light entering the sensor. To ensure accurate spectral readings, the sensor’s field of view is limited to ±20.5°.

