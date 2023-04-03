FROM ubuntu
ADD ./lab2.sh /home/german/conteiner/lab2.sh
RUN chmod +x /home/german/conteiner/lab2.sh
RUN apt-get update && apt-get install -y isomd5sum
CMD ["/home/german/conteiner/lab2.sh"]



