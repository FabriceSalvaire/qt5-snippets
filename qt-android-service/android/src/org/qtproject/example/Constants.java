package org.qtproject.example;

public class Constants {
  public interface ACTION {
    String MAIN = "org.qtproject.example.action.main";
    String START = "org.qtproject.example.action.start";
    String STOP = "org.qtproject.example.action.stop";
  }

  public interface NOTIFICATION_ID {
    int MY_SERVICE = 1; // The identifier for this notification, must not be 0.
  }
}
