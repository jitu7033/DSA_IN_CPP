


function init(){
  document.getElementById("jsworld").innerHTML = "hello world from javascript"
}

function initProduct(){
  document.getElementById("product-menu").innerHTML = `
   <h1>List of Product </h1>
  <table>
      <thead>
        <tr>
          <th>Sr. No</th>
          <th>product Name </th>
          <th>details </th>
          <th>price </th>
        </tr>
        <tbody>
          <tr>
            <td>1</td>
            <td>Dish 1</td>
            <td>good</td>
            <td>1000</td>
          </tr>
        </tbody>
      </thead>
    </table>`
}

initProduct()

init();