let express = require("express");
let router = express.Router();
let mongoose = require("mongoose");
mongoose.connect("localhost:27017/blog", {
  useNewUrlParser: true,
  useCreateIndex: true,
  useUnifiedTopology: true
});
let Schema = mongoose.Schema;


const bookSchema = new Schema(
  {
    bookID: String
  },
  { collection: "book" }
); 
const bookModel = mongoose.model("bookInfo", bookSchema);

const cartSchema = new Schema(
  {
    cartID: { type: String },
    title: { type: String },
    age: { type: Number }
  },
  { collection: "cart2" }
); 
const cartModel = mongoose.model("cartDetails", cartSchema);


let blogSchema = new Schema(
  {
    noEmployees: String
  },
  { collection: "employees" }
);
const EmployeeModel = mongoose.model("employeeInfo", blogSchema);



/* GET home page. */
router.get("/", function (req, res, next) {
  res.render("index", { title: "Express" })
});

router.post("/setNoEmployees", async function (req, res, next) {
  console.log(req.body)
  const data = await EmployeeModel.updateOne({}, req.body,{upsert: true});
  //var data = new EmployeeModel(req.body)
  //EmployeeModel.updateOne({}, data);
  //const data = new EmployeeModel({_id : ObjectId("6222018bb2e6654c58c8cb22")});
  //data.overwrite(req.body);
  //data.save()
  res.end()
});

router.post("/getNoEmployees", function (req, res, next) {
  //let theDoc = EmployeeModel.findOne({_id : ObjectId("6222018bb2e6654c58c8cb22")});
  EmployeeModel.find().then(function (docs) {
    let theDoc = docs[docs.length-1]
     console.log("/getNoEmployees: " + theDoc)
     // theDoc = JSON.stringify(theDoc)
    res.status(200).json(theDoc)
  });
});

router.post("/getBooks", function (req, res, next) {
  bookModel.find().then(function (docs) {
    //wrong thing
    let theDoc = docs[docs.length-1]
     //console.log("/getBooks: " + theDoc)
     docs = JSON.stringify(docs)
     console.log("/getBooks: docs" + docs)
    //theDoc = JSON.stringify(theDoc)
    //res.status(200).json(theDoc)
    res.status(200).json(docs)
  });
});


router.post("/setCart", function (req, res, next) {
  console.log(req.body)
  var data = new cartModel(req.body)
  data.save()
  res.end()
});


router.post("/getCart", function (req, res, next) {
  cartModel.find().then(function (docs) {
    //wrong thing
    let theDoc = docs[docs.length-1]
     //console.log("/getBooks: " + theDoc)
     docs = JSON.stringify(docs)
     console.log("/getCart: docs" + docs)
    //theDoc = JSON.stringify(theDoc)
    //res.status(200).json(theDoc)
    res.status(200).json(docs)
  });
});



router.delete("/deleteCart", function (req, res, next) {
  //cartModel.find().then(function (docs) {
    cartModel.findOneAndRemove().then(function(docs) {
    console.log("Data deleted"+ docs); // Success
      //wrong thing
    let theDoc = docs[docs.length-1]
     //console.log("/getBooks: " + theDoc)
     docs = JSON.stringify(docs)
     console.log("/deleteCart: docs" + docs)
    //theDoc = JSON.stringify(theDoc)
    //res.status(200).json(theDoc)
    res.status(200).json(docs)
  });
});

module.exports = router;
