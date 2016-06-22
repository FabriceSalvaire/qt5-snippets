/**************************************************************************************************/

package org.qtproject.example;

import android.content.Intent;
import android.os.Bundle;
import android.provider.SyncStateContract;
import android.util.Log;

/**************************************************************************************************/

public class MyActivity extends org.qtproject.qt5.android.bindings.QtActivity
{
  private static final String LOG_TAG = "MyActivity";

  private static MyActivity m_instance;

  public MyActivity()
  {
    m_instance = this;
  }

  @Override
  public void onCreate(Bundle savedInstanceState)
  {
    Log.i(LOG_TAG, ">>>>>>>>>> MyActivity.onCreate <<<<<<<<<<");
    super.onCreate(savedInstanceState);
  }

  @Override
  protected void onDestroy() {
    super.onDestroy();
  }

  public void start_service () {
    Log.i(LOG_TAG, ">>>>>>>>>> MyActivity.start_service <<<<<<<<<<");
    Intent start_intent = new Intent(MyActivity.this, MyService.class); // package_context, class
    start_intent.setAction(Constants.ACTION.START); // Set the general action to be performed.
    startService(start_intent);
  }

  public void stop_service () {
    Log.i(LOG_TAG, ">>>>>>>>>> MyActivity.stop_service <<<<<<<<<<");
    Intent stop_intent = new Intent(MyActivity.this, MyService.class);
    stop_intent.setAction(Constants.ACTION.STOP);
    startService(stop_intent);

    // boolean rc = stopService(stop_intent);
    // Log.i(LOG_TAG, "stopService " + rc);
  }
}

/***************************************************************************************************
 *
 * End
 *
 **************************************************************************************************/
