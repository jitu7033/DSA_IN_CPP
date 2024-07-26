const express = require("express")

const app = express();

app.use("/",express.static("./frontend"))

app.listen(8000,()=>{
  console.log("server started")
})