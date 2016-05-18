function [ nouv ] = Subdivise(terrain, alpha)
L = size(terrain,1)*2-1;
C = size(terrain,2)*2-1;
nouv = zeros(L , C) ;

%copie des points
for i=1:size(terrain,1),
    for j=1:size(terrain,2),
        nouv(i*2-1,j*2-1) = terrain(i,j);
    end
end

%diamond
for i=2:2:L-1,
    for j=2:2:C-1,
        moy = (nouv(i-1,j-1)+nouv(i+1,j-1)+nouv(i-1,j+1)+nouv(i+1,j+1))/4;
        moy = moy + alpha*rand();
        nouv(i,j) = moy;
    end
end

%square
%bords
for i=2:2:C-1,
    nouv(1,i)= (nouv(1,i-1)+nouv(1,i+1))/2 + alpha*rand();
    nouv(L,i)= (nouv(L,i-1)+nouv(L,i+1))/2 + alpha*rand();
end

for i=2:2:L-1,
    nouv(i,1)= (nouv(i-1,1)+nouv(i+1,1))/2 + alpha*rand();
    nouv(i,C)= (nouv(i-1,C)+nouv(i+1,C))/2 + alpha*rand();
end

%centre
for i=2:2:L-1,
    for j=3:2:C-1,
        moy = (nouv(i,j-1)+nouv(i,j+1)+nouv(i-1,j)+nouv(i+1,j))/4;
        moy = moy + alpha*rand();
        nouv(i,j) = moy;
    end
end

for i=3:2:L-1,
    for j=2:2:C-1,
        moy = (nouv(i,j-1)+nouv(i,j+1)+nouv(i-1,j)+nouv(i+1,j))/4;
        moy = moy + alpha*rand();
        nouv(i,j) = moy;
    end
end

end

