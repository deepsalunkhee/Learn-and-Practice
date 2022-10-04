const express=require('express')
const app=express()
const mongooes=require('mongoose')
const dotenv=require('dotenv')
const routesUrls=require('./routes/routes')
const cors=require('cors')

dotenv.config()
mongooes.connect(process.env.Database,()=>console.log("Database connected"))
app.use(express.json())
app.use(cors())

app.use('/app',routesUrls)

app.listen(4000,() => console.log("server is up running"))





// 1005025Dd11