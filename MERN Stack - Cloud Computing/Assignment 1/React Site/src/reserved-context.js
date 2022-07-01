// import { createContext, useState } from 'react';

// const ReservedContext = createContext({
//     Reserved: [],
//   totalReserved: 0,
//   addReserved: (ReservedBook) => {},
//   removeReserved: (bookId) => {},
//   itemIsReserved: (bookId) => {}
// });

// export function ReservedContextProvider(props) {
//   const [userReserved, setUserReserved] = useState([]);

//   function addReservedHandler(reservedBook) {
//     setUserReserved((prevUserReserved) => {
//       return prevUserReserved.concat(reservedBook);
//     });
//   }

//   function removeReservedHandler(bookId) {
//     setUserReserved(prevUserReserved => {
//       return prevUserReserved.filter(book => book.id !== bookId);
//     });
//   }

//   function bookIsReservedHandler(bookId) {
//     return userReserved.some(book => book.id === bookId);
//   }

//   const context = {
//     Reserved : userReserved,
//     totalReserved: userReserved.length,
//     addReserved: addReservedeHandler,
//     removeReserved: removeReservedeHandler,
//     itemIsReserved: bookIsReservedHandler
//   };

//   return (
//     <ReservedContext.Provider value={context}>
//       {props.children}
//     </ReservedContext.Provider>
//   );
// }

// export default ReservedContext;