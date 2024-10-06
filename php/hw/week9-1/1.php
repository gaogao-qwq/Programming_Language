<?php
$mysqli = mysqli_connect(hostname: "localhost", username: "root", password: "root", database: "test", port: "3306");

echo "<table border=1><tr>";
$post_column_names_result = $mysqli->query("show columns from post;");
while ($row = $post_column_names_result->fetch_array()) {
  echo "<td>".$row["Field"]."</td>";
}
echo "</tr>";

$post_result = $mysqli->query("select * from post;");
$posts = $post_result->fetch_all();
foreach ($posts as $post) {
  echo "<tr>";
  foreach($post as $key => $value) {
    echo "<td>".$value."</td>";
  }
  echo "</tr>";
}
echo"</table>";
?>
