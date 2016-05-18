function [ nouv ] = GenererTerrain(initterrain, nsubdiv, alpha, lambda)
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
nouv = initterrain;
for i=1:nsubdiv,
    nouv=Subdivise(nouv, alpha);
    alpha = alpha * lambda;
end


end

