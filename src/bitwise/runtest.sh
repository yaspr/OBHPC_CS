bname="bitwise_util"

echo "Compiling ...\n"
make >> /dev/null 2>> /dev/null
echo " "

echo -e "Running test for O0 - no optimization ...\n"
./$bname.0
echo  " "

echo -e "Running test for O1 optimization level ...\n"
./$bname.1
echo  " "

echo -e "Running test for O2 optimization level ...\n"
./$bname.2
echo  " "

echo -e "Running test for O3 optimization level ...\n"
./$bname.3
echo  " "

echo -e "Running test for Os optimization level ...\n"
./$bname.small
echo  " "

echo -e "Running test for Ofast optimization level ...\n"
./$bname.fast
echo  " "
