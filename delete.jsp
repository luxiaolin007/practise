<%--
  Created by IntelliJ IDEA.
  User: luxia
  Date: 2020/12/20
  Time: 17:57
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="java.sql.*" %>
<%@ page errorPage="ShowError.jsp" %>
<html>
<head>
    <title>删除</title>
</head>
<body>
<%
    String sure = (String) session.getAttribute("del");
    if (!sure.equals("sure")) {
        response.sendRedirect("index.jsp");
        return;
    }else {
        String del = request.getParameter("id");
        int i = Integer.parseInt(del);

        Class.forName("com.mysql.jdbc.Driver");
        Connection connection = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/mybbs?&useSSL=false",
                "root", "1992");
        String sql = "delete from mybbs.talk where id= ? or pid=? or rootid=?";
        PreparedStatement stmt = connection.prepareStatement(sql);
        stmt.setInt(1, i);
        stmt.setInt(2, i);
        stmt.setInt(3, i);
        stmt.executeUpdate();


        stmt.close();
        connection.close();
        response.sendRedirect("index.jsp");
    }
%>
</body>
</html>
