package com.tayler.menu;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Toast;

import java.io.DataOutputStream;

public class MainActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        if (requestRootAccess()) {
            Toast.makeText(this, "Root access granted!", Toast.LENGTH_SHORT).show();
            startService(new Intent(this, MenuService.class));
        } else {
            Toast.makeText(this, "Root access denied!", Toast.LENGTH_LONG).show();
        }

        finish();
    }

    private boolean requestRootAccess() {
        try {
            Process su = Runtime.getRuntime().exec("su");
            DataOutputStream outputStream = new DataOutputStream(su.getOutputStream());
            outputStream.writeBytes("exit\n");
            outputStream.flush();
            int exitCode = su.waitFor();
            return exitCode == 0;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }
}