import { useContext } from "react";


import NewBook from "../components/NewBook";


function ReservedBooks() {
  const books= [{id:"BillyConnolly",img:"BillyConnolly.jpg", desc:"Connolly's raucous run through his life is as furious, funny and foul-mouthed as you'd expect"},
  {id:"Snow",img:"Snow.jpg", desc:"A chilling, 1950s-set, festive mystery from the Man Booker Prize winne"},
  {id:"BobMortimer",img:"BobMortimer.jpg", desc:"Bob Mortimer’s life was trundling along happily until suddenly in 2015 he was diagnosed with a heart condition that required immediate surgery and forced him to cancel an upcoming tour. The episode unnerved him, but forced him to reflect on his life so far. This is the framework for his hilarious and moving memoir, And Away…"}];
  



  return (
    <section>
      <h1>Reserved Books</h1>
      <div> {books.id}</div>
    </section>
  );
}

export default ReservedBooks; 