<%--
  Created by IntelliJ IDEA.
  User: luxia
  Date: 2020/12/21
  Time: 8:45
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>登录</title>
</head>


<body>
<%
    String user = request.getParameter("user");
    String psw = request.getParameter("psw");
    if (user == null || !user.equals("a")) {
        response.sendRedirect("index.jsp");
        return;
    }
    if (psw == null || !psw.equals("a")) {
        response.sendRedirect("index.jsp");
        return;
    }

    session.setAttribute("enter", "true");
    response.sendRedirect("index.jsp");

    //return;
%>
</body>
</html>
