package org.qtproject.example;

import org.qtproject.qt5.android.bindings.QtService;

import android.app.Notification;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Environment;
import android.os.IBinder;
import android.support.v4.app.NotificationCompat;
import android.util.Log;

public class MyService extends QtService {

  private static final String LOG_TAG = "MyService";

  @Override
  public void onCreate() {
    Log.i(LOG_TAG, ">>>>>>>>>> MyService.onCreate <<<<<<<<<<");
    super.onCreate();
  }

  @Override
  public int onStartCommand(Intent intent, int flags, int start_id) {
    String action = intent.getAction();
    Log.i(LOG_TAG, "onStartCommand " + action);

    int rc =  super.onStartCommand(intent, flags, start_id);

    if (action.equals(Constants.ACTION.START))
      // start_foreground_service();
      NativeFunctions.ServiceServerStartTimer();
    else if (action.equals(Constants.ACTION.STOP))
      // stop_foreground_service();
      NativeFunctions.ServiceServerStopTimer();

    return rc;

    // return START_STICKY;
  }

  @Override
  public void onDestroy() {
    Log.i(LOG_TAG, "onDestroy");
    super.onDestroy();
  }

  @Override
  public IBinder onBind(Intent intent) {
    Log.i(LOG_TAG, "onBind");
    return super.onBind(intent);
    // Used only in case of bound services.
    // return null;
  }

  private void start_foreground_service() {
    Log.i(LOG_TAG, "Received Start Intent");
    // Make this service run in the foreground, supplying the ongoing notification to be shown to the user while in this state.
    startForeground(Constants.NOTIFICATION_ID.MY_SERVICE, build_notification());
  }

  private void stop_foreground_service() {
    Log.i(LOG_TAG, "Received Stop Intent");
    stopForeground(true);
    stopSelf();

    /*
E/ActivityThread(28831): Service org.qtproject.example.MyService has leaked ServiceConnection org.qtproject.qt5.android.bindings.QtLoader$3@450d0fe that was originally bound here
E/ActivityThread(28831): android.app.ServiceConnectionLeaked: Service org.qtproject.example.MyService has leaked ServiceConnection org.qtproject.qt5.android.bindings.QtLoader$3@450d0fe that was originally bound here
E/ActivityThread(28831):        at android.app.LoadedApk$ServiceDispatcher.<init>(LoadedApk.java:1134)
E/ActivityThread(28831):        at android.app.LoadedApk.getServiceDispatcher(LoadedApk.java:1028)
E/ActivityThread(28831):        at android.app.ContextImpl.bindServiceCommon(ContextImpl.java:2085)
E/ActivityThread(28831):        at android.app.ContextImpl.bindService(ContextImpl.java:2068)
E/ActivityThread(28831):        at android.content.ContextWrapper.bindService(ContextWrapper.java:559)
E/ActivityThread(28831):        at org.qtproject.qt5.android.bindings.QtLoader.startApp(QtLoader.java:652)
E/ActivityThread(28831):        at org.qtproject.qt5.android.bindings.QtServiceLoader.onCreate(QtServiceLoader.java:60)
E/ActivityThread(28831):        at org.qtproject.qt5.android.bindings.QtService.onCreate(QtService.java:57)
E/ActivityThread(28831):        at org.qtproject.example.MyService.onCreate(MyService.java:24)
E/ActivityThread(28831):        at android.app.ActivityThread.handleCreateService(ActivityThread.java:3100)
E/ActivityThread(28831):        at android.app.ActivityThread.access$1900(ActivityThread.java:172)
E/ActivityThread(28831):        at android.app.ActivityThread$H.handleMessage(ActivityThread.java:1505)
E/ActivityThread(28831):        at android.os.Handler.dispatchMessage(Handler.java:102)
E/ActivityThread(28831):        at android.os.Looper.loop(Looper.java:145)
E/ActivityThread(28831):        at android.app.ActivityThread.main(ActivityThread.java:5832)
E/ActivityThread(28831):        at java.lang.reflect.Method.invoke(Native Method)
E/ActivityThread(28831):        at java.lang.reflect.Method.invoke(Method.java:372)
E/ActivityThread(28831):        at com.android.internal.os.ZygoteInit$MethodAndArgsCaller.run(ZygoteInit.java:1399)
E/ActivityThread(28831):        at com.android.internal.os.ZygoteInit.main(ZygoteInit.java:1194)
I/ActivityManager(  894): Killing 28296:com.sec.android.app.myfiles/u0a50 (adj 15): emptyCount ##36
W/ActivityManager(  894): Unbind failed: could not find connection for android.os.BinderProxy@38cae15c
    */
  }

  private Notification build_notification() {
    Intent main_activity_intent = new Intent(this, MyActivity.class);
    main_activity_intent.setAction(Constants.ACTION.MAIN);
    main_activity_intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_CLEAR_TASK);
    PendingIntent pending_intent = PendingIntent.getActivity(this, 0, main_activity_intent, 0);

    Intent stop_intent = new Intent(this, MyService.class);
    stop_intent.setAction(Constants.ACTION.STOP);
    PendingIntent pending_stop_intent = PendingIntent.getService(this, 0, stop_intent, 0);

    Bitmap icon = BitmapFactory.decodeResource(getResources(), R.mipmap.ic_launcher); // R.drawable.xxx

    return new NotificationCompat.Builder(this)
      .setPriority(Notification.PRIORITY_MAX)
      .setContentTitle("Foreground Service")
      .setTicker("Foreground Service") // Set the text that is displayed in the status bar when the notification first arrives. 
      .setContentText("Hello!")
      .setSmallIcon(R.mipmap.ic_launcher)
      .setLargeIcon(Bitmap.createScaledBitmap(icon, 128, 128, false))
      .setContentIntent(pending_intent) // Supply a PendingIntent to send when the notification is clicked.
      .setOngoing(true)
      .addAction(android.R.drawable.ic_media_pause, "Stop", pending_stop_intent)
      .build();
  }
}
