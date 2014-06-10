setenv('PKG_CONFIG_PATH', [getenv('PKG_CONFIG_PATH') ':/opt/local/lib/pkgconfig']);
setenv('PATH', [getenv('PATH') ':/opt/local/bin']);
mexopencv.make('clean', true);
mex -setup
mxopencv.make
