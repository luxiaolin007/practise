<%--
  Created by IntelliJ IDEA.
  User: luxia
  Date: 2020/12/20
  Time: 20:29
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page errorPage="ShowError.jsp" %>
<html>
<head>
    <title>reply</title>
</head>
<body>
<%
    String sid = request.getParameter("id");
    int id = Integer.parseInt(sid);
    String srootid = request.getParameter("rootid");
    int rootid = Integer.parseInt(srootid);

%>
    <form name="reply" action="reply2.jsp">
        <label>名字：</label>
        <label>
            <input type="text" name="name">
        </label>
        <br/>
        <label>标题：</label>
        <label>
            <input type="text" name="title">
        </label>
        <br/>
        <label>内容：</label>
        <label>
            <input type="text" name="content">
        </label>
        <br/>
        <input type="hidden" name="id" value="<%=id%>">
        <input type="hidden" name="rootid" value="<%=srootid%>">

        <input type="submit" value="回复">


</body>
</html>
