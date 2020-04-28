package cn.model;

public class User {
    private int Id;
    private String username;
    private String password;
    private String email;
    private int phone;

    public User() {
    }

    public User(int id, String username, String password, String email, int phone) {
        Id = id;
        this.username = username;
        this.password = password;
        this.email = email;
        this.phone = phone;
    }

    public int getId() {
        return Id;
    }

    public void setId(int id) {
        Id = id;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public int getPhone() {
        return phone;
    }

    public void setPhone(int phone) {
        this.phone = phone;
    }
}

