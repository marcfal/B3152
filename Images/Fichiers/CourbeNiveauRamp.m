function [ texture ] = CourbeNiveauRamp( terrain, inter, seuil, rampfile )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
L = size(terrain,1);
C = size(terrain,2);
texture = zeros(L,C,3);
texture = uint8(texture);% + 65536;
color = imread(rampfile);


maxTer = max(max(terrain));
for i=1:L,
    for j=1:C,
        texture(i,j,:) = color(1,floor((terrain(i,j)*489)/maxTer)+1,:);
        if(mod(terrain(i,j), inter) < seuil || mod(terrain(i,j), inter) > (inter-seuil))
            texture(i,j,:) = 0;
        end
    end
end


end


