# nslookup command-line utility for Android

Based on awesome gist by [Jiri Hnidek](https://gist.github.com/jirihnidek/bf7a2363e480491da72301b228b35d5d).

## Prerequsites

Create a standalone Android toolchain using the SDK script:

```
Android$ ./Sdk/ndk-bundle/build/tools/make_standalone_toolchain.py --arch arm --api 21 --install-dir ~/forge/android-toolchain
```

## Building

```
mkdir build
cd build
LDFLAGS=-static CFLAGS="-fPIC -O3 -fomit-frame-pointer -ffast-math -march=armv7-a" CC=$(pwd)/../../android-toolchain/bin/arm-linux-androideabi-gcc cmake ..
make
```

## Testing

```
adb push ./nslookup /system/bin/
adb shell
nslookup google.com
```

Output:

```
Non-authoritative answer:
Name:	google.com
Address: 172.217.168.78
Name:	google.com
Address: 2a00:1450:400a:800::200e
```
