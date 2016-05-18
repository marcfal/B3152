function [ image ] = Ombrage( terrain, inter, rampfile, normales, points, lumiere)

%points = points 3D
%lumière = vecteur direction de la lumière
%multiplier chaque couleur par un coeff égal à I*cos(angle avec la
%normale.I est arbitraire...
texture = CourbeNiveauRamp( terrain, inter, 1, rampfile);



end

