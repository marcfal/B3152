function [ mat3D ] = ConstruitPoints3D (terrain, xmin, xmax, ymin, ymax )

mat3D = zeros(xmax+1-xmin,ymax+1-ymin,3);
for i=1:size(mat3D,1),
    for j=1:size(mat3D,2),
        mat3D(i,j,1) = i;
        mat3D(i,j,2) = j;
        mat3D(i,j,3) = terrain(i-1+xmin,j-1+ymin);
    end
end


end

