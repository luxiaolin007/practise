<%@ page import="java.sql.*" %>

<%--
  Created by IntelliJ IDEA.
  User: luxia
  Date: 2020/12/18
  Time: 13:28
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page errorPage="ShowError.jsp" %>

<html>
<head>
    <title>主页</title>
</head>
<body>
<a href="newtheme.jsp">发表新贴</a>
<br/>
<br/>
<%
    int pageSize = 3;
    int pagenum =1;

    String sp=request.getParameter("pagenum");
    if(sp==null){
    }else {
        try {
            pagenum = Integer.parseInt(sp);
        }catch(Exception e){
            response.sendRedirect("index.jsp");
            return;
        }
    }
    int totalpages;

    if (pagenum<1)
        pagenum=1;

    String login = "";
    boolean flag = false;

    try {
        login = (String) session.getAttribute("enter");
    } catch (Exception e) {
        e.printStackTrace();
    }

    if (login == null) ;
    else if (login.equals("true")) {
        flag = true;
    }

    String sout = request.getParameter("out");

    if (sout == null)
        ;
    else if (sout.equals("yes")) {
        flag = false;
        session.setAttribute("del", "deny");
    }
    Class.forName("com.mysql.jdbc.Driver");
    Connection connection = DriverManager.getConnection(
            "jdbc:mysql://localhost:3306/mybbs" +
                    "?&useSSL=false", "root", "1992");

    String s = "select count(*) from mybbs.talk where id=rootid;";
    PreparedStatement st = connection.prepareStatement(s);
    ResultSet r = st.executeQuery();
    r.next();
    totalpages = r.getInt(1);
    totalpages = totalpages % pageSize == 0
            ? totalpages / pageSize : totalpages / pageSize + 1;

    if(pagenum>totalpages)
        pagenum=totalpages;
    String sql = "select * from mybbs.talk " +
            "where id=rootid order by id  limit ?,? ";
    PreparedStatement stmt = connection.prepareStatement(sql);
    stmt.setInt(1, (pagenum - 1) * pageSize);
    stmt.setInt(2, pageSize);
    ResultSet rst = stmt.executeQuery();
%>
<table border="1">
    <tr>
        <th>id</th>
        <th>name</th>
        <th>pid</th>
        <th>rootid</th>
        <th>title</th>
        <th>content</th>
    </tr>
    <%
        while (rst.next()) {
    %>
    <tr>
        <td><%= rst.getString(1) %>
        </td>
        <td><%= rst.getString(2) %>
        </td>
        <td><%= rst.getString(3) %>
        </td>
        <td><%= rst.getString(4) %>
        </td>
        <td><a href='content.jsp?id=<%= rst.getInt("id")%>'>
            <%= rst.getString(5) %>
        </a>
        </td>
        <td><%= rst.getString(6) %>
        </td>

        <% if (flag) {%>
        <td>
            <%
                session.setAttribute("del", "sure");
                session.setMaxInactiveInterval(20);
            %>
            <a href='delete.jsp?id=<%= rst.getInt("id")%>'>删除</a>
        </td>
        <%}%>
        <td>
            <a href='reply.jsp?id=
            <%= rst.getInt("id")%>
            &rootid=<%=rst.getInt("rootid")%>'>回复</a>
        </td>
        <%
            }
        %>
    </tr>
</table>
<br/>
共<%=totalpages%>页，第<%=pagenum%>页
<br/>
<a href="index.jsp?pagenum=<%=pagenum-1%>">上一页</a>&nbsp;&nbsp;
<a href="index.jsp?pagenum=<%=pagenum+1%>">下一页</a>

<form action="index.jsp" name="ff">
<select >
    <%
        for(int i=1;i<=totalpages;i++){
    %>
        <option value="<%=i%>" <%=i==pagenum?"selected":""%>>第<%=i%>页</option>
    <%
}
        %>
</select>
</form>
<br/>
<form action="index.jsp">
    请输入第<input type="text" name="pagenum"  size="4"  value="<%=pagenum%>" >页
     <input type="submit" value="choose">
</form>

<form action="login.jsp" method="post">
    <label>管理员登录</label>
    <label>
        <input type="text" name="user">
    </label>
    <label>
        <input type="password" name="psw">
    </label>
    <input type="submit" value="ok">
</form>
<form action="index.jsp" method="post">
    <input type="hidden" name="out" value="yes">
    <input type="submit" value="out">
</form>
</body>
<%
    rst.close();
    stmt.close();
    connection.close();
%>
</html>