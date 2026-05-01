<?php 
    session_start();

    if(isset($_SESSION["page_view"])) {
        $_SESSION['page_view'] += 1;
    }
    else {
        $_SESSION['page_view'] = 1;
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h2>Total Page Count : <?php echo $_SESSION["page_view"]; ?> </h2>
    <div id = "time"> </div>
    
    <script>
        const timeBox = document.getElementById('time');

        function updateTime() {
            time.innerHTML = `Current Time: ${new Date()}`;
        }

        const intervalId = setInterval(updateTime, 1000);
    </script>
</body>
</html>
