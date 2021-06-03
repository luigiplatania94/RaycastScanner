# RaycastScanner

![](Documentation/Images/Image01.png)
 
## Description
Real-time geometry-based raycast system.

This is an attempt to recreate a Snowdrop Core Module called "BubbleSpace" in Unreal using C++.

It's an Actor Component that returns an average of the width around the player. It has both an Optimistic Metric and a Pessimistic Metric.
It can be used by Sound Designers to switch between ambiances, weather, weapon tails, modify parameters in real-time (for example reverb parameters).

Click here for more info about the original Bubblespace:
https://www.youtube.com/watch?v=mN56EauPhPQ&t=765s&ab_channel=GDC


## Supported Engine Versions
4.26 

## How to install the Plugin 
After you download the repository, extract the zip archive. Your Project can be either a C++ Project or a Blueprint Project. 

Copy the folders "RaycastScannerPlugin" into the "Plugins" folder of your UE4 project. 

If you don’t have a Plugins folder in your project folder yet, just create one.

You will be able to see it in the Editor only if you toggle the "Show Plugin Content" on the "View Options".
