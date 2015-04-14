# picking-challenge-json
Read in the APC workorder and bin contents from JSON file

Building
Shelf/src directory contains code for reading in the bin_contents object of the Amazon Picking Challenge JSON file.
Workorder/src directory contatins code for reading in the work_order object of the APC JSON.
Run make in each of the src directories. shelf.out and workorder.out will be created.

Usage
/path/to/shelf.out FILENAME
where FILENAME is the APC JSON file. This will read in the bin_contents in the file and print its contents.


/path/to/workorder.out FILENAME
where FILENAME is the APC JSON file. This will read in the work_order in the file and print its contents.
