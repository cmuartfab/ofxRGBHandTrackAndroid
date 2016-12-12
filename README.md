OpenFrameworks based android application for hand segmentation.

This application requires the following addons:

- ofxAndroid
- ofxAccelerometer
- ofxOpenCv
- ofxCv
- ofxPerPixelSegment (Use the one found here - https://github.com/cmuartfab/ofxPerPixelSegmentAndroid and rename the folder to ofxPerPixelSegment)

To install them for your environment, Google their names, find their GitHub repository, and clone those repositories in .../of_v0.9.7_android_release/addons

Steps for getting this project running:

- Install OpenFrameworks Android 0.97 and build according to the tutorial on the openframeworks site.
- Install all the addons listed above.
- Make a copy of the empty project and rename the files according to the tutorial on the openframeworks site.
- Copy and replace addons.make from this repository.
- Copy the 3 source files from the src folder
- Copy the models in "addons/ofxPerPixelSegment/libs/perpix/models/handtracking" tp "/sdcard/handtracking" on the phone
- Build the app.
