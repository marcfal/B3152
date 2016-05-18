function [  ] = writepng( array,  filename )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
nouv16 = uint16(array);
nouv16 = nouv16*(65536/512);
imwrite(nouv16, filename);

end

