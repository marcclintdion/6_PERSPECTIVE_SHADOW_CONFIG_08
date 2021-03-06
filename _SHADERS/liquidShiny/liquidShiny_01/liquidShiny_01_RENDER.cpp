    glUseProgram(liquidShiny_01_SHADER);      
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                  
    glEnableVertexAttribArray(1);    
    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);                                                                                                                                               
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_liquidShiny_01, liquidShiny_01_LIGHT_POSITION_01[0], 
                                                          liquidShiny_01_LIGHT_POSITION_01[1], 
                                                          liquidShiny_01_LIGHT_POSITION_01[2], 
                                                          liquidShiny_01_LIGHT_POSITION_01[3]);        
    
    glUniform4f(UNIFORM_LIGHT_POSITION_02_liquidShiny_01, liquidShiny_01_LIGHT_POSITION_02[0], 
                                                          liquidShiny_01_LIGHT_POSITION_02[1], 
                                                          liquidShiny_01_LIGHT_POSITION_02[2], 
                                                          liquidShiny_01_LIGHT_POSITION_02[3]);     
   
    glUniform1f(UNIFORM_SHININESS_liquidShiny_01, liquidShiny_01_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_liquidShiny_01, liquidShiny_01_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_liquidShiny_01,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_liquidShiny_01,    1,0,  lightMatrix1);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_DOT3_liquidShiny_01, 1);      
    glUniform1i (UNIFORM_TEXTURE_liquidShiny_01, 0 );   
