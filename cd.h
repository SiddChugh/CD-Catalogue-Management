// Description: Declaration of a CD class

#ifndef cd_h
#define cd_h

#include <string>

class CD
{
private:
  std::string artist;
  std::string albumtitle;
    
public:
  // Default constructor
  CD();
  
  // Parameterized constructor
  CD(std::string artistname, std::string title);
  
  // Destructor not required.
  // Class does not contain any member variables in dynamic memory
  
  /**
    *MUTATORS
    *Methods for updating CD's private fields
    *Update will only occur if parameter is not empty string
    *Returns true if update is successful, false otherwise.
    */
  bool UpdateArtist(std::string artistname);
  bool UpdateAlbum(std::string title);
  bool Update(std::string artistname, std::string title);
  
  /**
    *ACCESSORS
    *Methods for retrieving CD information
    */
  std::string GetArtist() const;
  std::string GetAlbum() const;
  
  /**
    *OVERLOADED OPERATORS
    *equality is true if all fields match
    *not-equals is true if any field does not match
    */
  bool operator==(const CD& disc) const;
  bool operator!=(const CD& disc) const;
};

#endif  //  cd_h 