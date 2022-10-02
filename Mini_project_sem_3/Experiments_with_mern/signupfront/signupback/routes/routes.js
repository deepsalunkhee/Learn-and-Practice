const { response } = require('express')
const express =require('express')
const router =express.Router()
const signUpTemplateCopy=require('../models/signUpmodels')


router.post('/signup',(request,response) =>{ 
   const signedUpUser = new signUpTemplateCopy({

    fullName:request.body.fullName,
    username:request.body.username,
    email:request.body.email,
    password:request.body.password,

   })

   signedUpUser.save()
   .then(data =>{
    response.jason(data)
   })
   .catch(error =>
    {
        response.json(error)
    })
})

module.exports=router