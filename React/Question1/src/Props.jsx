export default function Props(props) {
    return (
        <>
        <center>
            <h1 style={{backgroundColor:"orange", color:"white"}}>Name: {props.name}</h1>
            <h1>Age: {props.age}</h1>
            <h1 style={{backgroundColor:"green", color:"white"}}>University Name: {props.uniName}</h1>
        </center>
        </>
    )
}