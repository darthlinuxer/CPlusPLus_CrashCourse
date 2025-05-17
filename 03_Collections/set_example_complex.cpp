#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <functional> // For std::hash

// Point2D class with custom comparison
class Point2D {
private:
    double x, y;

public:
    Point2D(double x = 0, double y = 0) : x(x), y(y) {}

    // Getters
    double getX() const { return x; }
    double getY() const { return y; }

    // Required for std::set if no custom comparator is provided
    bool operator<(const Point2D& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }

    // For easy printing
    friend std::ostream& operator<<(std::ostream& os, const Point2D& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    // For testing equality
    bool operator==(const Point2D& other) const {
        return x == other.x && y == other.y;
    }
};

// Person class with multiple fields
class Person {
private:
    std::string name;
    int age;
    std::string id;

public:
    Person(const std::string& name, int age, const std::string& id)
        : name(name), age(age), id(id) {}

    // Getters
    const std::string& getName() const { return name; }
    int getAge() const { return age; }
    const std::string& getId() const { return id; }

    // For easy printing
    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << person.name << " (Age: " << person.age << ", ID: " << person.id << ")";
        return os;
    }

    // For testing equality
    bool operator==(const Person& other) const {
        return id == other.id; // Assuming ID is unique
    }
};

// Custom comparator for Person class (by name, then age)
struct PersonNameAgeComparator {
    bool operator()(const Person& a, const Person& b) const {
        if (a.getName() != b.getName()) return a.getName() < b.getName();
        return a.getAge() < b.getAge();
    }
};

// Custom comparator for Person class (by age only)
struct PersonAgeComparator {
    bool operator()(const Person& a, const Person& b) const {
        return a.getAge() < b.getAge();
    }
};

// Custom comparator for Person class (by ID)
struct PersonIdComparator {
    bool operator()(const Person& a, const Person& b) const {
        return a.getId() < b.getId();
    }
};

// Custom comparator for Point2D (by distance from origin)
struct PointDistanceComparator {
    bool operator()(const Point2D& a, const Point2D& b) const {
        double dist_a = a.getX() * a.getX() + a.getY() * a.getY();
        double dist_b = b.getX() * b.getX() + b.getY() * b.getY();
        return dist_a < dist_b;
    }
};

