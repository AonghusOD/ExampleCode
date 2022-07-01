import { React, useState, useEffect } from "react";
import CartList from "./cart/cart-list";

const Cart = () => {
  const [data, setData] = useState(null)
  const [isLoading, setLoading] = useState(false)
  
  useEffect(() => {
    setLoading(true)
    fetch('api/getCart')
      .then((res) => res.json())
      .then((data) => {
        const air = [];

        for (const key in data) {
          const meetup = {
            id: key,
            ...data[key]
            
          };
          console.log(meetup)
          air.push(meetup);
        }
        console.log(data)
        setData(data)
        //console.log(air)
        
        setLoading(false)
      })
  }, [])

  if (isLoading) return <p>Loading...</p>
  if (!data) return <p>No profile data</p>

  return (
    <section>
      <div>
        <div>
        <CartList items ={data} />
        </div>
      </div>
    </section>
  );
}

export default Cart;