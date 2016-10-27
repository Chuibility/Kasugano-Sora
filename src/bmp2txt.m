img=imread('original.bmp');
fid=fopen('original.txt','wt');
for i=1:256
    for j=1:256
        fprintf(fid,'%g %g %g\n',img(i,j,1),img(i,j,2),img(i,j,3));
    end
    fprintf(fid,'\n');
end
fclose(fid);