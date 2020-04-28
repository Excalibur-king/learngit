package cn.jdbcUtils;

//import javax.sql.DataSource;
//import java.io.InputStream;
import java.sql.*;
//import java.util.Properties;

public class JdbcUtils {

//    public static Connection getConnection(){
//        Connection conn = null;
//        try{
//            conn = DATA_SOURCE.getConnection();
//        }catch (SQLException e){
//            e.printStackTrace();
//        }
//        return conn;
    public static  void close(Connection conn, Statement stmt, ResultSet rs){
        if(rs!=null){
            try{
                rs.close();
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
        if(stmt!=null){
            try{
                stmt.close();
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
        if(conn!=null){
            try{
                conn.close();
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
    }
}
