# include "cdcatalogue.h"

CDCatalogue::CDCatalogue()
{
  maxsize = 4;
  cds = new CD[maxsize];
  numcds = 0;
}

CDCatalogue::CDCatalogue(const CDCatalogue &cat)
{
  CopyArray(cat);
}

void CDCatalogue::CopyArray(const CDCatalogue& cat)
{
  maxsize = cat.maxsize;
  numcds = cat.Count();
  cds = new CD[cat.maxsize];

  for(int i = 0; i < maxsize; ++i)
  {
    cds[i] = cat.cds[i];
  }
}

int CDCatalogue::Count() const
{
  return numcds;
}

CDCatalogue::~CDCatalogue()
{
  if (this->Count() > 0)
  {
    delete[] cds;
  }
}

int CDCatalogue::Find(CD disc) const
{
  int index = -1;
  
  if (disc.GetArtist() == "" && disc.GetAlbum() == "")
  {
    return index;
  }

  for (int i = 0 ; i < this->Count(); ++i) 
  {
    if (cds[i] == disc)
    {
      index = i;
      break;
    }
  }
  return index;
}

bool CDCatalogue::Insert(CD disc)
{
  if (this->Find(disc) != -1)
  {
    return false;
  }

  if (this->Count() == maxsize)
  {
    // Double the size of the array
    maxsize += maxsize;
    CD * newcds = new CD[maxsize];

    for(int i = 0; i < this->Count(); ++i)
    {
      newcds[i] = cds[i];
    }
    
    cds = newcds;
    delete newcds;
  }

  cds[this->Count()] = disc;
  return true;
}

bool CDCatalogue::Remove(CD disc)
{
  int CD_index = this->Find(disc);

  if ( CD_index== -1)
  {
    return false;
  }
  // Edge case
  // Swapping would not work for CD Catalogue, size == 1
  else if (CD_index == 0)
  {
    numcds --;
    return true;
  } else 
  {
    // Swap the contents between the cd that needs to be removed and 
    // the last CD in the collection.
    // Then decrement the count to not allow user to access the removed CD.
    cds[CD_index] = cds[this->Count() - 1];
    numcds--;

    return true;
  }
}

bool CDCatalogue::Boycott(std::string dontlikeanymore)
{
  bool boycottSuccessful = false;

  if (this->Count() == 0)
  {
    return false;
  }
  // Edge case
  // Swapping would not work for CD Catalogue, size == 1
  
  while (this->Count() != 0)
  {
    if (this->Count() == 1)
    {
      if (cds[this->Count() - 1].GetArtist() == dontlikeanymore)
      {
        numcds--;
        return true;
      } else {
        return false;
      }
    } else {
      int index = -1;
      
      for(int i = 0; i < this->Count(); ++i)
      {
        if (cds[i].GetArtist() == dontlikeanymore)
        {
          index = i;
          break;
        }
      }

      if (index != -1)
      {
        cds[index] = cds[this->Count() - 1];
        numcds--;
        boycottSuccessful = true;
      } else {
        return true;
      }
    }
  }
  // Corner Case
  // The flow reaches here only when all the cds in the catalogue are from
  // the boycotted artist and the post status of the CD Catalogue after the
  // function call is empty Catalogue.
  return boycottSuccessful;
}

CDCatalogue CDCatalogue::Join(const CDCatalogue& cat) const
{
  CDCatalogue catalogue_union(*this);

  // Perform Union of two catalogues
  for (int i = 0; i < cat.Count(); ++i)
  {
    catalogue_union.Insert(cat.cds[i]);
  }

  return catalogue_union;
}

CDCatalogue CDCatalogue::Common(const CDCatalogue& cat) const
{
  CDCatalogue catalogue_intersection(*this);

  // Perform Intersection of two catalogues
  bool investigationUnderway= true;

  while (investigationUnderway)
  {
    investigationUnderway = false;
    for (int i = 0; i < this->Count(); ++i)
    {
      if (cat.Find(cds[i]) == -1)
      {
        catalogue_intersection.Remove(cds[i]);
        investigationUnderway = true;
        break;
      }
    }
  }

  return catalogue_intersection;
}

CDCatalogue CDCatalogue::Split(const CDCatalogue& cat) const
{
  CDCatalogue catalogue_set_difference(*this);

  // Perform Set Difference of two catalogues
  bool investigationUnderway= true;

  while (investigationUnderway)
  {
    investigationUnderway = false;
    for (int i = 0; i < this->Count(); ++i)
    {
      if (cat.Find(cds[i]) != -1)
      {
        catalogue_set_difference.Remove(cds[i]);
        investigationUnderway = true;
        break;
      }
    }
  }
  
  return catalogue_set_difference;
}

void CDCatalogue::PrintCollection() const
{
  std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
  std::cout << "+          Printing the Collection            +" << std::endl;
  
  for(int i = 0; i < this->Count(); ++i)
  {
    std::cout << "CD# " << i << " -> " << cds[i].GetArtist() << "/" << 
    cds[i].GetAlbum() << std::endl;
  }
}

int main()
{
  return 0;
}