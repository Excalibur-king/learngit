package cn.servlet;


import cn.Dao.userDao;
import cn.model.User;


//import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;


@WebServlet("/regist")
public class RegistServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
//        super.doPost(req, resp);
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        String email = req.getParameter("email");
        String Phone = req.getParameter("phone");
//        System.out.println(username+ " " +password+ " " +email+ " " +Phone+ " ");
        int phone = Integer.parseInt(Phone);
        User user=new User();
        user.setUsername(username);
        user.setPassword(password);
        user.setEmail(email);
        user.setPhone(phone);
        userDao.insert(user);
        resp.sendRedirect("login.html");
    }
}
