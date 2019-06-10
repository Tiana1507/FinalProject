html>
  <head>
    <title>Tictactoe Simulation</title>
  </head>
  <body>
    <h1>TicTacToe Simulation</h1>
    <p>Computer simulates how TicTacToe is played using random maths to select spots.</p>

    <?php
       // define variables and set to empty values
       $arg1 = "";
       if ($_SERVER["REQUEST_METHOD"] == "POST") {
         $arg1 = test_input($_POST["arg1"]);
         if (is_numeric($arg1)) {
            echo "<h2>Your Input:</h2>";
            echo $arg1;
            echo "<br>";
            echo "<br>";
         }
         echo shell_exec('./tictactoe ' . $arg1);
         #echo shell_exec('gcc tictactoe.c -o tictactoe');
       }
       function test_input($data) {
         $data = trim($data);
         $data = stripslashes($data);
         $data = htmlspecialchars($data);
         return $data;
       }
    ?>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
      <br>
      Input a positive number (will be used as a random seed): <input type="text" name="arg1"><br>
      <br>
      <input type="submit" value="Go!">
    </form>

  </body>
</html>