// Template function to print any set
template <typename T>
void printSet(const std::set<T>& s, const std::string& name) {
    std::cout << name << ": ";
    for (const auto& item : s) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

// Overload for sets with custom comparators
template <typename T, typename Comp>
void printSet(const std::set<T, Comp>& s, const std::string& name) {
    std::cout << name << ": ";
    for (const auto& item : s) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "========== Point2D Sets ==========" << std::endl;
    
    // Creating a set of Point2D objects using the default comparison (operator<)
    std::set<Point2D> pointSet;
    
    // Insert some points
    pointSet.insert(Point2D(3, 4));
    pointSet.insert(Point2D(1, 2));
    pointSet.insert(Point2D(5, 6));
    pointSet.insert(Point2D(3, 4));  // Duplicate, will be ignored
    
    // Print the set
    printSet(pointSet, "Points (sorted by x, then y)");
    // Output: Points (sorted by x, then y): (1, 2) (3, 4) (5, 6)
    
    // Creating a set using distance from origin as comparison
    std::set<Point2D, PointDistanceComparator> distancePointSet;
    
    // Insert some points
    distancePointSet.insert(Point2D(3, 4));    // Distance: 25
    distancePointSet.insert(Point2D(1, 2));    // Distance: 5
    distancePointSet.insert(Point2D(5, 6));    // Distance: 61
    distancePointSet.insert(Point2D(0, 7));    // Distance: 49
    
    // Print the set
    printSet(distancePointSet, "Points (sorted by distance from origin)");
    // Output: Points (sorted by distance from origin): (1, 2) (3, 4) (0, 7) (5, 6)
    
    // Find a point
    auto it = pointSet.find(Point2D(3, 4));
    if (it != pointSet.end()) {
        std::cout << "Found point: " << *it << std::endl;
    }
    // Output: Found point: (3, 4)
    
    // Lower bound and upper bound for Point2D
    auto lb = pointSet.lower_bound(Point2D(3, 0));
    auto ub = pointSet.upper_bound(Point2D(3, 5));
    
    std::cout << "Points between (3,0) and (3,5): ";
    for (auto it = lb; it != ub; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
    // Output: Points between (3,0) and (3,5): (3, 4)
    
    std::cout << "========== Person Sets ==========" << std::endl;
    
    // Create people
    Person p1("Alice", 30, "A123");
    Person p2("Bob", 25, "B456");
    Person p3("Charlie", 35, "C789");
    Person p4("Alice", 22, "A456");
    Person p5("David", 25, "D123");
    
    // Set sorted by name, then age
    std::set<Person, PersonNameAgeComparator> peopleByNameAge;
    peopleByNameAge.insert(p1);
    peopleByNameAge.insert(p2);
    peopleByNameAge.insert(p3);
    peopleByNameAge.insert(p4);
    peopleByNameAge.insert(p5);
    
    printSet(peopleByNameAge, "People sorted by name, then age");
    // Output: People sorted by name, then age: Alice (Age: 22, ID: A456) Alice (Age: 30, ID: A123) Bob (Age: 25, ID: B456) Charlie (Age: 35, ID: C789) David (Age: 25, ID: D123)
    
    // Set sorted by age only
    std::set<Person, PersonAgeComparator> peopleByAge;
    peopleByAge.insert(p1);
    peopleByAge.insert(p2);
    peopleByAge.insert(p3);
    peopleByAge.insert(p4);
    peopleByAge.insert(p5);
    
    printSet(peopleByAge, "People sorted by age");
    // Output: People sorted by age: Alice (Age: 22, ID: A456) Bob (Age: 25, ID: B456) David (Age: 25, ID: D123) Alice (Age: 30, ID: A123) Charlie (Age: 35, ID: C789)
    
    // Set sorted by ID
    std::set<Person, PersonIdComparator> peopleById;
    peopleById.insert(p1);
    peopleById.insert(p2);
    peopleById.insert(p3);
    peopleById.insert(p4);
    peopleById.insert(p5);
    
    printSet(peopleById, "People sorted by ID");
    // Output: People sorted by ID: Alice (Age: 30, ID: A123) Alice (Age: 22, ID: A456) Bob (Age: 25, ID: B456) Charlie (Age: 35, ID: C789) David (Age: 25, ID: D123)
    
    // Finding a person by ID (custom find function since we need to match by ID)
    auto findById = [&peopleById](const std::string& id) -> Person* {
        for (const auto& person : peopleById) {
            if (person.getId() == id) {
                return new Person(person); // Return a copy
            }
        }
        return nullptr;
    };
    
    Person* found = findById("B456");
    if (found) {
        std::cout << "Found person with ID B456: " << *found << std::endl;
        delete found;
    }
    // Output: Found person with ID B456: Bob (Age: 25, ID: B456)
    
    // Remove people under 30
    std::cout << "\nRemoving people under 30..." << std::endl;
    for (auto it = peopleByAge.begin(); it != peopleByAge.end(); ) {
        if (it->getAge() < 30) {
            std::cout << "Removing: " << *it << std::endl;
            it = peopleByAge.erase(it);
        } else {
            ++it;
        }
    }
    // Output:
    // Removing people under 30...
    // Removing: Alice (Age: 22, ID: A456)
    // Removing: Bob (Age: 25, ID: B456)
    // Removing: David (Age: 25, ID: D123)
    
    printSet(peopleByAge, "People 30 and older");
    // Output: People 30 and older: Alice (Age: 30, ID: A123) Charlie (Age: 35, ID: C789)
    
    // Set operations with Point2D sets
    std::cout << "\n========== Set Operations with Points ==========" << std::endl;
    
    std::set<Point2D> pointSetA = {Point2D(1, 1), Point2D(2, 2), Point2D(3, 3)};
    std::set<Point2D> pointSetB = {Point2D(2, 2), Point2D(3, 3), Point2D(4, 4)};
    
    printSet(pointSetA, "Point Set A");
    // Output: Point Set A: (1, 1) (2, 2) (3, 3)
    
    printSet(pointSetB, "Point Set B");
    // Output: Point Set B: (2, 2) (3, 3) (4, 4)
    
    // Union
    std::set<Point2D> pointUnion;
    std::set_union(
        pointSetA.begin(), pointSetA.end(),
        pointSetB.begin(), pointSetB.end(),
        std::inserter(pointUnion, pointUnion.begin())
    );
    
    printSet(pointUnion, "Union of Point Sets");
    // Output: Union of Point Sets: (1, 1) (2, 2) (3, 3) (4, 4)
    
    // Intersection
    std::set<Point2D> pointIntersection;
    std::set_intersection(
        pointSetA.begin(), pointSetA.end(),
        pointSetB.begin(), pointSetB.end(),
        std::inserter(pointIntersection, pointIntersection.begin())
    );
    
    printSet(pointIntersection, "Intersection of Point Sets");
    // Output: Intersection of Point Sets: (2, 2) (3, 3)
    
    // Difference (A - B)
    std::set<Point2D> pointDifference;
    std::set_difference(
        pointSetA.begin(), pointSetA.end(),
        pointSetB.begin(), pointSetB.end(),
        std::inserter(pointDifference, pointDifference.begin())
    );
    
    printSet(pointDifference, "Difference of Point Sets (A - B)");
    // Output: Difference of Point Sets (A - B): (1, 1)
    
    return 0;
}