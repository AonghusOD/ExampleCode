export default function handler(req, res) {
    fetch('http://localhost:8000/deleteCart', {
        method: 'DELETE'
    })
    .then((res) => res.json())
    .then((data) => {
        console.log(req)
        console.log(res)
        res.status(200).json(data);
    })
}