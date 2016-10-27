fid=fopen('ciphertext.txt','r');
for i=1:256
    for j=1:256
        img(i,j,1)=fscanf(fid,'%d',1);
        img(i,j,2)=fscanf(fid,'%d',1);
        img(i,j,3)=fscanf(fid,'%d',1);
    end
end
fclose(fid);
img=uint8(img);
imwrite(img,'ciphertext.bmp');