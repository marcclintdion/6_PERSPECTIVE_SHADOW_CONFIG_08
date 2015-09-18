    leaves_A_SHADER = glCreateProgram();                                                                                     
        //----------------------------------------------------                                                                  
    const GLchar *vertexSource_leaves_A =                                                                                    

    " #define highp                                                                                                                           \n" 
    
    //--------------------------------------------     
    "    attribute       vec4   position;                                                                                                        \n" 
    "    attribute       vec2   textureCoords;                                                                                                   \n" 
    //--------------------------------------------   
    "    uniform         mat4   modelView;                                                                                                       \n" 
    "    uniform         mat4   projection;                                                                                                      \n" 
    "    uniform         mat4   view;                                                                                                       \n"         
    "    uniform         mat4   modelWorld;                                                                                                       \n"         
    "    uniform         mat4   view_Rotate;                                                                                                       \n"            
    "    uniform         mat4   moveSetMatrix;                                                                                                       \n"            
    //--------------------------------------------                                        
    "    uniform  highp  vec4   light_POSITION_01;                                                                                              \n" 
    "    uniform  highp  vec4   light_POSITION_02;                                                                                              \n" 
    "    uniform         mat4   light_TextureMatrix;                                                                                               \n"        
    //--------------------------------------------
    "    uniform         mat4   lightMatrix;                                                                                                    \n" 
    "    varying  highp  vec4   shadowTexcoord;                                                                                                 \n"       
    //--------------------------------------------
    "    varying  highp  vec4   lightPosition_PASS_01;                                                                                             \n" 
    "    varying  highp  vec4   lightPosition_PASS_02;                                                                                             \n"     
    "    varying  highp  vec2   varTexcoord;                                                                                                    \n" 
    //--------------------------------------------

    //==================================================================================================================================
    
    " void main()                                                                                                                               \n" 
    " {                                                                                                                                         \n" 
          //-------------------------------------------------------------------------------    
    "     shadowTexcoord          =  light_TextureMatrix * moveSetMatrix * modelWorld * position;                                         \n" 
          //-------------------------------------------------------------------------------
    "     varTexcoord             =  textureCoords;                                                                                       \n" 
    "     lightPosition_PASS_01   =  normalize(lightMatrix * light_POSITION_01);                                                          \n" 
    "     lightPosition_PASS_02   =  normalize(lightMatrix * light_POSITION_02);                                                          \n"     
    
    "     gl_Position             =  projection* view * view_Rotate  * moveSetMatrix* modelWorld * position;                                                                                \n" 
    
    " } \n";   
    
    //===================================================================================================================================                 

    const GLchar *fragmentSource_leaves_A =                                                                                  

    "#ifdef GL_ES                                                                                                                                \n" 
    "#else                                                                                                                                       \n" 
    "#define highp                                                                                                                               \n" 
    "#endif                                                                                                                                      \n" 
    
    //--------------------------------------------
    "    uniform  sampler2D     ShadowTexture;                                                                                                      \n"   
    "    varying  highp  vec4   shadowTexcoord;                                                                                                     \n"       
    //--------------------------------------------
    "    uniform  sampler2D     NormalMap;                                                                                                        \n" 
    "             highp  vec3   NormalTex;                                                                                                        \n" 
    "             highp  float  NdotL1;                                                                                                           \n" 
    "             highp  float  NdotL2;                                                                                                           \n"     
    //--------------------------------------------
    "    uniform  sampler2D     Texture1;                                                                                                         \n"     
    "    varying  highp  vec2   varTexcoord;                                                                                                      \n" 
    //--------------------------------------------
    "    uniform  highp  float  shininess;                                                                                                        \n"    
    "    uniform  highp  float  ambient;                                                                                                          \n" 
    //--------------------------------------------                                                                      
    "    varying  highp  vec4   lightPosition_PASS_01;                                                                                           \n" 
    "    varying  highp  vec4   lightPosition_PASS_02;                                                                                           \n"  
    //--------------------------------------------                                                                       
    "             highp  vec4   tempColor;                                                                                                        \n" 
    "             highp  vec4   specular;                                                                                                         \n"     
    //-------------------------------------------- 
    "             highp  float  comp;                                                                                                             \n" 
    "             highp  float  depth_PowerVR;                                                                                                    \n" 
    "             highp  float  shadowVal;                                                                                                        \n" 
    "             highp  float  bias;                                                                                                             \n"         
                                                            
    //=======================================================================================================================                      
   
    "void main()                                                                                                                                 \n" 
    "{                                                                                                                                           \n" 
    "    NormalTex                =  texture2D(NormalMap,  varTexcoord.xy).xyz;                                                                    \n" 
    "    NormalTex                =  normalize((NormalTex  - 0.5));                                                                                \n" 
    "    NdotL1                   =  max(dot(NormalTex, lightPosition_PASS_01.xyz), 0.5);                                                          \n" 
    "    NdotL2                   =  max(dot(NormalTex, lightPosition_PASS_02.xyz), 0.5);                                                          \n"           
         //----------------------------------------------------------------------------                                                   
         //"bias                  =  shininess * tan(acos(NdotL1));                                                                             \n" 
         //"bias                  =  clamp(bias, 0.0, 0.1);                                                                                     \n"               
    "    bias                     =  shininess;                                                                                                   \n"         
    "    comp                     = (shadowTexcoord.z / shadowTexcoord.w) - bias;                                                                 \n" 
    "    depth_PowerVR            =  texture2DProj(ShadowTexture, shadowTexcoord).r;                                                              \n" 
    "    shadowVal                =  comp <= depth_PowerVR ? 1.0 : 0.4;                                                                           \n" 
         //---------------------------------------------------------------------------------------------------------------   
    "    gl_FragColor             =  (texture2D(Texture1, varTexcoord.xy) * NdotL1 * NdotL2  + highp vec4(0.2, 0.2, 0.2, 0.2));                   \n" 
    "    gl_FragColor.w           =   shadowVal;                                                                                                  \n"     
    
    "}\n";

    
        
        
        
    //=======================================================================================================================                   

        leaves_A_SHADER_VERTEX = glCreateShader( GL_VERTEX_SHADER);                                                          
        glShaderSource( leaves_A_SHADER_VERTEX, 1, &vertexSource_leaves_A, NULL );                                        
        glCompileShader( leaves_A_SHADER_VERTEX);                                              //glShaderBinary                              
        //----------------------------------------------------                                                                  
        leaves_A_SHADER_FRAGMENT = glCreateShader( GL_FRAGMENT_SHADER);                                                      
        glShaderSource( leaves_A_SHADER_FRAGMENT, 1, &fragmentSource_leaves_A, NULL );                                    
        glCompileShader(leaves_A_SHADER_FRAGMENT);                                              //glShaderBinary                                                                             
        //--------------------------------------------------------------------------------------------------                    
        glAttachShader( leaves_A_SHADER, leaves_A_SHADER_VERTEX );                                                        
        glAttachShader( leaves_A_SHADER, leaves_A_SHADER_FRAGMENT );                                                      
        //--------------------------------------------------------------------------------------------------                    
        glBindAttribLocation(leaves_A_SHADER,   0, "position");                                                              
        glBindAttribLocation(leaves_A_SHADER,   1, "normal");                                                            
        glBindAttribLocation(leaves_A_SHADER,   2, "textureCoords");                                                             
        //--------------------------------------------------------------------------------------------------                    
        glDeleteShader( leaves_A_SHADER_VERTEX);                                                                             
        glDeleteShader( leaves_A_SHADER_FRAGMENT);                                                                           
        glLinkProgram(leaves_A_SHADER);                                                                                      
        //--------------------------------------------------------------------------------------------------                    
        UNIFORM_LIGHT_MATRIX_leaves_A                       = glGetUniformLocation(leaves_A_SHADER, "lightMatrix");                
        //-----------------------------        
        UNIFORM_MODELVIEW_leaves_A                          = glGetUniformLocation(leaves_A_SHADER, "modelView");                  
        UNIFORM_PROJECTION_leaves_A                         = glGetUniformLocation(leaves_A_SHADER, "projection");  
        UNIFORM_VIEW_leaves_A                               = glGetUniformLocation(leaves_A_SHADER, "view");                  
        UNIFORM_MODELWORLD_leaves_A                         = glGetUniformLocation(leaves_A_SHADER, "modelWorld");          
        UNIFORM_VIEW_ROTATE_leaves_A                        = glGetUniformLocation(leaves_A_SHADER, "view_Rotate");             
        UNIFORM_MOVESET_MATRIX_leaves_A                     = glGetUniformLocation(leaves_A_SHADER, "moveSetMatrix");          
        //-------------------------------
        UNIFORM_SHADOW_LIGHT_TEXTURE_MATRIX_leaves_A        = glGetUniformLocation(leaves_A_SHADER, "light_TextureMatrix");                                                  
        //-------------------------------      

        UNIFORM_LIGHT_POSITION_01_leaves_A                  = glGetUniformLocation(leaves_A_SHADER, "light_POSITION_01");    
        UNIFORM_LIGHT_POSITION_02_leaves_A                  = glGetUniformLocation(leaves_A_SHADER, "light_POSITION_02");                  
        UNIFORM_shininess_leaves_A                          = glGetUniformLocation(leaves_A_SHADER, "shininess");  
       
        UNIFORM_ambient_leaves_A                            = glGetUniformLocation(leaves_A_SHADER, "ambient");  
          
        UNIFORM_ShadowTexture_leaves_A                      = glGetUniformLocation(leaves_A_SHADER, "ShadowTexture");           
        UNIFORM_TEXTURE_DOT3_leaves_A                       = glGetUniformLocation(leaves_A_SHADER, "NormalMap");                  
        UNIFORM_TEXTURE_leaves_A                            = glGetUniformLocation(leaves_A_SHADER, "Texture1");  
