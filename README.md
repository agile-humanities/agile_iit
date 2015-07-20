# Agile IIT
## Introduction

A Drupal 7 wrapper for the IIT Image Comparison Tool.

## Requirements

* [Flag](https://www.drupal.org/project/flag)


## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Usage

Installing this module will cause three things to be automatically created:

* A flag called "Selected" (machine name: selected_images), with permissions to flag/unflag given to all authenticated users,
* A view at /selected (i.e. at URL http://DRUPAL_ROOT/selected) where users can see their own selected images, and
* A block that contains the IIT Viewer, and shows up only on at /selected. 

A link to /selected ("My Selected Images") will appear on the Navigation menu, which is by default visible in the first sidebar. 

After dragging two images into the IIT Image viewer, the "View Two Images", "Crop Sections", and "Show/Hide Grid" buttons are functional. 

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
