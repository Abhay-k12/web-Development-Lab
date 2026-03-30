<?php
session_start();

if(!isset($_SESSION['username'])) {
    echo"No Active Session For User";
}
else {
    echo "Welcome User :".$_SESSION['username'];
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Welcome</title>
</head>
    <br>
    <a href="logout.php">Logout</a>
</body>
</html>