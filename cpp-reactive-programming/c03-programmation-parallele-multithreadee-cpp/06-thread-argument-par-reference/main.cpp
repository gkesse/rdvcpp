void update_data(shared_data &data);
void another_func()
{
    shared_data data;
    std::thread t(update_data, std::ref(data));
    t.join();
    do_something_else(data);
}

// pourquoi utiliser std::ref
// pour un argument qui est déjà une référence ?
std::thread t(update_data, data);

// lorsque le thread appelle la fonction update_data,
// celle-ci reçoit une référence à une copie locale de l'argument,
// et non une référence à l'objet original
