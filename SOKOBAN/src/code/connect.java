package gui;
import java.sql.*;

public class Connect {
	/** 
     * Connect to a sample database 
     * https://www.javatpoint.com/java-sqlite
     */  
    public static void connect() {  
        Connection conn = null; 
        
        try {  
            // db parameters  
            String url = "jdbc:sqlite:/Polytech/arguillot/Telechargements/sqlite-tools-linux-x86-3400000/test.db";  
            // create a connection to the database  
            conn = DriverManager.getConnection(url);  
              
            System.out.println("Connection to SQLite has been established.");  
            
            String sql = "CREATE TABLE IF NOT EXISTS employees (\n"  
                    + " id integer PRIMARY KEY,\n"  
                    + " name text NOT NULL,\n"  
                    + " capacity real\n"  
                    + ");";
            Statement stmt = conn.createStatement();  
            stmt.execute(sql);
            
        } catch (SQLException e) {  
            System.out.println(e.getMessage());  
        } finally {  
            try {  
                if (conn != null) {  
                    conn.close();  
                }  
            } catch (SQLException ex) {  
                System.out.println(ex.getMessage());  
            }  
        }
        
    }  
    /** 
     * @param args the command line arguments 
     */  
    public static void main(String[] args) {  
        connect();  
    }  
}
