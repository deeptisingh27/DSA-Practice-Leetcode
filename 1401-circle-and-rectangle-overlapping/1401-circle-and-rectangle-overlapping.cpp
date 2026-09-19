class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        // Find the closest x-coordinate on the rectangle to xCenter
        int closestX = clamp(xCenter, x1, x2);
        
        // Find the closest y-coordinate on the rectangle to yCenter
        int closestY = clamp(yCenter, y1, y2);
        
        // Distance components between the center and the closest point
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;
        
        // Check if the squared distance is within the squared radius
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};