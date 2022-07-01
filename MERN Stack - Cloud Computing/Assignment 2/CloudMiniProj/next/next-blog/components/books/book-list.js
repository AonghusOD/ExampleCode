import BookItem from './book-item';
import classes from './book-list.module.css';

function BookList(props) {
  const { items } = props;

  return (
    <ul className={classes.list}>
      {items.map((book) => (
        <BookItem
          key={book.bookID}
          id={book.bookID}
          title={book.title}
          location={book.bookID}
          date={book.date}
          image={book.image}
          description={book.description}
        />
      ))}
    </ul>
  );
}

export default BookList;