#!/bin/bash
echo "Egle German robertovich"
echo "var 3"
echo "program sozdaet obraz CD diska"
#zapros puti
read -p "vvedi put k obrazy - " image_path
#proverka kontrol summ
if ! checkisomd5 = 0 $image_path; then
#esli sum net
implantisomd5 $image_path

else
#esli est to vivodim
checkisomd5 --verbose $image_path
fi
