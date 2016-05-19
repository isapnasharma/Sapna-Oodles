// This is a test harness for your module
// You should do something interesting in this harness
// to test out the module and to provide instructions
// to users on how to use it by example.



var smslistener = require('com.oodles.smslistener');


//check whether SMS permissions are enabled
if (!smslistener.hasSMSReceivePermission()) {
	 //for android 6.0 move user to app settings to enable SMS permission at run time
		var enablePermissionDialogue = Titanium.UI.createAlertDialog({
        		message : "To auto fetch OTP please enable SMS permission in the app's settings",
        		buttonNames : ['Allow', 'Deny'],
        		cancel : 1
        	});
        	enablePermissionDialogue.addEventListener('click', function(e) {
        		if (e.index === 0) {
        			var intent = Ti.Android.createIntent({
        				action : 'android.settings.APPLICATION_SETTINGS',
        			});
        			intent.addFlags(Ti.Android.FLAG_ACTIVITY_NEW_TASK);
        			Ti.Android.currentActivity.startActivity(intent);
        		}
        	});
        	enablePermissionDialogue.show();
		return;

		//listen SMS to auto fetch OTP
        smslistener.addEventListener('complete', function(e) {
        	Ti.API.info('Result: ' + (e.success ? 'success' : 'failure') + ' msg: ' + e.resultMessage + 'sender' +e.senderNum);
        	switch (e.result) {
        	case smslistener.RECEIVED:
        		Ti.API.info("***********RECEIVED*********");
        		var arr = e.resultMessage.split(".");
        		$.verificationCode.value = (arr[0].split("is")[1]).trim();
        		break;
        	case smslistener.FAILED:
        	    alert("Enter OTP manually");
        		break;
        	}
        });
}