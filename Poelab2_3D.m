%cd ..
%cd 'Year 2'
%cd 'PoE/poe-lab-2'
load positions.txt

hold on
plot3(positions(:,1),positions(:,2),positions(:,3),'.')

xlabel('x (sideways) distance in cm')
ylabel('y (forward) distance in cm')
zlabel('z (up) distance in cm')