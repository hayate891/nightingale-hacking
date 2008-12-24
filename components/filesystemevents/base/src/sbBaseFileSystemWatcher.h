/*
//
// BEGIN SONGBIRD GPL
//
// This file is part of the Songbird web player.
//
// Copyright(c) 2005-2008 POTI, Inc.
// http://songbirdnest.com
//
// This file may be licensed under the terms of of the
// GNU General Public License Version 2 (the "GPL").
//
// Software distributed under the License is distributed
// on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, either
// express or implied. See the GPL for the specific language
// governing rights and limitations.
//
// You should have received a copy of the GPL along with this
// program. If not, go to http://www.gnu.org/licenses/gpl.html
// or write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
//
// END SONGBIRD GPL
//
*/

#ifndef sbBaseFileSystemWatcher_h_
#define sbBaseFileSystemWatcher_h_

#include <sbIFileSystemWatcher.h>
#include <sbIFileSystemListener.h>
#include "sbFileSystemTree.h"
#include "sbFileSystemTreeListener.h"
#include <nsStringAPI.h>
#include <nsCOMPtr.h>


//
// \brief Base class for the file system watcher. Handles the listener,
//        watch path, and watch state.
//
class sbBaseFileSystemWatcher : public sbIFileSystemWatcher,
                                public sbFileSystemTreeListener
{
public:
  sbBaseFileSystemWatcher();
  virtual ~sbBaseFileSystemWatcher();

  NS_DECL_ISUPPORTS
  NS_DECL_SBIFILESYSTEMWATCHER

  virtual void OnChangeFound(nsAString & aChangePath, 
                             EChangeType aChangeType);
  virtual void OnTreeReady();

protected:
  nsRefPtr<sbFileSystemTree>      mTree;
  nsCOMPtr<sbIFileSystemListener> mListener;
  nsString                        mWatchPath;
  PRBool                          mIsRecursive;
  PRBool                          mIsWatching;
};

#endif  // sbBaseFileSystemWatcher_h_

