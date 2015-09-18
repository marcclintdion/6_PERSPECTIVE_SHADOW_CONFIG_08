

    //===================================================================================================================
 
    glGenFramebuffers( 1, &gaussianBlurHorizontalPass_fboId);
    
    glGenTextures(1, &gaussianBlurHorizontal_TEXTURE);
    glBindTexture(GL_TEXTURE_2D, gaussianBlurHorizontal_TEXTURE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)viewWidth, (GLsizei)viewHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    glBindFramebuffer(GL_FRAMEBUFFER, gaussianBlurHorizontalPass_fboId);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gaussianBlurHorizontal_TEXTURE, 0);

    //--------------------------------------------------------------------------------------------------------------------
   

    glGenFramebuffers( 1, &gaussianBlurVerticalPass_fboId);
    
    glGenTextures(1, &gaussianBlurVertical_TEXTURE);
    glBindTexture(GL_TEXTURE_2D, gaussianBlurVertical_TEXTURE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)viewWidth, (GLsizei)viewHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    glBindFramebuffer(GL_FRAMEBUFFER, gaussianBlurVerticalPass_fboId);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gaussianBlurVertical_TEXTURE, 0); 
    //===================================================================================================================
    
    #include "frameBufferPlane_GaussianHorizontal_Init.cpp"                                                                   
    #include "frameBufferPlane_GaussianVertical_Init.cpp"  
