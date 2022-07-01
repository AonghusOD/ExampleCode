import CartItem from './cart-item';
import classes from './cart-list.module.css';

function CartList(props) {
  const { items } = props;

  return (
    <ul className={classes.list}>
      {items.map((cart) => (
        <CartItem
          key={cart.cartID}
          id={cart.cartID}
          title={cart.title}
        />
      ))}
    </ul>
  );
}

export default CartList;