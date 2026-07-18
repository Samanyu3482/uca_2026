#!/bin/bash

echo "Task 1: Basic Field Extraction"
awk -F',' '{print $1, $2}' data.txt

echo
echo "Task 2: Engineering Employees"
awk -F',' '$2=="Engineering"' data.txt

echo
echo "Task 3: Gross Pay"
awk -F',' '{print $1 " gross pay: $" $3*$4}' data.txt

echo
echo "Task 4: Record Number and Number of Fields"
awk -F',' '{print NR " (" NF " fields): " $0}' data.txt

echo
echo "Task 5: Total Engineering Payroll"
awk -F',' '
BEGIN {
    total = 0
}
$2 == "Engineering" {
    total += $3 * $4
}
END {
    print "Total Engineering Payroll: $" total
}
' data.txt
