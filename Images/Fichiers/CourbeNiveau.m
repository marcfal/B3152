function [ texture ] = CourbeNiveau(terrain,inter, seuil)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
L = size(terrain,1);
C = size(terrain,2);
texture = zeros(L,C,3);
texture = texture + 65536;
for i=1:L,
    for j=1:C,
        if(mod(terrain(i,j), inter) < seuil || mod(terrain(i,j), inter) > (inter-seuil))
            texture(i,j,:) = 0;
        end
    end
end

end

