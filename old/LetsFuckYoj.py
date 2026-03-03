import pymysql

# 连接到数据库
connection = pymysql.connect(
    host='218.106.181.143',
    user='2023202295',
    password='ljy2005129',
    database='your_database'
)

try:
    with connection.cursor() as cursor:
        # 更新ac题目数量的SQL语句
        sql = "UPDATE users SET ac_count = 1231 WHERE username = %s"
        cursor.execute(sql, ('your_username',))

        # 提交更改
        connection.commit()
finally:
    connection.close()
