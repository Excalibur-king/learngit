package cn.Dao;

import cn.jdbcUtils.JdbcUtils;
import cn.model.User;



import java.sql.*;

public class userDao {
    private static final String driver = "com.mysql.cj.jdbc.Driver";
    private static final String url = "jdbc:mysql://localhost:3306/loginre";
    private static final String uname ="root";
    private static final String password = "@Cc153612";



    public static void insert(User user){
        String sql = "insert into loginandre VALUES(null,?,?,?,?)";
        Connection conn = null;
        PreparedStatement stat = null;
        try{
            Class.forName(driver);
            conn = DriverManager.getConnection(url, uname ,password);
            stat = conn.prepareStatement(sql);
            stat.setString(1, user.getUsername());
            stat.setString(2, user.getPassword());
            stat.setString(3, user.getEmail());
            stat.setInt(4, user.getPhone());
            stat.executeUpdate();
            System.out.println(sql);
        }catch(Exception e){
            e.printStackTrace();
        }finally {
            try{
                if(stat!=null){
                    stat.close();
                }
                if(conn!=null){
                    conn.close();
                }
            }catch (SQLException e){
                e.printStackTrace();
            }
        }

    }
    public int login(String username,String password){
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
                return 1;
            }
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            JdbcUtils.close(conn,stmt,rs);
        }
        return 0;
    }

    public static void main(String[] args) {
        User user =  new User();
        user.setUsername("cqr");
        user.setPassword("13456");
        user.setEmail("cqr@qq.com");
        user.setPhone(123);
        insert(user);


    }

    }
