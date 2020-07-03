#include "cd.h"

CD::CD(std::string artistname, std::string title)
{
    artist = artistname;
    albumtitle = title;
}

bool CD::UpdateArtist(std::string artistname)
{
  if (artistname != "")
  {
      artist = artistname;
      return true;
  }
  return false;
}

bool CD::UpdateAlbum(std::string title)
{
  if (title != "")
  {
      albumtitle = title;
      return true;
  }
  return false;
}

bool CD::Update(std::string artistname, std::string title)
{
  if (artistname != "" && title != "")
  {
      artist = artistname;
      albumtitle = title;
      return true;
  }
  return false;
}

std::string CD::GetArtist() const
{
  return artist;
}

std::string CD::GetAlbum() const
{
  return albumtitle;
}

bool CD::operator==(const CD& disc) const
{
  return (artist == disc.artist && albumtitle == disc.albumtitle);
}

bool CD::operator!=(const CD& disc) const
{
  return !(*this == disc);
}