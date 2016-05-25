function [  ] = Ombrage( terrain, inter, rampfile, lumiere)

%points = points 3D
%lumière = vecteur direction de la lumière
%multiplier chaque couleur par un coeff égal à I*cos(angle avec la
%normale.)
%I est arbitraire...
l = size(terrain,1);
h = size(terrain,2);
intensite = 1;
texture = CourbeNiveauRamp( terrain, inter, 1, rampfile);
points3d = ConstruitPoints3D(terrain, 1, l, 1, h);
normales = ConstruitNormales(points3d);
for i=1:l,
    for j=1:h,
        vect = zeros(3,1);
        vect(1) = normales(i,j,1);
        vect(2)= normales(i,j,2);
        vect(3)= normales(i,j,3);
        texture(i,j,:)=texture(i,j, :)*intensite*(dot(lumiere, vect)/(norm(lumiere)*norm(vect)));
    end
end

writepng(terrain, 'tempterr.png');
imwrite(texture, 'temptext.png');
RenderTerrain('tempterr.png', 'temptext.png', 'renduombr.png', [1000, -1500, 800], [0, 0, 0]);

%[0, -700, 200], [0, 0, 0]
end

