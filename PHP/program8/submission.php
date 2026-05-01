<?php 
    $empName = $_POST['empname'];
    $empid = $_POST['empid'];
    $dno = $_POST['dno'];
    $salary = $_POST['salary'];
    
    $conn = mysqli_connect("localhost:3306", "root", "", "phpquestions");
    if(!$conn) {
        echo "Error while making connection";
        exit();
    }
    
    $query = "INSERT INTO employee VALUE ('$empid', '$empName','$dno','$salary')";
    if(mysqli_query($conn, $query)) {
        echo "Inserted successfully";
    }
    else {
        echo "Some error occurred.";
    }
?>