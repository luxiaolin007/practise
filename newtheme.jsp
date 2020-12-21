<%--
  Created by IntelliJ IDEA.
  User: luxia
  Date: 2020/12/18
  Time: 14:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>发表新帖</title>
</head>
<body>
<form  action="insert.jsp">
    <label>名字:  </label>
    <label>
        <input type="text" name="name" >
    </label>
    <br/>
    <label>标题： </label>
    <label>
        <input type="text" name="title" placeholder="请输入标题">
    </label>
    <br/>
    <label>内容：</label>
    <label>
        <input type="text" name="content" >
    </label>
    <br/>

    <input type="submit" value="提交">
</form>
</body>
</html>
