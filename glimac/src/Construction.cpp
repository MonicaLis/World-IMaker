#include <glimac/Construction.hpp>
#include <iostream>


Construction::Construction()
{
    //create 3 layers of cubes
    for(unsigned int i=0; i<m_length; i++)
    {
        for(unsigned int j=0; j<m_width; j++)
        {
            for (unsigned int layer=0; layer<m_height; layer++)
            {
                m_all_cubes(i,j).push_back( Cube(Param_Pos_Color(glm::vec3(i,layer,j),glm::vec3(0.2,1,0)), 36) );
            }
        }
    } 
}


const glm::vec2 Construction::find_column(Cursor &cursor)
{
    bool column_found = false;
    unsigned int i = 0;
    unsigned int j = 0;
    while ( i<m_length && j<m_width && !column_found)
    {
        if( cursor.get_position().x == i && cursor.get_position().z == j )
        {
            column_found = true;
        }
        i++;
        j++;
    }
    
    if (!column_found) return glm::vec2(-1, -1);
    else return glm::vec2(i, j);
}


bool Construction::is_there_a_cube(Cursor &cursor)
{
    bool res = false;
    unsigned int x = cursor.get_position().x;
    unsigned int y = cursor.get_position().y;
    unsigned int z = cursor.get_position().z;
    //make sure the cursor is in the world's limits
    if (x <= m_length && z <= m_width)
    {
        unsigned int i = 0;
        //check if the cursor's position is the same as one of the column's cube
        while (i<m_height && !res)
        {
            if(m_all_cubes(x, z).at(i).get_position().y == y) res = true; 
            else i++;
        }
    }
    
    return res;
}
