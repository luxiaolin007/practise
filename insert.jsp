<%--
  Created by IntelliJ IDEA.
  User: luxia
  Date: 2020/12/20
  Time: 13:05
  To change this template use File | Settings | File Templates.
--%>
<%@ page import="java.sql.*" %>
<%@ page errorPage="ShowError.jsp" %>


<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>insert</title>
</head>
<body>
<%
    String name = request.getParameter("name");
    String title = request.getParameter("title");
    String content = request.getParameter("content");
    Class.forName("com.mysql.jdbc.Driver");
    Connection connection = DriverManager.getConnection(
            "jdbc:mysql://localhost:3306/mybbs?&useSSL=false",
            "root", "1992");

    connection.setAutoCommit(false);
    String sql = "insert into mybbs.talk values (null,?,?,?,?,?);";

    PreparedStatement stmt = connection.prepareStatement(
            sql,Statement.RETURN_GENERATED_KEYS);

    stmt.setString(1, name);
    stmt.setInt(2, 0);
    stmt.setInt(3, 0);
    stmt.setString(4, title);
    stmt.setString(5, content);
    stmt.executeUpdate();
    connection.commit();

    ResultSet rs=stmt.getGeneratedKeys();
    rs.next();
    int id =rs.getInt(1);

//    sql="select * from mybbs.talk where id=?;";
//    stmt = connection.prepareStatement(sql);
//    stmt.setInt(1,id);



    sql="update mybbs.talk set pid=? ,rootid=? where id= "+ id;
    stmt=connection.prepareStatement(sql);
    stmt.setInt(1, id);
    stmt.setInt(2, id);
    stmt.executeUpdate();
    connection.commit();

    rs.close();
    stmt.close();
    connection.close();
    response.sendRedirect("index.jsp");
    %>
    <%--
    sql = "select * from mybbs.talk";
    stmt=connection.prepareStatement(sql);
    rs = stmt.executeQuery();
    while (rs.next()) {
%>
        <%= rs.getString(1) %>
        <%= rs.getString(2) %>
        <%= rs.getString(3) %>
        <%= rs.getString(4) %>
        <%= rs.getString(5) %>
        <%= rs.getString(6) %>

    <%
    }
    %>
title=
<%= title   %>
<br/>
content=
<%= content %>
--%>
</body>
</html>
