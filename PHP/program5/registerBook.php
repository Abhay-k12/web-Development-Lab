<?php
$conn = mysqli_connect("localhost", "root", "", "library");

if(!$conn){
    echo "No Connection Created With Database";
    exit();
}

$accessionNumber = $_POST['accessionNumber'];
$title = $_POST['title'];
$authors = $_POST['authors'];
$edition = $_POST['edition'];
$publisher = $_POST['publisher'];

$sql = "INSERT INTO books VALUES ('$accessionNumber', '$title', '$authors', '$edition', '$publisher')";

if(mysqli_query($conn, $sql) === TRUE){
    echo "Book registered successfully!";
} 
else {
    echo "Error: " . $conn->error;
}
?>