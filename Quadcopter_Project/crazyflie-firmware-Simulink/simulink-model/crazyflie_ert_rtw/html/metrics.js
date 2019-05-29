function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/crazyflie_ert_rtw/crazyflie.c",
	size: 51};
	 this.metricsArray.var["rtU"] = {file: "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/crazyflie_ert_rtw/crazyflie.c",
	size: 80};
	 this.metricsArray.var["rtY"] = {file: "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/crazyflie_ert_rtw/crazyflie.c",
	size: 56};
	 this.metricsArray.fcn["atan2"] = {file: "/usr/local/MATLAB/R2019a/sys/lcc/include/math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["cos"] = {file: "/usr/local/MATLAB/R2019a/sys/lcc/include/math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["crazyflie.c:norm"] = {file: "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/crazyflie_ert_rtw/crazyflie.c",
	stack: 32,
	stackTotal: 32};
	 this.metricsArray.fcn["crazyflie_initialize"] = {file: "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/crazyflie_ert_rtw/crazyflie.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["crazyflie_step"] = {file: "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/crazyflie_ert_rtw/crazyflie.c",
	stack: 700,
	stackTotal: 700};
	 this.metricsArray.fcn["crazyflie_terminate"] = {file: "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/crazyflie_ert_rtw/crazyflie.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["fabs"] = {file: "/usr/local/MATLAB/R2019a/sys/lcc/include/math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["fmax"] = {file: "/home/lucas/Desktop/11_Github/Model-based-development-of-cyberphysical-systems (SSY191)/Bitcraze Shared Folder/quadrotor-lab-spring-2019-group_19/crazyflie-firmware/simulink-model/crazyflie_ert_rtw/crazyflie.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["memcpy"] = {file: "/usr/local/MATLAB/R2019a/sys/lcc/include/string.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sin"] = {file: "/usr/local/MATLAB/R2019a/sys/lcc/include/math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sqrt"] = {file: "/usr/local/MATLAB/R2019a/sys/lcc/include/math.h",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="crazyflie_metrics.html">Global Memory: 187(bytes) Maximum Stack: 700(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
