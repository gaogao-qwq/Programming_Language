<!DOCTYPE html>
<html>
	<body>
		<?php 
		$var1 = 114514;
		$var2 = 1919810;
		# 花括号风格 ifelse-stmt
		if ($var1 == 114514) {
			echo "var1 = 114514";
		} elseif ($var1 == 1919810) {
			echo "var1 = 1919810";
		}
		?>
		<!-- 分割风格 ifelse-stmt -->
		<?php if ($var2 == 114514): ?>
		var2 = 114514
		<?php elseif ($var2 == 1919810): ?>
		var2 = 1919810
		<?php endif ?>
	</body>
</html>
