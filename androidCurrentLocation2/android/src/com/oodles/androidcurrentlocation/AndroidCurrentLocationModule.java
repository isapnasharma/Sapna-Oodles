package com.oodles.androidcurrentlocation;

import org.appcelerator.kroll.KrollModule;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.titanium.*;
import org.appcelerator.kroll.KrollDict;
import org.appcelerator.titanium.TiC;

import android.location.LocationListener;

import org.appcelerator.titanium.TiApplication;
import org.appcelerator.kroll.common.Log;
import org.appcelerator.kroll.common.TiConfig;

import android.content.Context;
import android.app.Activity;
import android.location.Location;
import android.location.LocationListener;
import android.os.Bundle;
import android.location.LocationManager;

import java.lang.Override;
import java.lang.String;
import android.provider.Settings;

@Kroll.module(name="AndroidCurrentLocation", id="com.oodles.androidcurrentlocation")
public class AndroidCurrentLocationModule extends KrollModule
{

	// Standard Debugging variables
	private static final String LCAT = "AndroidCurrentLocationModule";
	private static final boolean DBG = TiConfig.LOGD;

	@Kroll.constant
	public static final int RECEIVED = 0;
	@Kroll.constant
	public static final int FAILED = -2;

	String latitude, longitude;
	LocationManager locationManager;
	//Location location;

	public AndroidCurrentLocationModule()
	{
		super();
	}

	@Kroll.onAppCreate
	public static void onAppCreate(TiApplication app)
	{
		Log.d(LCAT, "inside onAppCreate");
		// put module init code that needs to run when the application is created
	}

	@Kroll.method
	public void getUserLocation(){
		Log.d(LCAT, "inside getUserLocation");
		Activity currentActivity = TiApplication.getInstance().getCurrentActivity();
		 locationManager = (LocationManager) currentActivity.getSystemService(Context.LOCATION_SERVICE);
		if(locationManager!=null){
			Log.d(LCAT, "providers 1" + locationManager.getAllProviders());
			for (String provider : locationManager.getAllProviders()) {
				if(provider.equals("gps") || provider.equals("network")){
					locationManager.requestLocationUpdates(provider, 10, 10, locationListener);
				}
			}
		}

	}

	LocationListener locationListener = new LocationListener() {
		@Override
		public void onLocationChanged(Location location) {
			Log.d(LCAT, "inside onLocationChanged");
			Activity currentActivity = TiApplication.getInstance().getCurrentActivity();
			KrollDict event;
			latitude = String.valueOf(location.getLatitude());
			longitude = String.valueOf(location.getLongitude());
			Log.d(LCAT, "inside getUserLocation " + latitude + " " + longitude);
			boolean isMock = false;
			if (android.os.Build.VERSION.SDK_INT < 23) {
				if (Settings.Secure.getString(currentActivity.getContentResolver(), Settings.Secure.ALLOW_MOCK_LOCATION).equals("0"))
					isMock = false;
				else
					isMock = true;
			} else {
				isMock = location.isFromMockProvider();
			}
			if(latitude != null){
				event = createEventObject(true, RECEIVED, latitude, longitude, isMock);
				Log.d(LCAT, "location Received");
			}else{
				event = createEventObject(false, FAILED, null, null, isMock);
				Log.d(LCAT, "location not received");
			}
			fireEvent("complete", event);
			if (locationManager != null && latitude != null) {
				locationManager.removeUpdates(locationListener);
				locationManager = null;
			}
		}
		@Override
		public void onStatusChanged(String s, int i, Bundle bundle) {

		}
		@Override
		public void onProviderEnabled(String s) {

		}
		@Override
		public void onProviderDisabled(String s) {

		}
	};

	public KrollDict createEventObject (boolean success, int result, String lati, String longi, boolean isMock) {
		KrollDict event = new KrollDict();
		event.put("success", success);
		event.put("result", result);
		event.put("latitude", lati);
		event.put("longitude", longi);
		event.put("isMock", isMock);

		return event;
	}
}

