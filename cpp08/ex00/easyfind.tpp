template <typename Container>
void easyfind(const Container &container, int toFind ) {
    for (typename Container ::const_iterator it = container.begin();
    it != container.end(); ++it) {
        if (*it == toFind) {
            std::cout << "Occurrence found" << std::endl;
            return ;
        };
    }
    throw std::runtime_error("No element match argument!");
}