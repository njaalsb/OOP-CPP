#include "Meeting.h"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

// BEGIN 3b
std::ostream& operator<<(std::ostream& os, const Campus& cs){
    os << campusToString.at(cs) << std::endl;
    return os;
}
// END 3b

// BEGIN 3e
void Meeting::addParticipant(std::shared_ptr<Person> p){
    participants.push_back(p);
}
// END 3e

// BEGIN 3f
Meeting::Meeting(int day, int startTime, int endTime, Campus location, const std::string& subject, const std::shared_ptr<Person> leader)
: day(day), startTime(startTime), endTime(endTime), location(location), subject(subject), leader(leader) {}
// END 3f

// BEGIN 3h
std::vector<std::string> Meeting::getParticipantList() const{
    std::vector<std::string> names;
    for (const auto& participant : participants)
    {
        names.push_back(participant->getName());
    }
    
    return names;
}
// END 3h

// BEGIN 3i
std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDriving(Meeting& m) const{
    std::vector<std::shared_ptr<Person>> available; 
    

    if(location == m.location && day == m.day && std::abs(startTime-m.startTime) <= 1 && std::abs(endTime - m.endTime) <= 1 ){
        for(const auto& participant : m.participants){
            if(participant->hasAvailableSeats()){
                available.push_back(participant);
            }
        }
    }
    return available;
}
// END 3i

// BEGIN 3j
std::ostream& operator<<(std::ostream& os, const Meeting& meeting) {
    os << "Meeting: " << meeting.getSubject() << "\n"
       << "Location: " << campusToString.at(meeting.getLocation()) << "\n"
       << "Time: " << meeting.getStartTime() << " - " << meeting.getEndTime() << "\n"
       << "Leader: " << meeting.getLeader()->getName() << "\n"
       << "Participants: \n";

    for (const auto& participant : meeting.getParticipants()) {
        os << " - " << participant->getName() << "\n";
    }

    return os;
}
// END 3j
