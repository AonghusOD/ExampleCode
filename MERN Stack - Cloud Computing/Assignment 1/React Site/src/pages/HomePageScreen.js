import classes from "./HomePageScreen.module.css";
import Card from '../components/Card';
import Back_drop from "../components/Back_drop";
import Modal from "../components/Modal";
import { useState, useRef, useContext } from "react";
import ReservedBooks from './ReservedBooks'

function HomePageScreen(props) {
  const [modalIsOpen, setModalIsOpen] = useState(false);
  const place = useRef("default");

  const books= [{id:"BillyConnolly",img:"BillyConnolly.jpg", desc:"Connolly's raucous run through his life is as furious, funny and foul-mouthed as you'd expect"},
  {id:"Snow",img:"Snow.jpg", desc:"A chilling, 1950s-set, festive mystery from the Man Booker Prize winne"},
  {id:"BobMortimer",img:"BobMortimer.jpg", desc:"Bob Mortimer’s life was trundling along happily until suddenly in 2015 he was diagnosed with a heart condition that required immediate surgery and forced him to cancel an upcoming tour. The episode unnerved him, but forced him to reflect on his life so far. This is the framework for his hilarious and moving memoir, And Away…"}];
  

  const Handler= (event) => {
    var text = event.target.closest(".row").querySelector("h1").textContent;
    place.current = text;
    setModalIsOpen(true);
  }

  const ReservedBookHandler= (event) => {
    <ReservedBooks>
      <div>
        {books.id}
        {books.img}
      </div>
    </ReservedBooks>
  }
  function closeModalHandler() {
    setModalIsOpen(false);
  }

  function textChanged() {
    props.globalObject.setText(document.getElementById('textarea1').value);
    props.globalObject.refreshApp();
  }
  console.log(props.globalObject.getText());

  return (
    <div className={classes.row}>
      <div align="center" className='row'>
        <Card>
          <h1 id="GuinessWorldRecords"> Guiness World Records</h1>
          <img className={classes.img} src="GuinessWorldRecords.jpg"></img>
          
          <div className={classes.actions}>
            <button className='btn' onClick={Handler}>
              Description
            </button>
            <button className='btn' onClick={ReservedBookHandler}>
              Reserve
            </button>
          </div>
        </Card>
      </div>
      <div align="center" className='row'>
        <Card>
          <h1 id="BillyConnolly"> Billy Connolly</h1>
          <img className={classes.img} src="BillyConnolly.jpg"></img>
          <div className={classes.actions}>
            <button className='btn' onClick={Handler}>
            Description
            </button>
            <button className='btn' onClick={ReservedBookHandler}>
            Reserve
            </button>
          </div>
        </Card>
      </div>
      <div align="center" className='row'>
        <Card>
          <h1 id="BobMortimer"> Bob Mortimer</h1>
          <img className={classes.img} src="BobMortimer.jpg"></img>
          <div className={classes.actions}>
            <button className='btn' onClick={Handler}>
            Description
            </button>
            <button className='btn' onClick={ReservedBookHandler}>
            Reserve
            </button>
          </div>
        </Card>
      </div>
      <div align="center" className='row'>
        <Card>
          <h1 id="Snow"> Snow</h1>
          <img className={classes.img} src="Snow.jpg"></img>
          <div className={classes.actions}>
            <button className='btn' onClick={Handler}>
            Description
            </button>
            <button className='btn' onClick={ReservedBookHandler}>
            Reserve 
            </button>
          </div>
        </Card>
      </div>
      {modalIsOpen ? <Modal onCancel={closeModalHandler} Heading={place.current} /> : null}
      {modalIsOpen && <Back_drop onClick={closeModalHandler} />}
    </div>
    

  );
}

export default HomePageScreen;
