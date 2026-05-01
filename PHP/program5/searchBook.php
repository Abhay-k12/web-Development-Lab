<?php
    
$title = $_POST['title'];

$conn = mysqli_connect("localhost", "root", "", "library");

if(!$conn){
    echo "No Connection Created With Database";
    exit();
}

$sql = "SELECT * FROM books WHERE title LIKE '%$title%'";
$result = mysqli_query($conn, $sql);

if(mysqli_num_rows($result) > 0){
    echo "<h2>Search Results</h2>";
    echo "<table border='1'>
            <tr>
                <th>Accession No</th>
                <th>Title</th>
                <th>Authors</th>
                <th>Edition</th>
                <th>Publisher</th>
            </tr>";

    while($row = mysqli_fetch_assoc($result)){
        echo "<tr>
                <td>".$row['accession_number']."</td>
                <td>".$row['title']."</td>
                <td>".$row['authors']."</td>
                <td>".$row['edition']."</td>
                <td>".$row['publisher']."</td>
          </tr>";
        }

    echo "</table>";
    } 
    else {
        echo "No results found!";
    }
?>