function [ image ] = Ombrage( terrain, inter, rampfile, normales, points, lumiere)

%points = points 3D
%lumi�re = vecteur direction de la lumi�re
%multiplier chaque couleur par un coeff �gal � I*cos(angle avec la
%normale.I est arbitraire...
texture = CourbeNiveauRamp( terrain, inter, 1, rampfile);



end

