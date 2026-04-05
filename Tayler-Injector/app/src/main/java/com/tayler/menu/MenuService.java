package com.tayler.menu;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;

public class MenuService extends Service {
    static {
        System.loadLibrary("TaylerMenu");
    }

    @Override
    public void onCreate() {
        super.onCreate();
        initCheat();
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    private native void initCheat();
}