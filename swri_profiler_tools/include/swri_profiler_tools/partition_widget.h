// *****************************************************************************
//
// Copyright (c) 2015, Southwest Research Institute® (SwRI®)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Southwest Research Institute® (SwRI®) nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL Southwest Research Institute® BE LIABLE 
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// *****************************************************************************
#ifndef SWRI_PROFILER_TOOLS_PARTITION_WIDGET_H_
#define SWRI_PROFILER_TOOLS_PARTITION_WIDGET_H_

#include <QWidget>
#include <QColor>
#include <QRectF>
#include <swri_profiler_tools/database_key.h>

QT_BEGIN_NAMESPACE
class QGraphicsView;
QT_END_NAMESPACE

namespace swri_profiler_tools
{
class ProfileDatabase;
class PartitionWidget : public QWidget
{
  Q_OBJECT;

  ProfileDatabase *db_;
  QGraphicsView *view_;
  DatabaseKey active_key_;
  
 public:
  PartitionWidget(QWidget *parent=0);
  ~PartitionWidget();
  void setDatabase(ProfileDatabase *db);

 public Q_SLOTS:
  void setActiveNode(int profile_key, int node_key);

 Q_SIGNALS:
  void activeNodeChanged(int profile_key, int node_key);

                                       
 private Q_SLOTS:
  void handleProfileAdded(int profile_key);
  void handleNodesAdded(int profile_key);
  // void handleItemActivated(QTreeWidgetItem *item, int column);
  // void handleTreeContextMenuRequest(const QPoint &pos);

 private:
  void synchronizeWidget();
  // void addProfile(int profile_key);
  // void addNode(QTreeWidgetItem *parent, const Profile &profile, const int node_key);

  struct ParitionItem
  {
    int profile_key;
    int node_key;
    QColor color;
    QString name;
    QRectF full_rect;
    QRectF level_rect;
  };
  void generatePartition();
  
 protected:
  void paintEvent(QPaintEvent *event);
};  // class PartitionWidget  
}  // namespace swri_profiler_tools
#endif  // SWRI_PROFILER_TOOLS_PARTITION_WIDGET_H_

