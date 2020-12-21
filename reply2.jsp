<%--
  Created by IntelliJ IDEA.
  User: luxia
  Date: 2020/12/20
  Time: 20:44
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="java.sql.*" %>
<%@ page errorPage="ShowError.jsp" %>
<html>
<head>
    <title>reply2</title>
</head>
<body>
<%
    String spid = request.getParameter("id");
    int pid = Integer.parseInt(spid);
    String srootid = request.getParameter("rootid");
    int rootid = Integer.parseInt(srootid);
    String title = request.getParameter("title");
    String name = request.getParameter("name");
    String content = request.getParameter("content");

    Class.forName("com.mysql.jdbc.Driver");
    Connection connection = DriverManager.getConnection(
            "jdbc:mysql://localhost:3306/mybbs?&useSSL=false",
            "root", "1992");

    String sql = "insert into mybbs.talk values (null,?,?,?,?,?)";
    PreparedStatement stmt=connection.prepareStatement(sql);
    stmt.setString(1,name);
    stmt.setInt(2,pid);
    stmt.setInt(3,rootid);
    stmt.setString(4,title);
    stmt.setString(5, content);
    stmt.executeUpdate();

    stmt.close();
    connection.close();
    response.sendRedirect("index.jsp");
%>

</body>
</html>
