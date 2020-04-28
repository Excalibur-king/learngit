package cn.Dao;

import cn.jdbcUtils.JdbcUtils;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class Userlogin {
    private static final String driver = "com.mysql.cj.jdbc.Driver";
    private static final String url = "jdbc:mysql://localhost:3306/loginre";
    private static final String uname ="root";
    private static final String password = "@Cc153612";
    public  int login(String username,String password){
        int num=0;
        String sql = "select * from loginandre where username = ? and password =?";
        Connection conn = null;
        PreparedStatement stmt = null;
        ResultSet rs = null;
        try{
            Class.forName(driver);
            conn = DriverManager.getConnection(url,uname,password);
            stmt = conn.prepareStatement(sql);
            stmt.setString(1,username);
            stmt.setString(2,password);
            rs = stmt.executeQuery();
            if(rs.next()){
                 num = 1;
            }

        }catch (Exception e){
            e.printStackTrace();
        }finally {
            JdbcUtils.close(conn,stmt,rs);
        }
        return num;
    }

    public static void main(String[] args) {
        Userlogin userlogin = new Userlogin();

    }
}
