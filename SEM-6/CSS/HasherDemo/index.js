const express = require("express");
const app = express();
const connectDB = require("./Database/db.js");
const userSchema = require("./Database/schema.js");
const Hasher = require("@deepsalunkhee/hasher");

connectDB();

app.use(express.json());

app.get("/", (req, res) => {
  res.send("You have reached the Demo server");
});

app.post("/create", async (req, res) => {
  console.log(req.body);
  const { email, password } = req.body;
  const hashedPassword = Hasher.hash(password);
  const newUser = new userSchema({
    email: email,
    passwordHash: hashedPassword,
  });

  await newUser.save();
  res.send("User Created");
});

app.get("/verify",async(req,res)=>{
    const {email,password}=req.body;
    console.log(req.body);
    const user=await userSchema.findOne({email:email});
    console.log(user);
    if(user){
        
        if(Hasher.check(user.passwordHash,password)){
            res.send("User has been verified Successfully");
        }else{
            res.send("Imposter user!");
        }
    }else{
        res.send("User not found");
    }
})

app.listen(3000, () => {
  console.log("Server is running on port 3000");
});
