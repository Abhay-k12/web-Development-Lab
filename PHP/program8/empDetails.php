<?php
    $dnos = $_POST['dno'];
    $conn = mysqli_connect("localhost:3306", "root", "", "phpquestions");

    if(!$conn) {
        echo "Connection Error";
        exit();
    }

    echo "<table border=1 cellpadding=5>";
    echo "<tr> <th>Employee Id</th> <th>Employee Name</th> <th>Department No.</th> <th>Salary</th> </tr>";

    $totalRows = 0;
    foreach($dnos as $dno) {
        $query = "SELECT * FROM employee WHERE dno='$dno'";
        $result = mysqli_query($conn, $query);

        $totalRows += mysqli_num_rows($result);
        while($row = mysqli_fetch_assoc($result)) {
            echo "<tr><td>".$row['empid']."</td><td>".$row['empname']."</td><td>".$row['dno']."</td><td>".$row['salary']."</td></tr>";
        }
    }
    
    echo "</table><br>";
    echo "<h3>Total Rows Selected: ".$totalRows."</h3>";
    
    mysqli_close($conn);
?>