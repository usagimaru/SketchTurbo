var onStartup = function(context) {
	var TurboCore_FrameworkPath = TurboCore_FrameworkPath || COScript.currentCOScript().env().scriptURL.path().stringByDeletingLastPathComponent();
	(function() {
	 return load(TurboCore_FrameworkPath);
	 })();
};

function load(path) {
	var bundle = [NSBundle bundleWithPath:path];
	var frameworkName = path.lastPathComponent();

	if ([bundle isLoaded]) {
		log("😎 already loaded: " + frameworkName);
		return true;
	}
	else if ([bundle load]) {
		log("✅ success: " + frameworkName);
		return true;
	}

	log("❌ failed: " + frameworkName);
	runAlert();
	return false;
}

function runAlert() {
	var alert = [[NSAlert alloc] init];
	alert.alertStyle = NSAlertStyleCritical;
	alert.messageText = "Loading " + frameworkName + " Failed"
	alert.informativeText = ""
	alert.runModal();
}
