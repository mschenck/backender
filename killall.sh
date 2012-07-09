echo "Current processes"
ps ax | grep backend

killall -9 backend

echo "Remaining processes"
ps ax | grep backend
