'''breadth first search'''
def search(name):
    graph = {}
    graph["you"] = ["kevin", "Bob"]
    graph["kevin"] = ["Alice", "Lucy"]
    graph["Bob"] = ["Nancy"]

    search_queue = deque()
    search_queue += graph[name]
    searched = []
    while search_queue:
        person = search_queue.popleft()
        if not person in searched:
            if person_is_seller(person):
                print(person+" is a mango seller!")
                return True
            else:
                search_queue += graph[person]
                searched.append(person)
    return False

def person_is_seller(name):
    return name[-1] == "m"  #return true or false 

if __name__ == "__search__":
    search()