package cn.servlet;
import cn.Dao.Userlogin;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;





@WebServlet("/login")
public class LoginServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        System.out.println(username+ " " +password+ " " );
        Userlogin userlogin = new Userlogin();

        int num = userlogin.login(username,password);
        System.out.println(num);
        if(num==1){
            request.getRequestDispatcher("success.html").forward(request,response);
        }else{
            request.setAttribute("errorMsg","昵称或密码错误");
            request.getRequestDispatcher("login.html").forward(request,response);
        }
    }

}