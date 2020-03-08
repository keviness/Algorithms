def main():
    states_needed = set(["mt", "wa", "or", "id", "nv", "ut", "az", "ca"])
    stations = {}
    stations["kone"] = set(["id", "nv", "ut"])
    stations["ktwo"] = set(["wa", "id", "mt"])
    stations["kthree"] = set(["or", "nv", "ca"])
    stations["kfour"] = set(["nv", "ut"])
    final_value = algoHandler(states_needed, stations)
    for i in final_value:
        print(i)

def algoHandler(states_needed, stations):
    final_stations = set()
    while states_needed:
        best_station = None
        states_covered = set()
        for station, states in stations.items():
            covered = states_needed & states
            if len(covered) > len(states_covered):
                best_station = station
                station_covered = covered
        states_needed -= states_covered
        final_stations.add(best_station)
    return final_stations
if __name__ == "__main__":
    main()