package main

import (
	"database/sql"
	"fmt"

	_ "github.com/go-sql-driver/mysql"
)

func main() {
	// 插入数据
	db, err := sql.Open("mysql", "root:8603Ace!@tcp(127.0.0.1:3306)/test_db")
	checkErr(err)

	stmt, err := db.Prepare("insert test_db.userinfo set username=?,created=?")
	checkErr(err)

	res, err := stmt.Exec("gaogao_qwq", "2023-01-16")
	checkErr(err)

	id, err := res.LastInsertId()
	checkErr(err)
	fmt.Println("LastInsertId:", id)

	// 更新数据
	stmt, err = db.Prepare("update test_db.userinfo set username=? where uid=?")
	checkErr(err)

	res, err = stmt.Exec("gaogao_qwq_updated", id)
	checkErr(err)

	affect, err := res.RowsAffected()
	checkErr(err)
	fmt.Println("RowsAffected:", affect)

	// 查询数据
	rows, err := db.Query("select * from test_db.userinfo")
	checkErr(err)
	for rows.Next() {
		var uid int
		var username string
		var created string
		err = rows.Scan(&uid, &username, &created)
		checkErr(err)
		fmt.Println("uid:", uid)
		fmt.Println("username:", username)
		fmt.Println("created:", created)
	}

	// 删除数据
	stmt, err = db.Prepare("delete from test_db.userinfo where uid=?")
	checkErr(err)

	res, err = stmt.Exec(id)
	checkErr(err)

	affect, err = res.RowsAffected()
	checkErr(err)
	fmt.Println("RowsAffected:", affect)

	err = db.Close()
	checkErr(err)
}

func checkErr(err error) {
	if err != nil {
		panic(err)
	}
}
