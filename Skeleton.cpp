#include<iostream>
#include<vector>
using namespace std;

//singleton design
class Admin
{
public:
	static Admin* getInstance();
	void addEvent(Event* event);
	void manageSystem();//perform CRUD Operations on system
	void deactivateAccount(int userID);		
	void addUsers(User* user);
	void manageRoles(string roles, string username);
	~Admin();
	//prevent copy constructor and assignment operator
	Admin(const Admin&) = delete;
	Admin& operator=(const Admin&) = delete;

private:
	static Admin* instance;
	vector<Event*> events;
	vector<User*> users;
	// private constructor 
	Admin();

};
//singleton design
class Project_Manager
{
public:
	static Project_Manager* getInstance();
	void getProjectDetails();
	void setProjectDetails(string projectDetail);
	void allocateResources(Resources* resource);
	void assignTask(int teamID,string responsibility);
	void addVenue(int eventID, string venueName);
	void createProject(string projectName, string description);
	void setPayment(Payment* payment);
	void addTeamMember(TeamMember* member);

private:
	Project_Manager();
	string projectDetail;
	vector<TeamMember*> teamMembers;
	Payment* payment;
	vector<Resources*> resources;
	static Project_Manager* instance;

};

//prototype design
class EventPrototype
{
public:
	virtual Event* clone() const = 0;
	virtual ~EventPrototype();

};

// Concrete class representing an Event
class Event : public EventPrototype
{
private:
    std::string eventID;
    std::string eventName;
    std::string type;
    std::string date;
    std::string time;

public:
    // Constructor
    Event(string id, string name,string t, string d, string tme);
 
    // Get event details
    void getEventDetail();

    // Update event details
    void updateEvent(const string& newName, const string& newType,const string& newDate,const string& newTime);

	// Clone method
	Event* clone() const override;
};

class User
{
public:
	User();
	void create_Account(string username,string email, string password);
	void login(string username, string pssword);
	void logout();
	void changePassword(string oldPassword, string new_Password);
	~User();

private:
	string username;
	string email;
	string password;
};

class Customer:public User
{
public:
	Customer();
	~Customer();
	void requestEvent();
private:
	int customerID;
	string customerInfo;
	string eventDetails;
	Attendee* attendee;
	Payment* payment;
};
class Attendee:public User
{
private:
	std::vector<Feedback*> feedbacks;
	std::vector<Ticket*> tickets;
	int attendeeID;
	
public:
	Attendee();
	void buyTicket(string ticketType, int eventID);
	void submitFeedback(int eventID, int ratings, string comment);
	void updateProfile(string newDetails);
	~Attendee();

private:

};
class TeamMember:public User
{
public:
	TeamMember();
	void updateProfile(string skill);
	void performTask();
	~TeamMember();

private:
	int teamID;
	string role;
	string responsibility;
	string skills;
};
class Venue
{
public:
	Venue();
	void addVenue(string name,int capacity,string facility,string address);
	void manageVenue(string action, int venueID);
	~Venue();

private:
	int venueID;
	string venueName;
	string facility;
	string address;
	int capacity;

};
class Payment
{
private:
	int paymentID;
	string status;
	double amount;
	string paymentMethod;
public:
	Payment();
	void processPayment(int paymentID, int amount, string paymentMethod);
	void viewPaymentDetail(int paymentID);
	~Payment();

};
//prototype design
class FeedbackPrototype
{
public:
	virtual Feedback* clone() const = 0;
	virtual ~FeedbackPrototype();

};

// Concrete class representing an feedback
class Feedback : public FeedbackPrototype
{
private:
   	   int feedbackID;
	   int ratings;
	   string comment;
	   string time;
public:
	Feedback();
	void submitFeedback(int eventID, int ratings, string comments,int attendeeID);
	void viewfeedback(int feedbackID, int attendeeID);
	~Feedback();
	Feedback* clone() const override;
};

//Prototype design
class TicketPrototype
{
public:
	virtual Ticket* clone() const = 0; 
	virtual ~TicketPrototype();
};

// Concrete class representing an ticket
class Ticket:public TicketPrototype
{
public:
	Ticket();
	void setTicket(int eventID, int attendeeID, string type, double price);
	void updateTicket(int eventID,int attendeeID, string type, double price);
	Ticket getTicketDetails(int tickeID);
	Ticket* clone() const override;
	~Ticket();

private:
	int ticketID;
	string ticketType;
	double price;
};
class Resources
{
public:
	Resources();
	Resources getResource();
	void addResource(string name, int id, bool availability, double cost);
	~Resources();

private:
	int resID;
	string name;
	bool availability;
	double cost;
};