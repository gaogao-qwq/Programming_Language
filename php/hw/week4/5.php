<html>
  <head>
    <title>表格生成器</title>
    <style>
      table {
        border-collapse: collapse;
        border: 2px solid rgb(140 140 140);
      }
      thead {
        background-color: rgb(228 240 245);
      }
      th, td {
        border: 1px solid rgb(160 160 160);
        width: 80px;
      }
      tr {
        height: 40px
      }
      .grey {
        background-color: rgb(237 238 242);
      }
    </style>
  </head>
  <body>
    <table>
      <thead>
        <tr>
          <?php
            $row = 5;
            $col = 10;
            for ($i = 0; $i < $col; ++$i) {
              echo "<th></th>";
            }
          ?>
        </tr>
      </thead>
      <tbody>
        <?php
          for ($i = 0; $i < $row; ++$i) {
            echo ($i & 1) ? '<tr class="grey">' : "<tr>";
            for ($j = 0; $j < $col; ++$j) {
              echo "<td></td>";
            }
            echo "</tr>";
          }
        ?>
      </tbody>
    </table>
  </body>
</html>
