package org.qtproject.example;

public class NativeFunctions {
  // Define the native function
  // these functions are called by the BroadcastReceiver object
  // when it receives a new notification
  public static native void ServiceServerStartTimer();
  public static native void ServiceServerStopTimer();
}
