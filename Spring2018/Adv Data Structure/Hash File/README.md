# Hash File
Program to understand the storing and retriveing of hash files. C++

## Record
Class to hold one entry of data, can set and retrieve
* Name
* ID

## Bucket
Class to hold multiple records,a bucket is an array of records<br />
Can insert and retrieve a whole record class from bucket

## Hash File
Class to store buckets of records to binary a binary file.
* h/h2: function to pick bucket to insert or retrieve record, bases on ID
* inset: adds record to n bucket, n determined by h/h2
* isRoom: determines if bucket is at capacity
* revealTable: displays all buckets and its contents
* retrive: returns record determied by ID, using h/h2 to find bucket
