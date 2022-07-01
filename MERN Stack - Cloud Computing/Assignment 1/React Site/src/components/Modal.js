import React from 'react'
import classes from "./Modal.module.css";



const Modal = ({ props, onCancel }) => {

  const [index, setIndex] = React.useState(0);

  const colors = ["#0088FE", "#00C49F", "#FFBB28"];
  const books= [{id:"BillyConnolly",img:"BillyConnolly.jpg", desc:"Connolly's raucous run through his life is as furious, funny and foul-mouthed as you'd expect"},
  {id:"Snow",img:"Snow.jpg", desc:"A chilling, 1950s-set, festive mystery from the Man Booker Prize winne"},
  {id:"BobMortimer",img:"BobMortimer.jpg", desc:"Bob Mortimer’s life was trundling along happily until suddenly in 2015 he was diagnosed with a heart condition that required immediate surgery and forced him to cancel an upcoming tour. The episode unnerved him, but forced him to reflect on his life so far. This is the framework for his hilarious and moving memoir, And Away…"}];
  

  return (
    <div>
      <div className='modal'>
        <h1 id='heading'> {props} </h1>
        <div className='sildeshow'>
          <div
            className="slideshowSlider"
            style={{ transform: `translate3d(${-index * 100}%, 0, 0)` }}>
            {books.map((src, index) => (
              console.log(src),
                  <div className={classes.description}>{src.desc}</div>
            ))}
          </div>
        </div>
        <div className='slideshowDots'>
          {colors.map((_, idx) => (
            <div
              key={idx}
              className={`slideshowDot${index === idx ? " active" : ""}`}
              onClick={() => {
                setIndex(idx);
              }}
            ></div>
          ))}
        </div>

        <button className='btn' type="button" onClick={(event) => onCancel()}>Close</button>
      </div>
    </div>
  );
};
export default Modal;