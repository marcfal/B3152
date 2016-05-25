function [] = RendreTerrainMatrix(terrain, texture, outfile, origin, target)

w = target - origin;
w = w/norm(w);
u = cross(w, [0,0,1]);
u = u/norm(u);
v = cross(u, w);
u = -u;
mat = zeros(4,4);
mat(:,1)= [u , 0];
mat(:,2)= [v , 0];
mat(:,3)= [w , 0];
mat(:,4)= [origin , 1];

mat = mat';
matrix = mat(:);

repertoire = '\\servif-home\fic_eleves\Espace Pedagogique\3IF\Modeles et Outils Mathematiques\Images fondements\image\Mitsuba';
cmd = strcat('"',repertoire,'\mitsuba" -Dhfile=',terrain,' -Dtfile=',texture,' -Dmatrix="',sprintf('%f ',matrix), '" -o ',outfile,' texture-matrix.xml');
disp(cmd);
system(cmd);

end

