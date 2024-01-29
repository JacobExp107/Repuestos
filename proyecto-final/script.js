let inventario = [];  //sirve para almacenar los datos guardados

function encontrarProducto(nombre) {
    return inventario.findIndex(producto => producto.nombre.toLowerCase() === nombre.toLowerCase()); //findIndex sirve para buscar un producto en el inventario con su mismo nombre
}

function agregarProducto() {
    const productoNombre = document.getElementById('producto').value;
    const precio = parseFloat(document.getElementById('precio').value);     // Sirve para que la funcion busque en el documento una referencia y lo mande a la id
    const cantidad = parseInt(document.getElementById('cantidad').value);

    if (productoNombre && !isNaN(precio) && !isNaN(cantidad)) { //Se verifica si se ingresaron valores válidos para el nombre del producto, el precio y la cantidad.
        const productoIndex = encontrarProducto(productoNombre);

        if (productoIndex !== -1) {
            // Si el producto ya existe, aumentar la cantidad
            inventario[productoIndex].cantidad += cantidad;
        } else {
            // Si el producto no existe, agregarlo al inventario
            const nuevoProducto = {
                nombre: productoNombre,
                precio: precio,
                cantidad: cantidad
            };

            inventario.push(nuevoProducto);
        }

        // Limpiar los campos después de agregar/editar el producto
        document.getElementById('producto').value = '';
        document.getElementById('precio').value = '';
        document.getElementById('cantidad').value = '';

        alert('Producto agregado/editado con éxito!');
    } else {
        alert('Por favor, complete todos los campos correctamente.');
    }
}

function buscarProducto() {
    const buscar = document.getElementById('buscar').value.toLowerCase();

    const resultado = inventario.filter(producto => producto.nombre.toLowerCase().includes(buscar));

    if (resultado.length > 0) {
        // Calcular el precio total
        const precioTotal = resultado[0].precio * resultado[0].cantidad;

        // Mostrar el resultado en el nuevo contenedor
        document.getElementById('buscar-resultados').innerHTML = `
            <p><strong>Producto:</strong> ${resultado[0].nombre}</p>
            <p><strong>Cantidad:</strong> ${resultado[0].cantidad}</p>
            <p><strong>Precio por unidad:</strong> $${resultado[0].precio.toFixed(2)}</p>
            <p><strong>Precio total:</strong> $${precioTotal.toFixed(2)}</p>
        `;
    } else {
        document.getElementById('buscar-resultados').innerHTML = '<p>Producto no encontrado.</p>';
    }
}

function mostrarInventario() {
    if (inventario.length > 0) {
        const inventarioHTML = inventario.map((producto, index) =>
            `<p><strong>${producto.nombre}</strong> - Cantidad: ${producto.cantidad}, 
            Precio por unidad: $${producto.precio.toFixed(2)}, 
            Precio total: $${(producto.precio * producto.cantidad).toFixed(2)}
            <button class="editar" onclick="editarProducto('${producto.nombre}')">Editar</button></p>`
        ).join('');

        document.getElementById('inventario').innerHTML = inventarioHTML;
    } else {
        document.getElementById('inventario').innerHTML = '<p>No hay productos en el inventario.</p>';
    }
}

function editarProducto(nombre) {
    const productoIndex = encontrarProducto(nombre);
    
    if (productoIndex !== -1) {
        const producto = inventario[productoIndex];
    
        // Rellenar los campos con la información del producto seleccionado
        document.getElementById('producto').value = producto.nombre;
        document.getElementById('precio').value = producto.precio;
        document.getElementById('cantidad').value = producto.cantidad;

        // Eliminar el producto del inventario
        inventario.splice(productoIndex, 1);

        // Actualizar la vista del inventario
        mostrarInventario();
    }
}
