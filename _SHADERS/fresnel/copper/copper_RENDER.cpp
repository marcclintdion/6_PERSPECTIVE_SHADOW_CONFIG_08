    glUseProgram(copper_SHADER);     
    //------------------------------------------------------------------------------------------------------
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                  
    glEnableVertexAttribArray(1);    
    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);                                                                                                                                               
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_copper, copper_LIGHT_POSITION_01[0], copper_LIGHT_POSITION_01[1], copper_LIGHT_POSITION_01[2], copper_LIGHT_POSITION_01[3]);        
    glUniform4f(UNIFORM_LIGHT_POSITION_02_copper, copper_LIGHT_POSITION_02[0], copper_LIGHT_POSITION_02[1], copper_LIGHT_POSITION_02[2], copper_LIGHT_POSITION_02[3]);       
    glUniform1f(UNIFORM_SHININESS_01_copper, copper_SHININESS_01);                                                                                                                  
    glUniform1f(UNIFORM_SHININESS_02_copper, copper_SHININESS_02);     
    glUniform1f(UNIFORM_ATTENUATION_01_copper, copper_ATTENUATION_01);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_02_copper, copper_ATTENUATION_02);     
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_copper,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_MODELVIEW_copper,       1,0,  modelView);    
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_copper,    1,0,  lightMatrix1);                                                                                                    
    //------------------------------------------------------------------------------------------------------   
    glUniform1i (UNIFORM_FRESNELMAP_copper, 2);       
    glUniform1i (UNIFORM_TEXTURE_DOT3_copper, 1);    
    glUniform1i (UNIFORM_TEXTURE_copper, 0 );  

    //---       
    glActiveTexture ( GL_TEXTURE2 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, copper_FRESNELMAP);
